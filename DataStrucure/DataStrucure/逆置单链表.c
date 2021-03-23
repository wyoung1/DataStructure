// 对于不带头结点的单链表L，设计一个递归算法逆置所有的结点。

#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct LNode* List;

struct LNode {
	ElementType val;
	List next;
};

// 初始化链表
List MakeEmpty() {
	List l = (List)malloc(sizeof(struct LNode));
	l = NULL;
	return l;
}

// 在链表尾部插入值
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

// 递归算法逆置所有结点
List Reverse(List l) {
	if (l == NULL || l->next == NULL) return l;
	List p = Reverse(l->next);
	l->next->next = l;
	l->next = NULL;
	return p;
}

// 输出
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