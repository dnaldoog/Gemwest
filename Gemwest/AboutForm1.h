#pragma once
#include "CEmbeddedImage.h"

namespace ZaniahSystems {
	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutForm1
	/// </summary>
	public ref class AboutForm1 : public System::Windows::Forms::Form
	{
	public:
		AboutForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		String^ versionInformation() {
			auto resourceAssembly = Reflection::Assembly::GetExecutingAssembly();
			// .Resources is the name generated by resxgen, e.g., from the input file name Resources.resx
			auto resourceName = resourceAssembly->GetName()->Name + ".Resource";
			auto resourceManager = gcnew Resources::ResourceManager(resourceName, resourceAssembly);
			auto v = cli::safe_cast<String^>(resourceManager->GetObject("Version"));
			return v;
		}
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AboutForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureZaniahLogo;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ labelAbout;
	private: System::Windows::Forms::Label^ labelProgramTitle;
	private: System::Windows::Forms::Label^ labelVersion;
	private: System::Windows::Forms::PictureBox^ picAboutLogo;
	private: System::Windows::Forms::PictureBox^ picPayPal;
	private: System::Windows::Forms::Button^ btnCheckNewVersion;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::Label^ label1;

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
			this->pictureZaniahLogo = (gcnew System::Windows::Forms::PictureBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->labelAbout = (gcnew System::Windows::Forms::Label());
			this->labelProgramTitle = (gcnew System::Windows::Forms::Label());
			this->labelVersion = (gcnew System::Windows::Forms::Label());
			this->picAboutLogo = (gcnew System::Windows::Forms::PictureBox());
			this->picPayPal = (gcnew System::Windows::Forms::PictureBox());
			this->btnCheckNewVersion = (gcnew System::Windows::Forms::Button());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureZaniahLogo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAboutLogo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPayPal))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureZaniahLogo
			// 
			this->pictureZaniahLogo->Location = System::Drawing::Point(109, 222);
			this->pictureZaniahLogo->Name = L"pictureZaniahLogo";
			this->pictureZaniahLogo->Size = System::Drawing::Size(67, 22);
			this->pictureZaniahLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureZaniahLogo->TabIndex = 0;
			this->pictureZaniahLogo->TabStop = false;
			this->pictureZaniahLogo->Tag = L"";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(62, 141);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(160, 13);
			this->linkLabel1->TabIndex = 1;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://gemwest.sourceforge.io/";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm1::linkLabel1_LinkClicked);
			// 
			// labelAbout
			// 
			this->labelAbout->AutoSize = true;
			this->labelAbout->Location = System::Drawing::Point(22, 182);
			this->labelAbout->Name = L"labelAbout";
			this->labelAbout->Size = System::Drawing::Size(241, 26);
			this->labelAbout->TabIndex = 2;
			this->labelAbout->Text = L"Calculates the weight of a mounted gemstone,\r\nor a loose stone in the absence of "
				L"a set of scales.";
			this->labelAbout->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// labelProgramTitle
			// 
			this->labelProgramTitle->AutoSize = true;
			this->labelProgramTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelProgramTitle->Location = System::Drawing::Point(78, 89);
			this->labelProgramTitle->Name = L"labelProgramTitle";
			this->labelProgramTitle->Size = System::Drawing::Size(128, 25);
			this->labelProgramTitle->TabIndex = 3;
			this->labelProgramTitle->Text = L"GEMWEST";
			// 
			// labelVersion
			// 
			this->labelVersion->Location = System::Drawing::Point(117, 120);
			this->labelVersion->Name = L"labelVersion";
			this->labelVersion->Size = System::Drawing::Size(50, 13);
			this->labelVersion->TabIndex = 4;
			this->labelVersion->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// picAboutLogo
			// 
			this->picAboutLogo->Location = System::Drawing::Point(120, 26);
			this->picAboutLogo->Name = L"picAboutLogo";
			this->picAboutLogo->Size = System::Drawing::Size(48, 48);
			this->picAboutLogo->TabIndex = 5;
			this->picAboutLogo->TabStop = false;
			// 
			// picPayPal
			// 
			this->picPayPal->Location = System::Drawing::Point(200, 222);
			this->picPayPal->Name = L"picPayPal";
			this->picPayPal->Size = System::Drawing::Size(50, 36);
			this->picPayPal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPayPal->TabIndex = 6;
			this->picPayPal->TabStop = false;
			this->picPayPal->Tag = L"";
			this->picPayPal->Click += gcnew System::EventHandler(this, &AboutForm1::picPayPal_Click);
			// 
			// btnCheckNewVersion
			// 
			this->btnCheckNewVersion->Location = System::Drawing::Point(83, 266);
			this->btnCheckNewVersion->Name = L"btnCheckNewVersion";
			this->btnCheckNewVersion->Size = System::Drawing::Size(118, 23);
			this->btnCheckNewVersion->TabIndex = 7;
			this->btnCheckNewVersion->Text = L"Check new version";
			this->btnCheckNewVersion->UseVisualStyleBackColor = true;
			this->btnCheckNewVersion->Click += gcnew System::EventHandler(this, &AboutForm1::btnCheckNewVersion_Click);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->linkLabel2->Location = System::Drawing::Point(46, 334);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(193, 13);
			this->linkLabel2->TabIndex = 8;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"https://github.com/dnaldoog/Gemwest";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm1::linkLabel2_LinkClicked);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(83, 313);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Report errors to:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// AboutForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 361);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->btnCheckNewVersion);
			this->Controls->Add(this->picPayPal);
			this->Controls->Add(this->picAboutLogo);
			this->Controls->Add(this->labelVersion);
			this->Controls->Add(this->labelProgramTitle);
			this->Controls->Add(this->labelAbout);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->pictureZaniahLogo);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(300, 400);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(300, 400);
			this->Name = L"AboutForm1";
			this->Text = L"About";
			this->Load += gcnew System::EventHandler(this, &AboutForm1::AboutForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureZaniahLogo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picAboutLogo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPayPal))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void AboutForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		this->labelVersion->Text=versionInformation();
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");

		CEmbeddedImage^ logo = gcnew CEmbeddedImage;
		logo->setName("logo48");
		this->picAboutLogo->Image = logo->getName();

		CEmbeddedImage^ zimage = gcnew CEmbeddedImage;
		zimage->setName("zaniah");
		this->pictureZaniahLogo->Image = zimage->getName();

		CEmbeddedImage^ ppim = gcnew CEmbeddedImage;
		ppim->setName("paypallogo");
		this->picPayPal->Image = ppim->getName();
		//this->ResumeLayout(false);
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->linkLabel1->LinkVisited = true;

		// Navigate to a URL.
		System::Diagnostics::Process::Start(WEBSITE);
	}
private: System::Void picPayPal_Click(System::Object^ sender, System::EventArgs^ e) {
	
	// Navigate to a URL.
	System::Diagnostics::Process::Start(WEBPAYPAL);

}
private: System::Void btnCheckNewVersion_Click(System::Object^ sender, System::EventArgs^ e) {

	System::Diagnostics::Process::Start(WEBSITE+"?versioncheck="+ versionInformation());
}
private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

	this->linkLabel1->LinkVisited = true;

	// Navigate to a URL.
	System::Diagnostics::Process::Start(WEBGITHUB);
}
};
}
