/*
https://www.acmicpc.net/problem/6131

&Title
	6131번 - 완전 제곱수출처다국어 

&Question
상근이는 선영이와 함께 게임을 하고 있다. 먼저, 상근이는 
두 양의 정수 A와 B를 고른다. (1 ≤ B 
≤ A ≤ 500) 그 다음, 선영이는 상근이가 고른 
수를 맞춰야 한다.상근이는 선영이에게 다음과 같은 힌트를 주었다.A의 제곱은 
B의 제곱보다 N만큼 커 (1 ≤ N ≤ 1,000)위의 
힌트 조건을 만족하는 A와 B 쌍의 개수를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 N이 주어진다. 

&Output
상근이의 힌트 조건을 만족하는 (A,B) 쌍의 개수를 출력한다. 


&Example
-input
15

-output
2


*/

/*
#include <iostream>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int res = 0;
	for (int i = 1; i <= 500; i++) {
		for (int j = i; j <= 500; j++) {
			int num = j * j - i * i;
			if (num == n)
				res++;
			else if (num > n) break;
		}
	}
	cout << res << endl;
	return 0;
}
*/