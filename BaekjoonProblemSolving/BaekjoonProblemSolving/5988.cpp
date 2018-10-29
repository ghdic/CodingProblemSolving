/*
https://www.acmicpc.net/problem/5988

&Title
5988번 - 홀수일까 짝수일까

&Question
짝이 없는 경재는 매일 홀로 있다보니 홀수를 판별할 
수 있는 능력이 생겼다. 창식이는 경재의 말이 사실인지 그 
능력을 시험해보려 한다. 창식이의 의심이 끝이 없을 것 같아 
N개만 확인하기로 정했다.N개의 정수가 주어지면 홀수인지 짝수인지를 출력하는 프로그램을 
만들어 경재의 능력을 검증할 수 있게 도와주자. 

&Input
첫 번째 줄에 숫자의 개수 N(1 <= N 
<= 100)이 주어진다.두 번째 줄부터 N+1번째 줄에 걸쳐 홀수인지 
짝수인지 확인할 정수 K (1 <= K <= 10^60)가 
주어진다. 

&Output
N개의 줄에 걸쳐 한 줄씩 정수 K가 홀수라면 
'odd'를, 짝수라면 'even'을 출력한다. 

&Example
-input
2
1024
5931

-output
even
odd


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		int last = s[s.length() - 1] - '0';
		if (last % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}
	return 0;
}
*/