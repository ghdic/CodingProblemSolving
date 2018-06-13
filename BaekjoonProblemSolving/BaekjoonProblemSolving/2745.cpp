/*
https://www.acmicpc.net/problem/2745

&Title
2745번 - 진법 변환

&Question
B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 
출력하는 프로그램을 작성하시오.10진법을 넘어가는 진법은 숫자로 표시할 수 없는 
자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.A: 
10, B: 11, ..., F: 15, ..., Y: 34, 
Z: 35 

&Input
첫째 줄에 N과 B가 주어진다. (2 ≤ B 
≤ 36)B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 
같다. 

&Output
첫째 줄에 B진법 수 N을 10진법으로 출력한다. 

&Example
-input
ZZZZZ 36

-output
60466175


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int N;
	cin >> s >> N;
	long long result = 0LL;
	for (int i = 0; i <s.size(); i++ ) {
		result *= N;
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			result += (s[i] - 'A') + 10;
		}
		else if (s[i] >= '0' &&s[i] <= '9') {
			result += (s[i] - '0');
		}
	}
	cout << result << endl;
	return 0;
}
*/