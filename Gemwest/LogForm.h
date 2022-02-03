#pragma once
#include "BridgeCS.h"
namespace GemwestProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LogForm
	/// </summary>
	public ref class LogForm : public System::Windows::Forms::Form
	{
	public:
		LogForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LogForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^ richTextLog;
	protected:


	private: System::Windows::Forms::Button^ btnCloseLogForm;
	private: System::Windows::Forms::Button^ clearLogForm;
	private: System::Windows::Forms::Button^ btnSaveEdit;
	private: System::Windows::Forms::Button^ btnCopyCalcToClipboard;
	protected:

	private:
	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->richTextLog = (gcnew System::Windows::Forms::RichTextBox());
			this->btnCloseLogForm = (gcnew System::Windows::Forms::Button());
			this->clearLogForm = (gcnew System::Windows::Forms::Button());
			this->btnSaveEdit = (gcnew System::Windows::Forms::Button());
			this->btnCopyCalcToClipboard = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextLog
			// 
			this->richTextLog->Location = System::Drawing::Point(12, 12);
			this->richTextLog->Name = L"richTextLog";
			this->richTextLog->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextLog->Size = System::Drawing::Size(660, 200);
			this->richTextLog->TabIndex = 0;
			this->richTextLog->Text = L"";
			// 
			// btnCloseLogForm
			// 
			this->btnCloseLogForm->Location = System::Drawing::Point(12, 226);
			this->btnCloseLogForm->Name = L"btnCloseLogForm";
			this->btnCloseLogForm->Size = System::Drawing::Size(75, 23);
			this->btnCloseLogForm->TabIndex = 1;
			this->btnCloseLogForm->Text = L"close";
			this->btnCloseLogForm->UseVisualStyleBackColor = true;
			this->btnCloseLogForm->Click += gcnew System::EventHandler(this, &LogForm::btnCloseLogForm_Click);
			// 
			// clearLogForm
			// 
			this->clearLogForm->Location = System::Drawing::Point(93, 226);
			this->clearLogForm->Name = L"clearLogForm";
			this->clearLogForm->Size = System::Drawing::Size(75, 23);
			this->clearLogForm->TabIndex = 2;
			this->clearLogForm->Text = L"clear all\?";
			this->clearLogForm->UseVisualStyleBackColor = true;
			this->clearLogForm->Click += gcnew System::EventHandler(this, &LogForm::clearLogForm_Click);
			// 
			// btnSaveEdit
			// 
			this->btnSaveEdit->Location = System::Drawing::Point(174, 226);
			this->btnSaveEdit->Name = L"btnSaveEdit";
			this->btnSaveEdit->Size = System::Drawing::Size(75, 23);
			this->btnSaveEdit->TabIndex = 3;
			this->btnSaveEdit->Text = L"save ed&its\?";
			this->btnSaveEdit->UseVisualStyleBackColor = true;
			this->btnSaveEdit->Click += gcnew System::EventHandler(this, &LogForm::btnSaveEdit_Click);
			// 
			// btnCopyCalcToClipboard
			// 
			this->btnCopyCalcToClipboard->Location = System::Drawing::Point(255, 226);
			this->btnCopyCalcToClipboard->Name = L"btnCopyCalcToClipboard";
			this->btnCopyCalcToClipboard->Size = System::Drawing::Size(75, 23);
			this->btnCopyCalcToClipboard->TabIndex = 4;
			this->btnCopyCalcToClipboard->Text = L"c&opy all\?";
			this->btnCopyCalcToClipboard->UseVisualStyleBackColor = true;
			this->btnCopyCalcToClipboard->Click += gcnew System::EventHandler(this, &LogForm::btnCopyCalcToClipboard_Click);
			// 
			// LogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 261);
			this->Controls->Add(this->btnCopyCalcToClipboard);
			this->Controls->Add(this->btnSaveEdit);
			this->Controls->Add(this->clearLogForm);
			this->Controls->Add(this->btnCloseLogForm);
			this->Controls->Add(this->richTextLog);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(700, 300);
			this->Name = L"LogForm";
			this->Text = L"LogForm";
			this->Load += gcnew System::EventHandler(this, &LogForm::LogForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCloseLogForm_Click(System::Object^ sender, System::EventArgs^ e) {
		//		Close();
		Hide();
	}
	private: System::Void clearLogForm_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show(
			"Clear All Data?",
			"This cannot be undone!", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes)
			this->richTextLog->Clear();
	}

	private: System::Void LogForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");
	}
	private: System::Void btnSaveEdit_Click(System::Object^ sender, System::EventArgs^ e) {

		BridgeCS^ saveString = gcnew BridgeCS;
		saveString->propBridgeCalc = this->richTextLog->Text;
		MessageBox::Show("Changes Saved");
	}
	private: System::Void btnCopyCalcToClipboard_Click(System::Object^ sender, System::EventArgs^ e) {

		array<String^>^ lines = this->richTextLog->Lines;
		int count = lines->Length;
		if (count > 0) {
			Clipboard::SetDataObject(this->richTextLog->Text, true);
			MessageBox::Show("All data copied to clipboard!");
		}
		else {
			MessageBox::Show("Nothing to copy!");
		}
	}
	};
}
