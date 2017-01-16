#include<iostream>
#include"Filter.h"
#include"MeanFilter.h"
#include"MedianFilter.h"
void main()
{
	Image img("images\\Lena_gaussian.jpg");
	img.Show("Origin");

	Filter *filter=NULL;
	/*filter=new MeanFilter(3);
	Image img_mean;	
	img_mean=filter->Filtering(img);
	img_mean.Show("img_mean");
	delete filter;*/

	filter = new MedianFilter(5);
	Image result_median;
	result_median = filter->Filtering(img);
	result_median.Show("Median");
	delete filter;
}

