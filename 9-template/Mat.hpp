#ifndef  MAT_HPP
#define  MAT_HPP

template< class T>
class Mat
{
public:
	void ALLOC();
	Mat();//�޲����Ĺ��캯�����������ж�Ϊ���Mat����
	Mat(int h, int w); //���캯�����أ�����h�У�w�е�Mat����
	Mat(int h, int w, T val); //���캯�����أ�����Ԫ�ص�ֵ��Ϊval;
	Mat(char* ImageName); //���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪMat����;
	Mat(T **m, int h, int w); //���캯�����أ��Ӷ�̬���鴴��Mat����;
	Mat(const Mat &m); //�������캯��;
	~Mat(); //��������;

	void Read(char *ImageName); //��Ӳ���ļ��ж���ͼ������;
	void Write(char *filename); //�����ݱ���Ϊͼ���ļ�;
	void Show(char *winname); //��ͼ������ʾ����;

	int Height();//�õ�����߶�
	int Height() const;//�õ�����߶�
	int Width();//�õ�������
	int Width() const;//�õ�������

	T& At(int row,int col);//��ȡĳ���ֵ
	T& At(int row,int col) const; //��ȡĳ���ֵ��const����
	void Set(int row, int col, T value); //����Ԫ��(row,col)Ϊĳֵ;
	void SetAll(T value); //��������Ԫ��Ϊͬһֵ;
	void FlipImageUpDown();
	void FlipImageLeftRight();
	void Flip(int code); //��ת; ����code��ֵ��0:���ҷ�ת��1:���·�ת;
	void Resize(int h, int w) ;//����
	void Cut(int x1,int y1,int x2,int y2);//�ü���(x1,y1)����(x2,y2)
	void Rotate(int degree);//��ת
	void Transpose(); // ת��
	void Reshape(int h, int w); //��Ԫ���������������£�����������б�Ϊ���������Ĵ�С
	bool IsEmpty();// �ж��Ƿ�Ϊ�վ���
	bool IsSquare();// �жϾ����Ƿ�Ϊ����
	Mat<T> MajorDiagonal();// �����Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���
	Mat<T> MinorDiagonal();// �󸱶Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���

	Mat<T> Row(int n);// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��1��N�еľ��������NΪ��n����Ԫ�صĸ���
	Mat<T> Column(int n);// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��N��1�еľ��������NΪ��n����Ԫ�صĸ���
	void CopyTo(Mat<T> &m); // �������Ƹ�m
	void CopyTo(Mat<T> &m)const; // �������Ƹ�m,����������
	void Cat(Mat<T> &m, int code); // ��m�뵱ǰ�������ƴ�ӣ�code����ƴ�ӵķ�ʽ
	void Square();//Mat ��data��������ƽ��������ǿ�Աȶ�

	//Mat<T>& operator=(const Mat<T> &m); //���ظ�ֵ���������ɶ��������
	Mat<T>& operator=(const Mat<T> &m); //���ظ�ֵ���������ɶ�����ǳ������
	bool operator==(const Mat<T> &m);  //�ж�����Mat�����Ƿ����
	Mat<T> operator+(const Mat<T> &m);  //��ӦԪ�ص���ֵ��ӣ�
	Mat<T> operator-(const Mat<T> &m);  //��ӦԪ�ص���ֵ�����
	Mat<T>& operator++();  //ǰ���Լӣ�
	Mat<T>& operator--();  //ǰ���Լ���
	Mat<T> operator ++(int);  //�����Լӣ�
	Mat<T> operator --(int);  //�����Լ���
	Mat<double> operator-();  // ȡ����ע��Ҫ�Ѿ�������ݹ�����[0,1]���������1��

