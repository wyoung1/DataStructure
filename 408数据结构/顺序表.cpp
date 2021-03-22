#include<stdio.h>

const int MaxSize = 100;
const int InitSize = 50;

typedef int ElementType;
typedef struct {
	ElementType* data;
	int length;
} SqList;

// 初始化
bool InitList(SqList *L) {
	L->length = 0;
	L->data = new ElementType[InitSize];
	return true;
}

// 插入
bool ListInsert(SqList &L, int i, ElementType e) {
	if (i<1 || i>L.length + 1) return false;
	if (L.length >= MaxSize) return false;
	for (int j = L.length; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 打印
void Print(SqList &L) {
	if (L.length == 0) {
		printf("Nothing");
		return;
	}
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.data[i]);
	}
	return;
}

// Question1
// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值，空出的位置由最后一个元素填补
bool Del_Min(SqList &L, ElementType &value) {
	if (L.length == 0) return false;
	value = L.data[0];
	int pos = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] < value) {
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];
	L.length--;
	return true;
}

// Question2
// 设计一个空间复杂度为O(1)的算法，将顺序表所有的元素逆置
void Reverse(SqList &L) {
	ElementType temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

// Question3
// 从有序顺序表中删除所有值重复的元素，并由函数返回结果顺序表
bool Del_Dup(SqList &L) {
	if (L.length == 0 || L.length == 1) return false;
	int i, j;
	for (i = 0, j = 1; j < L.length; j++) {  // i存储第一个不相同的元素，j为工作指针
		if (L.data[i] != L.data[j]) {
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1; // 由length来限定顺序表长度
	return true;
	// 思考一下如果是无序表怎么做?(使用散列表)
}

// Question4 
// 设计一个算法，实现将一个数组中的所有元素循环左移p位
/*
将左p位和右n-p位分开处理，先逆置左p位，再逆置右n-p位，最后再对整体逆置一遍，得到结果
逆置算法采用Question2
时间复杂度O(n),空间复杂度O(1)
*/
void ReversePart(int R[], int from, int to) {
	int temp;
	for (int i = 0; i < (to - from + 1) / 2; i++) {
		temp = R[from + i];
		R[from + i] = R[to - i];
		R[to - i] = temp;
	}
}
void ReverseWhole(int R[], int p, int n) {
	ReversePart(R, 0, p-1);
	ReversePart(R, p, n - 1);
	ReversePart(R, 0, n - 1);
}

int main() {
	SqList L;
	InitList(&L);
	ListInsert(L, 1, 9);
	ListInsert(L, 2, 8);
	ListInsert(L, 3, 7);
	Print(L);
	printf("\n");

	// 测试Question1
	int value; // 查看被删除的值
	Del_Min(L, value);
	printf("%d\t", value);
	Print(L);
	printf("\n");

	// 测试Question2
	Reverse(L);
	Print(L);
	printf("\n");
	
	// 测试Question3
	ListInsert(L, 3, 9);
	ListInsert(L, 4, 10);
	Print(L);
	Del_Dup(L);
	Print(L);
	printf("\n");

	// 测试Question4
	printf("------------Q4---------------\n");
	int R[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ReverseWhole(R, 3, 9);
	for (auto i : R) {
		printf("%d\t", i);
	}

	return 0;
}
