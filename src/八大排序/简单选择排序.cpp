#include<iostream>
#include<vector>
using namespace std;

vector<int> SelectSort(vector<int> list) {
	vector<int> result = list;
	for (int i = 0; i < list.size(); i++) {
		int index = i;
		for (int j = i + 1; j < result.size(); j++) {
			if (result[index] > result[j]) {
				index = j;
			}
		}
		if (index == i) {
			continue;
		}
		swap(result[i], result[index]);
		cout << "第" << i + 1 << "趟：\t";
		for (int item : result) {
			cout << item << "	";
		}
		cout << endl;
	}
	return result;
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "排序前" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = SelectSort(test);
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
不稳定
*/