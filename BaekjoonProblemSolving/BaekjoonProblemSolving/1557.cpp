/*
https://www.acmicpc.net/problem/1557

&Title
1557번 - 제곱 ㄴㄴ

&Question
어떤수 N이 1이 아닌 제곱수로 나누어지지 않을 때, 
이 수를 제곱ㄴㄴ수라고 한다. 제곱수는 4, 9, 16, 25와 
같은 것이고, 제곱ㄴㄴ수는 1, 2, 3, 5, 6, 7, 
10, 11, 13, ...과 같은 수이다.K가 주어졌을 때, K번째 
제곱ㄴㄴ수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 K가 주어진다. 

&Output
첫째 줄에 K번째 제곱ㄴㄴ수를 출력한다. 

&Example
-input
13

-output
19


*/

// 1e9 범위라 배열할당시 메모리 초과가 되버림..
// square free number이라고 치면 힌트를 얻을 수 있다.
// https://www.geeksforgeeks.org/nth-square-free-number/
// https://www.youtube.com/watch?v=fApdB8g7jE4

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 1e5;
const int MAX = 2e9;

int k;
bool arr[MAXN];
vector<int> prime;

long long get_nth(long long i, long long cur, long long k) {
	long long square = (long long)prime[i] * prime[i];
	long long newCur = square * cur;

	if (newCur > k)
		return 0;
	long long cnt = k / newCur;
	cnt += get_nth(i + 1, cur, k);
	cnt -= get_nth(i + 1, newCur, k);
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	prime.reserve(MAXN);
	cin >> k;
	fill(&arr[0], &arr[MAXN], true);
	for (int i = 2; i * i < MAXN; ++i) {
		if (arr[i]) {
			for (int j = i * i; j < MAXN; j += i)
				arr[j] = false;
		}
	}
	for (int i = 2; i < MAXN; ++i)
		if (arr[i])
			prime.push_back(i);
	long long left = 1, right = MAX;
	while (left < right) {
		long long mid = (left + right) / 2;
		long long res = mid - get_nth(0, 1, mid);
		if (res < k)
			left = mid + 1;
		else
			right = mid;
	}

	cout << left << endl;
	return 0;
}
*/