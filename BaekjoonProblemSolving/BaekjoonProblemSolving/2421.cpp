// https://www.acmicpc.net/problem/2421

/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1e6;

int n;
int cache[1000][1000], isPrime[MAX];

void eratos() {
	for (int i = 2; i < MAX; i++)
		isPrime[i] = i;

	int range = (int)sqrt(MAX);
	for (int i = 2; i <= range; i++) {
		if (isPrime[i] == i) {
			for (int j = i + i; j < MAX; j += i)
				isPrime[j] = 0;
		}
	}
}

int getDigitNum(int num) {
	int cnt = 0;
	while (num) {
		num /= 10;
		cnt++;
	}
	return cnt;
}

int maxPrimeNum(int leftCoin, int rightCoin) {
    if (leftCoin > n || rightCoin > n)
        return 0;

    int rightCoinDigit = getDigitNum(rightCoin);
    int leftCoinDigit = rightCoinDigit;
    int copyLeft = leftCoin;
    for (int i = 0; i < leftCoinDigit; i++)
        copyLeft *= 10;

    if (leftCoin == n && rightCoin == n) {
        if (isPrime[copyLeft + rightCoin] == copyLeft + rightCoin)
            return 1;
        else
            return 0;

    }

    int& result = cache[leftCoin][rightCoin];

    if (result != -1)
        return result;

    result = 0;

    if (copyLeft + rightCoin != 11 && isPrime[copyLeft + rightCoin] == copyLeft + rightCoin)
        result++;
    result += max(maxPrimeNum(leftCoin + 1, rightCoin), maxPrimeNum(leftCoin, rightCoin + 1));

    return result;

}


int main() {
	FASTIO;
	cin >> n;
    eratos();
    memset(cache, -1, sizeof(cache));
    cout << maxPrimeNum(1, 1) << endl;
    return 0;
}
*/