#include<iostream>
using namespace std;
#include "Image.h"
#include "cv.h"
#include"highgui.h"
//#include<math.h>
void Image::ALLOC()
{
	data=new double *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new double [width];
	}
}

//���캯�����������ж�Ϊ���Image����
Image::Image():Matrix(){}

//���캯�����أ�����h�У�w�е�Image����
Image::Image(int h, int w):Matrix(h, w){} 

//���캯�����أ�������ͼ������ֵ��Ϊval;
Image::Image(int h, int w, unsigned char val):Matrix( h,  w, val){} 

 //���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪImage����;
Image::Image(char* ImageName)
{
	 Read(ImageName);
} 

//���캯�����أ��Ӿ�̬���鴴��Image����;
Image::Image(unsigned char m[][100], int n):Matrix(n,100)//Matrix(n,100) Ϊ�����๹�캯�����û��๹�캯��
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<100;j++)
		{
			data[i][j]=m[i][j];
		}
	}
}

//���캯�����أ��Ӷ�̬���鴴��Image����;
Image::Image(unsigned char **m, int h, int w) :Matrix(h,w)
{
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]=m[i][j];
		}
	}
}

//���캯�����أ���Matrix�������Image�����
Image::Image(const Matrix &m):Matrix(m){}

//�������캯��;
Image::Image(const Image &im):Matrix(im){}

//��������;
Image::~Image()
{
	for(int i=0;i<height;i++)
		delete []data[i];
		delete []data;
}

//��Ӳ���ļ��ж���ͼ������;
void Image:: Read(char* ImageName)
{
	IplImage *img =cvLoadImage( ImageName , 0); 
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int width_step=img->widthStep;
	width=img->width;
	height=img->height;
	ALLOC();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			data[i][j]=img_data[width_step*i+j];
		}

	}
	cvReleaseImage( &img );
}
void Image:: Write(char* filename) //��ͼ�����ݱ���Ϊͼ���ļ�;
{
	IplImage *img= cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1); ;
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int width_step=img->widthStep;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<height;j++)
		{
			img_data[width_step*i+j]=(unsigned char )data[i][j];
		}
	}
	cvSaveImage( filename, img );
	cvReleaseImage(&img);
}
void Image:: Show(char* winname) //��ʾͼ��;
{
	 IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int width_step=img->widthStep;
	//ALLOC();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			img_data[width_step*i+j]=(unsigned char)data[i][j];
		}

	}
	 cvNamedWindow( winname, CV_WINDOW_AUTOSIZE ); 
	 cvShowImage( winname, img );
	 cvWaitKey(0);
	 cvReleaseImage( &img );
	
}
void Image::FlipImageLeftRight()
{
	int p=0,q=width-1;
	unsigned char p_temp[1000];
	while(p<q)   //(p!=q)���������ж�
	{
		for(int i=0;i<height;i++)
			p_temp[i]=*(*(data+i)+p);
		for(int i=0;i<height;i++)
			*(*(data+i)+p)=*(*(data+i)+q);
		for(int i=0;i<height;i++)	
			*(*(data+i)+q)=p_temp[i];
		p++;
		q--;
	}
}
void Image::FlipImageUpDown()
{
	int p=0,q=height-1;
	unsigned char p_temp[1000];
	while(p<q)   //       (p!=q)���������ж�
	{
		for(int i=0;i<width;i++)
			p_temp[i]=*(*(data+p)+i);
		for(int i=0;i<width;i++)
			*(*(data+p)+i)=*(*(data+q)+i);
		for(int i=0;i<width;i++)	
			*(*(data+q)+i)=p_temp[i];
		p++;
		q--;
	}
}
void Image:: Flip(int code)//ͼ��ķ�ת; codeΪ0���ң�1 ����;
{
	//write your code here
	if(code==0)
		FlipImageLeftRight();
	else
		FlipImageUpDown();
}