	template< typename T>
	friend Mat<T> operator+(Mat<T> &m, T num);//����Ԫ�ؼ���ͬһ��ֵ;
	template< typename T>
	friend Mat<T> operator-(Mat<T> &m, T num); //����Ԫ�ؼ�ȥͬһ��ֵ;
	template< typename T>
	friend Mat<T> operator*(Mat<T> &m, T num); //����Ԫ�س���ͬһ��ֵ;
	template< typename T>
	friend Mat<T> operator/(Mat<T> &m, T num); //����Ԫ�س���ͬһ��ֵ;
	//���⣬����Ԫ������д��һ��T���͵�����һ��Mat����ļ�,��,��,��
	template< typename T>
	friend Mat<T> operator+( T num,Mat<T> &m);//ͬһ��ֵ��������Ԫ��;
	template< typename T>
	friend Mat<T> operator-( T num,Mat<T> &m);//ͬһ��ֵ��ȥ����Ԫ��;
	template< typename T>
	friend Mat<T> operator*( T num,Mat<T> &m);//ͬһ��ֵ��������Ԫ��;
	template< typename T>
	friend Mat<T> operator/( T num,Mat<T> &m);//ͬһ��ֵ��������Ԫ��;

	Mat<T> gray2bw(T t); //�Ը�����ֵt���ж�ֵ�������ؽ������
	Mat<double> Normalize();//������Ԫ�ص�ֵ�任��0-1��Χ�ڣ���double���͵�Mat���������ע�⣺�����������޷�����Mat<double>���͵Ķ����˽�г�Աdata����Ҫ������At�������ĳ��Ԫ�ء�
	template< typename T>
	friend void Swap(Mat<T> &a, Mat<T> &b);//ʹ����Ԫ������������Mat����

private:
	int  height;
	int  width;
	T **data;
	unsigned long *ref_cnt; // ���ü���
};


template <typename T>
void Mat<T>::ALLOC()
{
	data=new T *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new T [width];
	}


}

template <typename T>
Mat<T>::Mat() //�޲����Ĺ��캯�����������ж�Ϊ���Mat����
{
	height=0;
	width=0;
	data=NULL;
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(int h, int w) //���캯�����أ�����h�У�w�е�Mat����
{
	height=h;
	width=w;
	data=new T *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new T [width];
	}
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(int h, int w, T val) //���캯�����أ�����Ԫ�ص�ֵ��Ϊval;
{
	height=h;
	width=w;
	data=new T *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new T [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			*(*(data+i)+j)=val;
		}
	}
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(char* ImageName) //���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪMat����;
{
	Read(ImageName);
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(T **m, int h, int w) //���캯�����أ��Ӷ�̬���鴴��Mat����;
{
	height=h;
	width=w;
	data=new T *[height];
	for(int i=0;i<height;i++)
	{
		data[i]=new T [width];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<100;j++)
		{
			data[i][j]=m[i][j];
		}
	}
	ref_cnt=new unsigned long (1);
}

//template <typename T>
//Mat<T>::Mat(const Mat &m) //�������캯��,�˴�Ϊ���;
//{
//	height=m.height;
//	width=m.width;
//	data=new T *[height];
//	for(int i=0;i<height;i++)
//	{
//		data[i]=new T [width];
//	}
//	for(int i=0;i<height;i++)
//	{
//		for(int j=0;j<width;j++)
//		{
//			*(*(data+i)+j)=*(*(m.data+i)+j);
//		}
//	}
//}

template <typename T>
Mat<T>::Mat(const Mat &m) //�������캯��,�˴�Ϊǳ����;
{
	height=m.height;
	width=m.width;
	data=m.data;
	ref_cnt=m.ref_cnt;
	++(*ref_cnt);
}

template <typename T>
Mat<T>::~Mat() //��������;
{
	--(*ref_cnt);
	if(*ref_cnt==0)
	{
		for(int i=0;i<height;i++)
			delete []data[i];
		delete []data;
		delete ref_cnt;
	}
	else
		cout << "����" << *ref_cnt << "��ָ��ָ���������" << endl;

}

template <typename T>
void Mat<T>::Read(char *ImageName) //��Ӳ���ļ��ж���ͼ������;
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

template <typename T>
void Mat<T>::Write(char *filename) //�����ݱ���Ϊͼ���ļ�;
{
	IplImage *img= cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,1); ;
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int width_step=img->widthStep;
	Normalize();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<height;j++)
		{
			img_data[width_step*i+j]=(unsigned char )255*data[i][j];
		}
	}
	cvSaveImage( filename, img );
	cvReleaseImage(&img);
}

