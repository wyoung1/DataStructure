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

/*
优化：
加入标志性变量exchange，用于标志某一趟排序过程中是否有数据交换。
如果进行某一趟排序时并没有进行数据交换，则说明所有数据已经有序，可立即结束排序，避免不必要的比较过程。
*/

/*
vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	int temp;
	// 要遍历的次数
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "第" << i + 1 << "趟排序:" << endl;;
		//交换标志位
		bool bChanged = false;
		// 从后向前依次的比较相邻两个数的大小
		for (int j = 0; j < result.size() - i - 1; j++){
			// 如果后面的元素小，则交换它们的位置
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
				bChanged = true;
			}
			cout << "排序中:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		// 如果标志为false，说明本轮遍历没有交换，已经是有序数列，可以结束排序
		if (false == bChanged){
			break;
		}
		cout << "排序结果:";
		for (int s = 0; s < result.size(); s++){
			cout << result[s] << " ";
		}
		cout << endl;
	}

	return result;
}
*/