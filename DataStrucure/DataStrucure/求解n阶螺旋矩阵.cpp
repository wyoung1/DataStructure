#include<iostream>
using namespace std;

const int nmax = 50;
int a[nmax][nmax];//����һ����ά������װ���ֺ�ֱ�Ӵ�ӡ
int n;//����n


/*
˼·��ͨ��������֪������n�����������������n>2�Ժ�����õݹ��Ϊ��������ʵ�֣�һ��������ʵ�֣�һ�����ڲ�ĵݹ�
������
	1��n
	2,num0 ����ȷ�����������
	3,len ������ʾ��ǰ���õ����ĸ��ݹ�
	4, m ����ȷ���������
*/
void HelixMatrix(int n, int num0, int len, int m) {

	if (len == 1) {
		a[m][m] = num0;
		return;
	}
	if (len == 2) {
		a[m][m] = num0++;
		a[m][m + 1] = num0++;
		a[m + 1][m + 1] = num0++;
		a[m + 1][m] = num0;
		return;

	}

	int x = m;//������Сֵ
	int y = n + 1 - m;//�������ֵ(��һ���ʱ����n���ڶ�����n-1,��������n-2.......
	int tmp = num0;//��Ҫ���ı䴫�������ֵ

	if (len >= 3) {
		//����
		for (int i = x; i <= y; i++) {
			a[x][i] = tmp;
			tmp++;
		}
		//�ұ�
		for (int i = x + 1; i <= y; i++) {
			a[i][y] = tmp;
			tmp++;
		}
		//����
		for (int i = y - 1; i >= x; i--) {
			a[y][i] = tmp;
			tmp++;
		}
		//���
		for (int i = y - 1; i >= x + 1; i--) {
			a[i][x] = tmp;
			tmp++;
		}
		HelixMatrix(n, tmp, len - 2, m + 1);
	}
}


int main()
{
	while (1) {
		cin >> n;//����n

		if (n == 0) {//����0����
			printf("��������Чֵ\n");
			break;
		}

		//���ú���
		HelixMatrix(n, 1, n, 1);

		//��ӡ
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%5d", a[i][j]);			//����Ҷ���
			}
			cout << endl;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
