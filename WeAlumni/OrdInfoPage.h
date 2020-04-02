#pragma once
#include "Database.h"

/*
 * OrderInfoPage.h
 *
 * This file shows a Order Information page for a unique Order Id.
 *
 * @author: Haoran Li
 * Revised: 4/1/20
 *
 */

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// OrderInfoPage 摘要
	/// </summary>
	public ref class OrdInfoPage : public System::Windows::Forms::Form
	{
	public:
		OrdInfoPage(int^ inputId)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			odrId = inputId;

			try {
				database = gcnew Database(Database::DatabaseType::Data);
				UpdateInfo();
			}
			catch (Exception^ exception) {
				lbl_DBError->Text = exception->Message;
				btn_ChangeInfo->Enabled = false;
				btn_Delete->Enabled = false;
			}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~OrdInfoPage()
		{
			if (components)
			{
				delete components;
			}
			if (database)
			{
				delete database;
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_OdrId;
	private: System::Windows::Forms::Label^ lbl_Prompt_OdrStat;
	private: System::Windows::Forms::Label^ lbl_Prompt_SbmTime;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemID;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Country;
	private: System::Windows::Forms::Label^ lbl_Prompt_City;
	private: System::Windows::Forms::Label^ lbl_Prompt_Postal;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address2;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfID;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfName;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemAmt;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemPrice;
	private: System::Windows::Forms::Label^ lbl_Prompt_Content;
	private: System::Windows::Forms::TextBox^ txt_OdrAmt;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Button^ btn_Check;
	private: System::Windows::Forms::RichTextBox^ rtxt_Content;
	private: System::Windows::Forms::Label^ lbl_OdrStat;
	private: System::Windows::Forms::TextBox^ txt_OdrStat;
	private: System::Windows::Forms::Label^ lbl_OdrAmt;
	private: System::Windows::Forms::Label^ lbl_OdrPrice;
	private: System::Windows::Forms::Label^ lbl_ItemId;
	private: System::Windows::Forms::Label^ lbl_ItemName;
	private: System::Windows::Forms::TextBox^ txt_ItemId;
	private: System::Windows::Forms::TextBox^ txt_ItemName;
	private: System::Windows::Forms::Label^ lbl_Content;
	private: System::Windows::Forms::Label^ lbl_DBError;
	private: System::Windows::Forms::Label^ lbl_OdrId;
	private: System::Windows::Forms::Label^ lbl_Sbmtime;
	private: System::Windows::Forms::Label^ lbl_MemID;
	private: System::Windows::Forms::Label^ lbl_MemName;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_Country;
	private: System::Windows::Forms::Label^ lbl_City;
	private: System::Windows::Forms::Label^ lbl_Postal;
	private: System::Windows::Forms::Label^ lbl_Address1;
	private: System::Windows::Forms::Label^ lbl_Address2;
	private: System::Windows::Forms::Label^ lbl_StfID;
	private: System::Windows::Forms::Label^ lbl_StfName;
	private: System::Windows::Forms::Button^ btn_DelConfirm;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemFnd;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OrdInfoPage::typeid));
			this->lbl_Prompt_OdrId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_OdrStat = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_SbmTime = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemID = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_City = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfID = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemAmt = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Content = (gcnew System::Windows::Forms::Label());
			this->txt_OdrAmt = (gcnew System::Windows::Forms::TextBox());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->btn_Check = (gcnew System::Windows::Forms::Button());
			this->rtxt_Content = (gcnew System::Windows::Forms::RichTextBox());
			this->lbl_OdrStat = (gcnew System::Windows::Forms::Label());
			this->txt_OdrStat = (gcnew System::Windows::Forms::TextBox());
			this->lbl_OdrAmt = (gcnew System::Windows::Forms::Label());
			this->lbl_OdrPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemId = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemName = (gcnew System::Windows::Forms::Label());
			this->txt_ItemId = (gcnew System::Windows::Forms::TextBox());
			this->txt_ItemName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Content = (gcnew System::Windows::Forms::Label());
			this->lbl_DBError = (gcnew System::Windows::Forms::Label());
			this->lbl_OdrId = (gcnew System::Windows::Forms::Label());
			this->lbl_Sbmtime = (gcnew System::Windows::Forms::Label());
			this->lbl_MemID = (gcnew System::Windows::Forms::Label());
			this->lbl_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_City = (gcnew System::Windows::Forms::Label());
			this->lbl_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_StfID = (gcnew System::Windows::Forms::Label());
			this->lbl_StfName = (gcnew System::Windows::Forms::Label());
			this->btn_DelConfirm = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_ItemFnd = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_OdrId
			// 
			resources->ApplyResources(this->lbl_Prompt_OdrId, L"lbl_Prompt_OdrId");
			this->lbl_Prompt_OdrId->Name = L"lbl_Prompt_OdrId";
			// 
			// lbl_Prompt_OdrStat
			// 
			resources->ApplyResources(this->lbl_Prompt_OdrStat, L"lbl_Prompt_OdrStat");
			this->lbl_Prompt_OdrStat->Name = L"lbl_Prompt_OdrStat";
			// 
			// lbl_Prompt_SbmTime
			// 
			resources->ApplyResources(this->lbl_Prompt_SbmTime, L"lbl_Prompt_SbmTime");
			this->lbl_Prompt_SbmTime->Name = L"lbl_Prompt_SbmTime";
			// 
			// lbl_Prompt_MemID
			// 
			resources->ApplyResources(this->lbl_Prompt_MemID, L"lbl_Prompt_MemID");
			this->lbl_Prompt_MemID->Name = L"lbl_Prompt_MemID";
			// 
			// lbl_Prompt_MemName
			// 
			resources->ApplyResources(this->lbl_Prompt_MemName, L"lbl_Prompt_MemName");
			this->lbl_Prompt_MemName->Name = L"lbl_Prompt_MemName";
			// 
			// lbl_Prompt_Email
			// 
			resources->ApplyResources(this->lbl_Prompt_Email, L"lbl_Prompt_Email");
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			// 
			// lbl_Prompt_Country
			// 
			resources->ApplyResources(this->lbl_Prompt_Country, L"lbl_Prompt_Country");
			this->lbl_Prompt_Country->Name = L"lbl_Prompt_Country";
			// 
			// lbl_Prompt_City
			// 
			resources->ApplyResources(this->lbl_Prompt_City, L"lbl_Prompt_City");
			this->lbl_Prompt_City->Name = L"lbl_Prompt_City";
			// 
			// lbl_Prompt_Postal
			// 
			resources->ApplyResources(this->lbl_Prompt_Postal, L"lbl_Prompt_Postal");
			this->lbl_Prompt_Postal->Name = L"lbl_Prompt_Postal";
			// 
			// lbl_Prompt_Address1
			// 
			resources->ApplyResources(this->lbl_Prompt_Address1, L"lbl_Prompt_Address1");
			this->lbl_Prompt_Address1->Name = L"lbl_Prompt_Address1";
			// 
			// lbl_Prompt_Address2
			// 
			resources->ApplyResources(this->lbl_Prompt_Address2, L"lbl_Prompt_Address2");
			this->lbl_Prompt_Address2->Name = L"lbl_Prompt_Address2";
			// 
			// lbl_Prompt_StfID
			// 
			resources->ApplyResources(this->lbl_Prompt_StfID, L"lbl_Prompt_StfID");
			this->lbl_Prompt_StfID->Name = L"lbl_Prompt_StfID";
			// 
			// lbl_Prompt_StfName
			// 
			resources->ApplyResources(this->lbl_Prompt_StfName, L"lbl_Prompt_StfName");
			this->lbl_Prompt_StfName->Name = L"lbl_Prompt_StfName";
			// 
			// lbl_Prompt_ItemId
			// 
			resources->ApplyResources(this->lbl_Prompt_ItemId, L"lbl_Prompt_ItemId");
			this->lbl_Prompt_ItemId->Name = L"lbl_Prompt_ItemId";
			// 
			// lbl_Prompt_ItemName
			// 
			resources->ApplyResources(this->lbl_Prompt_ItemName, L"lbl_Prompt_ItemName");
			this->lbl_Prompt_ItemName->Name = L"lbl_Prompt_ItemName";
			// 
			// lbl_Prompt_ItemAmt
			// 
			resources->ApplyResources(this->lbl_Prompt_ItemAmt, L"lbl_Prompt_ItemAmt");
			this->lbl_Prompt_ItemAmt->Name = L"lbl_Prompt_ItemAmt";
			// 
			// lbl_Prompt_ItemPrice
			// 
			resources->ApplyResources(this->lbl_Prompt_ItemPrice, L"lbl_Prompt_ItemPrice");
			this->lbl_Prompt_ItemPrice->Name = L"lbl_Prompt_ItemPrice";
			// 
			// lbl_Prompt_Content
			// 
			resources->ApplyResources(this->lbl_Prompt_Content, L"lbl_Prompt_Content");
			this->lbl_Prompt_Content->Name = L"lbl_Prompt_Content";
			// 
			// txt_OdrAmt
			// 
			resources->ApplyResources(this->txt_OdrAmt, L"txt_OdrAmt");
			this->txt_OdrAmt->Name = L"txt_OdrAmt";
			// 
			// btn_ChangeInfo
			// 
			resources->ApplyResources(this->btn_ChangeInfo, L"btn_ChangeInfo");
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Change_Click);
			// 
			// btn_Delete
			// 
			resources->ApplyResources(this->btn_Delete, L"btn_Delete");
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Delete_Click);
			// 
			// btn_Confirm
			// 
			resources->ApplyResources(this->btn_Confirm, L"btn_Confirm");
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Confirm_Click);
			// 
			// btn_Cancel
			// 
			resources->ApplyResources(this->btn_Cancel, L"btn_Cancel");
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Cancel_Click);
			// 
			// btn_Check
			// 
			resources->ApplyResources(this->btn_Check, L"btn_Check");
			this->btn_Check->Name = L"btn_Check";
			this->btn_Check->UseVisualStyleBackColor = true;
			this->btn_Check->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Check_Click);
			// 
			// rtxt_Content
			// 
			resources->ApplyResources(this->rtxt_Content, L"rtxt_Content");
			this->rtxt_Content->Name = L"rtxt_Content";
			// 
			// lbl_OdrStat
			// 
			resources->ApplyResources(this->lbl_OdrStat, L"lbl_OdrStat");
			this->lbl_OdrStat->Name = L"lbl_OdrStat";
			// 
			// txt_OdrStat
			// 
			resources->ApplyResources(this->txt_OdrStat, L"txt_OdrStat");
			this->txt_OdrStat->Name = L"txt_OdrStat";
			// 
			// lbl_OdrAmt
			// 
			resources->ApplyResources(this->lbl_OdrAmt, L"lbl_OdrAmt");
			this->lbl_OdrAmt->Name = L"lbl_OdrAmt";
			// 
			// lbl_OdrPrice
			// 
			resources->ApplyResources(this->lbl_OdrPrice, L"lbl_OdrPrice");
			this->lbl_OdrPrice->Name = L"lbl_OdrPrice";
			// 
			// lbl_ItemId
			// 
			resources->ApplyResources(this->lbl_ItemId, L"lbl_ItemId");
			this->lbl_ItemId->Name = L"lbl_ItemId";
			// 
			// lbl_ItemName
			// 
			resources->ApplyResources(this->lbl_ItemName, L"lbl_ItemName");
			this->lbl_ItemName->Name = L"lbl_ItemName";
			// 
			// txt_ItemId
			// 
			resources->ApplyResources(this->txt_ItemId, L"txt_ItemId");
			this->txt_ItemId->Name = L"txt_ItemId";
			// 
			// txt_ItemName
			// 
			resources->ApplyResources(this->txt_ItemName, L"txt_ItemName");
			this->txt_ItemName->Name = L"txt_ItemName";
			// 
			// lbl_Content
			// 
			resources->ApplyResources(this->lbl_Content, L"lbl_Content");
			this->lbl_Content->Name = L"lbl_Content";
			// 
			// lbl_DBError
			// 
			resources->ApplyResources(this->lbl_DBError, L"lbl_DBError");
			this->lbl_DBError->Name = L"lbl_DBError";
			// 
			// lbl_OdrId
			// 
			resources->ApplyResources(this->lbl_OdrId, L"lbl_OdrId");
			this->lbl_OdrId->Name = L"lbl_OdrId";
			// 
			// lbl_Sbmtime
			// 
			resources->ApplyResources(this->lbl_Sbmtime, L"lbl_Sbmtime");
			this->lbl_Sbmtime->Name = L"lbl_Sbmtime";
			// 
			// lbl_MemID
			// 
			resources->ApplyResources(this->lbl_MemID, L"lbl_MemID");
			this->lbl_MemID->Name = L"lbl_MemID";
			// 
			// lbl_MemName
			// 
			resources->ApplyResources(this->lbl_MemName, L"lbl_MemName");
			this->lbl_MemName->Name = L"lbl_MemName";
			// 
			// lbl_Email
			// 
			resources->ApplyResources(this->lbl_Email, L"lbl_Email");
			this->lbl_Email->Name = L"lbl_Email";
			// 
			// lbl_Country
			// 
			resources->ApplyResources(this->lbl_Country, L"lbl_Country");
			this->lbl_Country->Name = L"lbl_Country";
			// 
			// lbl_City
			// 
			resources->ApplyResources(this->lbl_City, L"lbl_City");
			this->lbl_City->Name = L"lbl_City";
			// 
			// lbl_Postal
			// 
			resources->ApplyResources(this->lbl_Postal, L"lbl_Postal");
			this->lbl_Postal->Name = L"lbl_Postal";
			// 
			// lbl_Address1
			// 
			resources->ApplyResources(this->lbl_Address1, L"lbl_Address1");
			this->lbl_Address1->Name = L"lbl_Address1";
			// 
			// lbl_Address2
			// 
			resources->ApplyResources(this->lbl_Address2, L"lbl_Address2");
			this->lbl_Address2->Name = L"lbl_Address2";
			// 
			// lbl_StfID
			// 
			resources->ApplyResources(this->lbl_StfID, L"lbl_StfID");
			this->lbl_StfID->Name = L"lbl_StfID";
			// 
			// lbl_StfName
			// 
			resources->ApplyResources(this->lbl_StfName, L"lbl_StfName");
			this->lbl_StfName->Name = L"lbl_StfName";
			// 
			// btn_DelConfirm
			// 
			resources->ApplyResources(this->btn_DelConfirm, L"btn_DelConfirm");
			this->btn_DelConfirm->Name = L"btn_DelConfirm";
			this->btn_DelConfirm->UseVisualStyleBackColor = true;
			this->btn_DelConfirm->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_DelConfirm_Click);
			// 
			// lbl_Prompt_ItemFnd
			// 
			resources->ApplyResources(this->lbl_Prompt_ItemFnd, L"lbl_Prompt_ItemFnd");
			this->lbl_Prompt_ItemFnd->Name = L"lbl_Prompt_ItemFnd";
			// 
			// OrderInfoPage
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->lbl_Prompt_ItemFnd);
			this->Controls->Add(this->btn_DelConfirm);
			this->Controls->Add(this->lbl_StfName);
			this->Controls->Add(this->lbl_StfID);
			this->Controls->Add(this->lbl_Address2);
			this->Controls->Add(this->lbl_Address1);
			this->Controls->Add(this->lbl_Postal);
			this->Controls->Add(this->lbl_City);
			this->Controls->Add(this->lbl_Country);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_MemName);
			this->Controls->Add(this->lbl_MemID);
			this->Controls->Add(this->lbl_Sbmtime);
			this->Controls->Add(this->lbl_OdrId);
			this->Controls->Add(this->lbl_DBError);
			this->Controls->Add(this->rtxt_Content);
			this->Controls->Add(this->lbl_Content);
			this->Controls->Add(this->txt_OdrAmt);
			this->Controls->Add(this->txt_OdrStat);
			this->Controls->Add(this->txt_ItemId);
			this->Controls->Add(this->txt_ItemName);
			this->Controls->Add(this->lbl_ItemName);
			this->Controls->Add(this->lbl_ItemId);
			this->Controls->Add(this->lbl_OdrPrice);
			this->Controls->Add(this->lbl_OdrAmt);
			this->Controls->Add(this->lbl_OdrStat);
			this->Controls->Add(this->btn_Check);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_Content);
			this->Controls->Add(this->lbl_Prompt_ItemPrice);
			this->Controls->Add(this->lbl_Prompt_ItemAmt);
			this->Controls->Add(this->lbl_Prompt_ItemName);
			this->Controls->Add(this->lbl_Prompt_ItemId);
			this->Controls->Add(this->lbl_Prompt_StfName);
			this->Controls->Add(this->lbl_Prompt_StfID);
			this->Controls->Add(this->lbl_Prompt_Address2);
			this->Controls->Add(this->lbl_Prompt_Address1);
			this->Controls->Add(this->lbl_Prompt_Postal);
			this->Controls->Add(this->lbl_Prompt_City);
			this->Controls->Add(this->lbl_Prompt_Country);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_MemName);
			this->Controls->Add(this->lbl_Prompt_MemID);
			this->Controls->Add(this->lbl_Prompt_SbmTime);
			this->Controls->Add(this->lbl_Prompt_OdrStat);
			this->Controls->Add(this->lbl_Prompt_OdrId);
			this->Name = L"OrderInfoPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Database^ database;
			int^ odrId;
			double^ item_price;
		private:
			Void UpdateInfo();
			Void btn_Change_Click(System::Object^ sender, System::EventArgs^ e);
			Void btn_Check_Click(System::Object^ sender, System::EventArgs^ e);
			Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
			Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
			Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
			Void btn_DelConfirm_Click(System::Object^ sender, System::EventArgs^ e);
};
}
