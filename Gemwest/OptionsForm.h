#pragma once
//#include "Form1.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OptionsForm
	/// </summary>
 
	public ref class OptionsForm : public System::Windows::Forms::Form
	{
	private:
	public:
		//void Form1 f(Form1^ f1);
		OptionsForm()
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
		~OptionsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		 property String^ proplimit
		{
			String^ get()
			{
				// return the value of the private field
				return num1000Limit->Text;
			}
		}

		 property bool prop1000
		 {
			 bool get()
			 {
				 // return the value of the private field
				 return cbOptionsShow1000->Checked;
			 }
			 void set(bool pb)
			 {
				 // return the value of the private field
				 cbOptionsShow1000->Checked=pb;

			 }
		 }		 
		 
		 property bool prop1000under
		 {
			 bool get()
			 {
				 // return the value of the private field
				 return cb1000forStonesUnder->Checked;
			 }
		 }

		 property bool propRecut
		 {
			 bool get()
			 {
				 // return the value of the private field
				 return cbRecutEstimation->Checked;
			 }
		 }

		 property bool propLogAll
		 {
			 bool get()
			 {
				 // return the value of the private field
				 return cbRecordToLog->Checked;
			 }
			 void set(bool pb)
			 {
				 // return the value of the private field
				 cbRecordToLog->Checked = pb;

			 }
		 }



	private: System::Windows::Forms::Button^ btnCloseOptions;
	private: System::Windows::Forms::CheckBox^ cbOptionsShow1000;
	private: System::Windows::Forms::CheckBox^ cb1000forStonesUnder;

	private: System::Windows::Forms::CheckBox^ cbRecutEstimation;

	private: System::Windows::Forms::NumericUpDown^ num1000Limit;
	private: System::Windows::Forms::Label^ lbl100mm;
	private: System::Windows::Forms::CheckBox^ cbRecordToLog;
	private: System::Windows::Forms::Label^ lblHeaderPreferences;

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
			this->btnCloseOptions = (gcnew System::Windows::Forms::Button());
			this->cbOptionsShow1000 = (gcnew System::Windows::Forms::CheckBox());
			this->cb1000forStonesUnder = (gcnew System::Windows::Forms::CheckBox());
			this->cbRecutEstimation = (gcnew System::Windows::Forms::CheckBox());
			this->num1000Limit = (gcnew System::Windows::Forms::NumericUpDown());
			this->lbl100mm = (gcnew System::Windows::Forms::Label());
			this->cbRecordToLog = (gcnew System::Windows::Forms::CheckBox());
			this->lblHeaderPreferences = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num1000Limit))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCloseOptions
			// 
			this->btnCloseOptions->Location = System::Drawing::Point(12, 134);
			this->btnCloseOptions->Name = L"btnCloseOptions";
			this->btnCloseOptions->Size = System::Drawing::Size(75, 23);
			this->btnCloseOptions->TabIndex = 3;
			this->btnCloseOptions->Text = L"Close";
			this->btnCloseOptions->UseVisualStyleBackColor = true;
			this->btnCloseOptions->Click += gcnew System::EventHandler(this, &OptionsForm::btnCloseOptions_Click);
			// 
			// cbOptionsShow1000
			// 
			this->cbOptionsShow1000->AutoSize = true;
			this->cbOptionsShow1000->Location = System::Drawing::Point(13, 51);
			this->cbOptionsShow1000->Name = L"cbOptionsShow1000";
			this->cbOptionsShow1000->Size = System::Drawing::Size(168, 17);
			this->cbOptionsShow1000->TabIndex = 4;
			this->cbOptionsShow1000->Text = L"Show 1/1000ct for all stones\?";
			this->cbOptionsShow1000->UseVisualStyleBackColor = true;
			// 
			// cb1000forStonesUnder
			// 
			this->cb1000forStonesUnder->AutoSize = true;
			this->cb1000forStonesUnder->Location = System::Drawing::Point(13, 5);
			this->cb1000forStonesUnder->Name = L"cb1000forStonesUnder";
			this->cb1000forStonesUnder->Size = System::Drawing::Size(191, 17);
			this->cb1000forStonesUnder->TabIndex = 5;
			this->cb1000forStonesUnder->Text = L"Show 1/1000ct for stones under ->";
			this->cb1000forStonesUnder->UseVisualStyleBackColor = true;
			this->cb1000forStonesUnder->Visible = false;
			// 
			// cbRecutEstimation
			// 
			this->cbRecutEstimation->AutoSize = true;
			this->cbRecutEstimation->Location = System::Drawing::Point(13, 76);
			this->cbRecutEstimation->Name = L"cbRecutEstimation";
			this->cbRecutEstimation->Size = System::Drawing::Size(120, 17);
			this->cbRecutEstimation->TabIndex = 6;
			this->cbRecutEstimation->Text = L"RECUT Estimation\?";
			this->cbRecutEstimation->UseVisualStyleBackColor = true;
			// 
			// num1000Limit
			// 
			this->num1000Limit->Location = System::Drawing::Point(198, 4);
			this->num1000Limit->Name = L"num1000Limit";
			this->num1000Limit->Size = System::Drawing::Size(47, 20);
			this->num1000Limit->TabIndex = 7;
			this->num1000Limit->Visible = false;
			// 
			// lbl100mm
			// 
			this->lbl100mm->AutoSize = true;
			this->lbl100mm->Location = System::Drawing::Point(251, 7);
			this->lbl100mm->Name = L"lbl100mm";
			this->lbl100mm->Size = System::Drawing::Size(23, 13);
			this->lbl100mm->TabIndex = 8;
			this->lbl100mm->Text = L"mm";
			this->lbl100mm->Visible = false;
			// 
			// cbRecordToLog
			// 
			this->cbRecordToLog->AutoSize = true;
			this->cbRecordToLog->Location = System::Drawing::Point(13, 101);
			this->cbRecordToLog->Name = L"cbRecordToLog";
			this->cbRecordToLog->Size = System::Drawing::Size(122, 17);
			this->cbRecordToLog->TabIndex = 9;
			this->cbRecordToLog->Text = L"Log all calculations\?";
			this->cbRecordToLog->UseVisualStyleBackColor = true;
			// 
			// lblHeaderPreferences
			// 
			this->lblHeaderPreferences->AutoSize = true;
			this->lblHeaderPreferences->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHeaderPreferences->Location = System::Drawing::Point(89, 9);
			this->lblHeaderPreferences->Name = L"lblHeaderPreferences";
			this->lblHeaderPreferences->Size = System::Drawing::Size(106, 20);
			this->lblHeaderPreferences->TabIndex = 10;
			this->lblHeaderPreferences->Text = L"Preferences";
			this->lblHeaderPreferences->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OptionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 184);
			this->Controls->Add(this->lblHeaderPreferences);
			this->Controls->Add(this->cbRecordToLog);
			this->Controls->Add(this->lbl100mm);
			this->Controls->Add(this->num1000Limit);
			this->Controls->Add(this->cbRecutEstimation);
			this->Controls->Add(this->cb1000forStonesUnder);
			this->Controls->Add(this->cbOptionsShow1000);
			this->Controls->Add(this->btnCloseOptions);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"OptionsForm";
			this->Text = L"Preferences";
			this->Load += gcnew System::EventHandler(this, &OptionsForm::OptionsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->num1000Limit))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCloseOptions_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		//Application::Restart();
		//Form1^ f1 = gcnew Form1;
		//f1->Refresh();
	}
private: System::Void OptionsForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
