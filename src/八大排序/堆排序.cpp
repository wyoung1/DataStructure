#include<iostream>
#include<vector>
using namespace std;

void HeapAdjust(vector<int> &list, int parent, int length) {
	int temp = list[parent];                    // temp���浱ǰ���ڵ�
	int child = 2 * parent + 1;                    // �Ȼ������

	while (child < length) {
		// ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
		if (child + 1 < length && list[child] < list[child + 1]) {
			child++;
		}

		// ������Һ��ӽ�㣬�����Һ��ӽ���ֵ�������ӽ�㣬��ѡȡ�Һ��ӽ��
		if (temp >= list[child]) {
			break;
		}

		// �Ѻ��ӽ���ֵ���������
		list[parent] = list[child];

		// ѡȡ���ӽ������ӽ��,��������ɸѡ
		parent = child;
		child = 2 * parent + 1;
	}
	list[parent] = temp;
}

vector<int> HeadSort(vector<int> list) {
	int length = list.size();
	// ѭ��������ʼ��
	for (int i = length / 2 - 1; i >= 0; i--) {
		HeapAdjust(list, i, length);
	}

	// ����n-1��ѭ�����������
	for (int i = length - 1; i > 0; i--) {
		// ���һ��Ԫ�غ͵�һԪ�ؽ��н���
		int temp = list[i];
		list[i] = list[0];
		list[0] = temp;

		// ɸѡ R[0] ��㣬�õ�i-1�����Ķ�
		HeapAdjust(list, 0, i);
		cout << "��" << length - i << "������:";
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	return list;
}

int main() {
	int arr[] = { 6, 4, 8, 9, 2, 3, 1 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ:";
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;
	vector<int> result;
	result = HeadSort(test);
	cout << "�����:";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

/*
ʱ�临�Ӷȣ�
O(nlogn)
�ռ临�Ӷȣ�
O(1)
�㷨�ȶ��ԣ�
���ȶ�
*/
