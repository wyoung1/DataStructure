// ���ڲ���ͷ���ĵ�����L�����һ���ݹ��㷨�������еĽ�㡣

#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct LNode* List;

struct LNode {
	ElementType val;
	List next;
};

// ��ʼ������
List MakeEmpty() {
	List l = (List)malloc(sizeof(struct LNode));
	l = NULL;
	return l;
}

// ������β������ֵ
List Push(List l, ElementType item) {
	List p, s;
	if (l == NULL) {
		p = (List)malloc(sizeof(struct LNode));
		p->val = item;
		p->next = l;
		return p;
	}
	s = l;
	while (s->next) {
		s = s->next;
	}
	p = (List)malloc(sizeof(struct LNode));
	p->next = s->next;
	p->val = item;
	s->next = p;
	return l;
}

// �ݹ��㷨�������н��
List Reverse(List l) {
	if (l == NULL || l->next == NULL) return l;
	List p = Reverse(l->next);
	l->next->next = l;
	l->next = NULL;
	return p;
}

// ���
void Print(List l) {
	while (l) {
		printf("%d\n", l->val);
		l = l->next;
	}
	return;
}

int main() {
	List l;
	l = MakeEmpty();
	for (ElementType i = 0; i < 10; i++) {
		l = Push(l, i);
	}
	Print(l);
	l = Reverse(l);
	Print(l);
	return 0;
}