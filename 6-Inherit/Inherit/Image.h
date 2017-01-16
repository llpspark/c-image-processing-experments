#ifndef Image_H
#define Image_H

#include "Matrix.h"

class Image : public Matrix
{
public:
	Image(); //���캯�����������ж�Ϊ���Image����
	Image(int h, int w); //���캯�����أ�����h�У�w�е�Image����
	Image(int h, int w, unsigned char val); //���캯�����أ�������ͼ������ֵ��Ϊval;
	Image(char* ImageName); //���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪImage����;
	Image(unsigned char m[][100], int n); //���캯�����أ��Ӿ�̬���鴴��Image����;
	Image(unsigned char **m, int h, int w); //���캯�����أ��Ӷ�̬���鴴��Image����;
	Image(const Matrix &m); //���캯�����أ���Matrix�������Image�����
	Image(const Image &im); //�������캯��;
	~Image(); //��������;
	void ALLOC();

	void Read(char* ImageName); //��Ӳ���ļ��ж���ͼ������;
	void Write(char* filename); //��ͼ�����ݱ���Ϊͼ���ļ�;
	void Show(char* winname); //��ʾͼ��;

	void FlipImageLeftRight();//ͼ�����ҷ�ת
	void Image::FlipImageUpDown();//ͼ�����·�ת
	void Flip(int code); //ͼ��ķ�ת; codeΪ0���ң�1 ����;
	void Resize(int h, int w); //ͼ�������Ϊ����ָ���Ĵ�С
	void Cut(int x1,int y1,int x2,int y2);//�ü���(x1,y1)����(x2,y2)��ͼ��
	void Rotate(int degree);//ͼ����ת�ĺ�������ת�Ƕ�Ϊ����Ƕȣ�
	double Mean();//����ͼ��ľ�ֵ
	double Variance();//��ͼ��ķ���

};
#endif
