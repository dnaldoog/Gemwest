#pragma once
#include <map>
#include "CDiamondCut.h"
#include "SpecificGravity.h"
#include "CGemCut.h"
#include "CEmbeddedImage.h"
#include "resource1.h"
#include "CCutDim.h"
#include "CDcalc.h"
#include "CTaperedBaguette.h"
#include "CDround.h"
#include "CDfancy.h"
#include "CGcalc.h"
#include "LogForm.h"
#include "AboutForm1.h"
#include "HelpForm.h"
#include "OptionsForm.h"
#include "BridgeCS.h"

namespace CppCLRWinformsProjekt {
	//
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Diagnostics;
	using namespace System::Resources;
	using namespace System::Configuration;


	/// <summary>
	/// Zusammenfassung für Form1
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
	private:
		/***************************************************************************************/
		String^ miSign() {
			String^ retSig = L"+";
			String^ extracted_adjustments = this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1);
			Double conv = Convert::ToDouble(extracted_adjustments);
			signed short sign = Math::Sign(conv);
			if (sign == -1) {

				retSig = L"";
			}
			return retSig;
	
		}
	
		void repaint_girdle_thickness() {

			String^ gThk = "thingirdle";
			if (this->tbGirdleThickness->Value < 4) {
				gThk = "thingirdle";
			}
			else if (this->tbGirdleThickness->Value < 10) {
				gThk = "mediumgirdle";
			}
			else if (this->tbGirdleThickness->Value < 14) {
				gThk = "thickgirdle";
			}
			else if (this->tbGirdleThickness->Value < 21) {
				gThk = "sthickgirdle";
			}
			else {
				gThk = "thingirdle";
			}

			CEmbeddedImage^ girdleImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			girdleImage->setName(gThk);
			this->picGirdle->Image = girdleImage->getName();

		}
		/***************************************************************************************/
		void repaint_pavilion_bulge() {
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
			CEmbeddedImage^ bulgeImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			bulgeImage->setName(pBulge);
			this->picBulge->Image = bulgeImage->getName();
		}
		/***************************************************************************************/
		void repaint_shape_outline() {
			String^ so = "so3";

			if (this->tbShapeOutline->Value < -3) {
				so = "so1";
			}
			else if (this->tbShapeOutline->Value < 0) {
				so = "so2";
			}
			else if (this->tbShapeOutline->Value < 1) {
				so = "so3";
			}
			else if (this->tbShapeOutline->Value < 5) {
				so = "so4";
			}
			else if (this->tbShapeOutline->Value < 10) {
				so = "so5";
			}
			else if (this->tbShapeOutline->Value < 16) {
				so = "so6";
			}
			else {
				so = "so3";
			}
			CEmbeddedImage^ shapeOutlineImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			shapeOutlineImage->setName(so);
			this->picShapeOutline->Image = shapeOutlineImage->getName();

		}
		/***************************************************************************************/
		void calculate_carat_weight() {

			CDcalc^ p = nullptr;
			String^ errorMessage = L"Invalid Input!!\nPlease select a cut!";

			if (this->comboCut->Text->Contains("choose")) {
				MessageBox::Show(errorMessage);
			}
			else {
				if (this->radioBtnDia->Checked) { // Calculate the weight of a diamond



					if (this->comboCut->Text->Equals(TAPBAG))

					{
						CTaperedBaguette^ TB = gcnew CTaperedBaguette(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						TB->maxW = this->numTaperedBaguetteMaxWidth->Value;
						p = TB;
					}
					else if (this->comboCut->Text->Equals(MARQ)) {
						CDfancy^ MQ = gcnew CDfancy(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						MQ->fancyType = MARQ;
						p = MQ;
					}
					else if (this->comboCut->Text->Equals(PEAR)) {
						CDfancy^ PR = gcnew CDfancy(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						PR->fancyType = PEAR;
						p = PR;
					}
					else if (this->comboCut->Text->Equals(EMER)) {
						CDfancy^ EM = gcnew CDfancy(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						EM->fancyType = EMER;
						p = EM;
					}
					else if (this->comboCut->Text->Equals(RADI)) {
						CDfancy^ RI = gcnew CDfancy(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						RI->fancyType = RADI;
						p = RI;
					}
					else if (CCutDim::isRoundish(this->comboCut->Text)) {
						CDround^ RC = gcnew CDround(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked);
						p = RC;
						this->txtEstRecut->Text = RC->recut_weight() + " ct";
					}
					else {

						CDcalc^ defaultCutFormula = gcnew CDcalc(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						p = defaultCutFormula;
					}
					String^ tot = System::Convert::ToString(Math::Round(p->term(), 3)) + "ct";
					this->txtResult->Text = tot;
					if (CCutDim::isRoundish(this->comboCut->Text)) {
						Decimal avd = Decimal::Add(this->numDia1->Value,this->numDia2->Value) / 2;
							avd = Math::Round((avd),2);
						this->toolStrip->Text = L"[Diamond:" + this->comboCut->Text + "] Total weight=(" + avd + ")2 x" + this->numDepth->Text + " x" + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
					}
					else {
						this->toolStrip->Text = L"[Diamond:" + this->comboCut->Text + "] Total weight=" + this->numDia1->Text + " x" + this->numDia2->Text + " x" + this->numDepth->Text + " x" + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;

					}
					
				} // is tapered baguette or other
				else { // Calculate the weight of a Gemstone
					CGcalc^ GC = gcnew CGcalc;
					GC->Initializer(

						this->comboCut->Text,
						this->comboGems->Text,
						this->txtFactor->Text,
						this->numDia1->Value,
						this->numDia2->Value,
						this->numDepth->Value,
						this->numSG->Text,
						this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1),
						this->txtGirdleThickness->Text,
						this->txtPavilionBulge->Text,
						this->txtShapeOutline->Text,
						this->radioBtnDia->Checked,
						this->cbInterpolate->Checked,
						this->cbRecut->Checked,
						CCutDim::isRoundish(this->comboCut->Text),
						this->radDepthAsPerc->Checked
					);
				}

			} // text is valid


		} // main calculation code

		/***************************************************************************************/
		Boolean fancyCutSelected(String^ sel) {
			Boolean ret = false;
			if (sel->Equals(MARQ) || sel->Equals(PEAR) || sel->Equals(EMER) || sel->Equals(RADI))
				ret = true;
			return ret;
		} // check whether a fancy cut was selected

		void onScreenInfo() {

			this->cbInterpolate->Enabled = false;
			this->cbRecut->Enabled = false;

			if (!this->numDia1->Text->Equals("0.00")) {

				if (!this->numDia2->Text->Equals("0.00")) {
					Double dep = System::Convert::ToDouble(this->numDepth->Text);
					Double len = System::Convert::ToDouble(this->numDia1->Text);
					Double wid = System::Convert::ToDouble(this->numDia2->Text);
					Double lwRatio;
					Double depthPercentage;
					Double depmm;
					if (dep == 0.00 || len == 0.00 || wid == 0.00) {
						/*https://social.msdn.microsoft.com/Forums/vstudio/en-US/5ac4c768-2c33-4636-a700-d0b3fafeac68/warning-c4965-implicit-box-of-integer-0-use-nullptr-or-explicit-cast*/

						return;
					}
					lwRatio = len / wid;
					/*
					cut hasn't been chosen so we need to determine how to calculate Width
					Should it be just Width or Diameter-1 + Diameter-2/2 ?
					*/


					if (CCutDim::isRoundish(this->comboCut->Text)) {
						this->cbRecut->Enabled = true;
						wid = (wid + len) / 2;
						depthPercentage = (dep / wid) * 100;
						depmm = (wid * dep) / 100;
						this->lblCombinedRoundAverage->Text = "AV:" + System::Convert::ToString(Math::Round(wid, 2));
					}
					else {
						this->lblCombinedRoundAverage->Text = "";
					}
					depthPercentage = (dep / wid) * 100;
					depmm = (wid * dep) / 100;

					String^ lwString = System::Convert::ToString(Math::Round(lwRatio, 2));
					String^ lWtxt = "LW Ratio = " + lwString + ":1";
					String^ percString = System::Convert::ToString(Math::Round(depthPercentage, 2));
					String^ mmString = System::Convert::ToString(depmm);

					if (this->radDepthAsPerc->Checked) {
						this->lblDepthPerc->Text = "Depth = " + mmString + "mm";
						this->lblHiddenDepth->Text = this->numDepth->Text;

					}
					else {
						this->lblDepthPerc->Text = "Depth = " + percString + "%";

						this->lblHiddenDepth->Text = percString;

					}
					this->lblLwRatio->Text = lWtxt;
					if (len >= wid) {
						draw_lw(lwString);
					}
					else if (wid > len) {
						this->picLW->Image = nullptr;
						this->picLW->Refresh();
						CEmbeddedImage^ cd = gcnew CEmbeddedImage;
						cd->setName("checklength");
						this->picLW->Image = cd->getName();
					}
					if (fancyCutSelected(this->comboCut->Text)) {
						this->cbInterpolate->Enabled = true;
						CDfancy^ fancyFactor = gcnew CDfancy(

							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbInterpolate->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);

						fancyFactor->interpolate = this->cbInterpolate->Checked;
						fancyFactor->length = len;
						fancyFactor->width = wid;
						fancyFactor->fancyType = this->comboCut->Text;
						this->txtFactor->Text = fancyFactor->setFancyRecutFactor();

					}


				} 	// end numDia1 or numDia2 == 0

			}
			Form1::Update();
			this->calculate_carat_weight();
		}
		/***************************************************************************************/
		void combine_adjustments() {

			Double sum;
			sum = this->tbGirdleThickness->Value + this->tbPavilionBulge->Value + this->tbShapeOutline->Value;
			this->txtGlobAdjust->Text = System::Convert::ToString(sum) + "%";
		}

		void draw_depth(String^ perc) {

			this->picDepth->Image = nullptr;
			this->picDepth->Refresh();

			Double divider = System::Convert::ToDouble(this->lblHiddenDepth->Text) / 100;
			Double percentage = System::Convert::ToDouble(this->picDepth->Height) * divider;
			Graphics^ gd = picDepth->CreateGraphics();
			Rectangle  r = Rectangle(0, 0, this->picDepth->Width, System::Convert::ToInt32(percentage));

			if (divider >= 1.00) { gd->FillRectangle(Brushes::Orange, r); }
			else { gd->FillRectangle(Brushes::CornflowerBlue, r); }


		}
		/***************************************************************************************/
		void draw_lw(String^ lwStr) {	}

		void draw_lw2(String^ lwStr) {

			if (!this->comboCut->Text->Equals(TAPBAG)) {
				this->picLW->Image = nullptr;
				this->picLW->Refresh();

				Double push = 0;
				Double shrink = 0.8;
				Graphics^ gl = this->picLW->CreateGraphics();
				Double lw = System::Convert::ToDouble(lwStr) - push * shrink;
				Double w = System::Convert::ToDouble(this->picLW->Width - push) * shrink;
				Double l = System::Convert::ToDouble(this->picLW->Height - push) * shrink;

				w = (w / lw) - push * shrink;

				Pen^ myPen = gcnew Pen(Color::RoyalBlue, 2);
				Single halfPenWidth = myPen->Width * 0.5f;

				Double placeCentre = (this->picLW->Width / 2) - (w / 2) - halfPenWidth;

				RectangleF  r = RectangleF(System::Convert::ToSingle(placeCentre), System::Convert::ToSingle(6), System::Convert::ToSingle(w), System::Convert::ToSingle(l));

				gl->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::HighQuality;
				gl->DrawEllipse(myPen, r);


			}// if not tapered baguette crashing at line 206

		} // end function draw LW Rectangle

	private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ preferencesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem1;
	private: System::Windows::Forms::TextBox^ txtShapeOutline;
	private: System::Windows::Forms::Label^ lblShape;
	private: System::Windows::Forms::TrackBar^ tbShapeOutline;
	private: System::Windows::Forms::PictureBox^ pictAdjArrow;
	private: System::Windows::Forms::PictureBox^ picRecut;

	private: System::Windows::Forms::PictureBox^ picDepth;

	private: System::Windows::Forms::Label^ lblRecut;
	private: System::Windows::Forms::Label^ lblHiddenDepth;
	private: System::Windows::Forms::GroupBox^ groupBoxCalculate;
	private: System::Windows::Forms::Label^ lblWeightInCarats;
	private: System::Windows::Forms::PictureBox^ picLW;


	private: System::Windows::Forms::PictureBox^ picShapeOutline;



	public:

	protected:

	private: System::Windows::Forms::Button^ btnEq;
	private: System::Windows::Forms::Button^ buttonCalc;
	private: System::Windows::Forms::Button^ buttonClear;
	private: System::Windows::Forms::TextBox^ txtResult;

	private: System::Windows::Forms::Label^ lbllSelectedSG;
	private: System::Windows::Forms::GroupBox^ lwguide;

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

	private: System::Windows::Forms::ToolStripMenuItem^ viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ logToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^ lblPavilionBulge;
	private: System::Windows::Forms::Label^ lblGirdleThickness;
	private: System::Windows::Forms::Label^ lblGlobAdj;

	private: System::Windows::Forms::Label^ lblDepth;
	private: System::Windows::Forms::Label^ lblDia2;
	private: System::Windows::Forms::Label^ lblDia1;
	private: System::Windows::Forms::TrackBar^ tbPavilionBulge;
	private: System::Windows::Forms::TrackBar^ tbGirdleThickness;
	private: System::Windows::Forms::TextBox^ txtFactor;
	private: System::Windows::Forms::Label^ lblSelectedCut;
	private: System::Windows::Forms::ComboBox^ comboCut;
	private: System::Windows::Forms::Label^ lblSgValue;
	private: System::Windows::Forms::Label^ lblCutFactor;
	private: System::Windows::Forms::ComboBox^ comboGems;
	private: System::Windows::Forms::TextBox^ txtPavilionBulge;
	private: System::Windows::Forms::TextBox^ txtGirdleThickness;
	private: System::Windows::Forms::TextBox^ txtGlobAdjust;
	private: System::Windows::Forms::PictureBox^ picGem;
	private: System::Windows::Forms::PictureBox^ picCut;
	private: System::Windows::Forms::PictureBox^ picBulge;
	private: System::Windows::Forms::PictureBox^ picGirdle;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStrip;
	private: System::Windows::Forms::NumericUpDown^ numSG;
	private: System::Windows::Forms::NumericUpDown^ numDepth;
	private: System::Windows::Forms::NumericUpDown^ numDia2;
	private: System::Windows::Forms::NumericUpDown^ numDia1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ radDepthAsPerc;
	private: System::Windows::Forms::RadioButton^ radDepthAsMm;
	private: System::Windows::Forms::Label^ lblCombinedRoundAverage;
	private: System::Windows::Forms::GroupBox^ groupBoxChooseDiaOrGem;

	private: System::Windows::Forms::TextBox^ txtEstRecut;
	private: System::Windows::Forms::NumericUpDown^ numTaperedBaguetteMaxWidth;
	private: System::Windows::Forms::Label^ lblMaxWidth;
	private: System::Windows::Forms::Button^ btnClearSO;
	private: System::Windows::Forms::Button^ btnClearPB;
	private: System::Windows::Forms::Button^ btnClearGT;



	protected:
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboGems = (gcnew System::Windows::Forms::ComboBox());
			this->btnEq = (gcnew System::Windows::Forms::Button());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->txtResult = (gcnew System::Windows::Forms::TextBox());
			this->lbllSelectedSG = (gcnew System::Windows::Forms::Label());
			this->lwguide = (gcnew System::Windows::Forms::GroupBox());
			this->btnClearSO = (gcnew System::Windows::Forms::Button());
			this->btnClearPB = (gcnew System::Windows::Forms::Button());
			this->btnClearGT = (gcnew System::Windows::Forms::Button());
			this->lblMaxWidth = (gcnew System::Windows::Forms::Label());
			this->numTaperedBaguetteMaxWidth = (gcnew System::Windows::Forms::NumericUpDown());
			this->picShapeOutline = (gcnew System::Windows::Forms::PictureBox());
			this->lblDepthPerc = (gcnew System::Windows::Forms::Label());
			this->picGirdle = (gcnew System::Windows::Forms::PictureBox());
			this->picBulge = (gcnew System::Windows::Forms::PictureBox());
			this->lblHiddenDepth = (gcnew System::Windows::Forms::Label());
			this->picLW = (gcnew System::Windows::Forms::PictureBox());
			this->lblDepth = (gcnew System::Windows::Forms::Label());
			this->picDepth = (gcnew System::Windows::Forms::PictureBox());
			this->numDepth = (gcnew System::Windows::Forms::NumericUpDown());
			this->pictAdjArrow = (gcnew System::Windows::Forms::PictureBox());
			this->txtShapeOutline = (gcnew System::Windows::Forms::TextBox());
			this->lblShape = (gcnew System::Windows::Forms::Label());
			this->tbShapeOutline = (gcnew System::Windows::Forms::TrackBar());
			this->lblCombinedRoundAverage = (gcnew System::Windows::Forms::Label());
			this->lblLwRatio = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radDepthAsPerc = (gcnew System::Windows::Forms::RadioButton());
			this->radDepthAsMm = (gcnew System::Windows::Forms::RadioButton());
			this->numDia2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numDia1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtPavilionBulge = (gcnew System::Windows::Forms::TextBox());
			this->txtGirdleThickness = (gcnew System::Windows::Forms::TextBox());
			this->txtGlobAdjust = (gcnew System::Windows::Forms::TextBox());
			this->tbPavilionBulge = (gcnew System::Windows::Forms::TrackBar());
			this->tbGirdleThickness = (gcnew System::Windows::Forms::TrackBar());
			this->lblPavilionBulge = (gcnew System::Windows::Forms::Label());
			this->lblGirdleThickness = (gcnew System::Windows::Forms::Label());
			this->lblGlobAdj = (gcnew System::Windows::Forms::Label());
			this->lblDia2 = (gcnew System::Windows::Forms::Label());
			this->lblDia1 = (gcnew System::Windows::Forms::Label());
			this->lblRecut = (gcnew System::Windows::Forms::Label());
			this->picRecut = (gcnew System::Windows::Forms::PictureBox());
			this->cbRecut = (gcnew System::Windows::Forms::CheckBox());
			this->cbInterpolate = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtEstRecut = (gcnew System::Windows::Forms::TextBox());
			this->numSG = (gcnew System::Windows::Forms::NumericUpDown());
			this->picGem = (gcnew System::Windows::Forms::PictureBox());
			this->picCut = (gcnew System::Windows::Forms::PictureBox());
			this->lblSgValue = (gcnew System::Windows::Forms::Label());
			this->lblCutFactor = (gcnew System::Windows::Forms::Label());
			this->txtFactor = (gcnew System::Windows::Forms::TextBox());
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
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxCalculate = (gcnew System::Windows::Forms::GroupBox());
			this->lblWeightInCarats = (gcnew System::Windows::Forms::Label());
			this->groupBoxChooseDiaOrGem = (gcnew System::Windows::Forms::GroupBox());
			this->lwguide->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTaperedBaguetteMaxWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picShapeOutline))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGirdle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBulge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLW))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDepth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDepth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictAdjArrow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbShapeOutline))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDia2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDia1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPavilionBulge))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGirdleThickness))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecut))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGem))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCut))->BeginInit();
			this->statusbar->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBoxCalculate->SuspendLayout();
			this->groupBoxChooseDiaOrGem->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboGems
			// 
			this->comboGems->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboGems->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboGems->Enabled = false;
			this->comboGems->FormattingEnabled = true;
			this->comboGems->Items->AddRange(gcnew cli::array< System::Object^  >(200) {
				L"actinolite", L"agate", L"albite", L"alexandrite",
					L"almandine", L"almandine", L"amazonite", L"amber", L"amethyst", L"ammolite", L"andalusite", L"apatite", L"aquamarine", L"aragonite",
					L"aventurine quartz", L"aventurine", L"axinite (ferro-axinite)", L"azurite", L"bakelite", L"benitoite", L"beryl aquamarine",
					L"beryl colourless", L"beryl heliodor", L"beryl morganite", L"beryl", L"beryl maxixe", L"blende", L"bloodstone", L"blue topaz",
					L"bonamite", L"bowenite", L"brazilianite", L"calcite", L"californite", L"carborundum", L"carnelian", L"cassiterite", L"cat\'s eye chrysoberyl",
					L"celluloid", L"chalcedony agate", L"chalcedony aventurine", L"chalcedony carnelian", L"chalcedony heliotrope", L"chalcedony moss agate",
					L"chalcedony onyx", L"chalcedony", L"chrome diopside", L"chrysoberyl alexandrite", L"chrysoberyl cat\'s eye", L"chrysoberyl cymophane",
					L"chrysoberyl", L"chrysocolla", L"chrysoprase", L"citrine", L"colourless beryl", L"conch pearl", L"copal resin", L"coral", L"cornelian",
					L"corundum ruby", L"corundum sapphire", L"corundum synthetic", L"corundum", L"crocidolite", L"cubic zirconia", L"cymophane",
					L"cz", L"danburite", L"datolite", L"demantoid", L"diamond", L"diopside", L"ekanite", L"emerald (Gilson)", L"emerald", L"enstatite",
					L"epidote", L"euclase", L"fibrolite", L"fire opal", L"fluorite", L"garnet almandine", L"garnet demantoid", L"garnet grossular (pure)",
					L"garnet hessonite", L"garnet (mali)", L"garnet pyrope", L"garnet spessartine", L"garnet uvarovite", L"garnet", L"ggg", L"glass",
					L"golden beryl", L"goshenite", L"grossular garnet", L"grossular", L"grossular (pure)", L"haematite", L"hambergite", L"heliodor",
					L"hematite", L"hemimorphite", L"hessonite", L"hiddenite", L"howlite", L"idocrase", L"imperial topaz", L"iolite", L"jadeite",
					L"jasper", L"jet", L"kornerupine", L"kunzite", L"kyanite", L"lapis lazuli", L"larimar", L"lazulite", L"lepidolite", L"lithium niobate",
					L"malachite", L"malaia garnet", L"mali garnet", L"marcasite", L"maw-sit-sit", L"maxixe", L"moissanite", L"moldavite", L"morganite",
					L"moss agate", L"nephrite", L"obsidian", L"odontolite", L"onyx", L"opal", L"padparadscha", L"painite", L"paraíba tourmaline",
					L"pearl", L"periclase", L"peridot", L"phenakite", L"pink beryl", L"pink topaz", L"pleonaste", L"porcelain", L"prehnite", L"pseudophite",
					L"pyrites", L"pyrope", L"quartz amethyst", L"quartz aventurine", L"quartz chalcedony", L"quartz citrine", L"quartz rutillated",
					L"quartz", L"rhodochrosite", L"rhodonite", L"rubbelite", L"ruby", L"rutile", L"rutillated quartz", L"sapphire", L"sard", L"scapolite",
					L"scheelite", L"schorl", L"serpentine", L"seraphinite", L"silica glass", L"sinhalite", L"smithsonite", L"spessartine", L"sphalerite",
					L"sphene", L"spinel synthetic", L"spinel", L"spodumene", L"strontium titanate", L"sugilite", L"synthetic corundum", L"taaffeite",
					L"tanzanite", L"tektite", L"tiger eye", L"titanite", L"topaz", L"tortoiseshell", L"tourmaline schorl", L"tourmaline", L"turquoise",
					L"uvarovite", L"variscite", L"vesuvianite", L"vivianite", L"water opal", L"yttrium aluminate YAG", L"zircon (metamict)", L"zircon (normal)",
					L"zirconia (cubic)", L"zoisite"
			});
			this->comboGems->Location = System::Drawing::Point(90, 28);
			this->comboGems->Name = L"comboGems";
			this->comboGems->Size = System::Drawing::Size(121, 21);
			this->comboGems->TabIndex = 8;
			this->comboGems->Text = L"choose from below";
			this->comboGems->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboGems_SelectedIndexChanged);
			// 
			// btnEq
			// 
			this->btnEq->Location = System::Drawing::Point(154, 29);
			this->btnEq->Name = L"btnEq";
			this->btnEq->Size = System::Drawing::Size(37, 20);
			this->btnEq->TabIndex = 1;
			this->btnEq->Text = L"=";
			this->btnEq->UseVisualStyleBackColor = true;
			this->btnEq->Click += gcnew System::EventHandler(this, &Form1::btnEq_Click);
			// 
			// buttonCalc
			// 
			this->buttonCalc->Location = System::Drawing::Point(307, 25);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(100, 23);
			this->buttonCalc->TabIndex = 5;
			this->buttonCalc->Text = L"Calculate";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &Form1::buttonCalc_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::SystemColors::Desktop;
			this->buttonClear->ForeColor = System::Drawing::SystemColors::Window;
			this->buttonClear->Location = System::Drawing::Point(419, 25);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(47, 23);
			this->buttonClear->TabIndex = 6;
			this->buttonClear->Text = L"X";
			this->buttonClear->UseVisualStyleBackColor = false;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// txtResult
			// 
			this->txtResult->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->txtResult->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtResult->Location = System::Drawing::Point(139, 19);
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
			this->lbllSelectedSG->Location = System::Drawing::Point(14, 30);
			this->lbllSelectedSG->Name = L"lbllSelectedSG";
			this->lbllSelectedSG->Size = System::Drawing::Size(62, 13);
			this->lbllSelectedSG->TabIndex = 9;
			this->lbllSelectedSG->Text = L"Select Gem";
			// 
			// lwguide
			// 
			this->lwguide->BackColor = System::Drawing::SystemColors::ControlLight;
			this->lwguide->Controls->Add(this->btnClearSO);
			this->lwguide->Controls->Add(this->btnClearPB);
			this->lwguide->Controls->Add(this->btnClearGT);
			this->lwguide->Controls->Add(this->lblMaxWidth);
			this->lwguide->Controls->Add(this->numTaperedBaguetteMaxWidth);
			this->lwguide->Controls->Add(this->picShapeOutline);
			this->lwguide->Controls->Add(this->lblDepthPerc);
			this->lwguide->Controls->Add(this->picGirdle);
			this->lwguide->Controls->Add(this->picBulge);
			this->lwguide->Controls->Add(this->lblHiddenDepth);
			this->lwguide->Controls->Add(this->picLW);
			this->lwguide->Controls->Add(this->lblDepth);
			this->lwguide->Controls->Add(this->picDepth);
			this->lwguide->Controls->Add(this->numDepth);
			this->lwguide->Controls->Add(this->pictAdjArrow);
			this->lwguide->Controls->Add(this->txtShapeOutline);
			this->lwguide->Controls->Add(this->lblShape);
			this->lwguide->Controls->Add(this->tbShapeOutline);
			this->lwguide->Controls->Add(this->lblCombinedRoundAverage);
			this->lwguide->Controls->Add(this->lblLwRatio);
			this->lwguide->Controls->Add(this->panel1);
			this->lwguide->Controls->Add(this->numDia2);
			this->lwguide->Controls->Add(this->numDia1);
			this->lwguide->Controls->Add(this->txtPavilionBulge);
			this->lwguide->Controls->Add(this->txtGirdleThickness);
			this->lwguide->Controls->Add(this->txtGlobAdjust);
			this->lwguide->Controls->Add(this->tbPavilionBulge);
			this->lwguide->Controls->Add(this->tbGirdleThickness);
			this->lwguide->Controls->Add(this->lblPavilionBulge);
			this->lwguide->Controls->Add(this->lblGirdleThickness);
			this->lwguide->Controls->Add(this->lblGlobAdj);
			this->lwguide->Controls->Add(this->lblDia2);
			this->lwguide->Controls->Add(this->lblDia1);
			this->lwguide->Controls->Add(this->btnEq);
			this->lwguide->Location = System::Drawing::Point(12, 27);
			this->lwguide->Name = L"lwguide";
			this->lwguide->Size = System::Drawing::Size(505, 352);
			this->lwguide->TabIndex = 12;
			this->lwguide->TabStop = false;
			// 
			// btnClearSO
			// 
			this->btnClearSO->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnClearSO->ForeColor = System::Drawing::SystemColors::Window;
			this->btnClearSO->Location = System::Drawing::Point(389, 244);
			this->btnClearSO->Name = L"btnClearSO";
			this->btnClearSO->Size = System::Drawing::Size(47, 23);
			this->btnClearSO->TabIndex = 58;
			this->btnClearSO->Text = L"X";
			this->btnClearSO->UseVisualStyleBackColor = false;
			this->btnClearSO->Click += gcnew System::EventHandler(this, &Form1::btnClearSO_Click);
			// 
			// btnClearPB
			// 
			this->btnClearPB->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnClearPB->ForeColor = System::Drawing::SystemColors::Window;
			this->btnClearPB->Location = System::Drawing::Point(288, 244);
			this->btnClearPB->Name = L"btnClearPB";
			this->btnClearPB->Size = System::Drawing::Size(47, 23);
			this->btnClearPB->TabIndex = 57;
			this->btnClearPB->Text = L"X";
			this->btnClearPB->UseVisualStyleBackColor = false;
			this->btnClearPB->Click += gcnew System::EventHandler(this, &Form1::btnClearPB_Click);
			// 
			// btnClearGT
			// 
			this->btnClearGT->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnClearGT->ForeColor = System::Drawing::SystemColors::Window;
			this->btnClearGT->Location = System::Drawing::Point(187, 244);
			this->btnClearGT->Name = L"btnClearGT";
			this->btnClearGT->Size = System::Drawing::Size(47, 23);
			this->btnClearGT->TabIndex = 54;
			this->btnClearGT->Text = L"X";
			this->btnClearGT->UseVisualStyleBackColor = false;
			this->btnClearGT->Click += gcnew System::EventHandler(this, &Form1::btnClearGT_Click);
			// 
			// lblMaxWidth
			// 
			this->lblMaxWidth->AutoSize = true;
			this->lblMaxWidth->Location = System::Drawing::Point(281, 14);
			this->lblMaxWidth->Name = L"lblMaxWidth";
			this->lblMaxWidth->Size = System::Drawing::Size(58, 13);
			this->lblMaxWidth->TabIndex = 56;
			this->lblMaxWidth->Text = L"Max Width";
			this->lblMaxWidth->Visible = false;
			// 
			// numTaperedBaguetteMaxWidth
			// 
			this->numTaperedBaguetteMaxWidth->DecimalPlaces = 2;
			this->numTaperedBaguetteMaxWidth->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numTaperedBaguetteMaxWidth->Location = System::Drawing::Point(284, 30);
			this->numTaperedBaguetteMaxWidth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numTaperedBaguetteMaxWidth->Name = L"numTaperedBaguetteMaxWidth";
			this->numTaperedBaguetteMaxWidth->Size = System::Drawing::Size(55, 20);
			this->numTaperedBaguetteMaxWidth->TabIndex = 55;
			this->numTaperedBaguetteMaxWidth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->numTaperedBaguetteMaxWidth->Visible = false;
			this->numTaperedBaguetteMaxWidth->ValueChanged += gcnew System::EventHandler(this, &Form1::numTaperedBaguetteMaxWidth_ValueChanged);
			// 
			// picShapeOutline
			// 
			this->picShapeOutline->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picShapeOutline->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picShapeOutline->Location = System::Drawing::Point(363, 273);
			this->picShapeOutline->Name = L"picShapeOutline";
			this->picShapeOutline->Size = System::Drawing::Size(85, 67);
			this->picShapeOutline->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picShapeOutline->TabIndex = 54;
			this->picShapeOutline->TabStop = false;
			// 
			// lblDepthPerc
			// 
			this->lblDepthPerc->AutoSize = true;
			this->lblDepthPerc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDepthPerc->Location = System::Drawing::Point(202, 63);
			this->lblDepthPerc->Name = L"lblDepthPerc";
			this->lblDepthPerc->Size = System::Drawing::Size(79, 13);
			this->lblDepthPerc->TabIndex = 16;
			this->lblDepthPerc->Text = L"Depth = 50%";
			// 
			// picGirdle
			// 
			this->picGirdle->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picGirdle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picGirdle->Location = System::Drawing::Point(165, 273);
			this->picGirdle->Name = L"picGirdle";
			this->picGirdle->Size = System::Drawing::Size(85, 67);
			this->picGirdle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picGirdle->TabIndex = 23;
			this->picGirdle->TabStop = false;
			// 
			// picBulge
			// 
			this->picBulge->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picBulge->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picBulge->Location = System::Drawing::Point(264, 273);
			this->picBulge->Name = L"picBulge";
			this->picBulge->Size = System::Drawing::Size(85, 67);
			this->picBulge->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBulge->TabIndex = 22;
			this->picBulge->TabStop = false;
			// 
			// lblHiddenDepth
			// 
			this->lblHiddenDepth->AutoSize = true;
			this->lblHiddenDepth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHiddenDepth->Location = System::Drawing::Point(14, 79);
			this->lblHiddenDepth->Name = L"lblHiddenDepth";
			this->lblHiddenDepth->Size = System::Drawing::Size(13, 13);
			this->lblHiddenDepth->TabIndex = 52;
			this->lblHiddenDepth->Text = L"0";
			this->lblHiddenDepth->Visible = false;
			this->lblHiddenDepth->TextChanged += gcnew System::EventHandler(this, &Form1::lblHiddenDepth_TextChanged);
			// 
			// picLW
			// 
			this->picLW->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picLW->Location = System::Drawing::Point(56, 79);
			this->picLW->Name = L"picLW";
			this->picLW->Size = System::Drawing::Size(72, 72);
			this->picLW->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picLW->TabIndex = 53;
			this->picLW->TabStop = false;
			// 
			// lblDepth
			// 
			this->lblDepth->AutoSize = true;
			this->lblDepth->Location = System::Drawing::Point(375, 14);
			this->lblDepth->Name = L"lblDepth";
			this->lblDepth->Size = System::Drawing::Size(61, 13);
			this->lblDepth->TabIndex = 19;
			this->lblDepth->Text = L"Depth (mm)";
			// 
			// picDepth
			// 
			this->picDepth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picDepth->Location = System::Drawing::Point(203, 79);
			this->picDepth->Name = L"picDepth";
			this->picDepth->Size = System::Drawing::Size(98, 72);
			this->picDepth->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picDepth->TabIndex = 49;
			this->picDepth->TabStop = false;
			// 
			// numDepth
			// 
			this->numDepth->DecimalPlaces = 2;
			this->numDepth->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numDepth->Location = System::Drawing::Point(363, 30);
			this->numDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numDepth->Name = L"numDepth";
			this->numDepth->Size = System::Drawing::Size(98, 20);
			this->numDepth->TabIndex = 35;
			this->numDepth->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numDepth->ValueChanged += gcnew System::EventHandler(this, &Form1::numDepth_ValueChanged);
			// 
			// pictAdjArrow
			// 
			this->pictAdjArrow->Location = System::Drawing::Point(77, 212);
			this->pictAdjArrow->Name = L"pictAdjArrow";
			this->pictAdjArrow->Size = System::Drawing::Size(86, 20);
			this->pictAdjArrow->TabIndex = 44;
			this->pictAdjArrow->TabStop = false;
			// 
			// txtShapeOutline
			// 
			this->txtShapeOutline->Location = System::Drawing::Point(373, 218);
			this->txtShapeOutline->Name = L"txtShapeOutline";
			this->txtShapeOutline->Size = System::Drawing::Size(85, 20);
			this->txtShapeOutline->TabIndex = 43;
			this->txtShapeOutline->Text = L"0%";
			this->txtShapeOutline->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblShape
			// 
			this->lblShape->AutoSize = true;
			this->lblShape->Location = System::Drawing::Point(385, 166);
			this->lblShape->Name = L"lblShape";
			this->lblShape->Size = System::Drawing::Size(74, 13);
			this->lblShape->TabIndex = 42;
			this->lblShape->Text = L"Shape Outline";
			// 
			// tbShapeOutline
			// 
			this->tbShapeOutline->LargeChange = 1;
			this->tbShapeOutline->Location = System::Drawing::Point(370, 182);
			this->tbShapeOutline->Maximum = 15;
			this->tbShapeOutline->MaximumSize = System::Drawing::Size(104, 30);
			this->tbShapeOutline->Minimum = -10;
			this->tbShapeOutline->MinimumSize = System::Drawing::Size(104, 30);
			this->tbShapeOutline->Name = L"tbShapeOutline";
			this->tbShapeOutline->Size = System::Drawing::Size(104, 45);
			this->tbShapeOutline->TabIndex = 41;
			this->tbShapeOutline->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbShapeOutline->Scroll += gcnew System::EventHandler(this, &Form1::tbShapeOutline_Scroll);
			// 
			// lblCombinedRoundAverage
			// 
			this->lblCombinedRoundAverage->AutoSize = true;
			this->lblCombinedRoundAverage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lblCombinedRoundAverage->Location = System::Drawing::Point(152, 13);
			this->lblCombinedRoundAverage->Name = L"lblCombinedRoundAverage";
			this->lblCombinedRoundAverage->Size = System::Drawing::Size(42, 13);
			this->lblCombinedRoundAverage->TabIndex = 39;
			this->lblCombinedRoundAverage->Text = L"AV: 0.0";
			this->lblCombinedRoundAverage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblLwRatio
			// 
			this->lblLwRatio->AutoSize = true;
			this->lblLwRatio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLwRatio->Location = System::Drawing::Point(44, 63);
			this->lblLwRatio->Name = L"lblLwRatio";
			this->lblLwRatio->Size = System::Drawing::Size(97, 13);
			this->lblLwRatio->TabIndex = 15;
			this->lblLwRatio->Text = L"LW Ratio =  0:0";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->panel1->Controls->Add(this->radDepthAsPerc);
			this->panel1->Controls->Add(this->radDepthAsMm);
			this->panel1->Location = System::Drawing::Point(363, 79);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(98, 72);
			this->panel1->TabIndex = 38;
			// 
			// radDepthAsPerc
			// 
			this->radDepthAsPerc->AutoSize = true;
			this->radDepthAsPerc->Location = System::Drawing::Point(26, 39);
			this->radDepthAsPerc->Name = L"radDepthAsPerc";
			this->radDepthAsPerc->Size = System::Drawing::Size(39, 17);
			this->radDepthAsPerc->TabIndex = 37;
			this->radDepthAsPerc->Text = L"(%)";
			this->radDepthAsPerc->UseVisualStyleBackColor = true;
			this->radDepthAsPerc->CheckedChanged += gcnew System::EventHandler(this, &Form1::radDepthAsPerc_CheckedChanged);
			// 
			// radDepthAsMm
			// 
			this->radDepthAsMm->AutoSize = true;
			this->radDepthAsMm->Checked = true;
			this->radDepthAsMm->Location = System::Drawing::Point(26, 16);
			this->radDepthAsMm->Name = L"radDepthAsMm";
			this->radDepthAsMm->Size = System::Drawing::Size(47, 17);
			this->radDepthAsMm->TabIndex = 36;
			this->radDepthAsMm->TabStop = true;
			this->radDepthAsMm->Text = L"(mm)";
			this->radDepthAsMm->UseVisualStyleBackColor = true;
			this->radDepthAsMm->CheckedChanged += gcnew System::EventHandler(this, &Form1::radDepthAsMm_CheckedChanged);
			// 
			// numDia2
			// 
			this->numDia2->DecimalPlaces = 2;
			this->numDia2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numDia2->Location = System::Drawing::Point(205, 30);
			this->numDia2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numDia2->Name = L"numDia2";
			this->numDia2->Size = System::Drawing::Size(98, 20);
			this->numDia2->TabIndex = 34;
			this->numDia2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numDia2->ValueChanged += gcnew System::EventHandler(this, &Form1::numDia2_ValueChanged);
			// 
			// numDia1
			// 
			this->numDia1->DecimalPlaces = 2;
			this->numDia1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numDia1->Location = System::Drawing::Point(43, 28);
			this->numDia1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numDia1->Name = L"numDia1";
			this->numDia1->Size = System::Drawing::Size(98, 20);
			this->numDia1->TabIndex = 25;
			this->numDia1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numDia1->ValueChanged += gcnew System::EventHandler(this, &Form1::numDia1_ValueChanged);
			// 
			// txtPavilionBulge
			// 
			this->txtPavilionBulge->Location = System::Drawing::Point(269, 218);
			this->txtPavilionBulge->Name = L"txtPavilionBulge";
			this->txtPavilionBulge->Size = System::Drawing::Size(85, 20);
			this->txtPavilionBulge->TabIndex = 33;
			this->txtPavilionBulge->Text = L"0%";
			this->txtPavilionBulge->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGirdleThickness
			// 
			this->txtGirdleThickness->Location = System::Drawing::Point(165, 218);
			this->txtGirdleThickness->Name = L"txtGirdleThickness";
			this->txtGirdleThickness->Size = System::Drawing::Size(85, 20);
			this->txtGirdleThickness->TabIndex = 32;
			this->txtGirdleThickness->Text = L"0%";
			this->txtGirdleThickness->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGlobAdjust
			// 
			this->txtGlobAdjust->Location = System::Drawing::Point(40, 191);
			this->txtGlobAdjust->Name = L"txtGlobAdjust";
			this->txtGlobAdjust->ReadOnly = true;
			this->txtGlobAdjust->Size = System::Drawing::Size(85, 20);
			this->txtGlobAdjust->TabIndex = 30;
			this->txtGlobAdjust->Text = L"0%";
			this->txtGlobAdjust->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// tbPavilionBulge
			// 
			this->tbPavilionBulge->LargeChange = 1;
			this->tbPavilionBulge->Location = System::Drawing::Point(263, 182);
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
			this->tbGirdleThickness->LargeChange = 1;
			this->tbGirdleThickness->Location = System::Drawing::Point(156, 182);
			this->tbGirdleThickness->Maximum = 20;
			this->tbGirdleThickness->MaximumSize = System::Drawing::Size(104, 30);
			this->tbGirdleThickness->Minimum = -5;
			this->tbGirdleThickness->MinimumSize = System::Drawing::Size(104, 30);
			this->tbGirdleThickness->Name = L"tbGirdleThickness";
			this->tbGirdleThickness->Size = System::Drawing::Size(104, 45);
			this->tbGirdleThickness->TabIndex = 28;
			this->tbGirdleThickness->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbGirdleThickness->Scroll += gcnew System::EventHandler(this, &Form1::tbGirdleThickness_Scroll);
			// 
			// lblPavilionBulge
			// 
			this->lblPavilionBulge->AutoSize = true;
			this->lblPavilionBulge->Location = System::Drawing::Point(281, 165);
			this->lblPavilionBulge->Name = L"lblPavilionBulge";
			this->lblPavilionBulge->Size = System::Drawing::Size(74, 13);
			this->lblPavilionBulge->TabIndex = 24;
			this->lblPavilionBulge->Text = L"Pavilion Bulge";
			// 
			// lblGirdleThickness
			// 
			this->lblGirdleThickness->AutoSize = true;
			this->lblGirdleThickness->Location = System::Drawing::Point(165, 165);
			this->lblGirdleThickness->Name = L"lblGirdleThickness";
			this->lblGirdleThickness->Size = System::Drawing::Size(86, 13);
			this->lblGirdleThickness->TabIndex = 23;
			this->lblGirdleThickness->Text = L"Girdle Thickness";
			// 
			// lblGlobAdj
			// 
			this->lblGlobAdj->AutoSize = true;
			this->lblGlobAdj->Location = System::Drawing::Point(37, 165);
			this->lblGlobAdj->Name = L"lblGlobAdj";
			this->lblGlobAdj->Size = System::Drawing::Size(75, 13);
			this->lblGlobAdj->TabIndex = 21;
			this->lblGlobAdj->Text = L"Global Adj. (%)";
			// 
			// lblDia2
			// 
			this->lblDia2->AutoSize = true;
			this->lblDia2->Location = System::Drawing::Point(223, 14);
			this->lblDia2->Name = L"lblDia2";
			this->lblDia2->Size = System::Drawing::Size(58, 13);
			this->lblDia2->TabIndex = 18;
			this->lblDia2->Text = L"Diameter-2";
			// 
			// lblDia1
			// 
			this->lblDia1->AutoSize = true;
			this->lblDia1->Location = System::Drawing::Point(63, 12);
			this->lblDia1->Name = L"lblDia1";
			this->lblDia1->Size = System::Drawing::Size(58, 13);
			this->lblDia1->TabIndex = 17;
			this->lblDia1->Text = L"Diameter-1";
			// 
			// lblRecut
			// 
			this->lblRecut->AutoSize = true;
			this->lblRecut->Location = System::Drawing::Point(430, 16);
			this->lblRecut->Name = L"lblRecut";
			this->lblRecut->Size = System::Drawing::Size(36, 13);
			this->lblRecut->TabIndex = 50;
			this->lblRecut->Text = L"Recut";
			// 
			// picRecut
			// 
			this->picRecut->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picRecut->Location = System::Drawing::Point(325, 14);
			this->picRecut->Name = L"picRecut";
			this->picRecut->Size = System::Drawing::Size(82, 64);
			this->picRecut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picRecut->TabIndex = 47;
			this->picRecut->TabStop = false;
			// 
			// cbRecut
			// 
			this->cbRecut->AutoSize = true;
			this->cbRecut->Location = System::Drawing::Point(300, 84);
			this->cbRecut->Name = L"cbRecut";
			this->cbRecut->Size = System::Drawing::Size(189, 17);
			this->cbRecut->TabIndex = 12;
			this->cbRecut->Text = L"Estimate Recut : Round Diamonds";
			this->cbRecut->UseVisualStyleBackColor = true;
			this->cbRecut->CheckedChanged += gcnew System::EventHandler(this, &Form1::cbRecut_CheckedChanged);
			// 
			// cbInterpolate
			// 
			this->cbInterpolate->AutoSize = true;
			this->cbInterpolate->Enabled = false;
			this->cbInterpolate->Location = System::Drawing::Point(300, 107);
			this->cbInterpolate->Name = L"cbInterpolate";
			this->cbInterpolate->Size = System::Drawing::Size(173, 17);
			this->cbInterpolate->TabIndex = 11;
			this->cbInterpolate->Text = L"Interpolate Fancy Cut Formula\?";
			this->cbInterpolate->UseVisualStyleBackColor = true;
			this->cbInterpolate->Visible = false;
			this->cbInterpolate->CheckedChanged += gcnew System::EventHandler(this, &Form1::cbInterpolate_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox2->Controls->Add(this->txtEstRecut);
			this->groupBox2->Controls->Add(this->numSG);
			this->groupBox2->Controls->Add(this->lblRecut);
			this->groupBox2->Controls->Add(this->picGem);
			this->groupBox2->Controls->Add(this->picRecut);
			this->groupBox2->Controls->Add(this->picCut);
			this->groupBox2->Controls->Add(this->lblSgValue);
			this->groupBox2->Controls->Add(this->lblCutFactor);
			this->groupBox2->Controls->Add(this->txtFactor);
			this->groupBox2->Controls->Add(this->lblSelectedCut);
			this->groupBox2->Controls->Add(this->comboCut);
			this->groupBox2->Controls->Add(this->comboGems);
			this->groupBox2->Controls->Add(this->lbllSelectedSG);
			this->groupBox2->Controls->Add(this->cbInterpolate);
			this->groupBox2->Controls->Add(this->cbRecut);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(12, 499);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(505, 159);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			// 
			// txtEstRecut
			// 
			this->txtEstRecut->Location = System::Drawing::Point(412, 57);
			this->txtEstRecut->Name = L"txtEstRecut";
			this->txtEstRecut->ReadOnly = true;
			this->txtEstRecut->Size = System::Drawing::Size(85, 20);
			this->txtEstRecut->TabIndex = 56;
			this->txtEstRecut->Text = L"0.00 ct";
			this->txtEstRecut->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// numSG
			// 
			this->numSG->DecimalPlaces = 2;
			this->numSG->Enabled = false;
			this->numSG->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numSG->Location = System::Drawing::Point(90, 58);
			this->numSG->Name = L"numSG";
			this->numSG->Size = System::Drawing::Size(100, 20);
			this->numSG->TabIndex = 24;
			// 
			// picGem
			// 
			this->picGem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picGem->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picGem->Location = System::Drawing::Point(226, 14);
			this->picGem->Name = L"picGem";
			this->picGem->Size = System::Drawing::Size(64, 64);
			this->picGem->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picGem->TabIndex = 21;
			this->picGem->TabStop = false;
			// 
			// picCut
			// 
			this->picCut->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picCut->Location = System::Drawing::Point(226, 84);
			this->picCut->Name = L"picCut";
			this->picCut->Size = System::Drawing::Size(64, 67);
			this->picCut->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picCut->TabIndex = 20;
			this->picCut->TabStop = false;
			// 
			// lblSgValue
			// 
			this->lblSgValue->AutoSize = true;
			this->lblSgValue->Location = System::Drawing::Point(48, 60);
			this->lblSgValue->Name = L"lblSgValue";
			this->lblSgValue->Size = System::Drawing::Size(28, 13);
			this->lblSgValue->TabIndex = 19;
			this->lblSgValue->Text = L"S.G.";
			// 
			// lblCutFactor
			// 
			this->lblCutFactor->AutoSize = true;
			this->lblCutFactor->Location = System::Drawing::Point(20, 120);
			this->lblCutFactor->Name = L"lblCutFactor";
			this->lblCutFactor->Size = System::Drawing::Size(56, 13);
			this->lblCutFactor->TabIndex = 18;
			this->lblCutFactor->Text = L"Cut Factor";
			// 
			// txtFactor
			// 
			this->txtFactor->Location = System::Drawing::Point(90, 117);
			this->txtFactor->Name = L"txtFactor";
			this->txtFactor->Size = System::Drawing::Size(100, 20);
			this->txtFactor->TabIndex = 17;
			this->txtFactor->Text = L"0.0061";
			this->txtFactor->TextChanged += gcnew System::EventHandler(this, &Form1::txtFactor_TextChanged);
			this->txtFactor->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::txtFactor_KeyPress);
			// 
			// lblSelectedCut
			// 
			this->lblSelectedCut->AutoSize = true;
			this->lblSelectedCut->Location = System::Drawing::Point(53, 94);
			this->lblSelectedCut->Name = L"lblSelectedCut";
			this->lblSelectedCut->Size = System::Drawing::Size(23, 13);
			this->lblSelectedCut->TabIndex = 16;
			this->lblSelectedCut->Text = L"Cut";
			// 
			// comboCut
			// 
			this->comboCut->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(187) {
				L"agate", L"albite", L"alexandrite",
					L"almandine", L"amazonite", L"amber", L"ammolite", L"amethyst", L"andalusite", L"apatite", L"aquamarine", L"aragonite", L"aventurine quartz",
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
			this->comboCut->Location = System::Drawing::Point(90, 90);
			this->comboCut->Name = L"comboCut";
			this->comboCut->Size = System::Drawing::Size(121, 21);
			this->comboCut->TabIndex = 15;
			this->comboCut->Text = L"round brilliant";
			this->comboCut->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboCut_SelectedIndexChanged);
			// 
			// radioBtnGem
			// 
			this->radioBtnGem->AutoSize = true;
			this->radioBtnGem->Location = System::Drawing::Point(327, 8);
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
			this->radioBtnDia->Location = System::Drawing::Point(105, 8);
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
			this->statusbar->Location = System::Drawing::Point(0, 661);
			this->statusbar->Name = L"statusbar";
			this->statusbar->Size = System::Drawing::Size(529, 22);
			this->statusbar->SizingGrip = false;
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
			this->fileToolStripMenuItem->Text = L"&File";
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
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->preferencesToolStripMenuItem });
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->preferencesToolStripMenuItem->Text = L"&Preferences";
			this->preferencesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::preferencesToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->logToolStripMenuItem });
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem->Text = L"&View";
			// 
			// logToolStripMenuItem
			// 
			this->logToolStripMenuItem->Name = L"logToolStripMenuItem";
			this->logToolStripMenuItem->Size = System::Drawing::Size(91, 22);
			this->logToolStripMenuItem->Text = L"&log";
			this->logToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::logToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->helpToolStripMenuItem1,
					this->aboutToolStripMenuItem1
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem1
			// 
			this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
			this->helpToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->helpToolStripMenuItem1->Text = L"Help";
			this->helpToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem1_Click);
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem1->Text = L"About";
			this->aboutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem1_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// groupBoxCalculate
			// 
			this->groupBoxCalculate->BackColor = System::Drawing::SystemColors::Info;
			this->groupBoxCalculate->Controls->Add(this->lblWeightInCarats);
			this->groupBoxCalculate->Controls->Add(this->txtResult);
			this->groupBoxCalculate->Controls->Add(this->buttonCalc);
			this->groupBoxCalculate->Controls->Add(this->buttonClear);
			this->groupBoxCalculate->Location = System::Drawing::Point(12, 385);
			this->groupBoxCalculate->Name = L"groupBoxCalculate";
			this->groupBoxCalculate->Size = System::Drawing::Size(505, 71);
			this->groupBoxCalculate->TabIndex = 16;
			this->groupBoxCalculate->TabStop = false;
			// 
			// lblWeightInCarats
			// 
			this->lblWeightInCarats->AutoSize = true;
			this->lblWeightInCarats->Location = System::Drawing::Point(39, 30);
			this->lblWeightInCarats->Name = L"lblWeightInCarats";
			this->lblWeightInCarats->Size = System::Drawing::Size(87, 13);
			this->lblWeightInCarats->TabIndex = 53;
			this->lblWeightInCarats->Text = L"Weight in carats.";
			// 
			// groupBoxChooseDiaOrGem
			// 
			this->groupBoxChooseDiaOrGem->Controls->Add(this->radioBtnGem);
			this->groupBoxChooseDiaOrGem->Controls->Add(this->radioBtnDia);
			this->groupBoxChooseDiaOrGem->Location = System::Drawing::Point(12, 462);
			this->groupBoxChooseDiaOrGem->Name = L"groupBoxChooseDiaOrGem";
			this->groupBoxChooseDiaOrGem->Size = System::Drawing::Size(505, 31);
			this->groupBoxChooseDiaOrGem->TabIndex = 17;
			this->groupBoxChooseDiaOrGem->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 683);
			this->Controls->Add(this->groupBoxChooseDiaOrGem);
			this->Controls->Add(this->groupBoxCalculate);
			this->Controls->Add(this->statusbar);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->lwguide);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Gemwest";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load_1);
			this->lwguide->ResumeLayout(false);
			this->lwguide->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numTaperedBaguetteMaxWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picShapeOutline))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGirdle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBulge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLW))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDepth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDepth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictAdjArrow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbShapeOutline))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDia2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDia1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbPavilionBulge))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbGirdleThickness))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picRecut))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGem))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCut))->EndInit();
			this->statusbar->ResumeLayout(false);
			this->statusbar->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxCalculate->ResumeLayout(false);
			this->groupBoxCalculate->PerformLayout();
			this->groupBoxChooseDiaOrGem->ResumeLayout(false);
			this->groupBoxChooseDiaOrGem->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		OptionsForm myPreferences; // declare Object pointing to Options Form

		BridgeCS^ loadData = gcnew BridgeCS;
		String^ getDecPlacesFromConfig = loadData->propBridge1000;
		String^ getLogAllFromConfig = loadData->propBridgeLog;

	private: System::Void btnEq_Click(System::Object^ sender, System::EventArgs^ e) {

		this->numDia2->Text = this->numDia1->Text;
	}
		   /*************************************************************************************/
	private: System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
		this->calculate_carat_weight();

	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e) {

		this->txtResult->Text = ""; // clear all textBox
		this->numDia1->Text = "0.00";
		this->numDia2->Text = "0.00";
		this->numDepth->Text = "0.00";
		this->toolStrip->Text = L"Ready..."; // clear all textBox
		this->tbGirdleThickness->Value = 0;
		this->tbPavilionBulge->Value = 0;
		this->tbGirdleThickness->Value = 0;
		this->tbShapeOutline->Value = 0;
		this->txtGlobAdjust->Text = L"0%";
		this->txtPavilionBulge->Text = L"0%";
		this->txtGirdleThickness->Text = L"0%";
		this->txtShapeOutline->Text = L"0%";
	}
	private: System::Void txtResult_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboGems_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SpecificGravity^ sg = gcnew SpecificGravity; // Declare object
		sg->dictInitializer();
		/**************************IMAGE MANAGEMENT FOR GEMSTONES**************************/
		CEmbeddedImage^ gemImage = gcnew CEmbeddedImage;
		if (sg->prop_sg->ContainsKey(this->comboGems->Text)) {
			gemImage->setName(this->comboGems->Text);
			this->picGem->Image = gemImage->getName();
			this->numSG->Text = sg->prop_sg[this->comboGems->Text];
		} //stop crash if key doesn't exist
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
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
		this->cbRecut->Enabled = false;
		/*reset tapered baguette settings*/
		this->numTaperedBaguetteMaxWidth->Hide();
		this->lblMaxWidth->Hide();
		this->numDia2->Width = this->numDia1->Width;
		this->lblDia2->Text = L"Diameter-2";
		this->lblDia2->Location = Point(223, 14);
		this->numDia2->Location = Point(205, 30);
		if (fancyCutSelected(this->comboCut->Text)) {
			this->cbInterpolate->Enabled = true;
		}
		else {
			this->cbInterpolate->Enabled = false;

		}
		if (CCutDim::isRoundish(this->comboCut->Text)) {
			this->cbRecut->Enabled = true;

			this->lblDia1->Text = "Diameter-1";
			this->lblDia2->Text = "Diameter-2";
		}
		else {
			this->lblDia1->Text = "Length";
			this->lblDia2->Text = "Width";
		}
		if (this->radioBtnGem->Checked) {
			CGemCut^ gc = gcnew CGemCut; // Declare object
			gc->dictInitializer();
			String^ myGemCut = gc->getCut(this->comboCut->Text); // dc->_diaCut[this->comboCut->Text];
			this->txtFactor->Text = myGemCut;

			CEmbeddedImage^ gCutImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			gCutImage->setName(this->comboCut->Text);
			this->picCut->Image = gCutImage->getName();
		}
		else if (this->radioBtnDia->Checked) {
			CDiamondCut^ dc = gcnew CDiamondCut; // Declare object
			dc->dictInitializer();
			String^ myDiamondCut = dc->getCut(this->comboCut->Text); // dc->_diaCut[this->comboCut->Text];

			this->txtFactor->Text = myDiamondCut;
		}


		if (this->comboCut->Text->Equals(TAPBAG)) {
			/*change labels and make min width/max width appear*/
			this->numTaperedBaguetteMaxWidth->Show();
			this->lblMaxWidth->Show();
			this->numDia2->Width = this->numTaperedBaguetteMaxWidth->Width;
			this->lblDia2->Location = Point(223, 14);
			this->numDia2->Location = Point(223, 30);

			this->lblDia2->Text = L"Min Width";
		}
		CEmbeddedImage^ dCutImage = gcnew CEmbeddedImage;
		/**************************IMAGE MANAGEMENT**************************/
		dCutImage->setName(this->comboCut->Text);
		this->picCut->Image = dCutImage->getName();

		onScreenInfo(); // should trigger correct cut formulae for fancy cuts.
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutForm1^ aform = gcnew AboutForm1;
		aform->Show();
	}
	private: System::Void txtFactor_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

		{
			// Only allow 1 decimal point
			if (e->KeyChar == '.')
			{
				if (this->txtFactor->Text->Contains(".") && !this->txtFactor->SelectedText->Contains("."))
					e->Handled = true;
			}
			// Accept only digits "." and the Backspace character
			else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
				e->Handled = true;
		}
		
	}
	private: System::Void radioBtnDia_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

		this->txtFactor->Clear();
		this->comboCut->ResetText();
		this->comboCut->SelectedText = "choose from below";
		this->comboGems->ResetText();
		this->comboGems->SelectedText = "choose from below";
		this->numSG->Text = "3.52";
		this->comboGems->Enabled = false;
		this->numSG->Enabled = false;
		array<String^>^ dias = gcnew array<String^>{};
		CDiamondCut^ dc = gcnew CDiamondCut; // Declare object
		if (dc != nullptr) {
			dc->dictInitializer();
			dias = dc->getCutNames();
			Form1::comboCut->Items->Clear();
			Form1::comboCut->Items->AddRange(dias);
		} // != null

		CEmbeddedImage^ defaultRBC = gcnew CEmbeddedImage;
		/**************************IMAGE MANAGEMENT**************************/
		defaultRBC->setName("round brilliant");
		this->picCut->Image = defaultRBC->getName();
	}
	private: System::Void radioBtnGem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->txtFactor->Clear();
		this->comboCut->ResetText();
		this->comboCut->SelectedText = "choose from below";

		this->comboGems->ResetText();
		this->comboGems->SelectedText = "choose from below";
		this->numSG->Text = "0.00";
		this->comboGems->Enabled = true;
		this->numSG->Enabled = true;
		array<String^>^ gems = gcnew array<String^>{};
		CGemCut^ gc = gcnew CGemCut; // Declare object
		if (gc != nullptr) {
			gc->dictInitializer();
			gems = gc->getCutNames();
			Form1::comboCut->Items->Clear();
			Form1::comboCut->Items->AddRange(gems);

		} // != null
		CEmbeddedImage^ defaultGemCut = gcnew CEmbeddedImage;
		/**************************IMAGE MANAGEMENT**************************/
		defaultGemCut->setName("oval cut");
		this->picCut->Image = defaultGemCut->getName();
	}

	private: System::Void tbShapeOutline_Scroll(System::Object^ sender, System::EventArgs^ e) {

		combine_adjustments();
		this->txtShapeOutline->Text = this->tbShapeOutline->Value.ToString() + "%";
		repaint_shape_outline();
		this->onScreenInfo();
	}

	private: System::Void tbGirdleThickness_Scroll(System::Object^ sender, System::EventArgs^ e) {
		combine_adjustments();
		this->txtGirdleThickness->Text = this->tbGirdleThickness->Value.ToString() + "%";
		repaint_girdle_thickness();
		this->onScreenInfo();
	}
	private: System::Void tbPavilionBulge_Scroll(System::Object^ sender, System::EventArgs^ e) {
		combine_adjustments();
		this->txtPavilionBulge->Text = this->tbPavilionBulge->Value.ToString() + "%";
		repaint_pavilion_bulge();
		this->onScreenInfo(); // print depth percentage and L/W Ratio

	}
	private: System::Void txtFactor_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	
	}
	private: System::Void numDia2_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo(); // print depth percentage and L/W Ratio
	}
	private: System::Void numDia1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo(); // print depth percentage and L/W Ratio

	}
	private: System::Void numDepth_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo(); // print depth percentage and L/W Ratio
	}
	private: System::Void radDepthAsMm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->lblDepth->Text = "Depth (mm)";

		if (myPreferences.propLogAll) {
			// = "true";
		}
		if (myPreferences.prop1000 == true) {

			this->numDia1->DecimalPlaces = 3;
			this->numDia1->Increment = System::Decimal(0.001);

			this->numDia2->DecimalPlaces = 3;
			this->numDia2->Increment = System::Decimal(0.001);

			this->numDepth->DecimalPlaces = 3;
			this->numDepth->Increment = System::Decimal(0.001);
			//decplaces = "3";
		}
		else {
			this->numDia1->DecimalPlaces = 2;
			this->numDia1->Increment = System::Decimal(0.01);

			this->numDia2->DecimalPlaces = 2;
			this->numDia2->Increment = System::Decimal(0.01);

			this->numDepth->DecimalPlaces = 2;
			this->numDepth->Increment = System::Decimal(0.01);
			//decplaces = "2";
		}
	}
	private: System::Void radDepthAsPerc_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		/*Use Percentage (%) as Depth data entry*/
		this->lblDepth->Text = "Depth (%)";
		this->numDepth->DecimalPlaces = 1;
		this->numDepth->Increment = System::Decimal(0.1);
		Boolean isRoundish = true;

		Double  lengthInMm = System::Convert::ToDouble(this->numDia1->Text);
		Double  widthInMm = System::Convert::ToDouble(this->numDia2->Text);

		Double reverseMm2Perc;
		Double reversePercentage2mm;

		if (CCutDim::isRoundish(this->comboCut->Text)) {

			widthInMm = (lengthInMm + widthInMm) / 2;

		}
		if (this->radDepthAsPerc->Checked) {
			reverseMm2Perc = Math::Round((System::Convert::ToDouble(this->numDepth->Text) / widthInMm) * 100, 2);
			this->numDepth->Text = System::Convert::ToString(reverseMm2Perc);
		}
		else
		{

			reversePercentage2mm = CDcalc::depthConvertFromPercent(widthInMm, System::Convert::ToDouble(this->numDepth->Text) / 100, true);
			this->numDepth->Text = System::Convert::ToString(reversePercentage2mm);
		}
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void preferencesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		myPreferences.ShowDialog();
		String^ decplaces = "2";
		String^ logAllcalculations = "false";
		if (myPreferences.propLogAll) {
			logAllcalculations = "true";
		}
		if (myPreferences.prop1000 == true) {

			this->numDia1->DecimalPlaces = 3;
			this->numDia1->Increment = System::Decimal(0.001);

			this->numDia2->DecimalPlaces = 3;
			this->numDia2->Increment = System::Decimal(0.001);

			this->numDepth->DecimalPlaces = 3;
			this->numDepth->Increment = System::Decimal(0.001);
			decplaces = "3";
		}
		else {
			this->numDia1->DecimalPlaces = 2;
			this->numDia1->Increment = System::Decimal(0.01);

			this->numDia2->DecimalPlaces = 2;
			this->numDia2->Increment = System::Decimal(0.01);

			this->numDepth->DecimalPlaces = 2;
			this->numDepth->Increment = System::Decimal(0.01);
			decplaces = "2";
		}

		BridgeCS^ settingsSave = gcnew BridgeCS;
		settingsSave->propBridge1000 = decplaces;
		settingsSave->propBridgeLog = logAllcalculations;

		/*This is old code for C++ but it only saves to Application Folder
		String^ decPlaces = ConfigurationSettings::AppSettings["decPlaces"];
		String^ log = ConfigurationSettings::AppSettings["log"];
		Console::WriteLine("{0} - {1}", firstName, name);

		System::Configuration::Configuration^ config = ConfigurationManager::OpenExeConfiguration(ConfigurationUserLevel::None);
		config->AppSettings->Settings->Remove("decPlaces");
		config->AppSettings->Settings->Remove("logAll");

		config->AppSettings->Settings->Add("decPlaces",decplaces);
		config->AppSettings->Settings->Add("logAll", logAllcalculations);
		config->Save(ConfigurationSaveMode::Modified);
		ConfigurationManager::RefreshSection("appSettings");*/

	}
	private: System::Void helpToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {

		HelpForm^ hform = gcnew HelpForm;
		hform->Visible = true;
	}
	private: System::Void aboutToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		AboutForm1^ aform = gcnew AboutForm1;
		aform->Show();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void logToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		LogForm^ lform = gcnew LogForm;
		lform->Visible = true;
	}
	private: System::Void lblHiddenDepth_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		//this->Invalidate();   request a delayed Repaint by the normal MessageLoop system    
		//this->Update();      forces Repaint of invalidated area 
		//this->Refresh();    // Combines Invalidate() and Update(
		this->draw_depth(this->lblHiddenDepth->Text);

	}

	private: System::Void Form1_Load_1(System::Object^ sender, System::EventArgs^ e) {
		/****************LOAD CONFIG FILES***************************/

		CEmbeddedImage^ rc = gcnew CEmbeddedImage;
		rc->setName("recut");
		this->picRecut->Image = rc->getName();

		//CEmbeddedImage^ dp = gcnew CEmbeddedImage;
		//dp->setName("defrec");
		//this->picDepth->Image = dp->getName();

		CEmbeddedImage^ adjarrow = gcnew CEmbeddedImage;
		adjarrow->setName("adjustmentarrow");
		this->pictAdjArrow->Image = adjarrow->getName();

		CEmbeddedImage^ defaultCut = gcnew CEmbeddedImage;
		defaultCut->setName("round brilliant");
		this->picCut->Image = defaultCut->getName();

		CEmbeddedImage^ defaultBulge = gcnew CEmbeddedImage;
		defaultBulge->setName("bulge_non");
		this->picBulge->Image = defaultBulge->getName();

		CEmbeddedImage^ defaultShapeOutline = gcnew CEmbeddedImage;
		defaultShapeOutline->setName("so3");
		this->picShapeOutline->Image = defaultShapeOutline->getName();

		CEmbeddedImage^ defaultGem = gcnew CEmbeddedImage;
		defaultGem->setName("diamond");
		this->picGem->Image = defaultGem->getName();

		CEmbeddedImage^ defaultGirdle = gcnew CEmbeddedImage;
		defaultGirdle->setName("thingirdle");
		this->picGirdle->Image = defaultGirdle->getName();

		/*CEmbeddedImage^ checkDepth = gcnew CEmbeddedImage;
		checkDepth->setName("checkDepth")*/

		Boolean set1000s = false; //   these variables are sent to GUI
		Boolean setLogging = false; //   these variables are sent to GUI
		if (!System::String::IsNullOrEmpty(getDecPlacesFromConfig)) {
			if (getDecPlacesFromConfig->Equals("3")) {
				set1000s = true;
			}
			else {
				set1000s = false;
			}
			myPreferences.prop1000 = set1000s;
		} // not null or empty
		/****************************************************/
		if (!System::String::IsNullOrEmpty(getLogAllFromConfig)) {
			if (getLogAllFromConfig->Equals("true")) {
				setLogging = true;
			}
			else {
				setLogging = false;
			}
			myPreferences.propLogAll = setLogging;
		}//not null or empty
		/****************************************************/

	}

	private: System::Void numTaperedBaguetteMaxWidth_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cbInterpolate_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo();
	}
	private: System::Void cbRecut_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnClearGT_Click(System::Object^ sender, System::EventArgs^ e) {

		this->tbGirdleThickness->Value = 0;
		this->txtGirdleThickness->Text = "0%";
		combine_adjustments();
		repaint_girdle_thickness();
		this->onScreenInfo();
	}
	private: System::Void btnClearPB_Click(System::Object^ sender, System::EventArgs^ e) {

		this->tbPavilionBulge->Value = 0;
		this->txtPavilionBulge->Text = "0%";
		combine_adjustments();
		repaint_pavilion_bulge();
		this->onScreenInfo();
	}
	private: System::Void btnClearSO_Click(System::Object^ sender, System::EventArgs^ e) {

		this->tbShapeOutline->Value = 0;
		this->txtShapeOutline->Text = "0%";
		combine_adjustments();
		repaint_shape_outline();
		this->onScreenInfo();
	}
	};
}
