#pragma once
using namespace System::Drawing;

ref class kitty
{
	void load() {
		// Point()$B$G:BI8;XDj$J$I!#(B
		System::Drawing::Point curpoint;
		curpoint = this->pictureBox1->Location;
		curpoint.X++;
		curpoint.Y++;
		this->pictureBox1->Location = curpoint;
		// $B"($*$=$i$/!V(BSize()$B!W$G$bF1$8$O$:!#(B

	// PictureBox$B$H(BBitmap$B$N@\B3!#(B
		Bitmap^ bmap;
		bmap = gcnew Bitmap("cur01.jpg");
		this->pictureBox1->Image = this->bmap;

		// $B%?%$%^!<$GF0$+$9!#(B

		// DrawImage$B$G?-=L!#(B
		Graphics^ grpPicBox;
		Bitmap^ srcbmpImage = gcnew Bitmap("curry_cat.png");
		this->pictureBox1->Image = this->bmap;

		// $B@\B3(B
		if (grpPicBox != nullptr) delete grpPicBox;
		grpPicBox = Graphics::FromImage(this->pictureBox1->Image);

		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Default;			// $B5,Dj$NJd4V%b!<%I(B 
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::High;				// $B9bIJ<AJd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Low;				// $BDcIJ<AJd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;	// $B:G6aK5Jd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Bilinear;			// $BAP0l<!Jd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Bicubic;			// $BAP;0<!Jd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBilinear;	// $B9bIJ<AAP0l<!Jd4V(B
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;	// $B9bIJ<AAP;0<!Jd4V(B

			// $B%S%C%H%^%C%W$NIA2h85$NNN0h(B
		RectangleF SrcRect = RectangleF(0, 0, 100, 100);
		// $B%T%/%A%c%\%C%/%9$X$NIA2h@h(B
		RectangleF DstRect = RectangleF(20, 20, 50, 50);

		// $BIA2h(B
		grpPicBox->DrawImage(srcbmpImage, DstRect, SrcRect, GraphicsUnit::Pixel);

		// $B2hA|=hM}!&(BDrawImage
		// http://imagingsolution.blog107.fc2.com/blog-entry-95.html
	}
};

