#include<iostream>
using namespace std;
#include"Matrix.h"
#include"Image.h"
Matrix::Matrix()//�޲εĹ��캯��
{
	height=0;
	width=0;
	data=NULL;
}
Matrix::Matrix(int h,int w)//���������Ĺ��캯��
{
	height=h;
	width=w;
	data=new double *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new double [width];
	}
}
Matrix::Matrix(int h, int w, double val)
{
	height=h;
	width=w;
	data=new double *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new double [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=val;
		}
	}
}
Matrix::Matrix(const Matrix &m)//�������캯��
{
	height=m.height;
	width=m.width;
	data=new double *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new double [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=*(*(m.data+i)+j);
		}
	}
}
Matrix::~Matrix()//��������
{

}

Matrix& Matrix:: operator=(const Matrix &m)   //���ظ�ֵ���������ɶ����Ŀ�����
{
	
	height=m.height;//�Ե�ǰ�������·���
	width=m.width;
	data=new double *[height];
	for(int i=0;i<height;i++)
		data[i]=new double [width];

	for(int i=0;i<height;i++)  //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=m.data[i][j];
		}
		return *this;//ע��this��ָ��ǰ�����ָ�룬*this�ǵ�ǰ����
}

bool Matrix::operator==(const Matrix &m)  //�ж�����Matrix�����Ƿ����
{
	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++)  //data ��ֵ
		for(int j=0;j<width;j++)
		{
			if(data[i][j]!=m.data[i][j])
			return false;
		}
		return true;
	}
	else 
		return false;
}

void Matrix:: Ones(int h, int w) // ���ݲ�������h��w�е�ȫ1����
{
	height=h;
	width=w;
	data=new double *[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new double [w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			*(*(data+i)+j)=1;
		}
	}
}
void Matrix:: Zeros(int h, int w) // ���ݲ�������h��w�е�ȫ�����
{
	height=h;
	width=w;
	data=new double *[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new double [w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			*(*(data+i)+j)=0;
		}
	}
}

Matrix Matrix::operator+(const Matrix &m)  //�����ߴ���ͬ�ľ��󣬶�ӦԪ�ص���ֵ���
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]+m.data[i][j];
			if(temp.data[i][j]>255)
				temp.data[i][j]=255;
		}
	}
	else
		cout<<"��������ߴ粻��ͬ";
	return temp;
}

Matrix Matrix::operator-(const Matrix &m)  //�����ߴ���ͬ�ľ��󣬶�ӦԪ�ص���ֵ�����
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]-m.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"��������ߴ粻��ͬ";
	return temp;
}
Matrix Matrix::operator*(const Image &img)  //�����ߴ���ͬ��ͼ�񣬶�Ӧ���ص����ֵ��ˣ�
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==img.height&&width==img.width)
	{
		for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]*img.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"��������ߴ粻��ͬ";
	return temp;
}

Matrix Matrix::operator/(const Image &img)  //�����ߴ���ͬ��ͼ�񣬶�Ӧ���ص����ֵ�����
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==img.height&&width==img.width)
	{
		for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]/img.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"��������ߴ粻��ͬ";
	return temp;
}
Matrix& Matrix::operator++()  //ǰ���Լӣ�
{
	
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1;
			if(data[i][j]>255)
				data[i][j]=255;
		}
		return *this;
}
Matrix& Matrix::operator--()  //ǰ���Լ���
{
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1;
			if(data[i][j]<0)
				data[i][j]=0;
		}
		return *this;
}
Matrix Matrix::operator++(int)  //�����Լӣ�
{
	Matrix temp;
	temp=*this;
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1;
			if(temp.data[i][j]>255)
				temp.data[i][j]=255;
		}
		return temp;

}

Matrix Matrix::operator--(int)  //�����Լ���
{
	Matrix temp;
	temp=*this;
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1;
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
		return temp;

}
    //����Ԫ�ؼ���ͬһ��ֵ;
Matrix operator+(Matrix &m, double num)
	{
		for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+num;
			if(m.data[i][j]>255)
				m.data[i][j]=255;
		}
		return m;
	}

