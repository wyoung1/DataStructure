#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElementType;
typedef struct TreeNode *BinTree;

struct TreeNode {
	ElementType data;
	BinTree left;
	BinTree right;
};

// 查找递归实现
BinTree Find(ElementType data, BinTree BST) {
	if (!BST) return NULL;
	if (data < BST->data) return Find(data, BST->left);
	else if (data > BST->data)return Find(data, BST->right);
	else if (data == BST->data)return BST;
}

// 查找非递归实现
BinTree IterFind(ElementType data, BinTree BST) {
	while (BST) {
		if (data < BST->data)
			BST = BST->left;
		else if (data > BST->data)
			BST = BST->right;
		else if (data == BST->data)
			return BST;	
	}
	return NULL;
}

// 查找最小值的递归实现
BinTree FindMin(BinTree BST) {
	if (!BST)
		return NULL;
	else if (BST->left)
		return FindMin(BST->left);
	else
		return BST;
}

// 查找最大值的非递归实现
BinTree FindMax(BinTree BST) {
	if (BST)  // 先判空，避免NULL结点没有right报错
		while (BST->right)
			BST = BST->right;
	return BST;
}

// 插入
BinTree Insert(ElementType data, BinTree BST) {
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->data = data;
		BST->left = NULL;
		BST->right = NULL;
	}
	else {
		if (data < BST->data)
			BST->left = Insert(data, BST->left);
		else if (data > BST->data)
			BST->right = Insert(data, BST->right);
		// 如果相等，不做处理
	}
	return BST;
}

// 删除
BinTree Delete(ElementType data, BinTree BST) {
	if (!BST) return NULL;
	BinTree temp;
	if (data < BST->data)
		BST->left = Delete(data, BST->left);
	else if (data > BST->data)
		BST->right = Delete(data, BST->right);
	else {
		if (BST->left && BST->right) { // 被删除结点有两个孩子结点
			temp = FindMin(BST->right); // 找到右子树中值最小的
			BST->data = temp->data;
			BST->right = Delete(temp->data, BST->right);
		}
		else {
			temp = BST;
			if (!BST->right)
				BST = BST->left;
			else if (!BST->left)
				BST = BST->right;
			free(temp);
		}
	}
	return BST;
}

// 中序遍历 
void  InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->left);  // 进入左子树 
		cout << BT->data;  // 打印根 
		InOrderTraversal(BT->right);  // 进入右子树 
	}
}

int main() {
	BinTree BST = NULL;
	BST = Insert(5, BST);
	BST = Insert(7, BST);
	BST = Insert(3, BST);
	BST = Insert(1, BST);
	BST = Insert(2, BST);
	BST = Insert(4, BST);
	BST = Insert(6, BST);
	BST = Insert(8, BST);
	BST = Insert(9, BST);
	/*
				5
			   /\
			  3  7
			 /\	 /\
			1 4 6  8
			\      \
			 2      9
	*/
	cout << "中序遍历的结果是：";
	InOrderTraversal(BST);
	cout << endl;
	cout << "查找最小值是：" << FindMin(BST)->data << endl;
	cout << "查找最大值是：" << FindMax(BST)->data << endl;
	cout << "查找值为3的结点左子树结点值为：" << Find(3, BST)->left->data << endl;
	cout << "查找值为7的结点右子树结点值为：" << IterFind(7, BST)->right->data << endl;
	cout << "删除值为5的结点" << endl;
	Delete(5, BST);
	/*
				6
			   /\
			  3  7
			 /\	  \
			1 4    8
			\      \
			 2      9
	*/
	cout << "中序遍历的结果是：";
	InOrderTraversal(BST);
	cout << endl;
	return 0;
}

