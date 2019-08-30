/*
https://www.acmicpc.net/problem/15684

&Title
15684번 - 사다리 조작

&Question
사다리 게임은 N개의 세로선과 M개의 가로선으로 이루어져 있다. 
인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 
가로선을 놓을 수 있는 위치의 개수는 H이고, 모든 세로선이 
같은 위치를 갖는다. 아래 그림은 N = 5, H 
= 6 인 경우의 그림이고, 가로선은 없다.초록선은 세로선을 나타내고, 
초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다. 
가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 
연속하거나 서로 접하면 안 된다. 또, 가로선은 점선 위에 
있어야 한다.위의 그림에는 가로선이 총 5개 있다. 가로선은 위의 
그림과 같이 인접한 두 세로선을 연결해야 하고, 가로선을 놓을 
수 있는 위치를 연결해야 한다.사다리 게임은 각각의 세로선마다 게임을 
진행하고, 세로선의 가장 위에서부터 아래 방향으로 내려가야 한다. 이때, 
가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 
세로선에서 아래 방향으로 이동해야 한다.위의 그림에서 1번은 3번으로, 2번은 
2번으로, 3번은 5번으로, 4번은 1번으로, 5번은 4번으로 도착하게 된다. 
아래 두 그림은 1번과 2번이 어떻게 이동했는지 나타내는 그림이다.1번 
세로선2번 세로선사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 
이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 
위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 
세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. 
(2 ≤ N ≤ 10, 1 ≤ H ≤ 
30, 0 ≤ M ≤ (N-1)×H)둘째 줄부터 M개의 줄에는 
가로선의 정보가 한 줄에 하나씩 주어진다.가로선의 정보는 두 정수 
a과 b로 나타낸다. (1 ≤ a ≤ H, 1 
≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 
점선 위치에서 연결했다는 의미이다.가장 위에 있는 점선의 번호는 1번이고, 
아래로 내려갈 때마다 1이 증가한다. 세로선은 가장 왼쪽에 있는 
것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.입력으로 주어지는 
가로선이 서로 연속하는 경우는 없다. 

&Output
i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 
추가해야 하는 가로선 개수의 최솟값을 출력한다. 만약, 정답이 3보다 
큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다. 


&Example
-input
2 0 3

-output
0

-input
2 1 3
1 1

-output
1

-input
5 5 6
1 1
3 2
2 3
5 1
5 4

-output
3

-input
6 5 6
1 1
3 2
1 3
2 5
5 5

-output
3

-input
5 8 6
1 1
2 2
3 3
4 4
3 1
4 2
5 3
6 4

-output
-1

-input
5 12 6
1 1
1 3
2 2
2 4
3 1
3 3
4 2
4 4
5 1
5 3
6 2
6 4

-output
-1

-input
5 6 6
1 1
3 1
5 2
4 3
2 3
1 4

-output
2


*/

/*
// dfs로 안하고 bfs로 하고 싶었는데
// 사다리 하나 선택해보고 만족하는게 없으면
// 깊이 하나 더 들어가는식으로
#include <iostream>
using namespace std;
bool check[31][11];
int n, m, h, Ladder;
bool res;

bool countLadder() {
	for (int i = 1; i <= n; ++i) {
		int pt = i;
		for (int j = 1; j <= h; ++j)
			if (check[j][pt])pt += 1; //오른쪽 이동
			else if (pt - 1 > 0 && check[j][pt - 1])pt -= 1; // 왼쪽 이동
		if (i == pt)continue;
		else return false;
	}
	res = true;
	return true;
}

void dfs(int x, int cnt) {
	if(res) return;
	if (cnt == Ladder) {
		if (countLadder())m = cnt;
		return;
	}
	for(int i = x; i <= h; ++i)
		for (int j = 1; j < n; ++j) {
			if (!check[i][j - 1] && !check[i][j] && !check[i][j + 1]) {
				check[i][j] = true;
				dfs(i, cnt + 1);
				check[i][j] = false;
			}
		}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> h;
	int a, b;
	while (m--) {
		cin >> a >> b;
		check[a][b] = true;
	}
	for (int i = 0; i < 4; ++i) {
		Ladder = i;
		dfs(1, 0);
		if (res)break;
	}
	if (!res)cout << -1 << '\n';
	else cout << m << '\n';
	return 0;
}
*/

/*
#include <stdio.h>
int N,M,H,a,b,arr[31][10],ans=4;
void cf(int val){
	int i,x,y;
	if(ans<val) return;
	for(i=1;i<N;i++){
		x=i; y=1;
		while(y<=H){
			if(x<N && arr[y][x]==1){
				x++; y++;
			}
			else if(x>1 && arr[y][x-1]==1){
				x--; y++;
			}
			else y++;
		}
		if(x!=i) return;
	}
	ans=val;
}
void BT(int n){
	int i,j;
	if(n>=ans) return;
	for(j=1;j<N;j++){
		for(i=1;i<=H;i++){
			if(arr[i][j]) continue;
			if(j>1 && arr[i][j-1]) continue;
			if(j<N-1 && arr[i][j+1]) continue;
			arr[i][j]=1;
			cf(n);
			BT(n+1);
			arr[i][j]=0;
			while(1){
				if(i>=H) break;
				if(j>1 && arr[i][j-1]) break;
				if(j<N-1 && arr[i][j+1]) break;
				i++;
			}
		}
	}
}
int main(){
	int i;
	scanf("%d%d%d",&N,&M,&H);
	for(i=1;i<=M;i++){
		scanf("%d%d",&a,&b);
		arr[a][b]=1;
	}
	cf(0);
	BT(1);
	if(ans==4) printf("-1");
	else printf("%d",ans);
}
*/