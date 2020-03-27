#include "TreInfoPage.h"



System::Void WeAlumni::TreInfoPage::UpdatePageInfo(String^ OId) {
    IdShow->Text = OId;
    
    int RowNum = _TreDB->ReadData("SELECT StfId, Time, Type, Amount, Comment" 
                                    " FROM Treasury WHERE Id = " + OId +"; ");
    SQLiteDataReader^ DataReader = _TreDB->dataReader;
    String^ StaffId;

    if (RowNum != -1) {
        StaffId = DataReader[0]->ToString();
        StfIdShow->Text = StaffId;

        TimeShow->Text = DataReader[1]->ToString();
        TypeShow->Text = DataReader[2]->ToString();
        AmountShow->Text = DataReader[3]->ToString();
        CommentShow->Text = DataReader[4]->ToString();
    }
    else {
        StfIdShow->Text = "Open file failed ";
    }


    

    RowNum = _DataDB->ReadData("SELECT S.Dept, S.Position, M.Name "
        "FROM Staff S, Member M WHERE S.Id = "+ StaffId +" And M.Id = S.MemId;");
    DataReader = _DataDB->dataReader;
    if (RowNum != -1) {
        
        
        DepartmentShow->Text = DataReader[0]->ToString();
        PositionShow->Text = DataReader[1]->ToString();
        StfNameShow->Text = DataReader[2]->ToString();

    }
    else {
        CommentShow->Text = "No data";
    }


}

System::Void WeAlumni::TreInfoPage::ModTre_Click(System::Object^ sender, System::EventArgs^ e) {
    SetShowLabelStatus(false);
    SetTextStatus(true);
    SetShowToText(true);
    SetButtonStatus(true);
}

System::Void WeAlumni::TreInfoPage::SetShowLabelStatus(bool NewStatus) {
    IdShow->Visible = NewStatus;
    StfIdShow->Visible = NewStatus;
    TimeShow->Visible = NewStatus;
    DepartmentShow->Visible = NewStatus;
    StfNameShow->Visible = NewStatus;
    PositionShow->Visible = NewStatus;
    TypeShow->Visible = NewStatus;
    AmountShow->Visible = NewStatus;
    CommentShow->Visible = NewStatus;
}

System::Void WeAlumni::TreInfoPage::SetTextStatus(bool NewStatus) {
    IdText->Visible = NewStatus;
    StfText->Visible = NewStatus;
    TimeText->Visible = NewStatus;
    DeptText->Visible = NewStatus;
    StfNameText->Visible = NewStatus;
    PositionText->Visible = NewStatus;
    TypeText->Visible = NewStatus;
    AmountText->Visible = NewStatus;
    CommentText->Visible = NewStatus;
}

System::Void WeAlumni::TreInfoPage::SetShowToText(bool Mode) {
    if (Mode) {
        IdText->Text = IdShow->Text;
        StfText->Text = StfIdShow->Text;
        TimeText->Text = TimeShow->Text;;
        DeptText->Text = DepartmentShow->Text;
        StfNameText->Text = StfNameShow->Text;
        PositionText->Text = PositionShow->Text;
        TypeText->Text = TypeShow->Text;
        AmountText->Text = AmountShow->Text;
        CommentText->Text = CommentShow->Text;
    }
    else {
        IdShow->Text = IdText->Text;
        StfIdShow->Text = StfText->Text;
        TimeShow->Text = TimeText->Text;
        DepartmentShow->Text = DeptText->Text;
        StfNameShow->Text = StfNameText->Text;
        PositionShow->Text = PositionText->Text;
        TypeShow->Text = TypeText->Text;
        AmountShow->Text = AmountText->Text;
        CommentShow->Text = CommentText->Text;
    }
    
}

System::Void WeAlumni::TreInfoPage::SetButtonStatus(bool ModifyStatus) {
    if (ModifyStatus) {
        ModTre->Visible = false;
        DelTre->Visible = false;
        ConfirmMod->Visible = true;
        CancelMod->Visible = true;
    }
    else {
        ModTre->Visible = true;
        DelTre->Visible = true;
        ConfirmMod->Visible = false;
        CancelMod->Visible = false;
    }
}

System::Void WeAlumni::TreInfoPage::ConfirmMod_Click(System::Object^ sender, System::EventArgs^ e) {
    UpdateDB();
    SetShowToText(false);
    
    SetShowLabelStatus(true);
    SetTextStatus(false);
    SetButtonStatus(false);
}

int WeAlumni::TreInfoPage::UpdateDB() {
    return 0;
}
