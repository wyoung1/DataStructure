#include<iostream>
#include<vector>
using namespace std;

vector<int> ShellSort(vector<int> list) {
	vector<int> res = list;
	int n = res.size();
	for (int gap = n >> 1; gap > 0; gap >>= 1) {
		for (int i = gap; i < n; i++) {
			int temp = res[i];
			int j = i - gap;
			while (j >= 0 && res[j] > temp) {
				res[j + gap] = res[j];
				j -= gap;
			}
			res[j + gap] = temp;
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return res;
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	cout << "������" << endl;
	vector<int> result;
	result = ShellSort(test);
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
O(1)
�㷨�ȶ��ԣ�
���ȶ�
*/