#include"highgui.h"
#include"cv.h"
#include<iostream>
using namespace std;
#include "Mat.hpp"
#include "Filter.hpp"
void main()
{
	//����ÿ��ģ��Ϳ��Բ���������ģ�����������֤

	////1.���ü�������֤ģ��
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


	////2.��ɫ�Ĳ���ģ��
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//-Img;
	//Img.Show("��ɫ");

	////3.��ȡ������ĳ��Ԫ�ص�ֵ
	//Mat<double> Img("images\\Fruits.jpg");
	//cout<<Img.At(7,99)<<endl;

	////4.��ת����--------------------------------------��������
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Rotate(60);
	//Img.Show("rotate");

	////5.���Ų���
	//   Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Resize(895,955);
	//Img.Show("resize");

	////6.�ü�����
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Orign");
	//Img.Cut(55,55,466,466);
	//Img.Show("cutted");

	////7.����(������ƴ��)����  
	//Mat<double> Img("images\\Airplane.jpg");
	//Img.Show("Airplane");
	//Mat<double> Img1("images\\Baboon.jpg");
	//Img1.Show("Baboon");
	//Img.Cat(Img1,3);
	//Img.Show("joint");

	////8.��Mat�ļӼ�����֮ �Ӳ���(������ͼƬ��д���ֵ�)
	//Mat<double> Img("images\\Fruits.jpg");
	//Img.Show("Fruits");
	//Mat<double> Img1("images\\word.jpg");
	//Img1.Show("word");
	//Img=Img+Img1;
	//Img.Show("Mat_add_Mat");

	////9.��Mat�ļӼ�����֮ ����������������ȡͼƬ�еľ��
	//Mat<double> Img("images\\scene2_fg.jpg");
	//Img.Show("scene2_fg");
	//Mat<double> Img1("images\\scene2_bg.jpg");
	//Img1.Show("scene2_bg");
	//Img=Img-Img1;
	//Img.Show("Mat_minus_Mat");

	////10.��ͼƬ�����˲�����֮   ��ֵ�˲�
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MeanFilter <double>(5);
	//Mat<double> Img_Mean;
	//Img_Mean=fp->Filtering(Img);
	//Img_Mean.Show("MeanFilter");

	////11.��ͼƬ�����˲�����֮   ��ֵ�˲�   
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MedianFilter <double>(9);
	//Mat<double> Img_Median;
	//Img_Median=fp->Filtering(Img);
	//Img_Median.Show("Img_Median");


	////12.ԭMat���ֵ�˲���Ĳ�ֵ����ʾ
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MeanFilter <double>(3);
	//Mat<double> Img_Mean;
	//Img_Mean=fp->Filtering(Img);
	//Img_Mean.Show("MeanFilter");
	//Img=Img-Img_Mean;//��������
	//Img.Show("Origin-MeanFilter");


	//	//13.ԭMat����ֵ�˲���Ĳ�ֵ����ʾ
	//Mat<double> Img("images\\Lena_gaussian.jpg");
	//Img.Show("Lena_gaussian");
	//Filter<double> * fp=NULL;
	//fp=new MedianFilter <double>(9);
	//Mat<double> Img_Median;
	//Img_Median=fp->Filtering(Img);
	//Img_Median.Show("Img_Median");
	//Img=Img-Img_Median;//��������
	//Img.Show("Origin-Median");

	////14.�������ҷ�ת��ת����
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img.Flip(0);
	//Img.Show("Fruits");

	//  //15.��ͼƬת��
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img.Transpose();
	//Img.Show("Fruits");

	////16.�����ظ�����������£���ͼƬ��Ϊָ����С
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img.Reshape(512,480);
	//	Img.Show("Reshape_Fruits");

	////17.ͼ���ֵ��������ʾ
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img.gray2bw(0.555);
	//	Img.Show("gray2bw_Fruits");

	////18.1���ȵ���֮�ֵ�����
	//	Mat<double> Img("images\\Fruits.jpg"); 
	//	Img.Show("Fruits");
	//	Img=operator+(Img,22.2);
	//	Img.Show("flat_tune_light_Fruits");

	////18.2���ȵ���֮�ֵ��䰵
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//Img=operator-(Img,42.2);
	//Img.Show("flat_tune_dark_Fruits");

	////19.1���ȵ���֮ϸ������
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//++Img;
	//Img.Show("fine_tune_light_Fruits");

	////19.2���ȵ���֮ϸ���䰵
	//Mat<double> Img("images\\Fruits.jpg"); 
	//Img.Show("Fruits");
	//--Img;
	//Img.Show("fine_tune_dark_Fruits");

	////20.������ʾ
	//Mat<double> Img1("images\\Airplane.jpg"); 
	//Img1.Show("Airplane");
	//Mat<double> Img2("images\\Baboon.jpg"); 
	//Img2.Show("Baboon");
	//Swap(Img1,Img2);
	//Img1.Show("Airplane");
	//Img2.Show("Baboon");
   
    //21.�򵥵���ǿ�Աȶȣ���������˷���
	Mat<double> Img("images\\Fruits.jpg"); 
	Img.Show("Fruits");
	Img.Square();
	Img.Show("enhancing_contrast_Fruits");

}