template <typename T>
void Mat<T>::Show(char *winname) //��ͼ������ʾ����;
{
	IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int width_step=img->widthStep;
	Normalize();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			img_data[width_step*i+j]=unsigned char (255*data[i][j]);
		}
	}
	cvNamedWindow( winname, CV_WINDOW_AUTOSIZE ); 
	cvShowImage( winname, img );
	cvWaitKey(0);
	cvReleaseImage( &img );
}

template <typename T>
int Mat<T>::Height()//�õ�����߶�
{
	return height;
}

template <typename T>
int Mat<T>::Height() const//�õ�����߶�
{
	return height;
}

template <typename T>
int Mat<T>::Width()//�õ�������
{
	return width;
}

template <typename T>
int Mat<T>::Width() const//�õ�������
{
	return width;
}

template <typename T>
T& Mat<T>::At(int row,int col)         //��ȡĳ���ֵ
{
	return data[row][col];
}

template <typename T>
T& Mat<T>::At(int row,int col) const  //��ȡĳ���ֵ��const����
{
	return data[row][col];
}

template <typename T>
void Mat<T>::Set(int row, int col, T value) //����Ԫ��(row,col)Ϊĳֵ;
{
	data[row][col]=value;
}

template <typename T>
void Mat<T>::SetAll(T value) //��������Ԫ��Ϊͬһֵ;
{
	for(int i=0;i<width;i++)
		for(int j=0;j<height;j++)
		{
			data[i][j]=value;
		}
}

