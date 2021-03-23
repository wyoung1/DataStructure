#include<iostream>
#include<vector>
using namespace std;

vector<int> insertSort(vector<int> list) {
	vector<int> res = list;
	if (list.empty()) {
		return res;
	}
	for (int i = 1; i < res.size(); ++i) {
		int temp = res[i];
		int j = i - 1;
		for (j; j >= 0 && res[j] > temp; --j) {
			res[j + 1] = res[j];
		}
		res[j + 1] = temp;
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
	vector<int> result;
	result = insertSort(test);
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
O(N2)
空间复杂度：
O(1)
算法稳定性：
稳定
*/

/*
// 优化：查找插入的位置时选择二分查找
// 给定一个有序的数组，查找第一个大于等于value的下标，不存在返回-1
int BinarySearch(vector<int> list, int n, int value){
	int left = 0;
	int right = n - 1;

	while (left <= right){
		int middle = left + ((right - left) >> 1);

		if (list[middle] > value){
			right = middle - 1;
		}
		else{
			left = middle + 1;
		}
	}
	return (left < n) ? left : -1;
}

vector<int> BinaryInsertSort(vector<int> list){
	vector<int> result = list;
	for (int i = 1; i < result.size(); i++){
		int insert_index = BinarySearch(result, i, result[i]);
		if (insert_index != -1){
			int temp = result[i];
			int j = i - 1;
			while (j >= insert_index){
				result[j + 1] = result[j];
				j--;
			}
			result[j + 1] = temp;
		}
		printf("第 %d 趟： ", i);
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return result;
}
*/