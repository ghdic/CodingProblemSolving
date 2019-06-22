/*
https://www.acmicpc.net/problem/1929

&Title
1929번 - 소수 구하기

&Question
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 
두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) 


&Output
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다. 

&Example
-input
3 16

-output
3
5
7
11
13


*/

/*
#include <iostream>
using namespace std;

int arr[1000001] = { 0, 1 };
int main() {
	int a, b;
	ios::sync_with_stdio(false);
	cin >> a >> b;
	for (int i = 2; i <= b; i++)
		for (int j = 2; i * j <= b; j++)
			arr[i * j] = 1;
	for (int i = a; i <= b; i++) {
		if (!arr[i])cout << i << "\n";
	}
	
	return 0;
}
*/