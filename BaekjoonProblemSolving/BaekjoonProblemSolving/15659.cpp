/*
https://www.acmicpc.net/problem/15659

&Title
15659번 - 연산자 끼워넣기 (3)

&Question
N개의 수로 이루어진 수열 A1, A2, ..., AN이 
주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 
연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.우리는 
수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 
수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.예를 
들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 
5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 
1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 
있다. 예를 들어, 아래와 같은 식을 만들 수 있다.1+2+3-4×5÷61÷2+3+4-5×61+2÷3×4-5+61÷2×3-4+5+6식의 
계산은 연산자 우선 순위를 이용해 계산해야 한다. 연산자 우선 
순위는 ×와 ÷가 +와 -보다 앞선다. 우선 순위가 같은 
경우에는 앞에 있는 식을 먼저 계산한다. 또, 나눗셈은 정수 
나눗셈으로 몫만 취한다. 이에 따라서, 위의 식 4개의 결과를 
계산해보면 아래와 같다.1+2+3-4×5÷6 = 31÷2+3+4-5×6 = -231+2÷3×4-5+6 = 21÷2×3-4+5+6 
= 7N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 
있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 수의 개수 N(2 ≤ N ≤ 
11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. 
(1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1인 
4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 
개수, 나눗셈(÷)의 개수이다. 

&Output
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 
둘째 줄에는 최솟값을 출력한다. 최댓값과 최솟값이 항상 -10억보다 크거나 
같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 
식을 어떤 순서로 계산해도 중간에 계산되는 식의 결과도 항상 
-10억보다 크거나 같고, 10억보다 작거나 같다. 

&Example
-input
2
5 6
0 0 1 0

-output
30
30

-input
3
3 4 5
1 0 1 0

-output
23
17

-input
6
1 2 3 4 5 6
2 1 1 1

-output
35
-27


*/

/*
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

enum Operator{Plus=101, Minus, Multiply, Division};

struct calc {
	vector<int> exp;

	int isOp(int op) {
		switch (op) {
		case Plus:
		case Minus:
			return 1;
		case Multiply:
		case Division:
			return 2;
		default:
			return -1;
		}
	}

	void postfix(vector<int>& v) {
		stack<int> st;
		for (int i = 0; i < v.size(); ++i) {
			if (isOp(v[i]) == -1)
				exp.push_back(v[i]);
			else {
				while (!st.empty() && isOp(v[i]) <= isOp(st.top())) {
					exp.push_back(st.top());
					st.pop();
				}
				st.push(v[i]);
			}
		}
		while (!st.empty()) {
			exp.push_back(st.top());
			st.pop();
		}
	}

	int calculation() {
		stack<int> s;
		for (int i = 0; i < exp.size(); ++i) {
			if (isOp(exp[i]) == -1)
				s.push(exp[i]);
			else {
				int n2 = s.top(); s.pop();
				int n1 = s.top(); s.pop();
				switch (exp[i])
				{
				case Plus:
					s.push(n1 + n2);
					break;
				case Minus:
					s.push(n1 - n2);
					break;
				case Multiply:
					s.push(n1 * n2);
					break;
				case Division:
					s.push(n1 / n2);
					break;
				}
			}

		}
		return s.top();
	}
};

int n, arr[11], express[4], mx = -2e9, mn = 2e9;
vector<int> v;

void dfs(int depth) {
	if (depth == n) {
		calc c;
		c.postfix(v);
		int num = c.calculation();
		mx = max(mx, num);
		mn = min(mn, num);
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (express[i]) {
			--express[i];
			switch (i) {
			case 0:
				v.push_back(Plus);
				v.push_back(arr[depth]);
				break;
			case 1:
				v.push_back(Minus);
				v.push_back(arr[depth]);
				break;
			case 2:
				v.push_back(Multiply);
				v.push_back(arr[depth]);
				break;
			case 3:
				v.push_back(Division);
				v.push_back(arr[depth]);
			}
			dfs(depth + 1);
			v.pop_back();
			v.pop_back();
			++express[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	v.reserve(30);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> express[i];
	v.push_back(arr[0]);
	dfs(1);
	cout << mx << '\n' << mn << endl;
	return 0;
}
*/