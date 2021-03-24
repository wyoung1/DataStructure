#include <iostream>
#include <vector>

using namespace std;

// ����������������λ���ĺ���
int MaxBit(vector<int> input) {
	// �������ֵ
	int max_data = input[0];
	for (int i = 1; i < input.size(); i++) {
		if (input[i] > max_data) {
			max_data = input[i];
		}
	}

	// �������ֵ��λ��
	int bits_num = 0;
	while (max_data) {
		bits_num++;
		max_data /= 10;
	}

	return bits_num;
}

// ȡ��xxx�ϵĵ�dλ����
int digit(int num, int d) {
	int pow = 1;
	while (--d > 0) {
		pow *= 10;
	}
	return num / pow % 10;
}

// ��������
vector<int> RadixSort(vector<int> input, int n) {
	// ��ʱ���飬���������������е�����
	vector<int> bucket(n);
	// λ���������ӵ�0��Ԫ�ص���9��Ԫ������������¼��ǰ�Ƚ�λ��0���ж��ٸ�...��9���ж��ٸ���
	vector<int> count(10);
	// �ӵ�λ����λѭ��
	for (int d = 1; d <= MaxBit(input); d++) {
		// ��������0
		for (int i = 0; i < 10; i++) {
			count[i] = 0;
		}

		// ͳ�Ƹ���Ͱ�еĸ���
		for (int i = 0; i < n; i++) {
			count[digit(input[i], d)]++;
		}

		/*
		* ����ĳ�ξ�������ͳ�ƺ���Ϊ��[0, 2, 3, 3, 0, 0, 0, 0, 0, 0]�򾭹��������� ���Ϊ�� [0, 2,
		* 5, 8, 8, 8, 8, 8, 8, 8]��ʵ����ֻ������[0, 2, 5, 8, 0, 0, 0, 0, 0, 0]��
		* ���������õ�����Ϊ����λ�����ڣ����Ƿֱ��ʾ���£�2��ʾ�Ƚ�λΪ1��Ԫ�ؿ��Դ��������Ϊ1��0��
		* λ�ã�5��ʾ�Ƚ�λΪ2��Ԫ�ؿ��Դ����4��3��2����(5-2=3)λ�ã�8��ʾ�Ƚ�λΪ3��Ԫ�ؿ��Դ����
		* 7��6��5����(8-5=3)λ��
		*/
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		/*
		* ע������ֻ�ܴ��������ǰѭ������Ϊ����ʱ���豣����ǰ��������õ�˳�򣬲�Ӧ�ô�
		* ��ԭ�����źõ��������ǰ����������ԭ����ǰ���ڵ�����ȥ����Ϊ�ڴ���ĳ��
		* Ԫ�ص�λ��ʱ��λ�������ǴӴ󵽵�С��count[digit(arr[i], d)]--���ķ�ʽ����
		* ��ģ����ȴ���������Ԫ�أ��ٴ������С��Ԫ�أ�����������һ��Ԫ�ؿ�ʼ����
		* ����������һ������[212,213,312]��������մӵ�һ��Ԫ�ؿ�ʼѭ���Ļ���������һ��
		* �󣨸�λ������󣬵õ�����һ������[312,212,213]����һ�κ���ûʲô���⣬�������
		* �ӵڶ��ֿ�ʼ���֣��ڶ�������󣬻�õ�[213,212,312]��������λΪ3��Ԫ�ر�Ӧ��
		* ������󣬵������ڶ��ֺ�ȴ������ǰ���ˣ����Գ���������
		*/
		for (int i = n - 1; i >= 0; i--) {
			int k = digit(input[i], d);
			bucket[count[k] - 1] = input[i];
			count[k]--;
		}

		// ��ʱ���鸴�Ƶ� input ��
		for (int i = 0; i < n; i++) {
			input[i] = bucket[i];
		}
	}

	return input;
}

int main() {
	int arr[] = { 50, 123, 543, 187, 49, 30, 0, 2, 11, 100 };
	vector<int> test(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "����ǰ:";
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
	cout << endl;

	vector<int> result = test;
	result = RadixSort(result, result.size());
	cout << "�����:";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}