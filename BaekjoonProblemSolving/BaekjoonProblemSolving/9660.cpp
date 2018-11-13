/*
https://www.acmicpc.net/problem/9660

&Title
9660번 - 돌 게임 6

&Question
돌 게임은 두 명이서 즐기는 재밌는 게임이다.탁자 위에 
돌 N개가 있다. 상근이와 창영이는 턴을 번갈아가면서 돌을 가져가며, 
돌은 1개, 3개 또는 4개 가져갈 수 있다. 마지막 
돌을 가져가는 사람이 게임을 이기게 된다.두 사람이 완벽하게 게임을 
했을 때, 이기는 사람을 구하는 프로그램을 작성하시오. 게임은 상근이가 
먼저 시작한다. 

&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
1,000,000,000,000) 

&Output
상근이가 게임을 이기면 SK를, 창영이가 게임을 이기면 CY을 
출력한다. 

&Example
-input
6

-output
SK


*/

//시간 초과남,,,ㅋㅋ 규칙이나 다른방법찾기
/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <list>
using namespace std;

list<bool> l;

//현재 기준으로 -4, -3, -1의 경우의수에서 무조건 이길 경우 상대방이 이긴다.
bool return_result() {
	list<bool>::iterator iter;
	int i;
	bool b1, b2, b3;
	for (i = 0, iter = l.begin(); i < 4; i++, iter++) {
		if (i == 0)b1 = *iter;
		if (i == 1)b2 = *iter;
		if (i == 3)b3 = *iter;
	}
	bool rest = !(b1 & b2 & b3);
	l.pop_front();
	l.push_back(rest);
	return rest;

}

int main() {
	l.push_back(true);
	l.push_back(false);
	l.push_back(true);
	l.push_back(true);
	int N;
	scanf("%d", &N);
	for (int i = 4; i < N - 1; i++) {
		return_result();
	}

	if (N == 1) {
		printf("SK\n");
	}
	else if (N == 2) {
		printf("CY\n");
	}
	else if (N == 3) {
		printf("SK\n");
	}
	else if (N == 4) {
		printf("SK\n");
	}
	else {
		printf("%s", return_result() ? "SK" : "CY");
	}
	return 0;
}
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;


int main() {
	long long int a;
	scanf("%lld", &a);
	printf("%s\n", a % 7 == 0 || a % 7 == 2 ? "CY" : "SK");
}
*/