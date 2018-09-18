/*
https://www.acmicpc.net/problem/1431

&Title
1431번 - 시리얼 번호

&Question
다솜이는 기타를 많이 가지고 있다. 그리고 각각의 기타는 
모두 다른 시리얼 번호를 가지고 있다. 다솜이는 기타를 빨리 
찾아서 빨리 사람들에게 연주해주기 위해서 기타를 시리얼 번호 순서대로 
정렬하고자 한다.모든 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)로 
이루어져 있다.시리얼번호 A가 시리얼번호 B의 앞에 오는 경우는 다음과 
같다.A와 B의 길이가 다르면, 짧은 것이 먼저 온다.만약 서로 
길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 
합을 비교해서 작은 합을 가지는 것이 먼저온다. (숫자인 것만 
더한다)만약 1,2번 둘 조건으로도 비교할 수 없으면, 사전순으로 비교한다. 
숫자가 알파벳보다 사전순으로 작다.시리얼이 주어졌을 때, 정렬해서 출력하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 기타의 개수 N이 주어진다. N은 1,000보다 
작거나 같다. 둘째 줄부터 N개의 줄에 시리얼 번호가 하나씩 
주어진다. 시리얼 번호의 길이는 최대 50이고, 알파벳 대문자 또는 
숫자로만 이루어져 있다. 시리얼 번호는 중복되지 않는다. 

&Output
첫째 줄부터 차례대로 N개의 줄에 한줄에 하나씩 시리얼 
번호를 정렬한 결과를 출력한다. 

&Example
-input
5
ABCD
145C
A
A910
Z321

-output
A
ABCD
Z321
145C
A910


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int sum_num(const string &a) {
	int num = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
			num += a[i] - '0';
	return num;
}

bool cmp(const string &a, const string &b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		int num1 = sum_num(a);
		int num2 = sum_num(b);
		if (num1 != num2) {
			return num1 < num2;
		}
		else
			return a < b;
	}
}
int main() {
	int N;
	vector<string> v;
	string s;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), cmp);

	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
*/