template <typename T>
void Mat<T>::FlipImageUpDown()
{
	int p=0,q=height-1;
	T p_temp[1000];
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

template <typename T>
void Mat<T>::FlipImageLeftRight()
{
	int p=0,q=width-1;
	T p_temp[1000];
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

template <typename T>
void Mat<T>::Flip(int code) //��ת; ����code��ֵ��0:���ҷ�ת��1:���·�ת;
{
	//write your code here
	if(code==0)
		FlipImageLeftRight();
	else
		FlipImageUpDown();
}

template <typename T>
void Mat<T>::Resize(int h, int w) //����
{
	T **new_data=new T *[h];
	for(int i=0;i<h;i++)
	{
		new_data[i]=new T [w];
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
template <typename T>
void Mat<T>::Cut(int x1,int y1,int x2,int y2)//�ü���(x1,y1)����(x2,y2)
{
	int New_height=abs(y2-y1)+1;
	int New_width=abs(x2-x1)+1;
	T **new_data=new T *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new T[New_width];
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
template <typename T>
void Mat<T>::Rotate(int degree)//��ת
{
	double rx0=width*0.5;  //(rx0,ry0)Ϊ��ת���� 
	double ry0=height*0.5; 

	//��ת��ͼ����ڴ����
	int New_height=1.045*height;
	int New_width=1.045*width;
	T **new_data=new T *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new T[New_width];
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
template <typename T>
void Mat<T>::Transpose() // ת��
{
	Mat temp(width,height);
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
		{
			temp.data[j][i]=data[i][j];
		}
		height=temp.height;
		width=temp.width;
		ALLOC();
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
			{
				data[i][j]=temp.data[i][j];
			}
}
template <typename T>
void Mat<T>::Reshape(int h, int w) //��Ԫ���������������£�����������б�Ϊ���������Ĵ�С
{
	Mat temp(h,w);int num=0,J=0;
	for(int i=0,I=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			temp.data[I][J]=data[i][j];
			num++,J++;
			if(num==w)
			{
				I++;
				num=0;
				J=0;
			}

		}
	}

	height=h;
	width=w;
	ALLOC();
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]=temp.data[i][j];
		}
	}
}
template <typename T>
bool Mat<T>::IsEmpty()// �ж��Ƿ�Ϊ�վ���
{
	if(width==0&&height==0)
		return true;
	else
		return false;
}
template <typename T>
bool Mat<T>::IsSquare()// �жϾ����Ƿ�Ϊ����
{
	if(width==height)
		return true;
	else
		return false;
}
template <typename T>
Mat<T> Mat<T>::MajorDiagonal()// �����Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���
{
	int n=0,l=sqrt(double(width*width+height*height))+1;//�Խ����ϵĵ�����б��Ҫ��
	T *temp=new T [l];
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
		{
			if(i==j*(height-1)/(width-1))
			{
				temp[n]=data[i][j];
				n++;
			}		
		}
		Mat vec(n+1,1);
		for(int i=0;i<n+1;i++)
		{
			vec.Set(i,0,temp[i]);
		}
		delete []temp;
		return vec;
}
template <typename T>
Mat<T> Mat<T>::MinorDiagonal()// �󸱶Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���
{
	int n=0;//�Խ����ϵĵ�����б��Ҫ��
	T *temp=new T (width+height);
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
		{
			if(i==(-1)*j*(height-1)/(width-1)+(height-1))
			{
				temp[n]=data[i][j];
				n++;
			}		
		}
		Mat vec(n,1);
		for(int i=0;i<n;i++)
		{
			vec.Set(i,0,temp[i]);
		}
		return vec;
}
template <typename T>
Mat<T> Mat<T>::Row(int n)// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��1��N�еľ��������NΪ��n����Ԫ�صĸ���
{
	Mat vec(1,width);
	for(int i=0;i<height;i++)
		if(i==n-1)
		{
			for(int j=0;j<width;j++)
				vec.Set(0,j,data[i][j]);
		}
		return vec;
}
template <typename T>
Mat<T> Mat<T>::Column(int n)// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��N��1�еľ��������NΪ��n����Ԫ�صĸ���
{
	Mat vec(height,1);
	for(int j=0;j<width;j++)
		if(j==n-1)
		{
			for(int i=0;i<width;i++)
				vec.Set(i,0,data[i][j]);
		}
		return vec;
}

template <typename T>
void Mat<T>::CopyTo(Mat<T> &m)const // �������Ƹ�m
{
	m.width=width;
	m.height=height;
	m.data=new T *[height];
	for(int i=0;i<height;i++)
	{
		m.data[i]=new T [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			m.data[i][j]=data[i][j];
		}
	}
}
template <typename T>
void Mat<T>::CopyTo(Mat<T> &m) // �������Ƹ�m
{
	m.width=width;
	m.height=height;
	m.data=new T *[height];
	for(int i=0;i<height;i++)
	{
		m.data[i]=new T [width];
	}
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			m.data[i][j]=data[i][j];
		}
	}
}
template <typename T>
void Mat<T>::Cat(Mat<T> &m, int code) // ��m�뵱ǰ�������ƴ�ӣ�code����ƴ�ӵķ�ʽ
{
	Mat temp;
	CopyTo(temp);
	switch(code)
	{
	case 1://mƴ�ӵ���ǰ�������
		{
			data=new T *[height+m.height];
			for(int i=0;i<height+m.height;i++)
			{
				data[i]=new T [width];
			}
			for(int i=0;i<height+m.height;i++)
				for(int j=0;j<width;j++)
				{
					if(i<height)
						data[i][j]=m.data[i][j];
					else
						data[i][j]=temp.data[i-height][j];
				}
				height=height+m.height;
				break;
		}

	case 2://mƴ�ӵ���ǰ�������
		{
			data=new T *[height+m.height];
			for(int i=0;i<height+m.height;i++)
			{
				data[i]=new T [width];
			}
			for(int i=0;i<height+m.height;i++)
				for(int j=0;j<width;j++)
				{
					if(i<height)
						data[i][j]=temp.data[i][j];
					else
						data[i][j]=m.data[i-height][j];
				}
				height=height+m.height;
				break;

		}
	case 3://mƴ�ӵ���ǰ�������
		{
			data=new T *[height];
			for(int i=0;i<height;i++)
			{
				data[i]=new T [width+m.width];
			}
			for(int i=0;i<height;i++)
				for(int j=0;j<width+m.width;j++)
				{
					if(j<width)
						data[i][j]=m.data[i][j];
					else
						data[i][j]=temp.data[i][j-m.width];
				}
				width=width+m.width;
				break;

		}
	case 4://mƴ�ӵ���ǰ�������
		{
			data=new T *[height];
			for(int i=0;i<height;i++)
			{
				data[i]=new T [width+m.width];
			}
			for(int i=0;i<height;i++)
				for(int j=0;j<width+m.width;j++)
				{
					if(j<width)
						data[i][j]=temp.data[i][j];
					else
						data[i][j]=m.data[i][j-m.width];
				}
		}
		width=width+m.width;
		break;
	}

}

