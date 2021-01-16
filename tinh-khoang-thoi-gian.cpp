#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct time
{
	int h, m, s;
};

// Ham nhap 1 thoi diem
void input1Moment(time &t)
{
	t.m = 60;
	t.s = 60;
	while(!(t.m <= 59 && t.m >= 0 && t.s >= 0 && t.s <= 59))
	{
		cout << "Nhap gio: ";
		cin >> t.h;
		cout << "Nhap phut: ";
		cin >> t.m;
		cout << "Nhap giay: ";
		cin >> t.s;
		if (!(t.m <= 59 && t.m >= 0))
		   cout << "Invalid minute. Moi nhap lai" << endl << endl;
		if (!(t.s >= 0 && t.s <= 59))
		   cout << "Invalid second. Moi nhap lai" << endl << endl;
	}
}

// Ham doi thoi diem thanh giay
long doi_thanh_giay(time t)
{
	long sec;
	sec = t.h*3600 + t.m*60 + t.s;
	return sec;
}

// Ham tinh khoang chenh lech bang giay
long chenh_lech(time t1, time t2)
{
	long interval;
	interval = doi_thanh_giay(t1) - doi_thanh_giay(t2);
	
	return fabs(interval);
}

// Ham doi giay thanh thoi diem
time doi_thanh_gio(long s)
{
	time t;
	t.h = s/3600;
	s %=3600;
	t.m = s/60;
	t.s = s%60;
	
	return t;
}

// Ham in ra thoi diem
void show_time(time t)
{
	cout << setfill('0') << setw(2) << t.h << ":"
	     << setfill('0') << setw(2) << t.m << ":" 
		 << setfill('0') << setw(2) << t.s;
}

int main()
{
	time t1, t2, t;
	
	cout << "Moi nhap thoi diem thu nhat" << endl;
	input1Moment(t1);
	cout << endl;
	cout << "Moi nhap thoi diem thu hai" << endl;
	input1Moment(t2);
	
	t = doi_thanh_gio(chenh_lech(t1, t2));
	
	cout << endl;
	cout << "Khoang thoi gian giua 2 thoi diem la: ";
	show_time(t);
	
	return 0;
}
