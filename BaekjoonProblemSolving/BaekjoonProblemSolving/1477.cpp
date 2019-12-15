/*
https://www.acmicpc.net/problem/1477

&Title
1477번 - 휴게소 세우기

&Question
다솜이는 유료 고속도로를 가지고 있다. 다솜이는 현재 고속도로에 
휴게소를 N개 가지고 있는데, 휴게소의 위치는 고속도로의 시작으로부터 얼만큼 
떨어져 있는지로 주어진다. 다솜이는 지금 휴게소를 M개 더 세우려고 
한다.다솜이는 이미 휴게소가 있는 곳에 휴게소를 또 세울 수 
없고, 고속도로의 끝에도 휴게소를 세울 수 없다.다솜이는 이 고속도로를 
이용할 때, 모든 휴게소를 방문한다. 다솜이는 휴게소를 M개 더 
지어서 휴게소가 없는 구간의 길이의 최댓값을 최소로 하려고 한다. 
(반드시 M개를 모두 지어야 한다.)예를 들어, 고속도로의 길이가 1000이고, 
현재 휴게소가 {200, 701, 800}에 있고, 휴게소를 1개 더 
세우려고 한다고 해보자.일단, 지금 이 고속도로를 타고 달릴 때, 
휴게소가 없는 구간의 최댓값은 200~701구간인 501이다. 하지만, 새로운 휴게소를 
451구간에 짓게 되면, 최대가 251이 되어서 최소가 된다. 

&Input
첫째 줄에 현재 휴게소의 개수 N, 더 지으려고 
하는 휴게소의 개수 M, 고속도로의 길이 L이 주어진다. N은 
100보다 작거나 같으며, M도 100보다 작거나 같다. L은 100보다 
크거나 같고, 1000보다 작거나 같다. 모든 휴게소의 위치는 중복되지 
않으며, N+M은 L보다 작다. 둘째 줄에, 휴게소의 위치가 공백을 
사이에 두고 주어진다. 

&Output
첫째 줄에 M개의 휴게소를 짓고 난 후에 휴게소가 
없는 구간의 최댓값의 최솟값을 출력한다. 

&Example
-input
6 7 800
622 411 201 555 755 82

-output
70


*/

/*
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct rest {
	double distance;
	int cnt; // 휴게소 사이 거리, 나뉜수

	bool operator < (const rest& a) const {
		return this->distance < a.distance;
	}
};
int n, m, l; // 휴게소개수, 더지을개수, 고속도로길이
int rest_area[102];
priority_queue<rest> pq;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> rest_area[i];
	}
	rest_area[0] = 0;
	rest_area[n + 1] = l;
	sort(rest_area, rest_area + n + 2);

	for (int i = 1; i < n + 2; ++i) {
		pq.push({ (double)(rest_area[i] - rest_area[i - 1]), 1 });
	}

	while (m--) {
		rest re = pq.top();
		pq.pop();
		double total = re.distance * re.cnt;
		int cnt = re.cnt + 1;
		pq.push({ total / cnt, cnt });
	}

	double item = pq.top().distance;
	int toint = (int)pq.top().distance;
	cout << toint + (toint == item ? 0 : 1) << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int rest[102];
int n, m, k;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i) {
		cin >> rest[i];
	}
	rest[n + 1] = k;
	sort(rest, rest + n + 1);

	int l = 1, r = k - 1;
	while (l <= r) {
		int cnt = 0;
		int mid = (l + r) / 2;
		
		for (int i = 1; i <= n + 1; ++i) {
			if (rest[i] - rest[i - 1] > mid) {
				cnt += (rest[i] - rest[i - 1] - 1) / mid;
			}
		}
		if (cnt > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l << endl;
	return 0;
}
*/