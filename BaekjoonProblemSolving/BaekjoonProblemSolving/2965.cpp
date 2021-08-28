/*
https://www.acmicpc.net/problem/2965

&Title
	2965번 - 캥거루 세마리출처다국어 

&Question
캥거루 세 마리가 사막에서 놀고 있다. 사막에는 수직선이 
하나 있고, 캥거루는 서로 다른 한 좌표 위에 있다.한 
번 움직일 때, 바깥쪽의 두 캥거루 중 한 마리가 
다른 두 캥거루 사이의 정수 좌표로 점프한다. 한 좌표 
위에 있는 캥거루가 두 마리 이상일 수는 없다.캥거루는 최대 
몇 번 움직일 수 있을까? 

&Input
첫째 줄에 세 캥거루의 초기 위치 A, B, 
C가 주어진다. (0 < A < B < C 
< 100) 

&Output
캥거루가 최대 몇 번 움직일 수 있는지 출력한다. 


&Example
-input
2 3 5

-output
1

-input
3 5 9

-output
3


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	cout << max(b - a - 1, c - b - 1) << endl;
	return 0;
}
*/