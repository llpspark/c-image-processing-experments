#ifndef Image_H
#define Image_H

#include "Mat.hpp"
template< class T>
class Image : public Mat<T>
{
public:
	Image():Mat(){} //���캯�����������ж�Ϊ���Image����
	Image(int h, int w):Mat(h,w){} //���캯�����أ�����h�У�w�е�Image����
	Image(int h, int w, unsigned char val):Mat( h,  w, val){}  //���캯�����أ�������ͼ������ֵ��Ϊval;
	Image(char* ImageName):Mat(ImageName){}//���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪImage����;

	Image(unsigned char m[][100], int n):Mat(n,100)//���캯�����أ��Ӿ�̬���鴴��Image����;
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<100;j++)
			{
				data[i][j]=m[i][j];
			}
		}
	} 
	Image(unsigned char **m, int h, int w):Matrix(h,w) //���캯�����أ��Ӷ�̬���鴴��Image����;
	{
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				data[i][j]=m[i][j];
			}
		}
	}
	//Image(const Mat &m)��Mat(m){} //���캯�����أ���Matrix�������Image�����
	Image(const Image &im); //�������캯��;
	~Image(){} //��������;
	void ALLOC()
	{
		data=new double *[height];
		for(int i=0;i<height;i++)
		{
			data[i]=new double [width];
		}
	}

	//void Read(char* ImageName) //��Ӳ���ļ��ж���ͼ������;
	//void Write(char* filename); //��ͼ�����ݱ���Ϊͼ���ļ�;
	//void Show(char* winname); //��ʾͼ��;

	Image operator-();  //��ͼ��ȡ����ÿ�����ض���1.0��
	Image gray2bw(unsigned char t); //�Ը�����ֵt��ͼ����ж�ֵ�������ؽ��ͼ�����


	//void FlipImageLeftRight();//ͼ�����ҷ�ת
	//void Image::FlipImageUpDown();//ͼ�����·�ת
	//void Flip(int code); //ͼ��ķ�ת; codeΪ0���ң�1 ����;
	//void Resize(int h, int w); //ͼ�������Ϊ����ָ���Ĵ�С
	//void Cut(int x1,int y1,int x2,int y2);//�ü���(x1,y1)����(x2,y2)��ͼ��
	//void Rotate(int degree);//ͼ����ת�ĺ�������ת�Ƕ�Ϊ����Ƕȣ�
	//double Mean();//����ͼ��ľ�ֵ
	//double Variance();//��ͼ��ķ���

};
#endif
