// 8.16 두니발 박사의 탈옥 (중)
//https://algospot.com/judge/problem/read/NUMB3RS


/*
#include <iostream>
#include <vector>
using namespace std;

int n, d, p, t, q; // 마을의수 0~50, 지금까지 지난 일수 1~100, 교도소가 있는 마을 번호 0~n-1, 확률을 계산할 마을 수 1~n
int map[51][51] = {};
int deg[51] = {}; // 마을 i와 연결된 마을 개수


double search(vector<int>& path){
	//기저 사례 : d일이 지난 경우
	if (path.size() == d + 1) {
		//이 시나리오가 q에서 끝나지 않는다면 무효
		if (path.back() != q)return 0.0;
		// path의 출현 확률을 계산한다.
		double ret = 1.0;
		for (int i = 0; i + 1 < path.size(); ++i)
			ret /= deg[path[i]];
		return ret;
	}
	double ret = 0.0;
	// 경로의 다음 위치를 결정한다.
	for (int there = 0; there < n; ++there) {
		if (map[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(8);
	int c;
	cin >> c;
	while (c--) {

		cin >> n >> d >> p;
		for (int i = 0; i < n; ++i) {
			int count = 0;
			for (int j = 0; j < n; ++j) {
				cin >> map[i][j];
				if (map[i][j])count++;
			}
			deg[i] = count;
		}
		cin >> t;
		for (int i = 0; i < t - 1; ++i) {
			vector<int> path;
			path.push_back(p);
			cin >> q;
			cout << search(path) << " ";
		}
		vector<int> path;
		path.push_back(p);
		cin >> q;
		cout << search(path) << "\n";
	}
}


*/

/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, p, q, t;
// cache[][] 는 -1 로 초기화
double cache[51][101];
// connected[i][j] == 마을 i j 연결여부
// deg[i] == 마을 i와 연결된 마을 개수
int connected[51][51], deg[51];
// days일째 here번 마을에 숨어 있다고 가정하고,
// 마지막 날에 q번 마을에 숨어 있을 조건부 확률을 반환한다.
double search2(int here, int days) {
	// 기저사례 : d일이 지난 경우
	if (days == d)return (here == q ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if (ret > -0.5)return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
		if (connected[here][there])
			ret += search2(there, days + 1) / deg[here];
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(8);
	int c;
	cin >> c;
	while (c--) {
		
		cin >> n >> d >> p;
		for (int i = 0; i < n; ++i) {
			int count = 0;
			for (int j = 0; j < n; ++j) {
				cin >> connected[i][j];
				if (connected[i][j])count++;
			}
			deg[i] = count;
		}
		
		cin >> t;
		for (int i = 0; i < t - 1; ++i) {
			for (int i = 0; i < 51; ++i)
				for (int j = 0; j < 101; ++j)
					cache[i][j] = -1.0;
			cin >> q;
			cout << search2(p, 0) << " ";
		}
		for (int i = 0; i < 51; ++i)
			for (int j = 0; j < 101; ++j)
				cache[i][j] = -1.0;
		cin >> q;
		cout << search2(p, 0) << "\n";
	}
}

*/

/*
// 2번째껄 거꾸로 계산하는 소스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, p, q, t;
// cache[][] 는 -1 로 초기화
double cache[51][101];
// connected[i][j] == 마을 i j 연결여부
// deg[i] == 마을 i와 연결된 마을 개수
int connected[51][51], deg[51];
// days일째 here번 마을에 숨어 있다고 가정하고,
// 마지막 날에 q번 마을에 숨어 있을 조건부 확률을 반환한다.
double search3(int here, int days) {
	// 기저 사례: 0일째
	if (days == 0) return (here == p ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if (ret > -0.5)return ret;
	ret = 0.0;
	for (int there = 0; there < n; ++there)
		if (connected[here][there])
			ret += search3(there, days - 1) / deg[there];
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(8);
	int c;
	cin >> c;
	while (c--) {

		cin >> n >> d >> p;
		for (int i = 0; i < n; ++i) {
			int count = 0;
			for (int j = 0; j < n; ++j) {
				cin >> connected[i][j];
				if (connected[i][j])count++;
			}
			deg[i] = count;
		}
		for (int i = 0; i < 51; ++i)
			for (int j = 0; j < 101; ++j)
				cache[i][j] = -1.0;
		cin >> t;
		for (int i = 0; i < t - 1; ++i) {
			
			cin >> q;
			cout << search3(q, d) << " ";
		}
		cin >> q;
		cout << search3(q, d) << "\n";
	}
}
*/