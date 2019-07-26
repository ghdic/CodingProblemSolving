/*
https://www.acmicpc.net/problem/8984

&Title
8984번 - 막대기

&Question
다양한 길이의 막대기를 가지고 즐길 수 있는 게임이 
있다. 게임을 시작하기 전에 간격이 L인 두 개의 평행한 
수평선을 책상 위에 긋고, 막대기의 양 끝이 각 수평선에 
하나씩 위치하도록 놓는다. 여러 개의 막대기 끝이 수평선 위의 
한 점에서 만날 수는 있지만, 두 막대기가 완전히 겹쳐져 
있는 경우는 없다. 놓여 있는 각 막대기는 (t, d)로 
표현된다. 여기서 t는 위쪽 수평선에서의 좌표이고 d는 아래쪽 수평선에서의 
좌표이다. 아래 그림 1에서 막대기 a는 (1, 0), 막대기 
b는 (6, 0)으로 표시된다.게임은 책상에 놓여 있는 막대기들 중 
일부를 들어내어 남아 있는 막대기들이 다음의 세 조건을 모두 
만족하는 하나의 지그재그 선이 구성되도록 하는 것이다: (1) 막대기들은 
끝점을 제외하곤 서로 교차하지 않는다. (2) 세 개 이상의 
막대기 끝이 한 점에서 만나지 않는다. (3) 모든 막대기는 
연결되어 있다. 이 게임의 승자는 길이가 가장 긴 지그재그 
선을 만든 사람이다. 지그재그 선의 길이는 막대기 길이들의 합이며, 
각 막대기의 길이는 양 끝점의 수평 거리와 수직 거리를 
더한 값으로 계산한다. 즉, 막대기 (t, d)의 수평 거리는 
t와 d 사이의 절댓값 |t-d|이고, 수직 거리는 두 수평선 
사이의 간격인 L이다. 위 그림에서 각 막대기의 길이는 다음과 
같다.막대기abcdefg길이4964473예를 들면, 그림 1에서 막대기 a, b, e 만 
남겨진 경우는 세 조건을 모두 만족하는 지그재그 선이 며, 
길이는 17 = 4+9+4 이다. 막대기 c, e 만 
남겨진 경우도 세 조건을 모두 만족하는 지그재그 선이며, 길이는 
10 = 6+4 이다. 막대기 b, c 만 남겨진 
경우는 조건 (1)에 위배되고, 막대기 c, d, e 만 
남겨진 경우는 조건 (2)에 위배되고, 막대기 a, b, g 
만 남겨진 경우는 조건 (3)에 위배된다. 길이가 가장 긴 
지그재그 선은 막대기 c, d, f, g로 구성되며, 길이는 
20 = 6+4+7+3 이다. 막대기들의 초기 상태가 주어져 있을 
때, 가장 긴 지그재그 선의 길이를 구하기 위한 프로그램을 
작성하시오. 

&Input
첫 줄에는 막대기의 개수와 수평선 사이의 간격을 나타내는 
두 개의 정수 N과 L이 주어진다. 여기서 N은 1 
이상 100,000 이하이고, L은 1 이상 1,000,000 이하이다. 그 
다음 N 개의 줄에는 각 줄마다 막대기 (t, d)를 
나타내는 두 개의 정수 t와 d가 빈칸을 사이에 두고 
주어진다. 여기서 t와 d는 각각 0 이상 100,000,000 이하이다. 
입력으로 들어오는 막대기들 중 어떤 두 막대기도 완전히 겹쳐져 
있는 경우는 없다. 

&Output
주어진 입력에 대해 길이가 가장 긴 지그재그 선의 
길이를 한 줄에 출력한다. 

&Example
-input
7 3
1 0
6 0
2 5
4 5
6 5
4 8
8 8

-output
20


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int n, l;
long long dp[100001][2];
pair<int, int> stick[100001];
vector<int> tv, dv;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l;
	for (int i = 0; i < n; ++i) {
		cin >> stick[i].first >> stick[i].second;
		tv.push_back(stick[i].first);
		dv.push_back(stick[i].second);
	}
	sort(stick, stick + n);
	sort(tv.begin(), tv.end());
	sort(dv.begin(), dv.end());

	tv.erase(unique(tv.begin(), tv.end()), tv.end());
	dv.erase(unique(dv.begin(), dv.end()), dv.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int t_idx = lower_bound(tv.begin(), tv.end(), stick[i].first) - tv.begin();
		// 해당 원소 위치를 이분탐색으로 찾음, 못찾을 경우 키 보다 한단계 큰 원소 위치를 반환
		int d_idx = lower_bound(dv.begin(), dv.end(), stick[i].second) - dv.begin();
		int len = l + (abs(stick[i].first - stick[i].second));
		long long t = dp[t_idx][0], d = dp[d_idx][1];
		dp[t_idx][0] = max(t, d + len); // 현재 점에서 해당 선으로 옮겼을때 최선인가?
		dp[d_idx][1] = max(d, t + len);
		ans = max(dp[t_idx][0], max(ans, dp[d_idx][1]));
	}
	cout << ans << endl;
	return 0;
}
*/