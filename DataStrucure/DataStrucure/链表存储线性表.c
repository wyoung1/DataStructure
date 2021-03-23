#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct LNode* List;

struct LNode {
	ElementType data;
	List next;
};

List L;

// 初始化链表
int MakeEmpty() {
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	/*
	这里初始化了头结点指针，然后又把它指向NULL，并不是没有意义的。在C语言中，把一个指针指向NULL表明它为空指针，
	但它指向的位置是确定的。C++为nullptr。但是如果一个指针没有初始化，则为野指针，那会访问不确定的东西。
	通过下面的插入可以看出，当插入了一个结点后，这个空结点被挤到了后面，因此这是一个没有头结点的链表
	*/
	return L;
}

// 求表长
int Length(List L) {
	List p = L;
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	return len;
}

// 按序查找
List FindKth(int k, List L) {
	/*
	int length = Length(L);
	if (k > L || k < 0) {
		printf("Invalid Serial Number!");
		return -1;
	}
	*/
	List p = L;
	int i = 1;
	while (p && i < k) {
		p = p->next;
		i++;
	}
	if (i == k)return p;
	else return NULL;
}

// 按值查找
List Find(ElementType x, List L) {
	List p = L;
	while (p && p->data != x)
		p = p->next;
	return p;  // 如果没有找到，此时p为NULL
}

// 插入(双指针)
List Insert(ElementType x, int i, List L) {
	List p, s;
	if (i == 1) {
		s = (List)malloc(sizeof(struct LNode));
		s->data = x;
		s->next = L;
		return s;
	}
	p = FindKth(i - 1, L);
	if (!p) {
		printf("Error Node!");
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return L;
	}
}

// 删除(双指针)
List Delete(int i, List L) {
	List p, s;
	if (i == 1) {
		s = L;
		if (L)
			L = L->next;
		else
			return NULL;
		free(s);  // 释放被删除的结点空间
		return L;
	}
	p = FindKth(i - 1, L);
	if (!p || !(p->next)) {
		printf("Error Node!");
		return NULL;
	}
	else {
		s = p->next;
		p->next = s->next;
		free(s);
		return L;
	}
}

// 输出链表元素
void Print(List L) {
	List p;
	int flag = 1; // 判空
	printf("当前链表为：");
	for (p = L; p; p = p->next) {
		printf("%d	", p->data);
		flag = 0;
	}
	if (flag)
		printf("NULL");
	printf("\n");
}

int main() {
	L = MakeEmpty();
	Print(L);
	L = Insert(11, 1, L);
	L = Insert(25, 1, L);
	L = Insert(33, 2, L);
	L = Insert(77, 3, L);
	Print(L);
	printf("当前链表长度为：%d\n", Length(L));
	printf("此时链表中第二个结点的值是：%d\n", FindKth(2, L)->data);
	printf("查找22是否在该链表中：");
	if (Find(22, L))
		printf("是！\n");
	else
		printf("否！\n");
	printf("查找33是否在该链表中：");
	if (Find(33, L))
		printf("是！\n");
	else
		printf("否！\n");
	L = Delete(1, L);
	L = Delete(3, L);
	printf("----------删除后-----\n");
	Print(L);
	return 0;
}
