#ifndef FILTER_H
#define FILTER_H

#include "Image.h"

class Filter
{
public:
	Filter(int size); //���캯��
	virtual ~Filter(); //��������;

	virtual Matrix Filtering(const Matrix &input) = 0;  //�˲����������麯����;

protected:
	int filterSize;
};

#endif
