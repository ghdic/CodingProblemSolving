/*
https://www.acmicpc.net/problem/2038

&Title
2038번 - 골롱 수열

&Question
Golomb 수열이란 모든 k에 대해 k가 수열상에서 f(k)번 
등장하는 단조증가 수열이다. 단조증가 수열이란 k값이 증가함에 따라 f(k)값이 
감소하지 않는 수열을 말한다. 여기서 k와 f(k)는 모두 자연수이다.골롱 
수열은 유일하게 결정될 수밖에 없다. 잘 생각해 보시길 ..n이 
주어졌을 때 f(n)을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 n(1≤n≤2,000,000,000)이 주어진다. 

&Output
첫째 줄에 f(n)을 출력한다. 

&Example
-input
100
-output
21

*/

/*
#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long long, long long> cache;

long long backtrack(long long cur) {
	if (cache[cur])return cache[cur];

	if (cache[cur - 1] == 0)
		cache[cur-1] = backtrack(cur - 1);
	if (cache[cache[cur - 1]] == 0)
		cache[cache[cur - 1]] = backtrack(cache[cur - 1]);
	if (cache[cur - cache[cache[cur - 1]]] == 0)
		cache[cur - cache[cache[cur - 1]]] = backtrack(cur - cache[cache[cur - 1]]);
	return cache[cur] = 1 + cache[cur - cache[cache[cur - 1]]];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	cache[1] = 1;
	cout << backtrack(n) << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long long, long long> um;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	um[1] = 1;
	long long sum = 1;
	for (int i = 2; i <= n; ++i) {
		um[i] = 1 + um[i - um[um[i - 1]]];
		sum += um[i];

		if (sum >= n) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
*/