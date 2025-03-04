/*
https://www.acmicpc.net/problem/4597

&Title
4597번 - 패리티

&Question
1의 개수가 홀수개인 비트스트링을 "홀수 패리티"를 가지고 있다고 
한다. 또, 짝수개인 경우에는 "짝수 패리티"를 가지고 있다고 한다. 
또, 0도 짝수로 간주한다. 따라서, 1이 없는 비트 스트링은 
짝수 패리티를 가지고 있다. 마지막 숫자가 지워진 비트 스트링이 
주어지고, 이 비트 스트링의 패리티가 주어졌을 때, 마지막 숫자를 
올바르게 구하는 프로그램을 작성하시오. 

&Input
입력은 여러 개의 비트 스트링으로 이루어져 있다. 각 
비트 스트링은 한 줄로 이루어져 있고, 길이는 1~31비트이다. 또, 
비트 스트링의 마지막 문자는 e 또는 o이다. (e: 짝수 
패리티, o: 홀수 패리티) 마지막 줄에는 '#'이 주어진다. 

&Output
입력으로 주어진 각각의 비트 스트링에 대해서, 마지막 문자를 
올바른 비트로 바꾼 비트 스트링을 출력한다. 

&Example
-input
101e
010010o
1e
000e
110100101o
#

-output
1010
0100101
11
0000
1101001010


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (true) {
		cin >> s;
		if (s == "#")break;
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i++)
			if (s[i] == '1')cnt++;
		if (s[s.size() - 1] == 'o')cnt++;
		if (cnt % 2 == 0) {
			s[s.size() - 1] = '0';
		}
		else
			s[s.size() - 1] = '1';
		cout << s << endl;
	}

	return 0;
}
*/