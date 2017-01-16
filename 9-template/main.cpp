#include"highgui.h"
#include"cv.h"
#include<iostream>
using namespace std;
#include "Mat.hpp"
#include "Filter.hpp"
void main()
{
	//以下每个模块就可以不依赖其他模块独立运行验证

	////1.引用计数的验证模块
	//Mat<double> Img3("images\\Fruits.jpg");
	//Img3.Show("Orign3");
	//{
	//	Mat<double> Img2(Img3);
	//	Img2.Show("Orign2");
	//	{
	//		Mat<double> Img(Img3);
	//		Img.Show("Orign");
	//	}
	//}


	////2.求反色的测试模块
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//-Img;
	//Img.Show("反色");

	////3.获取矩阵中某个元素的值
	//Mat<double> Img("images\\Fruits.jpg");
	//cout<<Img.At(7,99)<<endl;

	////4.旋转操作--------------------------------------还需完善
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Rotate(60);
	//Img.Show("rotate");

	////5.缩放操作
	//   Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Resize(895,955);
	//Img.Show("resize");

	////6.裁剪操作
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Cut(55,55,466,466);
	//Img.Show("cutted");

	////7.重组(各方向拼接)操作  
	//Mat<double> Img("images\\Airplane.jpg");
	//Img.Show("Airplane");
	//Mat<double> Img1("images\\Baboon.jpg");
	//Img1.Show("Baboon");
	//Img.Cat(Img1,3);
	//Img.Show("joint");

	////8.对Mat的加减操作之 加操作(用于向图片上写文字等)
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Fruits");
	//Mat<double> Img1("images\\word.jpg");
	//Img1.Show("word");
	//Img=Img+Img1;
	//Img.Show("Mat_add_Mat");

	////9.对Mat的加减操作之 减操作（可用于提取图片中的景物）
	//Mat<double> Img("images\\scene2_fg.jpg");
	//Img.Show("scene2_fg");
	//Mat<double> Img1("images\\scene2_bg.jpg");
	//Img1.Show("scene2_bg");
	//Img=Img-Img1;
	//Img.Show("Mat_minus_Mat");

	////10.对图片进行滤波操作之   均值滤波
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MeanFilter <double>(5);
	//Mat<double> Img_Mean;
	//Img_Mean=fp->Filtering(Img);
	//Img_Mean.Show("MeanFilter");

	////11.对图片进行滤波操作之   中值滤波   
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MedianFilter <double>(9);
	//Mat<double> Img_Median;
	//Img_Median=fp->Filtering(Img);
	//Img_Median.Show("Img_Median");


	////12.原Mat与均值滤波后的差值并显示
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MeanFilter <double>(3);
	//Mat<double> Img_Mean;
	//Img_Mean=fp->Filtering(Img);
	//Img_Mean.Show("MeanFilter");
	//Img=Img-Img_Mean;//做差运算
	//Img.Show("Origin-MeanFilter");


	//	//13.原Mat与中值滤波后的差值并显示
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MedianFilter <double>(9);
	//Mat<double> Img_Median;
	//Img_Median=fp->Filtering(Img);
	//Img_Median.Show("Img_Median");
	//Img=Img-Img_Median;//做差运算
	//Img.Show("Origin-Median");

	////14.上下左右翻转翻转操作
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img.Flip(0);
	//Img.Show("Fruits");

	//  //15.对图片转置
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img.Transpose();
	//Img.Show("Fruits");

	////16.总像素个数不变情况下，将图片变为指定大小
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img.Reshape(512,480);
	//	Img.Show("Reshape_Fruits");

	////17.图像二值化处理并显示
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img.gray2bw(0.555);
	//	Img.Show("gray2bw_Fruits");

	////18.1亮度调节之粗调变亮
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img=operator+(Img,22.2);
	//	Img.Show("flat_tune_light_Fruits");

	////18.2亮度调节之粗调变暗
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img=operator-(Img,42.2);
	//Img.Show("flat_tune_dark_Fruits");

	////19.1亮度调节之细调变亮
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//++Img;
	//Img.Show("fine_tune_light_Fruits");

	////19.2亮度调节之细调变暗
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//--Img;
	//Img.Show("fine_tune_dark_Fruits");

	////20.交换显示
	//Mat<double> Img1("images\\Airplane.jpg"); 
	//Img1.Show("Airplane");
	//Mat<double> Img2("images\\Baboon.jpg"); 
	//Img2.Show("Baboon");
	//Swap(Img1,Img2);
	//Img1.Show("Airplane");
	//Img2.Show("Baboon");
   
    //21.简单的增强对比度（矩阵自身乘方）
	Mat<double> Img("images\\Fruits.jpg"); 
	Img.Show("Fruits");
	Img.Square();
	Img.Show("enhancing_contrast_Fruits");

}