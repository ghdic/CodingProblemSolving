/*
https://www.acmicpc.net/problem/1373

&Title
1373번 - 2진수 8진수

&Question
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오. 

&Input
첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 
넘지 않는다. 

&Output
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다. 

&Example
-input
11001100

-output
314


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N, result;
	cin >> N;
	int i = 0;
	if (N.size() % 3 == 1) {
		result += N[0];
		i = 1;
	}
	else if (N.size() % 3 == 2) {
		result += (N[0] - '0') * 2 + (N[1] - '0') + '0';
		i = 2;
	}
	for (; i < N.size(); i += 3) {
		result += (N[i] - '0') * 4 + (N[i + 1] - '0') * 2 + (N[i + 2] - '0') + '0';
	}

	cout << result << endl;
	return 0;
}
*/