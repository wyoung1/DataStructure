// ����N������Ai���Լ�һ��������C���������ж��ٶ�i��j����Ai-Aj=C
#include<iostream>
using namespace std;


int main() {
	int n, c, count = 0;
	cin >> n >> c;
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (abs(a[j] - a[i]) == c) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}