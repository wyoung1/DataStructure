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

// ���ҵݹ�ʵ��
BinTree Find(ElementType data, BinTree BST) {
	if (!BST) return NULL;
	if (data < BST->data) return Find(data, BST->left);
	else if (data > BST->data)return Find(data, BST->right);
	else if (data == BST->data)return BST;
}

// ���ҷǵݹ�ʵ��
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

// ������Сֵ�ĵݹ�ʵ��
BinTree FindMin(BinTree BST) {
	if (!BST)
		return NULL;
	else if (BST->left)
		return FindMin(BST->left);
	else
		return BST;
}

// �������ֵ�ķǵݹ�ʵ��
BinTree FindMax(BinTree BST) {
	if (BST)  // ���пգ�����NULL���û��right����
		while (BST->right)
			BST = BST->right;
	return BST;
}

// ����
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
		// �����ȣ���������
	}
	return BST;
}

// ɾ��
BinTree Delete(ElementType data, BinTree BST) {
	if (!BST) return NULL;
	BinTree temp;
	if (data < BST->data)
		BST->left = Delete(data, BST->left);
	else if (data > BST->data)
		BST->right = Delete(data, BST->right);
	else {
		if (BST->left && BST->right) { // ��ɾ��������������ӽ��
			temp = FindMin(BST->right); // �ҵ���������ֵ��С��
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

// ������� 
void  InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->left);  // ���������� 
		cout << BT->data;  // ��ӡ�� 
		InOrderTraversal(BT->right);  // ���������� 
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
	cout << "��������Ľ���ǣ�";
	InOrderTraversal(BST);
	cout << endl;
	cout << "������Сֵ�ǣ�" << FindMin(BST)->data << endl;
	cout << "�������ֵ�ǣ�" << FindMax(BST)->data << endl;
	cout << "����ֵΪ3�Ľ�����������ֵΪ��" << Find(3, BST)->left->data << endl;
	cout << "����ֵΪ7�Ľ�����������ֵΪ��" << IterFind(7, BST)->right->data << endl;
	cout << "ɾ��ֵΪ5�Ľ��" << endl;
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
	cout << "��������Ľ���ǣ�";
	InOrderTraversal(BST);
	cout << endl;
	return 0;
}

