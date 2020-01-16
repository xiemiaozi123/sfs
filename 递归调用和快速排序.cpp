#include<iostream>
#include<stdio.h>
#include<stdlib.h> 
using namespace std;


void MergeSort(int a[], int left, int right);
void Merge(int c[], int d[], int n, int m, int r);
void copy(int a[], int b[], int l, int r);



//合并c[n:m]和c[m+1:r]到d[n:r]
void Merge(int c[], int d[], int n, int m, int r)
{
int i = n, j = m + 1, k = n;
while ((i <= m) && (j <= r))
{
if (c[i] <= c[j])
d[k++] = c[i++];
else
d[k++] = c[j++];
}
if (i > m)
{
for (int q = j; q <= r; q++)
d[k++] = c[q];
}
else
{
for (int q = i; q <= m; q++)
d[k++] = c[q];
}
}


void copy(int a[], int b[], int l, int r)
{
for (int i = l; i <= r; i++)
{
a[i] = b[i];
}
}


void MergeSort(int a[], int left, int right)
{
int b[200];
if (left < right)
{
int i = (left + right) / 2;
MergeSort(a, left, i);
MergeSort(a, i + 1, right);
Merge(a, b, left, i, right);//合并到数组b
copy(a, b, left, right);//复制回数组a
}
}


 
void quick_sort(int a[], int start, int end) {
	if (start < end) {
		int s = a[start];
		int i = start;
		int j = end;
 
		//注意刚开始排序一定得从右向左查找才可以
		while (i < j) {
 
			//从右向左查找第一个小于s的值与a[0]交换
			while (i < j && a[j] >= s)
				j--;
			if (i<j) 
				a[i++] = a[j];//把a[j]的值给a[i]，并让i向后走一位
 
			//从左向右查找第一个大于等于s的值与a[0]交换
			while (i < j && a[i] < s)
				i++;
			if (i < j) {
				a[j--] = a[i];//把a[i]的值给此时s所在的地址，并让j向前退一位
			}
		}
		a[i] = s;//因为在之前的交换值过程中a[i]的值已经不是最初的值，所以要变回来
		quick_sort(a, start, i - 1);//排序枢轴前数列
		quick_sort(a, i + 1, end);//排序枢轴后数列
	}
}
 
void put(int a[],int length) {
	for (int i = 0; i < length; i++) {
		cout << a[i]<<' ';
	}
}


int main()
{
int array[14] = { 1,4,2,3,9,11,10,7,95,64,100,151,121,113 };


	cout << "排序前：";
	put(array, 14);
	quick_sort(array, 0, 13);
	cout << "\n排序后：";
	put(array, 14);

cout << "\n初始时，array里的元素顺序是：" << endl;
for (int i = 0; i < 14; i++)
{
cout << array[i] << "，";
}
cout << endl;
MergeSort(array, 0, 13);
cout << "排序后，array里的元素顺序是：" << endl;
for (int i = 0; i < 14; i++)
{
cout << array[i] << "，";
}
cout << endl;

system("pause");
return 0;


}