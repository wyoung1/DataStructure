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
		cout << "��" << i + 1 << "������" << endl;
		for (int j = 0; j < res.size() - 1 - i; ++j) {
			if (res[j + 1] < res[j]) {
				temp = res[j + 1];
				res[j + 1] = res[j];
				res[j] = temp;
			}
			cout << "�����У�";
			for (int s = 0; s < res.size(); ++s) {
				cout << res[s] << "	";
			}
			cout << endl;
		}
		cout << "��������";
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
	cout << "����ǰ" << endl;
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = bubbleSort(test);
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
O(n2)
�ռ临�Ӷȣ�
O(1)
�㷨�ȶ��ԣ�
�ȶ�
*/