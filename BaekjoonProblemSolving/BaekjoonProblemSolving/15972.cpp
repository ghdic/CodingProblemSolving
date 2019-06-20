/*
https://www.acmicpc.net/problem/15972

&Title
15972번 - 물탱크서브태스크

&Question
세로 길이가 N, 가로 길이가 M, 높이가 H인 
물탱크가 있다. N, M, H는 모두 양의 정수이다. <그림 
1>은 세로 길이가 2, 가로 길이가 3, 높이가 5인 
물탱크 모양을 보여준다. <그림 1>에서 보듯이 물탱크 내부는 가로와 
세로로 벽이 설치되어 있는데, 내부 각 칸(즉 사각기둥 모양)의 
세로와 가로 길이는 1이고 높이는 H가 되도록 벽이 설치되어 
있다. 이 물탱크를 위에서 내려다보면 <그림 2>와 같이 각 
칸이 정사각형인 격자 모양이 된다. 물탱크 각 칸의 벽에는 
물 높이 조정을 위해 구멍이 뚫려 있을 수 있다. 
각 칸에는 네 개의 벽이 있는데, 각 벽 내부에는 
최대 한 개의 구멍이 뚫려 있을 수 있다. 단, 
모서리엔 구멍이 없다.<그림 1><그림 1>에서 구멍이 있는 높이는 바닥을 
기준으로 표시되어 있다. 구멍의 위치를 위에서 보면 <그림 2>처럼 
보이는데 이는 물탱크를 위에서 보았을때 어느 벽, 어떤 높이에 
구멍이 뚫려 있는지를 알려주며, <그림 1>에선 표시 하기 어려운 
물탱크의 구멍 위치도 표시한다. <그림 2>에서 보듯이 물탱크 내부 
벽에도 구멍이 있을 수 있다. <그림 2>물탱크에 물을 채울 
땐, 모든 구멍을 마개로 막아 물이 새지 못하도록 한 
후, 격자의 각 칸 위에 설치된 급수 장치를 통해 
물탱크 전체를 물로 채운다. 물이 꽉 찬 후에 구멍을 
막고 있는 모든 마개를 제거하면 물이 구멍을 통해 인접한 
방이나 외부로 흘러나가게 된다. 어느 정도 시간이 지나면 물이 
더 이상 흘러 나가지 않게 되고, 그 때 물탱크 
격자의 각 칸에 남아 있는 물의 높이는 서로 다를 
수 있다.참고로, <그림 2>에서 보인 물탱크의 각 칸에 남아 
있는 물의 높이를 나타내면 <그림 3>의 괄호 속의 수치와 
같다. <그림 3>벽의 두께를 무시할 때, 물탱크에 남아 있는 
물의 총량(부피)을 계산하는 프로그램을 작성하시오. 

&Input
표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 
물탱크의 세로 길이, 가로 길이, 높이를 나타내는 세 양의 
정수 N, M, H가 차례로 주어진다.다음 줄에는 첫 번째 
가로 벽에 설치된 구멍 정보를 나타내는 M개의 정수가 주어진다. 
각 정수는 왼쪽부터 시작하여 순서대로 각 칸의 구멍 높이를 
의미한다. 구멍의 높이는 0 이상 H미만의 정수이다. 해당 벽에 
구멍이 없는 경우는 –1로 표시한다. 이어지는 줄엔 두 번째 
가로 벽에 설치된 구멍 정보가 주어지고, 이런 식으로 N+1 
줄에 걸쳐 가로 벽에 설치된 모든 구멍에 대한 정보가 
주어진다.이어지는 줄에는 첫 번째 가로 벽을 공유하는 칸들(<그림 2>에서 
맨 윗줄의 칸들)의 세로 벽에 설치된 구멍 정보를 나타내는 
M+1개의 정수가 주어진다. 각 정수는 첫 번째 세로 벽부터 
시작하여 차례로 각 세로 벽의 구멍 높이를 나타낸다. 그 
다음 줄에는 그 다음에 있는 칸들의 세로 벽에 설치된 
구멍 정보가 주어진다. 이런 식으로 N줄에 걸쳐 세로 벽에 
설치된 모든 구멍 정보가 주어진다.참고로, 입출력 예에서 보인 첫 
번째 예제는 <그림 2>에서 보인 경우에 대응된다. 

&Output
물이 더 이상 흘러 나가지 않는 시점에 물탱크에 
남아 있는 물의 총량(부피)을 표준 출력으로 출력한다. 

&Example
-input
2 3 5
1 -1 -1
3 2 -1
4 -1 2
-1 -1 4 3
-1 -1 -1 -1

-output
17

-input
1 5 10
5 -1 -1 -1 6
-1 7 -1 6 -1
-1 2 8 4 2 3

-output
20


*/

