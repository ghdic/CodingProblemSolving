/*
https://www.acmicpc.net/problem/18870

&Title
	18870번 - 좌표 압축

&Question
수직선 위에 N개의 좌표 X1, X2, ..., XN이 
있다. 이 좌표에 좌표 압축을 적용하려고 한다.Xi를 좌표 압축한 
결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 
좌표의 개수와 같아야 한다.X1, X2, ..., XN에 좌표 압축을 
적용한 결과 X'1, X'2, ..., X'N를 출력해보자. 

&Input
첫째 줄에 N이 주어진다.둘째 줄에는 공백 한 칸으로 
구분된 X1, X2, ..., XN이 주어진다. 

&Output
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 
칸으로 구분해서 출력한다. 

&Example
-input
5
2 4 -10 4 -9

-output
2 3 0 3 1

-input
6
1000 999 1000 999 1000 999

-output
1 0 1 0 1 0


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<int> v, c;
unordered_map<int, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		int i;
		cin >> i;
		v.push_back(i);
		c.push_back(i);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++) {
		um.insert({ v[i], i });
	}

	for (int i : c) {
		cout << um[i] << " ";
	}

	return 0;
}
*/