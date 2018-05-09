/*
https://www.acmicpc.net/problem/1506

&Title
1506번 - 경찰서

&Question
종욱이가 살고있는 나라에는 도시가 N개 있고, 도시의 일부는 
일방 통행 도로로 연결되어 있다. 종욱이가 살고있는 나라의 대통령 
욱종이는 범죄와 싸우기 위해서 일부 도시에 경찰서를 세우려고 한다. 
도시 i에 경찰서를 세우는 비용은 cost[i] 이다.도시 i에 세운 
경찰서가 도시 j를 통제할 수 있으려면, i에서 j로 갔다가, 
다시 돌아오는 경로가 존재해야 한다.도로가 연결되어 있는 상태와 각 
도시에 경찰서를 지을 때 필요한 비용이 주어졌을 때, 모든 
도시를 통제하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 도시의 개수 N (1 ≤ N 
≤ 100)이 주어진다. 둘째 줄에 각 도시에 경찰서를 세우는데 
드는 비용이 주어진다. 셋째 줄부터 도로가 연결되어 있는 상태가 
한 줄에 한 줄에 하나씩 주어진다. i번째 줄의 j번째 
문자가 0인 경우에는 도시 i에서 도시 j로 갈 수 
없는 것이고, 1인 경우에는 갈 수 있는 것이다. 

&Output
첫째 줄에 모든 도시를 통제하는데 필요한 최소 비용을 
출력한다. 

&Example
-input
5
1 2 3 4 5
00011
10000
00010
00100
01000

-output
4


*/


#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[100][100] = {};
int N, a, result = 0, temp;
pair <int, int> cost[100];
bool finish;
bool bb[100] = {};
stack <int> st;
stack <int> visit;

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		cost[i] = make_pair(a, i);
	}
	sort(cost, cost + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	temp = 0;
	while (!finish) {
		//스택에 쌓아줌
		int start = cost[temp].second;
		bb[start] = true;	//시작 하는 값을 true로 만들고 한다.
		st.push(start);

		while (!st.empty()) {
			int item = st.top();
			visit.push(item);
			st.pop();
			for (int i = 0; i < N; i++) {
				if (arr[item][i] == 1) {
					//1.해당 값이 start 값 인지
					if (i == start) {

					}
					//2.해당 값이 이미 방문한 곳인지(사이클)
					//두번째 이상 시행시에도 이미 방문한곳은 다 true가 되있으므로
					st.push(i);
					bb[i] = true;
				}
				//3.더이상 갈 노드가 없는지
			}
		}
		//결과 비용을 넣고 다음 새로 세울 곳을 결정
		result += cost[temp].first;
		for (int i = temp; i < N; i++) {
			if (bb[i] == false) {
				temp = i;
				break;
			}
		}

		//모든 도시 감찰이 되는지 확인
		finish = true;
		for (int j = 0; j < N; j++) {
			if (bb[j] == false) {
				finish = false;
				break;
			}
		}
	}
	return 0;
}