/*

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, H; // 세로, 가로, 높이
bool check_horizontal[1003][1002] = {}, check_vertical[1002][1003] = {};
int horizontal[1003][1002] = {}, vertical[1002][1003] = {};
int board[1001][1001] = {};
void func(int y, int x) {
	if (!check_horizontal[y][x] && horizontal[y][x] != -1 && y != 1) {//위
		board[y - 1][x] = min(board[y - 1][x], max(horizontal[y][x], board[y][x]));
		check_horizontal[y][x] = true;
		func(y - 1, x);
		board[y][x] = min(board[y][x], max(horizontal[y][x], board[y - 1][x]));
		//check_horizontal[y][x] = false;
	}
	if (!check_horizontal[y + 1][x] && horizontal[y + 1][x] != -1 && y != N) {//아래
		board[y + 1][x] = min(board[y + 1][x], max(horizontal[y + 1][x], board[y][x]));
		check_horizontal[y + 1][x] = true;
		func(y + 1, x);
		board[y][x] = min(board[y][x], max(horizontal[y + 1][x], board[y + 1][x]));
		//check_horizontal[y + 1][x] = false;
	}
	if (!check_vertical[y][x] && vertical[y][x] != -1 && x != 1) {//왼
		board[y][x - 1] = min(board[y][x - 1], max(vertical[y][x], board[y][x]));
		check_vertical[y][x] = true;
		func(y, x - 1);
		board[y][x] = min(board[y][x], max(vertical[y][x], board[y][x - 1]));
		//check_vertical[y][x] = false;
	}
	if (!check_vertical[y][x + 1] && vertical[y][x + 1] != -1 && x != M) {//오
		board[y][x + 1] = min(board[y][x + 1], max(vertical[y][x + 1], board[y][x]));
		check_vertical[y][x + 1] = true;
		func(y, x + 1);
		board[y][x] = min(board[y][x], max(vertical[y][x + 1], board[y][x + 1]));
		//check_vertical[y][x + 1] = false;
	}
}
int main() {
	
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	//입력 받기
	cin >> N >> M >> H;
	for (int i = 1; i <= N + 1; i++)
		for (int j = 1; j <= M; j++)
			cin >> horizontal[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M + 1; j++)
			cin >> vertical[i][j];

	// 기본적으로 높이만큼 물을 다 채워줌
	for (int i = 1; i <= N; i++)
		fill(board[i] + 1, board[i] + M + 1, H);

	// 테두리 부분 미리 물 빼놓는다.
	for (int i = 1; i <= M; i++) {
		if (horizontal[1][i] != -1) board[1][i] = horizontal[1][i];
		if (horizontal[N + 1][i] != -1) board[N][i] = min(board[N][i], horizontal[N + 1][i]); //세로 1일때.. 최소
	}
	for (int i = 1; i <= N; i++) {
		if (vertical[i][1] != -1) board[i][1] = min(board[i][1], vertical[i][1]);
		if (vertical[i][M + 1] != -1) board[i][M] = min(board[i][M], vertical[i][M + 1]);
	}
	//테두리를 기준으로 bfs
	for (int i = 1; i <= M; i++) {
		if (horizontal[1][i] != -1) {
			check_horizontal[1][i] = true;
			func(1, i);
		}
		if (horizontal[N + 1][i] != -1) {
			check_horizontal[N + 1][i] = true;
			func(N, i);
		}
	}
	//// check 초기화
	//for (int i = 1; i <= N; i++) {
	//	fill(check_horizontal[i] + 1, check_horizontal[i] + M + 2, false);
	//	fill(check_horizontal[i] + 1, check_horizontal[i] + M + 2, false);
	//	fill(check_vertical[i] + 1, check_vertical[i] + M + 1, false);
	//	fill(check_vertical[i] + 1, check_vertical[i] + M + 1, false);
	//}
	//fill(check_vertical[N + 1] + 1, check_vertical[N + 1] + M + 1, false);
	//fill(check_vertical[N + 1] + 1, check_vertical[N + 1] + M + 1, false);
	for (int i = 1; i <= N; i++) {
		if (vertical[i][1] != -1) {
			check_vertical[i][1] = true;
			func(i, 1);
		}
		if (vertical[i][M + 1] != -1) {
			check_vertical[i][M + 1] = true;
			func(i, M);
		}
	}
	
	// 육면체의 높이의 합을 구함
	int sum = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			sum += board[i][j];
	cout << sum << endl;
	return 0;
}
*/

