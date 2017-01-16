#include "cv.h"
#include "highgui.h"
#include "ClassObject.h"

//���캯��
Image::Image()
{
	height=0;
	width=0;
	data=NULL;
}
//���캯������
Image::Image(int h, int w)
{
	height=h;
	width=w;
	data=new unsigned char *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new unsigned char [width];
	}
}

// �������ع��캯����ʵ��
Image::Image(int h, int w, unsigned char val)//���캯�����أ�������ͼ������ֵ��Ϊval;
{
	height=h;
	width=w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			*(*(data+i)+j)=val;
		}
	}
}

Image::Image(char* ImageName)//���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪImage����;
{
	IplImage *img=cvLoadImage(ImageName, CV_LOAD_IMAGE_GRAYSCALE);
	int widthstep = img->widthStep;
	height=img->height;
	width=img->width;
	char *p=img->imageData;
	data=new unsigned char *[height];
	for(int i=0;i<width;i++)
	{
		data[i]=new unsigned char [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=*(p+(widthstep*i)+j);
		}
	}
}
Image::Image(unsigned char *m, int rows, int cols) //���캯�����أ���һά��̬���鴴��Image����ͼ��������������ɺ���������������;
{
	height=rows;
	width=cols;	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			*(*(data+i)+j)=*m;
			m++;
			if(m==NULL)
				break;
		}
		if(m==NULL)
			break;
	}
}

Image::Image(unsigned char m[][100], int rows) //���캯�����أ��Ӿ�̬��ά���鴴��Image����ͼ�����������ά����ĵ�һ��ά�ȣ��ɵڶ�������rows����;
{
	height=rows;
	width=100;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<100;j++)
		{
			*(*(data+i)+j)=m[i][j];
		}
	}
}

Image::Image(unsigned char **m, int h, int w) //���캯�����أ��Ӷ�̬���飨����ָ�룩����Image����ͼ��������������ɺ���������������;
{
	height=h;
	width=w;
	m=new unsigned char * [h];
	for(int i=0;i<h;i++)
	{
		m[i]=new unsigned char [w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			*(*(data+i)+j)=*(*(m+i)+j);
		}
	}
}
//�������캯��
Image::Image(const Image &im)
{
	height=im.height;
	width=im.width;
	data=new unsigned char *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new unsigned char [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=*(*(im.data+i)+j);
		}
	}
}

//��������
Image::~Image()
{
	/*if(data!=NULL)
	{
		for(int i=0;i<height;i++)
		{
			delete []data[i];
		}
		delete []data;
	}*/

}

//��Ӳ�̶���ͼ���ļ�; 
void Image::Read(char* ImageName)
{
	IplImage* img = cvLoadImage(ImageName, CV_LOAD_IMAGE_GRAYSCALE);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;
	//��һάָ��img_dataָ����ڴ��е�ֵд���Ա������άָ��data��ָ���ڴ���
	//write your code here
	height=img->height;
	width=img->width;
	unsigned char *p=img_data;
	data=new unsigned char *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new unsigned char [width];
	}

	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=*((p+i*widthstep)+j);
		}
	}

	/*int i,j;                  //ʹ���������ȷ��
	for(i = 0; i < height; i++)
	for(j = 0; j < width; j++)

	data[i][j] = img_data[i*widthstep+j];
	*/
	cvReleaseImage(&img);
}

//����ͼ��; 
void Image::Write(char *filename)
{
	IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;

	//����Ա������άָ��data��ָ�ڴ��е�ֵд��һάָ��img_data��ָ���ڴ�
	//write your code here
	unsigned char *p = NULL;
	p = img_data;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{

			*p = *(*(data+i)+j);
			p++;
		}	
	}
	/*for(i = 0; i < height; i++)   //���鷽��
	for(j = 0; j < width; j++)
	img_data[i*widthstep+j] = data[i][j];
	*/
	cvSaveImage(filename, img);
	cvReleaseImage(&img);
}

//��ʾͼ��;
void Image::Show(char *winname)
{
	IplImage *img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;

	//��data��ָ�ڴ��е�ֵд��img_data��ָ���ڴ�
	//write your code here
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{

			*(img_data+(widthstep*i)+j) = *(*(data+i)+j);
		}	
	}

	cvNamedWindow(winname, CV_WINDOW_AUTOSIZE);//��������
	cvShowImage(winname, img);
	cvWaitKey(0);
	cvReleaseImage(&img); //�ͷ�ͼ��;
}