template <typename T>
void Mat<T>::Square()
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]*data[i][j];
		}
	}
}

//template <typename T>
//Mat<T>& Mat<T>::operator=(const Mat<T> &m��int)  //���ظ�ֵ���������ɶ����������
//{
//	height=m.height;//�Ե�ǰ�������·���
//	width=m.width;
//	data=new T *[height];
//	for(int i=0;i<height;i++)
//		data[i]=new T [width];
//
//	for(int i=0;i<height;i++)  //data ��ֵ
//		for(int j=0;j<width;j++)
//		{
//			data[i][j]=m.data[i][j];
//		}
//		return *this;//ע��this��ָ��ǰ�����ָ�룬*this�ǵ�ǰ����
//}

template <typename T>
Mat<T>& Mat<T>::operator=(const Mat<T> &m)  //���ظ�ֵ���������ɶ�����ǳ������
{
	++(*(m.ref_cnt));
	if(--(*ref_cnt)==0)
	{
		for(int i=0;i<height;i++)
			delete []data[i];
		delete []data;
		delete ref_cnt;
	}
	ref_cnt=m.ref_cnt;
	data=m.data;
	height=m.height;//�Ե�ǰ�������·���
	width=m.width;
	return *this;//ע��this��ָ��ǰ�����ָ�룬*this�ǵ�ǰ����
}


template <typename T>
bool Mat<T>::operator==(const Mat<T> &m)  //�ж�����Mat�����Ƿ����
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

template <typename T>
Mat<T> Mat<T>::operator+(const Mat<T> &m)  //��ӦԪ�ص���ֵ��ӣ�
{
	Mat temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new T *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new T [width];

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
template <typename T>
Mat<T> Mat<T>::operator-(const Mat<T> &m)  //��ӦԪ�ص���ֵ�����
{
	Mat<T> temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new T *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new T [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data ��ֵ
			for(int j=0;j<width;j++)
			{
				temp.data[i][j]=data[i][j]-m.data[i][j];
				if(temp.data[i][j]<0)
					temp.data[i][j]=0;
				//cout<<temp.data[i][j]<<endl;
			}
	}
	else
		cout<<"��������ߴ粻��ͬ";
	
				

	return temp;
}
template <typename T>
Mat<T>& Mat<T>::operator++()  //ǰ���Լӣ�
{
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1/255;
			if(data[i][j]>1)//�ٶ��Ѿ����򻯵�0~1֮��
				data[i][j]=1;
		}
		return *this;
}

template <typename T>
Mat<T>& Mat<T>::operator--()  //ǰ���Լ���
{
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1/255;
			if(data[i][j]<0)
				data[i][j]=0;
		}
		return *this;
}

