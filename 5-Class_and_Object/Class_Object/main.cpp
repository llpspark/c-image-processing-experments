#include<iostream>
using namespace std;
#include "ClassObject.h"
#include "cv.h"
#include "highgui.h"

int main(int argc, char* argv[])
{
	int number, x,y, value;
	Image img("Fruits.jpg"); //创建对象
	cout<<"请按照以下提示进行选择："<<endl;
	cout<<"*********************** 1:显示当前读入的图像：***********************"<<endl;
	cout<<"*********************** 2:将当前图像存为相应图像副本：***************"<<endl;
	cout<<"*********************** 3:获取当前图像某一像素点的值：****************"<<endl;
	cout<<"*********************** 4:将所有像素设置为某值，并显示相应图像：******"<<endl;
	cout<<"*********************** 5:将图像中给定像素点的像素值设置为某值：******"<<endl;
	cout<<"*********************** 6:图像的上下翻转、左右翻转：*******************"<<endl;
	cout<<"*********************** 7:指定区域裁剪图像：***************************"<<endl;
	cout<<"*********************** 8:图像的均值，方差：***************************"<<endl;
	cout<<"*********************** 9:图像的旋转：*********************************"<<endl;
	cout<<"*********************** 10:图像的放缩：********************************"<<endl;
	cout<<"*********************** 11:交换两图像的数据：**************************"<<endl;

	cin>>number;
	switch(number) 
	{
	case 1:
		img.Show("Image");
		break;
	case 2:
		img.Write("image\\FruitsCopy.jpg");
		break;
	case 3:
		cout<<"请输入需要获取像素点的坐标：";
		cin>>x>>y;
		cout<<"相应点的像素值("<<x<<","<<y<<")："<<int(img.At(x,y))<<endl;
		system("pause");
		break;
	case 4:
		cout<<"请输入需要设置的像素值（0~255）：";
		cin>>value;
		img.SetAll(value);
		img.Show("Image");
		cvWaitKey(0); //等待按键
		break;
	case 5:
		cout<<"请输入需要设置的像素像素点和相应像素值（用空格隔开）：";
		cin>>x>>y>>value;
		img.Set(x, y, value);
		cout<<"相应点的像素值已经设置为("<<x<<","<<y<<")："<<int(img.At(x,y))<<endl;
		system("pause");
		break;
	case 6:
		img.Show("Image");
		cvWaitKey(0); //等待按键
		cout<<"输入0左右翻转；输入其他数字上下翻转"<<endl;
		cin>>x;
		if(x)
		{
			img.Flip(1) ;
			img.Show("Image");
		}
		else
		{
			img.Flip(0) ;
			img.Show("Image");
		}
		break;
	case 7:
		int x1,x2,y1,y2;
		img.Show("Image");
		cout<<"输入裁剪图像的对角坐标，分别为x1，y1,x2,y2(注意x1<x2,y1<y2)"<<endl;
		cin>>x1>>y1>>x2>>y2;
		img.Cut(x1,y1,x2,y2);
		img.Show("Image");
		break;
	case 8:
		float m,var;
		img.Mean_Variance(m, var);
		cout<<"图像的均值为："<<m<<"方差分别为:"<<var<<endl;
		system("pause");
		break;
	case 9:
		img.Show("Image");
		cout<<"输入图像逆时针旋转的角度（90,180,270）"<<endl;
		cin>>x;
		if(x==90)
		{
			img.Flip(1) ;
			img.Flip(0) ;
			img.Rotate();
			img.Flip(0) ;
			img.Show("Image");
		}else if(x==180)
		{
			img.Flip(1) ;
			img.Flip(0) ;
			img.Rotate();
			img.Flip(0) ;
			img.Show("Image");
		}else if(x==270)
		{
			img.Flip(1) ;
			img.Flip(0) ;
			img.Rotate();
			img.Flip(0) ;
			img.Show("Image");
		}
		break;
	case 10:
		img.Show("Image");
		cout<<"图像缩小输入0；图像放大输入其他数字"<<endl;
		cin>>x;
		img.Resize(x);
		img.Show("Image");

	default:
		cout<<"交换两张图片：";
		Image img1("Baboon.jpg");
		Image img2("Lena.jpg");
		img1.Show("Image1");
		img2.Show("Image2");
		cout<<"交换以上两张图片：";
		Swap(img1, img2);
		img1.Show("Image1");
		img2.Show("Image2");
	}
	return 0;
}