/*
내 소스 문제점
1. 시간이 너무 많이 걸림
처음 짠 소스는 자기가 visit한 흔적을 발을 뺄때 지우는데 시간복잡도가 어마무시하게 늘어난다
2. 값 갱신이 효율적이지 못함
board[y][x] 를 기준으로 왼쪽으로부터 board[y][x]가 갱신되었을때
오른쪽, 위, 아래 구멍이 뚫린 곳이 있다면 영향을 받는다.
이때 갱신되기전에 오른쪽, 위, 아래를 이미 방문했다면..? 재갱신해야 되는 어처구니 없는 상황이 발생하는것


c++
백점짜리 소스에 한번 주석 달아 보겟33
priority_queue를 써서 테두리 쪽에서 시작하는 방문의 순서를 정해준다.
전진하는 블록에 물의 높이가 바뀌지 않으면 굳이 전진하지 않는다.
```
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
	int x, y, h;
} pqelem;

struct compare
{
	bool operator () (pqelem a, pqelem b)	//priority_queue에 compare함수 높이를 오름차순으로 정리
	{
		if (a.h > b.h)
			return true;
		else
			return false;
	}
};

int main()
{
	int n, m, h, answer = 0;
	vector < vector <int> > a, b, ans;
	priority_queue <pqelem, vector <pqelem>, compare> pq;	// 트리로 만들었는지 디버깅할때 보면 순서대로 정렬되지 않은것 처럼 보임
	pqelem temp;

	scanf("%d %d %d", &n, &m, &h);
	a.resize(n+2);
	b.resize(n+1);
	ans.resize(n+1);
	//입력
	for (int i = 1; i <= n+1; i++)
	{
		a[i].resize(m+1);
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	}

	for (int i = 1; i <= n; i++)
	{
		b[i].resize(m+2);
		for (int j = 1; j <= m+1; j++)
			scanf("%d", &b[i][j]);
	}
	// 높이 최대 높이로 초기화
	for (int i = 1; i <= n; i++)
	{
		ans[i].resize(m+1);
		for (int j = 1; j <= m; j++)
			ans[i][j] = h;
	}
	// 높이 테두리 위 아래 갱신
	for (int i = 1; i <= m; i++)
	{
		if (a[1][i] != -1)
			ans[1][i] = a[1][i];
		if (a[n+1][i] != -1)
			ans[n][i] = min(ans[n][i],a[n+1][i]);
	}
	// 높이 테두리 왼쪽 오른쪽 갱신
	for (int i = 1; i <= n; i++)
	{
		if (b[i][1] != -1 && b[i][1] < ans[i][1])
			ans[i][1] = b[i][1];
		if (b[i][m+1] != -1 && b[i][m+1] < ans[i][m])
			ans[i][m] = b[i][m+1];
	}
	// 테두리를 우선순위 큐에 집어넣음
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || i == n)
		{
			for (int j = 1; j <= m; j++)
			{
				temp.x = i; temp.y = j; temp.h = ans[i][j];
				pq.push(temp);
			}
		}
		else
		{
			if (m == 1)
			{
				temp.x = i; temp.y = 1; temp.h = ans[i][1];
				pq.push(temp);
			}
			else
			{
				temp.x = i; temp.y = 1; temp.h = ans[i][1];
				pq.push(temp);
				temp.x = i; temp.y = m; temp.h = ans[i][m];
				pq.push(temp);
			}
		}
	}
	// 큐가 빌때까지 반복
	while (pq.size())
	{
		temp = pq.top();
		int x = temp.x, y = temp.y, hh = temp.h;
		pq.pop();

		if (hh != ans[x][y]) // hh != ans[x][y]는 이미 높이가 더 작아졌으니 굳이 돌필요 없다는 의미, 큐에 중복되서 들어 갈수도 있기 때문
			continue;

		//경계검사, -1이 아닌지, 왼쪽의 높이가 구멍 높이보다 큰지, 현재 높이가 구멍 높이보다 작거나 같은지
		//왼쪽의 높이는 구멍 높이가 된다
		if (x > 1 && a[x][y] != -1 && ans[x-1][y] > a[x][y] && ans[x][y] <= a[x][y])// 왼쪽
		{
			ans[x-1][y] = a[x][y];
			temp.x = x-1; temp.y = y; temp.h = ans[x-1][y];
			pq.push(temp);
		}
		//경계검사, -1이 아닌지, 현재 높이가 구멍 높이보다 크거나 같은지, 왼쪽 높이가 현재 구멍보다 큰지
		//왼쪽높이는 현재 높이가 된다.
		else if (x > 1 && a[x][y] != -1 && ans[x][y] >= a[x][y] && ans[x-1][y] > ans[x][y])
		{
			ans[x-1][y] = ans[x][y];
			temp.x = x-1; temp.y = y; temp.h = ans[x-1][y];
			pq.push(temp);
		}

		if (x < n && a[x+1][y] != -1 && ans[x+1][y] > a[x+1][y] && ans[x][y] <= a[x+1][y])// 오른쪽
		{
			ans[x+1][y] = a[x+1][y];
			temp.x = x+1; temp.y = y; temp.h = ans[x+1][y];
			pq.push(temp);
		}
		else if (x < n && a[x+1][y] != -1 && ans[x][y] >= a[x+1][y] && ans[x+1][y] > ans[x][y])
		{
			ans[x+1][y] = ans[x][y];
			temp.x = x+1; temp.y = y; temp.h = ans[x+1][y];
			pq.push(temp);
		}

		if (y > 1 && b[x][y] != -1 && ans[x][y-1] > b[x][y] && ans[x][y] <= b[x][y]) // 위쪽
		{
			ans[x][y-1] = b[x][y];
			temp.x = x; temp.y = y-1; temp.h = ans[x][y-1];
			pq.push(temp);
		}
		else if (y > 1 && b[x][y] != -1 && ans[x][y] >= b[x][y] && ans[x][y-1] > ans[x][y])
		{
			ans[x][y-1] = ans[x][y];
			temp.x = x; temp.y = y-1; temp.h = ans[x][y-1];
			pq.push(temp);
		}

		if (y < m && b[x][y+1] != -1 && ans[x][y+1] > b[x][y+1] && ans[x][y] <= b[x][y+1]) // 아래쪽
		{
			ans[x][y+1] = b[x][y+1];
			temp.x = x; temp.y = y+1; temp.h = ans[x][y+1];
			pq.push(temp);
		}
		else if (y < m && b[x][y+1] != -1 && ans[x][y] >= b[x][y+1] && ans[x][y+1] > ans[x][y])
		{
			ans[x][y+1] = ans[x][y];
			temp.x = x; temp.y = y+1; temp.h = ans[x][y+1];
			pq.push(temp);
		}
	}

	for (int i = 1; i <= n; i++) // 합계 구하기
	{
		for (int j = 1; j <= m; j++)
			answer += ans[i][j];
	}

	printf("%d", answer);
	return 0;
}
```
*/