#include<iostream>
#include<stack>
using namespace std;

class MyQueue {

public:
	stack<int> in, out;
	/** Initialize your data structure here. */
	MyQueue() {
		
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		in2out();
		int top = out.top();
		out.pop();
		return top;
	}

	/** Get the front element. */
	int peek() {
		in2out();
		return out.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}

	void in2out() {
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.top());
				in.pop();
			}
		}
	}
};

int main() {
	MyQueue* obj = new MyQueue();
	obj->push(3);
	obj->push(4);
	obj->push(5);
	obj->push(6);
	cout << obj->peek() << endl;
	cout << obj->pop() << endl;
	return 0;
}