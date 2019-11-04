/*
https://www.acmicpc.net/problem/1996

&Title
1996번 - 지뢰 찾기

&Question
다들 windows에서 지원하는 지뢰 찾기 게임을 한번쯤은 해 
보았을 것이다. 특히 동호는 지뢰찾기의 매니아로 알려져 있다. 지뢰 
찾기 map은 N*N의 정사각형 모양으로 각 칸에는 숫자가 들어가 
있거나 지뢰가 들어가 있다. 빈 칸에는 숫자 0이 들어있다고 
생각하자.map의 어떤 칸에 적혀 있는 숫자는, 그 칸과 인접해 
있는 여덟 개의 칸 중에서 지뢰가 들어 있는 칸이 
몇 개인지를 나타내 준다. 물론 인접한 칸이 map 내부에 
있는 경우에 대해서만 생각하면 된다. 예제를 보면 더 잘 
이해할 수 있을 것이다.이번 문제 조금 업그레이드 된 지뢰 
찾기로, 한 칸에 한 개의 지뢰가 있는 것이 아니고, 
한 칸에 여러 개(1 이상 9 이하)의 지뢰가 묻혀 
있는 게임이다. 따라서 map의 어떤 칸에 적혀 있는 숫자는, 
그 칸과 인접해 있는 여덟 개의 칸들에 들어 있는 
지뢰의 총 개수가 된다.이미 windows 지뢰찾기 같은 것을 마스터한 
영식이는, map에서 지뢰에 대한 정보만이 주어졌을 때, 영식이는 map을 
완성하고 싶다고 한다. N과 지뢰의 위치가 주어졌을 때, 영식이를 
도와서 지뢰 찾기 map을 완성하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1≤N≤1,000)이 주어진다. 다음 N개의 줄에는 지뢰 
찾기 map에 대한 정보가 주어지는데 '.' 또는 숫자로 이루어진 
문자열이 들어온다. '.'는 지뢰가 없는 것이고 숫자는 지뢰가 있는 
경우로 그 칸의 지뢰의 개수이다. 한 줄은 N개의 문자로 
이루어져 있다. 

&Output
N개의 줄에 걸쳐서 완성된 지뢰 찾기 map을 출력한다. 
지뢰는 '*'로 출력하며. 10 이상인 경우는 'M'(Many)으로 출력하면 된다. 
map은 숫자 또는 'M' 또는 '*'로만 이루어져 있어야 한다. 


&Example
-input
5
1....
..3..
.....
.4...
...9.
-output
*4330
14*30
47730
4*M99
44M*9

*/

/*
#include <iostream>
#include <string>
using namespace std;

int n;
string arr[1000], map[1000];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	string s = "";
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		s += '0';
	}
	for (int i = 0; i < n; ++i)
		map[i] = s;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != '.') {
				int val = arr[i][j] - '0';
				map[i][j] = '*';
				for (int k = 0; k < 8; ++k) {
					int y = i + dy[k], x = j + dx[k];
					if (y < 0 || y >= n || x < 0 || x >= n)continue;
					if (map[y][x] == '*')continue;
					map[y][x] += val;
				}
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (map[i][j] != '*' && map[i][j] > '9')
				map[i][j] = 'M';
	for (int i = 0; i < n; ++i)
		cout << map[i] << '\n';
	return 0;
}
*/