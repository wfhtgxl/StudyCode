#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 10000 
//交换函数
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

long getTime() {
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}


//打印
void Print(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
}
int flag = 0;//标识没排序好
//冒泡改良版
void BubbleSort(int arr[], int length) {
	for (int i = 0; i < length && flag ==0; i++) {
		flag = 1;//认为已经排序好
		for (int j = length -1 ; j > i; j--) {
			if (arr[j-1] < arr[j]) {
				flag = 0;
				Swap(&arr[j - 1], &arr[j]);
			}
		}
	}
}

int main() {
	int arr[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	cout << "排序前" << endl;
	Print(arr, MAX);
	long t_start = getTime();
	BubbleSort(arr, MAX);
	long t_end = getTime();
	cout << "排序后" << endl;
	Print(arr, MAX);
	cout << "冒泡时间：" << t_end - t_start;
	return 0;
}