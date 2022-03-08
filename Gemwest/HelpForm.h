#pragma once
#include"pch.h"
#include "CEmbeddedImage.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace ZaniahSystems {

	using namespace System;
	using namespace System::Windows::Forms;


	/// <summary>
	/// Summary for HelpForm
	/// </summary>
	public ref class HelpForm : public System::Windows::Forms::Form
	{
	public:
		HelpForm(void)
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
		~HelpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblHelpHeading;
	protected:
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::LinkLabel^ linkSourceforge;
	private: System::Windows::Forms::RichTextBox^ richTextHelp;
	private: System::Windows::Forms::PictureBox^ picBackdrop;
	private: System::Windows::Forms::LinkLabel^ linkReportError;
	private: System::Windows::Forms::Label^ label1;
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
			this->lblHelpHeading = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkSourceforge = (gcnew System::Windows::Forms::LinkLabel());
			this->richTextHelp = (gcnew System::Windows::Forms::RichTextBox());
			this->picBackdrop = (gcnew System::Windows::Forms::PictureBox());
			this->linkReportError = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBackdrop))->BeginInit();
			this->SuspendLayout();
			// 
			// lblHelpHeading
			// 
			this->lblHelpHeading->AutoSize = true;
			this->lblHelpHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHelpHeading->Location = System::Drawing::Point(195, 9);
			this->lblHelpHeading->Name = L"lblHelpHeading";
			this->lblHelpHeading->Size = System::Drawing::Size(94, 33);
			this->lblHelpHeading->TabIndex = 0;
			this->lblHelpHeading->Text = L"HELP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 1;
			// 
			// linkSourceforge
			// 
			this->linkSourceforge->AutoSize = true;
			this->linkSourceforge->Location = System::Drawing::Point(139, 195);
			this->linkSourceforge->Name = L"linkSourceforge";
			this->linkSourceforge->Size = System::Drawing::Size(211, 13);
			this->linkSourceforge->TabIndex = 3;
			this->linkSourceforge->TabStop = true;
			this->linkSourceforge->Text = L"https://sourceforge.net/projects/gemwest/";
			this->linkSourceforge->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &HelpForm::linkSourceforge_LinkClicked);
			// 
			// richTextHelp
			// 
			this->richTextHelp->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextHelp->Cursor = System::Windows::Forms::Cursors::No;
			this->richTextHelp->Location = System::Drawing::Point(20, 55);
			this->richTextHelp->Name = L"richTextHelp";
			this->richTextHelp->ReadOnly = true;
			this->richTextHelp->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::None;
			this->richTextHelp->Size = System::Drawing::Size(460, 131);
			this->richTextHelp->TabIndex = 4;
			this->richTextHelp->Text = L"";
			// 
			// picBackdrop
			// 
			this->picBackdrop->Location = System::Drawing::Point(76, 230);
			this->picBackdrop->Name = L"picBackdrop";
			this->picBackdrop->Size = System::Drawing::Size(320, 168);
			this->picBackdrop->TabIndex = 5;
			this->picBackdrop->TabStop = false;
			// 
			// linkReportError
			// 
			this->linkReportError->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->linkReportError->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->linkReportError->Location = System::Drawing::Point(142, 454);
			this->linkReportError->Name = L"linkReportError";
			this->linkReportError->Size = System::Drawing::Size(216, 21);
			this->linkReportError->TabIndex = 6;
			this->linkReportError->TabStop = true;
			this->linkReportError->Text = L"https://github.com/dnaldoog/Gemwest";
			this->linkReportError->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkReportError->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &HelpForm::linkReportError_LinkClicked);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(191, 431);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Report errors to:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 511);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkReportError);
			this->Controls->Add(this->picBackdrop);
			this->Controls->Add(this->richTextHelp);
			this->Controls->Add(this->linkSourceforge);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblHelpHeading);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(516, 550);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(516, 550);
			this->Name = L"HelpForm";
			this->Text = L"Help";
			this->Load += gcnew System::EventHandler(this, &HelpForm::HelpForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBackdrop))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void HelpForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");

		auto resourceAssembly = Reflection::Assembly::GetExecutingAssembly();
		// .Resources is the name generated by resxgen, e.g., from the input file name Resources.resx
		auto resourceName = resourceAssembly->GetName()->Name + ".Resource";
		auto resourceManager = gcnew Resources::ResourceManager(resourceName, resourceAssembly);
		auto String1 = cli::safe_cast<String^>(resourceManager->GetObject("HelpText"));
		this->richTextHelp->Text = String1;

		CEmbeddedImage^ im = gcnew CEmbeddedImage;
		im->setName("helpbackdrop");
		this->picBackdrop->Image = im->getName();
	}
	private: System::Void linkSourceforge_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->linkSourceforge->LinkVisited = true;

		// Navigate to a URL.
		System::Diagnostics::Process::Start(WEBSF);
	}
	private: System::Void linkReportError_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->linkReportError->LinkVisited = true;
		// Navigate to a URL.
		System::Diagnostics::Process::Start(WEBGITHUB);
	}
};
}
