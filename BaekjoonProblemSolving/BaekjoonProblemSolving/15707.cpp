/*
https://www.acmicpc.net/problem/15707

&Title
15707번 - exceed or not제출 언어 제한

&Question
두 정수 a와 b를 곱한 값이, r보다 큰지 
판단하는 프로그램을 작성하시오. 

&Input
첫째 줄에 정수 a, b, r이 공백으로 구분되어 
주어진다. (0 ≤ a, b ≤ 1020, 0 ≤ 
r < 263)각 정수 a, b, r이 '0'인 경우를 
제외하고, 0으로 시작하는 입력은 주어지지 않는다. 

&Output
a와 b를 곱한 값이 r보다 크면 overflow를, 그렇지 
않다면 a와 b를 곱한 값을 출력하라. 

&Example
-input
30130130130130130130 63 9000000000000000000

-output
overflow

-input
373 0 0

-output
0


*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b, r;

string multiply(string num1, string num2) {
	int len1 = num1.length(), len2 = num2.length();

	vector<int> res(len1 + len2, 0);

	int pos1 = 0, pos2 = 0;

	for (int i = len1 - 1; i >= 0; --i) {
		int carry = false;
		int n1 = num1[i] - '0';
		pos2 = 0;
		for (int j = len2 - 1; j >= 0; --j) {
			int n2 = num2[j] - '0';
			int sum = n1 * n2 + res[pos1 + pos2] + carry;
			carry = sum / 10;
			res[pos1 + pos2] = sum % 10;
			++pos2;
		}

		if (carry > 0)
			res[pos1 + pos2] += carry;

		++pos1;
	}

	int i = res.size() - 1;
	while (i >= 0 && res[i] == 0)
		--i;

	if (i == -1)
		return "0";

	string s = "";
	while (i >= 0)
		s += to_string(res[i--]);
	return s;
}

bool strComp(string num1, string num2) {
	int len1 = num1.length(), len2 = num2.length();
	if (len1 < len2)return true;
	else if (len1 > len2)return false;
	else {
		int idx = 0;
		while (idx < len1) {
			if (num1[idx] != num2[idx])
				return num1[idx] < num2[idx];
			else
				++idx;
		}
	}
	return false; // 동일한 경우
}
int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> r;
	string res = multiply(a, b);

	if (strComp(r, res)) {
		cout << "overflow" << endl;
	}
	else {
		cout << res << endl;
	}
	return 0;
}
*/


/*
// 숏코딩 보소.. int128로 해결되는 문제였네;;
__int128 a,b,r;main(){scanf("%lu%lu%lu",&a,&b,&r);printf(b&&a>r/b?"overflow":"%ld",a*b);}
*/