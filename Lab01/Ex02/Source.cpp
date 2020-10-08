#include <iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int sec;
public:
	Time();
	Time(int);
	Time(int, int);
	Time(int, int, int);
	void Xuat();
};

Time::Time()
{
	hour = 0;
	minute = 0;
	sec = 0;
}

Time::Time(int giay)
{
	hour = 0;
	if (giay > 3600)
	{
		hour = giay / 3600;
		giay -= 3600;
	}
	if (giay < 0)
	{
		minute = 0;
		sec = 0;
	}
	else
	{
		minute = giay / 60;
		sec = giay % 60;
	}
}

Time::Time(int phut, int giay)
{
	hour = 0;
	if (giay < 0) sec = 0;
	else sec = giay % 60;
	if (phut < 0) minute = 0;
	else if (phut < 60) minute = phut;
	else
	{
		hour = phut / 60;
		minute = phut % 60;
	}
}

Time::Time(int gio, int phut, int giay)
{
	if (giay < 0) sec = 0;
	else sec = giay;
	if (phut < 0) minute = 0;
	else minute = phut;
	if (gio < 0) hour = 0;
	else hour = gio;
	if (sec >= 60)
	{
		minute += sec / 60;
		sec = sec % 60;
	}
	if (minute >= 60)
	{
		hour += minute / 60;
		minute = minute % 60;
	}
}


void Time::Xuat()
{
	if (hour < 10) cout << '0' << hour << ':'; else cout << hour << ':';
	if (minute < 10) cout << '0' << minute << ':'; else cout << minute << ':';
	if (sec < 10) cout << '0' << sec << endl; else cout << sec << endl;
}

void main()
{
	Time t1;
	t1.Xuat();
	Time t2(1212);
	t2.Xuat();
	Time t3(125,45);
	t3.Xuat();
	Time t4(12, 239, -78);
	t4.Xuat();
}