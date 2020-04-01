#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 5

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
	for (int i = 0; i < length && flag == 0; i++) {
		flag = 1;//认为已经排序好
		for (int j = length - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				flag = 0;
				Swap(&arr[j - 1], &arr[j]);
			}
		}
	}
}

//选择排序
void SelectSort(int arr[], int length) {
	//减少交换次数
	for (int i =0 ; i < length; i++) {
		int min= i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;//min时刻取得最小值下标
			}
		}
		if (min != i) {
			Swap(&arr[min], &arr[i]);
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
	cout << "冒泡时间：" << t_end - t_start<<endl;
	cout << "——————————————————————————————————————————" << endl;
	int arr_Select[MAX];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++) {
		arr_Select[i] = rand() % MAX;
	}
	cout << "排序前" << endl;
	Print(arr, MAX);
	long t_start_Select = getTime();
	SelectSort(arr_Select, MAX);
	long t_end_Select = getTime();
	cout << "排序后" << endl;
	Print(arr_Select, MAX);
	cout << "选择排序时间：" << t_end_Select - t_start_Select;
	return 0;
}