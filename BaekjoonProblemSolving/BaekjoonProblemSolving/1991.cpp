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
