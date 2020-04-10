// https://www.algospot.com/judge/problem/read/NERD2

/*
#include <iostream>
#include <map>
using namespace std;

// 현재 다른 점에 지배당하지 않는 점들의 목록을 저장한다
map<int, int> coords;
// 새로운 점 (x, y)가 기존의 다른 점들에 지배당하는지 확인한다
bool isDominated(int x, int y) {
	// x보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾는다.
	map<int, int>::iterator it = coords.lower_bound(x);
	// 그런 점이 없으면 (x, y)는 지배당하지 않는다.
	if (it == coords.end())return false;
	// 이 점은 x보다 오른쪽에 있는 점 중 가장 위에 있는 점이므로,
	// (x, y)가 어느 점에 지배되려면 이 점에도 지배되어야 한다.
	return y < it->second;
}

// 새로운 점 (x,y)에 지배당하는 점들을 트리에서 지운다
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	// (x, y)보다 왼쪽에 있는 점이 없다!
	if (it == coords.begin())return;
	--it;
	// 반복문 불변식: it는 (x,y)의 바로 왼쪽에 있는 점
	while (true) {
		// (x, y)바로 왼쪽에 오는 점을 찾는다
		// it가 표시하는 점이 (x, y)에 지배되지 않는다면 곧장 종료
		if (it->second > y)break;
		// 이전 점이 더 없으므로 it만 지우고 종료
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		// 이전 점으로 이터레이터를 하나 옮겨 놓고 it를 지운다
		else {
			map<int, int>::iterator jt = it;
			--it;
			coords.erase(jt);
		}
	}
}

// 새 점(x, y)가 추가 되었을 때 coords를 갱신하고
// 다른 점에 지배당하지 않는 점들의 개수를 반환한다
int registered(int x, int y) {
	// (x, y)가 이미 지배당하는 경우에는 그냥 (x, y)를 버린다
	if (isDominated(x, y))return coords.size();
	// 기존에 있던 점 중 (x, y)에 지배당하는 점들을 지운다
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, p, q;
	cin >> t;
	while (t--) {
		int res = 0;
		coords.clear();
		cin >> n;
		while (n--) {
			cin >> p >> q;
			res += registered(p, q);
		}
		cout << res << "\n";
	}
	return 0;
}
*/