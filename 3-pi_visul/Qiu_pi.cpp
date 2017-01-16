#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{	
	float pi=100.00000,residual=100.00000;
    float m=0.00000,n=0.00000;
    float pi1=100,pi2;
	while(fabs(residual)>0.00001)
	{
        int N=100000;
		for(int P=N;P>0;P--)
		{
			float x=0.00000,y=0.00000,distance=0.00000;
			x=float(rand())/float(RAND_MAX)*999;
			y=float(rand())/float(RAND_MAX)*999;
			//DrawPixel(img, x, y,255);
			distance=sqrt((x-500)*(x-500)+(y-500)*(y-500));//(500,500)为圆心
			if(distance<499.5)//499.5为圆半径
				++m;
        }
        n=n+N;
		pi2=float(m)/float(n);
        residual=(pi2-pi1)*4;
        pi1=pi2;
        pi=pi1*4;
       // 同时在控制台输出当前的pi值
       cout<<"pi value is "<<pi<<endl;
    }
    return 0;
}