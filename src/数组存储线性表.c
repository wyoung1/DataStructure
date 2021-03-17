#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 100 // 数组大小

typedef int ElementType;
typedef struct LNode *List;

struct LNode {
	ElementType Data[MAXSIZE];
	int Last;  // 线性表的最后一个元素的数组下标
};
// 线性表的长度：L->Last+1

List L;

// 初始化顺序表
List MakeEmpty() {
	List L;
	L = (List)malloc(sizeof(struct LNode));  // 分配成功则返回指向被分配内存的指针，否则返回空指针NULL
	L->Last = -1;
	return L;
}

// 按值查找
int Find(ElementType X, List L) {
	int i = 0;
	while (i <= L->Last&&L->Data[i] != X)
		i++;
	if (L->Last < i)
		return -1;
	else
		return i;  // 返回数组下标
}

// 插入
void Insert(ElementType X, int i, List L) {
	int j;
	if (L->Last == MAXSIZE - 1) {
		printf("FULL!");
		return;
	}
	if (i < 0 || i > L->Last + 1) {
		printf("ERROR LOCATION!");
		return;
	}
	for (j = L->Last; j >= i; j--)
		L->Data[j + 1] = L->Data[j];
	L->Data[i] = X;
	L->Last++;
	return;
}

// 删除
void Delete(int i, List L) {
	int j;
	if (i<0 || i>L->Last) {
		printf("ERROR LOCATION!");
		return;
	}
	for (j = i; j < L->Last; j++)
		L->Data[j] = L->Data[j + 1];
	L->Last--;
	return;
}

// 按序查找
ElementType FindKth(int K, List L) {
	if (K<0 || K>L->Last) {
		printf("ERROR LOCATION!");
		return -1;
	}
	return L->Data[K];
}

// 表长
int Length(List L) {
	return L->Last + 1;
}

int main() {
	int i = 0;
	L = MakeEmpty();
	Insert(11, 0, L);
	printf("在线性表L-Data[0]插入11\n");
	Insert(25, 0, L);
	printf("在线性表L-Data[0]插入25\n");
	Insert(33, 0, L);
	printf("在线性表L-Data[0]插入33\n");
	Insert(77, 0, L);
	printf("在线性表L-Data[0]插入77\n");
	printf("此时的线性表为：");
	for (i = 0; i < Length(L); i++)
		printf("%d ", L->Data[i]);
	printf("\n");
	printf("查找值为12的下标是：%d\n", Find(12, L));
	printf("下标为3的线性表的值是：%d\n", FindKth(3, L));
	Delete(2, L);
	printf("删除线性表中下标为2的元素\n");
	Delete(2, L);
	printf("删除线性表中下标为2的元素\n");
	printf("此时的线性表为：");
	for (i = 0; i < Length(L); i++)
		printf("%d ", L->Data[i]);
	printf("\n");
}
