#include<iostream>
#include<vector>
using namespace std;

int division(vector<int> &list, int left, int right) {
	int base = list[left];
	while (left < right) {
		while (left < right && list[right] >= base)
			right--;
		list[left] = list[right];
		while (left < right && list[left] <= base) {
			left++;
		}
		list[right] = list[left];
	}
	list[left] = base;
	return left;
}

void QuickSort(vector<int> &list, int left, int right) {
	if (left < right) {
		int base = division(list, left, right);
		QuickSort(list, left, base - 1);
		QuickSort(list, base + 1, right);
	}
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result = test;
	QuickSort(result, 0, result.size() - 1);
	cout << "�����" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
ʱ�临�Ӷȣ�
O(nlog2n)
�ռ临�Ӷȣ�
O(log2n)
�㷨�ȶ��ԣ�
���ȶ�
*/