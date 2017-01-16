#include <iostream>
using namespace std;
#include "highgui.h"
#include "Image.h"

int main(int argc, char* argv[])
{

	//Matrix ma,mb,mc;
	//ma.Zeros(4,4);
	//mb.Ones(4,4);
	

	//mb=ma.Row(5);
	//mb=ma.Column(5);
	//ma.Transpose();
	//double c=++(ma.At(2,2));
	//ma.Reshape(2,8);
	//bool A;
	//A=ma.IsEmpty();
	//A=ma.IsSquare();
	//ma.CopyTo(mb);
	//ma.Mul(5);
	//ma.Cat(mb,4);

	//mc=Add(ma,mb);
	//mc= Sub(ma,mb);
	 //Swap(ma,mb);
	//Matrix m(16, 1);
	//for (int i = 0; i < 16; i++)
	//{
	//	m.At(i, 0) = i%256;
		//std::cout<<++(m.At(i, 0));
   	 // m.Set(i,0,i%256);
	//}
	//m.Reshape(4, 4);
	//for(int i=0;i<4;i++)        
	//		{
	//		for(int j=0;j<4;j++)
	//		{
	//		std::cout<<m.At(i,j);
	//		}
	//		std::cout<<endl;
	//		}
            
	//Image img("Fruits.jpg");
	/*Image img;
	img.Read("Images\\Fruits.jpg");*/
	//img.Write("Images\\CopeFruits.jpg");
	//img.Show("image");
	//img.Flip(0);
	//img.Show("image");
	//Image img(m);
	//img.Resize(666,666);
	//img.Show("image");
	//img.Cut(222,222,444,444);
	//img.Show("image");
	//double a=img.Mean();
	//double b=img.Variance();
	/*img.Rotate(36);
    img.Show("image");
*/


	//Matrix d = img.MajorDiagonal();
	//Image *p = new Image(d);
	//p->Show("pimage");
	//p->Reshape(30,30);
 //   p->Show("pimagereshaped");
	//delete p;
	//p = NULL;


	//Image im("Images\\Fruits.jpg");
	//im.Resize(200, 200);
	//im.Show("resized image");
	//im.Rotate(30);
	//im.Show("rotated image");

	Image img1("Images\\Fruits.jpg"); 
	img1.Show("image2");
	Image img2("Images\\word.jpg"); 
	img2.Show("image1");
	//两图片相加
	/*Image img_add(Add(img1, img2)) ;
	img_add.Show("add");*/

	//两图片相减
	Image img_sub(Sub(img1, img2));
	img_sub.Show("sub");

	//图片的转置
	//Image img3("Images\\lena.jpg");
	//img3.Show("yuantu");
	//img3.Transpose();
	//img3.Show("transpose");

	////在右边拼接图片；
	//Image img4("Images\\airplane.jpg"); 
	//Image img5("Images\\baboon.jpg");
	//img4.Cat(img5,4);
	//img4.Show("catright");
	
	return 0;
}
