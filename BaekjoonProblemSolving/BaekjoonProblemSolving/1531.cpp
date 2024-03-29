/*
https://www.acmicpc.net/problem/1531

&Title
	1531번 - 투명

&Question
세준이는 1*1크기의 그림으로 모자이크한 100*100크기의 그림을 가지고 있다. 
어느 날 이 모자이크 중 일부 그림이 너무 보기 
싫어서 N개의 불투명한 종이로 그림을 가리기 시작했다. 불투명한 종이로 
가린다고 항상 그 그림이 안 보이는 것은 아니다. 그 
그림의 현재 부분 위에 M개 이하의 종이가 올려져 있으면 
그림은 그 부분에서 보이게 된다.그림의 크기는 100*100이고, N개의 종이는 
왼쪽 아래 모서리 좌표와 오른쪽 위 모서리 좌표가 입력으로 
들어온다. 또, 종이가 가리는 영역에는 두 모서리의 좌표도 포함된다. 
예를 들어, (1,1)부터 (2,2)를 가린다면, 총 4개의 그림이 가려진다. 
(1,1), (1,2), (2,1), (2,2).100*100크기의 모자이크 중에 보이지 않는 그림의 
개수를 세는 프로그램을 작성하시오. 

&Input
첫째 줄에 N과 M이 주어진다. N은 0보다 크거나 
같고, 50보다 작거나 같다. M은 0보다 크거나 같고, 50보다 
작거나 같다. 둘째 줄부터 N개의 줄에 종이의 좌표가 주어진다. 
왼쪽 아래 모서리의 x, y좌표, 오른쪽 위 모서리의 x, 
y좌표 순으로 주어진다. 모든 좌표는 100보다 작거나 같은 자연수이다. 


&Output
첫째 줄에 정답을 출력한다. 

&Example
-input
3 1
21 21 80 80
41 41 60 60
71 71 90 90

-output
500


*/

/*
#include <iostream>
using namespace std;

int n, k, arr[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i <= c; i++)
			for (int j = b; j <= d; j++)
				arr[i][j] += 1;
	}
	int res = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (arr[i][j] > k)
				res++;
	cout << res << endl;
	return 0;
}
*/