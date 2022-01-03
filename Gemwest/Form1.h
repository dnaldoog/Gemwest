#pragma once
#include <map>
#include "DiamondCut.h"
#include "GemCut.h"
#include "EmbeddedImage.h"
#include "resource1.h"
namespace CppCLRWinformsProjekt {
//
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;
	using namespace System::Resources;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung f�r Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{


			InitializeComponent();

		}
			
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEq;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ txtDia1;
	private: System::Windows::Forms::TextBox^ txtDia2;
	private: System::Windows::Forms::TextBox^ txtDepth;

	private: System::Windows::Forms::Button^ buttonCalc;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::TextBox^ txtResult;

	private: System::Windows::Forms::Label^ lbllSelectedSG;

	private: System::Windows::Forms::TextBox^ txtSg;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ lblDepthPerc;
	private: System::Windows::Forms::Label^ lblLwRatio;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ radioBtnGem;
	private: System::Windows::Forms::RadioButton^ radioBtnDia;
	private: System::Windows::Forms::CheckBox^ cbRecut;
	private: System::Windows::Forms::CheckBox^ cbInterpolate;
	private: System::Windows::Forms::StatusStrip^ statusbar;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ logToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^ lblPavilionBulge;

	private: System::Windows::Forms::Label^ lblGirdleThickness;

	private: System::Windows::Forms::Label^ lblOther;

	private: System::Windows::Forms::Label^ lblGlobAdj;

	private: System::Windows::Forms::Label^ lblResult;

	private: System::Windows::Forms::Label^ lblDepth;

	private: System::Windows::Forms::Label^ lblDia2;

	private: System::Windows::Forms::Label^ lblDia1;
	private: System::Windows::Forms::TrackBar^ tbPavilionBulge;


	private: System::Windows::Forms::TrackBar^ tbGirdleThickness;
	private: System::Windows::Forms::TrackBar^ tbOtherNudge;
	private: System::Windows::Forms::TrackBar^ tbGlobalAdj;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ txtCutSel;
	private: System::Windows::Forms::Label^ lblSelectedCut;

	private: System::Windows::Forms::ComboBox^ comboCut;
	private: System::Windows::Forms::Label^ lblSgValue;
	private: System::Windows::Forms::Label^ lblCutFactor;
	private: System::Windows::Forms::ComboBox^ comboGems;
	private: System::Windows::Forms::TextBox^ txtPavilionBulge;
	private: System::Windows::Forms::TextBox^ txtGirdleThickness;
	private: System::Windows::Forms::TextBox^ txtOther;
	private: System::Windows::Forms::TextBox^ txtGlobAdjust;
	private: System::Windows::Forms::PictureBox^ picGem;
	private: System::Windows::Forms::PictureBox^ picCut;
	private: System::Windows::Forms::PictureBox^ picBulge;
	private: System::Windows::Forms::PictureBox^ picGirdle;
private: System::Windows::Forms::PictureBox^ picDepth;
private: System::Windows::Forms::ToolStripStatusLabel^ toolStrip;







