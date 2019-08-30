/*
https://www.acmicpc.net/problem/5373

&Title
5373번 - 큐빙

&Question
루빅스 큐브는 삼차원 퍼즐이다. 보통 루빅스 큐브는 3×3×3개의 
작은 정육면체로 이루어져 있다. 퍼즐을 풀려면 각 면에 있는 
아홉 개의 작은 정육면체의 색이 동일해야 한다.큐브는 각 면을 
양방향으로 90도 만큼 돌릴 수 있도록 만들어져 있다. 회전이 
마친 이후에는, 다른 면을 돌릴 수 있다. 이렇게 큐브의 
서로 다른 면을 돌리다 보면, 색을 섞을 수 있다.이 
문제에서는 루빅스 큐브가 모두 풀린 상태에서 시작한다. 윗 면은 
흰색, 아랫 면은 노란색, 앞 면은 빨간색, 뒷 면은 
오렌지색, 왼쪽 면은 초록색, 오른쪽 면은 파란색이다.루빅스 큐브를 돌린 
방법이 순서대로 주어진다. 이때, 모두 돌린 다음에 가장 윗 
면의 색상을 구하는 프로그램을 작성하시오.위의 그림은 루빅스 큐브를 푼 
그림이다. 왼쪽 면은 시계방향으로 조금 돌려져 있는 상태이다. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 
최대 100개이다. 각 테스트 케이스는 다음과 같이 구성되어져 있다.첫째 
줄에 큐브를 돌린 횟수 n이 주어진다. (1 ≤ n 
≤ 1000)둘째 줄에는 큐브를 돌린 방법이 주어진다. 각 방법은 
공백으로 구분되어져 있으며, 첫 번째 문자는 돌린 면이다. U: 
윗 면, D: 아랫 면, F: 앞 면, B: 
뒷 면, L: 왼쪽 면, R: 오른쪽 면이다. 두 
번째 문자는 돌린 방향이다. +인 경우에는 시계 방향 (그 
면을 바라봤을 때가 기준), -인 경우에는 반시계 방향이다. 

&Output
각 테스트 케이스에 대해서 큐브를 모두 돌린 후의 
윗 면의 색상을 출력한다. 첫 번째 줄에는 뒷 면과 
접하는 칸의 색을 출력하고, 두 번째, 세 번째 줄은 
순서대로 출력하면 된다. 흰색은 w, 노란색은 y, 빨간색은 r, 
오렌지색은 o, 초록색은 g, 파란색은 b. 

&Example
-input
4
1
L-
2
F+ B+
4
U- D- L+ R+
10
L- U- L+ U- L- U- U- L+ U+ U+

-output
rww
rww
rww
bbb
www
ggg
gwg
owr
bwb
gwo
www
rww


*/


/*            U
		  0  1  2
		  3  4  5
		  6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
		-----------
		  9  10 11
		  12 13 14
		  15 16 17
		  D
*/

/*
#include <cstdio>
enum FACE { U, D, F, B, L, R, SIZE };
char init[7] = "wyrogb";
char arr[55];
int cube[SIZE][3][3];
char temp[3][3];

int rot[6][12] = {
	{36,37,38,18,19,20,45,46,47,27,28,29},        //U
	{33,34,35,51,52,53,24,25,26,42,43,44},        //D
	{6,7,8,44,41,38,11,10,9,45,48,51},            //F
	{2,1,0,53,50,47,15,16,17,36,39,42},            //B
	{0,3,6,35,32,29,9,12,15,18,21,24},            //L
	{8,5,2,26,23,20,17,14,11,27,30,33}            //R
};

void rotate(FACE f, int cnt) {
	char que[12];
	while (cnt--) {
		// 옆을 돌림
		for (int i = 0; i < 12; ++i)
			que[i] = arr[rot[f][i]];
		for (int i = 0; i < 12; ++i)
			arr[rot[f][i]] = que[(i + 3) % 12];
		// 면을 돌림
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				temp[j][2 - i] = arr[cube[f][i][j]];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				arr[cube[f][i][j]] = temp[i][j];
	}
}

int conv[256];

int main() {
	conv['-'] = 3;
	conv['+'] = 1;
	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;

	// 큐브 인덱스 부여하기
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				cube[i][j][k] = i * 9 + j * 3 + k;
	int n, m;
	char comm[3];
	scanf("%d\n", &n);

	while (n--) {
		// 큐브 초기화
		for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 9; ++j)
				arr[i * 9 + j] = init[i];
		scanf("\n%d\n", &m);

		while (m--) {
			scanf("%s \n", comm);
			int f = conv[comm[0]], cnt = conv[comm[1]];
			rotate((FACE)f, cnt);
		}
		// 출력
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				printf("%c", arr[cube[U][i][j]]);
			printf("\n");
		}
	}
	return 0;
}
*/


