/*
 * Copyright (c) 2003-2012 Rony Shapiro <ronys@users.sourceforge.net>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file PasswordPolicy.cpp
* 
*/
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "PasswordPolicy.h"

////@begin XPM images
////@end XPM images



/*!
 * CPasswordPolicy event table definition
 */

BEGIN_EVENT_TABLE( CPasswordPolicy, wxDialog )

////@begin CPasswordPolicy event table entries
  EVT_BUTTON( wxID_OK, CPasswordPolicy::OnOkClick )

  EVT_BUTTON( wxID_CANCEL, CPasswordPolicy::OnCancelClick )

  EVT_BUTTON( wxID_HELP, CPasswordPolicy::OnHelpClick )

////@end CPasswordPolicy event table entries

END_EVENT_TABLE()


/*!
 * CPasswordPolicy constructor
 */

CPasswordPolicy::CPasswordPolicy( wxWindow* parent, PWScore &core,
				  wxWindowID id, const wxString& caption,
				  const wxPoint& pos, const wxSize& size, long style )
: m_core(core)
{
  Init();
  Create(parent, id, caption, pos, size, style);
}


/*!
 * CPasswordPolicy creator
 */

bool CPasswordPolicy::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin CPasswordPolicy creation
  SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
  wxDialog::Create( parent, id, caption, pos, size, style );

  CreateControls();
  if (GetSizer())
  {
    GetSizer()->SetSizeHints(this);
  }
  Centre();
////@end CPasswordPolicy creation
  return true;
}


/*!
 * CPasswordPolicy destructor
 */

CPasswordPolicy::~CPasswordPolicy()
{
////@begin CPasswordPolicy destruction
////@end CPasswordPolicy destruction
}


/*!
 * Member initialisation
 */

void CPasswordPolicy::Init()
{
////@begin CPasswordPolicy member initialisation
  m_pwMinsGSzr = NULL;
  m_pwpUseLowerCtrl = NULL;
  m_pwNumLCbox = NULL;
  m_pwpLCSpin = NULL;
  m_pwpUseUpperCtrl = NULL;
  m_pwNumUCbox = NULL;
  m_pwpUCSpin = NULL;
  m_pwpUseDigitsCtrl = NULL;
  m_pwNumDigbox = NULL;
  m_pwpDigSpin = NULL;
  m_pwpSymCtrl = NULL;
  m_pwNumSymbox = NULL;
  m_pwpSymSpin = NULL;
  m_pwpEasyCtrl = NULL;
  m_pwpPronounceCtrl = NULL;
  m_pwpHexCtrl = NULL;
////@end CPasswordPolicy member initialisation
}


/*!
 * Control creation for CPasswordPolicy
 */

