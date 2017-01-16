#include <ctime>
#include "cv.h"
#include "highgui.h"
#include <windows.h>

using namespace std;

//��ȡͼ����ĳ���������ֵ���ڱ�ʵ����ֱ�ӵ���
unsigned char GetPixel(IplImage *img, int row, int col)
{
unsigned char *img_data = (unsigned char *)(img->imageData);
int width_step = img->widthStep;
return img_data[width_step * row + col];
}
//��ͼ����ĳ���������ֵ��ֵ���ڱ�ʵ����ֱ�ӵ���
void DrawPixel(IplImage *img, int row, int col, unsigned char v)
{
unsigned char *img_data = (unsigned char *)(img->imageData);
int width_step = img->widthStep;
img_data[width_step * row + col] = v;
}


// ��ͼ���������ص�����ֵ��ֵΪ����v��ֵ���������Ӧ�Ĵ���
void DrawAll(IplImage *img, int height, int width, unsigned char v)
{
    // �ڸú���������ѭ����䣬������DrawPixel��������ͼ�����е����ض���Ϊ����v��ֵ
	for(int Height =0;Height<height;Height++)
	{
		for(int Width=0;Width<width;Width++)
			DrawPixel(img, Height, Width, v);
	}
}

// ��ͼ���л���Բ�ĺ�����Բ��Ϊ(row,col)���뾶Ϊradius, Բ���ϵ�����ֵΪv���������Ӧ�Ĵ���
void DrawCircle(IplImage *img, int height, int width, int row, int col, int radius, unsigned char v)
{
    // ����ͼ�����е����ص�����꣬�Ƚ��䵽Բ�ĵľ����Ƿ񡰵��ڡ��뾶��
	// ע�⣬��Ȼ���ص��������������������ľ���Ӧ������Ϊ�����͡���ʱ����Ͱ뾶��ȣ�Ӧ��ʹ�ø��������Ƚϵ���䡣
    // ���ÿ��������ĸ������ıȽϷ������趨һ�������ʡ�����ֵ����ͼ���л���������Բ��
   // ����DrawPixel��������Ӧ�����ص���и�ֵ
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

// ��ƺ����������Ӧ�Ĵ��룬��ͼ���з��������ֵ��ȥĳ����ֵ���Ӷ��ڲ�������㡰������ʧ��Ч��ʱ����
//����GetPixel������ȡĳ���ص������ֵ
void fade(IplImage *img, int height, int width)
{
	unsigned char flag_v=1;//���flag_v
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
// ����ĺ���Ϊ�㴴��һ��OpenCV��ͼ��ͼ��Ŀ�ȣ�width���͸߶ȣ�height�������趨��
// ��ʵ���е�ͼ��Ϊ�����Σ�����Ӧ������Ϊ��ͬ����ֵ��Ҳ������Բ�İ뾶
IplImage* img = cvCreateImage(cvSize(999, 999), IPL_DEPTH_8U, 1); // IplImage��OpenCV�д洢ͼ��Ľṹ��

// ͨ������DrawAll��������ͼ���������ص�����ֵ����ֵΪ0��ȫ�ڣ�
DrawAll(img, 999, 999, 0);
// �ð�ɫ��255��������Բ��Բ�ģ�x,y���뾶r
DrawCircle(img, 999, 999, 500, 500, 499.5, 255);
cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//��������
cvShowImage("Image", img);//��ʾͼ��
cvWaitKey(0); //�ȴ���������ʼ���������


{	
// ��ʼ�����piѭ��
// �����ѭ������

    // ��������Ƶĺ�����ʹͼ�������з��������ֵ��ȥĳ���̶��ĳ������Բ�����̬�Ľ���Ч�������ͼ��ߴ��С�����ȥ����ֵӦ���ʵ���һЩ
    // ����һ�������
    // ���ݵ�������ҵ���Ӧͼ���е����ص㣬��������ֵ��ֵΪ255��
    // ���»�������Բ
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
			distance=sqrt((x-500)*(x-500)+(y-500)*(y-500));//(500,500)ΪԲ��
			if(distance<499.5)//499.5ΪԲ�뾶
				++m;
        }
        n=n+N;
		pi2=float(m)/float(n);
        residual=(pi2-pi1)*4;
        pi1=pi2;
        pi=pi1*4;
		cvShowImage("Image", img);//��ʾͼ��
        cvWaitKey(50); //��ʱ50����
		//fade(img, 999, 999 );
       // ͬʱ�ڿ���̨�����ǰ��piֵ
       cout<<"pi value is "<<pi<<endl;
    }
}
    cvDestroyWindow("Image");//���ٴ���
    cvReleaseImage(&img); //�ͷ�ͼ��
    return 0;
}