#include<stdio.h>
#include<malloc.h>

enum {InitSize = 100};

typedef int ElementType;
typedef struct {
	ElementType* data;  // 动态分配数组长度
	int length;
} SeqList;

int main() {
	SeqList L;
	// L.data = (ElementType*)malloc(sizeof(ElementType)*InitSize);
	L.data = new ElementType[InitSize];
}

