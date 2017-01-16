#ifndef  _FILTER_HPP
#define  _FILTER_HPP

template <class T>
class Filter
{
public:
	Filter(int size); //构造函数
	virtual ~Filter(); //析构函数;
	virtual Mat<T> Filtering(const Mat<T> &input) = 0; //滤波函数（纯虚函数）;
protected:
	int filterSize;
};

template <class T>
Filter<T>::Filter(int size):filterSize(size){};//构造函数

template <class T>
Filter<T>::~Filter(){} //析构函数;


//meanFilter类
template <class T>
class MeanFilter : public Filter<T>
{
public:
	MeanFilter(int size);
	virtual ~MeanFilter();
	virtual Mat<T> Filtering(const Mat<T> &input);//均值滤波函数
};


//median类
template <class T>
class MedianFilter : public Filter<T>
{
public:
	MedianFilter(int size);
	virtual ~MedianFilter();
	virtual Mat<T> Filtering(const Mat<T> &input); // 中值滤波器函数
};

template <class T>
MeanFilter<T>::MeanFilter(int size):Filter(size){};

template <class T>
MeanFilter<T>::~MeanFilter()
{

}

template <class T>
Mat<T> MeanFilter<T>::Filtering(const Mat<T> &input)//均值滤波函数
{
	//Mat<T> temp(input);这是浅拷贝，对于操作不行
	Mat<T> temp;
	input.CopyTo(temp);
	for(int i=filterSize/2;i<input.Height()-filterSize/2;i++)
	{
		for(int j=filterSize/2;j<input.Width()-filterSize/2;j++)
		{
			double sum=0,average;
			for(int k=i-filterSize/2;k<i+filterSize/2;k++)
			{
				for(int w=j-filterSize/2;w<j+filterSize/2;w++)
				{
					sum+=input.At(k,w);
				}
			}
			average=sum/(filterSize*filterSize);
			temp.Set(i, j, average);
		}
	}
	return temp;

}

template <class T>
MedianFilter<T>::MedianFilter(int size):Filter(size){};

template <class T>
MedianFilter<T>::~MedianFilter()
{

}

template <class T>
Mat<T> MedianFilter<T>::Filtering(const Mat<T> &input)//中值滤波器函数
{
	{
		//Mat<T> temp(input);这是浅拷贝，对于操作不行
		Mat<T> temp;
		input.CopyTo(temp);
		for(int i=filterSize/2;i<input.Height()-filterSize/2;i++)
		{
			for(int j=filterSize/2;j<input.Width()-filterSize/2;j++)
			{
				double median;int n=0;
				double *mid=new double [filterSize*filterSize];
				for(int k=i-filterSize/2;k<i+filterSize/2;k++)
				{
					for(int w=j-filterSize/2;w<j+filterSize/2;w++)
					{
						mid[n]=input.At(k,w);
						n++;
					}
				}
				int s;double num;
				for(int i=0;i<filterSize*filterSize-1;i++)
				{
					s=i;
					for(int j=i+1;j<=filterSize*filterSize-1;j++)
						if(mid[j]<mid[s])
							s=j;
					if(i!=s)//第i个元素与第k个元素交换
					{
						num=mid[s];
						mid[s]=mid[i];
						mid[i]=num;
					}
				}
				median=mid[filterSize*filterSize/2];
				temp.Set(i, j, median);
			}
		}
		return temp;
	}
}

#  endif