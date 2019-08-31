// http://codeforces.com/contest/1213/problem/B

// B. Bade Prices
// 하.. 영어 이전의 문제인거 같은데 먼소린지 모르겠네;;
// 이전보다 높은 가격이 형성되면 bad price래매.. 근데 예제테스트는 왜 그게 적용이 안되냐고
// 특히 2
// 2 1 이 경우는 왜 1이냐?,,
/*
각 날마다 ai의 가격으로 berPhone을 처분한다.
이때 i번째 날보다 이후에 더 낮은 가격에 팔렸다면 이 날을 bad day라 한다.
(난 이걸 전날로 해석했음.. latest가 최근이라는 의미도 있으니깐;; 착각했자나)

*/
/*
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

int main() {
	int t;
	cin >> t;
	forn(tt, t) {
		int n;
		cin >> n;
		vector<int> a(n);
		forn(i, n)
			cin >> a[i];
		int ans = 0;
		int right_min = INT_MAX;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] > right_min)
				++ans;
			right_min = min(right_min, a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
*/