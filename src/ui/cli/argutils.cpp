/*
 * Created by Saurav Ghosh on 19/06/16.
 * Copyright (c) 2003-2018 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

#include "argutils.h"
#include "./strutils.h"

#include <map>
#include <regex>

#include "../../core/PWScore.h"
#include "../../core/core.h"

using namespace std;

using String2FieldTypeMap = std::map<stringT, CItemData::FieldType>;

// Reverse of CItemData::FieldName
static String2FieldTypeMap  InitFieldTypeMap()
{
  String2FieldTypeMap ftmap;
  stringT retval;
  LoadAString(retval, IDSC_FLDNMGROUPTITLE);      ftmap[retval] = CItem::GROUPTITLE;
  LoadAString(retval, IDSC_FLDNMUUID);            ftmap[retval] = CItem::UUID;
  LoadAString(retval, IDSC_FLDNMGROUP);           ftmap[retval] = CItem::GROUP;
  LoadAString(retval, IDSC_FLDNMTITLE);           ftmap[retval] = CItem::TITLE;
  LoadAString(retval, IDSC_FLDNMUSERNAME);        ftmap[retval] = CItem::USER;
  LoadAString(retval, IDSC_FLDNMNOTES);           ftmap[retval] = CItem::NOTES;
  LoadAString(retval, IDSC_FLDNMPASSWORD);        ftmap[retval] = CItem::PASSWORD;
#undef CTIME
  LoadAString(retval, IDSC_FLDNMCTIME);           ftmap[retval] = CItem::CTIME;
  LoadAString(retval, IDSC_FLDNMPMTIME);          ftmap[retval] = CItem::PMTIME;
  LoadAString(retval, IDSC_FLDNMATIME);           ftmap[retval] = CItem::ATIME;
  LoadAString(retval, IDSC_FLDNMXTIME);           ftmap[retval] = CItem::XTIME;
  LoadAString(retval, IDSC_FLDNMRMTIME);          ftmap[retval] = CItem::RMTIME;
  LoadAString(retval, IDSC_FLDNMURL);             ftmap[retval] = CItem::URL;
  LoadAString(retval, IDSC_FLDNMAUTOTYPE);        ftmap[retval] = CItem::AUTOTYPE;
  LoadAString(retval, IDSC_FLDNMPWHISTORY);       ftmap[retval] = CItem::PWHIST;
  LoadAString(retval, IDSC_FLDNMPWPOLICY);        ftmap[retval] = CItem::POLICY;
  LoadAString(retval, IDSC_FLDNMXTIMEINT);        ftmap[retval] = CItem::XTIME_INT;
  LoadAString(retval, IDSC_FLDNMRUNCOMMAND);      ftmap[retval] = CItem::RUNCMD;
  LoadAString(retval, IDSC_FLDNMDCA);             ftmap[retval] = CItem::DCA;
  LoadAString(retval, IDSC_FLDNMSHIFTDCA);        ftmap[retval] = CItem::SHIFTDCA;
  LoadAString(retval, IDSC_FLDNMEMAIL);           ftmap[retval] = CItem::EMAIL;
  LoadAString(retval, IDSC_FLDNMPROTECTED);       ftmap[retval] = CItem::PROTECTED;
  LoadAString(retval, IDSC_FLDNMSYMBOLS);         ftmap[retval] = CItem::SYMBOLS;
  LoadAString(retval, IDSC_FLDNMPWPOLICYNAME);    ftmap[retval] = CItem::POLICYNAME;
  LoadAString(retval, IDSC_FLDNMKBSHORTCUT);      ftmap[retval] = CItem::KBSHORTCUT;
  return ftmap;;
}

CItemData::FieldType String2FieldType(const stringT& str)
{
  static const String2FieldTypeMap ftmap = InitFieldTypeMap();
  stringT s{str}; // Trim requires non-const
  auto itr = ftmap.find(Trim(s));
  if (itr != ftmap.end())
    return itr->second;
  throw std::invalid_argument("Invalid field: " + toutf8(str));
}

PWSMatch::MatchRule Str2MatchRule( const wstring &s)
{
  static const std::map<wstring, PWSMatch::MatchRule> rulemap{
    {L"==", PWSMatch::MR_EQUALS},
    {L"!==", PWSMatch::MR_NOTEQUAL},
    {L"^=", PWSMatch::MR_BEGINS},
    {L"!^=", PWSMatch::MR_NOTBEGIN},
    {L"$=", PWSMatch::MR_ENDS},
    {L"!$=", PWSMatch::MR_NOTEND},
    {L"~=", PWSMatch::MR_CONTAINS},
    {L"!~=", PWSMatch::MR_NOTCONTAIN}
  };
  const auto itr = rulemap.find(s);
  if ( itr != rulemap.end() )
    return itr->second;
  return PWSMatch::MR_INVALID;
}

CItemData::FieldBits ParseFields(const wstring &f)
{
  CItemData::FieldBits fields;
  Split(f, L",", [&fields](const wstring &field) {
    CItemData::FieldType ft = String2FieldType(field);
    fields.set(ft);
  });
  return fields;
}

void UserArgs::SetFields(const wstring &f)
{
  fields = ParseFields(f);
}

inline bool CaseSensitive(const wstring &str)
{
  assert(str.length() == 0 || (str.length() == 2 && str[0] == '/' && (str[1] == L'i' || str[1] == 'I')));
  return str.length() == 0 || str[0] == L'i';
}

Restriction ParseSubset(const std::wstring &s)
{
  const std::wregex restrictPattern{L"([[:alpha:]-]+)([!]?[=^$~]=)([^;]+?)(/[iI])?$"};
  wsmatch m;
  if (regex_search(s, m, restrictPattern))
    return Restriction{String2FieldType(m.str(1)), Str2MatchRule(m.str(2)), m.str(3), CaseSensitive(m.str(4))};
  throw std::invalid_argument("Invalid subset: " + toutf8(s));
}


void UserArgs::SetSubset(const std::wstring &s)
{
  subset = ParseSubset(s);
}

UserArgs::FieldUpdates ParseFieldValues(const wstring &updates)
{
  UserArgs::FieldUpdates fieldValues;
  Split(updates, L"[;,]", [&fieldValues](const wstring &nameval) {
    std::wsmatch m;
    if (std::regex_match(nameval, m, std::wregex(L"([^=:]+?)[=:](.+)"))) {
      fieldValues.push_back( std::make_tuple(String2FieldType(m.str(1)), std2stringx(m.str(2))) );
    }
    else {
      throw std::invalid_argument{"Could not parse field value to be updated: " + toutf8(nameval)};
    }
  });
  return fieldValues;
}

void UserArgs::SetFieldValues(const wstring &updates) {
  fieldValues = ParseFieldValues(updates);
}
