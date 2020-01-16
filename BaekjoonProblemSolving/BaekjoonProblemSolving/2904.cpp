/*
https://www.acmicpc.net/problem/2904

&Title
2904번 - 수학은 너무 쉬워

&Question
상근이의 할머니는 매우 유명한 수학자이다. 할머니는 매일 수학 
문제로 상근이를 힘들게 한다. 할머니는 종이 N장에 숫자를 하나씩 
쓴 다음 상근이에게 준다. 그 다음 상근이는 다음과 같이 
문제를 풀어야 한다. 두 수 A와 B를 고르고, A를 
나눌 수 있는 소수 X를 고른다. 그 다음, A를 
지우고 A/X를 쓰고, B를 지우고 B×X를 쓴다. 상근이는 위의 
행동을 무한히 반복할 수 있다. 할머니는 상근이가 만든 수를 
보고 점수를 계산한다. 점수가 높을수록 할머니는 상근이에게 사탕을 많이 
준다. 점수는 종이에 적혀있는 모든 수의 최대공약수이다. 상근이가 얻을 
수 있는 가장 높은 점수를 구하는 프로그램을 작성하시오. 또, 
그 점수를 얻으려면 최소 몇 번 해야 하는지도 구한다. 


&Input
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 
100) 둘째 줄에는 종이에 적혀있는 수 N개가 주어진다. 수는 
모두 1,000,000보다 작거나 같은 양의 정수이다. 

&Output
첫째 줄에 상근이가 얻을 수 있는 가장 큰 
점수와 최소 몇 번 만에 그 점수를 얻을 수 
있는지를 출력한다. 

&Example
-input
3
8 24 9

-output
12 3


*/

/*
#include <iostream>
#include <vector>
using namespace std;

int n;
bool composition[1000001];
vector<int> prime;

int main() {
	ios::sync_with_stdio(false);
	prime.reserve(100000);
	for (int i = 2; i <= 1000000; ++i) {
		if (!composition[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= 1000000; j += i) {
				composition[j] = true;
			}
		}
	}
	cin >> n;
	vector<vector<int>> factorization(n, vector<int>(prime.size())); // 각 인수분해 결과들 담을 2차원배열
	vector<int> sum(prime.size()); // 인수 분해 결과의 각 소수 개수의 합
	int a;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = 0; j < prime.size(); ++j) {
			while (a % prime[j] == 0) {
				a /= prime[j];
				++sum[j];
				++factorization[i][j];
			}
			if (a < prime[j]) // 소수가 a보다 더 큰 경우 더 이상 나눌 수 있는 소인수가 없다.(즉 1이라는거긴함..)
				break;
		}
	}

	int res = 1, cnt = 0;
	for (int i = 0; i < prime.size(); ++i) {
		if (sum[i] == 0)continue;
		int div = sum[i] / n;
		for (int j = 0; j < div; ++j)
			res *= prime[i];
		for (int j = 0; j < n; ++j) {
			if (div > factorization[j][i]) // 연산이 한방향으로 이뤄지므로 큰쪽이나 작은쪽 둘중 하나 차 구해주면 됨
				cnt += div - factorization[j][i];
		}
	}

	cout << res << ' ' << cnt << endl;
	return 0;
}
*/