void CPasswordPolicy::CreateControls()
{    
////@begin CPasswordPolicy content construction
  CPasswordPolicy* itemDialog1 = this;

  wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
  itemDialog1->SetSizer(itemBoxSizer2);

  wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
  itemBoxSizer2->Add(itemBoxSizer3, 0, 0, 0);

  wxStaticText* itemStaticText4 = new wxStaticText( itemDialog1, wxID_STATIC, _("Policy Name:"), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer3->Add(itemStaticText4, 1, wxALIGN_CENTER_VERTICAL|wxALL, 10);

  wxTextCtrl* itemTextCtrl5 = new wxTextCtrl( itemDialog1, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer3->Add(itemTextCtrl5, 2, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxStaticBox* itemStaticBoxSizer6Static = new wxStaticBox(itemDialog1, wxID_ANY, _("Random password generation rules"));
  wxStaticBoxSizer* itemStaticBoxSizer6 = new wxStaticBoxSizer(itemStaticBoxSizer6Static, wxVERTICAL);
  itemBoxSizer2->Add(itemStaticBoxSizer6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

  wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
  itemStaticBoxSizer6->Add(itemBoxSizer7, 0, wxALIGN_LEFT|wxALL, 5);

  wxStaticText* itemStaticText8 = new wxStaticText( itemDialog1, wxID_STATIC, _("Password length: "), wxDefaultPosition, wxDefaultSize, 0 );
  itemBoxSizer7->Add(itemStaticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxSpinCtrl* itemSpinCtrl9 = new wxSpinCtrl( itemDialog1, ID_SPINCTRL3, _T("12"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 4, 1024, 12 );
  itemBoxSizer7->Add(itemSpinCtrl9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwMinsGSzr = new wxGridSizer(6, 2, 0, 0);
  itemStaticBoxSizer6->Add(m_pwMinsGSzr, 0, wxALIGN_LEFT|wxALL, 5);

  m_pwpUseLowerCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX3, _("Use lowercase letters"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpUseLowerCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpUseLowerCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwNumLCbox = new wxBoxSizer(wxHORIZONTAL);
  m_pwMinsGSzr->Add(m_pwNumLCbox, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText13 = new wxStaticText( itemDialog1, wxID_STATIC, _("(At least "), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumLCbox->Add(itemStaticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpLCSpin = new wxSpinCtrl( itemDialog1, ID_SPINCTRL5, _T("0"), wxDefaultPosition, wxSize(20, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
  m_pwNumLCbox->Add(m_pwpLCSpin, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText15 = new wxStaticText( itemDialog1, wxID_STATIC, _(")"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumLCbox->Add(itemStaticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpUseUpperCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX4, _("Use UPPERCASE letters"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpUseUpperCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpUseUpperCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwNumUCbox = new wxBoxSizer(wxHORIZONTAL);
  m_pwMinsGSzr->Add(m_pwNumUCbox, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText18 = new wxStaticText( itemDialog1, wxID_STATIC, _("(At least "), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumUCbox->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpUCSpin = new wxSpinCtrl( itemDialog1, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxSize(20, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
  m_pwNumUCbox->Add(m_pwpUCSpin, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText20 = new wxStaticText( itemDialog1, wxID_STATIC, _(")"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumUCbox->Add(itemStaticText20, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpUseDigitsCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX5, _("Use digits"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpUseDigitsCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpUseDigitsCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwNumDigbox = new wxBoxSizer(wxHORIZONTAL);
  m_pwMinsGSzr->Add(m_pwNumDigbox, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText23 = new wxStaticText( itemDialog1, wxID_STATIC, _("(At least "), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumDigbox->Add(itemStaticText23, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpDigSpin = new wxSpinCtrl( itemDialog1, ID_SPINCTRL7, _T("0"), wxDefaultPosition, wxSize(20, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
  m_pwNumDigbox->Add(m_pwpDigSpin, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText25 = new wxStaticText( itemDialog1, wxID_STATIC, _(")"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumDigbox->Add(itemStaticText25, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpSymCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX6, _("Use symbols (i.e., ., %, $, etc.)"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpSymCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpSymCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwNumSymbox = new wxBoxSizer(wxHORIZONTAL);
  m_pwMinsGSzr->Add(m_pwNumSymbox, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText28 = new wxStaticText( itemDialog1, wxID_STATIC, _("(At least "), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumSymbox->Add(itemStaticText28, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  m_pwpSymSpin = new wxSpinCtrl( itemDialog1, ID_SPINCTRL8, _T("0"), wxDefaultPosition, wxSize(20, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
  m_pwNumSymbox->Add(m_pwpSymSpin, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText30 = new wxStaticText( itemDialog1, wxID_STATIC, _(")"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwNumSymbox->Add(itemStaticText30, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxRadioButton* itemRadioButton31 = new wxRadioButton( itemDialog1, IDC_USE_DEFAULTSYMBOLS, _("Default set"), wxDefaultPosition, wxDefaultSize, 0 );
  itemRadioButton31->SetValue(false);
  m_pwMinsGSzr->Add(itemRadioButton31, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxStaticText* itemStaticText32 = new wxStaticText( itemDialog1, IDC_STATIC_DEFAULT_SYMBOLS, _("Static text"), wxDefaultPosition, wxSize(120, -1), 0 );
  m_pwMinsGSzr->Add(itemStaticText32, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxRadioButton* itemRadioButton33 = new wxRadioButton( itemDialog1, IDC_USE_OWNSYMBOLS, _("Special set"), wxDefaultPosition, wxDefaultSize, 0 );
  itemRadioButton33->SetValue(false);
  m_pwMinsGSzr->Add(itemRadioButton33, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

  wxTextCtrl* itemTextCtrl34 = new wxTextCtrl( itemDialog1, IDC_OWNSYMBOLS, wxEmptyString, wxDefaultPosition, wxSize(60, -1), 0 );
  m_pwMinsGSzr->Add(itemTextCtrl34, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwpEasyCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX7, _("Use only easy-to-read characters\n(i.e., no 'l', '1', etc.)"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpEasyCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpEasyCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwMinsGSzr->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwpPronounceCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX8, _("Generate pronounceable passwords"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpPronounceCtrl->SetValue(false);
  m_pwMinsGSzr->Add(m_pwpPronounceCtrl, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  m_pwMinsGSzr->Add(5, 5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 0);

  wxStaticText* itemStaticText39 = new wxStaticText( itemDialog1, wxID_STATIC, _("Or"), wxDefaultPosition, wxDefaultSize, 0 );
  itemStaticBoxSizer6->Add(itemStaticText39, 0, wxALIGN_LEFT|wxALL, 5);

  m_pwpHexCtrl = new wxCheckBox( itemDialog1, ID_CHECKBOX9, _("Use hexadecimal digits only (0-9, a-f)"), wxDefaultPosition, wxDefaultSize, 0 );
  m_pwpHexCtrl->SetValue(false);
  itemStaticBoxSizer6->Add(m_pwpHexCtrl, 0, wxALIGN_LEFT|wxALL, 5);

  wxStdDialogButtonSizer* itemStdDialogButtonSizer41 = new wxStdDialogButtonSizer;

  itemBoxSizer2->Add(itemStdDialogButtonSizer41, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
  wxButton* itemButton42 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
  itemStdDialogButtonSizer41->AddButton(itemButton42);

  wxButton* itemButton43 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
  itemStdDialogButtonSizer41->AddButton(itemButton43);

  wxButton* itemButton44 = new wxButton( itemDialog1, wxID_HELP, _("&Help"), wxDefaultPosition, wxDefaultSize, 0 );
  itemStdDialogButtonSizer41->AddButton(itemButton44);

  itemStdDialogButtonSizer41->Realize();

  // Set validators
  itemTextCtrl5->SetValidator( wxGenericValidator(& m_polname) );
  itemSpinCtrl9->SetValidator( wxGenericValidator(& m_pwdefaultlength) );
////@end CPasswordPolicy content construction
}


/*!
 * Should we show tooltips?
 */

bool CPasswordPolicy::ShowToolTips()
{
  return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap CPasswordPolicy::GetBitmapResource( const wxString& name )
{
  // Bitmap retrieval
////@begin CPasswordPolicy bitmap retrieval
  wxUnusedVar(name);
  return wxNullBitmap;
////@end CPasswordPolicy bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon CPasswordPolicy::GetIconResource( const wxString& name )
{
  // Icon retrieval
////@begin CPasswordPolicy icon retrieval
  wxUnusedVar(name);
  return wxNullIcon;
////@end CPasswordPolicy icon retrieval
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void CPasswordPolicy::OnOkClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CPasswordPolicy.
  // Before editing this code, remove the block markers.
  event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in CPasswordPolicy. 
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void CPasswordPolicy::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in CPasswordPolicy.
  // Before editing this code, remove the block markers.
  event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in CPasswordPolicy. 
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP
 */

void CPasswordPolicy::OnHelpClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP in CPasswordPolicy.
  // Before editing this code, remove the block markers.
  event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_HELP in CPasswordPolicy. 
}

void CPasswordPolicy::SetPolicyData(const wxString &policyname, PSWDPolicyMap &MapPSWDPLC)
{
  m_MapPSWDPLC = MapPSWDPLC;
  m_polname = m_oldpolname = policyname;

  m_iter = m_polname.IsEmpty() ? m_MapPSWDPLC.end() :
    m_MapPSWDPLC.find(StringX(m_polname.c_str()));

  // Check the find worked above - if PolicyName not empty, it must be in the map!
  if (!m_polname.IsEmpty())
    ASSERT(m_iter != m_MapPSWDPLC.end());

  // If New, use default values; otherwise use this policy's values
  st_PSWDPolicy xst_pp = m_polname.IsEmpty() ? m_st_default_pp : m_iter->second;
#ifdef NOTYET
  m_PWUseLowercase = m_oldPWUseLowercase =
    (xst_pp.pwp.flags & PWPolicy::UseLowercase) ==
                       PWPolicy::UseLowercase;
  m_PWUseUppercase = m_oldPWUseUppercase =
    (xst_pp.pwp.flags & PWPolicy::UseUppercase) ==
                       PWPolicy::UseUppercase;
  m_PWUseDigits = m_oldPWUseDigits =
    (xst_pp.pwp.flags & PWPolicy::UseDigits) ==
                       PWPolicy::UseDigits;
  m_PWUseSymbols = m_oldPWUseSymbols =
    (xst_pp.pwp.flags & PWPolicy::UseSymbols) ==
                       PWPolicy::UseSymbols;
  m_PWUseHexdigits = m_oldPWUseHexdigits =
    (xst_pp.pwp.flags & PWPolicy::UseHexDigits) ==
                       PWPolicy::UseHexDigits;
  m_PWEasyVision = m_oldPWEasyVision =
    (xst_pp.pwp.flags & PWPolicy::UseEasyVision) ==
                       PWPolicy::UseEasyVision;
  m_PWMakePronounceable = m_oldPWMakePronounceable =
    (xst_pp.pwp.flags & PWPolicy::MakePronounceable) ==
                       PWPolicy::MakePronounceable;
  m_PWDefaultLength = m_oldPWDefaultLength = xst_pp.pwp.length;
  m_PWDigitMinLength = m_oldPWDigitMinLength = xst_pp.pwp.digitminlength;
  m_PWLowerMinLength = m_oldPWLowerMinLength = xst_pp.pwp.lowerminlength;
  m_PWSymbolMinLength = m_oldPWSymbolMinLength = xst_pp.pwp.symbolminlength;
  m_PWUpperMinLength = m_oldPWUpperMinLength = xst_pp.pwp.upperminlength;

  wxString symbols = xst_pp.symbols.c_str();
  m_Symbols = m_oldSymbols = symbols;
  m_UseOwnSymbols = m_oldUseOwnSymbols = cs_symbols.IsEmpty() ? DEFAULT_SYMBOLS : OWN_SYMBOLS;
#endif
}
