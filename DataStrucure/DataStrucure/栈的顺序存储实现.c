#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct SNode* Stack;

// const ElementType MaxSize = 100;  // ��������const��ֻ����������ʼ�����飨������
enum { MaxSize = 100 };  // ��c�У�define��enum���Զ��峣�����Ƽ�ʹ��enum��ʹ��ʹ�õ����ƽ���Ǻű�

struct SNode {
	ElementType data[MaxSize];
	int top; // ջ��Ԫ���±�
};

// ��ʼ����ջ
Stack CreateStack(){
	Stack s;
	s = (Stack)malloc(sizeof(struct SNode));
	s->top = -1;
	return s;
}

// �Ƿ�����
int IsFull(Stack s) {
	return (s->top == MaxSize - 1);
}

// �Ƿ�Ϊ��
int IsEmpty(Stack s) {
	return (s->top == -1);
}

// ��ջ
void Push(Stack s, ElementType item) {
	if (IsFull(s)) {
		printf("ջ����");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

// ��ջ
ElementType Pop(Stack s) {
	if (IsEmpty(s)) {
		printf("��ջ��");
		return;
	}
	else {
		ElementType val = s->data[s->top];
		s->top--;
		return val;
	}
}

int main() {
	Stack s;
	s = CreateStack();
	Push(s, 5);
	printf("5��ջ\n");
	Push(s, 7);
	printf("7��ջ\n");
	Push(s, 66);
	printf("66��ջ\n");
	printf("%d��ջ\n", Pop(s));
	printf("%d��ջ\n", Pop(s));
	return 0;
}
