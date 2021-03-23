#include<stdio.h>
#include<malloc.h>

typedef int ElementType;
typedef struct SNode* Stack;

// const ElementType MaxSize = 100;  // 不可以用const（只读变量）初始化数组（常量）
enum { MaxSize = 100 };  // 在c中，define和enum可以定义常量，推荐使用enum，使你使用的名称进入记号表

struct SNode {
	ElementType data[MaxSize];
	int top; // 栈顶元素下标
};

// 初始化堆栈
Stack CreateStack(){
	Stack s;
	s = (Stack)malloc(sizeof(struct SNode));
	s->top = -1;
	return s;
}

// 是否已满
int IsFull(Stack s) {
	return (s->top == MaxSize - 1);
}

// 是否为空
int IsEmpty(Stack s) {
	return (s->top == -1);
}

// 入栈
void Push(Stack s, ElementType item) {
	if (IsFull(s)) {
		printf("栈已满");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = item;
		return;
	}
}

// 出栈
ElementType Pop(Stack s) {
	if (IsEmpty(s)) {
		printf("堆栈空");
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
	printf("5入栈\n");
	Push(s, 7);
	printf("7入栈\n");
	Push(s, 66);
	printf("66入栈\n");
	printf("%d出栈\n", Pop(s));
	printf("%d出栈\n", Pop(s));
	return 0;
}
