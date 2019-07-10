/*
https://www.acmicpc.net/problem/10757

&Title
10757번 - 큰 수 A+B

&Question
A+B를 계산하시오. 

&Input
첫째 줄에 A와 B가 주어진다. (0 < A,B 
< 1010000) 

&Output
첫째 줄에 A+B를 출력한다. 

&Example
-input
9223372036854775807 9223372036854775808

-output
18446744073709551615


*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, result;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	int a = A.length() - 1, b = B.length() - 1;
	bool up = false;
	while (a != -1 && b != -1) {
		char val = A[a] + B[b] - '0' + up;
		if (val > '9') {
			up = true;
			result = (char)(val - 10) + result;
		}
		else {
			up = false;
			result = val + result;
		}
		--a, --b;
	}
	while (a != -1) {
		char val = A[a] + up;
		if (val > '9') {
			up = true;
			result = (char)(val - 10) + result;
		}
		else {
			up = false;
			result = val + result;
		}
		--a;
	}
	while (b != -1) {
		char val =  B[b] + up;
		if (val > '9') {
			up = true;
			result = (char)(val - 10) + result;
		}
		else {
			up = false;
			result = val + result;
		}
		--b;
	}
	if (up)result = '1' + result;
	cout << result << endl;

	return 0;
}
*/