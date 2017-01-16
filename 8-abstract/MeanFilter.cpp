#include"MeanFilter.h"
MeanFilter::MeanFilter(int size):Filter(size){};
MeanFilter::~MeanFilter()
{

}
Matrix MeanFilter::Filtering(const Matrix &input)  //¾ùÖµÂË²¨º¯Êı
{
	Matrix temp(input);
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