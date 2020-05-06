#include <stdio.h>
#include <stdlib.h>
//获取中间的数
int GetMid(int* array, int begin, int end) {
	int mid = begin + (end - begin) / 2;
	if (array[begin] < array[mid]) {
		if (array[mid] < array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else {
		if (array[mid] > array[end])
			return mid;
		else {
			if (array[begin] > array[end])
				return end;
			else
				return begin;
		}
	}
}
void Swap(int* array, int begin, int end) {
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}
int partion(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array,begin, mid);
	int prev = begin;
	int cur = prev + 1;
	int key = array[begin];
	while (cur<=end) {
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);
		cur++;
	}
	Swap(array, begin, prev);
	return prev;
}
//挖坑法
int partion1(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array, begin, mid);
	int key = array[begin];
	while (begin < end) {
		while (begin < end&&array[end] >= key)
			end--;
		array[begin] = array[end];
		while (begin < end&&array[begin] <= key)
			begin++;
		array[end] = array[begin];
	}
	array[begin] = key;
	return begin;
}
//hora法
int partion2(int* array, int begin, int end) {
	int mid = GetMid(array, begin, end);
	Swap(array, begin, mid);
	int key = array[begin];
	int start = begin;
	while (begin < end) {
		while (begin < end&&array[end] >= key)
			end--;
		while (begin < end&&array[begin] <= key)
			begin++;
		Swap(array, begin, end);
	}
	Swap(array, begin, start);
	return begin;
}
void quickSort(int* array, int begin, int end) {
	if (begin >= end)
		return;
	int keypos = partion2(array, begin, end);
	quickSort(array, begin, keypos - 1);
	quickSort(array, keypos + 1, end);
}

int main() {
	int array[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}