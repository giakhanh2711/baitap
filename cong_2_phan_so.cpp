#include <iostream>
using namespace std;

struct phanso
{
	int x, y;
};

// Ham lay vao 1 phan so
void inputFrac(phanso &f)
{
	cout << "Nhap tu so: ";
	cin >> f.x;
	cout << "Nhap mau so: ";
	cin >> f.y;
}

// Ham cong 2 phan so
void add(phanso f1, phanso f2, phanso &f)
{
	f.x = f1.x * f2.y + f1.y * f2.x;
	f.y = f1.y * f2.y;
}

// Ham tim uoc chung nho nhat
int gcd(int x, int y)
{
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	while (x != 0 && y != 0)
	{
		if (x > y) x = x % y;
		else y = y % x;
	}
	
	return x + y;
}

// Ham rut gon phan so
void rutgon(phanso &f)
{
	int ucln = gcd(f.x, f.y);
	f.x = f.x / ucln;
	f.y = f.y / ucln;
}

// Ham in ra phan so
void show(phanso f)
{
	cout << f.x << "/" << f.y;
}

int main()
{
	phanso f1, f2, f;
	
	cout << "Moi nhap phan so thu nhat" << endl;
	inputFrac(f1);
	cout << "Moi nhap phan so thu hai" << endl;
	inputFrac(f2);
	
	add(f1, f2, f);
	rutgon(f);
	
	show(f1);
	cout << " + ";
	show(f2);
	cout << " = ";
	show(f);
	
	return 0;
	
}