void Image:: Resize(int h, int w) //ͼ�������Ϊ����ָ���Ĵ�С
{
	double **new_data=new double *[h];
	for(int i=0;i<h;i++)
	{
		new_data[i]=new double [w];
	} 

	if  (  (0==width)||(0==height) 
		||(0==w)||(0==h)) 
		return ; 
	for  ( int  y=0;y<h;y++) 
	{ 
		for  ( int x=0;x<w;x++) 
		{ 
			int srcx=(x*width/w); 
			int srcy=(y*height/h);
			//Pixels(Dst,x,y)=Pixels(Src,srcx,srcy);
			new_data[y][x]=data[srcy][srcx];
		} 
	}

	width=w;
	height=h;
	ALLOC();

	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			
			data[i][j]=new_data[i][j];
		}
	}
	for(int i=0;i<height;i++)
	delete []new_data[i];
	delete new_data;
}
void Image:: Cut(int x1,int y1,int x2,int y2)//�ü���(x1,y1)����(x2,y2)��ͼ��
{
	int New_height=abs(y2-y1)+1;
	int New_width=abs(x2-x1)+1;
	unsigned char **new_data=new unsigned char *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new unsigned char[New_width];
	}
	for(int i=y1,w=0;i<=y2;i++,w++)
	{
		for(int j=x1,v=0;j<=x2;j++,v++)
		{
			*(*(new_data+w)+v) = *(*(data+i)+j);
		}	
	}
	//data=NULL;

	for(int i=0;i<New_height;i++)
	{
		for(int j=0;j<New_width;j++)
		{
			*(*(data+i)+j) = *(*(new_data+i)+j);
		}	
	}

	for(int i=0;i<New_height;i++)
		delete []new_data[i] ;
	delete []new_data ;

	height=New_height;
	width=New_width;
}
void Image::Rotate(int degree)//ͼ����ת�ĺ�������ת�Ƕ�Ϊ����Ƕȣ�
{
	double rx0=width*0.5;  //(rx0,ry0)Ϊ��ת���� 
	double ry0=height*0.5; 

	//��ת��ͼ����ڴ����
	int New_height=1.045*height;
	int New_width=1.045*width;
	unsigned char **new_data=new unsigned char *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new unsigned char[New_width];
	}
	//����ת��ͼ����г�ʼ��
	for(int i = 0;i <New_height;++i)  
	{  
		for(int j = 0;j < New_width;++j)  
		{  
			new_data[i][j] = 0;  
		}  
	}
	//��ԭͼ�����ز�Ϊ������ص㸳ֵ����Ӧ����ת��ͼ�����ص�
	for (int y=0;y<New_height;++y)
	{
		for (int x=0;x<New_width;++x)
		{
			int srcx=(double)((x-rx0)*cos((double)degree) - (y-ry0)*sin((double)degree) + rx0) ;
			int srcy=(double)((x-rx0)*sin((double)degree) + (y-ry0)*cos((double)degree) + ry0) ;
			if ((srcx>=0)&&(srcx<width) && (srcy>=0)&&(srcy<height))
				//Pixels(Dst,x,y)=Pixels(Src,srcx,srcy);
			*(*(new_data+y)+x) = *(*(data+srcy)+srcx);
		}
	}
	//����ת������¸�ֵ��data
	height=New_height;
	width=New_width;
	ALLOC();
	for(int i=0;i<New_height;i++)
	{
		for(int j=0;j<New_width;j++)
		{
			*(*(data+i)+j) = *(*(new_data+i)+j);
		}	
	}

	for(int i=0;i<New_height;i++)
		delete []new_data[i] ;
	delete []new_data ;
}
double Image::Mean()//����ͼ��ľ�ֵ
{
	double m=0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			m=*(*(data+i)+j)+m;
		}
	}
	m=m/(height*width);
	return m;
}
double Image::Variance()//��ͼ��ķ���
{
	double m=0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			m=*(*(data+i)+j)+m;
		}
	}
	m=m/(height*width);
	double var=0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			var=(*(*(data+i)+j)-m)*(*(*(data+i)+j)-m);
		}
	}
	var=var/(height*width);
	return var;
}