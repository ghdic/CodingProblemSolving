/*
https://www.acmicpc.net/problem/5671

&Title
5671번 - 호텔 방 번호

&Question
선영이는 집 호수에 반복되는 숫자가 있는 경우에는 그 
집에 사는 사람에게 불운이 찾아온다고 믿는다. 따라서, 선영이는 838호나 
1004호와 같이 한 숫자가 두 번 이상 들어있는 집에는 
절대 살지 않을 것이다.2050년, 선영이는 한국에서 가장 돈이 많은 
사람이 되었다. 그녀는 해변가에 새로운 호텔을 하나 지으려고 한다. 
하지만, 투숙객에게 불운이 찾아오는 것을 피하기 위해서 반복되는 숫자가 
없게 방 번호를 만들려고 한다.정부는 선영이의 호텔 방 번호는 
N보다 크거나 같고, M보다 작거나 같아야 한다는 조건을 걸고 
신축 허가를 내주었다. 선영이의 새 호텔에는 방이 최대 몇 
개 있을 수 있을까? (두 방이 같은 방 번호를 
사용할 수 없다) 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있고, 한 
줄이다. 각 줄에는 문제의 설명에 나와있는 N과 M이 주어진다. 
(1 ≤ N ≤ M ≤ 5000) 

&Output
각각의 테스트 케이스에 대해서 N보다 크거나 같고, M보다 
작거나 같은 수 중에서 반복되는 숫자가 없는 것의 개수를 
출력한다. 

&Example
-input
87 104
989 1022
22 25
1234 1234

-output
14
0
3
1


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cache[5001];

bool isFortuneNum(int num) {
	int& res = cache[num];
	if (res != -1)return (bool)res;
	res = 1;
	bool dict[10] = {};
	while (num) {
		int k = num % 10;
		num /= 10;
		if (dict[k]) {
			res = 0;
			break;
		}
		else {
			dict[k] = true;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	fill(cache, cache + 5001, -1);
	while (cin >> n >> m) {
		int cnt = 0;
		for (int i = n; i <= m; ++i) {
			if (isFortuneNum(i))
				++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}
*/