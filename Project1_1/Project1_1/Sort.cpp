//                    _____DO_AN_1: LAP TRINH_____                    
//                       _____OCTOBER 2015_____
//
//                SINH VIEN THUC HIEN: NGUYEN VAN TU
//                MSSV: 20136800
//                LOP:  CN_CNTT_01_K58_BKHN
//                GIANG VIEN HUONG DAN: TS. PHAM DANG HAI

/******************  BAI_1: CAC THUAT TOAN SAP XEP  ******************/

//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;
int Length;
int *Array;
/***********************  _KHAI_BAO_CAC_HAM_  ***********************/
void Allocate(int n);
void Swap(int &a, int &b);
void Import_Keyboard();
void Import_File(const char* filename = "in.txt");
void Import_Random();
void Display_Array();
void Export_File(const char* filename = "out.txt");
void Bubble_Sort(int Arr[], int N);
void Selection_Sort(int Arr[], int N);
void Insertion_Sort(int Arr[], int N);
void Shell_Sort(int Arr[], int N);
void Quick_Sort(int Arr[], int left, int right);
void Merge_Sort(int Arr[], int low, int high);
void Merge(int Arr[], int low, int high, int mid);
void Heap_Sort(int Arr[], int N);

/***************************  _HAM_CHINH_  ***************************/

int main()
{

	cout << "---------------------------  BAI TOAN SAP XEP DAY SO  ---------------------------" << endl;
	cout << "                               -------------------                               \n" << endl;
	cout << "	CHON PHUONG THUC NHAP DAY SO: \n" << endl;
	cout << "	   1. Chon day so tu file" << endl;
	cout << "	   2. Tao day so ngau nhien" << endl;
	cout << "	   3. Nhap day so tu ban phim" << endl;
	cout << "\n	LUA CHON: "; int chon; cin >> chon;

	switch (chon)
	{
	case 1:
		Import_File();
		break;
	case 2:
		Import_Random();
		break;
	case 3:
		Import_Keyboard();
		break;

	default:
		break;
	}
	Array;
	Length;
	clock_t start, end;
	Export_File();

	cout << "\n-------------------------   Day so truoc khi sap xep   -------------------------" << endl;
	Display_Array();
	cout << "\n---------------------------  CAC THUAT TOAN  SAP XEP  ---------------------------" << endl;
	cout << setiosflags(ios::showpoint) << setprecision(3);
	cout.setf(ios::fixed);
	//INSERTION_SORT
	start = clock();
	Insertion_Sort(Array, Length);
	end = clock();
	cout << "\n	INSERTION_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//QUICK_SORT
	start = clock();
	Quick_Sort(Array, 0, Length - 1);
	end = clock();
	cout << "\n	QUICK_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//SHELL_SORT
	start = clock();
	Shell_Sort(Array, Length);
	end = clock();
	cout << "\n	SHELL_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//HEAP_SORT
	start = clock();
	Heap_Sort(Array, Length);
	end = clock();
	cout << "\n	HEAP_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//SELECTION_SORT
	start = clock();
	Selection_Sort(Array, Length);
	end = clock();
	cout << "\n	SELECTION_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//MERGE_SORT
	start = clock();
	Merge_Sort(Array, 0, Length - 1);
	end = clock();
	cout << "\n	MERGE_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();
	//BUBBLE_SORT
	start = clock();
	Bubble_Sort(Array, Length);
	end = clock();
	cout << "\n	BUBBLE_SORT: " << endl;
	cout << "	Thoi gian thuc hien thuat toan: " << ((float)(end - start) / CLOCKS_PER_SEC) * 1000 << " ms " << endl;
	Display_Array();

	cout << endl;
	cout << "---------------------------     KET THUC BAI TOAN     ---------------------------" << endl;

	delete[]Array;
	getch();
	return 0;
}

/************************  _CAC_HAM__HO_TRO_  ************************/
/* Ham cap phat bo nho */
void Allocate(int n)
{
	Array = new int[n];
	Length = n;
}
/* Ham hoan doi vi tri 2 so nguyen */
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

/* Ham luu tru day so can sap xep vao mang */
void Import_Keyboard()
{
	cout << "\n	NHAP SO PHAN TU CUA DAY SO: ";
	cin >> Length;
	Allocate(Length);
	cout << "\n	NHAP " << Length << " SO NGUYEN TU BAN PHIM: ";
	for (int i = 0; i < Length; i++)
	{
		cin >> Array[i];
	}
}
void Import_File(const char* filename)
{
	ifstream input(filename);
	int i;
	input >> Length;
	Allocate(Length);
	for (i = 0; i < Length; i++)
	{
		input >> Array[i];
	}
	cout << "\n	SO PHAN TU CUA DAY SO LA: " << Length << endl;
}
void Import_Random()
{
	int i;
	cout << "\n	NHAP SO PHAN TU CUA DAY SO: ";
	cin >> Length;
	Allocate(Length);
	srand(time(0));
	for (i = 0; i < Length; i++)
	{
		Array[i] = rand() % 1000;
	}
}
void Display_Array()
{
	int i;
	cout << endl;
	for (i = 0; i<Length; i++)
	{
		cout << setw(4) << Array[i];
		if (i % 20 == 19)
			cout << endl;
	}
	cout << endl;
}
void Export_File(const char* filename)
{
	ofstream outp(filename);
	int i;
	outp << Length << endl;
	for (i = 0; i<Length; i++)
	{
		outp << setw(4) << Array[i];
		if (i % 20 == 19)
			outp << endl;
	}
	outp << endl;
	outp.close();
}

