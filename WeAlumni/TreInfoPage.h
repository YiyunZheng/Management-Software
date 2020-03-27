#include "Database.h"
#include "string"
#pragma once

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// TreInfoPage 摘要
	/// </summary>
	public ref class TreInfoPage : public System::Windows::Forms::Form
	{
	public:
		
		TreInfoPage(void)
		{
			InitializeComponent( );

			//
			//TODO:  在此处添加构造函数代码
			//
		}
		TreInfoPage(String^ OId)
		{
			InitializeComponent();
			OrderId = OId;
			UpdatePageInfo(OrderId);

			//
			//TODO:  在此处添加构造函数代码
			//
		}
		
		
		

		
		

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~TreInfoPage()
		{
			if (components)
			{
				delete components;
			}
			_DataDB->~Database();
			_TreDB->~Database();
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::Label^ ID;
	private: System::Windows::Forms::Label^ Time;
	private: System::Windows::Forms::Label^ StfId;
	private: System::Windows::Forms::Label^ StfName;
	private: System::Windows::Forms::Label^ Dept;
	private: System::Windows::Forms::Label^ Position;
	private: System::Windows::Forms::Label^ Amount;
	private: System::Windows::Forms::Label^ Comment;
	private: System::Windows::Forms::TextBox^ IdText;
	private: System::Windows::Forms::TextBox^ StfText;


	private: System::Windows::Forms::TextBox^ TimeText;
	private: System::Windows::Forms::TextBox^ AmountText;


	private: System::Windows::Forms::TextBox^ DeptText;
	private: System::Windows::Forms::TextBox^ PositionText;



	private: System::Windows::Forms::TextBox^ StfNameText;
	private: System::Windows::Forms::RichTextBox^ CommentText;
	private: System::Windows::Forms::Button^ ModTre;
	private: System::Windows::Forms::Button^ DelTre;
	private: System::Windows::Forms::Label^ IdShow;
	private: System::Windows::Forms::Label^ TimeShow;
	private: System::Windows::Forms::Label^ StfIdShow;
	private: System::Windows::Forms::Label^ DepartmentShow;
	private: System::Windows::Forms::Label^ StfNameShow;
	private: System::Windows::Forms::Label^ PositionShow;
	private: System::Windows::Forms::Label^ AmountShow;
	private: System::Windows::Forms::Label^ CommentShow;
	private: System::Windows::Forms::Label^ TypeShow;
	private: System::Windows::Forms::TextBox^ TypeText;


	private: System::Windows::Forms::Label^ Type;
	private: System::Windows::Forms::Button^ CancelMod;
	private: System::Windows::Forms::Button^ ConfirmMod;









	protected:

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->Title = (gcnew System::Windows::Forms::Label());
			this->ID = (gcnew System::Windows::Forms::Label());
			this->Time = (gcnew System::Windows::Forms::Label());
			this->StfId = (gcnew System::Windows::Forms::Label());
			this->StfName = (gcnew System::Windows::Forms::Label());
			this->Dept = (gcnew System::Windows::Forms::Label());
			this->Position = (gcnew System::Windows::Forms::Label());
			this->Amount = (gcnew System::Windows::Forms::Label());
			this->Comment = (gcnew System::Windows::Forms::Label());
			this->IdText = (gcnew System::Windows::Forms::TextBox());
			this->StfText = (gcnew System::Windows::Forms::TextBox());
			this->TimeText = (gcnew System::Windows::Forms::TextBox());
			this->AmountText = (gcnew System::Windows::Forms::TextBox());
			this->DeptText = (gcnew System::Windows::Forms::TextBox());
			this->PositionText = (gcnew System::Windows::Forms::TextBox());
			this->StfNameText = (gcnew System::Windows::Forms::TextBox());
			this->CommentText = (gcnew System::Windows::Forms::RichTextBox());
			this->ModTre = (gcnew System::Windows::Forms::Button());
			this->DelTre = (gcnew System::Windows::Forms::Button());
			this->IdShow = (gcnew System::Windows::Forms::Label());
			this->TimeShow = (gcnew System::Windows::Forms::Label());
			this->StfIdShow = (gcnew System::Windows::Forms::Label());
			this->DepartmentShow = (gcnew System::Windows::Forms::Label());
			this->StfNameShow = (gcnew System::Windows::Forms::Label());
			this->PositionShow = (gcnew System::Windows::Forms::Label());
			this->AmountShow = (gcnew System::Windows::Forms::Label());
			this->CommentShow = (gcnew System::Windows::Forms::Label());
			this->TypeShow = (gcnew System::Windows::Forms::Label());
			this->TypeText = (gcnew System::Windows::Forms::TextBox());
			this->Type = (gcnew System::Windows::Forms::Label());
			this->CancelMod = (gcnew System::Windows::Forms::Button());
			this->ConfirmMod = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(566, 82);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(374, 48);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Treasury Info Page";
			this->Title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// ID
			// 
			this->ID->AutoSize = true;
			this->ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ID->Location = System::Drawing::Point(268, 201);
			this->ID->Name = L"ID";
			this->ID->Size = System::Drawing::Size(52, 40);
			this->ID->TabIndex = 1;
			this->ID->Text = L"ID";
			// 
			// Time
			// 
			this->Time->AutoSize = true;
			this->Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Time->Location = System::Drawing::Point(916, 201);
			this->Time->Name = L"Time";
			this->Time->Size = System::Drawing::Size(97, 40);
			this->Time->TabIndex = 2;
			this->Time->Text = L"Time";
			// 
			// StfId
			// 
			this->StfId->AutoSize = true;
			this->StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfId->Location = System::Drawing::Point(268, 300);
			this->StfId->Name = L"StfId";
			this->StfId->Size = System::Drawing::Size(136, 40);
			this->StfId->TabIndex = 3;
			this->StfId->Text = L"Staff ID";
			this->StfId->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// StfName
			// 
			this->StfName->AutoSize = true;
			this->StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfName->Location = System::Drawing::Point(916, 300);
			this->StfName->Name = L"StfName";
			this->StfName->Size = System::Drawing::Size(197, 40);
			this->StfName->TabIndex = 4;
			this->StfName->Text = L"Staff Name";
			// 
			// Dept
			// 
			this->Dept->AutoSize = true;
			this->Dept->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Dept->Location = System::Drawing::Point(268, 405);
			this->Dept->Name = L"Dept";
			this->Dept->Size = System::Drawing::Size(205, 40);
			this->Dept->TabIndex = 5;
			this->Dept->Text = L"Department";
			// 
			// Position
			// 
			this->Position->AutoSize = true;
			this->Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Position->Location = System::Drawing::Point(916, 405);
			this->Position->Name = L"Position";
			this->Position->Size = System::Drawing::Size(145, 40);
			this->Position->TabIndex = 6;
			this->Position->Text = L"Position";
			// 
			// Amount
			// 
			this->Amount->AutoSize = true;
			this->Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Amount->Location = System::Drawing::Point(916, 511);
			this->Amount->Name = L"Amount";
			this->Amount->Size = System::Drawing::Size(141, 40);
			this->Amount->TabIndex = 7;
			this->Amount->Text = L"Amount";
			// 
			// Comment
			// 
			this->Comment->AutoSize = true;
			this->Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Comment->Location = System::Drawing::Point(268, 609);
			this->Comment->Name = L"Comment";
			this->Comment->Size = System::Drawing::Size(173, 40);
			this->Comment->TabIndex = 8;
			this->Comment->Text = L"Comment";
			// 
			// IdText
			// 
			this->IdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IdText->Location = System::Drawing::Point(530, 208);
			this->IdText->Name = L"IdText";
			this->IdText->Size = System::Drawing::Size(196, 41);
			this->IdText->TabIndex = 9;
			this->IdText->Visible = false;
			// 
			// StfText
			// 
			this->StfText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfText->Location = System::Drawing::Point(530, 300);
			this->StfText->Name = L"StfText";
			this->StfText->Size = System::Drawing::Size(196, 41);
			this->StfText->TabIndex = 10;
			this->StfText->Visible = false;
			// 
			// TimeText
			// 
			this->TimeText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeText->Location = System::Drawing::Point(1145, 208);
			this->TimeText->Name = L"TimeText";
			this->TimeText->Size = System::Drawing::Size(189, 41);
			this->TimeText->TabIndex = 11;
			this->TimeText->Visible = false;
			// 
			// AmountText
			// 
			this->AmountText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AmountText->Location = System::Drawing::Point(1138, 510);
			this->AmountText->Name = L"AmountText";
			this->AmountText->Size = System::Drawing::Size(196, 41);
			this->AmountText->TabIndex = 13;
			this->AmountText->Visible = false;
			// 
			// DeptText
			// 
			this->DeptText->Location = System::Drawing::Point(530, 405);
			this->DeptText->Name = L"DeptText";
			this->DeptText->Size = System::Drawing::Size(196, 35);
			this->DeptText->TabIndex = 14;
			this->DeptText->Visible = false;
			// 
			// PositionText
			// 
			this->PositionText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PositionText->Location = System::Drawing::Point(1145, 412);
			this->PositionText->Name = L"PositionText";
			this->PositionText->Size = System::Drawing::Size(189, 41);
			this->PositionText->TabIndex = 16;
			this->PositionText->Visible = false;
			// 
			// StfNameText
			// 
			this->StfNameText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfNameText->Location = System::Drawing::Point(1145, 307);
			this->StfNameText->Name = L"StfNameText";
			this->StfNameText->Size = System::Drawing::Size(189, 41);
			this->StfNameText->TabIndex = 17;
			this->StfNameText->Visible = false;
			// 
			// CommentText
			// 
			this->CommentText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CommentText->Location = System::Drawing::Point(275, 703);
			this->CommentText->Name = L"CommentText";
			this->CommentText->Size = System::Drawing::Size(1034, 289);
			this->CommentText->TabIndex = 18;
			this->CommentText->Text = L"";
			this->CommentText->Visible = false;
			// 
			// ModTre
			// 
			this->ModTre->Location = System::Drawing::Point(444, 1117);
			this->ModTre->Name = L"ModTre";
			this->ModTre->Size = System::Drawing::Size(213, 117);
			this->ModTre->TabIndex = 19;
			this->ModTre->Text = L"Modify Record";
			this->ModTre->UseVisualStyleBackColor = true;
			this->ModTre->Click += gcnew System::EventHandler(this, &TreInfoPage::ModTre_Click);
			// 
			// DelTre
			// 
			this->DelTre->Location = System::Drawing::Point(923, 1117);
			this->DelTre->Name = L"DelTre";
			this->DelTre->Size = System::Drawing::Size(213, 113);
			this->DelTre->TabIndex = 20;
			this->DelTre->Text = L"Delete Record";
			this->DelTre->UseVisualStyleBackColor = true;
			// 
			// IdShow
			// 
			this->IdShow->AutoSize = true;
			this->IdShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IdShow->Location = System::Drawing::Point(524, 211);
			this->IdShow->Name = L"IdShow";
			this->IdShow->Size = System::Drawing::Size(32, 36);
			this->IdShow->TabIndex = 21;
			this->IdShow->Text = L"0";
			// 
			// TimeShow
			// 
			this->TimeShow->AutoSize = true;
			this->TimeShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TimeShow->Location = System::Drawing::Point(1139, 211);
			this->TimeShow->Name = L"TimeShow";
			this->TimeShow->Size = System::Drawing::Size(155, 36);
			this->TimeShow->TabIndex = 22;
			this->TimeShow->Text = L"TimeShow";
			// 
			// StfIdShow
			// 
			this->StfIdShow->AutoSize = true;
			this->StfIdShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfIdShow->Location = System::Drawing::Point(524, 303);
			this->StfIdShow->Name = L"StfIdShow";
			this->StfIdShow->Size = System::Drawing::Size(152, 36);
			this->StfIdShow->TabIndex = 23;
			this->StfIdShow->Text = L"StfIdShow";
			// 
			// DepartmentShow
			// 
			this->DepartmentShow->AutoSize = true;
			this->DepartmentShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartmentShow->Location = System::Drawing::Point(524, 409);
			this->DepartmentShow->Name = L"DepartmentShow";
			this->DepartmentShow->Size = System::Drawing::Size(243, 36);
			this->DepartmentShow->TabIndex = 24;
			this->DepartmentShow->Text = L"DepartmentShow";
			// 
			// StfNameShow
			// 
			this->StfNameShow->AutoSize = true;
			this->StfNameShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StfNameShow->Location = System::Drawing::Point(1139, 310);
			this->StfNameShow->Name = L"StfNameShow";
			this->StfNameShow->Size = System::Drawing::Size(204, 36);
			this->StfNameShow->TabIndex = 25;
			this->StfNameShow->Text = L"StfNameShow";
			// 
			// PositionShow
			// 
			this->PositionShow->AutoSize = true;
			this->PositionShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PositionShow->Location = System::Drawing::Point(1139, 409);
			this->PositionShow->Name = L"PositionShow";
			this->PositionShow->Size = System::Drawing::Size(199, 36);
			this->PositionShow->TabIndex = 26;
			this->PositionShow->Text = L"PositionShow";
			// 
			// AmountShow
			// 
			this->AmountShow->AutoSize = true;
			this->AmountShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AmountShow->Location = System::Drawing::Point(1139, 513);
			this->AmountShow->Name = L"AmountShow";
			this->AmountShow->Size = System::Drawing::Size(194, 36);
			this->AmountShow->TabIndex = 27;
			this->AmountShow->Text = L"AmountShow";
			// 
			// CommentShow
			// 
			this->CommentShow->AutoSize = true;
			this->CommentShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CommentShow->Location = System::Drawing::Point(278, 706);
			this->CommentShow->Name = L"CommentShow";
			this->CommentShow->Size = System::Drawing::Size(216, 36);
			this->CommentShow->TabIndex = 28;
			this->CommentShow->Text = L"CommentShow";
			// 
			// TypeShow
			// 
			this->TypeShow->AutoSize = true;
			this->TypeShow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TypeShow->Location = System::Drawing::Point(524, 510);
			this->TypeShow->Name = L"TypeShow";
			this->TypeShow->Size = System::Drawing::Size(157, 36);
			this->TypeShow->TabIndex = 31;
			this->TypeShow->Text = L"TypeShow";
			// 
			// TypeText
			// 
			this->TypeText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TypeText->Location = System::Drawing::Point(530, 508);
			this->TypeText->Name = L"TypeText";
			this->TypeText->Size = System::Drawing::Size(196, 41);
			this->TypeText->TabIndex = 30;
			this->TypeText->Visible = false;
			// 
			// Type
			// 
			this->Type->AutoSize = true;
			this->Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Type->Location = System::Drawing::Point(268, 511);
			this->Type->Name = L"Type";
			this->Type->Size = System::Drawing::Size(97, 40);
			this->Type->TabIndex = 29;
			this->Type->Text = L"Type";
			// 
			// CancelMod
			// 
			this->CancelMod->ForeColor = System::Drawing::Color::Red;
			this->CancelMod->Location = System::Drawing::Point(923, 1113);
			this->CancelMod->Name = L"CancelMod";
			this->CancelMod->Size = System::Drawing::Size(213, 113);
			this->CancelMod->TabIndex = 33;
			this->CancelMod->Text = L"Cancel Modify";
			this->CancelMod->UseVisualStyleBackColor = true;
			this->CancelMod->Visible = false;
			// 
			// ConfirmMod
			// 
			this->ConfirmMod->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ConfirmMod->Location = System::Drawing::Point(444, 1113);
			this->ConfirmMod->Name = L"ConfirmMod";
			this->ConfirmMod->Size = System::Drawing::Size(213, 117);
			this->ConfirmMod->TabIndex = 32;
			this->ConfirmMod->Text = L"Confirm Modify";
			this->ConfirmMod->UseVisualStyleBackColor = true;
			this->ConfirmMod->Visible = false;
			this->ConfirmMod->Click += gcnew System::EventHandler(this, &TreInfoPage::ConfirmMod_Click);
			// 
			// TreInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1583, 1402);
			this->Controls->Add(this->CancelMod);
			this->Controls->Add(this->ConfirmMod);
			this->Controls->Add(this->TypeShow);
			this->Controls->Add(this->TypeText);
			this->Controls->Add(this->Type);
			this->Controls->Add(this->CommentShow);
			this->Controls->Add(this->AmountShow);
			this->Controls->Add(this->PositionShow);
			this->Controls->Add(this->StfNameShow);
			this->Controls->Add(this->DepartmentShow);
			this->Controls->Add(this->StfIdShow);
			this->Controls->Add(this->TimeShow);
			this->Controls->Add(this->IdShow);
			this->Controls->Add(this->DelTre);
			this->Controls->Add(this->ModTre);
			this->Controls->Add(this->CommentText);
			this->Controls->Add(this->StfNameText);
			this->Controls->Add(this->PositionText);
			this->Controls->Add(this->DeptText);
			this->Controls->Add(this->AmountText);
			this->Controls->Add(this->TimeText);
			this->Controls->Add(this->StfText);
			this->Controls->Add(this->IdText);
			this->Controls->Add(this->Comment);
			this->Controls->Add(this->Amount);
			this->Controls->Add(this->Position);
			this->Controls->Add(this->Dept);
			this->Controls->Add(this->StfName);
			this->Controls->Add(this->StfId);
			this->Controls->Add(this->Time);
			this->Controls->Add(this->ID);
			this->Controls->Add(this->Title);
			this->Name = L"TreInfoPage";
			this->Text = L"TreInfoPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
	private: Void UpdatePageInfo(String^ OrderId);
	private: String^ OrderId;
	private: Database^ _TreDB = gcnew Database(Database::DatabaseType::Treasury);
	private: Database^ _DataDB = gcnew Database(Database::DatabaseType::Data);

	

	private: System::Void ModTre_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void WeAlumni::TreInfoPage::SetShowLabelStatus(bool);
	private: System::Void WeAlumni::TreInfoPage::SetTextStatus(bool);
	private: System::Void WeAlumni::TreInfoPage::SetShowToText(bool);
	private: System::Void WeAlumni::TreInfoPage::SetButtonStatus(bool);

	private: System::Void ConfirmMod_Click(System::Object^ sender, System::EventArgs^ e);
	private: int WeAlumni::TreInfoPage::UpdateDB();
};
}
