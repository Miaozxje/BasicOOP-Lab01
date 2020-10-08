#include <iostream>
using namespace std;

class NgayThang
{
public:
	int dd, mm, yy;
	NgayThang(int a, int b, int c)
	{
		dd = a;
		mm = b;
		yy = c;
	}
};

class SinhVien
{
private:
	char mssv[10];
	char HoTen[100];
	int day, month, year;
	float DLT, DTH;
public:
	SinhVien();
	SinhVien(const char[]);
	SinhVien(const char[], const char[], float, float);
	SinhVien(const char[], const char[], float, float, int ,int ,int);
	SinhVien(const char[], const char[], float, float, NgayThang);
	void Xuat();
};

SinhVien::SinhVien()
{
	strcpy(mssv, "xxxxxxx");
	strcpy(HoTen, "xxxx");
	day = -1;
	month = -1;
	year = -1;
	DLT = 10;
	DTH = 10;
}

SinhVien::SinhVien(const char str[])
{
	strcpy(mssv, str);
	strcpy(HoTen, "xxxx");
	day = -1;
	month = -1;
	year = -1;
	DLT = 10;
	DTH = 10;
}

SinhVien::SinhVien(const char str[], const char Ten[], float d1, float d2)
{
	strcpy(mssv, str);
	strcpy(HoTen, Ten);
	day = -1;
	month = -1;
	year = -1;
	DLT = d1;
	DTH = d2;
}

SinhVien::SinhVien(const char str[], const char Ten[], float d1, float d2, int ngay, int thang, int nam)
{
	strcpy(mssv, str);
	strcpy(HoTen, Ten);
	day = ngay;
	month = thang;
	year = nam;
	DLT = d1;
	DTH = d2;
}

SinhVien::SinhVien(const char str[], const char Ten[], float d1, float d2, NgayThang date)
{
	strcpy(mssv, str);
	strcpy(HoTen, Ten);
	DLT = d1;
	DTH = d2;
	day = date.dd;
	month = date.mm;
	year = date.yy;
}

void SinhVien::Xuat()
{
	cout << endl << "MSSV : " << mssv << endl;
	cout << "Ho ten : " << HoTen << endl;
	cout << "Ngay sinh: ";
	if (day == -1 && month == -1 && year == -1) cout << "xx/xx/xxxx" << endl;
	else
	{
		if (day < 10) cout << '0' << day << '/'; else cout << day << '/';
		if (month < 10) cout << '0' << month << '/'; else cout << month << '/';
		cout << year << endl;
	}
	cout << "DLT : " << DLT << endl;
	cout << "DTH : " << DTH << endl;
}

void main()
{
	SinhVien s1;
	s1.Xuat();
	SinhVien s2("1363001");
	s2.Xuat();
	SinhVien s3("1363002", "Nguyen Van A",7,8.5);
	s3.Xuat();
	SinhVien s4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
	s4.Xuat();
	NgayThang n(30, 2, 1990);
	SinhVien s5("1363004", "Ngo Van C", 5, 6, n);
	s5.Xuat();
	SinhVien s6(s5);
	s6.Xuat();
}