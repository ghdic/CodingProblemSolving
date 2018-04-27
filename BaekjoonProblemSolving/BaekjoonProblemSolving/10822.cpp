/*
https://www.acmicpc.net/problem/10822

&Title
10822번 - 더하기

&Question
숫자와 콤마로만 이루어진 문자열 S가 주어진다. 이 때, 
S에 포함되어있는 자연수의 합을 구하는 프로그램을 작성하시오.S의 첫 문자와 
마지막 문자는 항상 숫자이고, 콤마는 연속해서 주어지지 않는다. 주어지는 
수는 항상 자연수이다. 

&Input
첫째 줄에 문자열 S가 주어진다. S의 길이는 최대 
100이다. 포함되어있는 정수는 1,000,000보다 작거나 같은 자연수이다. 

&Output
문자열 S에 포함되어 있는 자연수의 합을 출력한다. 

&Example
-input
10,20,30,50,100

-output
210


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, sum = 0, num = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')num = num * 10 + (s[i] - '0');
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