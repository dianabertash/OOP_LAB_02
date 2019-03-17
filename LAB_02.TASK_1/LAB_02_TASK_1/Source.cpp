#include <iostream>
#include <cmath>

using namespace std;

class Rectangle
{
private:
	int *height;
	int *width;

public:
	Rectangle();
	Rectangle(int a, int b);
	Rectangle(const Rectangle &obj);
	~Rectangle(); 

	int GetHeight();  
	int GetWidth(); 

	void SetHeight(int a); 
	void SetWidth(int b);  

	

	void Print(void); 
	int Area(Rectangle obj); 
	int Perymetr(Rectangle obj); 
};


int main()
{
	Rectangle obj1(8, 10);
	Rectangle *obj2 = new Rectangle;
	
	cout << endl;
	cout << "GetHeight: " << obj1.GetHeight() << endl;
	cout << "GetWidth: " << obj1.GetWidth() << endl << endl;

	cout << "Object 1: "<<endl;
	obj1.Print();
	cout << "Object 2: "<<endl;
	obj2->Print();

	cout << "Area: " << obj1.Area(obj1) << endl;
	cout << "Area: " << obj1.Area(*obj2) << endl;

	cout << "Perimetr: " << obj1.Perymetr(obj1) << endl;
	cout << "Perimetr: " << obj2->Perymetr(*obj2) << endl << endl;

	cout << "Object 1: " << endl;
	obj1.SetHeight(15);
	obj1.SetWidth(8);
	obj1.Print();

	cout << "Object 2: " << endl;
	obj2->SetHeight(20);
	obj2->SetWidth(11);
	obj2->Print();

	cout << "New Area: " << obj1.Area(obj1) << endl;
	cout << "New Perimetr: " << obj1.Perymetr(obj1) << endl;
	cout << "New Perimetr: " << obj2->Perymetr(*obj2) << endl;

	
	system("pause");
	return 0;

}

Rectangle::Rectangle()
{
	height = new int(0); width = new int(0);
}

Rectangle::Rectangle(int a, int b)
{
	this->height = new int(a);
	this->width = new int (b);
}

Rectangle::Rectangle(const Rectangle &obj)
{
	height = new int(*obj.height); width = new int(*obj.width); 
}

Rectangle::~Rectangle() 
{
	delete width;
	delete height;
}

int Rectangle::GetHeight()  
{
	return *height;
}

int Rectangle::GetWidth() 
{
	return *width;
}


void Rectangle::SetHeight(int a) 
{
	if (height > 0) 
	{
		*height = a;
	}
	else
	{
		cout << " Incorrect value";
	}
}

void  Rectangle::SetWidth(int b) 
{
	if (width > 0)
	{
		*width = b;
	}
	else
	{
		cout << " Incorrect value";
	}
}


void Rectangle::Print(void)
{
	cout << "Height: " << *height << endl << "Width :" << *width << endl << endl;
}

int Rectangle::Area(Rectangle obj)
{
	return *height * *width;
}

int Rectangle::Perymetr(Rectangle obj)
{
	return (*height + *width) * 2;
}