	protected:




	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->comboGems = (gcnew System::Windows::Forms::ComboBox());
			this->btnEq = (gcnew System::Windows::Forms::Button());
			this->txtDia1 = (gcnew System::Windows::Forms::TextBox());
			this->txtDia2 = (gcnew System::Windows::Forms::TextBox());
			this->txtDepth = (gcnew System::Windows::Forms::TextBox());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->lbllSelectedSG = (gcnew System::Windows::Forms::Label());
			this->txtSg = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->picDepth = (gcnew System::Windows::Forms::PictureBox());
			this->txtPavilionBulge = (gcnew System::Windows::Forms::TextBox());
			this->txtGirdleThickness = (gcnew System::Windows::Forms::TextBox());
			this->txtOther = (gcnew System::Windows::Forms::TextBox());
			this->txtGlobAdjust = (gcnew System::Windows::Forms::TextBox());
			this->tbPavilionBulge = (gcnew System::Windows::Forms::TrackBar());
			this->tbGirdleThickness = (gcnew System::Windows::Forms::TrackBar());
			this->cbRecut = (gcnew System::Windows::Forms::CheckBox());
			this->tbOtherNudge = (gcnew System::Windows::Forms::TrackBar());
			this->cbInterpolate = (gcnew System::Windows::Forms::CheckBox());
			this->tbGlobalAdj = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->lblLwRatio = (gcnew System::Windows::Forms::Label());
			this->lblDepthPerc = (gcnew System::Windows::Forms::Label());
			this->lblPavilionBulge = (gcnew System::Windows::Forms::Label());
			this->lblGirdleThickness = (gcnew System::Windows::Forms::Label());
			this->lblOther = (gcnew System::Windows::Forms::Label());
			this->lblGlobAdj = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->lblDepth = (gcnew System::Windows::Forms::Label());
			this->lblDia2 = (gcnew System::Windows::Forms::Label());
			this->lblDia1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->picGirdle = (gcnew System::Windows::Forms::PictureBox());
			this->picBulge = (gcnew System::Windows::Forms::PictureBox());
			this->picGem = (gcnew System::Windows::Forms::PictureBox());
			this->picCut = (gcnew System::Windows::Forms::PictureBox());
			this->lblSgValue = (gcnew System::Windows::Forms::Label());
			this->lblCutFactor = (gcnew System::Windows::Forms::Label());
			this->txtCutSel = (gcnew System::Windows::Forms::TextBox());
			this->lblSelectedCut = (gcnew System::Windows::Forms::Label());
			this->comboCut = (gcnew System::Windows::Forms::ComboBox());
			this->radioBtnGem = (gcnew System::Windows::Forms::RadioButton());
			this->radioBtnDia = (gcnew System::Windows::Forms::RadioButton());
			this->statusbar = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDepth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPavilionBulge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGirdleThickness))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOtherNudge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGlobalAdj))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGirdle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBulge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGem))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCut))->BeginInit();
			this->statusbar->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboGems
			// 
			this->comboGems->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(186) {
				L"agate", L"albite", L"alexandrite",
					L"almandine", L"amazonite", L"amber", L"amethyst", L"andalusite", L"apatite", L"aquamarine", L"aragonite", L"aventurine quartz",
					L"aventurine", L"axinite (Ferro-axinite)", L"azurite", L"bakelite", L"benitoite", L"beryl aquamarine", L"beryl colourless", L"beryl heliodor",
					L"beryl morganite", L"beryl", L"beryl maxixe", L"blende", L"bloodstone", L"blue topaz", L"bonamite", L"bowenite", L"brazilianite",
					L"calcite", L"californite", L"carborundum", L"carnelian", L"cassiterite", L"cat\'s eye chrysoberyl", L"celluloid", L"chalcedony agate",
					L"chalcedony aventurine", L"chalcedony carnelian", L"chalcedony heliotrope", L"chalcedony moss agate", L"chalcedony onyx", L"chalcedony",
					L"chrome diopside", L"chrysoberyl alexandrite", L"chrysoberyl cat\'s eye", L"chrysoberyl cymophane", L"chrysoberyl", L"chrysocolla",
					L"chrysoprase", L"citrine", L"colourless beryl", L"conch pearl", L"copal resin", L"coral", L"cornelian", L"corundum ruby", L"corundum sapphire",
					L"corundum synthetic", L"corundum", L"crocidolite", L"cubic zirconia", L"cymophane", L"cz", L"danburite", L"datolite", L"demantoid",
					L"diamond", L"diopside", L"ekanite", L"emerald (Gilson)", L"emerald", L"enstatite", L"epidote", L"euclase", L"fibrolite", L"fire opal",
					L"fluorite", L"garnet almandine", L"garnet demantoid", L"garnet grossular (pure)", L"garnet hessonite", L"garnet (mali)", L"garnet pyrope",
					L"garnet spessartine", L"garnet uvarovite", L"garnet", L"ggg", L"glass", L"golden beryl", L"goshenite", L"grossular garnet",
					L"grossular", L"grossular (pure)", L"haematite", L"hambergite", L"heliodor", L"hematite", L"hemimorphite", L"hessonite", L"hiddenite",
					L"howlite", L"idocrase", L"imperial topaz", L"iolite", L"jadeite", L"jasper", L"jet", L"kornerupine", L"kunzite", L"kyanite",
					L"lapis lazuli", L"larimar", L"lazulite", L"lepidolite", L"lithium niobate", L"malachite", L"mali garnet", L"marcasite", L"maw-sit-sit",
					L"maxixe", L"moissanite", L"morganite", L"moss agate", L"nephrite", L"obsidian", L"odontolite", L"onyx", L"opal", L"painite",
					L"pearl", L"periclase", L"peridot", L"phenakite", L"pink beryl", L"pink topaz", L"pleonaste", L"porcelain", L"prehnite", L"pseudophite",
					L"pyrites", L"pyrope", L"quartz amethyst", L"quartz aventurine", L"quartz chalcedony", L"quartz citrine", L"quartz", L"rhodochrosite",
					L"rhodonite", L"ruby", L"rutile", L"sapphire", L"sard", L"scapolite", L"scheelite", L"schorl", L"serpentine", L"seraphinite",
					L"silica glass", L"sinhalite", L"smithsonite", L"spessartine", L"sphalerite", L"sphene", L"spinel synthetic", L"spinel", L"spodumene",
					L"strontium titanate", L"sugilite", L"synthetic corundum", L"taaffeite", L"tektite", L"topaz", L"tortoiseshell", L"tourmaline Schorl",
					L"tourmaline", L"turquoise", L"uvarovite", L"variscite", L"vivianite", L"water opal", L"yttrium aluminate YAG", L"zircon (metamict)",
					L"zircon (normal)", L"zirconia (cubic)", L"zoisite"
			});
			this->comboGems->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboGems->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboGems->Enabled = false;
			this->comboGems->FormattingEnabled = true;
			this->comboGems->Items->AddRange(gcnew cli::array< System::Object^  >(188) {
				L"agate", L"albite", L"alexandrite", L"almandine",
					L"amazonite", L"amber", L"amethyst", L"andalusite", L"apatite", L"aquamarine", L"aragonite", L"aventurine quartz", L"aventurine",
					L"axinite (ferro-axinite)", L"azurite", L"bakelite", L"benitoite", L"beryl aquamarine", L"beryl colourless", L"beryl heliodor",
					L"beryl morganite", L"beryl", L"beryl maxixe", L"blende", L"bloodstone", L"blue topaz", L"bonamite", L"bowenite", L"brazilianite",
					L"calcite", L"californite", L"carborundum", L"carnelian", L"cassiterite", L"cat\'s eye chrysoberyl", L"celluloid", L"chalcedony agate",
					L"chalcedony aventurine", L"chalcedony carnelian", L"chalcedony heliotrope", L"chalcedony moss agate", L"chalcedony onyx", L"chalcedony",
					L"chrome diopside", L"chrysoberyl alexandrite", L"chrysoberyl cat\'s eye", L"chrysoberyl cymophane", L"chrysoberyl", L"chrysocolla",
					L"chrysoprase", L"citrine", L"colourless beryl", L"conch pearl", L"copal resin", L"coral", L"cornelian", L"corundum ruby", L"corundum sapphire",
					L"corundum synthetic", L"corundum", L"crocidolite", L"cubic zirconia", L"cymophane", L"cz", L"danburite", L"datolite", L"demantoid",
					L"diamond", L"diopside", L"ekanite", L"emerald (Gilson)", L"emerald", L"enstatite", L"epidote", L"euclase", L"fibrolite", L"fire opal",
					L"fluorite", L"garnet almandine", L"garnet demantoid", L"garnet grossular (pure)", L"garnet hessonite", L"garnet (mali)", L"garnet pyrope",
					L"garnet spessartine", L"garnet uvarovite", L"garnet", L"ggg", L"glass", L"golden beryl", L"goshenite", L"grossular garnet",
					L"grossular", L"grossular (pure)", L"haematite", L"hambergite", L"heliodor", L"hematite", L"hemimorphite", L"hessonite", L"hiddenite",
					L"howlite", L"idocrase", L"imperial topaz", L"iolite", L"jadeite", L"jasper", L"jet", L"kornerupine", L"kunzite", L"kyanite",
					L"lapis lazuli", L"larimar", L"lazulite", L"lepidolite", L"lithium niobate", L"malachite", L"mali garnet", L"marcasite", L"maw-sit-sit",
					L"maxixe", L"moissanite", L"morganite", L"moss agate", L"nephrite", L"obsidian", L"odontolite", L"onyx", L"opal", L"painite",
					L"pearl", L"periclase", L"peridot", L"phenakite", L"pink beryl", L"pink topaz", L"pleonaste", L"porcelain", L"prehnite", L"pseudophite",
					L"pyrites", L"pyrope", L"quartz amethyst", L"quartz aventurine", L"quartz chalcedony", L"quartz citrine", L"quartz", L"rhodochrosite",
					L"rhodonite", L"ruby", L"rutile", L"sapphire", L"sard", L"scapolite", L"scheelite", L"schorl", L"serpentine", L"seraphinite",
					L"silica glass", L"sinhalite", L"smithsonite", L"spessartine", L"sphalerite", L"sphene", L"spinel synthetic", L"spinel", L"spodumene",
					L"strontium titanate", L"sugilite", L"synthetic corundum", L"taaffeite", L"tanzanite", L"tektite", L"topaz", L"tortoiseshell",
					L"tourmaline schorl", L"tourmaline", L"turquoise", L"uvarovite", L"variscite", L"vesuvianite", L"vivianite", L"water opal", L"yttrium aluminate YAG",
					L"zircon (metamict)", L"zircon (normal)", L"zirconia (cubic)", L"zoisite"
			});
			this->comboGems->Location = System::Drawing::Point(79, 19);
			this->comboGems->Name = L"comboGems";
			this->comboGems->Size = System::Drawing::Size(121, 21);
			this->comboGems->TabIndex = 8;
			this->comboGems->Text = L"choose from below";
			this->comboGems->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboGems_SelectedIndexChanged);
			// 
			// btnEq
			// 
			this->btnEq->Location = System::Drawing::Point(112, 44);
			this->btnEq->Name = L"btnEq";
			this->btnEq->Size = System::Drawing::Size(100, 20);
			this->btnEq->TabIndex = 1;
			this->btnEq->Text = L"=";
			this->btnEq->UseVisualStyleBackColor = true;
			this->btnEq->Click += gcnew System::EventHandler(this, &Form1::btnEq_Click);
			// 
			// txtDia1
			// 
			this->txtDia1->Location = System::Drawing::Point(6, 45);
			this->txtDia1->Name = L"txtDia1";
			this->txtDia1->Size = System::Drawing::Size(100, 20);
			this->txtDia1->TabIndex = 0;
			this->txtDia1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtDia1_KeyPress);
			// 
			// txtDia2
			// 
			this->txtDia2->Location = System::Drawing::Point(226, 45);
			this->txtDia2->Name = L"txtDia2";
			this->txtDia2->Size = System::Drawing::Size(100, 20);
			this->txtDia2->TabIndex = 2;
			this->txtDia2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtDia2_KeyPress);
			// 
			// txtDepth
			// 
			this->txtDepth->Location = System::Drawing::Point(336, 45);
			this->txtDepth->Name = L"txtDepth";
			this->txtDepth->Size = System::Drawing::Size(100, 20);
			this->txtDepth->TabIndex = 3;
			this->txtDepth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtDepth_KeyPress);
			// 
			// buttonCalc
			// 
			this->buttonCalc->Location = System::Drawing::Point(337, 71);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(100, 23);
			this->buttonCalc->TabIndex = 5;
			this->buttonCalc->Text = L"Calculate";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &Form1::buttonCalc_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(336, 266);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(100, 23);
			this->buttonClear->TabIndex = 6;
			this->buttonClear->Text = L"Clear";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// txtResult
			// 
			this->txtResult->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->txtResult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtResult->Location = System::Drawing::Point(288, 100);
			this->txtResult->MaxLength = 20;
			this->txtResult->MinimumSize = System::Drawing::Size(100, 40);
			this->txtResult->Name = L"txtResult";
			this->txtResult->ReadOnly = true;
			this->txtResult->Size = System::Drawing::Size(149, 31);
			this->txtResult->TabIndex = 7;
			this->txtResult->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtResult->TextChanged += gcnew System::EventHandler(this, &Form1::txtResult_TextChanged);
			// 
			// lbllSelectedSG
			// 
			this->lbllSelectedSG->AutoSize = true;
			this->lbllSelectedSG->Location = System::Drawing::Point(3, 21);
			this->lbllSelectedSG->Name = L"lbllSelectedSG";
			this->lbllSelectedSG->Size = System::Drawing::Size(62, 13);
			this->lbllSelectedSG->TabIndex = 9;
			this->lbllSelectedSG->Text = L"Select Gem";
			// 
			// txtSg
			// 
			this->txtSg->Enabled = false;
			this->txtSg->Location = System::Drawing::Point(79, 46);
			this->txtSg->Name = L"txtSg";
			this->txtSg->Size = System::Drawing::Size(100, 20);
			this->txtSg->TabIndex = 10;
			this->txtSg->Text = L"3.52";
			this->txtSg->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtSg_KeyPress);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->picDepth);
			this->groupBox1->Controls->Add(this->txtPavilionBulge);
			this->groupBox1->Controls->Add(this->txtGirdleThickness);
			this->groupBox1->Controls->Add(this->txtOther);
			this->groupBox1->Controls->Add(this->txtGlobAdjust);
			this->groupBox1->Controls->Add(this->tbPavilionBulge);
			this->groupBox1->Controls->Add(this->tbGirdleThickness);
			this->groupBox1->Controls->Add(this->cbRecut);
			this->groupBox1->Controls->Add(this->tbOtherNudge);
			this->groupBox1->Controls->Add(this->cbInterpolate);
			this->groupBox1->Controls->Add(this->tbGlobalAdj);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->lblPavilionBulge);
			this->groupBox1->Controls->Add(this->lblGirdleThickness);
			this->groupBox1->Controls->Add(this->lblOther);
			this->groupBox1->Controls->Add(this->lblGlobAdj);
			this->groupBox1->Controls->Add(this->lblResult);
			this->groupBox1->Controls->Add(this->lblDepth);
			this->groupBox1->Controls->Add(this->lblDia2);
			this->groupBox1->Controls->Add(this->lblDia1);
			this->groupBox1->Controls->Add(this->txtDia1);
			this->groupBox1->Controls->Add(this->btnEq);
			this->groupBox1->Controls->Add(this->txtDia2);
			this->groupBox1->Controls->Add(this->txtDepth);
			this->groupBox1->Controls->Add(this->txtResult);
			this->groupBox1->Controls->Add(this->buttonCalc);
			this->groupBox1->Controls->Add(this->buttonClear);
			this->groupBox1->Location = System::Drawing::Point(36, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(459, 306);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Calculate";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// picDepth
			// 
			this->picDepth->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->picDepth->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picDepth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picDepth->Location = System::Drawing::Point(157, 86);
			this->picDepth->Name = L"picDepth";
			this->picDepth->Padding = System::Windows::Forms::Padding(0, 3, 0, 0);
			this->picDepth->Size = System::Drawing::Size(55, 62);
			this->picDepth->TabIndex = 24;
			this->picDepth->TabStop = false;
			// 
			// txtPavilionBulge
			// 
			this->txtPavilionBulge->Location = System::Drawing::Point(354, 231);
			this->txtPavilionBulge->Name = L"txtPavilionBulge";
			this->txtPavilionBulge->Size = System::Drawing::Size(85, 20);
			this->txtPavilionBulge->TabIndex = 33;
			this->txtPavilionBulge->Text = L"0%";
			this->txtPavilionBulge->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGirdleThickness
			// 
			this->txtGirdleThickness->Location = System::Drawing::Point(241, 231);
			this->txtGirdleThickness->Name = L"txtGirdleThickness";
			this->txtGirdleThickness->Size = System::Drawing::Size(85, 20);
			this->txtGirdleThickness->TabIndex = 32;
			this->txtGirdleThickness->Text = L"0%";
			this->txtGirdleThickness->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtOther
			// 
			this->txtOther->Location = System::Drawing::Point(130, 231);
			this->txtOther->Name = L"txtOther";
			this->txtOther->Size = System::Drawing::Size(85, 20);
			this->txtOther->TabIndex = 31;
			this->txtOther->Text = L"0%";
			this->txtOther->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGlobAdjust
			// 
			this->txtGlobAdjust->Location = System::Drawing::Point(18, 231);
			this->txtGlobAdjust->Name = L"txtGlobAdjust";
			this->txtGlobAdjust->Size = System::Drawing::Size(85, 20);
			this->txtGlobAdjust->TabIndex = 30;
			this->txtGlobAdjust->Text = L"0%";
			this->txtGlobAdjust->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbPavilionBulge
			// 
			this->tbPavilionBulge->Location = System::Drawing::Point(349, 193);
			this->tbPavilionBulge->Maximum = 30;
			this->tbPavilionBulge->MaximumSize = System::Drawing::Size(104, 30);
			this->tbPavilionBulge->MinimumSize = System::Drawing::Size(104, 30);
			this->tbPavilionBulge->Name = L"tbPavilionBulge";
			this->tbPavilionBulge->Size = System::Drawing::Size(104, 45);
			this->tbPavilionBulge->TabIndex = 29;
			this->tbPavilionBulge->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbPavilionBulge->Scroll += gcnew System::EventHandler(this, &Form1::tbPavilionBulge_Scroll);
			// 
			// tbGirdleThickness
			// 
			this->tbGirdleThickness->Location = System::Drawing::Point(236, 193);
			this->tbGirdleThickness->Maximum = 15;
			this->tbGirdleThickness->MaximumSize = System::Drawing::Size(104, 30);
			this->tbGirdleThickness->MinimumSize = System::Drawing::Size(104, 30);
			this->tbGirdleThickness->Name = L"tbGirdleThickness";
			this->tbGirdleThickness->Size = System::Drawing::Size(104, 45);
			this->tbGirdleThickness->TabIndex = 28;
			this->tbGirdleThickness->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbGirdleThickness->Scroll += gcnew System::EventHandler(this, &Form1::tbGirdleThickness_Scroll);
			// 
			// cbRecut
			// 
			this->cbRecut->AutoSize = true;
			this->cbRecut->Location = System::Drawing::Point(139, 270);
			this->cbRecut->Name = L"cbRecut";
			this->cbRecut->Size = System::Drawing::Size(61, 17);
			this->cbRecut->TabIndex = 12;
			this->cbRecut->Text = L"Recut\?";
			this->cbRecut->UseVisualStyleBackColor = true;
			// 
			// tbOtherNudge
			// 
			this->tbOtherNudge->Location = System::Drawing::Point(123, 193);
			this->tbOtherNudge->MaximumSize = System::Drawing::Size(104, 30);
			this->tbOtherNudge->Minimum = -10;
			this->tbOtherNudge->MinimumSize = System::Drawing::Size(104, 30);
			this->tbOtherNudge->Name = L"tbOtherNudge";
			this->tbOtherNudge->Size = System::Drawing::Size(104, 45);
			this->tbOtherNudge->TabIndex = 27;
			this->tbOtherNudge->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbOtherNudge->Scroll += gcnew System::EventHandler(this, &Form1::tbOtherNudge_Scroll);
			// 
			// cbInterpolate
			// 
			this->cbInterpolate->AutoSize = true;
			this->cbInterpolate->Location = System::Drawing::Point(21, 270);
			this->cbInterpolate->Name = L"cbInterpolate";
			this->cbInterpolate->Size = System::Drawing::Size(82, 17);
			this->cbInterpolate->TabIndex = 11;
			this->cbInterpolate->Text = L"Interpolate\?";
			this->cbInterpolate->UseVisualStyleBackColor = true;
			// 
			// tbGlobalAdj
			// 
			this->tbGlobalAdj->Location = System::Drawing::Point(10, 193);
			this->tbGlobalAdj->Maximum = 25;
			this->tbGlobalAdj->MaximumSize = System::Drawing::Size(104, 30);
			this->tbGlobalAdj->Minimum = -25;
			this->tbGlobalAdj->MinimumSize = System::Drawing::Size(104, 30);
			this->tbGlobalAdj->Name = L"tbGlobalAdj";
			this->tbGlobalAdj->Size = System::Drawing::Size(104, 45);
			this->tbGlobalAdj->TabIndex = 26;
			this->tbGlobalAdj->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbGlobalAdj->Scroll += gcnew System::EventHandler(this, &Form1::tbGlobalAdj_Scroll);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->lblLwRatio);
			this->groupBox3->Controls->Add(this->lblDepthPerc);
			this->groupBox3->Location = System::Drawing::Point(6, 75);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(145, 85);
			this->groupBox3->TabIndex = 25;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Dimension:";
			// 
			// lblLwRatio
			// 
			this->lblLwRatio->AutoSize = true;
			this->lblLwRatio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLwRatio->Location = System::Drawing::Point(18, 25);
			this->lblLwRatio->Name = L"lblLwRatio";
			this->lblLwRatio->Size = System::Drawing::Size(97, 13);
			this->lblLwRatio->TabIndex = 15;
			this->lblLwRatio->Text = L"LW Ratio =  0:0";
			// 
			// lblDepthPerc
			// 
			this->lblDepthPerc->AutoSize = true;
			this->lblDepthPerc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDepthPerc->Location = System::Drawing::Point(18, 52);
			this->lblDepthPerc->Name = L"lblDepthPerc";
			this->lblDepthPerc->Size = System::Drawing::Size(79, 13);
			this->lblDepthPerc->TabIndex = 16;
			this->lblDepthPerc->Text = L"Depth = 50%";
			// 
			// lblPavilionBulge
			// 
			this->lblPavilionBulge->AutoSize = true;
			this->lblPavilionBulge->Location = System::Drawing::Point(365, 176);
			this->lblPavilionBulge->Name = L"lblPavilionBulge";
			this->lblPavilionBulge->Size = System::Drawing::Size(74, 13);
			this->lblPavilionBulge->TabIndex = 24;
			this->lblPavilionBulge->Text = L"Pavilion Bulge";
			// 
			// lblGirdleThickness
			// 
			this->lblGirdleThickness->AutoSize = true;
			this->lblGirdleThickness->Location = System::Drawing::Point(247, 176);
			this->lblGirdleThickness->Name = L"lblGirdleThickness";
			this->lblGirdleThickness->Size = System::Drawing::Size(86, 13);
			this->lblGirdleThickness->TabIndex = 23;
			this->lblGirdleThickness->Text = L"Girdle Thickness";
			// 
			// lblOther
			// 
			this->lblOther->AutoSize = true;
			this->lblOther->Location = System::Drawing::Point(132, 176);
			this->lblOther->Name = L"lblOther";
			this->lblOther->Size = System::Drawing::Size(83, 13);
			this->lblOther->TabIndex = 22;
			this->lblOther->Text = L"Other % (nudge)";
			// 
			// lblGlobAdj
			// 
			this->lblGlobAdj->AutoSize = true;
			this->lblGlobAdj->Location = System::Drawing::Point(25, 176);
			this->lblGlobAdj->Name = L"lblGlobAdj";
			this->lblGlobAdj->Size = System::Drawing::Size(75, 13);
			this->lblGlobAdj->TabIndex = 21;
			this->lblGlobAdj->Text = L"Global Adj. (%)";
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Location = System::Drawing::Point(230, 111);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(50, 13);
			this->lblResult->TabIndex = 20;
			this->lblResult->Text = L"RESULT";
			// 
			// lblDepth
			// 
			this->lblDepth->AutoSize = true;
			this->lblDepth->Location = System::Drawing::Point(365, 29);
			this->lblDepth->Name = L"lblDepth";
			this->lblDepth->Size = System::Drawing::Size(36, 13);
			this->lblDepth->TabIndex = 19;
			this->lblDepth->Text = L"Depth";
			// 
			// lblDia2
			// 
			this->lblDia2->AutoSize = true;
			this->lblDia2->Location = System::Drawing::Point(234, 29);
			this->lblDia2->Name = L"lblDia2";
			this->lblDia2->Size = System::Drawing::Size(83, 13);
			this->lblDia2->TabIndex = 18;
			this->lblDia2->Text = L"Diameter/Depth";
			this->lblDia2->Click += gcnew System::EventHandler(this, &Form1::lblDia2_Click);
			// 
			// lblDia1
			// 
			this->lblDia1->AutoSize = true;
			this->lblDia1->Location = System::Drawing::Point(9, 29);
			this->lblDia1->Name = L"lblDia1";
			this->lblDia1->Size = System::Drawing::Size(93, 13);
			this->lblDia1->TabIndex = 17;
			this->lblDia1->Text = L"Diameter / Length";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox2->Controls->Add(this->picGirdle);
			this->groupBox2->Controls->Add(this->picBulge);
			this->groupBox2->Controls->Add(this->picGem);
			this->groupBox2->Controls->Add(this->picCut);
			this->groupBox2->Controls->Add(this->lblSgValue);
			this->groupBox2->Controls->Add(this->lblCutFactor);
			this->groupBox2->Controls->Add(this->txtCutSel);
			this->groupBox2->Controls->Add(this->lblSelectedCut);
			this->groupBox2->Controls->Add(this->comboCut);
			this->groupBox2->Controls->Add(this->radioBtnGem);
			this->groupBox2->Controls->Add(this->radioBtnDia);
			this->groupBox2->Controls->Add(this->comboGems);
			this->groupBox2->Controls->Add(this->txtSg);
			this->groupBox2->Controls->Add(this->lbllSelectedSG);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(36, 339);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(459, 206);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Select Gem / Cut";
			// 
			// picGirdle
			// 
			this->picGirdle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picGirdle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picGirdle->Location = System::Drawing::Point(357, 100);
			this->picGirdle->Name = L"picGirdle";
			this->picGirdle->Size = System::Drawing::Size(82, 67);
			this->picGirdle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picGirdle->TabIndex = 23;
			this->picGirdle->TabStop = false;
			// 
			// picBulge
			// 
			this->picBulge->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picBulge->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picBulge->Location = System::Drawing::Point(357, 21);
			this->picBulge->Name = L"picBulge";
			this->picBulge->Size = System::Drawing::Size(82, 64);
			this->picBulge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBulge->TabIndex = 22;
			this->picBulge->TabStop = false;
			// 
			// picGem
			// 
			this->picGem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picGem->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picGem->Location = System::Drawing::Point(262, 21);
			this->picGem->Name = L"picGem";
			this->picGem->Size = System::Drawing::Size(64, 64);
			this->picGem->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picGem->TabIndex = 21;
			this->picGem->TabStop = false;
			// 
			// picCut
			// 
			this->picCut->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picCut->Location = System::Drawing::Point(262, 103);
			this->picCut->Name = L"picCut";
			this->picCut->Size = System::Drawing::Size(64, 64);
			this->picCut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picCut->TabIndex = 20;
			this->picCut->TabStop = false;
			// 
			// lblSgValue
			// 
			this->lblSgValue->AutoSize = true;
			this->lblSgValue->Location = System::Drawing::Point(37, 51);
			this->lblSgValue->Name = L"lblSgValue";
			this->lblSgValue->Size = System::Drawing::Size(28, 13);
			this->lblSgValue->TabIndex = 19;
			this->lblSgValue->Text = L"S.G.";
			// 
			// lblCutFactor
			// 
			this->lblCutFactor->AutoSize = true;
			this->lblCutFactor->Location = System::Drawing::Point(9, 111);
			this->lblCutFactor->Name = L"lblCutFactor";
			this->lblCutFactor->Size = System::Drawing::Size(56, 13);
			this->lblCutFactor->TabIndex = 18;
			this->lblCutFactor->Text = L"Cut Factor";
			// 
			// txtCutSel
			// 
			this->txtCutSel->Location = System::Drawing::Point(79, 108);
			this->txtCutSel->Name = L"txtCutSel";
			this->txtCutSel->Size = System::Drawing::Size(100, 20);
			this->txtCutSel->TabIndex = 17;
			this->txtCutSel->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtCutSel_KeyPress);
			// 
			// lblSelectedCut
			// 
			this->lblSelectedCut->AutoSize = true;
			this->lblSelectedCut->Location = System::Drawing::Point(42, 85);
			this->lblSelectedCut->Name = L"lblSelectedCut";
			this->lblSelectedCut->Size = System::Drawing::Size(23, 13);
			this->lblSelectedCut->TabIndex = 16;
			this->lblSelectedCut->Text = L"Cut";
			// 
			// comboCut
			// 
			this->comboCut->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(186) {
				L"agate", L"albite", L"alexandrite",
					L"almandine", L"amazonite", L"amber", L"amethyst", L"andalusite", L"apatite", L"aquamarine", L"aragonite", L"aventurine quartz",
					L"aventurine", L"axinite (Ferro-axinite)", L"azurite", L"bakelite", L"benitoite", L"beryl aquamarine", L"beryl colourless", L"beryl heliodor",
					L"beryl morganite", L"beryl", L"beryl maxixe", L"blende", L"bloodstone", L"blue topaz", L"bonamite", L"bowenite", L"brazilianite",
					L"calcite", L"californite", L"carborundum", L"carnelian", L"cassiterite", L"cat\'s eye chrysoberyl", L"celluloid", L"chalcedony agate",
					L"chalcedony aventurine", L"chalcedony carnelian", L"chalcedony heliotrope", L"chalcedony moss agate", L"chalcedony onyx", L"chalcedony",
					L"chrome diopside", L"chrysoberyl alexandrite", L"chrysoberyl cat\'s eye", L"chrysoberyl cymophane", L"chrysoberyl", L"chrysocolla",
					L"chrysoprase", L"citrine", L"colourless beryl", L"conch pearl", L"copal resin", L"coral", L"cornelian", L"corundum ruby", L"corundum sapphire",
					L"corundum synthetic", L"corundum", L"crocidolite", L"cubic zirconia", L"cymophane", L"cz", L"danburite", L"datolite", L"demantoid",
					L"diamond", L"diopside", L"ekanite", L"emerald (Gilson)", L"emerald", L"enstatite", L"epidote", L"euclase", L"fibrolite", L"fire opal",
					L"fluorite", L"garnet almandine", L"garnet demantoid", L"garnet grossular (pure)", L"garnet hessonite", L"garnet (mali)", L"garnet pyrope",
					L"garnet spessartine", L"garnet uvarovite", L"garnet", L"ggg", L"glass", L"golden beryl", L"goshenite", L"grossular garnet",
					L"grossular", L"grossular (pure)", L"haematite", L"hambergite", L"heliodor", L"hematite", L"hemimorphite", L"hessonite", L"hiddenite",
					L"howlite", L"idocrase", L"imperial topaz", L"iolite", L"jadeite", L"jasper", L"jet", L"kornerupine", L"kunzite", L"kyanite",
					L"lapis lazuli", L"larimar", L"lazulite", L"lepidolite", L"lithium niobate", L"malachite", L"mali garnet", L"marcasite", L"maw-sit-sit",
					L"maxixe", L"moissanite", L"morganite", L"moss agate", L"nephrite", L"obsidian", L"odontolite", L"onyx", L"opal", L"painite",
					L"Pearl", L"periclase", L"peridot", L"phenakite", L"pink beryl", L"pink topaz", L"pleonaste", L"porcelain", L"prehnite", L"pseudophite",
					L"pyrites", L"pyrope", L"quartz amethyst", L"quartz aventurine", L"quartz chalcedony", L"quartz citrine", L"quartz", L"rhodochrosite",
					L"rhodonite", L"ruby", L"rutile", L"sapphire", L"sard", L"scapolite", L"scheelite", L"schorl", L"serpentine", L"seraphinite",
					L"silica glass", L"sinhalite", L"smithsonite", L"spessartine", L"sphalerite", L"sphene", L"spinel synthetic", L"spinel", L"spodumene",
					L"strontium titanate", L"sugilite", L"synthetic corundum", L"taaffeite", L"tektite", L"topaz", L"tortoiseshell", L"tourmaline Schorl",
					L"tourmaline", L"turquoise", L"uvarovite", L"variscite", L"vivianite", L"water opal", L"yttrium aluminate YAG", L"zircon (metamict)",
					L"zircon (normal)", L"zirconia (cubic)", L"zoisite"
			});
			this->comboCut->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboCut->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboCut->FormattingEnabled = true;
			this->comboCut->Items->AddRange(gcnew cli::array< System::Object^  >(23) {
				L"asscher", L"barion", L"cushion brilliant", L"eight cut",
					L"emerald cut diamond", L"heart brilliant", L"flanders cut (dia.)", L"old european cut", L"old mine cut", L"marquise brilliant",
					L"pear brilliant", L"princess brilliant", L"oval brilliant", L"round brilliant", L"rose cut", L"small baguette", L"square cut (dia.)",
					L"tapered baguette", L"semi circle cut (dia.)", L"triangular cut (dia.)", L"radiant cut (dia.)", L"trilliant cut (dia.)", L"trillion (rounded sides)"
			});
			this->comboCut->Location = System::Drawing::Point(79, 81);
			this->comboCut->Name = L"comboCut";
			this->comboCut->Size = System::Drawing::Size(121, 21);
			this->comboCut->TabIndex = 15;
			this->comboCut->Text = L"choose from below";
			this->comboCut->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboCut_SelectedIndexChanged);
			// 
			// radioBtnGem
			// 
			this->radioBtnGem->AutoSize = true;
			this->radioBtnGem->Location = System::Drawing::Point(79, 162);
			this->radioBtnGem->Name = L"radioBtnGem";
			this->radioBtnGem->Size = System::Drawing::Size(73, 17);
			this->radioBtnGem->TabIndex = 14;
			this->radioBtnGem->Text = L"Gemstone";
			this->radioBtnGem->UseVisualStyleBackColor = true;
			this->radioBtnGem->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioBtnGem_CheckedChanged);
			// 
			// radioBtnDia
			// 
			this->radioBtnDia->AutoSize = true;
			this->radioBtnDia->Checked = true;
			this->radioBtnDia->Location = System::Drawing::Point(79, 136);
			this->radioBtnDia->Name = L"radioBtnDia";
			this->radioBtnDia->Size = System::Drawing::Size(67, 17);
			this->radioBtnDia->TabIndex = 13;
			this->radioBtnDia->TabStop = true;
			this->radioBtnDia->Text = L"Diamond";
			this->radioBtnDia->UseVisualStyleBackColor = true;
			this->radioBtnDia->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioBtnDia_CheckedChanged);
			// 
			// statusbar
			// 
			this->statusbar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStrip });
			this->statusbar->Location = System::Drawing::Point(0, 560);
			this->statusbar->Name = L"statusbar";
			this->statusbar->Size = System::Drawing::Size(529, 22);
			this->statusbar->TabIndex = 14;
			this->statusbar->Text = L"statusStrip1";
			// 
			// toolStrip
			// 
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(48, 17);
			this->toolStrip->Text = L"Ready...";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->viewToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(529, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->quitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(97, 22);
			this->quitToolStripMenuItem->Text = L"&Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::quitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->logToolStripMenuItem });
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"View";
			// 
			// logToolStripMenuItem
			// 
			this->logToolStripMenuItem->Name = L"logToolStripMenuItem";
			this->logToolStripMenuItem->Size = System::Drawing::Size(91, 22);
			this->logToolStripMenuItem->Text = L"log";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem1,
					this->aboutToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 582);
			this->Controls->Add(this->statusbar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Gemwest";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDepth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPavilionBulge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGirdleThickness))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOtherNudge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGlobalAdj))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGirdle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBulge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGem))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCut))->EndInit();
			this->statusbar->ResumeLayout(false);
			this->statusbar->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void txtDia1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		{
			// Only allow 1 decimal point
			if (e->KeyChar == '.')
			{
				if (this->txtDia1->Text->Contains(".") && !this->txtDia1->SelectedText->Contains("."))
					e->Handled = true;
			}
			// Accept only digits "." and the Backspace character
			else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;

		}
		this->toolStrip->Text = this->txtDia1->Text;
	}
