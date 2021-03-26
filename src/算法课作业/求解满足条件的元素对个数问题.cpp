// 给定N个整数Ai，以及一个正整数C，问其中有多少对i、j满足Ai-Aj=C
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