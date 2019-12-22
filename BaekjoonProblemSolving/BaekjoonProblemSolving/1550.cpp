/*
https://www.acmicpc.net/problem/1550

&Title
1550번 - 16진수

&Question
16진수 수를 입력받아서 10진수로 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 16진수 수가 주어진다. 이 수의 최대 
길이는 6글자이다. 16진수 수는 0~9와 A~F로 이루어져 있고, A~F는 
10~15를 뜻한다. 또, 이 수는 음이 아닌 정수이다. 

&Output
첫째 줄에 입력으로 주어진 16진수 수를 10진수로 변환해 
출력한다. 

&Example
-input
A

-output
10


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int num = 0;
	for (int i = 0; i < s.length(); ++i) {
		num *= 16;
		if (s[i] >= 'A') {
			num += (s[i] - 'A' + 10);
		}
		else {
			num += (s[i] - '0');
		}
	}
	cout << num << endl;
	return 0;
}
*/