/*
https://www.acmicpc.net/problem/10828

&Title
스택

&Question
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

&Input
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

&Output
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

&Example
-input
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top
-output
2
2
0
2
1
-1
0
1
-1
0
3

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	int item;
	struct Stack * next;
}stack;

stack * head=NULL;

void push(int item) {
	stack *tmp = (stack*)malloc(sizeof(stack));
	
	tmp->item= item;
	tmp->next = head;
	head = tmp;
}

int pop() {
	int item;
	if (head == NULL)
		return -1;
	stack *tmp=head;
	item = head->item;
	head = head->next;
	free(tmp);

	return item;
}

int size() {
	stack* tmp = head;
	int cnt = 0;
	while (tmp) {
		tmp = tmp->next;
		cnt++;
	}

	return cnt;
}

int empty() {
	if (head == NULL)
		return 1;
	else
		return 0;
}

int top() {
	if (head == NULL)
		return -1;
	else
		return head->item;
}

int main() {
	int N, item;
	char a[10];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &a);
		if (!strcmp(a, "push")) {
			scanf("%d", &item);
			push(item);
		}
		else if (!strcmp(a, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(a, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(a, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(a, "top")) {
			printf("%d\n", top());
		}

	}

	return 0;
}

*/