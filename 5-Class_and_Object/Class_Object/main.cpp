#include<iostream>
using namespace std;
#include "ClassObject.h"
#include "cv.h"
#include "highgui.h"

int main(int argc, char* argv[])
{
	int number, x,y, value;
	Image img("Fruits.jpg"); //��������
	cout<<"�밴��������ʾ����ѡ��"<<endl;
	cout<<"*********************** 1:��ʾ��ǰ�����ͼ��***********************"<<endl;
	cout<<"*********************** 2:����ǰͼ���Ϊ��Ӧͼ�񸱱���***************"<<endl;
	cout<<"*********************** 3:��ȡ��ǰͼ��ĳһ���ص��ֵ��****************"<<endl;
	cout<<"*********************** 4:��������������Ϊĳֵ������ʾ��Ӧͼ��******"<<endl;
	cout<<"*********************** 5:��ͼ���и������ص������ֵ����Ϊĳֵ��******"<<endl;
	cout<<"*********************** 6:ͼ������·�ת�����ҷ�ת��*******************"<<endl;
	cout<<"*********************** 7:ָ������ü�ͼ��***************************"<<endl;
	cout<<"*********************** 8:ͼ��ľ�ֵ�����***************************"<<endl;
	cout<<"*********************** 9:ͼ�����ת��*********************************"<<endl;
	cout<<"*********************** 10:ͼ��ķ�����********************************"<<endl;
	cout<<"*********************** 11:������ͼ������ݣ�**************************"<<endl;

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
		cout<<"��������Ҫ��ȡ���ص�����꣺";
		cin>>x>>y;
		cout<<"��Ӧ�������ֵ("<<x<<","<<y<<")��"<<int(img.At(x,y))<<endl;
		system("pause");
		break;
	case 4:
		cout<<"��������Ҫ���õ�����ֵ��0~255����";
		cin>>value;
		img.SetAll(value);
		img.Show("Image");
		cvWaitKey(0); //�ȴ�����
		break;
	case 5:
		cout<<"��������Ҫ���õ��������ص����Ӧ����ֵ���ÿո��������";
		cin>>x>>y>>value;
		img.Set(x, y, value);
		cout<<"��Ӧ�������ֵ�Ѿ�����Ϊ("<<x<<","<<y<<")��"<<int(img.At(x,y))<<endl;
		system("pause");
		break;
	case 6:
		img.Show("Image");
		cvWaitKey(0); //�ȴ�����
		cout<<"����0���ҷ�ת�����������������·�ת"<<endl;
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
		cout<<"����ü�ͼ��ĶԽ����꣬�ֱ�Ϊx1��y1,x2,y2(ע��x1<x2,y1<y2)"<<endl;
		cin>>x1>>y1>>x2>>y2;
		img.Cut(x1,y1,x2,y2);
		img.Show("Image");
		break;
	case 8:
		float m,var;
		img.Mean_Variance(m, var);
		cout<<"ͼ��ľ�ֵΪ��"<<m<<"����ֱ�Ϊ:"<<var<<endl;
		system("pause");
		break;
	case 9:
		img.Show("Image");
		cout<<"����ͼ����ʱ����ת�ĽǶȣ�90,180,270��"<<endl;
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
		cout<<"ͼ����С����0��ͼ��Ŵ�������������"<<endl;
		cin>>x;
		img.Resize(x);
		img.Show("Image");

	default:
		cout<<"��������ͼƬ��";
		Image img1("Baboon.jpg");
		Image img2("Lena.jpg");
		img1.Show("Image1");
		img2.Show("Image2");
		cout<<"������������ͼƬ��";
		Swap(img1, img2);
		img1.Show("Image1");
		img2.Show("Image2");
	}
	return 0;
}