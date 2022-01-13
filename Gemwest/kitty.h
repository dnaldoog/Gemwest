#pragma once
using namespace System::Drawing;

ref class kitty
{
	void load() {
		// Point()で座標指定など。
		System::Drawing::Point curpoint;
		curpoint = this->pictureBox1->Location;
		curpoint.X++;
		curpoint.Y++;
		this->pictureBox1->Location = curpoint;
		// ※おそらく「Size()」でも同じはず。

	// PictureBoxとBitmapの接続。
		Bitmap^ bmap;
		bmap = gcnew Bitmap("cur01.jpg");
		this->pictureBox1->Image = this->bmap;

		// タイマーで動かす。

		// DrawImageで伸縮。
		Graphics^ grpPicBox;
		Bitmap^ srcbmpImage = gcnew Bitmap("curry_cat.png");
		this->pictureBox1->Image = this->bmap;

		// 接続
		if (grpPicBox != nullptr) delete grpPicBox;
		grpPicBox = Graphics::FromImage(this->pictureBox1->Image);

		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Default;			// 規定の補間モード 
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::High;				// 高品質補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Low;				// 低品質補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;	// 最近傍補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Bilinear;			// 双一次補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::Bicubic;			// 双三次補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBilinear;	// 高品質双一次補間
		//	grpPicBox->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;	// 高品質双三次補間

			// ビットマップの描画元の領域
		RectangleF SrcRect = RectangleF(0, 0, 100, 100);
		// ピクチャボックスへの描画先
		RectangleF DstRect = RectangleF(20, 20, 50, 50);

		// 描画
		grpPicBox->DrawImage(srcbmpImage, DstRect, SrcRect, GraphicsUnit::Pixel);

		// 画像処理・DrawImage
		// http://imagingsolution.blog107.fc2.com/blog-entry-95.html
	}
};

