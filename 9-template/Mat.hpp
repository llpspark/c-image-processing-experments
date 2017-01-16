#ifndef  MAT_HPP
#define  MAT_HPP

template< class T>
class Mat
{
public:
	void ALLOC();
	Mat();//无参数的构造函数，创建行列都为零的Mat对象
	Mat(int h, int w); //构造函数重载，创建h行，w列的Mat对象
	Mat(int h, int w, T val); //构造函数重载，矩阵元素的值都为val;
	Mat(char* ImageName); //构造函数重载，利用文件名从硬盘加载图像文件成为Mat对象;
	Mat(T **m, int h, int w); //构造函数重载，从动态数组创建Mat对象;
	Mat(const Mat &m); //拷贝构造函数;
	~Mat(); //析构函数;

	void Read(char *ImageName); //从硬盘文件中读入图像数据;
	void Write(char *filename); //将数据保存为图像文件;
	void Show(char *winname); //用图像来显示矩阵;

	int Height();//得到矩阵高度
	int Height() const;//得到矩阵高度
	int Width();//得到矩阵宽度
	int Width() const;//得到矩阵宽度

	T& At(int row,int col);//获取某点的值
	T& At(int row,int col) const; //获取某点的值，const重载
	void Set(int row, int col, T value); //设置元素(row,col)为某值;
	void SetAll(T value); //设置所有元素为同一值;
	void FlipImageUpDown();
	void FlipImageLeftRight();
	void Flip(int code); //翻转; 根据code的值：0:左右翻转，1:上下翻转;
	void Resize(int h, int w) ;//缩放
	void Cut(int x1,int y1,int x2,int y2);//裁剪点(x1,y1)到点(x2,y2)
	void Rotate(int degree);//旋转
	void Transpose(); // 转置
	void Reshape(int h, int w); //在元素总数不变的情况下，将矩阵的行列变为参数给定的大小
	bool IsEmpty();// 判断是否为空矩阵
	bool IsSquare();// 判断矩阵是否为方阵
	Mat<T> MajorDiagonal();// 求主对角线上的元素，输出一个N行1列的矩阵，N为主对角线上元素的个数
	Mat<T> MinorDiagonal();// 求副对角线上的元素，输出一个N行1列的矩阵，N为副对角线上元素的个数

	Mat<T> Row(int n);// 返回矩阵的第n行上的元素，组出一个1行N列的矩阵输出，N为第n行上元素的个数
	Mat<T> Column(int n);// 返回矩阵的第n列上的元素，组出一个N行1列的矩阵输出，N为第n列上元素的个数
	void CopyTo(Mat<T> &m); // 将矩阵复制给m
	void CopyTo(Mat<T> &m)const; // 将矩阵复制给m,常函数重载
	void Cat(Mat<T> &m, int code); // 将m与当前对象进行拼接，code代表拼接的方式
	void Square();//Mat 的data数据自身平方，可增强对比度

	//Mat<T>& operator=(const Mat<T> &m); //重载赋值运算符，完成对象间的深拷贝
	Mat<T>& operator=(const Mat<T> &m); //重载赋值运算符，完成对象间的浅拷贝；
	bool operator==(const Mat<T> &m);  //判断两个Mat对象是否相等
	Mat<T> operator+(const Mat<T> &m);  //对应元素的数值相加；
	Mat<T> operator-(const Mat<T> &m);  //对应元素的数值相减；
	Mat<T>& operator++();  //前置自加；
	Mat<T>& operator--();  //前置自减；
	Mat<T> operator ++(int);  //后置自加；
	Mat<T> operator --(int);  //后置自减；
	Mat<double> operator-();  // 取反；注意要把矩阵的数据规整到[0,1]区间后，再用1减