private: System::Void txtDia2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	{
		// Only allow 1 decimal point
		if (e->KeyChar == '.')
		{
			if (this->txtDia2->Text->Contains(".") && !this->txtDia2->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}

}
private: System::Void txtDepth_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	{
		// Only allow 1 decimal point
		if (e->KeyChar == '.')
		{
			if (this->txtDepth->Text->Contains(".") && !this->txtDepth->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}
}
private: System::Void btnEq_Click(System::Object^ sender, System::EventArgs^ e) {

	this->txtDia2->Text = this->txtDia1->Text;
}
private: System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
	double output = System::Convert::ToDouble(txtDia1->Text) * System::Convert::ToDouble(txtDia2->Text);// *System::Convert::ToDouble(sg[comboGems->Text]);
	System::String^ calculatedResult = System::Convert::ToString(output)+"ct";
	this->txtResult->Text = calculatedResult;
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	//EmbeddedImage^ ico = gcnew EmbeddedImage;
	//ico->setName("gw");
	//this->Icon = cli::safe_cast<System::Drawing::Icon^>(ico->getName());
	
	//this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject("IDI_ICON1")));
	EmbeddedImage^ defaultCut = gcnew EmbeddedImage;
	defaultCut->setName("round brilliant");
	this->picCut->Image = defaultCut->getName();

	EmbeddedImage^ defaultBulge = gcnew EmbeddedImage;
	defaultBulge->setName("bulge_non");
	this->picBulge->Image = defaultBulge->getName();

	EmbeddedImage^ defaultGem = gcnew EmbeddedImage;
	defaultGem->setName("diamond");
	this->picGem->Image = defaultGem->getName();

	EmbeddedImage^ defaultGirdle = gcnew EmbeddedImage;
	defaultGirdle->setName("thingirdle");
	this->picGirdle->Image = defaultGirdle->getName();

	EmbeddedImage^ checkDepth = gcnew EmbeddedImage;
	checkDepth->setName("checkDepth");
	this->picDepth->Image = checkDepth->getName();

	//EmbeddedImage^ ico = gcnew EmbeddedImage;
	//ico->setName(L"$this.Icon");
	//Form1 = ico->getName(); // (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	//this->Form>Image = defaultCut->getName();


}

private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {

	this->txtResult->Text = ""; // clear all textBox
	this->txtDia1->Text = ""; // clear all textBox
	this->txtDia2->Text = ""; // clear all textBox
	this->txtDepth->Text = ""; // clear all textBox
	this->toolStrip->Text = L"Ready..."; // clear all textBox
	this->tbGlobalAdj->Value = 0;
	this->tbGirdleThickness->Value = 0;
	this->tbOtherNudge->Value = 0;
	this->tbPavilionBulge->Value = 0;
	this->tbGlobalAdj->Value = 0;
	this->tbGirdleThickness->Value = 0;

	this->txtGlobAdjust->Text = L"0%";
	this->txtOther->Text = L"0%";
	this->txtPavilionBulge->Text = L"0%";
	this->txtGirdleThickness->Text = L"0%";

	
}
private: System::Void txtResult_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void comboGems_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	Dictionary<String^, String^>^ sg;
	sg = gcnew Dictionary<String^, String^>();
	sg->Add("agate", "2.6");
	sg->Add("albite", "2.58");
	sg->Add("alexandrite", "3.71");
	sg->Add("almandine", "4");
	sg->Add("amazonite", "2.56");
	sg->Add("amber", "1.08");
	sg->Add("amethyst", "2.65");
	sg->Add("andalusite", "3.15");
	sg->Add("apatite", "3.2");
	sg->Add("aquamarine", "2.69");
	sg->Add("aragonite", "2.94");
	sg->Add("aventurine quartz", "2.66");
	sg->Add("aventurine", "2.6");
	sg->Add("axinite (ferro-axinite)", "3.31");
	sg->Add("azurite", "3.8");
	sg->Add("bakelite", "1.26");
	sg->Add("benitoite", "3.67");
	sg->Add("beryl aquamarine", "2.69");
	sg->Add("beryl colourless", "2.7");
	sg->Add("beryl heliodor", "2.7");
	sg->Add("beryl morganite", "2.7");
	sg->Add("beryl", "2.7");
	sg->Add("beryl maxixe", "2.7");
	sg->Add("blende", "4.09");
	sg->Add("bloodstone", "2.6");
	sg->Add("blue topaz", "3.53");
	sg->Add("bonamite", "4.35");
	sg->Add("bowenite", "2.59");
	sg->Add("brazilianite", "2.99");
	sg->Add("calcite", "2.71");
	sg->Add("californite", "3.3");
	sg->Add("carborundum", "3.17");
	sg->Add("carnelian", "2.64");
	sg->Add("cassiterite", "6.9");
	sg->Add("cat's eye chrysoberyl", "3.71");
	sg->Add("celluloid", "1.38");
	sg->Add("chalcedony agate", "2.6");
	sg->Add("chalcedony aventurine", "2.6");
	sg->Add("chalcedony carnelian", "2.64");
	sg->Add("chalcedony heliotrope", "2.6");
	sg->Add("chalcedony moss agate", "2.6");
	sg->Add("chalcedony onyx", "2.6");
	sg->Add("chalcedony", "2.61");
	sg->Add("chrome diopside", "3.3");
	sg->Add("chrysoberyl alexandrite", "3.71");
	sg->Add("chrysoberyl cat's eye", "3.71");
	sg->Add("chrysoberyl cymophane", "3.71");
	sg->Add("chrysoberyl", "3.71");
	sg->Add("chrysocolla", "2.1");
	sg->Add("chrysoprase", "2.6");
	sg->Add("citrine", "2.65");
	sg->Add("colourless beryl", "2.7");
	sg->Add("conch pearl", "2.84");
	sg->Add("copal resin", "1.06");
	sg->Add("coral", "2.68");
	sg->Add("cornelian", "2.64");
	sg->Add("corundum ruby", "3.99");
	sg->Add("corundum sapphire", "3.99");
	sg->Add("corundum synthetic", "4");
	sg->Add("corundum", "4");
	sg->Add("crocidolite", "2.66");
	sg->Add("cubic zirconia", "5.80");
	sg->Add("cymophane", "3.71");
	sg->Add("cz", "5.80");
	sg->Add("danburite", "3");
	sg->Add("datolite", "2.95");
	sg->Add("demantoid", "3.85");
	sg->Add("diamond", "3.52");
	sg->Add("diopside", "3.29");
	sg->Add("ekanite", "3.28");
	sg->Add("emerald (Gilson)", "2.70");
	sg->Add("emerald", "2.71");
	sg->Add("enstatite", "3.27");
	sg->Add("epidote", "3.4");
	sg->Add("euclase", "3.1");
	sg->Add("fibrolite", "3.25");
	sg->Add("fire opal", "2");
	sg->Add("fluorite", "3.18");
	sg->Add("garnet almandine", "4");
	sg->Add("garnet demantoid", "3.85");
	sg->Add("garnet grossular (pure)", "3.59");
	sg->Add("garnet hessonite", "3.63");
	sg->Add("garnet (mali)", "3.67");
	sg->Add("garnet pyrope", "3.8");
	sg->Add("garnet spessartine", "4.16");
	sg->Add("garnet uvarovite", "3.77");
	sg->Add("garnet", "4.00");
	sg->Add("ggg", "7.05");
	sg->Add("glass", "2.65");
	sg->Add("golden beryl", "2.7");
	sg->Add("goshenite", "2.7");
	sg->Add("grossular garnet", "3.59");
	sg->Add("grossular", "3.59");
	sg->Add("grossular (pure)", "3.59");
	sg->Add("haematite", "5.1");
	sg->Add("hambergite", "2.35");
	sg->Add("heliodor", "2.7");
	sg->Add("hematite", "5.1");
	sg->Add("hemimorphite", "3.52");
	sg->Add("hessonite", "3.63");
	sg->Add("hiddenite", "3.18");
	sg->Add("howlite", "2.56");
	sg->Add("idocrase", "3.4");
	sg->Add("imperial topaz", "3.53");
	sg->Add("iolite", "2.63");
	sg->Add("jadeite", "3.33");
	sg->Add("jasper", "2.55");
	sg->Add("jet", "1.33");
	sg->Add("kornerupine", "3.32");
	sg->Add("kunzite", "3.18");
	sg->Add("kyanite", "3.68");
	sg->Add("lapis lazuli", "2.8");
	sg->Add("larimar", "4.75");
	sg->Add("lazulite", "3.1");
	sg->Add("lepidolite", "2.8");
	sg->Add("lithium niobate", "4.64");
	sg->Add("malachite", "3.8");
	sg->Add("mali garnet", "3.67");
	sg->Add("marcasite", "4.9");
	sg->Add("maw-sit-sit", "3");
	sg->Add("maxixe", "2.71");
	sg->Add("moissanite", "3.15");
	sg->Add("morganite", "2.7");
	sg->Add("moss agate", "2.6");
	sg->Add("nephrite", "3.00");
	sg->Add("obsidian", "2.5");
	sg->Add("odontolite", "3.1");
	sg->Add("onyx", "2.6");
	sg->Add("opal", "2.15");
	sg->Add("painite", "4.01");
	sg->Add("pearl", "2.71");
	sg->Add("periclase", "3.59");
	sg->Add("peridot", "3.34");
	sg->Add("phenakite", "2.96");
	sg->Add("pink beryl", "2.7");
	sg->Add("pink topaz", "3.53");
	sg->Add("pleonaste", "3.8");
	sg->Add("porcelain", "2.3");
	sg->Add("prehnite", "2.87");
	sg->Add("pseudophite", "2.7");
	sg->Add("pyrites", "4.9");
	sg->Add("pyrope", "3.8");
	sg->Add("quartz amethyst", "2.65");
	sg->Add("quartz aventurine", "2.66");
	sg->Add("quartz chalcedony", "2.61");
	sg->Add("quartz citrine", "2.65");
	sg->Add("quartz", "2.65");
	sg->Add("rhodochrosite", "3.6");
	sg->Add("rhodonite", "3.6");
	sg->Add("ruby", "3.99");
	sg->Add("rutile", "4.25");
	sg->Add("sapphire", "3.99");
	sg->Add("sard", "2.61");
	sg->Add("scapolite", "2.7");
	sg->Add("scheelite", "6.1");
	sg->Add("schorl", "3.06");
	sg->Add("serpentine", "2.6");
	sg->Add("seraphinite", "2.8");
	sg->Add("silica glass", "2.21");
	sg->Add("sinhalite", "3.48");
	sg->Add("smithsonite", "4.35");
	sg->Add("spessartine", "4.16");
	sg->Add("sphalerite", "4.09");
	sg->Add("sphene", "3.53");
	sg->Add("spinel synthetic", "3.65");
	sg->Add("spinel", "3.65");
	sg->Add("spodumene", "3.18");
	sg->Add("strontium titanate", "5.13");
	sg->Add("sugilite", "2.74");
	sg->Add("synthetic corundum", "4");
	sg->Add("taaffeite", "3.61");
	sg->Add("tanzanite", "3.35");
	sg->Add("tektite", "2.4");
	sg->Add("topaz", "3.53");
	sg->Add("tortoiseshell", "1.29");
	sg->Add("tourmaline schorl", "3.06");
	sg->Add("tourmaline", "3.06");
	sg->Add("turquoise", "2.8");
	sg->Add("uvarovite", "3.77");
	sg->Add("variscite", "2.55");
	sg->Add("vesuvianite", "3.40");
	sg->Add("vivianite", "2.6");
	sg->Add("water opal", "2");
	sg->Add("yttrium aluminate YAG", "4.57");
	sg->Add("zircon (metamict)", "4");
	sg->Add("zircon (normal)", "4.69");
	sg->Add("zirconia (cubic)", "5.7");
	sg->Add("zoisite", "3.35");

	//MessageBox::Show("you chose :: " + this->comboGems->Text + " sg = " + sg[comboGems->Text]);

		/**************************IMAGE MANAGEMENT**************************/
	EmbeddedImage^ gemImage = gcnew EmbeddedImage;
	if (sg->ContainsKey(this->comboGems->Text)){
		gemImage->setName(this->comboGems->Text);
	this->picGem->Image = gemImage->getName();
	this->txtSg->Text = sg[this->comboGems->Text];
	} //stop crash if key doesn't exist
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void quitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (MessageBox::Show(
		"Really quit program?",
		"EXIT PROGRAM", MessageBoxButtons::YesNo,
		MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		Close();
	}
}
private: System::Void comboCut_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Form1::radioBtnGem->Checked) {
		GemCut^ gc = gcnew GemCut; // Declare object
		gc->dictInitializer();
		String^ myGemCut = gc->getCut(this->comboCut->Text); // dc->_diaCut[this->comboCut->Text];
		//MessageBox::Show(myGemCut);
		Form1::txtCutSel->Text = myGemCut;

		EmbeddedImage^ gCutImage = gcnew EmbeddedImage;
		/**************************IMAGE MANAGEMENT**************************/
			gCutImage->setName(this->comboCut->Text);
			this->picCut->Image = gCutImage->getName();


	

	}
	else if (Form1::radioBtnDia->Checked) {
		DiamondCut^ dc = gcnew DiamondCut; // Declare object
		dc->dictInitializer();
		String^ myDiamondCut = dc->getCut(this->comboCut->Text); // dc->_diaCut[this->comboCut->Text];
		//MessageBox::Show(myDiamondCut);
		Form1::txtCutSel->Text = myDiamondCut;
	}
	EmbeddedImage^ dCutImage = gcnew EmbeddedImage;
	/**************************IMAGE MANAGEMENT**************************/
	dCutImage->setName(this->comboCut->Text);
	this->picCut->Image = dCutImage->getName();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show(
		"Gemwest 2.0\nA mounted gemstone ct weight estimator\nMade with C++/CLI",
		"About Gemwest 2.0", MessageBoxButtons::OK,
		MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
	{
		 //do nothing - just close dialog
	}
}
private: System::Void txtSg_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	{
		// Only allow 1 decimal point
		if (e->KeyChar == '.')
		{
			if (this-> txtSg->Text->Contains(".") && !this->txtSg->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}
}
private: System::Void txtCutSel_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	{
		// Only allow 1 decimal point
		if (e->KeyChar == '.')
		{
			if (this->txtCutSel->Text->Contains(".") && !this->txtCutSel->SelectedText->Contains("."))
				e->Handled = true;
		}
		// Accept only digits "." and the Backspace character
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}


}
private: System::Void radioBtnDia_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	
	this->txtCutSel->Clear();
	this->comboCut->ResetText();
	this->comboCut->SelectedText="choose from below";
	this->comboGems->ResetText();
	this->comboGems->SelectedText = "choose from below";
	this->txtSg->Text = "3.52";
	this->comboGems->Enabled = false;
	this->txtSg->Enabled = false;
	array<String^>^ dias = gcnew array<String^>{};
	DiamondCut^ dc = gcnew DiamondCut; // Declare object
	if (dc != nullptr) {
		dc->dictInitializer();
		dias = dc->getCutNames();
		Form1::comboCut->Items->Clear();
		Form1::comboCut->Items->AddRange(dias);
	} // != null

	EmbeddedImage^ defaultRBC = gcnew EmbeddedImage;
	/**************************IMAGE MANAGEMENT**************************/
	defaultRBC->setName("round brilliant");
	this->picCut->Image = defaultRBC->getName();
}
private: System::Void radioBtnGem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->txtCutSel->Clear();
	this->comboCut->ResetText();
	this->comboCut->SelectedText = "choose from below";

	this->comboGems->ResetText();
	this->comboGems->SelectedText = "choose from below";
	this->txtSg->Text = "";
	this->comboGems->Enabled = true;
	this->txtSg->Enabled = true;
	array<String^>^ gems = gcnew array<String^>{};
		GemCut^ gc = gcnew GemCut; // Declare object
		if (gc != nullptr) {
		gc->dictInitializer();
		gems = gc->getCutNames();
		Form1::comboCut->Items->Clear();
		Form1::comboCut->Items->AddRange(gems);

	} // != null
		EmbeddedImage^ defaultGemCut = gcnew EmbeddedImage;
		/**************************IMAGE MANAGEMENT**************************/
		defaultGemCut->setName("oval cut");
		this->picCut->Image = defaultGemCut->getName();
}
private: System::Void tbGlobalAdj_Scroll(System::Object^ sender, System::EventArgs^ e) {

	this->txtGlobAdjust->Text = this->tbGlobalAdj->Value.ToString()+"%";
}
private: System::Void tbOtherNudge_Scroll(System::Object^ sender, System::EventArgs^ e) {

	this->txtOther->Text = this->tbOtherNudge->Value.ToString() + "%";
}

