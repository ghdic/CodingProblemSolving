/*
https://www.acmicpc.net/problem/2170

&Title
2170번 - 선 긋기

&Question
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 
선을 그을 때에는 자의 한 점에서 다른 한 점까지 
긋게 된다. 선을 그을 때에는 이미 선이 있는 위치에 
겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 
번 그은 곳의 차이를 구별할 수 없다고 하자.이와 같은 
식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 
프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 
계산한다. 

&Input
첫째 줄에 선을 그은 횟수 N(1≤N≤1,000,000)이 주어진다. 다음 
N개의 줄에는 선을 그을 때 선택한 두 점이 주어진다. 
선택한 지점은 -1,000,000,000 이상 1,000,000,000 이하의 정수이다. 

&Output
첫째 줄에 그은 선의 총 길이를 출력한다. 

&Example
-input
4
1 3
2 5
3 5
6 7

-output
5

*/

/*
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}
	// 선분을 왼쪽 끝 좌표 순으로 정렬
	sort(p, p + n);

	// [l, r] : 현재 합치고 있는 구간
	int result = 0, l = -1000000001, r = -1000000001;
	for (int i = 0; i < n; ++i) {
		// 현재 구간과 이번 선분이 합쳐질 수 없음(겹치는 구간이 없음)
		if (r < p[i].first) {
			// 결과에 더함
			result += r - l;
			// 현재 구간을 이번 선분으로 초기화
			l = p[i].first;
			r = p[i].second;
		}
		// 겹침 : 현재 구간의 r을 늘릴 수 있으면 늘림
		else {
			r = max(r, p[i].second);
		}
	}
	result += r - l; // 마지막 구간까지 더해줌
	cout << result << endl;
	return 0;
}
*/