#pragma once
#include "CEmbeddedImage.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace CppCLRWinformsProjekt {

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
	private: System::Windows::Forms::PictureBox^ picHelpBackdrop;
	private: System::Windows::Forms::LinkLabel^ linkSourceforge;


	protected:

	protected:

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
			this->lblHelpHeading = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->picHelpBackdrop = (gcnew System::Windows::Forms::PictureBox());
			this->linkSourceforge = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHelpBackdrop))->BeginInit();
			this->SuspendLayout();
			// 
			// lblHelpHeading
			// 
			this->lblHelpHeading->AutoSize = true;
			this->lblHelpHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHelpHeading->Location = System::Drawing::Point(105, 9);
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
			// picHelpBackdrop
			// 
			this->picHelpBackdrop->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picHelpBackdrop->Dock = System::Windows::Forms::DockStyle::Left;
			this->picHelpBackdrop->Location = System::Drawing::Point(0, 0);
			this->picHelpBackdrop->MaximumSize = System::Drawing::Size(320, 168);
			this->picHelpBackdrop->Name = L"picHelpBackdrop";
			this->picHelpBackdrop->Size = System::Drawing::Size(320, 165);
			this->picHelpBackdrop->TabIndex = 2;
			this->picHelpBackdrop->TabStop = false;
			// 
			// linkSourceforge
			// 
			this->linkSourceforge->AutoSize = true;
			this->linkSourceforge->Location = System::Drawing::Point(58, 62);
			this->linkSourceforge->Name = L"linkSourceforge";
			this->linkSourceforge->Size = System::Drawing::Size(211, 13);
			this->linkSourceforge->TabIndex = 3;
			this->linkSourceforge->TabStop = true;
			this->linkSourceforge->Text = L"https://sourceforge.net/projects/gemwest/";
			this->linkSourceforge->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &HelpForm::linkSourceforge_LinkClicked);
			// 
			// HelpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 165);
			this->Controls->Add(this->linkSourceforge);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblHelpHeading);
			this->Controls->Add(this->picHelpBackdrop);
			this->Name = L"HelpForm";
			this->Text = L"Help";
			this->Load += gcnew System::EventHandler(this, &HelpForm::HelpForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picHelpBackdrop))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void HelpForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");

		CEmbeddedImage^ bd = gcnew CEmbeddedImage;
		bd->setName("helpbackdrop");
		
		this->picHelpBackdrop->Image = bd->getName();
	}
	private: System::Void linkSourceforge_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->linkSourceforge->LinkVisited = true;

		// Navigate to a URL.
		System::Diagnostics::Process::Start(WEBSF);
	}
};
}
