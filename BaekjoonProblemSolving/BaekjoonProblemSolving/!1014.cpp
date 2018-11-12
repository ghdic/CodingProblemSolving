/*
https://www.acmicpc.net/problem/1014

&Title
1014번 - 컨닝

&Question
최백준은 서강대학교에서 “컨닝의 기술”이라는 과목을 가르치고 있다. 이 
과목은 상당히 까다롭기로 정평이 나있기 때문에, 몇몇 학생들은 시험을 
보는 도중에 다른 사람의 답지를 베끼려 한다.시험은 N행 * 
M열 크기의 직사각형 교실에서 이루어진다. 교실은 1*1 크기의 단위 
정사각형으로 이루어져 있는데, 각 단위 정사각형은 자리 하나를 의미한다.최백준은 
컨닝을 방지하기 위해서 다음과 같은 전략을 세웠다. 모든 학생은 
자신의 왼쪽, 오른쪽, 왼쪽 대각선 위, 오른쪽 대각선 위, 
이렇게 총 네 자리에 앉아있는 친구의 답지를 항상 베낀다고 
가정한다. 따라서, 자리 배치는 모든 학생이 컨닝을 할 수 
없도록 배치되어야 한다.위의 그림을 보자. A , C , 
D 혹은 E에 다른 학생을 앉히는 것은 좋은 생각이 
아니다. 그 이유는 이미 앉아있는 학생이 그들의 답안지를 베낄 
우려가 있기 때문이다. 하지만, B에 다른 학생을 앉힌다면, 두 
학생은 서로의 답지를 베낄 수 없어 컨닝의 우려가 없다.위와 
같이 컨닝이 불가능하도록 자리를 배치 하려는 최백준의 행동에 분노한 
일부 학생들이 교실의 책상을 부숴버렸기 때문에, 일부 자리에는 학생이 
앉을 수 없다.최백준은 교실의 모양이 주어졌을 때, 이 곳에서 
아무도 컨닝을 할 수 없도록 학생을 배치하였을 경우에 교실에 
배치할 수 있는 최대 학생 수가 몇 명인지 궁금해졌다. 
최백준을 위해 이를 구하는 프로그램을 작성하라. 

&Input
입력의 첫 줄에는 테스트케이스의 개수 C가 주어진다. 각각의 
테스트 케이스는 아래와 같이 두 부분으로 이루어진다.첫 번째 부분에서는 
교실의 세로길이 N과 가로길이 M이 한 줄에 주어진다. (1 
≤ M ≤ 10, 1 ≤ N ≤ 10)두 
번째 부분에서는 정확하게 N줄이 주어진다. 그리고 각 줄은 M개의 
문자로 이루어져있다. 모든 문자는 ‘.’(앉을 수 있는 자리) 또는 
‘x’(앉을 수 없는 자리, 소문자)로 구성된다. 

&Output
각각의 테스트 케이스에 대해 그 교실에서 시험을 볼 
수 있는 최대 학생의 수를 출력한다. 

&Example
-input
4
2 3
...
...
2 3
x.x
xxx
2 3
x.x
x.x
10 10
....x.....
..........
..........
..x.......
..........
x...x.x...
.........x
...x......
........x.
.x...x....

-output
4
1
2
46


*/

//http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220617896760
//http://jda2002.tistory.com/entry/%EB%B0%B1%EC%A4%80-1014%EB%B2%88-%EC%BB%A8%EB%8B%9D
/*
//네트워크 플로우
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// 컨닝 가능한 다른 6개의 자리와의 행, 열 번호 차
const int roff[6] = { -1, 0, 1, -1, 0, 1 };
const int coff[6] = { -1, -1, -1, 1, 1, 1 };

int A, B;
vector<int> adj[50];
int Amatch[50], Bmatch[50];
bool visited[50];

//dfs를 통한 이분 매칭
bool DFS(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for(int b: adj[a])
		if (Bmatch[b] == -1 || DFS(Bmatch[b])) {
			Amatch[a] = b;
			Bmatch[b] = a;
			return true;

		}
	return false;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N, M, broken = 0;
		scanf("%d %d", &N, &M);
		//지도를 입력 받으면서 부서진 자리의 개수를 세 둠
		bool map[10][10];
		for (int i = 0; i < N; i++) {
			//엔터버퍼를 먹음
			getchar();
			for (int j = 0; j < M; j++)
				broken += map[i][j] = (getchar() == 'x');
		}

		//편의를 위해 각 자리가 가지는 노드의 번호를 계산해 둠
		int nodeNum[10][10];
		A = B = 0;
		for(int i=0;i<N;i++)
			for (int j = 0; j < M; j += 2) {
				adj[A].clear();
				nodeNum[i][j] = A++;
			}

		for (int i = 0; i < N; i++)
			for (int j = 1; j < M; j += 2)
				nodeNum[i][j] = B++;

		//컨닝이 가능한 빈 자리 쌍에 대해 A그룹에서 B그룹으로 가는 간선 추가
		for(int j=0;j<M;j+=2)
			for (int i = 0; i < N; i++) {
				if (map[i][j])continue;
				for (int d = 0; d < 6; d++) {
					int ni = i + roff[d];
					int nj = j + coff[d];
					if (ni < 0 || ni >= N || nj < 0 || nj >= M || map[ni][nj]) continue;
					adj[nodeNum[i][j]].push_back(nodeNum[ni][nj]);
				}
			}
		// 이분 매칭으로 맥스 플로우 구함
		int maxMatch = 0;
		memset(Amatch, -1, sizeof(Amatch));
		memset(Bmatch, -1, sizeof(Bmatch));
		for (int i = 0; i < A; i++) {
			memset(visited, 0, sizeof(visited));
			if (DFS(i)) maxMatch++;
		}
		// 빈 자리 개수에서 맥스 플로우를 빼면 정답
		printf("%d\n", N*M - broken - maxMatch);
	}


	return 0;
}
*/