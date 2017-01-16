#include <ctime>
#include "cv.h"
#include "highgui.h"
#include <windows.h>

using namespace std;

//获取图像中某个点的像素值，在本实验中直接调用
unsigned char GetPixel(IplImage *img, int row, int col)
{
unsigned char *img_data = (unsigned char *)(img->imageData);
int width_step = img->widthStep;
return img_data[width_step * row + col];
}
//将图像中某个点的像素值赋值，在本实验中直接调用
void DrawPixel(IplImage *img, int row, int col, unsigned char v)
{
unsigned char *img_data = (unsigned char *)(img->imageData);
int width_step = img->widthStep;
img_data[width_step * row + col] = v;
}


// 将图像所有像素的像素值赋值为参数v的值，请完成相应的代码
void DrawAll(IplImage *img, int height, int width, unsigned char v)
{
    // 在该函数内利用循环语句，并调用DrawPixel函数，将图像所有的像素都置为参数v的值
	for(int Height =0;Height<height;Height++)
	{
		for(int Width=0;Width<width;Width++)
			DrawPixel(img, Height, Width, v);
	}
}

// 在图像中绘制圆的函数。圆心为(row,col)，半径为radius, 圆周上的像素值为v，请完成相应的代码
void DrawCircle(IplImage *img, int height, int width, int row, int col, int radius, unsigned char v)
{
    // 遍历图像所有的像素点的坐标，比较其到圆心的距离是否“等于”半径。
	// 注意，虽然像素点的坐标是整数，但计算的距离应该设置为浮点型。这时距离和半径相比，应该使用浮点型数比较的语句。
    // 利用课上所讲的浮点数的比较方法，设定一个“合适”的阈值，在图像中画出完整的圆周
   // 调用DrawPixel函数对相应的像素点进行赋值
	for(int Height =0;Height<height;Height++)
	{
		for(int Width=0;Width<width;Width++)
		{
			double distance;
	        distance=sqrt((row-Height)*(row-Height)*1.0+(col-Width)*(col-Width)*1.0);
			if(distance-radius<=0.01)
				DrawPixel(img, Height, Width, v);
		}
	}
}

// 设计函数并完成相应的代码，将图像中非零的像素值减去某个数值，从而在产生随机点“渐渐消失”效果时调用
//调用GetPixel函数获取某像素点的像素值
void fade(IplImage *img, int height, int width)
{
	unsigned char flag_v=1;//标记flag_v
	while(flag_v>0)
	{
		flag_v=0;
		for(int Height=0;Height<height;Height++)
		{
			for(int Width=0;Width<width;Width++)
			{
				unsigned char v=GetPixel(img,Height, Width);
				if(v>0)
					DrawPixel(img, Height, Width,  v-200);
				if(GetPixel(img, Height, Width)>0)
					flag_v=1;
			}
		}
	}
}
//void fade(IplImage *img, int row, int col)
//{
//	unsigned char v=GetPixel(img,row, col);
//	if(v>0)
//		DrawPixel(img, row, col,  v-150);
//}
int main(int argc, char* argv[])
{
// 下面的函数为你创建一个OpenCV的图像，图像的宽度（width）和高度（height）由你设定。
// 本实验中的图像为正方形，所以应该设置为相同的数值，也即内切圆的半径
IplImage* img = cvCreateImage(cvSize(999, 999), IPL_DEPTH_8U, 1); // IplImage是OpenCV中存储图像的结构体

// 通过调用DrawAll函数，将图像所有像素的像素值都赋值为0（全黑）
DrawAll(img, 999, 999, 0);
// 用白色（255）画内切圆，圆心（x,y）半径r
DrawCircle(img, 999, 999, 500, 500, 499.5, 255);
cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//创建窗口
cvShowImage("Image", img);//显示图像
cvWaitKey(0); //等待按键，开始采样随机点


{	
// 开始你的求pi循环
// 在你的循环体内

    // 调用你设计的函数，使图像中所有非零的像素值减去某个固定的常数，以产生动态的渐变效果，如果图像尺寸较小，则减去的数值应该适当大一些
    // 产生一个随机点
    // 根据点的坐标找到对应图像中的像素点，将该像素值赋值为255。
    // 重新绘制内切圆
	float pi=100.00000,residual=100.00000;
    float m=0.00000,n=0.00000;
    float pi1=100,pi2;
	while(fabs(residual)>0.00001)
	{
        int N=100000;
		for(int P=N;P>0;P--)
		{
			float x=0.00000,y=0.00000,distance=0.00000;
			x=float(rand())/float(RAND_MAX)*998;
			y=float(rand())/float(RAND_MAX)*998;
			DrawPixel(img, x, y,255);
			//fade(img, x, y );
			distance=sqrt((x-500)*(x-500)+(y-500)*(y-500));//(500,500)为圆心
			if(distance<499.5)//499.5为圆半径
				++m;
        }
        n=n+N;
		pi2=float(m)/float(n);
        residual=(pi2-pi1)*4;
        pi1=pi2;
        pi=pi1*4;
		cvShowImage("Image", img);//显示图像
        cvWaitKey(50); //延时50毫秒
		//fade(img, 999, 999 );
       // 同时在控制台输出当前的pi值
       cout<<"pi value is "<<pi<<endl;
    }
}
    cvDestroyWindow("Image");//销毁窗口
    cvReleaseImage(&img); //释放图像
    return 0;
}