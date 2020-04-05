#include<iostream>
#include<time.h>
#include<sys/timeb.h>
using namespace std;

#define MAX 5

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
	for (int i = 0; i < length && flag == 0; i++) {
		flag = 1;//��Ϊ�Ѿ������
		for (int j = length - 1; j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				flag = 0;
				Swap(&arr[j - 1], &arr[j]);
			}
		}
	}
}

//ѡ������	ͨ����������±� �ҵ���Сֵ ���� ����������               δ�������ظ�Ԫ�ص����
void SelectSort(int arr[], int length) {
	//���ٽ�������
	for (int i =0 ; i < length; i++) {
		int min= i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min]) {
				min = j;//minʱ��ȡ����Сֵ�±�
			}
		}
		if (min != i) {//min ��= i				---> ���ǵ���Сֵ�������Լ������   
			Swap(&arr[min], &arr[i]);
	}
	}
}

//��������
void InsertSort(int arr[], int length) {//���������ǽ���������в��뵽��������� ������л�����������бȽ���ʱ��Ч�ʻ����
	//���ٽ�������
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

//ϣ������???
void ShellSort(int arr[], int length) {
	int increasement = length;
	int j, k;

	do {//��ִ�к��ж�
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
	//srand((unsigned int)time(NULL));//��λ�ö���������
	//for (int i = 0; i < MAX; i++) {
	//	arr[i] = rand() % MAX;
	//}
	//cout << "����ǰ" << endl;
	//Print(arr, MAX);
	//long t_start = getTime();
	//BubbleSort(arr, MAX);
	//long t_end = getTime();
	//cout << "�����" << endl;
	//Print(arr, MAX);
	//cout << "ð��ʱ�䣺" << t_end - t_start<<endl;
	//cout << "������������������������������������������������������������������������������������" << endl;
	//int arr_Select[MAX];
	//srand((unsigned int)time(NULL));
	//for (int i = 0; i < MAX; i++) {
	//	arr_Select[i] = rand() % MAX;
	//}
	//cout << "����ǰ" << endl;
	//Print(arr_Select, MAX);
	//long t_start_Select = getTime();
	//InsertSort(arr_Select, MAX);
	//long t_end_Select = getTime();
	//cout << "�����" << endl;
	//Print(arr_Select, MAX);
	//cout << "ѡ������ʱ�䣺" << t_end_Select - t_start_Select;

	int arr[MAX];
	srand((unsigned int)time(NULL));//��λ�ö���������
	for (int i = 0; i < MAX; i++) {
		arr[i] = rand() % MAX;
	}
	Print(arr, MAX);
	ShellSort(arr, MAX);
	Print(arr, MAX);
	return 0;
}