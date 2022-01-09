#pragma once
#include "EmbeddedImage.h"

namespace CppCLRWinformsProjekt {
	using namespace System;
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
			this->pictureZaniahLogo = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureZaniahLogo))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureZaniahLogo
			// 
			this->pictureZaniahLogo->Location = System::Drawing::Point(103, 12);
			this->pictureZaniahLogo->Name = L"pictureZaniahLogo";
			this->pictureZaniahLogo->Size = System::Drawing::Size(78, 27);
			this->pictureZaniahLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureZaniahLogo->TabIndex = 0;
			this->pictureZaniahLogo->TabStop = false;
			this->pictureZaniahLogo->Tag = L"";
			// 
			// AboutForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureZaniahLogo);
			this->Name = L"AboutForm1";
			this->Text = L"AboutForm1";
			this->Load += gcnew System::EventHandler(this, &AboutForm1::AboutForm1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureZaniahLogo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void AboutForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		EmbeddedImage^ zimage = gcnew EmbeddedImage;
		zimage->setName("zaniah");
		this->pictureZaniahLogo->Image = zimage->getName();
		//this->ResumeLayout(false);
	}
	};
}
