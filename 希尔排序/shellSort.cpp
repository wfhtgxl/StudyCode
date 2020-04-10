/***************************************************************************
 *  @file       main.cpp
 *  @author     MISAYAONE
 *  @date       27  March 2017
 *  @remark     27  March 2017
 *  @theme      Shell Sort
 ***************************************************************************/

#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;

void Shell_sort(int a[], size_t n)
{
	int i, j, k, group;
	for (group = n/2; group > 0; group /= 2)//增量序列为n/2,n/4....直到1
	{
		for (i = 0; i < group; ++i)
		{
			//对每个分组进行插入排序
			for (j = i + group; j < n; j += group)
			{
				if (a[j - group] > a[j])
				{
					int temp = a[j];
					k = j - group;
					while (k >= 0 && a[k] > temp)
					{
						a[k + group] = a[k];
						k -= group;
					}
					a[k] = temp;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	for (int i = 0; i < 5; i++) {
		cout << i <<endl;
	}
	int a[10] = { 1,51,6,2,8,2,564,1,65,6 };

	Shell_sort(a, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << " ";
	}
	cin.get();
	return 0;
}