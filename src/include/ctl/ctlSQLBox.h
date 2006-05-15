//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id: ctlSQLBox.h 4983 2006-01-31 21:42:25Z dpage $
// Copyright (C) 2002 - 2006, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// ctlSQLBox.h - SQL syntax highlighting textbox
//
//////////////////////////////////////////////////////////////////////////

#ifndef CTLSQLBOX_H
#define CTLSQLBOX_H

// wxWindows headers
#include <wx/wx.h>
#include <wx/stc/stc.h>
#include <wx/fdrepdlg.h>

#include "pgConn.h"

// Class declarations
class ctlSQLBox : public wxStyledTextCtrl
{
    static wxString sqlKeywords;

public:
    ctlSQLBox(wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0);
    ctlSQLBox();
    ~ctlSQLBox();

    void Create(wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0);

	void SetDatabase(pgConn *db);

    void OnKeyDown(wxKeyEvent& event);
	void OnAutoComplete(wxCommandEvent& event);
    void OnFind(wxCommandEvent& event);
    void OnReplace(wxCommandEvent& event);
    void OnFindDialog(wxFindDialogEvent& event);
	void OnKillFocus(wxFocusEvent& event);
    
    DECLARE_DYNAMIC_CLASS(ctlSQLBox)
    DECLARE_EVENT_TABLE()
		
private:

    void OnPositionStc(wxStyledTextEvent& event);

	wxFindReplaceData m_findData;
    wxFindReplaceDialog* m_dlgFind;
	pgConn *m_database;
#ifndef __WXMSW__
	bool findDlgLast;
#endif
		
};


#endif