/* Ham hien thi mang chua day so da sap xep */

/************************  _CAC_HAM_SAP_XEP_  *************************/

/* Sap xep noi bot */
// Arr la mang chua day so can sap xep
// N la so phan tu cua day so
void Bubble_Sort(int Arr[], int N)
{
	int i, j;
	for (i = (N - 1); i >= 0; i--)
	{
		for (j = 1; j <= i; j++)
		{
			if (Arr[j - 1] > Arr[j])
				Swap(Arr[j - 1], Arr[j]);
		}
	}
}
/* Sap xep chon */
// Arr la mang chua day so can sap xep
// N la so phan tu cua day so
void Selection_Sort(int Arr[], int N)
{
	int i, j, min;
	for (i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
		if (Arr[j] < Arr[min]) min = j;
		Swap(Arr[i], Arr[min]);
	}
}
/* Sap xep chen */
// Arr la mang chua day so can sap xep
// N la so phan tu cua day so
void Insertion_Sort(int Arr[], int N) 
{
	int i, j, tmp;
	for (i = 1; i < N; i++) 
	{
		j = i;
		while (j > 0 && Arr[j - 1] > Arr[j]) 
		{
			Swap(Arr[j - 1], Arr[j]);
			j--;
		}
	}
}

// Arr la mang chua day so can sap xep
// N la so phan tu cua day so
void Shell_Sort(int Arr[], int N)
{
	int i, j;
	for (int mid = N / 2; mid > 0; mid /= 2)
	{
		for (i = mid; i < N; ++i)
		{
			int temp = Arr[i];
			for (j = i; j >= mid && temp < Arr[j - mid]; j -= mid)
			{
				Arr[j] = Arr[j - mid];
			}
			Arr[j] = temp;
		}
	}

}
/* Sap xep nhanh */
void Quick_Sort(int Arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = Arr[(left + right) / 2];

	/* phan doan nho ra */
	while (i <= j) {
		while (Arr[i] < pivot)
			i++;
		while (Arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* goi lai ham  */
	if (left < j)
		Quick_Sort(Arr, left, j);
	if (i < right)
		Quick_Sort(Arr, i, right);
}
/* Sap xep vun dong */
void Max_Heapify(int Arr[], int i, int L)
{
	int left, right, largest, loc;
	left = 2 * i;
	right = (2 * i + 1);
	if ((left <= L) && Arr[left]>Arr[i])
		largest = left;
	else
		largest = i;
	if ((right <= L) && (Arr[right]>Arr[largest]))
		largest = right;
	if (largest != i)
	{
		loc = Arr[i];
		Arr[i] = Arr[largest];
		Arr[largest] = loc;
		Max_Heapify(Arr, largest, L);
	}
}
void Build_Max_Heap(int Arr[], int L)
{
	for (int k = L / 2; k >= 1; k--)
	{
		Max_Heapify(Arr, k, L);
	}
}
void Heap_Sort(int Arr[], int N)
{
	int L = N - 1;
	Build_Max_Heap(Arr, L);
	int i, temp;
	for (i = L; i >= 2; i--)
	{
		temp = Arr[i];
		Arr[i] = Arr[1];
		Arr[1] = temp;
		Max_Heapify(Arr, 1, i - 1);
	}
}
/* sap xep tron */
void Merge_Sort(int Arr[], int low, int high)
{
	int mid;
	if (low<high)
	{
		mid = (low + high) / 2;
		Merge_Sort(Arr, low, mid);
		Merge_Sort(Arr, mid + 1, high);
		Merge(Arr, low, high, mid);
	}
	return;
}
void Merge(int Arr[], int low, int high, int mid)
{
	int i, j, k, c[50000];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (Arr[i] < Arr[j])
		{
			c[k] = Arr[i]; k++; i++;
		}
		else
		{
			c[k] = Arr[j]; k++; i++;
		}
	}
	while (i <= mid)
	{
		c[k] = Arr[i]; k++; i++;
	}
	while (j <= high)
	{
		c[k] = Arr[j]; k++; j++;
	}
	for (i = low; i < k; i++)
	{
		Arr[i] = c[i];
	}
}