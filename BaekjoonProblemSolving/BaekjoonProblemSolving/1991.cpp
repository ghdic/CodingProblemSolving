/*
https://www.acmicpc.net/problem/1991

&Title
1991번 - 트리 순회

&Question
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder 
traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.예를 들어 
위와 같은 이진 트리가 입력되면,전위 순회한 결과 : ABDCEFG 
// (루트) (왼쪽 자식) (오른쪽 자식)중위 순회한 결과 : 
DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)후위 순회한 결과 
: DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)가 된다. 


&Input
첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 
둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 
자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 
차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
자식 노드가 없는 경우에는 .으로 표현된다. 

&Output
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 
셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 
알파벳을 공백 없이 출력하면 된다. 

&Example
-input
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .

-output
ABDCEFG
DBAECFG
DBEGFCA


*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include <queue>
//#include <malloc.h>
//#include <cstdlib>
//using namespace std;
//
//struct TreeNode {
//	char key;
//	TreeNode *LNode;
//	TreeNode *RNode;
//};
//
//TreeNode *Target;
//
//
//TreeNode* FindNode(char item) {
//	TreeNode *temp = Target;
//	queue<TreeNode*> q;
//	q.push(temp);
//
//	while (!q.empty()) {
//		TreeNode* t = q.front();
//		q.pop();
//		if (t->key == item)
//			return t;
//
//		if (t->LNode != NULL && t->LNode->key != '.') {
//			q.push(t->LNode);
//		}
//		if (t->RNode != NULL && t->RNode->key != '.') {
//			q.push(t->RNode);
//		}
//	}
//	return NULL;
//}
//
//void Add_Node(char root, char left, char right) {
//	TreeNode *LeftNode = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode *RightNode = (TreeNode*)malloc(sizeof(TreeNode));
//	LeftNode->key = left;
//	LeftNode->LNode = NULL;
//	LeftNode->RNode = NULL;
//	RightNode->key = right;
//	RightNode->LNode = NULL;
//	RightNode->RNode = NULL;
//
//	TreeNode *Root;
//
//	if (Target == NULL) {
//		Root = (TreeNode*)malloc(sizeof(TreeNode));
//		Root->key = root;
//		Target = Root;
//	}
//	else {
//		Root = FindNode(root);
//		if (Root == NULL)
//			exit(-1);
//	}
//	Root->LNode = LeftNode;
//	Root->RNode = RightNode;
//}
//
//void PreOrderTraversal(TreeNode* node) {
//	if (node == NULL || node->key == '.')
//		return;
//
//	printf("%c", node->key);
//	PreOrderTraversal(node->LNode);
//	PreOrderTraversal(node->RNode);
//}
//
//void InOrderTraversal(TreeNode* node) {
//	if (node == NULL || node->key == '.')
//		return;
//
//	InOrderTraversal(node->LNode);
//	printf("%c", node->key);
//	InOrderTraversal(node->RNode);
//}
//
//void PostOrderTraversal(TreeNode* node) {
//	if (node == NULL || node->key == '.')
//		return;
//
//	PostOrderTraversal(node->LNode);
//	PostOrderTraversal(node->RNode);
//	printf("%c", node->key);
//}
//int main() {
//	int N;
//	char root, left, right;
//	Target = NULL;
//
//	scanf("%d", &N);
//	while (N--) {
//		scanf(" %c %c %c", &root, &left, &right);
//
//		Add_Node(root, left, right);
//	}
//
//	PreOrderTraversal(Target);
//	puts("");
//	InOrderTraversal(Target);
//	puts("");
//	PostOrderTraversal(Target);
//	puts("");
//
//	return 0;
//}


/*
#include <iostream>
using namespace std;

struct node {
	char value;
	node* left;
	node* right;

	node(char key) : value(key) {
		left = right = NULL;
	}
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();

	void insert(char a, char b, char c); // 올바른 위치에 노드를 생성해 key를 집어넣는다.
	node* find(char key); // 해당 key를 가진 노드가 있는지 찾고 있으면 해당 노드를, 없으면 null을 반환한다.
	void preorder_print(); // 전위순회
	void inorder_print(); // 중위순회
	void postorder_print(); // 후위순회

private:
	node* root;

	void destroy_tree(node* leaf); // 순회하며 할당된 노드들을 삭제한다.
	void insert(char a, char b, char c, node* leaf);
	node* find(char key, node* leaf);
	void preorder_print(node* leaf); // root -> left -> right
	void inorder_print(node* leaf); // left -> root -> right
	void postorder_print(node* leaf); // left -> right -> root

};

BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy_tree(root);
}

void BinaryTree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::insert(char a, char b, char c) {
	if (root) insert(a, b, c, root);
	else {
		root = new node(a);
		root->left = (b == '.' ? NULL : new node(b));
		root->right = (c == '.' ? NULL : new node(c));
	}
}

void BinaryTree::insert(char a, char b, char c, node* leaf) {
	node* temp = find(a);
	temp->left = (b == '.' ? NULL : new node(b));
	temp->right = (c == '.' ? NULL : new node(c));
}

node* BinaryTree::find(char key) {
	return find(key, root);
}

node* BinaryTree::find(char key, node* leaf) {
	if (leaf == NULL)return NULL;
	if (leaf->value == key)return leaf;
	node* temp;
	temp = find(key, leaf->left);
	if (temp)return temp;
	temp = find(key, leaf->right);
	if (temp)return temp;
	return NULL;
}

void BinaryTree::preorder_print() {
	preorder_print(root);
	cout << '\n';
}

void BinaryTree::preorder_print(node* leaf) {
	if (leaf == NULL)return;
	cout << leaf->value;
	preorder_print(leaf->left);
	preorder_print(leaf->right);
}

void BinaryTree::inorder_print() {
	inorder_print(root);
	cout << '\n';
}

void BinaryTree::inorder_print(node* leaf) {
	if (leaf == NULL)return;
	inorder_print(leaf->left);
	cout << leaf->value;
	inorder_print(leaf->right);
}

void BinaryTree::postorder_print() {
	postorder_print(root);
	cout << '\n';
}

void BinaryTree::postorder_print(node* leaf) {
	if (leaf == NULL)return;
	postorder_print(leaf->left);
	postorder_print(leaf->right);
	cout << leaf->value;
}

int n;

int main() {
	ios::sync_with_stdio(false);
	BinaryTree* tree = new BinaryTree();
	char a, b, c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		tree->insert(a, b, c);
	}
	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	return 0;
}
*/