/*
// 이리 짤려했는데 쩝 면 회전을 안했었다 .. ㅋㅋ
#include<iostream>
#include<vector>

#define Up 3
#define Down 6
#define Front 5
#define Back 1
#define Left 2
#define Right 4

using namespace std;

char map[7][4][4];
char mmun[7] = {'.','o','g','w','b','r','y'};

void init()
{
	for(int i = 1; i <= 6; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			for(int k = 1; k <= 3; k++)
			{
				map[i][j][k] = mmun[i];
			}
		}
	}
}

void turnUp()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[5][1][i];
		map[5][1][i] = map[4][j][1];
		map[4][j][1] = map[1][3][j];
		map[1][3][j] = map[2][i][3];
		map[2][i][3] = tmp;
	}
}

void turnFront()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[6][1][i];
		map[6][1][i] = map[4][3][j];
		map[4][3][j] = map[3][3][j];
		map[3][3][j] = map[2][3][j];
		map[2][3][j] = tmp;
	}
}

void turnRight()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[6][i][3];
		map[6][i][3] = map[1][i][3];
		map[1][i][3] = map[3][i][3];
		map[3][i][3] = map[5][i][3];
		map[5][i][3] = tmp;
	}
}

void turnLeft()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[6][i][1];
		map[6][i][1] = map[5][i][1];
		map[5][i][1] = map[3][i][1];
		map[3][i][1] = map[1][i][1];
		map[1][i][1] = tmp;
	}
}

void turnBack()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[6][3][j];
		map[6][3][j] = map[2][1][i];
		map[2][1][i] = map[3][1][i];
		map[3][1][i] = map[4][1][i];
		map[4][1][i] = tmp;
	}
}

void turnDown()
{
	for(int i = 1, j = 3; i <= 3; i++, j--)
	{
		int tmp = map[1][1][i];
		map[1][1][i] = map[4][i][3];
		map[4][i][3] = map[5][3][j];
		map[5][3][j] = map[2][j][1];
		map[2][j][1] = tmp;
	}
}

void turnMun(int mun)
{
	int tmp = map[mun][1][1];
	map[mun][1][1] = map[mun][3][1];
	map[mun][3][1] = map[mun][3][3];
	map[mun][3][3] = map[mun][1][3];
	map[mun][1][3] = tmp;

	int ttmp = map[mun][1][2];
	map[mun][1][2] = map[mun][2][1];
	map[mun][2][1] = map[mun][3][2];
	map[mun][3][2] = map[mun][2][3];
	map[mun][2][3] = ttmp;
}

void top(char mun, char dir)
{
	if(mun == 'U')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnUp();
			turnMun(Up);
		}
	}
	else if(mun == 'D')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnDown();
			turnMun(Down);
		}
	}
	else if(mun == 'F')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnFront();
			turnMun(Front);
		}
	}
	else if(mun == 'B')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnBack();
			turnMun(Back);
		}
	}
	else if(mun == 'L')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnLeft();
			turnMun(Left);
		}
	}
	else if(mun == 'R')
	{
		int count;
		if(dir == '+') count = 1;
		else count = 3;

		for(int i = 0; i < count; i++)
		{
			turnRight();
			turnMun(Right);
		}
	}
}


void printUp()
{
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			cout << map[Up][i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for(int x = 0; x < testcase; x++)
	{
		int n;
		cin >> n;

		init();

		for(int y = 0; y < n; y++)
		{
			char mun, dir;
			cin >> mun >> dir;

			top(mun, dir);
		}
		printUp();
	}
	return 0;
}
*/