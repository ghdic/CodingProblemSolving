/*
https://www.acmicpc.net/problem/11723

&Title
11723번 - 집합

&Question
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 
프로그램을 작성하시오.add x: S에 x를 추가한다. (1 ≤ x 
≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.remove 
x: S에서 x를 제거한다. (1 ≤ x ≤ 20) 
S에 x가 없는 경우에는 연산을 무시한다.check x: S에 x가 
있으면 1을, 없으면 0을 출력한다.toggle x: S에 x가 있으면 
x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 
20)all: S를 {1, 2, ..., 20} 으로 바꾼다.empty: S를 
공집합으로 바꾼다. 

&Input
첫째 줄에 수행해야 하는 연산의 수 M (1 
≤ M ≤ 3,000,000)이 주어진다.둘째 줄부터 M개의 줄에 수행해야 
하는 연산이 한 줄에 하나씩 주어진다. 

&Output
check 연산이 주어질때마다, 결과를 출력한다. 

&Example
-input
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1

-output
1
1
0
1
0
1
0
1
0
1
1
0
0
0
1
0


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
using namespace std;

//집합
int X[20], idx=0;

void add(int x) {
	if (idx >= 20) return;
	for (int i = 0; i < idx; i++)
		if (X[i] == x) return;
	X[idx++] = x;
}

void remove(int x) {
	if (idx <= 0)return;
	for(int i=0;i<idx;i++)
		if (X[i] == x) {
			X[i] = X[idx-1];
			idx--;
			return;
		}
}

bool check(int x) {
	for(int i=0;i<idx;i++)
		if (X[i] == x) {
			return true;
		}
	return false;
}

void toggle(int x) {
	for (int i = 0; i < idx; i++)
		if (X[i] == x) {
			remove(x);
			return;
		}
	add(x);
}

void all() {
	for (int i = 0; i < 20; i++) {
		X[i] = i + 1;
	}
	idx = 20;
}

void empty() {
	idx = 0;
}

int main() {
	int Command, num;
	char s[7];
	scanf("%d", &Command);
	for (int i = 0; i < Command; i++) {
		scanf("%s %d", s, &num);

		if (strcmp(s, "add")==0) {
			add(num);
		}
		else if (strcmp(s, "remove") == 0) {
			remove(num);
		}
		else if (strcmp(s, "check") == 0) {
			printf("%d\n", check(num));
		}
		else if (strcmp(s, "toggle") == 0) {
			toggle(num);
		}
		else if (strcmp(s, "all") == 0) {
			all();
		}
		else if (strcmp(s, "empty") == 0) {
			empty();
		}
	}
	return 0;
}
*/