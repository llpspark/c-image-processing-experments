#include<iostream>
using namespace std;
#include"Matrix.h"
#include"Image.h"
Matrix::Matrix()//无参的构造函数
{
	height=0;
	width=0;
	data=NULL;
}
Matrix::Matrix(int h,int w)//两个参数的构造函数
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
Matrix::Matrix(const Matrix &m)//拷贝构造函数
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
Matrix::~Matrix()//析构函数
{

}

Matrix& Matrix:: operator=(const Matrix &m)   //重载赋值运算符，完成对象间的拷贝；
{
	
	height=m.height;//对当前对象重新分配
	width=m.width;
	data=new double *[height];
	for(int i=0;i<height;i++)
		data[i]=new double [width];

	for(int i=0;i<height;i++)  //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=m.data[i][j];
		}
		return *this;//注意this是指向当前对象的指针，*this是当前对象
}

bool Matrix::operator==(const Matrix &m)  //判断两个Matrix对象是否相等
{
	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++)  //data 赋值
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

void Matrix:: Ones(int h, int w) // 根据参数产生h行w列的全1矩阵
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
void Matrix:: Zeros(int h, int w) // 根据参数产生h行w列的全零矩阵
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

Matrix Matrix::operator+(const Matrix &m)  //两个尺寸相同的矩阵，对应元素的数值相加
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]+m.data[i][j];
			if(temp.data[i][j]>255)
				temp.data[i][j]=255;
		}
	}
	else
		cout<<"两个矩阵尺寸不相同";
	return temp;
}

Matrix Matrix::operator-(const Matrix &m)  //两个尺寸相同的矩阵，对应元素的数值相减；
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]-m.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"两个矩阵尺寸不相同";
	return temp;
}
Matrix Matrix::operator*(const Image &img)  //两幅尺寸相同的图像，对应像素点的数值相乘；
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==img.height&&width==img.width)
	{
		for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]*img.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"两个矩阵尺寸不相同";
	return temp;
}

Matrix Matrix::operator/(const Image &img)  //两幅尺寸相同的图像，对应像素点的数值相除；
{
	Matrix temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new double *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new double [width];

	if(height==img.height&&width==img.width)
	{
		for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			temp.data[i][j]=data[i][j]/img.data[i][j];
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
	}
	else
		cout<<"两个矩阵尺寸不相同";
	return temp;
}
Matrix& Matrix::operator++()  //前置自加；
{
	
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1;
			if(data[i][j]>255)
				data[i][j]=255;
		}
		return *this;
}
Matrix& Matrix::operator--()  //前置自减；
{
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1;
			if(data[i][j]<0)
				data[i][j]=0;
		}
		return *this;
}
Matrix Matrix::operator++(int)  //后置自加；
{
	Matrix temp;
	temp=*this;
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1;
			if(temp.data[i][j]>255)
				temp.data[i][j]=255;
		}
		return temp;

}

Matrix Matrix::operator--(int)  //后置自减；
{
	Matrix temp;
	temp=*this;
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1;
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
		return temp;

}
    //所有元素加上同一数值;
Matrix operator+(Matrix &m, double num)
	{
		for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+num;
			if(m.data[i][j]>255)
				m.data[i][j]=255;
		}
		return m;
	}

//所有元素减去同一数值;
 Matrix operator-(Matrix &m, double num)
 {
	 for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]-num;
			if(m.data[i][j]<0)
				m.data[i][j]=0;
			
		}
		return m;
 }

	//所有元素乘上同一数值;
 Matrix operator*(Matrix &m, double num)
 {
	  for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]*num;
			if(m.data[i][j]>255)
				m.data[i][j]=255;
		}
		return m;
 }

 //所有元素除以同一数值;
Matrix operator/(Matrix &m, double num)
{
	 for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]/num;
		}
		return m;
}


