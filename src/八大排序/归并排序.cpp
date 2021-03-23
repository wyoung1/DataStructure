#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &input, int left, int mid, int right, vector<int> temp) {
	int i = left;  // i�ǵ�һ�������±�
	int j = mid + 1;  // j�ǵڶ��������±�
	int k = 0;  // k��ʱ��źϲ����е��±�

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
	// ������ǰ���Ƚ���һ�����ȵ���ԭ���鳤�ȵ���ʱ���飬����ݹ���Ƶ�����ٿռ�
	vector<int> temp(input.size());
	MergeSort(input, 0, input.size() - 1, temp);
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ��";
	for (int item : test) {
		cout << item << "	";
	}
	cout << endl;

	vector<int> res = test;
	mergesort(res);
	cout << "�����:";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "	";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
ʱ�临�Ӷȣ�O(n*log2n)
�ռ临�Ӷȣ�O(n)
�㷨�ȶ��ԣ��ڹ鲢�����У���ȵ�Ԫ�ص�˳�򲻻�ı䣬���������ȶ����㷨��
*/