/*
https://www.acmicpc.net/problem/2661

&Title
2661번 - 좋은수열

&Question
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 
길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 
그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 
수열이다.다음은 나쁜 수열의 예이다.3332121323123123213다음은 좋은 수열의 예이다.232321231232123길이가 N인 좋은 
수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 
수열을 구하는 프로그램을 작성하라. 예를 들면, 1213121과 2123212는 모두 
좋은 수열이지만 그 중에서 작은 수를 나타내는 수열은 1213121이다. 


&Input
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 
이하이다. 

&Output
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 
길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 
수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 
두지 않는다. 

&Example
-input
7

-output
1213121


*/

/*
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;

void backtracking(char c, int depth) {
	if (depth - 1 == n) {
		cout << s << endl;
		exit(0);
	}
	s += c;
	for (int i = 1; i <= depth / 2; ++i) {
		string a = s.substr(depth - i, i);
		string b = s.substr(depth - i * 2, i);

		if (a == b) {
			s.erase(depth - 1);
			return;
		}
	}

	for (int i = '1'; i <= '3'; ++i) {
		if (c == i)continue;
		backtracking(i, depth + 1);
	}
	s.erase(depth - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	backtracking('1', 1);
	return 0;
}
*/