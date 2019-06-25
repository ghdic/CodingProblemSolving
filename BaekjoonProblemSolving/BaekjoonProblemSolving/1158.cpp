/*
https://www.acmicpc.net/problem/1158

&Title
1158번 - 조세퍼스 문제

&Question
조세퍼스 문제는 다음과 같다.1번부터 N번까지 N명의 사람이 원을 
이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 
K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 
원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 
사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 
(N, K)-조세퍼스 순열이라고 한다. 예를 들어 (7, 3)-조세퍼스 순열은 
<3, 6, 2, 7, 5, 1, 4>이다.N과 K가 주어지면 
(N, K)-조세퍼스 순열을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N과 K가 빈 칸을 사이에 두고 
순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000) 


&Output
예제와 같이 조세퍼스 순열을 출력한다. 

&Example
-input
7 3

-output
<3, 6, 2, 7, 5, 1, 4>


*/

/*
#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int result[5001] = {};
int main() {
	int N, K;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	ListNode* head = new ListNode(1), * temp = head;
	for (int i = 2; i <= N; i++) {
		temp->next = new ListNode(i);
		temp = temp->next;
	}
	temp->next = head;
	int idx = 0, cnt = K - 1;
	while (head != head->next) {
		while (cnt--) {
			if (cnt == 0)temp = head;
			head = head->next;
		}
		result[idx++] = head->val;
		temp->next = head->next;
		head = head->next;
		cnt = K - 1;
	}
	result[idx++] = head->val;
	cout << "<";
	for (int i = 0; i < idx - 1; i++)cout << result[i] << ", ";
	cout << result[idx - 1] << ">\n";
	return 0;
}
*/

/*
노드로 리스트만들어서 하는거보다...
strcpy써가면서 하는게 더 빠르다니...
이건 너무한거 아니냐구~wkd
```
#include <stdio.h>
#include <string.h>

int main()
{
	int N, M, size, cur, queue[5001];
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) queue[i] = i;
	printf("<%d", queue[M]);
	if(M != N) memcpy(queue + M, queue + M + 1, sizeof(int)*(N - M));
	size = N - 1;
	cur = M;
	while (size > 0)
	{
		cur += M - 1;
		while(cur > size) cur -= size;
		printf(", %d", queue[cur]);
		memcpy(queue + cur, queue + cur + 1, sizeof(int)*(size - cur));
		size--;
	}
	printf(">\n");
	return 0;
}
```
*/