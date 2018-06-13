/*
https://www.acmicpc.net/problem/5613

&Title
5613번 - 계산기 프로그램

&Question
덧셈, 뺄셈, 곱셈, 나눗셈을 할 수 있는 계산기 
프로그램을 만드세요. 

&Input
입력의 각 줄에는 숫자와 +, -, *, /, 
=중 하나가 교대로 주어진다. 첫 번째 줄은 수이다. 연산자의 
우선 순위는 생각하지 않으며, 입력 순서대로 계산을 하고, =가 
주어지면, 그때까지의 결과를 출력한다. 주어지는 수는 108 이하의 양의 
정수이다. 계산 중 결과는 0 또는 음수가 될 수 
있지만, -108 ~ 108 범위를 넘지는 않는다. 또, 나눗셈에서 
소수점은 버린다. 따라서, 100/3*3 = 99이다. 

&Output
첫째 줄에 계산 결과를 출력한다. 

&Example
-input
1
+
1
=

-output
2


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
typedef long long ll;

ll cal(char a, ll t1, ll result)
{
	if (a == '+') return result = result + t1;
	if (a == '-') return result = result - t1;
	if (a == '*') return result = result * t1;
	if (a == '/') return result = result / t1;
	if (a == '=') return result;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll result, t1;
	char a;
	cin >> result;
	cin >> a;
	while (a != '=')
	{
		cin >> t1;
		result = cal(a, t1, result);
		cin >> a;
	}
	cout << result;
}
*/