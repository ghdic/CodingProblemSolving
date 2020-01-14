/*
https://www.acmicpc.net/problem/9421

&Title
9421번 - 소수상근수

&Question
양의 정수 n의 각 자리수의 제곱의 합을 계산한다. 
그렇게 해서 나온 합도 각 자리수의 제곱의 합을 계산한다. 
이렇게 반복해서 1이 나온다면, n을 상근수라고 한다.700은 상근수이다.72 + 
02 + 02 = 4942 + 92 = 9792 
+ 72 = 13012 + 32 + 02 = 
1012 + 02 = 12는 상근수가 아니다.22 = 442 
= 1612 + 62 = 3732 + 72 = 
5852 + 82 = 8982 + 92 = 14512 
+ 42 + 52 = 4242 + 22 = 
2022 + 02 = 442 = 16... 끝나지 않는다소수는 
1과 자기자신을 제외하고 약수가 없는 수이다. 2, 3, 5, 
7, 11, 13, 17, 19, ... 는 소수이다.소수상근수는 소수이면서 
상근수인 숫자이다. 7, 13, 19, ... 는 소수 상근수이다.n이 
주어졌을 때, n보다 작거나 같은 모든 소수상근수를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 n (10 ≤ n ≤ 1000000)이 
주어진다. 

&Output
n보다 작거나 같은 소수상근수를 한 줄에 하나씩 오름차순으로 
출력한다. 

&Example
-input
20

-output
7
13
19


*/

/*
#include <iostream>
#include <unordered_set>
using namespace std;
const int MAXN = 1000000;

int n;
bool arr[MAXN + 1];
unordered_set<int> us;

bool check(int num) {
	unordered_set<int> st;
	while (true) {
		int next = 0;
		while (num) {
			int rest = num % 10;
			next += rest * rest;
			num /= 10;
		}
		if (us.find(next) != us.end()) {
			us.insert(st.begin(), st.end());
			return true;
		}
		if (st.find(next) != st.end())
			return false;
		st.insert(next);
		num = next;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (!arr[i]) {
			for (int j = i + i; j <= n; j += i)
				arr[j] = true;
		}
	}
	us.insert(1);
	for (int i = 2; i <= n; ++i) {
		if (!arr[i] && check(i))
			cout << i << '\n';
	}
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
const int MAXN = 1000000;

int n;
bool arr[MAXN + 1];
int dp[500];

int next_val(int num) {
	int next = 0;
	while (num) {
		int rest = num % 10;
		next += rest * rest;
		num /= 10;
	}
	return next;
}

bool check(int num) {
	if (dp[num] > 0)return true;
	if (dp[num] == -1)return false;
	dp[num] = -1;
	int next = next_val(num);
	if (check(next)) {
		dp[num] = next;
		return true;
	}
	else {
		dp[num] = 0;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		if (!arr[i]) {
			for (int j = i + i; j <= n; j += i)
				arr[j] = true;
		}
	}
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (!arr[i] && check(next_val(i))) {
			cout << i << '\n';
		}
	}
	return 0;
}
*/