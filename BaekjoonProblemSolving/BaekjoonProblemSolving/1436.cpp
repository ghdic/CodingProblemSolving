/*
https://www.acmicpc.net/problem/1436

&Title
1436번 - 영화감독 숌

&Question
666은 종말을 나타내는 숫자라고 한다. 따라서, 많은 블록버스터 
영화에서는 666이 들어간 제목을 많이 사용한다. 영화감독 숌은 세상의 
종말 이라는 시리즈 영화의 감독이다. 조지 루카스는 스타워즈를 만들 
때, 스타워즈 1, 스타워즈 2, 스타워즈 3, 스타워즈 4, 
스타워즈 5, 스타워즈 6과 같이 이름을 지었고, 피터 잭슨은 
반지의 제왕을 만들 때, 반지의 제왕 1, 반지의 제왕 
2, 반지의 제왕 3과 같이 영화 제목을 지었다.하지만 숌은 
자신이 조지 루카스와 피터 잭슨을 뛰어넘는다는 것을 보여주기 위해서 
영화 제목을 좀 다르게 만들기로 했다.종말의 숫자란 어떤 수에 
6이 적어도 3개이상 연속으로 들어가는 수를 말한다. 제일 작은 
종말의 숫자는 666이고, 그 다음으로 큰 수는 1666, 2666, 
3666, .... 과 같다.따라서, 숌은 첫 번째 영화의 제목은 
세상의 종말 666, 두 번째 영화의 제목은 세상의 종말 
1666 이렇게 이름을 지을 것이다. 일반화해서 생각하면, N번째 영화의 
제목은 세상의 종말 (N번째로 작은 종말의 숫자) 와 같다.숌이 
만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오. 
숌은 이 시리즈를 항상 차례대로 만들고, 다른 영화는 만들지 
않는다. 

&Input
첫째 줄에 숫자 N이 주어진다. N은 10,000보다 작거나 
같은 자연수이다. 

&Output
첫째 줄에 N번째 영화의 제목에 들어간 수를 출력한다. 


&Example
-input
2

-output
1666


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;
#define SIZE 10000
int main() {
	int N;
	scanf("%d", &N);

	int num = 666;
	int turn = 1;

	while (true) {
		if (turn == N)break;
		num++;
		string s = to_string(num);
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '6')cnt++;
			else cnt = 0;

			if (cnt == 3) {
				turn++;
				break;
			}
		}
		
	}
	printf("%d\n", num);
	return 0;
}
*/





/*
브루트포스로 풀어야 됬다니... 이게 대부분의 코드고

아래 풀이가 가장 아름다운 풀이인듯.. 이렇게 풀려다 망했어 ㅜㅜ

c++
```
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, check = 0, print[10], pc = 0, k;
void found(int now, int kind) {
	if (now == 3 && kind == 0 && print[pc - 1] != 6) {
		n--;
		if (n == 0) {
			check = 1;
			for (int i = 0; i < pc; i++) {
				printf("%d", print[i]);
			}
			printf("666");
		}
		return;
	}
	if (now == 0 && kind == 1) {
		n--;
		if (n == 0) {
			check = 1;
			for (int i = 0; i < pc; i++) {
				printf("%d", print[i]);
			}
		}
		return;
	}
	else if (now > 0) {
		int i;
		for (i = 0; i <= 9; i++) {
			if (pc != 0 || i != 0) {
				print[pc++] = i;
				if (pc >= 3 && print[pc - 1] == 6 && print[pc - 2] == 6 && print[pc - 3] == 6) {
					found(now - 1, 1);
				}
				else {
					found(now - 1, kind);
				}
				if (check)return;
				print[--pc] = 0;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (k = 3;; k++) {
		pc = 0;
		found(k, 0);
		if (check)break;
	}
	return 0;
}

```
*/