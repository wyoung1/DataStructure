// 给定一个长度为n的单调递增的正整数序列，即序列中的每一个数都比前一个数大，有m个询问，每次询问一个x，问序列中最后一个小于等于x的数是什么？
#include<iostream>
using namespace std;

int solution(int x, int a[], int n) {
	int i = 0;
	for (i; i < n; i++) {
		if (a[i] > x) {
			break;
		}
	}
	return a[--i];
}

int main() {
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int* acquire = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> acquire[i];
	}

	for (int i = 0; i < m; i++) {
		cout << solution(acquire[i], a, n) << endl;
	}

	return 0;
}