#pragma once

namespace ZaniahSystems {

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
				cbOptionsShow1000->Checked = pb;

			}
		}

		property bool propSaveDate
		{
			bool get()
			{
				// return the value of the private field
				return cbSaveDateToLog->Checked;
			}
			void set(bool sd)
			{
				// return the value of the private field
				cbSaveDateToLog->Checked = sd;

			}
		}

		property bool propSaveTime
		{
			bool get()
			{
				// return the value of the private field
				return cbSaveTimeToLog->Checked;
			}
			void set(bool st)
			{
				// return the value of the private field
				cbSaveTimeToLog->Checked = st;

			}
		}
		property String^ propCtPlace
		{
			String^ get()
			{
				// return the value of the private field
				return numWeightDecPlaces->Text;
			}
			void set(String^ ndec)
			{
				// return the value of the private field
				numWeightDecPlaces->Text = ndec;

			}
		}
	private: System::Windows::Forms::Button^ btnCloseOptions;
	private: System::Windows::Forms::CheckBox^ cbOptionsShow1000;
	private: System::Windows::Forms::Label^ lblHeaderPreferences;
	private: System::Windows::Forms::NumericUpDown^ numWeightDecPlaces;
	private: System::Windows::Forms::Label^ lblNumDecimalPlacesCtResult;
	private: System::Windows::Forms::CheckBox^ cbSaveTimeToLog;
	private: System::Windows::Forms::CheckBox^ cbSaveDateToLog;
	private: System::Windows::Forms::Label^ lblHelpOptions;

	protected:

	private:
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
			this->btnCloseOptions = (gcnew System::Windows::Forms::Button());
			this->cbOptionsShow1000 = (gcnew System::Windows::Forms::CheckBox());
			this->lblHeaderPreferences = (gcnew System::Windows::Forms::Label());
			this->numWeightDecPlaces = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblNumDecimalPlacesCtResult = (gcnew System::Windows::Forms::Label());
			this->cbSaveTimeToLog = (gcnew System::Windows::Forms::CheckBox());
			this->cbSaveDateToLog = (gcnew System::Windows::Forms::CheckBox());
			this->lblHelpOptions = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numWeightDecPlaces))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCloseOptions
			// 
			this->btnCloseOptions->Location = System::Drawing::Point(13, 156);
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
			this->cbOptionsShow1000->Location = System::Drawing::Point(13, 38);
			this->cbOptionsShow1000->Name = L"cbOptionsShow1000";
			this->cbOptionsShow1000->Size = System::Drawing::Size(168, 17);
			this->cbOptionsShow1000->TabIndex = 4;
			this->cbOptionsShow1000->Text = L"Show 1/1000ct for all stones\?";
			this->cbOptionsShow1000->UseVisualStyleBackColor = true;
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
			// numWeightDecPlaces
			// 
			this->numWeightDecPlaces->Location = System::Drawing::Point(13, 61);
			this->numWeightDecPlaces->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numWeightDecPlaces->Name = L"numWeightDecPlaces";
			this->numWeightDecPlaces->Size = System::Drawing::Size(37, 20);
			this->numWeightDecPlaces->TabIndex = 11;
			this->numWeightDecPlaces->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// lblNumDecimalPlacesCtResult
			// 
			this->lblNumDecimalPlacesCtResult->AutoSize = true;
			this->lblNumDecimalPlacesCtResult->Location = System::Drawing::Point(70, 63);
			this->lblNumDecimalPlacesCtResult->Name = L"lblNumDecimalPlacesCtResult";
			this->lblNumDecimalPlacesCtResult->Size = System::Drawing::Size(135, 13);
			this->lblNumDecimalPlacesCtResult->TabIndex = 12;
			this->lblNumDecimalPlacesCtResult->Text = L"Decimal Places Weight (ct)";
			// 
			// cbSaveTimeToLog
			// 
			this->cbSaveTimeToLog->AutoSize = true;
			this->cbSaveTimeToLog->Location = System::Drawing::Point(13, 99);
			this->cbSaveTimeToLog->Name = L"cbSaveTimeToLog";
			this->cbSaveTimeToLog->Size = System::Drawing::Size(116, 17);
			this->cbSaveTimeToLog->TabIndex = 13;
			this->cbSaveTimeToLog->Text = L"Save Time to Log\?";
			this->cbSaveTimeToLog->UseVisualStyleBackColor = true;
			// 
			// cbSaveDateToLog
			// 
			this->cbSaveDateToLog->AutoSize = true;
			this->cbSaveDateToLog->Location = System::Drawing::Point(12, 122);
			this->cbSaveDateToLog->Name = L"cbSaveDateToLog";
			this->cbSaveDateToLog->Size = System::Drawing::Size(126, 17);
			this->cbSaveDateToLog->TabIndex = 14;
			this->cbSaveDateToLog->Text = L"Save Date To Log\?\?";
			this->cbSaveDateToLog->UseVisualStyleBackColor = true;
			// 
			// lblHelpOptions
			// 
			this->lblHelpOptions->AutoSize = true;
			this->lblHelpOptions->ForeColor = System::Drawing::SystemColors::Highlight;
			this->lblHelpOptions->Location = System::Drawing::Point(143, 161);
			this->lblHelpOptions->Name = L"lblHelpOptions";
			this->lblHelpOptions->Size = System::Drawing::Size(163, 13);
			this->lblHelpOptions->TabIndex = 15;
			this->lblHelpOptions->Text = L"Changes are saved automatically";
			// 
			// OptionsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 194);
			this->Controls->Add(this->lblHelpOptions);
			this->Controls->Add(this->cbSaveDateToLog);
			this->Controls->Add(this->cbSaveTimeToLog);
			this->Controls->Add(this->lblNumDecimalPlacesCtResult);
			this->Controls->Add(this->numWeightDecPlaces);
			this->Controls->Add(this->lblHeaderPreferences);
			this->Controls->Add(this->cbOptionsShow1000);
			this->Controls->Add(this->btnCloseOptions);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(350, 233);
			this->MinimizeBox = false;
			this->Name = L"OptionsForm";
			this->Text = L"Preferences";
			this->Load += gcnew System::EventHandler(this, &OptionsForm::OptionsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numWeightDecPlaces))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnCloseOptions_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Visible = false;
		//Application::Restart();
		//Form1^ f1 = gcnew Form1;
		//f1->Refresh();
		//Hide();
	}
	private: System::Void OptionsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");
	}
	};
}
