#include<iostream>
#include<math.h>
using namespace std;
int main(int argc,char *argv[])
{
	float pi=100.00000,residual=100.00000,R=0.500000;
    float m=0.00000,n=0.00000;
    float pi1=100,pi2;
	while(fabs(residual)>0.01)
	{
        int N=1000000;
		for(int P=N;P>0;P--)
		{
			float x=0.00000,y=0.00000,distance=0.00000;
			x=float(rand())/float(RAND_MAX);
			y=float(rand())/float(RAND_MAX);
			distance=sqrt((x-0.5)*(x-0.5)+(y-0.5)*(y-0.5));
			if(distance<R)
				++m;
        }
        n=n+N;
		pi2=float(m)/float(n);
        residual=(pi2-pi1)*4;
        pi1=pi2;
        pi=pi1*4;
		
	}
	cout<<"pi value is "<<pi<<endl;
	char a;
	cin>>a;
	return a;
}