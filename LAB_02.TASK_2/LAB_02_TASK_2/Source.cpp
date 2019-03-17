#include <iostream>
#include <time.h>  
using namespace std;

class Matrix
{
private:
	int MAT[25][25];                              
	int *M;                                     
	int *N;                                    

public:
	Matrix();

	Matrix(int m, int n);

	~Matrix();

	void GetMatrix();  

	void ShowMatrix(); 

	void GetElements(int z, int y);  

	void MultiplyingMatrixByNumber(int x);  

	void AddingMatrices(Matrix object1);   

	void SubtractionMatrices(Matrix object1, Matrix object2);

	void MultiplyingMatrices(Matrix object1, Matrix object2);   

};

int main()
{
	srand(time(NULL));   

	Matrix obj1(3, 3);      
	obj1.GetMatrix();      
	cout << "Matrix 1:" << endl;
	obj1.ShowMatrix();    

	obj1.GetElements(2, 2);   

	obj1.MultiplyingMatrixByNumber(5);   
	obj1.ShowMatrix();       
	cout << endl;

	Matrix obj2(3, 3);     
	obj2.GetMatrix();      
	cout << "Matrix 2:" << endl;
	obj2.ShowMatrix();     

	obj2.AddingMatrices(obj1);   
	obj2.ShowMatrix();  

	Matrix obj3(3, 3);
	obj3.SubtractionMatrices(obj1, obj2);;

	Matrix obj4(3, 3); 
	obj4.MultiplyingMatrices(obj1, obj2);

	system("PAUSE");                         
	return 0;         
}

Matrix::Matrix()
{
	M = new int(0); N = new int(0);
}


Matrix::Matrix(int m, int n)
{
	this->M = new int (m);
	this->N = new int (n);
}

Matrix::~Matrix()
{
	delete N;
}

void Matrix::GetMatrix()
{
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			MAT[i][j] = 1 + rand() % 10;
		}
	}
}

void Matrix::ShowMatrix()
{
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			cout << MAT[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}

void Matrix::GetElements(int z, int y) 
{
	cout << endl << "Table of elements" << endl << endl;
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			z = i;
			y = j;
			cout << "Value[" << i << "][" << j << "] = " << MAT[z][y] << endl;
		}
	}
}

void Matrix::MultiplyingMatrixByNumber(int x)
{
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			MAT[i][j] *= x;
		}
	}
	cout << endl;
	cout << endl;
	cout << "Matrix 1 * 5:" << endl;
}

void Matrix::AddingMatrices(Matrix object1)
{
	cout << endl << endl;
	cout << "Matrix 1 + Matrix 2: " << endl;
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			MAT[i][j] += object1.MAT[i][j];
		}
	}
}

void Matrix::SubtractionMatrices(Matrix object1, Matrix object2)
{
	cout << endl << endl;
	cout << "Matrix 1 - Matrix 2:" << endl;
	int Q[3][3];
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			Q[i][j] = 0;
			Q[i][j] += (object1.MAT[i][j] - object2.MAT[i][j]);
		}
	}
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			cout << Q[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}

void Matrix::MultiplyingMatrices(Matrix object1, Matrix object2)
{
	cout << endl << endl;
	cout << "Matrix 1 * Matrix 2:" << endl;
	int Q[3][3];
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			Q[i][j] = 0;
			Q[i][j] += (object1.MAT[i][j] * object2.MAT[i][j]);
		}
	}
	for (int i = 0; i < *M; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			cout << Q[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}