/*
https://www.acmicpc.net/problem/10845

&Title
10845번 - 큐

&Question
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 
처리하는 프로그램을 작성하시오.명령은 총 여섯 가지이다.push X: 정수 X를 
큐에 넣는 연산이다.pop: 큐에서 가장 앞에 있는 정수를 빼고, 
그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 
-1을 출력한다.size: 큐에 들어있는 정수의 개수를 출력한다.empty: 큐가 비어있으면 
1, 아니면 0을 출력한다.front: 큐의 가장 앞에 있는 정수를 
출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.back: 
큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 
정수가 없는 경우에는 -1을 출력한다. 

&Input
첫째 줄에 주어지는 명령의 수 N (1 ≤ 
N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 
하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 
같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다. 

&Output
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다. 


&Example
-input
15
push 1
push 2
front
back
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
front

-output
1
2
2
0
1
2
-1
0
1
-1
0
3


*/

/*
#include <iostream>
#include <string>
using namespace std;

typedef struct que {
	que * next;
	int item;
}que;

que * head = NULL;

int empty() {
	if (!head)return 1;
	else return 0;
}
void push(int n) {
	que * k = new que, *temp;
	k->item = n;
	k->next = NULL;
	if (empty())head = k;
	else {
		temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = k;
	}
}

int pop() {
	if (empty())return -1;
	int itm = head->item;
	que * k = head;
	head = head->next;
	delete k;
	return itm;
}

int qsize() {
	int cnt = 0;
	que * temp = head;
	while (temp) {
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

int front() {
	if (empty())return -1;
	else return head->item;
}

int back() {
	if (empty())return -1;
	que * temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	return temp->item;
}
int main() {
	int N, num;
	string command;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			push(num);
		}
		else if (command == "pop") {
			cout << pop() << endl;
		}
		else if (command == "size") {
			cout << qsize() << endl;
		}
		else if (command == "empty") {
			cout << empty() << endl;
		}
		else if (command == "front") {
			cout << front() << endl;
		}
		else if (command == "back") {
			cout << back() << endl;
		}
	}

	return 0;
}
*/