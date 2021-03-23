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

/*
�Ż���
�����־�Ա���exchange�����ڱ�־ĳһ������������Ƿ������ݽ�����
�������ĳһ������ʱ��û�н������ݽ�������˵�����������Ѿ����򣬿������������򣬱��ⲻ��Ҫ�ıȽϹ��̡�
*/

/*
vector<int> bubbleSort(vector<int> list){
	vector<int> result;
	if (list.empty()){
		return result;
	}

	result = list;
	int temp;
	// Ҫ�����Ĵ���
	for (int i = 0; i < result.size() - 1; ++i){
		cout << "��" << i + 1 << "������:" << endl;;
		//������־λ
		bool bChanged = false;
		// �Ӻ���ǰ���εıȽ������������Ĵ�С
		for (int j = 0; j < result.size() - i - 1; j++){
			// ��������Ԫ��С���򽻻����ǵ�λ��
			if (result[j + 1] < result[j]){
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
				bChanged = true;
			}
			cout << "������:";
			for (int s = 0; s < result.size(); s++){
				cout << result[s] << " ";
			}
			cout << endl;
		}
		// �����־Ϊfalse��˵�����ֱ���û�н������Ѿ����������У����Խ�������
		if (false == bChanged){
			break;
		}
		cout << "������:";
		for (int s = 0; s < result.size(); s++){
			cout << result[s] << " ";
		}
		cout << endl;
	}

	return result;
}
*/