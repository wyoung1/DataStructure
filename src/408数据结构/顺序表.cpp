#include<stdio.h>

const int MaxSize = 100;
const int InitSize = 50;

typedef int ElementType;
typedef struct {
	ElementType* data;
	int length;
} SqList;

// ��ʼ��
bool InitList(SqList *L) {
	L->length = 0;
	L->data = new ElementType[InitSize];
	return true;
}

// ����
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

// ��ӡ
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
// ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ���
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
// ���һ���ռ临�Ӷ�ΪO(1)���㷨����˳������е�Ԫ������
void Reverse(SqList &L) {
	ElementType temp;
	for (int i = 0; i < L.length / 2; i++) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

// Question3
// ������˳�����ɾ������ֵ�ظ���Ԫ�أ����ɺ������ؽ��˳���
bool Del_Dup(SqList &L) {
	if (L.length == 0 || L.length == 1) return false;
	int i, j;
	for (i = 0, j = 1; j < L.length; j++) {  // i�洢��һ������ͬ��Ԫ�أ�jΪ����ָ��
		if (L.data[i] != L.data[j]) {
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1; // ��length���޶�˳�����
	return true;
	// ˼��һ��������������ô��?(ʹ��ɢ�б�)
}

// Question4 
// ���һ���㷨��ʵ�ֽ�һ�������е�����Ԫ��ѭ������pλ
/*
����pλ����n-pλ�ֿ�������������pλ����������n-pλ������ٶ���������һ�飬�õ����
�����㷨����Question2
ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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

	// ����Question1
	int value; // �鿴��ɾ����ֵ
	Del_Min(L, value);
	printf("%d\t", value);
	Print(L);
	printf("\n");

	// ����Question2
	Reverse(L);
	Print(L);
	printf("\n");
	
	// ����Question3
	ListInsert(L, 3, 9);
	ListInsert(L, 4, 10);
	Print(L);
	Del_Dup(L);
	Print(L);
	printf("\n");

	// ����Question4
	printf("------------Q4---------------\n");
	int R[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ReverseWhole(R, 3, 9);
	for (auto i : R) {
		printf("%d\t", i);
	}

	return 0;
}
