#pragma once

namespace CppCLRWinformsProjekt {

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
	private: System::Windows::Forms::RichTextBox^ richTextLog;
	protected:


	private: System::Windows::Forms::Button^ btnCloseLogForm;
	private: System::Windows::Forms::Button^ clearLogForm;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->SuspendLayout();
			// 
			// richTextLog
			// 
			this->richTextLog->Location = System::Drawing::Point(12, 12);
			this->richTextLog->Name = L"richTextLog";
			this->richTextLog->Size = System::Drawing::Size(260, 200);
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
			// LogForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->clearLogForm);
			this->Controls->Add(this->btnCloseLogForm);
			this->Controls->Add(this->richTextLog);
			this->Name = L"LogForm";
			this->Text = L"LogForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCloseLogForm_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	private: System::Void clearLogForm_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		
	};
}
