/*
 * Copyright (c) 2003-2011 Rony Shapiro <ronys@users.sourceforge.net>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file wxutils.cpp
* 
* Contains generic utility functions that should be global and don't fit anywhere else
*/

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "../../core/PWScore.h"
#include "./wxutils.h"

/*
 * Reads a file into a PWScore object, and displays an appropriate msgbox
 * in case of failure.  Returns PWScore::SUCCESS on success
 */

int ReadCore(PWScore& othercore, const wxString& file, const StringX& combination, 
                bool showMsgbox /*= true*/, wxWindow* msgboxParent /*= NULL*/)
{
  othercore.ClearData();

  // Reading a new file changes the preferences!
  const StringX sxSavePrefString(PWSprefs::GetInstance()->Store());
  const bool bDBPrefsChanged = PWSprefs::GetInstance()->IsDBprefsChanged();

  StringX dbpath(tostringx(file));
  int rc = othercore.ReadFile(dbpath, combination);

  // Reset database preferences - first to defaults then add saved changes!
  PWSprefs::GetInstance()->Load(sxSavePrefString);
  PWSprefs::GetInstance()->SetDBprefsChanged(bDBPrefsChanged);

  switch (rc) {
    case PWScore::SUCCESS:
      othercore.SetCurFile(tostringx(file));
      break;

    case PWScore::CANT_OPEN_FILE:
      if (showMsgbox)
        wxMessageBox(wxString(file) << _("\n\nCould not open file for reading!"),
                    _("File Read Error"), wxOK | wxICON_ERROR, msgboxParent );
      break;

    case PWScore::BAD_DIGEST:
      if (showMsgbox && wxMessageBox(wxString(file) << _("\n\nFile corrupt or truncated!\nData may have been lost or modified.\nContinue anyway?"), 
            _("File Read Error"), wxYES_NO | wxICON_QUESTION, msgboxParent) == wxYES) {
        rc = PWScore::SUCCESS;
      }
      break;

#ifdef DEMO
    case PWScore::LIMIT_REACHED:
      if( showMsgbox)
        wxMessageBox(wxString::Format(_("This version of PasswordSafe does not support more than %d entries in a database.\nTo get an unlimited version for the U3 platform, please visit http://software.u3.com\nNote: Saving this database will result in the removal of unread entries!"), MAXDEMO),
                        _("Trial Version Limitation"), wxOK | wxICON_WARNING, msgboxParent);
      break;
#endif

    default:
      if (showMsgbox)
        wxMessageBox( wxString(file) << _("\n\nUnknown error"), _("File Read Error"), wxOK | wxICON_ERROR, msgboxParent);
      break;
  }
  
  return rc;
}