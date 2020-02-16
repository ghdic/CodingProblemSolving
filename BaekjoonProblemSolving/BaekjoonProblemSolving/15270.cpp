/*
https://www.acmicpc.net/problem/15270

&Title
15270번 - 친구 팰린드롬

&Question
초등학생인 재홍이는 이번 봄 학예회 때, 재홍이가 지휘를 
맡고 반 친구들이 춤을 추기로 계획했다. 이 춤은 시작할 
때 춤추는 친구들이 일렬로 쭉 서서 각자 막춤을 추다가, 
가운데 있는 친구를 기준으로 왼쪽과 오른쪽에 있던 친구들이 두손을 
마주잡고 춤을 춘다. 즉 5명의 친구가 일렬로 서있었다면, 첫 
번째 친구와 다섯 번째 친구가 함께 춤을 추게 되며, 
두 번째 친구와 네 번째 친구가 함께 춤을 추게 
된다. 세 번째에 있던 친구는 같이 출 수 있는 
친구가 없기 때문에 혼자 로봇 댄스를 춘다.재홍이네 반 친구들은 
모두 자신과 친한 친구하고만 춤을 추고 싶어한다. 재홍이는 이번 
학예회에 스케일 크게 해보고 싶기 때문에 최대한 많은 친구를 
무대에 세우려고 한다. 친구 관계도가 주어졌을 때, 최대 몇 
명을 무대로 올려보낼 수 있는지 구해서 재홍이에게 알려주자. 친구들은 
출석번호로 나타내며, 1부터 시작해서 N까지 있다. 각 친구는 오로지 
하나의 출석번호를 갖는다.A와 B가 친한 친구고, B와 C가 친한 
친구라고해서 반드시 A와 C가 친한 친구는 아니다. 로봇 댄스를 
추는 친구를 제외한 무대에 올라가는 친구들은 모두 각자 자신과 
친한 친구하고만 춤을 춰야한다. 또한 재홍이 반 친구들은 모두 
로봇 댄스를 출 수 있다. 

&Input
첫째 줄에 총 반친구 수 N(2<=N<=20, 재홍이 제외)와 
관계도 수 M(0<=M<=(N^2-N)/2, 최대 50 제한)이 주어진다. 둘째 줄부터 
M+1줄까지 친한 친구 관계는 출석번호 u, v로 나타나며 u와 
v는 같지 않고, u와 v가 친한 친구라면 v와 u도 
친한 친구다.똑같은 입력은 두 번 이상 나오지 않는다. 가령 
1 2 가 이미 나왔다면 1 2 또는 2 
1는 입력으로 들어오지 않는다. 

&Output
무대에 최대한 세울 수 있는 친구의 수를 출력한다. 


&Example
-input
3 3
1 2
2 3
3 1

-output
3

-input
20 0

-output
1

-input
6 5
1 2
2 3
3 4
4 5
5 6

-output
6


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, res = 0;
vector<int> relation[21];
bool mate[21];

void dfs(int cur, int cnt) {
	if (cur == n + 1) {
		res = max(res, cnt + (cnt == n ? 0 : 1));
		return;
	}
	if (mate[cur]) {
		dfs(cur + 1, cnt);
		return;
	}
	dfs(cur + 1, cnt);
	for (int next : relation[cur]) {
		if (!mate[next]) {
			mate[cur] = mate[next] = true;
			dfs(cur + 1, cnt + 2);
			mate[cur] = mate[next] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		relation[u].push_back(v);
		relation[v].push_back(u);
	}
	dfs(1, 0);
	cout << res << endl;
	return 0;
}
*/