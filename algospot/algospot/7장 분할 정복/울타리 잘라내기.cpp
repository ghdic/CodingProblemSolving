//https://algospot.com/judge/problem/read/FENCE

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//각 판자의 높이를 저장하는 배열
vector<int> h;
//h[left... right] 구간에서 찾아 낼 수 있는 가장 큰 사각형의 넓이를 반환한다.
int solve(int left, int right) {
	//기저 사례: 판자가 하나밖에 없는 경우
	if (left == right) return h[left];
	//[left, mid], [mid+1, right]의 두 구간으로 문제를 분할한다.
	int mid = (left + right) / 2;
	//분할한 문제를 각개 격파
	int ret = max(solve(left, mid), solve(mid + 1, right));
	//부분 문제 3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	//[mid, mid + 1] 만 포함하는 너비 2인 사각형을 고려한다.
	ret = max(ret, height * 2);
	//사각형이 입력 전체를 덮을 때까지 확장해 나간다.
	while (left < lo || hi < right) {
		//항상 높이가 더 높은 쪽으로 확장한다.
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		//확장한 후 사각형의 넓이
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	int test_case, num;
	cin >> test_case;
	if (test_case < 0 || test_case > 50)
		exit(-1);
	for (int i = 0; i < test_case; ++i) {
		cin >> num;
		h.resize(num);
		for (int j = 0; j < num; ++j) {
			cin >> h[j];
			if (h[j] < 0 || h[j]>20000)
				exit(-1);
		}
		cout << solve(0, h.size()-1) << endl;
	}
}
*/