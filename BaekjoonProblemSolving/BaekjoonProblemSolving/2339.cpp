/*
https://www.acmicpc.net/problem/2339

&Title
2339번 - 석판 자르기

&Question
하나 이상의 불순물과 보석 결정체로 이루어진 석판을 여러 
조각으로 나누어 가공해서, 보다 높은 가치를 얻을 수 있도록 
만들려고 한다. 이때, 높은 가치의 석판을 만들기 위해서는 석판을 
여러 조각으로 나누되, 각 조각에는 불순물이 없도록 해야하며, 보석 
결정체도 단 하나씩만 포함하고 있어야 한다.또한, 석판에서 불순물을 빼내기 
위해서는 불순물을 포함하고 있는 지점을 중심으로 잘라야 되는데, 석판의 
결 때문에 가로 또는 세로 방향으로만 석판을 자를 수 
있다. 석판을 자를 때에는 이전에 자른 방향과 같은 방향으로는 
자를 수 없다. (단, 처음에 자를 때는 가로방향이나, 세로방향 
모두 가능하다.)석판에 있는 불순물과 보석 결정체의 정보가 주어질 때, 
이 석판에서 불순물들을 없애면서 석판을 나누되, 각 조각에 반드시 
하나의 보석 결정체만이 들어 있도록 석판을 나누는 방법이 모두 
몇 가지 존재하는지 계산하시오.위의 그림은 초기 석판의 상태에서 불순물을 
제거하면서 석판을 잘랐을 때, 최종적으로 나뉘어진 석판의 모습이다. 회색 
선은 불순물을 중심으로 가로 또는 세로 방향으로 자른 경계선이고, 
노란 색은 보석을 하나씩만 포함하고 있는 석판이다. 석판을 자를 
때 ②번이나 ③번은 이전에 잘려진 방향, 즉 ①번의 방향과 
같은 방향으로 자를 수 없으며, ④ 번도 마찬가지로 ②번과는 
같은 방향으로 자를 수 없다. 단순하게 자르는 순서를 의미하는 
것이 아니므로, ④번 방향이 ③번 방향과 같을 수도 있다.잘라진 
석판은 반드시 두 개의 석판이 나뉘어진 것이어야 한다. 또한 
결정체가 있는 곳은 자를 수 없으며, 최종적으로 나뉘어진 석판에 
두 개 이상의 결정체가 오면 안 된다. 

&Input
첫 번째 줄에는 석판의 크기 N(1≤N≤20)이 들어온다. 다음 
줄부터 N줄에 걸쳐서 석판의 상태가 입력으로 들어온다. 여기서 1은 
불순물을 의미하며, 2는 보석 결정체, 0은 불순물과 보석결정체가 존재하지 
않는 곳을 의미한다. 이때, 보석 결정체의 수는 15개를 넘지 
않으며, 각 줄에 주어지는 석판의 정보는 공백 하나로 구분한다. 


&Output
각각의 석판 안에 불순물이 없으면서 단 하나의 보석 
결정체만이 있도록 주어진 석판을 나눌 때, 모두 몇 가지의 
경우가 존재하는지를 출력하시오. 이때 가능한 경우가 존재하지 않으면 -1을 
출력한다. 

&Example
-input
8
0 0 0 0 0 2 0 0
0 0 0 0 0 0 1 0
0 0 2 1 0 0 2 0
0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 2 1 0 0 0
0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 0

-output
1

*/

/*
1. 석판을 불순물 기준으로 여러개를 나눈다.
2. 조각에는 불순물이 없어야하며, 보석 결정체도 단 하나씩 포함해야함
& 결정체가 있는곳은 자를수 없다
불순물:1, 보석결정체:2, 빈곳:0

인간처럼 생각하기
1. 해당 판떼기가 불순물이0개구 보석이 1개있는지 확인한다.
2. 불순물을 찾는다
3. 해당 불순물을 기준으로 둘로 나눌수 있으면 나눈다.
나눈 판떼기로 해당 과정을 반복한다.
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BLANK 0
#define DEBRIS 1
#define CRYSTAL 2

struct pos {
	int y = 0, x = 0;
};

struct slate {
	vector<pos> debris;
	int crystal = 0;
};

int n, map[20][20];

// 해당 영역에 먼지와 보석의 개수 및 먼지 위치 구하는 함수
void get_info(pos start, pos end, slate& a) {
	for (int i = start.y; i <= end.y; ++i)
		for (int j = start.x; j <= end.x; ++j)
			if (map[i][j] == DEBRIS)
				a.debris.push_back({ i, j });
			else if (map[i][j] == CRYSTAL)
				++a.crystal;
}

// 해당 라인으로 짤라도 되는지 확인 dir=false수직, true수평
bool checkDiv(pos& start, pos& end, pos& p, bool dir) {
	if (dir) {
		if (p.y <= start.y || p.y >= end.y)return false;
		for (int i = start.x; i <= end.x; ++i)
			if (map[p.y][i] == CRYSTAL)return false;
	}
	else {
		if (p.x <= start.x || p.x >= end.x)return false;
		for (int i = start.y; i <= end.y; ++i)
			if (map[i][p.x] == CRYSTAL)return false;
	}
	return true;
}

// 시작점, 끝점, 무슨방향으로 잘라야하는지
int divide_conquer(pos start, pos end, bool dir) {
	slate cur;

	get_info(start, end, cur);

	// 석판엔 1개의 크리스탈과 0개의 부스러기만 남아있어야함
	if (cur.crystal == 1 && cur.debris.size() == 0)return 1;
	// 기저 조건 : 크리스탈 또는 부스러기가 0개일때
	if (cur.crystal == 0 || cur.debris.size() == 0)return 0;

	int res = 0;
	// 각 부스러기 별로 잘라봄
	for (int i = 0; i < cur.debris.size(); ++i) {
		// 이미 같은 위치에 같은 방향으로 자른 경우 pass

		// 이전에 잘린 방향과 반대 방향으로 자를 수 있는지 확인
		if (checkDiv(start, end, cur.debris[i], dir)) {
			// 가로
			if (dir) {
				res += divide_conquer(start, { cur.debris[i].y - 1, end.x }, !dir) * divide_conquer({ cur.debris[i].y + 1, start.x }, end, !dir);
			}
			// 세로
			else {
				res += divide_conquer(start, { end.y, cur.debris[i].x - 1 }, !dir) * divide_conquer({ start.y, cur.debris[i].x + 1 }, end, !dir);
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];
	int res = divide_conquer({ 0, 0 }, { n - 1, n - 1 }, true) + divide_conquer({ 0, 0 }, { n - 1, n - 1 }, false);
	if (res == 0)res = -1;
	cout << res << endl;
	return 0;
}
*/