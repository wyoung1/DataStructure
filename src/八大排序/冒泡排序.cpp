#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> list) {
	vector<int> res;
	if (list.empty()) {
		return res;
	}
	res = list;
	int temp;
	for (int i = 0; i < res.size() - 1; ++i) {
		cout << "第" << i + 1 << "趟排序：" << endl;
		for (int j = 0; j < res.size() - 1 - i; ++j) {
			if (res[j + 1] < res[j]) {
				temp = res[j + 1];
				res[j + 1] = res[j];
				res[j] = temp;
			}
			cout << "排序中：";
			for (int s = 0; s < res.size(); ++s) {
				cout << res[s] << "	";
			}
			cout << endl;
		}
		cout << "排序结果：";
		for (int s = 0; s < res.size(); ++s) {
			cout << res[s] << "	";
		}
		cout << endl;
	}
	return res;
}



int main() {
	int arr[] = { 6, 4, 8, 1, 2, 3, 9 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
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
O(n2)
空间复杂度：
O(1)
算法稳定性：
稳定
*/