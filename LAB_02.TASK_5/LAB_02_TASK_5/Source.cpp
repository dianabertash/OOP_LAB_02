#include <iostream>
#include <math.h>

using namespace std;
class Vector
{
private:
	int n = 0;
	int* vect = new int[2];


public:
	Vector() {
		cout << "\nConstructor called\n";
	}
	~Vector() {
		cout << "\nDestructor called\n";
	}
	void AddItem(int item) {
		vect[(n)++] = item;
	}

	int Get(int index) {
		return vect[index];
	}

	int GetLength() {
		return (this->n);
	}

	Vector Add(Vector other) {
		Vector result;

		for (int i = 0; i < n; i++)
		{
			result.AddItem(other.Get(i) + vect[i]);
		}
		return result;
	}

	Vector Minus(Vector other) {
		Vector result;

		for (int i = 0; i < n; i++)
		{
			result.AddItem(other.Get(i) - vect[i]);
		}
		return result;
	}

	double dovzhyna()
	{
		return sqrt(pow((vect[0]), 2) + pow((vect[1]), 2));
	}

	int skalyar(Vector other)
	{
		return(other.Get(0) * vect[0] + other.Get(1) * vect[1]);
	}



};

void main()
{

	Vector* a = new Vector();
	a->AddItem(5);
	a->AddItem(8);

	Vector* b = new Vector();
	b->AddItem(3);
	b->AddItem(4);

	Vector c = a->Add(*b);

	Vector d = a->Minus(*b);

	for (int i = 0; i < c.GetLength(); i++) {
		cout << c.Get(i) << " ";
	}
	cout << endl;

	for (int i = 0; i < d.GetLength(); i++) {
		cout << d.Get(i) << " ";
	}
	cout << endl << "Length: " << a->dovzhyna() << endl;

	cout << "Scalar: " << a->skalyar(*b) << endl;

	system("pause");

}