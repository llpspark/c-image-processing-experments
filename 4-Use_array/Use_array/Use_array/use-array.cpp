#include "cv.h"
#include "highgui.h"
#include"iostream"
using namespace std;
void ReadImageData(unsigned char *src, int rows, int cols, int width_step, unsigned char **dst)
{
	for(int i=0;i<=rows-1;i++)
	{
		for(int j=0;j<=cols-1;j++)
		{
			//dst[i][j]=src[i*width_step+j];       值传递与问题！    
		    *(*(dst+i)+j)=src[i*width_step+j];
		}	
	}
}

void WriteImageData(unsigned char **src, int rows, int cols, int width_step, unsigned char *dst)
{
	for(int i=0;i<=rows-1;i++)
	{
		for(int j=0;j<=cols-1;j++)
		{
			//dst[i*width_step+j]=csrc[i][j];
			*(dst+(i*width_step+j))=src[i][j];
		}	
	}
}

void FlipImageUpDown(unsigned char **img, int rows, int cols)
{
	int p=0,q=rows-1;
	unsigned char p_temp[1000];
	while(p<q)   //       (p!=q)不能这样判断
	{
		for(int i=0;i<cols;i++)
			p_temp[i]=*(*(img+p)+i);
		for(int i=0;i<cols;i++)
			*(*(img+p)+i)=*(*(img+q)+i);
		for(int i=0;i<cols;i++)	
			*(*(img+q)+i)=p_temp[i];
		p++;
		q--;
	}
}

void FlipImageLeftRight(unsigned char **img, int rows, int cols)
{
    int p=0,q=cols-1;
	unsigned char p_temp[1000];
	while(p<q)   //(p!=q)不能这样判断
	{
		for(int i=0;i<rows;i++)
			p_temp[i]=*(*(img+i)+p);
		for(int i=0;i<rows;i++)
			*(*(img+i)+p)=*(*(img+i)+q);
		for(int i=0;i<rows;i++)	
			*(*(img+i)+q)=p_temp[i];
		p++;
		q--;
	}
}
 void aHarfTob(unsigned char **src, int rows, int cols, int width_step, unsigned char **dst)
 {
	for(int i=0;i<=(rows-1)/2;i++)
	{
		for(int j=0;j<=(cols-1)/2;j++)
			*(*(dst+i)+j)=src[i*2+1][j*2+1];
	}
 }


int main(int argc, char* argv[])
{
	IplImage* img = cvLoadImage("Fruits.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//创建窗口
	cvShowImage("Image", img);//显示图像
	cvWaitKey(0); //等待按键

	unsigned char *img_data = (unsigned char *)(img->imageData); //读取图像
	int height = img->height;    //获取图像高度（行数）
	int width = img->width;      //获取图像宽度（列数）
	int width_step = img->widthStep;    //获取图像每行所占的字节数

	// 判断width_step是否等于列数*每个元素所占字节数
	// write your code here
	if((img->width)*sizeof( unsigned char)==width_step)
		cout<<"width_step等于列数*每个元素所占字节数"<<endl;
	else
		cout<<"width_step不等于列数*每个元素所占字节数"<<endl;
	// 声明二维数组a，大小是height*width，unsigned char类型;
	// write your code here
	unsigned char **a;
	a=new unsigned char*[height];
	for(int i=0;i<height;i++)
	{
		a[i]=new unsigned char[width];
	}
	// 读取图像数据到二维数组a中，实现函数ReadImageData
	// 比如这样调用ReadImageData（img_data, height, width, width_step, a）；
	ReadImageData(img_data, height, width, width_step, a);
	// 上下翻转图像
	// 调用FlipImageUpDown
	FlipImageUpDown(a,height, width);
	// 将数组a的数据写回源图像的内存区（img_data指针所指的区域），即调用WriteImageData
	WriteImageData(a, height, width,width_step ,img_data);
	cvShowImage("Image", img);
	cvWaitKey(0); //等待按键
	// 左右翻转图像
	// 调用FlipImageLeftRight
	FlipImageLeftRight(a, height, width);
	// 调用WriteImageData
	WriteImageData(a, height, width,width_step ,img_data);
	cvShowImage("Image", img);
	cvWaitKey(0); //等待按键
	/// 动态分配二维数组b，用来存储缩小后的图像
	unsigned char **b;
	b=new unsigned char* [height/2];
	for(int i=0;i<height/2;i++)
	{
		b[i]=new unsigned char[width/2];
	}
	/// 将原图缩小为原尺寸的一半，结果存入b中，添加相应的函数实现
	// write your code here
	 aHarfTob(a,height, width,width_step/2, b);
	 IplImage *img2 = cvCreateImage(cvSize(width/2, height/2), IPL_DEPTH_8U, 1);
	//   WriteImageData(b, img2->width, img2->height, img2->widthStep, (unsigned char*)(img2->imageData));
	 //将数组b的数据写入
	 WriteImageData(b, (img2->height), (img2->width),(img2->widthStep), (unsigned char*)(img2->imageData));
	cvShowImage("Image", img2);
	cvWaitKey(0); //等待按键

	cvDestroyWindow("Image");//销毁窗口
	cvReleaseImage(&img); //释放图像
	cvReleaseImage(&img2); //释放图像
    // 释放二维数组a和b的空间
	 delete []a;
	 delete[]b;
	return 0;
}