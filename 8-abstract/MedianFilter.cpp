#include"MedianFilter.h"
MedianFilter::MedianFilter(int size):Filter(size){};
MedianFilter::~MedianFilter()
{

}
Matrix MedianFilter::Filtering(const Matrix &input)  // 中值滤波器函数
{
	{
		Matrix temp(input);
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