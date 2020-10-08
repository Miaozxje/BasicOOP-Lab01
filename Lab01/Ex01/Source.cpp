#include <iostream>
using namespace std;

class Ngay
{
private:
	int day, month, year;
public:
	Ngay();
	Ngay(int, int, int);
	Ngay(int);
	void Xuat();
	bool LeapYear(int);
	int FindDay(int, int, int&);
	void CountDay(int);
};

Ngay::Ngay()
{
	day = 1;
	month = 1;
	year = 1;
}

Ngay::Ngay(int ngay, int thang, int nam)
{
	int temp;
	if (ngay < 1 || ngay > 31) day = 1;
	else day = ngay;
	if (thang < 1 || thang > 12) month = 12;
	else month = thang;
	year = nam;
}

Ngay::Ngay(int value)
{
	int nam = 1;
	int thang = 1;
	while (true)
	{
		if (LeapYear(nam))
		{
			if (value > 366) value -= 366;
			else
			{
				day = FindDay(nam, value, thang);
				month = thang;
				year = nam;
				return;
			}
		}
		else
		{
			if (value > 365) value -= 365;
			else
			{
				day = FindDay(nam, value, thang);
				month = thang;
				year = nam;
				return;
			}
		}
		nam++;
	}
}

bool Ngay::LeapYear(int nam)
{
	if (nam % 400 == 0) return true;
	else if (nam % 100 != 0 && nam % 4 == 0) return true;
	else return false;
}

int Ngay::FindDay(int nam, int k, int & thang)
{
	int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (LeapYear(nam)) a[1] = 29;
	for (int i = 0; i < 12; i++)
	{
		if (k > a[i]) k -= a[i];
		else
		{
			thang = i + 1;
			return k + 1;
		}
	}
	return k + 1;
}

void Ngay::Xuat()
{
	cout << endl << day << '/' << month << '/' << year << endl;
}

void main()
{
	Ngay n1;
	n1.Xuat();
	Ngay n2(2, 10, 2020);
	n2.Xuat();
	Ngay n3(-10, 16, 1969);
	n3.Xuat();
	Ngay n4(1000);
	n4.Xuat();
}