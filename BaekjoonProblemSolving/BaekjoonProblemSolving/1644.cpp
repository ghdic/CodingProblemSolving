/*
https://www.acmicpc.net/problem/1644

&Title
1644번 - 소수의 연속합

&Question
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 
자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 
같다.3 : 3 (한 가지)41 : 2+3+5+7+11+13 = 11+13+17 
= 41 (세 가지)53 : 5+7+11+13+17 = 53 (두 
가지)하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 
20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 
13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 
반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 
같은 표현도 적합하지 않다.자연수가 주어졌을 때, 이 자연수를 연속된 
소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 자연수 N이 주어진다. (1 ≤ N 
≤ 4,000,000) 

&Output
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 
수 있는 경우의 수를 출력한다. 

&Example
-input
20

-output
0
-input
3

-output
1

-input
41

-output
3

-input
53

-output
2


*/

/*
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 4000001;
int n;
bool check[MAXN];
vector<int> prime;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 2; i < MAXN; ++i) {
		if (!check[i]) {
			prime.push_back(i);
			for (long long j = (long long)i * i; j < MAXN; j += i) {
				check[j] = true;
			}
		}
	}
	int left = 0, right = 0, cnt = 0;
	int sum = 0;
	while (left < prime.size()) {
		if (right < prime.size() && sum < n) {
			sum += prime[right++];
		}
		else {
			if (n == sum)++cnt;
			sum -= prime[left++];
		}
	}
	cout << cnt << endl;
	return 0;
}
*/