	template< typename T>
	friend Mat<T> operator+(Mat<T> &m, T num);//所有元素加上同一数值;
	template< typename T>
	friend Mat<T> operator-(Mat<T> &m, T num); //所有元素减去同一数值;
	template< typename T>
	friend Mat<T> operator*(Mat<T> &m, T num); //所有元素乘上同一数值;
	template< typename T>
	friend Mat<T> operator/(Mat<T> &m, T num); //所有元素除以同一数值;
	//另外，用友元函数再写出一个T类型的数和一个Mat对象的加,减,乘,除
	template< typename T>
	friend Mat<T> operator+( T num,Mat<T> &m);//同一数值加上所有元素;
	template< typename T>
	friend Mat<T> operator-( T num,Mat<T> &m);//同一数值减去所有元素;
	template< typename T>
	friend Mat<T> operator*( T num,Mat<T> &m);//同一数值乘以所有元素;
	template< typename T>
	friend Mat<T> operator/( T num,Mat<T> &m);//同一数值除以所有元素;

	Mat<T> gray2bw(T t); //以给定阈值t进行二值化，返回结果对象
	Mat<double> Normalize();//将矩阵元素的值变换到0-1范围内，以double类型的Mat对象输出。注意：在这个函数里，无法访问Mat<double>类型的对象的私有成员data，需要调用其At函数获得某个元素。
	template< typename T>
	friend void Swap(Mat<T> &a, Mat<T> &b);//使用友元函数交换两个Mat对象

private:
	int  height;
	int  width;
	T **data;
	unsigned long *ref_cnt; // 引用计数
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
Mat<T>::Mat() //无参数的构造函数，创建行列都为零的Mat对象
{
	height=0;
	width=0;
	data=NULL;
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(int h, int w) //构造函数重载，创建h行，w列的Mat对象
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
Mat<T>::Mat(int h, int w, T val) //构造函数重载，矩阵元素的值都为val;
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
Mat<T>::Mat(char* ImageName) //构造函数重载，利用文件名从硬盘加载图像文件成为Mat对象;
{
	Read(ImageName);
	ref_cnt=new unsigned long (1);
}

template <typename T>
Mat<T>::Mat(T **m, int h, int w) //构造函数重载，从动态数组创建Mat对象;
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
//Mat<T>::Mat(const Mat &m) //拷贝构造函数,此处为深拷贝;
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
Mat<T>::Mat(const Mat &m) //拷贝构造函数,此处为浅拷贝;
{
	height=m.height;
	width=m.width;
	data=m.data;
	ref_cnt=m.ref_cnt;
	++(*ref_cnt);
}

template <typename T>
Mat<T>::~Mat() //析构函数;
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
		cout << "还有" << *ref_cnt << "个指针指向基础对象" << endl;

}

template <typename T>
void Mat<T>::Read(char *ImageName) //从硬盘文件中读入图像数据;
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
void Mat<T>::Write(char *filename) //将数据保存为图像文件;
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
void Mat<T>::Show(char *winname) //用图像来显示矩阵;
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
int Mat<T>::Height()//得到矩阵高度
{
	return height;
}

template <typename T>
int Mat<T>::Height() const//得到矩阵高度
{
	return height;
}

template <typename T>
int Mat<T>::Width()//得到矩阵宽度
{
	return width;
}

template <typename T>
int Mat<T>::Width() const//得到矩阵宽度
{
	return width;
}

template <typename T>
T& Mat<T>::At(int row,int col)         //获取某点的值
{
	return data[row][col];
}

template <typename T>
T& Mat<T>::At(int row,int col) const  //获取某点的值，const重载
{
	return data[row][col];
}

template <typename T>
void Mat<T>::Set(int row, int col, T value) //设置元素(row,col)为某值;
{
	data[row][col]=value;
}

template <typename T>
void Mat<T>::SetAll(T value) //设置所有元素为同一值;
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
	while(p<q)   //       (p!=q)不能这样判断
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
	while(p<q)   //(p!=q)不能这样判断
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
void Mat<T>::Flip(int code) //翻转; 根据code的值：0:左右翻转，1:上下翻转;
{
	//write your code here
	if(code==0)
		FlipImageLeftRight();
	else
		FlipImageUpDown();
}

template <typename T>
void Mat<T>::Resize(int h, int w) //缩放
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
void Mat<T>::Cut(int x1,int y1,int x2,int y2)//裁剪点(x1,y1)到点(x2,y2)
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
void Mat<T>::Rotate(int degree)//旋转
{
	double rx0=width*0.5;  //(rx0,ry0)为旋转中心 
	double ry0=height*0.5; 

	//旋转后图像的内存分配
	int New_height=1.045*height;
	int New_width=1.045*width;
	T **new_data=new T *[New_height];
	for(int i=0;i<New_height;i++)
	{
		new_data[i]=new T[New_width];
	}
	//对旋转后图像进行初始化
	for(int i = 0;i <New_height;++i)  
	{  
		for(int j = 0;j < New_width;++j)  
		{  
			new_data[i][j] = 0;  
		}  
	}
	//将原图像像素不为零的像素点赋值给相应的旋转后图像像素点
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
	//将旋转后的重新赋值给data
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
void Mat<T>::Transpose() // 转置
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
void Mat<T>::Reshape(int h, int w) //在元素总数不变的情况下，将矩阵的行列变为参数给定的大小
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
bool Mat<T>::IsEmpty()// 判断是否为空矩阵
{
	if(width==0&&height==0)
		return true;
	else
		return false;
}
template <typename T>
bool Mat<T>::IsSquare()// 判断矩阵是否为方阵
{
	if(width==height)
		return true;
	else
		return false;
}
template <typename T>
Mat<T> Mat<T>::MajorDiagonal()// 求主对角线上的元素，输出一个N行1列的矩阵，N为主对角线上元素的个数
{
	int n=0,l=sqrt(double(width*width+height*height))+1;//对角线上的点满足斜率要求
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
Mat<T> Mat<T>::MinorDiagonal()// 求副对角线上的元素，输出一个N行1列的矩阵，N为副对角线上元素的个数
{
	int n=0;//对角线上的点满足斜率要求
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
Mat<T> Mat<T>::Row(int n)// 返回矩阵的第n行上的元素，组出一个1行N列的矩阵输出，N为第n行上元素的个数
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
Mat<T> Mat<T>::Column(int n)// 返回矩阵的第n列上的元素，组出一个N行1列的矩阵输出，N为第n列上元素的个数
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
void Mat<T>::CopyTo(Mat<T> &m)const // 将矩阵复制给m
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
void Mat<T>::CopyTo(Mat<T> &m) // 将矩阵复制给m
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
void Mat<T>::Cat(Mat<T> &m, int code) // 将m与当前对象进行拼接，code代表拼接的方式
{
	Mat temp;
	CopyTo(temp);
	switch(code)
	{
	case 1://m拼接到当前矩阵的上
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

	case 2://m拼接到当前矩阵的下
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
	case 3://m拼接到当前矩阵的左
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
	case 4://m拼接到当前矩阵的右
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
//Mat<T>& Mat<T>::operator=(const Mat<T> &m，int)  //重载赋值运算符，完成对象间的深拷贝；
//{
//	height=m.height;//对当前对象重新分配
//	width=m.width;
//	data=new T *[height];
//	for(int i=0;i<height;i++)
//		data[i]=new T [width];
//
//	for(int i=0;i<height;i++)  //data 赋值
//		for(int j=0;j<width;j++)
//		{
//			data[i][j]=m.data[i][j];
//		}
//		return *this;//注意this是指向当前对象的指针，*this是当前对象
//}

template <typename T>
Mat<T>& Mat<T>::operator=(const Mat<T> &m)  //重载赋值运算符，完成对象间的浅拷贝；
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
	height=m.height;//对当前对象重新分配
	width=m.width;
	return *this;//注意this是指向当前对象的指针，*this是当前对象
}


template <typename T>
bool Mat<T>::operator==(const Mat<T> &m)  //判断两个Mat对象是否相等
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

template <typename T>
Mat<T> Mat<T>::operator+(const Mat<T> &m)  //对应元素的数值相加；
{
	Mat temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new T *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new T [width];

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
template <typename T>
Mat<T> Mat<T>::operator-(const Mat<T> &m)  //对应元素的数值相减；
{
	Mat<T> temp;
	temp.height=height;
	temp.width=width;
	(temp.data)=new T *[height];
	for(int i=0;i<height;i++)
		(temp.data)[i]=new T [width];

	if(height==m.height&&width==m.width)
	{
		for(int i=0;i<height;i++) //data 赋值
			for(int j=0;j<width;j++)
			{
				temp.data[i][j]=data[i][j]-m.data[i][j];
				if(temp.data[i][j]<0)
					temp.data[i][j]=0;
				//cout<<temp.data[i][j]<<endl;
			}
	}
	else
		cout<<"两个矩阵尺寸不相同";
	
				

	return temp;
}
template <typename T>
Mat<T>& Mat<T>::operator++()  //前置自加；
{
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1/255;
			if(data[i][j]>1)//假定已经正则化到0~1之间
				data[i][j]=1;
		}
		return *this;
}

template <typename T>
Mat<T>& Mat<T>::operator--()  //前置自减；
{
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1/255;
			if(data[i][j]<0)
				data[i][j]=0;
		}
		return *this;
}

template <typename T>
Mat<T> Mat<T>::operator ++(int)  //后置自加；
{
	Mat temp;
	temp=*this;
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]+1/255;
			if(temp.data[i][j]>1)//假定已经正则化到0~1之间
				temp.data[i][j]=1;
		}
		return temp;
}

template <typename T>
Mat<T> Mat<T>::operator --(int)  //后置自减；
{
	Mat temp;
	temp=*this;
	for(int i=0;i<height;i++) //data 赋值
		for(int j=0;j<width;j++)
		{
			data[i][j]=data[i][j]-1/255;
			if(temp.data[i][j]<0)
				temp.data[i][j]=0;
		}
		return temp;
}

template <typename T>
Mat<double> Mat<T>::operator-()  // 取反；注意要把矩阵的数据规整到[0,1]区间后，再用1减
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
Mat<T>operator+(Mat<T> &m, T num)//所有元素加上同一数值;
{
	for(int i=0;i<m.height;i++) 
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+double(num/255);
			if(m.data[i][j]>1)//j假定已经正则化到0~1之间
				m.data[i][j]=1;
		}
		return m;
}

template< typename T>
Mat<T> operator-(Mat<T> &m, T num) //所有元素减去同一数值;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]-double(num/255);
			if(m.data[i][j]<0)
				m.data[i][j]=0;

		}
		return m;
}
template< typename T>
Mat<T> operator*(Mat<T> &m, T num) //所有元素乘上同一数值;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]*double(num/255);
			if(m.data[i][j]>1)//j假定已经正则化到0~1之间
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator/(Mat<T> &m, T num) //所有元素除以同一数值;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]/double(num/255);
		}
		return m;
}
template< typename T>
Mat<T> operator+( T num,Mat<T> &m)//同一数值加上所有元素;
{
	for(int i=0;i<m.height;i++) 
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=m.data[i][j]+double(num/255);
			if(m.data[i][j]>1)//j假定已经正则化到0~1之间
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator-( T num,Mat<T> &m)//同一数值减去所有元素;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)-m.data[i][j];
			if(m.data[i][j]<0)
				m.data[i][j]=0;

		}
		return m;
}
template< typename T>
Mat<T> operator*( T num,Mat<T> &m)//同一数值乘以所有元素;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)*m.data[i][j];
			if(m.data[i][j]>1)//j假定已经正则化到0~1之间
				m.data[i][j]=1;
		}
		return m;
}
template< typename T>
Mat<T> operator/( T num,Mat<T> &m)//同一数值除以所有元素;
{
	for(int i=0;i<m.height;i++) //data 赋值
		for(int j=0;j<m.width;j++)
		{
			m.data[i][j]=double(num/255)/m.data[i][j];
		}
		return m;
}

template <typename T>
Mat<T>Mat<T>:: gray2bw(T t) //以给定阈值t进行二值化，返回结果对象
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
void Swap(Mat<T> &a, Mat<T> &b)//使用友元函数交换两个Mat对象
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