private: System::Void tbGirdleThickness_Scroll(System::Object^ sender, System::EventArgs^ e) {
	this->txtGirdleThickness->Text = this->tbGirdleThickness->Value.ToString() + "%";
	String^ gThk = "thingirdle";
	if (this->tbGirdleThickness->Value < 4) {
		gThk = "thingirdle";
	}
	else if (this->tbGirdleThickness->Value < 7) {
		gThk = "mediumgirdle";
	}
	else if (this->tbGirdleThickness->Value < 11) {
		gThk = "thickgirdle";
	}
	else if (this->tbGirdleThickness->Value < 16) {
		gThk = "sthickgirdle";
	}
	else {
		gThk = "thingirdle";
	}
	EmbeddedImage^ girdleImage = gcnew EmbeddedImage;
	/**************************IMAGE MANAGEMENT**************************/
	girdleImage->setName(gThk);
	this->picGirdle->Image = girdleImage->getName();
}


private: System::Void tbPavilionBulge_Scroll(System::Object^ sender, System::EventArgs^ e) {
	this->txtPavilionBulge->Text = this->tbPavilionBulge->Value.ToString() + "%";
	String^ pBulge = "bulge_non";
	if (this->tbPavilionBulge->Value < 6) {
		pBulge = "bulge_non";
	}
	else if (this->tbPavilionBulge->Value < 11) {
		pBulge = "bulge_sml";
	}
	else if (this->tbPavilionBulge->Value < 21) {
		pBulge = "bulge_med";
	}
	else if (this->tbPavilionBulge->Value < 31) {
		pBulge = "bulge_big";
	}
	else {
		pBulge = "bulge_non";
	}
	EmbeddedImage^ bulgeImage = gcnew EmbeddedImage;
	/**************************IMAGE MANAGEMENT**************************/
	bulgeImage->setName(pBulge);
	this->picBulge->Image = bulgeImage->getName();
}
private: System::Void lblDia2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}

private: System::Void picDepth_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}



 