//��ȡͼ����ָ�����ֵ
unsigned char& Image::At(int row, int col)
{
	//write your code here
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(i==row&&j==col)
				return *(*(data+i)+j);
		}
	}
}

//��������(row,col)Ϊĳֵ;
void Image::Set(int row, int col, unsigned char value)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(i==row&&j==col)
				*(*(data+i)+j)=value;
		}
	}
}
//����ͼ��Ϊͬһֵ
void Image::SetAll(unsigned char value)
{
	//write your code here
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=value;;
		}
	}
}

//false ���ң�true ����;
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
void Image::Flip(int code) 
{
	//write your code here
	if(code==0)
		FlipImageLeftRight();
	else
		FlipImageUpDown();
}
//ͼ����С���Ŵ�
void Image::Harf()
{
	for(int i=0;i<=(height-1)/2;i++)
	{
		for(int j=0;j<=(width-1)/2;j++)
			*(*(data+i)+j)=data[i*2+1][j*2+1];
	}
	height=height/2;//ע�����������ø߿����������forѭ���󣬷���forѭ��ǰ�����data�������ٴγ���1/4.
	width=width/2;
}
void Image::Twice()
{
	int New_height=2*height;
	int New_width=2*width;
	unsigned char **new_data=new unsigned char *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new unsigned char[New_width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(new_data+2*i)+2*j)=data[i][j];
			*(*(new_data+2*i+1)+2*j)=data[i][j];
			*(*(new_data+2*i)+2*j+1)=data[i][j];
			*(*(new_data+2*i+1)+2*j+1)=data[i][j];
		}
	}
	height=New_height;
	width=New_width;
	data=new unsigned char *[height];
	for(int i=0;i<width;i++)
	{
		data[i]=new unsigned char [width];
	}
	for(int i=0;i<New_height;i++)
	{
		for(int j=0;j<New_width;j++)
		{
			*(*(data+i)+j)=*(*(new_data+i)+j);
		}
	}

	for(int i=0;i<New_height;i++)
		delete [] new_data[i];
	delete [] new_data;
}
void Image::Resize(int code)
{
	//write your code here
	if(code==0)
		Harf();
	else
		Twice();
}

//ͼ��ü��ĺ���
//֮ǰ����Խ��ԭ������forѭ���н�ͼ����к��ж�Ӧ����
void Image::Cut(int x1,int y1,int x2,int y2)//�ü���(x1,y1)����(x2,y2)��ͼ��
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


//ͼ����ת�ĺ���
void Image::Rotate()//ͼ����ת�ĺ��������������ת�Ƕ�Ϊ90�ȵ���������
{
	int new_width,new_height;
	new_height=width;
	new_width=height;
	unsigned char **new_data=new unsigned char *[new_height];
	for(int i=0;i<new_height;i++)
	{
		new_data[i]=new unsigned char [new_width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(new_data+j)+i)=*(*(data+i)+j);
		}
	}
	data=new_data;
	height=new_height;
	width=new_width;
}

void Image::Mean_Variance(float &m, float &var)//��ͼ��ľ�ֵ�ͷ�����ò������
{
	m=0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			m=*(*(data+i)+j)+m;
		}
	}
	m=m/(height*width);
	var=0;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			var=(*(*(data+i)+j)-m)*(*(*(data+i)+j)-m);
		}
	}
	var=var/(height*width);
}
//ʵ����Ԫ��������������Image���������
void Swap(Image &a, Image &b)
{
	unsigned char **temp_data=new unsigned char *[a.height];
	for(int i=0;i<a.height;i++)
	{
		temp_data[i]=new unsigned char [a.width];
	}
	//temp_data=a.data;
	for(int i=0;i<a.height;i++)
	{
		for(int j=0;j<a.width;j++)
		{
			*(*(temp_data+i)+j)=*(*(a.data+i)+j);
		}
	}
	//a.data=b.data;
	for(int i=0;i<b.height;i++)
	{
		for(int j=0;j<b.width;j++)
		{
			*(*(a.data+i)+j)=*(*(b.data+i)+j);
		}
	}
	//b.data=temp_data;
	for(int i=0;i<a.height;i++)
	{
		for(int j=0;j<a.width;j++)
		{
			*(*(b.data+i)+j)=*(*(temp_data+i)+j);
		}
	}
	for(int i=0;i<a.height;i++)
		delete [] temp_data[i];
	delete temp_data;
	int temp_height,temp_width;
	temp_height=a.height;
	temp_width=a.width;
	a.height=b.height;
	a.width=b.width;
	b.height=temp_height;
	b.width=temp_width;
}