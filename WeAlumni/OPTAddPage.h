#pragma once
#include "Database.h"

/*
 * OPTAddPage.h
 *
 * This file includes functions of inserting new data into OPT table
 *
 * @author: Xiangdong Che
 * Revised: 4/01/20
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
	/// Summary for OPTAddPage
	/// </summary>
	public ref class OPTAddPage : public System::Windows::Forms::Form
	{
	public:
		OPTAddPage(int^ input)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_StfId = input;
			try {
				database = gcnew Database(Database::DatabaseType::Data);
				Initialize();
			}
			catch (Exception^ exception) {
				lbl_error->Text = exception->Message;
				lbl_error->ForeColor = Color::Red;
				lbl_error->Visible = true;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OPTAddPage()
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
	private: System::Windows::Forms::Label^ lbl_PageName;
	private: System::Windows::Forms::Label^ lbl_Promt_OPTID;
	private: System::Windows::Forms::Label^ lbl_OPTID;
	private: System::Windows::Forms::ComboBox^ cmb_Status;
	private: System::Windows::Forms::Label^ lbl_Prompt_Status;
	private: System::Windows::Forms::Label^ lbl_MemId;
	private: System::Windows::Forms::TextBox^ txt_MemId;
	private: System::Windows::Forms::Label^ lbl_MemName;
	private: System::Windows::Forms::TextBox^ txt_MemName;
	private: System::Windows::Forms::Button^ btn_Verify;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::Label^ lbl_StartDate;
	private: System::Windows::Forms::TextBox^ txt_StartDate;
	private: System::Windows::Forms::TextBox^ txt_EndDate;
	private: System::Windows::Forms::Label^ lbl_EndDate;
	private: System::Windows::Forms::TextBox^ txt_Title;
	private: System::Windows::Forms::Label^ lbl_Title;
	private: System::Windows::Forms::Label^ lbl_Position;
	private: System::Windows::Forms::RichTextBox^ txt_Position;
	private: System::Windows::Forms::TextBox^ txt_CardNumber;
	private: System::Windows::Forms::Label^ lbl_CardNumber;
	private: System::Windows::Forms::TextBox^ txt_CardStartDate;
	private: System::Windows::Forms::Label^ lbl_CardStartDate;
	private: System::Windows::Forms::TextBox^ txt_CardEndDate;
	private: System::Windows::Forms::Label^ lbl_CardEndDate;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Label^ lbl_StfId;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_PageName = (gcnew System::Windows::Forms::Label());
			this->lbl_Promt_OPTID = (gcnew System::Windows::Forms::Label());
			this->lbl_OPTID = (gcnew System::Windows::Forms::Label());
			this->cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			this->lbl_MemId = (gcnew System::Windows::Forms::Label());
			this->txt_MemId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_MemName = (gcnew System::Windows::Forms::Label());
			this->txt_MemName = (gcnew System::Windows::Forms::TextBox());
			this->btn_Verify = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_StartDate = (gcnew System::Windows::Forms::Label());
			this->txt_StartDate = (gcnew System::Windows::Forms::TextBox());
			this->txt_EndDate = (gcnew System::Windows::Forms::TextBox());
			this->lbl_EndDate = (gcnew System::Windows::Forms::Label());
			this->txt_Title = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Title = (gcnew System::Windows::Forms::Label());
			this->lbl_Position = (gcnew System::Windows::Forms::Label());
			this->txt_Position = (gcnew System::Windows::Forms::RichTextBox());
			this->txt_CardNumber = (gcnew System::Windows::Forms::TextBox());
			this->lbl_CardNumber = (gcnew System::Windows::Forms::Label());
			this->txt_CardStartDate = (gcnew System::Windows::Forms::TextBox());
			this->lbl_CardStartDate = (gcnew System::Windows::Forms::Label());
			this->txt_CardEndDate = (gcnew System::Windows::Forms::TextBox());
			this->lbl_CardEndDate = (gcnew System::Windows::Forms::Label());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_PageName
			// 
			this->lbl_PageName->AutoSize = true;
			this->lbl_PageName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PageName->Location = System::Drawing::Point(215, 9);
			this->lbl_PageName->Name = L"lbl_PageName";
			this->lbl_PageName->Size = System::Drawing::Size(153, 25);
			this->lbl_PageName->TabIndex = 0;
			this->lbl_PageName->Text = L"OPTAddPage";
			// 
			// lbl_Promt_OPTID
			// 
			this->lbl_Promt_OPTID->AutoSize = true;
			this->lbl_Promt_OPTID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Promt_OPTID->Location = System::Drawing::Point(18, 63);
			this->lbl_Promt_OPTID->Name = L"lbl_Promt_OPTID";
			this->lbl_Promt_OPTID->Size = System::Drawing::Size(20, 13);
			this->lbl_Promt_OPTID->TabIndex = 1;
			this->lbl_Promt_OPTID->Text = L"ID";
			// 
			// lbl_OPTID
			// 
			this->lbl_OPTID->AutoSize = true;
			this->lbl_OPTID->Location = System::Drawing::Point(104, 63);
			this->lbl_OPTID->Name = L"lbl_OPTID";
			this->lbl_OPTID->Size = System::Drawing::Size(27, 13);
			this->lbl_OPTID->TabIndex = 2;
			this->lbl_OPTID->Text = L"N/A";
			// 
			// cmb_Status
			// 
			this->cmb_Status->FormattingEnabled = true;
			this->cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Active", L"Invalid" });
			this->cmb_Status->Location = System::Drawing::Point(247, 59);
			this->cmb_Status->Name = L"cmb_Status";
			this->cmb_Status->Size = System::Drawing::Size(121, 21);
			this->cmb_Status->TabIndex = 4;
			// 
			// lbl_Prompt_Status
			// 
			this->lbl_Prompt_Status->AutoSize = true;
			this->lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Status->Location = System::Drawing::Point(182, 63);
			this->lbl_Prompt_Status->Name = L"lbl_Prompt_Status";
			this->lbl_Prompt_Status->Size = System::Drawing::Size(43, 13);
			this->lbl_Prompt_Status->TabIndex = 5;
			this->lbl_Prompt_Status->Text = L"Status";
			// 
			// lbl_MemId
			// 
			this->lbl_MemId->AutoSize = true;
			this->lbl_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemId->Location = System::Drawing::Point(18, 110);
			this->lbl_MemId->Name = L"lbl_MemId";
			this->lbl_MemId->Size = System::Drawing::Size(68, 13);
			this->lbl_MemId->TabIndex = 6;
			this->lbl_MemId->Text = L"Member ID";
			// 
			// txt_MemId
			// 
			this->txt_MemId->Location = System::Drawing::Point(104, 106);
			this->txt_MemId->Name = L"txt_MemId";
			this->txt_MemId->Size = System::Drawing::Size(100, 20);
			this->txt_MemId->TabIndex = 7;
			// 
			// lbl_MemName
			// 
			this->lbl_MemName->AutoSize = true;
			this->lbl_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemName->Location = System::Drawing::Point(223, 110);
			this->lbl_MemName->Name = L"lbl_MemName";
			this->lbl_MemName->Size = System::Drawing::Size(87, 13);
			this->lbl_MemName->TabIndex = 8;
			this->lbl_MemName->Text = L"Member Name";
			// 
			// txt_MemName
			// 
			this->txt_MemName->Location = System::Drawing::Point(320, 106);
			this->txt_MemName->Name = L"txt_MemName";
			this->txt_MemName->Size = System::Drawing::Size(100, 20);
			this->txt_MemName->TabIndex = 9;
			// 
			// btn_Verify
			// 
			this->btn_Verify->Location = System::Drawing::Point(504, 97);
			this->btn_Verify->Name = L"btn_Verify";
			this->btn_Verify->Size = System::Drawing::Size(103, 38);
			this->btn_Verify->TabIndex = 10;
			this->btn_Verify->Text = L"Verify";
			this->btn_Verify->UseVisualStyleBackColor = true;
			this->btn_Verify->Click += gcnew System::EventHandler(this, &OPTAddPage::btn_Verify_Click);
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(395, 63);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(51, 13);
			this->lbl_Prompt_StfId->TabIndex = 11;
			this->lbl_Prompt_StfId->Text = L"Staff ID";
			// 
			// lbl_StartDate
			// 
			this->lbl_StartDate->AutoSize = true;
			this->lbl_StartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StartDate->Location = System::Drawing::Point(18, 163);
			this->lbl_StartDate->Name = L"lbl_StartDate";
			this->lbl_StartDate->Size = System::Drawing::Size(65, 13);
			this->lbl_StartDate->TabIndex = 12;
			this->lbl_StartDate->Text = L"Start Date";
			// 
			// txt_StartDate
			// 
			this->txt_StartDate->Location = System::Drawing::Point(104, 159);
			this->txt_StartDate->Name = L"txt_StartDate";
			this->txt_StartDate->Size = System::Drawing::Size(100, 20);
			this->txt_StartDate->TabIndex = 13;
			// 
			// txt_EndDate
			// 
			this->txt_EndDate->Location = System::Drawing::Point(320, 159);
			this->txt_EndDate->Name = L"txt_EndDate";
			this->txt_EndDate->Size = System::Drawing::Size(100, 20);
			this->txt_EndDate->TabIndex = 15;
			// 
			// lbl_EndDate
			// 
			this->lbl_EndDate->AutoSize = true;
			this->lbl_EndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EndDate->Location = System::Drawing::Point(223, 163);
			this->lbl_EndDate->Name = L"lbl_EndDate";
			this->lbl_EndDate->Size = System::Drawing::Size(60, 13);
			this->lbl_EndDate->TabIndex = 14;
			this->lbl_EndDate->Text = L"End Date";
			// 
			// txt_Title
			// 
			this->txt_Title->Location = System::Drawing::Point(104, 224);
			this->txt_Title->Name = L"txt_Title";
			this->txt_Title->Size = System::Drawing::Size(100, 20);
			this->txt_Title->TabIndex = 17;
			// 
			// lbl_Title
			// 
			this->lbl_Title->AutoSize = true;
			this->lbl_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Title->Location = System::Drawing::Point(18, 228);
			this->lbl_Title->Name = L"lbl_Title";
			this->lbl_Title->Size = System::Drawing::Size(32, 13);
			this->lbl_Title->TabIndex = 16;
			this->lbl_Title->Text = L"Title";
			// 
			// lbl_Position
			// 
			this->lbl_Position->AutoSize = true;
			this->lbl_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Position->Location = System::Drawing::Point(223, 228);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(52, 13);
			this->lbl_Position->TabIndex = 18;
			this->lbl_Position->Text = L"Position";
			// 
			// txt_Position
			// 
			this->txt_Position->Location = System::Drawing::Point(320, 199);
			this->txt_Position->Name = L"txt_Position";
			this->txt_Position->Size = System::Drawing::Size(232, 70);
			this->txt_Position->TabIndex = 19;
			this->txt_Position->Text = L"";
			// 
			// txt_CardNumber
			// 
			this->txt_CardNumber->Location = System::Drawing::Point(104, 292);
			this->txt_CardNumber->Name = L"txt_CardNumber";
			this->txt_CardNumber->Size = System::Drawing::Size(100, 20);
			this->txt_CardNumber->TabIndex = 21;
			// 
			// lbl_CardNumber
			// 
			this->lbl_CardNumber->AutoSize = true;
			this->lbl_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CardNumber->Location = System::Drawing::Point(18, 296);
			this->lbl_CardNumber->Name = L"lbl_CardNumber";
			this->lbl_CardNumber->Size = System::Drawing::Size(80, 13);
			this->lbl_CardNumber->TabIndex = 20;
			this->lbl_CardNumber->Text = L"Card Number";
			// 
			// txt_CardStartDate
			// 
			this->txt_CardStartDate->Location = System::Drawing::Point(320, 292);
			this->txt_CardStartDate->Name = L"txt_CardStartDate";
			this->txt_CardStartDate->Size = System::Drawing::Size(100, 20);
			this->txt_CardStartDate->TabIndex = 23;
			// 
			// lbl_CardStartDate
			// 
			this->lbl_CardStartDate->AutoSize = true;
			this->lbl_CardStartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CardStartDate->Location = System::Drawing::Point(223, 296);
			this->lbl_CardStartDate->Name = L"lbl_CardStartDate";
			this->lbl_CardStartDate->Size = System::Drawing::Size(91, 13);
			this->lbl_CardStartDate->TabIndex = 22;
			this->lbl_CardStartDate->Text = L"Card StartDate";
			// 
			// txt_CardEndDate
			// 
			this->txt_CardEndDate->Location = System::Drawing::Point(546, 292);
			this->txt_CardEndDate->Name = L"txt_CardEndDate";
			this->txt_CardEndDate->Size = System::Drawing::Size(100, 20);
			this->txt_CardEndDate->TabIndex = 25;
			// 
			// lbl_CardEndDate
			// 
			this->lbl_CardEndDate->AutoSize = true;
			this->lbl_CardEndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CardEndDate->Location = System::Drawing::Point(454, 296);
			this->lbl_CardEndDate->Name = L"lbl_CardEndDate";
			this->lbl_CardEndDate->Size = System::Drawing::Size(86, 13);
			this->lbl_CardEndDate->TabIndex = 24;
			this->lbl_CardEndDate->Text = L"Card EndDate";
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Location = System::Drawing::Point(244, 354);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(109, 66);
			this->btn_Cancel->TabIndex = 27;
			this->btn_Cancel->Text = L"Cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &OPTAddPage::btn_Cancel_Click);
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Location = System::Drawing::Point(58, 354);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(109, 66);
			this->btn_Confirm->TabIndex = 28;
			this->btn_Confirm->Text = L"Confirm";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &OPTAddPage::btn_Confirm_Click);
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Location = System::Drawing::Point(488, 63);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(27, 13);
			this->lbl_StfId->TabIndex = 29;
			this->lbl_StfId->Text = L"N/A";
			// 
			// lbl_error
			// 
			this->lbl_error->AutoSize = true;
			this->lbl_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(405, 375);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(136, 25);
			this->lbl_error->TabIndex = 30;
			this->lbl_error->Text = L"System Error";
			this->lbl_error->Visible = false;
			// 
			// OPTAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 464);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->txt_CardEndDate);
			this->Controls->Add(this->lbl_CardEndDate);
			this->Controls->Add(this->txt_CardStartDate);
			this->Controls->Add(this->lbl_CardStartDate);
			this->Controls->Add(this->txt_CardNumber);
			this->Controls->Add(this->lbl_CardNumber);
			this->Controls->Add(this->txt_Position);
			this->Controls->Add(this->lbl_Position);
			this->Controls->Add(this->txt_Title);
			this->Controls->Add(this->lbl_Title);
			this->Controls->Add(this->txt_EndDate);
			this->Controls->Add(this->lbl_EndDate);
			this->Controls->Add(this->txt_StartDate);
			this->Controls->Add(this->lbl_StartDate);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->btn_Verify);
			this->Controls->Add(this->txt_MemName);
			this->Controls->Add(this->lbl_MemName);
			this->Controls->Add(this->txt_MemId);
			this->Controls->Add(this->lbl_MemId);
			this->Controls->Add(this->lbl_Prompt_Status);
			this->Controls->Add(this->cmb_Status);
			this->Controls->Add(this->lbl_OPTID);
			this->Controls->Add(this->lbl_Promt_OPTID);
			this->Controls->Add(this->lbl_PageName);
			this->Name = L"OPTAddPage";
			this->Text = L"OPTAddPage";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		Database^ database;
		int^ _StfId;

	private: 
		System::Void Initialize();
		System::Void SetBoxReadOnly();
		System::Void btn_Verify_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}