//void Matrix:: Random(int h, int w) //产生h行w列的随机矩阵，矩阵的元素为[0,1]之间的随机实数（double类型）
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
//			r=255*double(rand())/double(RAND_MAX);//使随机生成的像素值控制在0~255范围内
//			*(*(data+i)+j)=r;
//		}
//	}
//}
//void Matrix:: Identity(int n) // 根据参数产生n行n列的单位矩阵
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
//int Matrix:: Height()const  // 获得矩阵的行数
//{
//	return height;
//}
//int Matrix::Width()const  // 获得矩阵的列数
//{
//	return width;
//}
//void Matrix::Set(int row, int col, double value) //设置第row行第col列矩阵元素的值为value
//{
//	data[row][col]=value;
//}
//void Matrix::SetAll(double value) //设置矩阵所有元素为同一值value
//{
//	for(int i=0;i<width;i++)
//		for(int j=0;j<height;j++)
//		{
//			data[i][j]=value;
//		}
//}
//Matrix Matrix:: MajorDiagonal()//求矩阵主对角线上的元素，输出一个N行1列的矩阵，N为主对角线元素的个数,假定为方阵
//{
//	int n=0,l=sqrt(double(width*width+height*height))+1;//对角线上的点满足斜率要求
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
//Matrix Matrix:: MinorDiagonal()// 求矩阵的副对角线上的元素，输出一个N行1列的矩阵，N为副对角线上元素的个数
//{
//	int n=0;//对角线上的点满足斜率要求
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
//Matrix Matrix:: Row(int n)// 返回矩阵的第n行上的元素，组出一个1行N列的矩阵输出，N为第n行上元素的个数
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
//Matrix Matrix:: Column(int n)// 返回矩阵的第n列上的元素，组出一个N行1列的矩阵输出，N为第n列上元素的个数
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
//void Matrix:: Transpose()// 将矩阵转置
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
//			/*for(int i=0;i<5;i++)        此注释检查转置是否实现
//			{
//			for(int j=0;j<10;j++)
//			{
//			std::cout<<data[i][j];
//			}
//			std::cout<<endl;
//			}
//			*/
//}
//double & Matrix:: At(int row, int col) //获取第row行第col列的矩阵元素的值
//{
//	/*static double value;----------------------------------------注意这样不可以                                 
//	value=data[row][col];
//	return value;*/
//	return data[row][col];
//}
//void Matrix::Reshape(int h, int w) //在矩阵元素总数不变的情况下，将矩阵行列变为参数给定的大小
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
//bool Matrix::IsEmpty()// 判断矩阵是否为空矩阵
//{
//	if(width==0&&height==0)
//		return true;
//	else
//		return false;
//}
//bool Matrix::IsSquare()// 判断矩阵是否为方阵
//{
//	if(width==height)
//		return true;
//	else
//		return false;
//}
//void Matrix::CopyTo(Matrix &m) // 将矩阵复制给m
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
//void  Matrix::Mul(double s) // 矩阵的每个元素都乘以参数
//{
//	for(int i=0;i<height;i++)
//		for(int j=0;j<width;j++)
//		{
//			data[i][j]=data[i][j]*s;
//		}
//}
//void Matrix::Cat(Matrix &m, int code)
//	// 将矩阵m与当前矩阵进行拼接，code代表拼接的方式：将m拼接到当前矩阵的上、下、左、右，具体例子见本大纲后面的说明
//{
//	Matrix temp;
//	CopyTo(temp);
//	switch(code)
//	{
//	case 1://m拼接到当前矩阵的上
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
//	case 2://m拼接到当前矩阵的下
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
//	case 3://m拼接到当前矩阵的左
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
//	case 4://m拼接到当前矩阵的右
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
//Matrix Add(const Matrix &m1, const Matrix &m2)// 友元函数，将矩阵m1和m2相加，结果矩阵作为函数的返回值
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
//Matrix Sub(const Matrix &m1, const Matrix &m2) // 友元函数，将矩阵m1和m2相减，结果矩阵作为函数的返回值
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
//void Swap(Matrix &a, Matrix &b) // 友元函数，交换两个矩阵
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
