#pragma once
#include <map>
//#include "pch.h"
#include "BridgeCS.h"
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
#include "CGoval.h"
#include "CBead.h"
#include "LogForm.h"
#include "AboutForm1.h"
#include "HelpForm.h"
#include "OptionsForm.h"
//#ifndef "choose from below"
//#define "choose from below" "choose from below"
//#endif // !"choose from below"


namespace ZaniahSystems {
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
		static String^ recordTime(String^ myFormat) {
			DateTime now = DateTime::Now;
			String^ myTime = now.ToString(myFormat);
			return myTime;
		}
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	protected:
		LogForm^ persistantLogRecord = gcnew LogForm();
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
			/*		L"Thin girdle, 0%.\n"
		"Slightly thick, add 2%.\n"
		"Thick, add 4%.\n"
		"Very thick, 6%.\n"
		"Extra thick, add 9%.";*/
			array<String^>^ girdleDescription = gcnew array<String^>{ "Thin girdle", "Slightly thick", "Thick", "Very thick", "Extra thick"};
			String^ gdes = girdleDescription[0];
			String^ gThk = "thingirdle";
			if (this->tbGirdleThickness->Value < 1) {
				gThk = "thingirdle";
				gdes = girdleDescription[0];
			}
			else if (this->tbGirdleThickness->Value < 3) {
				gThk = "mediumgirdle";
				gdes = girdleDescription[1];
			}
			else if (this->tbGirdleThickness->Value < 5) {
				gThk = "thickgirdle";
				gdes = girdleDescription[2];
			}
			else if (this->tbGirdleThickness->Value < 7) {
				gThk = "sthickgirdle";
				gdes = girdleDescription[3];
			}
			else {
				gThk = "vthickgirdle";
				gdes = girdleDescription[4];
			}
			this->lblDynGT->Text = gdes;
			CEmbeddedImage^ girdleImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			girdleImage->setName(gThk);
			this->picGirdle->Image = girdleImage->getName();

		}
		/***************************************************************************************/
		void repaint_crown_height() {
			array<String^>^ crownDescription = gcnew array<String^>{ "Normal", "low", "high"};

			String^ pcrownimage = "crown_normal";
			String^ crowndes = crownDescription[0];
			if (this->tbCrownHeight->Value < -6) {
				pcrownimage = "crown_low";
				crowndes = crownDescription[1];
			}
			else if (this->tbCrownHeight->Value > 4) {
				pcrownimage = "crown_high";
				crowndes = crownDescription[2];
			}
			else {
				pcrownimage = "crown_normal";
				crowndes = crownDescription[0];
			}
			this->lblDynCR->Text = crowndes;
			CEmbeddedImage^ crownImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			crownImage->setName(pcrownimage);
			this->picCrown->Image = crownImage->getName();

		}
		void repaint_pavilion_bulge() {
			array<String^>^ bulgeDescription = gcnew array<String^>{ "Normal", "Slight", "Noticeable", "Obvious", "Extreme" };

			String^ pBulge = "bulge_normal";
			if (this->tbPavilionBulge->Value < 3) {
				pBulge = "bulge_normal";
				this->lblDynPB->Text = bulgeDescription[0];
			}
			else if (this->tbPavilionBulge->Value < 6) {
				pBulge = "bulge_slight";
				this->lblDynPB->Text = bulgeDescription[1];
			}
			else if (this->tbPavilionBulge->Value < 9) {
				pBulge = "bulge_noticeable";
				this->lblDynPB->Text = bulgeDescription[2];
			}
			else if (this->tbPavilionBulge->Value < 13) {
				pBulge = "bulge_obvious";
				this->lblDynPB->Text = bulgeDescription[3];
			}
			else {
				pBulge = "bulge_extreme";
				this->lblDynPB->Text = bulgeDescription[4];
			}
			CEmbeddedImage^ bulgeImage = gcnew CEmbeddedImage;
			/**************************IMAGE MANAGEMENT**************************/
			bulgeImage->setName(pBulge);
			this->picBulge->Image = bulgeImage->getName();
		}
		/***************************************************************************************/
		void repaint_shape_outline() {
			//this->tbShapeOutline->Enabled = false;
			array<String^>^ shapeDescription = gcnew array<String^>{
					"Normal",
					"Wide Corners",
					"MQ/PE v short keel/none",
					"Straight sides",
					"Wide wings",
					"High Shoulders",
					"Straight Shoulders"
			};
			String^ shapedes = shapeDescription[0];
			String^ so = "so3";
			/*Wide corners on cut corner squares and rectangles can decrease weight as much as 5%.
For oval, pear, marquise, and heart cuts, wide wings or high shoulders can add up to 10%. Occasionally,
straight shoulders will require a deduction of 1% to 5%.
Marquise and (sometimes) pears will have a very short keel or none at all.
This will reduce the weight by 1% to 3%.*/

			this->tbShapeOutline->Minimum = -5;
			this->tbShapeOutline->Maximum = 10;
			String^ currentCut = this->comboCut->Text;

			if (currentCut->Contains("tri")) {// it is a triangle type cut

				//this->tbShapeOutline->Enabled = true;
				/*Triangles with straight sides will require a reduction of up to 10 % .*/
				this->tbShapeOutline->Minimum = -10;
				this->tbShapeOutline->Maximum = 0;
				so = "triangleshape";
				if (this->tbShapeOutline->Value > -4) {
					shapedes = shapeDescription[0];
				}
				else {
					shapedes = shapeDescription[3];
				}

			} //  END TRIANGULAR CUT STONES
			else if (currentCut->Contains("ect")
				|| currentCut->Contains("uare")
				|| currentCut->Contains("rald")
				|| currentCut->Contains("ushio")
				|| currentCut->Contains("rince")
				|| currentCut->Contains("scher")
				|| currentCut->Contains("ario")
				|| currentCut->Contains("flan")
				|| currentCut->Contains("adian")

				) { // it's a non square stone
				/*Wide corners on cut corner squares and rectangles can decrease weight as much as 5%.*/
				//this->tbShapeOutline->Enabled = true;
				this->tbShapeOutline->Minimum = -5;
				this->tbShapeOutline->Maximum = 0;
				so = "rectshape";
				if (this->tbShapeOutline->Value < -1) {

					shapedes = shapeDescription[1];
				}
				else {
					shapedes = shapeDescription[0];
				}

			}
			else if (currentCut->Contains("arqui")
				|| currentCut->Contains("ear")
				|| currentCut->Contains("oval")
				|| currentCut->Contains("ushio")
				) {// all other fancies
			/*For oval, pear, marquise, and heart cuts, wide wings or high shoulders can add up to 10 % .Occasionally,
				straight shoulders will require a deduction of 1 % to 5 % .*/
				this->tbShapeOutline->Minimum = -5;
				this->tbShapeOutline->Maximum = 10;
				if (this->tbShapeOutline->Value < -2) {
					so = "so1";
					shapedes = shapeDescription[6];

				}
				else if (this->tbShapeOutline->Value < 0) {
					so = "so2";
					shapedes = shapeDescription[6];

				}
				else if (this->tbShapeOutline->Value < 1) {
					so = "so3";
					shapedes = shapeDescription[0];

				}
				else if (this->tbShapeOutline->Value < 4) {
					so = "so4";
					shapedes = shapeDescription[4];

				}
				else if (this->tbShapeOutline->Value < 7) {
					so = "so5";
					shapedes = shapeDescription[4];

				}
				else if (this->tbShapeOutline->Value < 10) {
					so = "so6";
					shapedes = shapeDescription[5];

				}
				else {
					so = "so6";
					shapedes = shapeDescription[5];
				}

			}

			this->lblDynSO->Text = shapedes;
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
				this->txtEstRecut->Text = "0.00ct";
				return; // MessageBox::Show(errorMessage);
			}
			else {
/**************************************************************************



						DIAMOND CALCULATION




***************************************************************************/
				if (this->radioBtnDia->Checked) { // Calculate the weight of a diamond
					if (this->comboCut->Text->Equals(TAPBAG)) { // Tapered Baguette
						CTaperedBaguette^ TB = gcnew CTaperedBaguette(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
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
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
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
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
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
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
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
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
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
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked);

						RC->cutimage = L"recut";
						p = RC;

						if (this->cbRecut->Checked) {

							this->picRecut->Image = nullptr;
							this->picRecut->Refresh();
							this->txtEstRecut->Text = RC->recut_weight() + " ct";

							CEmbeddedImage^ rcdyn = gcnew CEmbeddedImage;
							rcdyn->setName(RC->cutimage);
							this->picRecut->Image = rcdyn->getName();
							this->lblRecutDetails->Text = RC->recutinformation;

						}

					}
					else {
					
						CDcalc^ defaultCutFormula = gcnew CDcalc(
							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);
						p = defaultCutFormula;
					}
					// print data to tool tip
					String^ tot = System::Convert::ToString(Decimal::Round(p->term(), Convert::ToInt16(myOptions.propCtPlace))) + "ct";
					this->txtResult->Text = tot;
					if (CCutDim::isRoundish(this->comboCut->Text)) {
						Decimal avd = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
						avd = Decimal::Round((avd), 2);
						this->toolStrip->Text = L"[Diamond:" + this->comboCut->Text + "] Est.=(" + avd + " x " + avd + ") x " + this->numDepth->Text + " x " + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
					}
					else {
						this->toolStrip->Text = L"[Diamond:" + this->comboCut->Text + "] Est.=" + this->numDia1->Text + " x" + this->numDia2->Text + " x" + this->numDepth->Text + " x" + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
						/*Wt=f(10.3,10.0,6.0,Thin-Medium)*/
					}

				} // is Diamond
				/**************************************************************************
				
				
				
										GEMSTONE CALCULATION
				
				
				
				
				***************************************************************************/
				else { // Calculate the weight of a Gemstone

					CGcalc^ p = nullptr;
					String^ errorMessage = L"Invalid Input!!\nPlease select a cut!";

					if (this->comboCut->Text->Contains("choose")) {
						MessageBox::Show(errorMessage);
					}
					if (this->comboCut->Text == RDBEAD || this->comboCut->Text == BRIO) {
						CBead^ BE = gcnew CBead(
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value, //  not used in weight calculation
							this->numSG->Value,
							this->txtFactor->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1)
						);
						p = BE;
					}
					else if (this->comboCut->Text == OVALG) {
						CGoval^ OV = gcnew CGoval(
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Value,
							this->txtFactor->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1)
						);
						p = OV;
					}
					else {
						CGcalc^ GC = gcnew CGcalc(
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Value,
							this->txtFactor->Text,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1)
						);
						p = GC;
					} // end is not round cut
					String^ ct = "ct";
					Decimal momme=Decimal(1);
					
					if (this->comboGems->Text == PEARL) {
						ct = "mo";
						momme = Decimal(MOMME);
					}
						String^ tot = System::Convert::ToString(Decimal::Round(Decimal::Multiply(p->term(),momme), 3)) + ct;
						this->txtResult->Text = tot;

						if (this->comboCut->Text == OVALG) {
							Decimal avd = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
							avd = Decimal::Round((avd), 2);
							this->toolStrip->Text = L"[" + this->comboGems->Text + "::" + this->comboCut->Text + "] Est. = (" + avd + " x " + avd + ") x " + this->numDepth->Text + " x " + this->numSG->Value + " x " + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
						}
						else if (this->comboCut->Text == RDBEAD || this->comboCut->Text == BRIO) {
							Decimal avd = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
							avd = Decimal::Round((avd), 2);
							this->toolStrip->Text = L"[" + this->comboGems->Text + "::" + this->comboCut->Text + "] Est. = (" + avd + " x " + avd + " x " + avd + ") x " + this->numSG->Value + " x " + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
						}
						else {
							this->toolStrip->Text = L"[" + this->comboGems->Text + "::" + this->comboCut->Text + "] Est.=" + this->numDia1->Text + " x" + this->numDia2->Text + " x" + this->numDepth->Text + " x " + this->numSG->Value + " x " + this->txtFactor->Text + this->miSign() + this->txtGlobAdjust->Text + " = " + tot;
							/*Wt=f(10.3,10.0,6.0,Thin-Medium)*/
						}
					
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
			/*Debug::WriteLine("fired by" + this->ActiveControl);*/
			this->cbRecut->Enabled = false;

			if (!this->numDia1->Text->Equals("0.00")) {

				if (!this->numDia2->Text->Equals("0.00")) {
					String^ percString;
					if (this->numDia1->Value == 0 || this->numDia2->Value == 0 || this->numDepth->Value == 0) {
						/*https://social.msdn.microsoft.com/Forums/vstudio/en-US/5ac4c768-2c33-4636-a700-d0b3fafeac68/warning-c4965-implicit-box-of-integer-0-use-nullptr-or-explicit-cast*/

						return;
					}

					/*
					cut hasn't been chosen so we need to determine how to calculate Width
					Should it be just Width or Diameter-1 + Diameter-2/2 ?
					*/


					if (CCutDim::isRoundish(this->comboCut->Text)) {
						this->cbRecut->Enabled = true;
						percString = System::Convert::ToString(Decimal::Round(CCalculator::depth_percentage_as_percent(CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value), this->numDepth->Value), 2));
						this->lblCombinedRoundAverage->Text = "AV:" + System::Convert::ToString(Decimal::Round(CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value), 2));
						this->lblDepthPerc->Text = "Depth = " + percString + "%";
					}
					else {
						percString = System::Convert::ToString(Decimal::Round(CCalculator::depth_percentage_as_percent(this->numDia2->Value, this->numDepth->Value), 2));
						this->lblCombinedRoundAverage->Text = "";
						this->lblDepthPerc->Text = "Depth = " + percString + "%";

					}
					Decimal tmp_lw = Decimal::Round(CCalculator::length_width_ratio(this->numDia1->Value, this->numDia2->Value), 1);
					this->lblLwRatio->Text = "LW Ratio = " + tmp_lw + ":1";
					draw_lw(tmp_lw);
					this->lblHiddenDepth->Text = percString;
					if (fancyCutSelected(this->comboCut->Text)) {

						CDfancy^ fancyFactor = gcnew CDfancy(

							this->comboCut->Text,
							this->txtFactor->Text,
							this->numDia1->Value,
							this->numDia2->Value,
							this->numDepth->Value,
							this->numSG->Value,
							this->txtGlobAdjust->Text->Substring(0, this->txtGlobAdjust->Text->Length - 1), this->txtGirdleThickness->Text,
							this->txtPavilionBulge->Text,
							this->txtShapeOutline->Text,
							this->radioBtnDia->Checked,
							this->cbRecut->Checked,
							this->radDepthAsPerc->Checked
						);

						fancyFactor->length = this->numDia1->Value;
						fancyFactor->width = this->numDia2->Value;
						fancyFactor->fancyType = this->comboCut->Text;
						this->txtFactor->Text = fancyFactor->setFancyRecutFactor();
					}
				} 	// end numDia1 or numDia2 == 0

			}
			Form1::Update();
			this->calculate_carat_weight();
		}
		/***************************************************************************************/
		void save_calculation_to_log() {
			String^ myDate = "";
			if (myOptions.propSaveDate == true && myOptions.propSaveTime == true) {

				myDate = " Date: " + Form1::recordTime("MM/dd/yyyy H:mm:ss");
				MessageBox::Show(myDate);
			}
			else if (myOptions.propSaveDate == true && myOptions.propSaveTime == false) {
				myDate = " Date: " + Form1::recordTime("MM/dd/yyyy");
				MessageBox::Show(myDate);
			}
			else if (myOptions.propSaveDate == false && myOptions.propSaveTime == true) {
				myDate = " Time: " + Form1::recordTime("H:mm:ss");
				MessageBox::Show(myDate);
			}
			else {
				myDate = "";
			}

			if (!this->toolStrip->Text->Equals(TOOLTIP)) {
				//if (persistantLogRecord->richTextLog->) {
				array<String^>^ lines = persistantLogRecord->richTextLog->Lines;
				int count = lines->Length;
				if (count == 0) {
					persistantLogRecord->richTextLog->Text = "";
					//persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + "\n");
					persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + myDate + "\n");
				}
				else {
					//for (int idx = 0; idx < count; ++idx)
					//{
					//	Debug::WriteLine(lines[idx]);
					//	// use lines[idx] as needed...
					//}
					//persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + "\n");
					persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + myDate + "\n");
				}
				BridgeCS^ saveString = gcnew BridgeCS;


				saveString->propBridgeCalc = this->persistantLogRecord->richTextLog->Text;
				//if (persistantLogRecord->richTextLog->Lines[count - 1]// != this->toolStrip->Text + "\n") {


				//}
					//persistantLogRecord->richTextLog->AppendText(L"");
					//persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + "\n");
				//}
				//else
				//{
				//	persistantLogRecord->richTextLog->AppendText(this->toolStrip->Text + "\n");
				//}
			} // text is not initialized
		}
		/***************************************************************************************/
		void combine_adjustments() {

			Double sum;
			sum = this->tbCrownHeight->Value + this->tbGirdleThickness->Value + this->tbPavilionBulge->Value + this->tbShapeOutline->Value + this->tbKeel->Value + this->tbOther->Value;
			this->txtGlobAdjust->Text = System::Convert::ToString(sum) + "%";
		}

		void draw_depth(String^ perc) {

			this->picDepth->Image = nullptr;
			this->picDepth->Refresh();

			Double divider = System::Convert::ToDouble(this->lblHiddenDepth->Text) / 100;
			Double percentage = System::Convert::ToDouble(this->picDepth->Height) * divider;
			Graphics^ gd = picDepth->CreateGraphics();
			Rectangle  r = Rectangle(0, 0, this->picDepth->Width, System::Convert::ToInt32(percentage));
			//Color^ myBlue = gcnew Color;
				//myBlue->FromArgb(51,102,153);
			//SolidBrush^  myBlueBrush=gcnew SolidBrush(Color::myBlue);
			SolidBrush^ blueBrush = gcnew SolidBrush(Color::FromArgb(51, 102, 153));

			if (divider >= 1.00) { gd->FillRectangle(Brushes::Orange, r); }
			//else { gd->FillRectangle(Brushes::CornflowerBlue, r); }
			else { gd->FillRectangle(blueBrush, r); }

			/*DRAWLINE*/
			Pen^ myPen = gcnew Pen(Color::Black);
			myPen->Width = 1;
			gd->DrawLine(myPen, Int16(0), static_cast<Int32>(this->picDepth->Height * 0.6), static_cast<Int32>(this->picDepth->Width), static_cast<Int32>(this->picDepth->Height * 0.6));

			/*https://docs.microsoft.com/ja-jp/dotnet/api/system.drawing.graphics.drawstring?view=dotnet-plat-ext-6.0*/
			/*DRAW TEXT*/
			String^ drawString = "60%";
			// Create font and brush.
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 8);
			SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);

			// Create point for upper-left corner of drawing.
			float x = 2.0F;
			float y = static_cast<Single>((this->picDepth->Height) * 0.6);
			//StringFormat ^drawFormat = gcnew StringFormat();

			gd->DrawString(drawString, drawFont, drawBrush, x, y/*,Stringformat*/);

		}
		/***************************************************************************************/
		void draw_lw(Decimal lwStr) {

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

				//Pen^ myPen = gcnew Pen(Color::RoyalBlue, 2);
				//Pen^ myPen = gcnew Pen(Color::FromArgb(255, 51, 102, 153), 2);
				//Single halfPenWidth = myPen->Width * 0.5f;
				SolidBrush^ blueBrush = gcnew SolidBrush(Color::FromArgb(51, 102, 153));
				Double placeCentre = (this->picLW->Width / 2) - (w / 2);// -halfPenWidth;

				RectangleF  r = RectangleF(System::Convert::ToSingle(placeCentre), System::Convert::ToSingle(6), System::Convert::ToSingle(w), System::Convert::ToSingle(l));

				gl->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
				if (CCutDim::lwSymbolIsRound(this->comboCut->Text)) {
					gl->FillEllipse(blueBrush, r);
				}
				else {
					gl->FillRectangle(blueBrush, r);
				}


			}// if not tapered baguette crashing at line 206

		} // end function draw LW Rectangle
		void draw_lw_ellipse(Decimal lwStr) {

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

				//Pen^ myPen = gcnew Pen(Color::RoyalBlue, 2);
				Pen^ myPen = gcnew Pen(Color::FromArgb(255, 51, 102, 153), 2);
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
	private: System::Windows::Forms::Label^ lblRecutDetails;

	private: System::Windows::Forms::NumericUpDown^ numVisDepth;
	private: System::Windows::Forms::Label^ lblHelp;
	private: System::Windows::Forms::Label^ lblDynSO;
	private: System::Windows::Forms::Label^ lblDynPB;
	private: System::Windows::Forms::Label^ lblDynGT;
	private: System::Windows::Forms::TrackBar^ tbCrownHeight;
	private: System::Windows::Forms::TextBox^ txtCrownHeight;



	private: System::Windows::Forms::Button^ btnClrCR;
	private: System::Windows::Forms::Label^ lblDynCR;
	private: System::Windows::Forms::PictureBox^ picCrown;
	private: System::Windows::Forms::Label^ lblCrownHeight;
	private: System::Windows::Forms::Label^ lblOther;
	private: System::Windows::Forms::Label^ lblKeel;
	private: System::Windows::Forms::TrackBar^ tbOther;

	private: System::Windows::Forms::TrackBar^ tbKeel;
	private: System::Windows::Forms::TextBox^ txtOther;
	private: System::Windows::Forms::TextBox^ txtKeel;
private: System::Windows::Forms::Label^ lblDynKeel;
private: System::Windows::Forms::Button^ btnCopy;
private: System::Windows::Forms::ToolStripMenuItem^ copyToolStripMenuItem;
private: System::Windows::Forms::Button^ btnSaveToLog;






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
			this->lblDynKeel = (gcnew System::Windows::Forms::Label());
			this->txtOther = (gcnew System::Windows::Forms::TextBox());
			this->txtKeel = (gcnew System::Windows::Forms::TextBox());
			this->txtCrownHeight = (gcnew System::Windows::Forms::TextBox());
			this->lblOther = (gcnew System::Windows::Forms::Label());
			this->lblKeel = (gcnew System::Windows::Forms::Label());
			this->tbOther = (gcnew System::Windows::Forms::TrackBar());
			this->tbKeel = (gcnew System::Windows::Forms::TrackBar());
			this->lblCrownHeight = (gcnew System::Windows::Forms::Label());
			this->btnClrCR = (gcnew System::Windows::Forms::Button());
			this->lblDynCR = (gcnew System::Windows::Forms::Label());
			this->picCrown = (gcnew System::Windows::Forms::PictureBox());
			this->lblHelp = (gcnew System::Windows::Forms::Label());
			this->lblDynSO = (gcnew System::Windows::Forms::Label());
			this->lblDynPB = (gcnew System::Windows::Forms::Label());
			this->lblDynGT = (gcnew System::Windows::Forms::Label());
			this->numVisDepth = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->tbCrownHeight = (gcnew System::Windows::Forms::TrackBar());
			this->lblRecut = (gcnew System::Windows::Forms::Label());
			this->picRecut = (gcnew System::Windows::Forms::PictureBox());
			this->cbRecut = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSaveToLog = (gcnew System::Windows::Forms::Button());
			this->btnCopy = (gcnew System::Windows::Forms::Button());
			this->lblRecutDetails = (gcnew System::Windows::Forms::Label());
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
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lwguide->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOther))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbKeel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCrown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVisDepth))->BeginInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbCrownHeight))->BeginInit();
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
			this->comboGems->TabIndex = 5;
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
			this->buttonCalc->Location = System::Drawing::Point(325, 19);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(100, 40);
			this->buttonCalc->TabIndex = 5;
			this->buttonCalc->Text = L"Calculate";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &Form1::buttonCalc_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->BackColor = System::Drawing::SystemColors::Desktop;
			this->buttonClear->ForeColor = System::Drawing::SystemColors::Window;
			this->buttonClear->Location = System::Drawing::Point(437, 25);
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
			this->txtResult->Location = System::Drawing::Point(154, 19);
			this->txtResult->MaxLength = 20;
			this->txtResult->MinimumSize = System::Drawing::Size(100, 40);
			this->txtResult->Name = L"txtResult";
			this->txtResult->ReadOnly = true;
			this->txtResult->Size = System::Drawing::Size(149, 40);
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
			this->lwguide->Controls->Add(this->lblDynKeel);
			this->lwguide->Controls->Add(this->txtOther);
			this->lwguide->Controls->Add(this->txtKeel);
			this->lwguide->Controls->Add(this->txtCrownHeight);
			this->lwguide->Controls->Add(this->lblOther);
			this->lwguide->Controls->Add(this->lblKeel);
			this->lwguide->Controls->Add(this->tbOther);
			this->lwguide->Controls->Add(this->tbKeel);
			this->lwguide->Controls->Add(this->lblCrownHeight);
			this->lwguide->Controls->Add(this->btnClrCR);
			this->lwguide->Controls->Add(this->lblDynCR);
			this->lwguide->Controls->Add(this->picCrown);
			this->lwguide->Controls->Add(this->lblHelp);
			this->lwguide->Controls->Add(this->lblDynSO);
			this->lwguide->Controls->Add(this->lblDynPB);
			this->lwguide->Controls->Add(this->lblDynGT);
			this->lwguide->Controls->Add(this->numVisDepth);
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
			this->lwguide->Controls->Add(this->tbCrownHeight);
			this->lwguide->Location = System::Drawing::Point(13, 27);
			this->lwguide->Name = L"lwguide";
			this->lwguide->Size = System::Drawing::Size(505, 364);
			this->lwguide->TabIndex = 12;
			this->lwguide->TabStop = false;
			this->lwguide->Enter += gcnew System::EventHandler(this, &Form1::lwguide_Enter);
			// 
			// lblDynKeel
			// 
			this->lblDynKeel->AutoSize = true;
			this->lblDynKeel->Location = System::Drawing::Point(7, 348);
			this->lblDynKeel->Name = L"lblDynKeel";
			this->lblDynKeel->Size = System::Drawing::Size(38, 13);
			this->lblDynKeel->TabIndex = 76;
			this->lblDynKeel->Text = L"normal";
			// 
			// txtOther
			// 
			this->txtOther->Location = System::Drawing::Point(65, 310);
			this->txtOther->Name = L"txtOther";
			this->txtOther->Size = System::Drawing::Size(30, 20);
			this->txtOther->TabIndex = 75;
			this->txtOther->Text = L"0%";
			this->txtOther->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtKeel
			// 
			this->txtKeel->Location = System::Drawing::Point(66, 272);
			this->txtKeel->Name = L"txtKeel";
			this->txtKeel->Size = System::Drawing::Size(30, 20);
			this->txtKeel->TabIndex = 74;
			this->txtKeel->Text = L"0%";
			this->txtKeel->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtCrownHeight
			// 
			this->txtCrownHeight->Location = System::Drawing::Point(101, 218);
			this->txtCrownHeight->Name = L"txtCrownHeight";
			this->txtCrownHeight->Size = System::Drawing::Size(85, 20);
			this->txtCrownHeight->TabIndex = 67;
			this->txtCrownHeight->Text = L"0%";
			this->txtCrownHeight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblOther
			// 
			this->lblOther->AutoSize = true;
			this->lblOther->Location = System::Drawing::Point(19, 294);
			this->lblOther->Name = L"lblOther";
			this->lblOther->Size = System::Drawing::Size(31, 13);
			this->lblOther->TabIndex = 73;
			this->lblOther->Text = L"other";
			// 
			// lblKeel
			// 
			this->lblKeel->AutoSize = true;
			this->lblKeel->Location = System::Drawing::Point(19, 249);
			this->lblKeel->Name = L"lblKeel";
			this->lblKeel->Size = System::Drawing::Size(57, 13);
			this->lblKeel->TabIndex = 72;
			this->lblKeel->Text = L"Keel/Culet";
			// 
			// tbOther
			// 
			this->tbOther->LargeChange = 1;
			this->tbOther->Location = System::Drawing::Point(0, 310);
			this->tbOther->Maximum = 20;
			this->tbOther->MaximumSize = System::Drawing::Size(60, 30);
			this->tbOther->Minimum = -5;
			this->tbOther->MinimumSize = System::Drawing::Size(60, 30);
			this->tbOther->Name = L"tbOther";
			this->tbOther->Size = System::Drawing::Size(60, 45);
			this->tbOther->TabIndex = 71;
			this->tbOther->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbOther->Scroll += gcnew System::EventHandler(this, &Form1::tbOther_Scroll);
			// 
			// tbKeel
			// 
			this->tbKeel->LargeChange = 1;
			this->tbKeel->Location = System::Drawing::Point(0, 265);
			this->tbKeel->MaximumSize = System::Drawing::Size(60, 30);
			this->tbKeel->Minimum = -10;
			this->tbKeel->MinimumSize = System::Drawing::Size(60, 30);
			this->tbKeel->Name = L"tbKeel";
			this->tbKeel->Size = System::Drawing::Size(60, 45);
			this->tbKeel->TabIndex = 70;
			this->tbKeel->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbKeel->Scroll += gcnew System::EventHandler(this, &Form1::tbKeel_Scroll);
			// 
			// lblCrownHeight
			// 
			this->lblCrownHeight->AutoSize = true;
			this->lblCrownHeight->Location = System::Drawing::Point(115, 165);
			this->lblCrownHeight->Name = L"lblCrownHeight";
			this->lblCrownHeight->Size = System::Drawing::Size(71, 13);
			this->lblCrownHeight->TabIndex = 69;
			this->lblCrownHeight->Text = L"Crown Height";
			// 
			// btnClrCR
			// 
			this->btnClrCR->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnClrCR->ForeColor = System::Drawing::SystemColors::Window;
			this->btnClrCR->Location = System::Drawing::Point(125, 244);
			this->btnClrCR->Name = L"btnClrCR";
			this->btnClrCR->Size = System::Drawing::Size(47, 23);
			this->btnClrCR->TabIndex = 66;
			this->btnClrCR->Text = L"X";
			this->btnClrCR->UseVisualStyleBackColor = false;
			// 
			// lblDynCR
			// 
			this->lblDynCR->AutoSize = true;
			this->lblDynCR->Location = System::Drawing::Point(131, 342);
			this->lblDynCR->Name = L"lblDynCR";
			this->lblDynCR->Size = System::Drawing::Size(40, 13);
			this->lblDynCR->TabIndex = 65;
			this->lblDynCR->Text = L"Normal";
			this->lblDynCR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// picCrown
			// 
			this->picCrown->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picCrown->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picCrown->Location = System::Drawing::Point(101, 273);
			this->picCrown->Name = L"picCrown";
			this->picCrown->Size = System::Drawing::Size(85, 67);
			this->picCrown->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picCrown->TabIndex = 64;
			this->picCrown->TabStop = false;
			// 
			// lblHelp
			// 
			this->lblHelp->AutoSize = true;
			this->lblHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHelp->Location = System::Drawing::Point(6, 123);
			this->lblHelp->Name = L"lblHelp";
			this->lblHelp->Size = System::Drawing::Size(0, 12);
			this->lblHelp->TabIndex = 63;
			// 
			// lblDynSO
			// 
			this->lblDynSO->AutoSize = true;
			this->lblDynSO->Location = System::Drawing::Point(407, 343);
			this->lblDynSO->Name = L"lblDynSO";
			this->lblDynSO->Size = System::Drawing::Size(40, 13);
			this->lblDynSO->TabIndex = 62;
			this->lblDynSO->Text = L"Normal";
			this->lblDynSO->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblDynPB
			// 
			this->lblDynPB->AutoSize = true;
			this->lblDynPB->Location = System::Drawing::Point(323, 342);
			this->lblDynPB->Name = L"lblDynPB";
			this->lblDynPB->Size = System::Drawing::Size(33, 13);
			this->lblDynPB->TabIndex = 61;
			this->lblDynPB->Text = L"None";
			this->lblDynPB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblDynGT
			// 
			this->lblDynGT->AutoSize = true;
			this->lblDynGT->Location = System::Drawing::Point(219, 343);
			this->lblDynGT->Name = L"lblDynGT";
			this->lblDynGT->Size = System::Drawing::Size(68, 13);
			this->lblDynGT->TabIndex = 60;
			this->lblDynGT->Text = L"Thin-Medium";
			this->lblDynGT->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numVisDepth
			// 
			this->numVisDepth->DecimalPlaces = 2;
			this->numVisDepth->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numVisDepth->Location = System::Drawing::Point(363, 31);
			this->numVisDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numVisDepth->Name = L"numVisDepth";
			this->numVisDepth->Size = System::Drawing::Size(98, 20);
			this->numVisDepth->TabIndex = 4;
			this->numVisDepth->ValueChanged += gcnew System::EventHandler(this, &Form1::numVisDepth_ValueChanged_1);
			// 
			// btnClearSO
			// 
			this->btnClearSO->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnClearSO->ForeColor = System::Drawing::SystemColors::Window;
			this->btnClearSO->Location = System::Drawing::Point(422, 244);
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
			this->btnClearPB->Location = System::Drawing::Point(323, 244);
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
			this->btnClearGT->Location = System::Drawing::Point(224, 244);
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
			this->numTaperedBaguetteMaxWidth->Visible = false;
			this->numTaperedBaguetteMaxWidth->ValueChanged += gcnew System::EventHandler(this, &Form1::numTaperedBaguetteMaxWidth_ValueChanged);
			// 
			// picShapeOutline
			// 
			this->picShapeOutline->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->picShapeOutline->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picShapeOutline->Location = System::Drawing::Point(407, 273);
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
			this->picGirdle->Location = System::Drawing::Point(203, 273);
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
			this->picBulge->Location = System::Drawing::Point(305, 273);
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
			this->numDepth->Location = System::Drawing::Point(363, 53);
			this->numDepth->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5000, 0, 0, 0 });
			this->numDepth->Name = L"numDepth";
			this->numDepth->Size = System::Drawing::Size(98, 20);
			this->numDepth->TabIndex = 35;
			this->numDepth->Visible = false;
			this->numDepth->ValueChanged += gcnew System::EventHandler(this, &Form1::numDepth_ValueChanged);
			// 
			// pictAdjArrow
			// 
			this->pictAdjArrow->Location = System::Drawing::Point(17, 207);
			this->pictAdjArrow->Name = L"pictAdjArrow";
			this->pictAdjArrow->Size = System::Drawing::Size(86, 20);
			this->pictAdjArrow->TabIndex = 44;
			this->pictAdjArrow->TabStop = false;
			// 
			// txtShapeOutline
			// 
			this->txtShapeOutline->Location = System::Drawing::Point(407, 218);
			this->txtShapeOutline->Name = L"txtShapeOutline";
			this->txtShapeOutline->Size = System::Drawing::Size(85, 20);
			this->txtShapeOutline->TabIndex = 43;
			this->txtShapeOutline->Text = L"0%";
			this->txtShapeOutline->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lblShape
			// 
			this->lblShape->AutoSize = true;
			this->lblShape->Location = System::Drawing::Point(418, 166);
			this->lblShape->Name = L"lblShape";
			this->lblShape->Size = System::Drawing::Size(74, 13);
			this->lblShape->TabIndex = 42;
			this->lblShape->Text = L"Shape Outline";
			// 
			// tbShapeOutline
			// 
			this->tbShapeOutline->LargeChange = 1;
			this->tbShapeOutline->Location = System::Drawing::Point(411, 182);
			this->tbShapeOutline->MaximumSize = System::Drawing::Size(80, 30);
			this->tbShapeOutline->Minimum = -5;
			this->tbShapeOutline->MinimumSize = System::Drawing::Size(80, 30);
			this->tbShapeOutline->Name = L"tbShapeOutline";
			this->tbShapeOutline->Size = System::Drawing::Size(80, 45);
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
			this->numDia2->TabIndex = 3;
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
			this->numDia1->TabIndex = 2;
			this->numDia1->ValueChanged += gcnew System::EventHandler(this, &Form1::numDia1_ValueChanged);
			// 
			// txtPavilionBulge
			// 
			this->txtPavilionBulge->Location = System::Drawing::Point(305, 218);
			this->txtPavilionBulge->Name = L"txtPavilionBulge";
			this->txtPavilionBulge->Size = System::Drawing::Size(85, 20);
			this->txtPavilionBulge->TabIndex = 33;
			this->txtPavilionBulge->Text = L"0%";
			this->txtPavilionBulge->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGirdleThickness
			// 
			this->txtGirdleThickness->Location = System::Drawing::Point(203, 218);
			this->txtGirdleThickness->Name = L"txtGirdleThickness";
			this->txtGirdleThickness->Size = System::Drawing::Size(85, 20);
			this->txtGirdleThickness->TabIndex = 32;
			this->txtGirdleThickness->Text = L"0%";
			this->txtGirdleThickness->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtGlobAdjust
			// 
			this->txtGlobAdjust->Location = System::Drawing::Point(10, 182);
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
			this->tbPavilionBulge->Location = System::Drawing::Point(307, 182);
			this->tbPavilionBulge->Maximum = 20;
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
			this->tbGirdleThickness->Location = System::Drawing::Point(203, 182);
			this->tbGirdleThickness->Maximum = 11;
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
			this->lblPavilionBulge->Location = System::Drawing::Point(320, 165);
			this->lblPavilionBulge->Name = L"lblPavilionBulge";
			this->lblPavilionBulge->Size = System::Drawing::Size(74, 13);
			this->lblPavilionBulge->TabIndex = 24;
			this->lblPavilionBulge->Text = L"Pavilion Bulge";
			// 
			// lblGirdleThickness
			// 
			this->lblGirdleThickness->AutoSize = true;
			this->lblGirdleThickness->Location = System::Drawing::Point(210, 165);
			this->lblGirdleThickness->Name = L"lblGirdleThickness";
			this->lblGirdleThickness->Size = System::Drawing::Size(86, 13);
			this->lblGirdleThickness->TabIndex = 23;
			this->lblGirdleThickness->Text = L"Girdle Thickness";
			// 
			// lblGlobAdj
			// 
			this->lblGlobAdj->AutoSize = true;
			this->lblGlobAdj->Location = System::Drawing::Point(20, 165);
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
			// tbCrownHeight
			// 
			this->tbCrownHeight->LargeChange = 1;
			this->tbCrownHeight->Location = System::Drawing::Point(99, 182);
			this->tbCrownHeight->MaximumSize = System::Drawing::Size(104, 30);
			this->tbCrownHeight->Minimum = -10;
			this->tbCrownHeight->MinimumSize = System::Drawing::Size(104, 30);
			this->tbCrownHeight->Name = L"tbCrownHeight";
			this->tbCrownHeight->Size = System::Drawing::Size(104, 45);
			this->tbCrownHeight->TabIndex = 68;
			this->tbCrownHeight->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->tbCrownHeight->Scroll += gcnew System::EventHandler(this, &Form1::tbCrownHeight_Scroll);
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
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->groupBox2->Controls->Add(this->lblRecutDetails);
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
			this->groupBox2->Controls->Add(this->cbRecut);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(12, 516);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(505, 163);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			// 
			// btnSaveToLog
			// 
			this->btnSaveToLog->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnSaveToLog->ForeColor = System::Drawing::SystemColors::Window;
			this->btnSaveToLog->Location = System::Drawing::Point(90, 19);
			this->btnSaveToLog->Name = L"btnSaveToLog";
			this->btnSaveToLog->Size = System::Drawing::Size(47, 35);
			this->btnSaveToLog->TabIndex = 61;
			this->btnSaveToLog->Text = L"&save";
			this->btnSaveToLog->UseVisualStyleBackColor = false;
			this->btnSaveToLog->Click += gcnew System::EventHandler(this, &Form1::btnSaveToLog_Click);
			// 
			// btnCopy
			// 
			this->btnCopy->BackColor = System::Drawing::SystemColors::Desktop;
			this->btnCopy->ForeColor = System::Drawing::SystemColors::Window;
			this->btnCopy->Location = System::Drawing::Point(29, 19);
			this->btnCopy->Name = L"btnCopy";
			this->btnCopy->Size = System::Drawing::Size(47, 35);
			this->btnCopy->TabIndex = 60;
			this->btnCopy->Text = L"&copy";
			this->btnCopy->UseVisualStyleBackColor = false;
			this->btnCopy->Click += gcnew System::EventHandler(this, &Form1::btnCopy_Click);
			// 
			// lblRecutDetails
			// 
			this->lblRecutDetails->AutoSize = true;
			this->lblRecutDetails->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRecutDetails->Location = System::Drawing::Point(300, 102);
			this->lblRecutDetails->Name = L"lblRecutDetails";
			this->lblRecutDetails->Size = System::Drawing::Size(68, 12);
			this->lblRecutDetails->TabIndex = 57;
			this->lblRecutDetails->Text = L"lblRecutDetails";
			this->lblRecutDetails->Visible = false;
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
			this->numSG->ValueChanged += gcnew System::EventHandler(this, &Form1::numSG_ValueChanged);
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
			this->comboCut->TabIndex = 6;
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
			this->statusbar->Location = System::Drawing::Point(0, 682);
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
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->copyToolStripMenuItem,
					this->saveToolStripMenuItem, this->preferencesToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"&Edit";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->copyToolStripMenuItem->Text = L"&Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::copyToolStripMenuItem_Click);
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
			this->groupBoxCalculate->Controls->Add(this->btnSaveToLog);
			this->groupBoxCalculate->Controls->Add(this->lblWeightInCarats);
			this->groupBoxCalculate->Controls->Add(this->btnCopy);
			this->groupBoxCalculate->Controls->Add(this->txtResult);
			this->groupBoxCalculate->Controls->Add(this->buttonCalc);
			this->groupBoxCalculate->Controls->Add(this->buttonClear);
			this->groupBoxCalculate->Location = System::Drawing::Point(12, 397);
			this->groupBoxCalculate->Name = L"groupBoxCalculate";
			this->groupBoxCalculate->Size = System::Drawing::Size(505, 84);
			this->groupBoxCalculate->TabIndex = 16;
			this->groupBoxCalculate->TabStop = false;
			// 
			// lblWeightInCarats
			// 
			this->lblWeightInCarats->AutoSize = true;
			this->lblWeightInCarats->Location = System::Drawing::Point(185, 66);
			this->lblWeightInCarats->Name = L"lblWeightInCarats";
			this->lblWeightInCarats->Size = System::Drawing::Size(87, 13);
			this->lblWeightInCarats->TabIndex = 53;
			this->lblWeightInCarats->Text = L"Weight in carats.";
			// 
			// groupBoxChooseDiaOrGem
			// 
			this->groupBoxChooseDiaOrGem->Controls->Add(this->radioBtnGem);
			this->groupBoxChooseDiaOrGem->Controls->Add(this->radioBtnDia);
			this->groupBoxChooseDiaOrGem->Location = System::Drawing::Point(12, 479);
			this->groupBoxChooseDiaOrGem->Name = L"groupBoxChooseDiaOrGem";
			this->groupBoxChooseDiaOrGem->Size = System::Drawing::Size(505, 31);
			this->groupBoxChooseDiaOrGem->TabIndex = 17;
			this->groupBoxChooseDiaOrGem->TabStop = false;
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->saveToolStripMenuItem->Text = L"S&ave";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 704);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbOther))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbKeel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCrown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVisDepth))->EndInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbCrownHeight))->EndInit();
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

		OptionsForm myOptions; // declare Object pointing to Options Form

		BridgeCS^ loadData = gcnew BridgeCS;
		String^ getDecPlacesFromConfig = loadData->propBridge1000;
		String^ getDecPlacesForEndWeight = loadData->propBridgeCarat;
		String^ getSavedCalculations = loadData->propBridgeCalc;
		Boolean getSaveDateToLog = loadData->propBridgeSaveDate;
		Boolean getSaveTimeToLog = loadData->propBridgeSaveTime;

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
		this->numVisDepth->Text = "0.00";
		this->toolStrip->Text = L"Ready..."; // clear all textBox
		this->tbGirdleThickness->Value = 0;
		this->tbPavilionBulge->Value = 0;
		this->tbGirdleThickness->Value = 0;
		this->tbShapeOutline->Value = 0;
		this->tbKeel->Value = 0;
		this->tbOther->Value = 0;
		this->tbCrownHeight->Value = 0;
		this->txtGlobAdjust->Text = L"0%";
		this->txtPavilionBulge->Text = L"0%";
		this->txtGirdleThickness->Text = L"0%";
		this->txtShapeOutline->Text = L"0%";
		this->txtKeel->Text = L"0%";
		this->txtOther->Text = L"0%";
		this->txtCrownHeight->Text = L"0%";
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
			onScreenInfo(); // repaint screen
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


		if (this->comboCut->Text->Equals(RDBEAD) || this->comboCut->Text->Equals(BRIO)) {
			this->numVisDepth->Enabled = false;
		}else{
			this->numVisDepth->Enabled = true;
		}
		if (this->comboCut->Text->Equals(TAPBAG)) {
			/*change labels and make min width/max width appear*/
			this->numTaperedBaguetteMaxWidth->Show();
			this->lblMaxWidth->Show();
			this->numDia2->Width = this->numTaperedBaguetteMaxWidth->Width;
			this->lblDia2->Location = Point(223, 14);
			this->numDia2->Location = Point(223, 30);

			this->lblDia2->Text = L"Min Width";
			//repaint_shape_outline(); //bring alive if necessary
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
		this->calculate_carat_weight();
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
		this->numSG->Value = Convert::ToDecimal(3.52);
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
		this->numSG->Value = Convert::ToDecimal(0.00);
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

	private: System::Void tbKeel_Scroll(System::Object^ sender, System::EventArgs^ e) {
		combine_adjustments();
		this->txtKeel->Text = this->tbKeel->Value.ToString() + "%";
		if (this->tbKeel->Value < -1) { this->lblDynKeel->Text = "short keel"; }
		else if (this->tbKeel->Value >1) { this->lblDynKeel->Text = "long keel"; }
		else { this->lblDynKeel->Text = "long keel"; }
		
		this->onScreenInfo();
	}

	private: System::Void tbOther_Scroll(System::Object^ sender, System::EventArgs^ e) {
		combine_adjustments();
		this->txtOther->Text = this->tbOther->Value.ToString() + "%";
		this->onScreenInfo();
	}
	private: System::Void tbCrownHeight_Scroll(System::Object^ sender, System::EventArgs^ e) {
		combine_adjustments();
		this->txtCrownHeight->Text = this->tbCrownHeight->Value.ToString() + "%";
		repaint_crown_height();
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
		if (this->numDia2->Value > this->numDia1->Value)
			this->numDia1->Value = this->numDia2->Value;
		this->onScreenInfo(); // print depth percentage and L/W Ratio
	}
	private: System::Void numDia1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->numDia2->Value > this->numDia1->Value)
			this->numDia2->Value = this->numDia1->Value;
		this->onScreenInfo(); // print depth percentage and L/W Ratio
	}

	private: System::Void radDepthAsMm_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radDepthAsMm->Checked) {
			this->lblDepth->Text = "Depth (mm)";
			this->numVisDepth->DecimalPlaces = 2;
			this->numVisDepth->Increment = System::Decimal(0.01);
			Decimal averagewidth = this->numDia2->Value;
			//Decimal localDepth = this->numDepth->Value;
			if (CCutDim::isRoundish(this->comboCut->Text)) {
				averagewidth = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
			}
			this->numVisDepth->Value = CCalculator::depth_percentage_to_mm(averagewidth, this->numVisDepth->Value);
		} //stop this triggering when radDepthAsPercent is selected
	}
	private: System::Void radDepthAsPerc_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radDepthAsPerc->Checked) {
			this->lblDepth->Text = "Depth (%)";
			this->numVisDepth->DecimalPlaces = 1;

			this->numVisDepth->Increment = System::Decimal(0.1);
			Decimal averagewidth = this->numDia2->Value;
			if (CCutDim::isRoundish(this->comboCut->Text)) {
				averagewidth = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
			}
			this->numVisDepth->Value = CCalculator::depth_percentage_as_percent(averagewidth, this->numVisDepth->Value);

			Decimal sendValue = CCalculator::depth_percentage_to_mm(averagewidth, this->numVisDepth->Value);
			if (sendValue < this->numDepth->Minimum || sendValue < this->numDepth->Maximum) {
				this->numDepth->Value = sendValue;
			}
		}// stop this triggering when MM is checked
	}
	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void preferencesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		myOptions.ShowDialog();
		String^ decplaces = "2";
		if (myOptions.prop1000 == true) {

			this->numDia1->DecimalPlaces = 3;
			this->numDia1->Increment = System::Decimal(0.001);

			this->numDia2->DecimalPlaces = 3;
			this->numDia2->Increment = System::Decimal(0.001);

			this->numDepth->DecimalPlaces = 3;
			this->numDepth->Increment = System::Decimal(0.001);

			this->numVisDepth->DecimalPlaces = 3;
			this->numVisDepth->Increment = System::Decimal(0.001);
			decplaces = "3";
		}
		else {
			this->numDia1->DecimalPlaces = 2;
			this->numDia1->Increment = System::Decimal(0.01);

			this->numDia2->DecimalPlaces = 2;
			this->numDia2->Increment = System::Decimal(0.01);

			this->numDepth->DecimalPlaces = 2;
			this->numDepth->Increment = System::Decimal(0.01);

			this->numVisDepth->DecimalPlaces = 2;
			this->numVisDepth->Increment = System::Decimal(0.01);
			decplaces = "2";
		}

		BridgeCS^ settingsSave = gcnew BridgeCS;
		settingsSave->propBridge1000 = decplaces;
		settingsSave->propBridgeCarat=myOptions.propCtPlace;
		settingsSave->propBridgeSaveDate=myOptions.propSaveDate;
		settingsSave->propBridgeSaveTime=myOptions.propSaveTime;


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
		//LogForm^ lform = gcnew LogForm;
		//lform->Visible = true;
		 persistantLogRecord->Visible = true;
	}
	private: System::Void lblHiddenDepth_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		//this->Invalidate();   request a delayed Repaint by the normal MessageLoop system    
		//this->Update();      forces Repaint of invalidated area 
		//this->Refresh();    // Combines Invalidate() and Update(
		this->draw_depth(this->lblHiddenDepth->Text);

	}

	private: System::Void Form1_Load_1(System::Object^ sender, System::EventArgs^ e) {
		/****************LOAD CONFIG FILES***************************/
		this->Icon = gcnew System::Drawing::Icon(L"app.ico");
		CEmbeddedImage^ rc = gcnew CEmbeddedImage;
		rc->setName("recut");
		
		this->picRecut->Image = rc->getName();

		CEmbeddedImage^ cr = gcnew CEmbeddedImage;
		cr->setName("crown_normal");
		this->picCrown->Image = cr->getName();

		CEmbeddedImage^ adjarrow = gcnew CEmbeddedImage;
		adjarrow->setName("adjustmentarrow");
		this->pictAdjArrow->Image = adjarrow->getName();

		CEmbeddedImage^ defaultCut = gcnew CEmbeddedImage;
		defaultCut->setName("round brilliant");
		this->picCut->Image = defaultCut->getName();

		CEmbeddedImage^ defaultBulge = gcnew CEmbeddedImage;
		defaultBulge->setName("bulge_normal");
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
		/* SET ELEMENTS ON OPTIONS FORM TO VALUES FOUND IN application.settings (user)*/
		Boolean set1000s = false; //   these variables are sent to GUI
		if (!System::String::IsNullOrEmpty(getDecPlacesFromConfig)) {
			if (getDecPlacesFromConfig->Equals("3")) {
				set1000s = true;
			}
			else {
				set1000s = false;
			}
			myOptions.prop1000=set1000s;
		} // not null or empty
		/****************************************************/
		if (!System::String::IsNullOrEmpty(getDecPlacesForEndWeight)) {
			myOptions.propCtPlace = getDecPlacesForEndWeight;
		/****************************************************/
		} // not null or empty
		if (!System::String::IsNullOrEmpty(getSavedCalculations)) {
			persistantLogRecord->richTextLog->Text = getSavedCalculations;
		} // not null or empty
		/****************************************************/
		if (getSaveDateToLog) {
			myOptions.propSaveDate = true;
		}
		else {
			myOptions.propSaveDate = false;
		}
		if (getSaveTimeToLog) {
			myOptions.propSaveTime = true;
		}
		else {
			myOptions.propSaveTime = false;
		}
			/*		
					myOptions.propSaveDate=getSaveDateToLog;
					myOptions.propSaveTime=getSaveTimeToLog;
			*/


		/****************************************************/
	}

	private: System::Void numTaperedBaguetteMaxWidth_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void cbInterpolate_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo();
	}
	private: System::Void cbRecut_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->cbRecut->Checked) {
			this->lblRecutDetails->Visible = true;
		}
		else {
			this->lblRecutDetails->Visible = false;
		}
		this->picRecut->Image = nullptr;
		this->picRecut->Refresh();
		CEmbeddedImage^ resetCutImage = gcnew CEmbeddedImage;
		resetCutImage->setName("recut");
		this->picRecut->Image = resetCutImage->getName();
		this->onScreenInfo();
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
	private: System::Void numDepth_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		this->onScreenInfo(); // print depth percentage and L/W Ratio
	}
	private: System::Void numVisDepth_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {

		if (this->radDepthAsPerc->Checked) {

			Decimal averagewidth = this->numDia2->Value;
			if (CCutDim::isRoundish(this->comboCut->Text)) {
				averagewidth = CCalculator::average_diameter(this->numDia1->Value, this->numDia2->Value);
			}
			this->numDepth->Value = CCalculator::depth_percentage_to_mm(averagewidth, this->numVisDepth->Value);

		}
		else {
			this->numDepth->Value = this->numVisDepth->Value;
		}
		//this->onScreenInfo();
	}

	private: System::Void lwguide_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textCrown_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void btnCopy_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!this->toolStrip->Text->Equals(TOOLTIP))
		Clipboard::SetDataObject(this->toolStrip->Text, true);
	}
private: System::Void copyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!this->toolStrip->Text->Equals(TOOLTIP))
	Clipboard::SetDataObject(this->toolStrip->Text, true);
}
	   /******************************************************************
	   
								SAVE TO LOG 
	   
	   ******************************************************************/
private: System::Void btnSaveToLog_Click(System::Object^ sender, System::EventArgs^ e) {
	save_calculation_to_log();
}



private: System::Void numSG_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->numSG == this->ActiveControl)
	{
		this->onScreenInfo();
		//MessageBox::Show("value changed");
	}
}
private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	save_calculation_to_log();
}
};
}
