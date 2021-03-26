#include<iostream>
using namespace std;
const int MaxSize = 100;
typedef struct SNode* Stack;

struct SNode {
	int data[MaxSize];
	int top;
	SNode(int x) : top(x) {}
};

// ��ʼ��ջ
Stack CreateStack() {
	Stack s = new SNode(-1);
	return s;
}

// �ж�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack s) {
	if (s->top == -1)return true;
	return false;
}

// �ж�ջ�Ƿ�����
bool IsFull(Stack s) {
	if (s->top == MaxSize - 1)return true;
	return false;
}

// ��ջ
Stack Push(Stack s, int val){
	if (IsFull(s))return s;
	s->data[++(s->top)] = val;
	return s;
}

// ��ջ
Stack Pop(Stack s) {
	if (IsEmpty(s))return s;
	(s->top)--;
	return s;
}

// �鿴ջ��Ԫ��
int GetElement(Stack s) {
	if (IsEmpty(s)) {
		printf("��ǰջΪ��");
		return -1;
	}
	else {
		return s->data[s->top];
	}
}

int main() {
	Stack s;
	int a;
	s = CreateStack();
	s = Push(s, 1);
	s = Push(s, 2);
	s = Push(s, 3);
	s = Pop(s);
	a = GetElement(s);
	cout << a << endl;
	return 0;
}