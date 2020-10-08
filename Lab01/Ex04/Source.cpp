#include <iostream>
using namespace std;

class MangSoNguyen
{
private:
	int a[1000];
	int n;
public:
	MangSoNguyen();
	MangSoNguyen(int);
	MangSoNguyen(int[], int);
	void Xuat();
};

MangSoNguyen::MangSoNguyen()
{
	a[0] = INT_MIN;
}

MangSoNguyen::MangSoNguyen(int value)
{
	a[0] = value;
	n = 1;
}

MangSoNguyen::MangSoNguyen(int arr[], int k)
{
	n = k;
	for (int i = 0; i < k; i++)
		a[i] = arr[i];
}

void MangSoNguyen::Xuat()
{
	if (a[0] == INT_MIN) cout << "Khong ton tai mang" << endl;
	else
		for (int i = 0; i < n; i++)
			cout << "a[" << i << "] =" << a[i] << endl;
	cout << endl;
}

void main()
{
	MangSoNguyen a1;
	a1.Xuat();
	MangSoNguyen a2(5);
	a2.Xuat();
	int arr[10];
	for (int i = 0; i < 8; i++)
		arr[i] = i * i;
	MangSoNguyen a3(arr, 8);
	a3.Xuat();
	MangSoNguyen a4(a3);
	a4.Xuat();
}