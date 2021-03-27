// 在一个非降序列中查找与给定值x最接近的元素
#include<iostream>
using namespace std;

int solution(int a[], int x, int n) {
	int i = 0;
	for (i; i < n; i++) {
		if (a[i] > x) {
			break;
		}
	}
	if (i == n)return a[n - 1];
	return (a[i] - x) > (x - a[i - 1]) ? a[i - 1] : a[i];
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	int* acquire = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> acquire[i];
	}

	for (int i = 0; i < m; i++) {
		cout << solution(a, acquire[i], n) << endl;
	}
	return 0;
}