//����Ԫ�ؼ�ȥͬһ��ֵ;
 Matrix operator-(Matrix &m, double num)
 {
	 for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]-num;
			if(m.data[i][j]<0)
				m.data[i][j]=0;
			
		}
		return m;
 }

	//����Ԫ�س���ͬһ��ֵ;
 Matrix operator*(Matrix &m, double num)
 {
	  for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]*num;
			if(m.data[i][j]>255)
				m.data[i][j]=255;
		}
		return m;
 }

 //����Ԫ�س���ͬһ��ֵ;
Matrix operator/(Matrix &m, double num)
{
	 for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]/num;
		}
		return m;
}


//void Matrix:: Random(int h, int w) //����h��w�е�������󣬾����Ԫ��Ϊ[0,1]֮������ʵ����double���ͣ�
//{
//	height=h;
//	width=w;
//	double r;
//	data=new double *[h];
//	for(int i=0;i<h;i++)
//	{
//		data[i]=new double [w];
//	}
//	for(int i=0;i<h;i++)
//	{
//		for(int j=0;j<w;j++)
//		{
//			r=255*double(rand())/double(RAND_MAX);//ʹ������ɵ�����ֵ������0~255��Χ��
//			*(*(data+i)+j)=r;
//		}
//	}
//}
//void Matrix:: Identity(int n) // ���ݲ�������n��n�еĵ�λ����
//{
//	height=n;
//	width=n;
//	data=new double *[n];
//	for(int i=0;i<n;i++)
//	{
//		data[i]=new double [n];
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			*(*(data+i)+j)=1;
//		}
//	}
//}
//int Matrix:: Height()const  // ��þ��������
//{
//	return height;
//}
//int Matrix::Width()const  // ��þ��������
//{
//	return width;
//}
//void Matrix::Set(int row, int col, double value) //���õ�row�е�col�о���Ԫ�ص�ֵΪvalue
//{
//	data[row][col]=value;
//}
//void Matrix::SetAll(double value) //���þ�������Ԫ��Ϊͬһֵvalue
//{
//	for(int i=0;i<width;i++)
//		for(int j=0;j<height;j++)
//		{
//			data[i][j]=value;
//		}
//}
//Matrix Matrix:: MajorDiagonal()//��������Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ���Ԫ�صĸ���,�ٶ�Ϊ����
//{
//	int n=0,l=sqrt(double(width*width+height*height))+1;//�Խ����ϵĵ�����б��Ҫ��
//	double *temp=new double [l];
//	for(int i=0;i<height;i++)
//		for(int j=0;j<width;j++)
//		{
//			if(i==j*(height-1)/(width-1))
//			{
//				temp[n]=data[i][j];
//				n++;
//			}		
//		}
//		Matrix vec(n+1,1);
//		for(int i=0;i<n+1;i++)
//		{
//			vec.Set(i,0,temp[i]);
//		}
//		delete []temp;
//		return vec;
//}
//Matrix Matrix:: MinorDiagonal()// �����ĸ��Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���
//{
//	int n=0;//�Խ����ϵĵ�����б��Ҫ��
//	double *temp=new double (width+height);
//	for(int i=0;i<height;i++)
//		for(int j=0;j<width;j++)
//		{
//			if(i==(-1)*j*(height-1)/(width-1)+(height-1))
//			{
//				temp[n]=data[i][j];
//				n++;
//			}		
//		}
//		Matrix vec(n,1);
//		for(int i=0;i<n;i++)
//		{
//			vec.Set(i,0,temp[i]);
//		}
//		return vec;
//}
//Matrix Matrix:: Row(int n)// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��1��N�еľ��������NΪ��n����Ԫ�صĸ���
//{
//	Matrix vec(1,width);
//	for(int i=0;i<height;i++)
//		if(i==n-1)
//		{
//			for(int j=0;j<width;j++)
//				vec.Set(0,j,data[i][j]);
//		}
//		/*for(int i=0;i<10;i++)
//		std::cout<<vec.data[0][i]<<std::endl;*/
//		return vec;
//}
//Matrix Matrix:: Column(int n)// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��N��1�еľ��������NΪ��n����Ԫ�صĸ���
//{
//	Matrix vec(height,1);
//	for(int j=0;j<width;j++)
//		if(j==n-1)
//		{
//			for(int i=0;i<width;i++)
//				vec.Set(i,0,data[i][j]);
//		}
//		return vec;
//}
//void Matrix:: Transpose()// ������ת��
//{
//	Matrix temp(width,height);
//	for(int i=0;i<height;i++)
//		for(int j=0;j<width;j++)
//		{
//			temp.data[j][i]=data[i][j];
//		}
//		height=temp.height;
//		width=temp.width;
//		for(int i=0;i<height;i++)
//			for(int j=0;j<width;j++)
//			{
//				data[i][j]=temp.data[i][j];
//			}
//
//			/*for(int i=0;i<5;i++)        ��ע�ͼ��ת���Ƿ�ʵ��
//			{
//			for(int j=0;j<10;j++)
//			{
//			std::cout<<data[i][j];
//			}
//			std::cout<<endl;
//			}
//			*/
//}
//double & Matrix:: At(int row, int col) //��ȡ��row�е�col�еľ���Ԫ�ص�ֵ
//{
//	/*static double value;----------------------------------------ע������������                                 
//	value=data[row][col];
//	return value;*/
//	return data[row][col];
//}
//void Matrix::Reshape(int h, int w) //�ھ���Ԫ���������������£����������б�Ϊ���������Ĵ�С
//{
//	Matrix temp(h,w);int num=0,J=0;
//	for(int i=0,I=0;i<height;i++)
//	{
//		for(int j=0;j<width;j++)
//		{
//			temp.data[I][J]=data[i][j];
//			num++,J++;
//			if(num==w)
//			{
//				I++;
//				num=0;
//				J=0;
//			}
//
//		}
//	}
//
//	height=h;
//	width=w;
//	for(int i=0;i<h;i++)
//	{
//		for(int j=0;j<w;j++)
//		{
//			data[i][j]=temp.data[i][j];
//		}
//	}
//}
//bool Matrix::IsEmpty()// �жϾ����Ƿ�Ϊ�վ���
//{
//	if(width==0&&height==0)
//		return true;
//	else
//		return false;
//}
//bool Matrix::IsSquare()// �жϾ����Ƿ�Ϊ����
//{
//	if(width==height)
//		return true;
//	else
//		return false;
//}
//void Matrix::CopyTo(Matrix &m) // �������Ƹ�m
//{
//	m.width=width;
//	m.height=height;
//	m.data=new double *[height];
//	for(int i=0;i<height;i++)
//	{
//		m.data[i]=new double [width];
//	}
//	for(int i=0;i<height;i++)
//	{
//		for(int j=0;j<width;j++)
//		{
//			m.data[i][j]=data[i][j];
//		}
//	}
//}
//void  Matrix::Mul(double s) // �����ÿ��Ԫ�ض����Բ���
//{
//	for(int i=0;i<height;i++)
//		for(int j=0;j<width;j++)
//		{
//			data[i][j]=data[i][j]*s;
//		}
//}
//void Matrix::Cat(Matrix &m, int code)
//	// ������m�뵱ǰ�������ƴ�ӣ�code����ƴ�ӵķ�ʽ����mƴ�ӵ���ǰ������ϡ��¡����ң��������Ӽ�����ٺ����˵��
//{
//	Matrix temp;
//	CopyTo(temp);
//	switch(code)
//	{
//	case 1://mƴ�ӵ���ǰ�������
//	{
//		data=new double *[height+m.height];
//		for(int i=0;i<height+m.height;i++)
//		{
//			data[i]=new double [width];
//		}
//		for(int i=0;i<height+m.height;i++)
//			for(int j=0;j<width;j++)
//			{
//				if(i<height)
//					data[i][j]=m.data[i][j];
//				else
//					data[i][j]=temp.data[i-height][j];
//			}
//			height=height+m.height;
//			break;
//	}
//
//	case 2://mƴ�ӵ���ǰ�������
//	{
//		data=new double *[height+m.height];
//		for(int i=0;i<height+m.height;i++)
//		{
//			data[i]=new double [width];
//		}
//		for(int i=0;i<height+m.height;i++)
//			for(int j=0;j<width;j++)
//			{
//				if(i<height)
//					data[i][j]=temp.data[i][j];
//				else
//					data[i][j]=m.data[i-height][j];
//			}
//			height=height+m.height;
//			break;
//
//	}
//	case 3://mƴ�ӵ���ǰ�������
//	{
//		data=new double *[height];
//		for(int i=0;i<height;i++)
//		{
//			data[i]=new double [width+m.width];
//		}
//		for(int i=0;i<height;i++)
//			for(int j=0;j<width+m.width;j++)
//			{
//				if(j<width)
//					data[i][j]=m.data[i][j];
//				else
//					data[i][j]=temp.data[i][j-m.width];
//			}
//			width=width+m.width;
//			break;
//
//	}
//	case 4://mƴ�ӵ���ǰ�������
//	{
//		data=new double *[height];
//		for(int i=0;i<height;i++)
//		{
//			data[i]=new double [width+m.width];
//		}
//		for(int i=0;i<height;i++)
//			for(int j=0;j<width+m.width;j++)
//			{
//				if(j<width)
//					data[i][j]=temp.data[i][j];
//				else
//					data[i][j]=m.data[i][j-m.width];
//			}
//	}
//	width=width+m.width;
//	break;
//	}
//	
//}
//Matrix Add(const Matrix &m1, const Matrix &m2)// ��Ԫ������������m1��m2��ӣ����������Ϊ�����ķ���ֵ
//{
//	Matrix m(m1);
//	for(int i=0;i<m1.height;i++)
//	{
//		for(int j=0;j<m1.width;j++)
//		{
//			m.data[i][j]=m1.data[i][j]+m2.data[i][j];
//			if(m.data[i][j]>255)
//				m.data[i][j]=255;
//		}
//	}
//	return m;
//}
//Matrix Sub(const Matrix &m1, const Matrix &m2) // ��Ԫ������������m1��m2��������������Ϊ�����ķ���ֵ
//{
//	Matrix m(m1);
//	for(int i=0;i<m1.height;i++)
//	{
//		for(int j=0;j<m1.width;j++)
//		{
//			m.data[i][j]=m1.data[i][j]-m2.data[i][j];
//			if(m.data[i][j]<0)
//				m.data[i][j]=0;
//		}
//	}
//	return m;
//}
//void Swap(Matrix &a, Matrix &b) // ��Ԫ������������������
//{
//	double **temp_data=new double *[a.height];
//	for(int i=0;i<a.height;i++)
//	{
//		temp_data[i]=new double [a.width];
//	}
//	//temp_data=a.data;
//	for(int i=0;i<a.height;i++)
//	{
//		for(int j=0;j<a.width;j++)
//		{
//			*(*(temp_data+i)+j)=*(*(a.data+i)+j);
//		}
//	}
//	//a.data=b.data;
//	for(int i=0;i<b.height;i++)
//	{
//		for(int j=0;j<b.width;j++)
//		{
//			*(*(a.data+i)+j)=*(*(b.data+i)+j);
//		}
//	}
//	//b.data=temp_data;
//	for(int i=0;i<a.height;i++)
//	{
//		for(int j=0;j<a.width;j++)
//		{
//			*(*(b.data+i)+j)=*(*(temp_data+i)+j);
//		}
//	}
//	for(int i=0;i<a.height;i++)
//		delete [] temp_data[i];
//	delete temp_data;
//	int temp_height,temp_width;
//	temp_height=a.height;
//	temp_width=a.width;
//	a.height=b.height;
//	a.width=b.width;
//	b.height=temp_height;
//	b.width=temp_width;
//	for(int i=0;i<4;i++)       
//	{
//		for(int j=0;j<4;j++)
//		{
//			std::cout<<b.data[i][j];
//		}
//		std::cout<<endl;
//	}
//}
