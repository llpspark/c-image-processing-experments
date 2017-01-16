#ifndef  _FILTER_HPP
#define  _FILTER_HPP

template <class T>
class Filter
{
public:
	Filter(int size); //���캯��
	virtual ~Filter(); //��������;
	virtual Mat<T> Filtering(const Mat<T> &input) = 0; //�˲����������麯����;
protected:
	int filterSize;
};

template <class T>
Filter<T>::Filter(int size):filterSize(size){};//���캯��

template <class T>
Filter<T>::~Filter(){} //��������;


//meanFilter��
template <class T>
class MeanFilter : public Filter<T>
{
public:
	MeanFilter(int size);
	virtual ~MeanFilter();
	virtual Mat<T> Filtering(const Mat<T> &input);//��ֵ�˲�����
};


//median��
template <class T>
class MedianFilter : public Filter<T>
{
public:
	MedianFilter(int size);
	virtual ~MedianFilter();
	virtual Mat<T> Filtering(const Mat<T> &input); // ��ֵ�˲�������
};

template <class T>
MeanFilter<T>::MeanFilter(int size):Filter(size){};

template <class T>
MeanFilter<T>::~MeanFilter()
{

}

template <class T>
Mat<T> MeanFilter<T>::Filtering(const Mat<T> &input)//��ֵ�˲�����
{
	//Mat<T> temp(input);����ǳ���������ڲ�������
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
Mat<T> MedianFilter<T>::Filtering(const Mat<T> &input)//��ֵ�˲�������
{
	{
		//Mat<T> temp(input);����ǳ���������ڲ�������
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
					if(i!=s)//��i��Ԫ�����k��Ԫ�ؽ���
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