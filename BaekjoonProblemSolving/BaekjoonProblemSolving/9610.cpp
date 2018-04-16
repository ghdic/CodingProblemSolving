/*
https://www.acmicpc.net/problem/9610

&Title
사분면
&Question
2차원 좌표 상의 여러 점의 좌표 (x,y)가 주어졌을 때, 각 사분면과 축에 점이 몇 개 있는지 구하는 프로그램을 작성하시오.
&Input
첫째 줄에 점의 개수 n (1 ≤ n ≤ 1000)이 주어진다. 다음 n개 줄에는 점의 좌표 (xi, yi)가 주어진다. (-106 ≤ xi, yi ≤ 106)
&Output
각 사분면과 축에 점이 몇 개 있는지를 예제 출력과 같은 형식으로 출력한다.
&Example
-input
5
0 0
0 1
1 1
3 -3
2 2
-output
Q1: 2
Q2: 0
Q3: 0
Q4: 1
AXIS: 2
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, x, y, Q1 = 0, Q2 = 0, Q3 = 0, Q4 = 0, AXIS = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (x > 0 && y > 0)Q1++;
		else if (x < 0 && y>0)Q2++;
		else if (x < 0 && y < 0)Q3++;
		else if (x > 0 && y < 0)Q4++;
		else AXIS++;
	}
	cout << "Q1: " << Q1 << endl;
	cout << "Q2: " << Q2 << endl;
	cout << "Q3: " << Q3 << endl;
	cout << "Q4: " << Q4 << endl;
	cout << "AXIS: " << AXIS << endl;

	return 0;
}
*/