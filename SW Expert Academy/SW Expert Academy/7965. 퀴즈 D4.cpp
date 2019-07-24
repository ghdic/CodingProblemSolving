/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWuSh2IKmu0DFASy&categoryId=AWuSh2IKmu0DFASy&categoryType=CODE

7965. 퀴즈 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


화섭이는 백수다. 학교도 다니기 싫어서 휴학하고서 매일 집에서 뒹굴기만 한다. 이를 안타깝게 생각한 재성이가 한가지 제안을 했다.

재성: “화섭아. 이 문제를 풀면 내가 밥을 사줄게.”

화섭: “오!! 어떤 문제야?? 바로 풀어볼게!!”

재성: “내가 너에게 N이라는 숫자를 주면 너는 를 구하는거야.”

화섭: “윽. 난 글렀어…”

화섭이가 공짜로 밥을 얻어먹을 수 있게 도와주자. 단, 결과가 클 수 있기 때문에 1,000,000,007로 나눈 나머지를 구해주자.


[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 자연수 N(1 ≤ N ≤ 106)가 주어진다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다  을 1,000,000,007으로 나눈 나머지를 출력하라.
 
입력
3
1
2
1000
// 테스트 케이스 개수
// 첫 번째 테스트 케이스, N = 1
// 두 번째 테스트 케이스, N = 2
// 세 번째 테스트 케이스, N = 1000
input.txt
출력
#1 1
#2 5
#3 7070481
// 첫 번째 테스트 케이스 결과
// 두 번째 테스트 케이스 결과
// 세 번째 테스트 케이스 결과
output.txt
*/

/*
#include <iostream>
using namespace std;
#define MOD 1000000007

int T, n;
int cache[1000001];

int func(int k) {
	long long ret = 1;
	long long factor = k;
	int exp = k;
	while (exp) { // 암호학 & 정수론에서 다루는 지수승 빠르게 계산하는 방식
		if (exp & 1) { // exp가 홀수이면
			ret *= factor;
		}
		exp >>= 1; // 짝수 일때 ret 업뎃 x 1/2 해줌
		factor *= factor; // n^x -> n^2x
		factor %= MOD;
		ret %= MOD;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	cache[1] = 1;
	for (int i = 2; i < 1000001; ++i)
		cache[i] = (cache[i - 1] + func(i)) % MOD;
	for (int t = 1; t < T + 1; ++t) {
		cin >> n;
		cout << "#" << t << " " << cache[n] << "\n";
	}
	return 0;
}
*/