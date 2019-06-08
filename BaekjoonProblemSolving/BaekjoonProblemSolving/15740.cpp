/*
https://www.acmicpc.net/problem/15740

&Title
15740번 - A+B - 9서브태스크

&Question
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 A와 B (-1010000 ≤ A, B 
≤ 1010000)가 주어진다. 

&Output
첫째 줄에 A+B를 출력한다. 

&Example
-input
1 2

-output
3

-input
-60 40

-output
-20

-input
-999999999 1000000000

-output
1

-input
1099511627776 1073741824
-output
1100585369600

-input
123456789123456789123456789 987654321987654321987654321

-output
1111111111111111111111111110


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string stringSum(string& A, string& B, int& a, int& b);
string stringSub(string& A, string& B, int& a, int& b);

int main() {
	string A, B;
	ios::sync_with_stdio(false);
	cin >> A >> B;
	int a = A.length() - 1, b = B.length() - 1;

	bool signA = true, signB = true;
	if (A[0] == '+') {
		A = A.substr(1, a + 1);
		a--;
		signA = true;
	}
	else if (A[0] == '-') {
		A = A.substr(1, a + 1);
		a--;
		signA = false;
	}

	if (B[0] == '+') {
		B = B.substr(1, b + 1);
		b--;
		signB = true;
	}
	else if (B[0] == '-') {
		B = B.substr(1, b + 1);
		b--;
		signB = false;
	}

	if (signA && signB) {
		A = stringSum(A, B, a, b);
	}
	else if (signA && !signB) {
		A = stringSub(A, B, a, b);
	}
	else if (!signA && signB) {
		A = stringSub(B, A, b, a);
	}
	else if (!signA && !signB) {
		A = stringSum(A, B, a, b);
		A = "-" + A;
	}
	cout << A << endl;
	return 0;
}

string stringSum(string &A, string &B, int &a, int &b) {
	bool up = false;
	string s = "";
	int add;
	while (a != -1 && b != -1) {
		add = A[a] - '0' + B[b] - '0' + up;
		s = (char)(add % 10 + '0') + s;
		if (add / 10) up = true;
		else up = false;
		a--, b--;
	}

	while (a != -1) {
		add = A[a] - '0' + up;
		s = (char)(add % 10 + '0') + s;
		if (add / 10)up = true;
		else up = false;
		a--;
	}
	while (b != -1) {
		add = B[b] - '0' + up;
		s = (char)(add % 10 + '0') + s;
		if (add / 10)up = true;
		else up = false;
		b--;
	}
	if (up)s = "1" + s;
	return s;
}

string stringSub(string &A, string &B, int &a, int &b) {
	bool down = false, Sign = true;
	string s = "";
	int sub;
	if (A.size() == B.size()) {
		if (A < B) {
			Sign = false;
			swap(A, B);
			swap(a, b);
		}
	}
	else if (A.size() < B.size()) {
		Sign = false;
		swap(A, B);
		swap(a, b);
	}
	while (a != -1 && b != -1) {
		sub = A[a] - '0' - (B[b] - '0') - down;
		if (sub < 0) {
			sub += 10;
			down = true;
		}
		else down = false;
		s = (char)(sub % 10 + '0') + s;
		a--, b--;
	}

	while (a != -1) {
		sub = A[a] - '0' - down;
		if (sub < 0) {
			sub += 10;
			down = true;
		}
		else down = false;
		s = (char)(sub % 10 + '0') + s;
		a--;
	}
	while (s[0] == '0')s.erase(s.begin(), s.begin() + 1); // 맨앞이 0일 경우 지워줌
	if (Sign == false)s = "-" + s;
	return s;
}
*/

/*
파이썬으로 하면 이리 쉬운걸... 흐흑
```
a, b = input().split()
a = int(a)
b = int(b)
print(a+b)
```
*/