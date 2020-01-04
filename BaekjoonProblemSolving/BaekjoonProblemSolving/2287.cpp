/*
https://www.acmicpc.net/problem/2287

&Title
2287번 - 모노디지털

&Question
몇 개의 숫자 K(K는 1, 2, …, 9중 
하나)와 사칙 연산(덧셈, 뺄셈, 곱셈, 나눗셈)만을 사용하여 어떤 자연수 
X를 수식으로 표현한 것을 X의 K-표현이라 부른다. 수식에는 괄호가 
포함될 수 있으며, 나눗셈은 나눈 몫만을 취한다.예를 들어 12의 
5-표현을 몇 개 써 보면 5+5+(5/5)+(5/5), 55/5+5/5, (55+5)/5 등이 
있다. K-표현의 길이를 사용한 K의 개수라 하면, 각각의 길이는 
6, 5, 4가 된다.K가 주어졌을 때, 어떤 자연수의 K-표현 
중 가장 짧은 길이를 알아보려 한다. 

&Input
첫째 줄에 K가 주어진다. 다음 줄에는 표현 식을 
찾을 수의 개수 n(1≤n≤1,000)이 주어진다. 다음 줄에는 K-표현 중 
가장 짧은 길이를 알아보려 하는 자연수 a(1≤a≤32,000)가 주어진다. 

&Output
입력되는 순서대로 K-표현의 최소 길이를 n개의 줄에 출력한다. 
만약 K-표현의 최소 길이가 8보다 크다면 “NO"를 출력한다. 

&Example
-input
5
2
12
31168

-output
4
NO


*/

/*
5 + 5
5 - 5
5 / 5
5 * 5
55
*/

/*
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

int k, t, a;
unordered_set<int> us[9];

int main() {
	cin >> k;

	// K-표현 중 연속하게 K를 붙이는 경우를 먼저 넣어줌
	int num = 0;
	for (int i = 1; i <= 8; ++i) {
		num = 10 * num + k;
		us[i].insert(num);
	}
	int kind;
	for (int i = 1; i <= 8; ++i) {
		for (int j = 1; j <= i; ++j) {
			kind = i + j;
			if (kind > 8)continue;
			for (int y : us[i]) {
				for (int x : us[j]) {
					us[kind].insert(y + x);
					if(y != x)
						us[kind].insert(abs(y - x));
					us[kind].insert(y * x);
					if (y > x)
						us[kind].insert(y / x);
					else
						us[kind].insert(x / y);
				}
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> a;

		// 구한것 중 일치하는 K-표현 최소길이 구하기
		int res = -1;
		for (int i = 1; i <= 8; ++i) {
			if (us[i].count(a)) {
				res = i;
				break;
			}
		}
		if (res == -1) {
			cout << "NO\n";
		}
		else {
			cout << res << '\n';
		}
	}
}
*/