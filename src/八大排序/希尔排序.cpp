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
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	cout << "排序中" << endl;
	vector<int> result;
	result = ShellSort(test);
	cout << "排序后" << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
时间复杂度：
O(nlog2n)
空间复杂度：
O(1)
算法稳定性：
不稳定
*/