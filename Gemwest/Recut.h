#pragma once
#include "CDround.h"
ref class Recut :
    public CDround
{
public:
	explicit Recut(
		String^ cutName, 
		String^ fac, 
		Decimal d1,
		Decimal d2,
		Decimal dep,
		String^ sg, 
		String^ adj, 
		String^ gt, 
		String^ pv, 
		String^ so, 

		Boolean isdiamond, 
		Boolean recut, 

		Boolean depthisperc) : CDround(cutName, fac, d1, d2, dep, sg, adj, gt, pv, so, isdiamond, recut, depthisperc) {}
};
/**/
///*
///*********************************************************************************************
//*
//*   First: work out the difference (decrease) between the two numbers you are comparing.
//*   Decrease = Original Number - New Number
//*   Then: divide the decrease by the original number and multiply the answer by 100.
//*   % Decrease = Decrease ÷ Original Number × 100
//*   If your answer is a negative number then this is a percentage increase.
//*
//***********************************************************************************************/
//float decrease=(original_weight.toFloat()-get_recut_weight.toFloat());
//float tmp=(decrease/original_weight.toFloat())*100;
//              _recut_Loss_Perc=String ^::number(tmp,'f',2);
//   }
//   void  DCalc::write_Recut_CaratLoss(const String ^ &arg1){
//       /*write recut weight*/
//       _recut_Loss=arg1;
//   }
//   void DCalc::write_Recut_Depth_Percentage(const String ^ &arg1)
//{
//        _recut_Depth_Percentage=arg1;
//}
//void DCalc::calculateRecut(void){
////    qDebug() << __FUNCTION__<<__LINE__;
//    /* OLD CUT
//The diameter of the girdle is measured in various directions; this gives very uneven results, especially in the case of square-round shapes. Then the smallest diameter in millimeters is selected.
//This smallest diameter = 100 %.
//The maximal allowable total height of 62 % is then calculated to avoid unnecessary loss of weight and to use as much as possible of the existing "diamond material" of the old-cut.
//The formula for calculating the new height is:
//Height = R Ø (smallest Value) X 0.62
//The result shows the total height in millimeters of the new brilliant after re-cutting.
//Taking this calculated height and the measured smallest girdle diameter the weight can be estimated according to the following formula:
//carat weight = height(new) x R Ø2 X 0.0061
//In the case of a square-round diameter, the loss in weight is about 20-30 %, in the case of brilliants with constant diameter about 5-15 %.
//In the case of old-cuts where. the total height is definitely too low (under 54 %), the girdle diameter must be decreased in order to achieve ideal proportions between the total height and the girdle diameter.
//A new girdle diameter must be established:
//The total height is measured in millimeters. The height is taken as = 58 %.
//A small percentage value recommended for a "very good" cut is selected so that the girdle does not have to be reduced too much in order to save weight. The girdle diameter of 100 % is calculated according to the following formula:
//R Ø = height x 100/58
//Taking the measured total height and the calculated girdle diameter the weight can be arrived at using the known formula:
//carat weight = height x R Ø2 X 0.0061
//In the case of a brilliant with square-round base the loss of weight is about 30-40 %, where the shape is more circular about 10-20 %.
//     */
//    int Image=0;
//    String ^ tooltipString,actualWeight;
//    const int lowThreshold=55;/*ie threshold is 54%*/
//    const int highThreshold=62;/*ie threshold is 62%*/
//    float *p,DeepStone,ShallowStone,newDiameter,newDepth,recut_Image=0,caratLoss=0;
//    actualWeight=_answer;
//    newDiameter=_avdiameter.toDouble();
//    newDepth=_depth.toDouble();
//    float dpCompareWithThreshold = _depth_Percentage.toFloat();
//    DeepStone=(_width.toDouble()*62)/100;
//    ShallowStone=(_depth.toDouble()*100)/58;
//    /*****************************/
//    if(String ^::compare(_cut,"oval brilliant")==0 || String ^::compare(_cut,"round brilliant")==0 ||
//            String ^::compare(_cut,"old mine cut")==0 || String ^::compare(_cut,"old european cut")==0){
//        Image=GOOD;/*default*/
//        if(dpCompareWithThreshold < lowThreshold){/*it's a shallow stone*/
//            p=&ShallowStone;
//            newDiameter=*p;
//            tooltipString="shallow stone";
//            Image=SHALLOW;
//        }/*END SHALLOW*/
//        if(dpCompareWithThreshold > highThreshold){/*it's a deep stone*/
//            p=&DeepStone;
//            newDepth=*p;
//            tooltipString="deep stone";
//            Image=DEEP;
//        }/*END DEEP*/
//            recut_Image=(newDiameter*newDiameter)*newDepth*DEFDIAFACTOR;
//            /*sent to external variable for logging*/
//            caratLoss=actualWeight.toDouble()-recut_Image;
//            //float caratLossPerc=100*(caratLoss/actualWeight.toDouble());
//    }else{
//        write_Recut_Image_Pix(NOTHING);
//    }
//switch(Image){
//case GOOD:
//    write_Recut_Image_Pix(GOOD);
//    break;
//case SHALLOW:
//    write_Recut_Image_Pix(SHALLOW);
//    break;
//case DEEP:
//    write_Recut_Image_Pix(DEEP);
//    break;
//default:
//    write_Recut_Image_Pix(NOTHING);
//    break;
//}
//write_Recut_Weight(String ^::number(recut_Image,'f',2));
//write_Recut_Diameter(String ^::number(newDiameter,'f',2));
//write_Recut_Depth(String ^::number(newDepth,'f',2));
//write_Recut_CaratLoss(String ^::number(caratLoss,'f',2));
//write_Recut_CaratLoss_Perc();
////qDebug() << __FUNCTION__;
//}
//*/
//
