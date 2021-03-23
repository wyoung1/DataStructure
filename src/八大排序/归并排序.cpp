#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp) {
	int i = left;  // i是第一段序列下标
	int j = mid + 1;  // j是第二段序列下标
	int k = 0;  // k临时存放合并序列的下标

	while (i <= mid && j <= right) {
		if (input[i] <= input[j])
			temp[k++] = input[i++];
		else
			temp[k++] = input[j++];
	}

	while (i <= mid) {
		temp[k++] = input[i++];
	}

	while (j <= right) {
		temp[k++] = input[j++];
	}

	k = 0;
	while (left <= right) {
		input[left++] = temp[k++];
	}
}

void MergeSort(vector<int> &input, int left, int right, vector<int> temp) {
	if (left < right) {
		int mid = (left + right) >> 1;
		MergeSort(input, left, mid, temp);
		MergeSort(input, mid + 1, right, temp);
		Merge(input, left, mid, right, temp);
	}
}

void mergesort(vector<int> &input) {
	// 在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	vector<int> temp(input.size());
	MergeSort(input, 0, input.size() - 1, temp);
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前：";
	for (int item : test) {
		cout << item << "	";
	}
	cout << endl;

	vector<int> res = test;
	mergesort(res);
	cout << "排序后:";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "	";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
时间复杂度：O(n*log2n)
空间复杂度：O(n)
算法稳定性：在归并排序中，相等的元素的顺序不会改变，所以它是稳定的算法。
*/