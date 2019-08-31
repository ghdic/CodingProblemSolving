// https://codeforces.com/contest/1213/problem/C

// C. Book Reading
/*
1~n까지 읽을 수 있는 책이 있는데
m으로 n이 나누어 떨어질때
일의자리수의 합?
*/

/*
#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		long long n, m, num = 0, result = 0, pos = 0;
		long long cache[10] = {};
		bool check[10] = {};
		cin >> n >> m;
		for (long long i = m; i <= n; i += m) {
			long long k = i % 10;
			if (check[k])break;
			cache[pos++] = k;
			check[k] = true;
		}
		if (pos != 0) {
			long long sum = 0;
			for (int i = 0; i < pos; ++i)sum += cache[i];
			long long recur = n / m, p;
			p = recur / pos;
			result = p * sum;
			p = 0, recur = recur % pos;
			while (recur--) {
				result += cache[p++];
			}
		}
		cout << result << '\n';
	}
	return 0;
}
*/