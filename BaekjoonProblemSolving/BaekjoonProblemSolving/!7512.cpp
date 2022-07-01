// https://www.acmicpc.net/problem/8913
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = (int)1e7;

bool isPrime[MAX];
vector<int> primes;

bool isCorrect(vector<int> sumArray, int val) {
	for (auto x : sumArray)
		if (x != val)
			return false;
	return true;
}

int main() {
	FASTIO;
	for (int i = 2; i < MAX; i++) {
		if (!isPrime[i]) {
			isPrime[i] = true;
			primes.push_back(i);
			for (int j = i + i; j < MAX; j += i) {
				isPrime[j] = true;
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int m;
		cin >> m;
		vector<int> narray(m, 0);
		vector<int> sumarray(m, 0);
		vector<int> sumBeginIndex(m, 0);

		for (int j = 0; j < m; j++)
			cin >> narray[j];

		for (int j = 0; j < m; j++) {
			sumarray[j] = accumulate(&primes[0], &primes[narray[j]], 0);
			while (!isPrime[sumarray[j]]) {
				sumarray[j] += primes[sumBeginIndex[j] + narray[j]] - primes[sumBeginIndex[j]];
				sumBeginIndex[j]++;
			}
		}

		int answer = *max_element(sumarray.begin(), sumarray.end());

		while (!isCorrect(sumarray, answer)) {
			for (int j = 0; j < m; j++) {
				if (sumarray[j] < answer) {
					do {
						sumarray[j] += primes[sumBeginIndex[j] + narray[j]] - primes[sumBeginIndex[j]];
						sumBeginIndex[j]++;
					} while (!isPrime[sumarray[j]]);
				}
				else {
					answer = sumarray[j];
				}
			}
		}
		cout << "Scenario " << i << ":\n";
		cout << answer << "\n\n";

	}
}
*/