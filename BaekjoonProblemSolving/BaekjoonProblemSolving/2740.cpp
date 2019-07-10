/*
https://www.acmicpc.net/problem/2740

&Title
2740번 - 행렬 곱셈

&Question
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 
두 행렬을 곱하는 프로그램을 작성하시오. 

&Input
첫째 줄에 행렬 A의 크기 N 과 M이 
주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 
순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 
K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 
차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 
행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다. 

&Output
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 
행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다. 

&Example
-input
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3

-output
-1 -2 6
-3 -6 12
-5 -10 18


*/

/*
#include <iostream>
using namespace std;

int matrix1[100][100], matrix2[100][100], matrix3[100][100];
int main() {
	int N, M, K; // 1~100
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> matrix1[i][j];
	cin >> M >> K;
	for (int i = 0; i < M; ++i)
		for (int j = 0; j < K; ++j)
			cin >> matrix2[i][j];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			int sum = 0;
			for (int k = 0; k < M; ++k)
				sum += matrix1[i][k] * matrix2[k][j];
			matrix3[i][j] = sum;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K - 1; ++j) {
			cout << matrix3[i][j] << " ";
		}
		cout << matrix3[i][K - 1] << "\n";
	}
	return 0;
}
*/