template <typename T>
Mat<T> Mat<T>::operator ++(int)  //�����Լӣ�
{
	Mat temp;
	temp=*this;
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1/255;
			if(temp.data[i][j]>1)//�ٶ��Ѿ����򻯵�0~1֮��
				temp.data[i][j]=1;
		}
		return temp;
}

template <typename T>
Mat<T> Mat<T>::operator --(int)  //�����Լ���
{
	Mat temp;
	temp=*this;
	for(int i=0;i<height;i++) //data ��ֵ
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1/255;
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
		return temp;
}

template <typename T>
Mat<double> Mat<T>::operator-()  // ȡ����ע��Ҫ�Ѿ�������ݹ�����[0,1]���������1��
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			data[i][j]=1-data[i][j];
		}
	}
	return *this;
}

template <typename T>
Mat<T>operator+(Mat<T> &m, T num)//����Ԫ�ؼ���ͬһ��ֵ;
{
	for(int i=0;i<m.height;i++) 
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+double(num/255);
			if(m.data[i][j]>1)//j�ٶ��Ѿ����򻯵�0~1֮��
				m.data[i][j]=1;
		}
		return m;
}

template< typename T>
Mat<T> operator-(Mat<T> &m, T num) //����Ԫ�ؼ�ȥͬһ��ֵ;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]-double(num/255);
			if(m.data[i][j]<0)
				m.data[i][j]=0;

		}
		return m;
}
template< typename T>
Mat<T> operator*(Mat<T> &m, T num) //����Ԫ�س���ͬһ��ֵ;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]*double(num/255);
			if(m.data[i][j]>1)//j�ٶ��Ѿ����򻯵�0~1֮��
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator/(Mat<T> &m, T num) //����Ԫ�س���ͬһ��ֵ;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]/double(num/255);
		}
		return m;
}
template< typename T>
Mat<T> operator+( T num,Mat<T> &m)//ͬһ��ֵ��������Ԫ��;
{
	for(int i=0;i<m.height;i++) 
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+double(num/255);
			if(m.data[i][j]>1)//j�ٶ��Ѿ����򻯵�0~1֮��
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator-( T num,Mat<T> &m)//ͬһ��ֵ��ȥ����Ԫ��;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)-m.data[i][j];
			if(m.data[i][j]<0)
				m.data[i][j]=0;

		}
		return m;
}
template< typename T>
Mat<T> operator*( T num,Mat<T> &m)//ͬһ��ֵ��������Ԫ��;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)*m.data[i][j];
			if(m.data[i][j]>1)//j�ٶ��Ѿ����򻯵�0~1֮��
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator/( T num,Mat<T> &m)//ͬһ��ֵ��������Ԫ��;
{
	for(int i=0;i<m.height;i++) //data ��ֵ
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)/m.data[i][j];
		}
		return m;
}

template <typename T>
Mat<T>Mat<T>:: gray2bw(T t) //�Ը�����ֵt���ж�ֵ�������ؽ������
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(data[i][j]<t)
				data[i][j]=0;
			else 
				data[i][j]=1;
		}
	}
	return *this;
}
template <typename T>
Mat<double> Mat<T>::Normalize()
{
	T max=0,min=0;double scope;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(At(i,j)<min)
				min=At(i,j);
			if(At(i,j)>max)
				max=At(i,j);
		}
	}
	scope=max-min;
	Mat<double> output(height,width);
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			output.Set(i,j,double (At(i,j)-min)/double(scope));
		}
	}
	Mat<double>::ALLOC();
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			Set(i,j,output.At(i,j));
		}
	}
	return *this;
}

template <typename T>
void Swap(Mat<T> &a, Mat<T> &b)//ʹ����Ԫ������������Mat����
{
	T **temp_data=new T *[a.height];
	for(int i=0;i<a.height;i++)
	{
		temp_data[i]=new T [a.width];
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

#endif