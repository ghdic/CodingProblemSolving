/*
https://www.acmicpc.net/problem/1212

&Title
1212번 - 8진수 2진수

&Question
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오. 

&Input
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 
넘지 않는다. 

&Output
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 
0인 경우를 제외하고는 반드시 1로 시작해야 한다. 

&Example
-input
314

-output
11001100


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class change {
private:
	string str;
	int len;
	string str1[8] = { "0", "1", "10", "11", "110", "101", "110", "111" };
	string str2[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
public:
	void setStr() {
		cin >> str;
		len = static_cast<int>(str.size());
	}
	void callSolution() {
		this->printFirstNum(str[0] - '0');     //8진수 맨 처음 수

		for (int i = 1; i<len; i++) {
			this->printNum(str[i] - '0');
		}
	}
	void printFirstNum(int num) const {
		cout << str1[num];
	}
	void printNum(int num) const {
		cout << str2[num];
	}
};

int main(void) {
	change oct;
	oct.setStr();
	oct.callSolution();
	return 0;
}
*/