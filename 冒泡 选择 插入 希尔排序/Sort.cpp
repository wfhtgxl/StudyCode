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

//选择排序	通过标记数组下标 找到最小值 交换 来进行排序               未考虑有重复元素的情况
void SelectSort(int arr[], int length) {
	//减少交换次数
	for (int i =0 ; i < length; i++) {
		int min= i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;//min时刻取得最小值下标
			}
		}
		if (min != i) {//min ！= i				---> 考虑到最小值就是它自己的情况   
			Swap(&arr[min], &arr[i]);
	}
	}
}

//插入排序
void InsertSort(int arr[], int length) {//插入排序是将无序的数列插入到有序的数列 如果数列基本有序或数列比较少时则效率会更高
	//减少交换次数
	int j;
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
		
	}
}

//希尔排序???
void ShellSort(int arr[], int length) {
	int increasement = length;
	int j, k;

	do {//先执行后判断
	 increasement = length/3 + 1;
		for (int i = 0; i < increasement; i++) {
			
			for (j = i + increasement; j < length; j += increasement) {
				if (arr[j] < arr[j - increasement]) {
					int temp = arr[j];
					for (k = j - increasement; j >= 0 && temp < arr[k]; k-= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);

}

int main() {
	//int arr[MAX];
	//srand((unsigned int)time(NULL));//如何获得多个随机数组
	//for (int i = 0; i < MAX; i++) {
	//	arr[i] = rand() % MAX;
	//}
	//cout << "排序前" << endl;
	//Print(arr, MAX);
	//long t_start = getTime();
	//BubbleSort(arr, MAX);
	//long t_end = getTime();
	//cout << "排序后" << endl;
	//Print(arr, MAX);
	//cout << "冒泡时间：" << t_end - t_start<<endl;
	//cout << "——————————————————————————————————————————" << endl;
	//int arr_Select[MAX];
	//srand((unsigned int)time(NULL));
	//for (int i = 0; i < MAX; i++) {
	//	arr_Select[i] = rand() % MAX;
	//}
	//cout << "排序前" << endl;
	//Print(arr_Select, MAX);
	//long t_start_Select = getTime();
	//InsertSort(arr_Select, MAX);
	//long t_end_Select = getTime();
	//cout << "排序后" << endl;
	//Print(arr_Select, MAX);
	//cout << "选择排序时间：" << t_end_Select - t_start_Select;

	int arr[MAX];
	srand((unsigned int)time(NULL));//如何获得多个随机数组
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	Print(arr, MAX);
	ShellSort(arr, MAX);
	Print(arr, MAX);
	return 0;
}