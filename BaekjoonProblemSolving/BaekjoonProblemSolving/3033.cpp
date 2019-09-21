/*
https://www.acmicpc.net/problem/3033

&Title
3033번 - 가장 긴 문자열

&Question
상근이는 꿈에서 길이가 L인 문자열을 외웠다. 꿈에서 깬 
상근이는 이 문자열을 종이에 적었다. 종이를 적던 중에 어떤 
문자열은 두 번 이상 등장하는 것 같은 느낌을 받았다. 
문자열이 주어졌을 때, 두 번 이상 등장한 부분 문자열 
중 가장 길이가 긴 것을 찾는 프로그램을 작성하시오. (부분문자열은 
겹쳐서 등장할 수도 있다) 

&Input
첫째 줄에 L이 주어진다. (1 ≤ L ≤ 
200,000) 다음 줄에는 길이가 L이면서 알파벳 소문자로 이루어진 문자열이 
주어진다. 

&Output
첫째 줄에 두 번 이상 등장하는 부분 문자열 
중 길이가 가장 긴 것의 길이를 출력한다. 만약 그러한 
문자열이 없을 때는 0을 출력한다. 

&Example
-input
11
sabcabcfabc

-output
3


*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MOD = 100003;

vector<vector<int>> pos; // pos[i] 해시값이 i인 부분 문자열의 등장 위치들

inline int mod(long long n) {
	if (n >= 0)return n % MOD;
	// 음수 인경우 오버플로우가 발생한것으로 아래식은 사실상 MOD + n값을 리턴한다
	return ((-n / MOD + 1) * MOD + n) % MOD;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l;
	string w;
	cin >> l >> w;
	int lo = 0, hi = l; // lo가능, hi불가능
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int h = 0, power = 1;
		pos.clear();
		pos.resize(MOD);
		bool found = false;

		// 가능한 모든 위치에서 길이 mid 부분 문자열들의 해시값을 구해 보며 처리
		for (int i = 0; i <= l - mid; ++i) {
			if (i == 0) {
				for (int j = 0; j < mid; ++j) {
					h = mod(h + 1LL * w[mid - 1 - j] * power);
					if (j < mid - 1)power = mod(power * 2);
				}
			}
			else h = mod(2 * (h - 1LL * w[i - 1] * power) + w[i + mid - 1]);

			// 해시값 충돌이 일어남
			if (!pos[h].empty()) {
				// 같은 문자열이 앞서 등장했는지 모두 비교
				for (int p : pos[h]) {
					bool same = true;
					for (int j = 0; j < mid; ++j) {
						if (w[i + j] != w[p + j]) {
							same = false;
							break;
						}
					}
					// 동일한 부분 문자열 등장
					if (same) {
						found = true;
						break;
					}
				}
			}
			if (found)break; // 찾음
			else pos[h].push_back(i); // 찾지 못함: 루프 계속
		}
		// 길이 mid인 부분 문자열이 2번 등장했느냐에 따라 상하값 조절
		(found ? lo : hi) = mid;
	}
	cout << lo << endl;
	return 0;
}
*/