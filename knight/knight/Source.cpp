#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
#define max 10
int A[max][max]; //Mang danh dau
int B[max][max]; //Mang luu duong di
int X[8] = { -1,-2,-2,-1,1,2,2,1 };
int Y[8] = { -2,-1,1,2,2,1,-1,-2 };
int n, x, y, Dem = 0;
//Khoi tao
void Init() {
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap x = ";
	cin >> x;
	cout << "Nhap y = ";
	cin >> y;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			A[i][j] = 0;   //Tat ca cac o chua duoc danh dau
	B[x][y] = 1;      //Duong di dau tien
	A[x][y] = 1;      //Danh dau o duoc chon
}
//Xuat ket qua ra man hinh
void Out() {
	Dem++;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			printf("%3d", B[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
//Tim duong di
void Try(int i) {
	if (i > n*n)
		Out();
	else {
		for (int j = 0; j<8; j++) {
			int x1 = x + X[j];
			int y1 = y + Y[j];
			if (x1 >= 0 && x1<n && y1 >= 0 && y1<n && A[x1][y1] == 0) {
				A[x1][y1] = 1;   //danh dau o (i,j)
				B[x1][y1] = i;   //luu lai duong di
				x = x1;         //lay toa do x moi
				y = y1;         //lay toa do y moi
				Try(i + 1);      //tim duong di tiep theo
				A[x1][y1] = 0;   //phuc hoi o (i,j)
				B[x1][y1] = 0;   //xem nhu o chua di qua
				x = x1 - X[j];   //phuc hoi dinh x
				y = y1 - Y[j];   //phuc hoi dinh y
			}
		}
	}
}
//chuong trinh chinh
void main() {
	//clrscr();
	Init();
	Try(2);
	if (Dem == 0)
		cout << "Khong co duong di";
	else
		cout << "So phuong an tim duoc" << Dem;
	getch();
}