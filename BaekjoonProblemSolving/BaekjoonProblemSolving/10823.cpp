/*
https://www.acmicpc.net/problem/10823

&Title
10823번 - 더하기 2

&Question
숫자와 콤마로만 이루어진 문자열 S가 주어진다. 이 때, 
S에 포함되어있는 자연수의 합을 구하는 프로그램을 작성하시오.S의 첫 문자와 
마지막 문자는 항상 숫자이고, 콤마는 연속해서 주어지지 않는다. 주어지는 
수는 항상 자연수이다. 

&Input
문자열 S가 여러 줄에 걸쳐서 주어진다. S의 길이는 
최대 10,000이다. 포함되어있는 정수는 1,000,000보다 작거나 같은 자연수이다. 

&Output
문자열 S에 포함되어 있는 자연수의 합을 출력한다. 

&Example
-input
10,20,
3
0,50
,1
00

-output
210


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string tmp;
	while (cin >> tmp) {
		s += tmp;
	}
	int num = 0, sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num = 10 * num + (s[i] - '0');
		}
		else if (s[i] == ',') {
			sum += num;
			num = 0;
		}
	}
	sum += num;
	cout << sum << endl;
	return 0;
}
*/