#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct LNode* List;

struct LNode {
	ElementType data;
	List next;
};

List L;

// ��ʼ������
int MakeEmpty() {
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	/*
	�����ʼ����ͷ���ָ�룬Ȼ���ְ���ָ��NULL��������û������ġ���C�����У���һ��ָ��ָ��NULL������Ϊ��ָ�룬
	����ָ���λ����ȷ���ġ�C++Ϊnullptr���������һ��ָ��û�г�ʼ������ΪҰָ�룬�ǻ���ʲ�ȷ���Ķ�����
	ͨ������Ĳ�����Կ�������������һ����������ս�㱻�����˺��棬�������һ��û��ͷ��������
	*/
	return L;
}

// ���
int Length(List L) {
	List p = L;
	int len = 0;
	while (p) {
		p = p->next;
		len++;
	}
	return len;
}

// �������
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

// ��ֵ����
List Find(ElementType x, List L) {
	List p = L;
	while (p && p->data != x)
		p = p->next;
	return p;  // ���û���ҵ�����ʱpΪNULL
}

// ����(˫ָ��)
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

// ɾ��(˫ָ��)
List Delete(int i, List L) {
	List p, s;
	if (i == 1) {
		s = L;
		if (L)
			L = L->next;
		else
			return NULL;
		free(s);  // �ͷű�ɾ���Ľ��ռ�
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

// �������Ԫ��
void Print(List L) {
	List p;
	int flag = 1; // �п�
	printf("��ǰ����Ϊ��");
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
	printf("��ǰ������Ϊ��%d\n", Length(L));
	printf("��ʱ�����еڶ�������ֵ�ǣ�%d\n", FindKth(2, L)->data);
	printf("����22�Ƿ��ڸ������У�");
	if (Find(22, L))
		printf("�ǣ�\n");
	else
		printf("��\n");
	printf("����33�Ƿ��ڸ������У�");
	if (Find(33, L))
		printf("�ǣ�\n");
	else
		printf("��\n");
	L = Delete(1, L);
	L = Delete(3, L);
	printf("----------ɾ����-----\n");
	Print(L);
	return 0;
}
