/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWnghFyq9eMDFAQU

7466. 팩토리얼과 최대공약수 D4
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

두 자연수 N과 K가 주어졌을 때에 N!과 K의 최대공약수를 구하는 프로그램을 작성하라.

예를 들어, N = 3, K = 10 이라면, gcd(3!,10) = gcd(6,10) = 2가 된다.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 개의 정수 N,K( 1 ≤ N, K ≤ 109) 가 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

N!과 K의 최대공약수를 출력한다.
입력
3
3 10
13 182
100 1000 // 테스트 케이스 개수
// 첫 번째 테스트 케이스

  s_input.txt
출력
#1 2
#2 182
#3 1000 // 첫 번째 테스트 케이스 결과

  s_output.txt
*/
/*
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a >= b)return b;
	int val = 1;
	for (int i = 2; i <= b; i++) {
		if(b % i == 0){
			b /= i;
			if (i <= a) {
				val *= i;
			}
		}
	}
	return val;
}
int main() {
	int T, a, b;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> a >> b;
		cout << "#" << t + 1 << " " << gcd(a, b) << "\n";
	}
	return 0;
}
*/

//머야 이렇게 해도 빠르네...?
/*
#include<iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "#" << t << " ";
		int N, K; cin >> N >> K;
		int result = 1;
		if (N >= K)
		{
			result = K;
		}
		else { for (int i = N; i > 0; i--) { if (K % i == 0) { result *= i; K /= i; } } } cout << result << endl;
	} return 0;
}
*/