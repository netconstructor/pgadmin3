//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
//
// Copyright (C) 2002 - 2011, The pgAdmin Development Team
// This software is released under the PostgreSQL Licence
//
// ddTableNameDialog.cpp - Utility dialog class to allow user input of table name and short name
//
//////////////////////////////////////////////////////////////////////////

#include "pgAdmin3.h"

// wxWindows headers
#include <wx/wx.h>
#include <wx/statline.h>

// App headers
#include "dd/dditems/utilities/ddTableNameDialog.h"
#include "dd/dditems/figures/ddTableFigure.h"

#define txtUsualTableName    CTRL_TEXT("txtUsualTableName")
#define txtShortTableName    CTRL_TEXT("txtShortTableName")
#define btnGenerate          CTRL_BUTTON("btnGenerate")


BEGIN_EVENT_TABLE(ddTableNameDialog, pgDialog)
	EVT_BUTTON(XRCID("btnGenerate"), ddTableNameDialog::OnGenButtonClicked )
END_EVENT_TABLE()

ddTableNameDialog::ddTableNameDialog(	wxWindow *parent,
                                        const wxString &defaultValue1,
                                        const wxString &defaultValue2,
                                        ddTextTableItemFigure *tableItem
                                    ) :
	pgDialog()
{
	wxWindowBase::SetFont(settings->GetSystemFont());
	LoadResource(parent, wxT("ddTableNameDialog"));
	RestorePosition();
	Init();
	tabItem = tableItem;
	checkGenerate = false;

	SetValue1(defaultValue1);
	SetValue2(defaultValue2);

	txtUsualTableName->SetFocus();
}

ddTableNameDialog::~ddTableNameDialog()
{
}

ddTableNameDialog::ddTableNameDialog() :
	pgDialog()
{
	Init();
}

void ddTableNameDialog::Init( )
{
	m_value1 = wxEmptyString;
	m_value2 = wxEmptyString;
}

//Transfer data to the window
bool ddTableNameDialog::TransferDataToWindow()
{
	txtUsualTableName->SetValue(m_value1);
	txtShortTableName->SetValue(m_value2);
	return true;
}

//Transfer data from the window
bool ddTableNameDialog::TransferDataFromWindow()
{
	m_value1 = txtUsualTableName->GetValue();
	m_value2 = txtShortTableName->GetValue();
	return true;
}

//Generation CheckBox Event to generata short name when checkbox clicked
void ddTableNameDialog::OnGenButtonClicked( wxCommandEvent &event )
{
	wxString shortName = ddTableFigure::generateShortName(txtUsualTableName->GetValue());
	txtShortTableName->SetValue(shortName);
}
