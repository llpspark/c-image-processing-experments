#ifndef Matrix_H
#define Matrix_H

class Matrix
{
public:
	Matrix();
	Matrix(int h,int w);
	Matrix(int h, int w, double val);
	Matrix(const Matrix &m);
	~Matrix();

	void Zeros(int h, int w); // ���ݲ�������h��w�е�ȫ�����
	void Ones(int h, int w); // ���ݲ�������h��w�е�ȫ1����
	void Random(int h, int w); //����h��w�е�������󣬾����Ԫ��Ϊ[0,1]֮������ʵ����double���ͣ�
	void Identity(int n); // ���ݲ�������n��n�еĵ�λ����

	int Height()const;  // ��þ��������
	int Width()const;   // ��þ��������
	Matrix MajorDiagonal();// ��������Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ���Ԫ�صĸ���
	Matrix MinorDiagonal();// �����ĸ��Խ����ϵ�Ԫ�أ����һ��N��1�еľ���NΪ���Խ�����Ԫ�صĸ���
	Matrix Row(int n);// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��1��N�еľ��������NΪ��n����Ԫ�صĸ���
	Matrix Column(int n);// ���ؾ���ĵ�n���ϵ�Ԫ�أ����һ��N��1�еľ��������NΪ��n����Ԫ�صĸ���

	void Transpose(); // ������ת��

	double & At(int row, int col); //��ȡ��row�е�col�еľ���Ԫ�ص�ֵ
	void Set(int row, int col, double value); //���õ�row�е�col�о���Ԫ�ص�ֵΪvalue
	void SetAll(double value); //���þ�������Ԫ��Ϊͬһֵvalue


	void Reshape(int h, int w); //�ھ���Ԫ���������������£����������б�Ϊ���������Ĵ�С
	bool IsEmpty();// �жϾ����Ƿ�Ϊ�վ���
	bool IsSquare();// �жϾ����Ƿ�Ϊ����
	void CopyTo(Matrix &m); // �������Ƹ�m
	void Mul(double s); // �����ÿ��Ԫ�ض����Բ���
	void Cat(Matrix &m, int code); 
	// ������m�뵱ǰ�������ƴ�ӣ�code����ƴ�ӵķ�ʽ����mƴ�ӵ���ǰ������ϡ��¡����ң��������Ӽ�����ٺ����˵��

	friend Matrix Add(const Matrix &m1, const Matrix &m2); // ��Ԫ������������m1��m2��ӣ����������Ϊ�����ķ���ֵ
	friend Matrix Sub(const Matrix &m1, const Matrix &m2); // ��Ԫ������������m1��m2��������������Ϊ�����ķ���ֵ
	friend void Swap(Matrix &a, Matrix &b); // ��Ԫ������������������

protected:
	int height;
	int width;
	double **data;
};

#endif
