/*
https://www.acmicpc.net/problem/3062

&Title
3062번 - 수 뒤집기

&Question
수 124를 뒤집으면 421이 되고 이 두 수를 
합하면 545가 된다. 124와 같이 원래 수와 뒤집은 수를 
합한 수가 좌우 대칭이 되는지 테스트 하는 프로그램을 작성하시오. 


&Input
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄에 하나의 정수 N(10 ≤ 
N ≤ 100000)이 주어진다. 

&Output
각 테스트 케이스에 대해서 원래 수와 뒤집은 수를 
합한 수가 좌우 대칭이 되면 YES를 아니면 NO를 한 
줄에 하나씩 출력한다. 

&Example
-input
4
13
58
120
5056

-output
YES
NO
YES
NO


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, reverse = 0, b;
		scanf("%d", &a);
		b = a;
		while (b) {
			reverse = reverse * 10 + b % 10;
			b /= 10;
		}
		a += reverse;
		string s = to_string(a);
		bool check = true;
		for (int j = 0; j < s.size() / 2; j++) {
			if (s[j] != s[s.size() - j - 1]) {
				check = false;
				break;
			}
		}
		printf("%s\n", check ? "YES" : "NO");
	}
	return 0;
}
*/