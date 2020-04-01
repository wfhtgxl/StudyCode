#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 10000 
//��������
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


//��ӡ
void Print(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << endl;
	}
}
int flag = 0;//��ʶû�����
//ð�ݸ�����
void BubbleSort(int arr[], int length) {
	for (int i = 0; i < length && flag ==0; i++) {
		flag = 1;//��Ϊ�Ѿ������
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
	cout << "����ǰ" << endl;
	Print(arr, MAX);
	long t_start = getTime();
	BubbleSort(arr, MAX);
	long t_end = getTime();
	cout << "�����" << endl;
	Print(arr, MAX);
	cout << "ð��ʱ�䣺" << t_end - t_start;
	return 0;
}