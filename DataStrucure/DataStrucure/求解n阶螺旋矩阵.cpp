#include<iostream>
using namespace std;

const int nmax = 50;
int a[nmax][nmax];//定义一个二维数组来装数字后直接打印
int n;//参数n


/*
思路：通过分析可知“创建n阶螺旋矩阵并输出”当n>2以后可以用递归分为两部分来实现，一个是外层的实现，一个是内层的递归
参数：
	1，n
	2,num0 用来确定输出的数字
	3,len 用来表示当前调用的是哪个递归
	4, m 用来确定输出坐标
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

	int x = m;//坐标最小值
	int y = n + 1 - m;//坐标最大值(第一层的时候是n，第二层是n-1,第三层是n-2.......
	int tmp = num0;//不要随便改变传入参数的值

	if (len >= 3) {
		//上面
		for (int i = x; i <= y; i++) {
			a[x][i] = tmp;
			tmp++;
		}
		//右边
		for (int i = x + 1; i <= y; i++) {
			a[i][y] = tmp;
			tmp++;
		}
		//下面
		for (int i = y - 1; i >= x; i--) {
			a[y][i] = tmp;
			tmp++;
		}
		//左边
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
		cin >> n;//输入n

		if (n == 0) {//输入0结束
			printf("请输入有效值\n");
			break;
		}

		//调用函数
		HelixMatrix(n, 1, n, 1);

		//打印
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%5d", a[i][j]);			//输出右对齐
			}
			cout << endl;
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
