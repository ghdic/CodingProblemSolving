/*
https://www.acmicpc.net/problem/2669

&Title
	2669번 - 직사각형 네개의 합집합의 면적 구하기출처 

&Question
평면에 네 개의 직사각형이 놓여 있는데 그 밑변은 
모두 가로축에 평행하다. 이 네 개의 직사각형들은 서로 떨어져 
있을 수도 있고, 겹쳐 있을 수도 있고, 하나가 다른 
하나를 포함할 수도 있으며, 변이나 꼭짓점이 겹칠 수도 있다. 
이 직사각형들이 차지하는 면적을 구하는 프로그램을 작성하시오. 

&Input
입력은 네 줄이며, 각 줄은 직사각형의 위치를 나타내는 
네 개의 정수로 주어진다. 첫 번째와 두 번째의 정수는 
사각형의 왼쪽 아래 꼭짓점의 x좌표, y좌표이고 세 번째와 네 
번째의 정수는 사각형의 오른쪽 위 꼭짓점의 x좌표, y좌표이다. 모든 
x좌표와 y좌표는 1이상이고 100이하인 정수이다. 

&Output
첫 줄에 네개의 직사각형이 차지하는 면적을 출력한다. 

&Example
-input
1 2 4 4
2 3 5 7
3 1 6 5
7 3 8 6
-output
26

*/

/*
#include <iostream>
using namespace std;

int arr[101][101];

void fill(int x1, int y1, int x2, int y2) {
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			arr[i][j] = 1;
		}
	}
}

int cnt() {
	int res = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] == 1)
				res++;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int a, b, c, d;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b >> c >> d;
		fill(a, b, c, d);
	}
	cout << cnt() << endl;
	return 0;
}
*/