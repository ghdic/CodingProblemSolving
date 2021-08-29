/*
https://www.acmicpc.net/problem/4084

&Title
	4084번 - Viva la Diferencia출처다국어 

&Question
네 개의 양의 정수 a, b, c, d가 
있을 때, 아래와 같이 차이를 계산할 수 있다.|a-b| |b-c| 
|c-d| |d-a|이렇게 나온 네 개의 수를 이용해서 다시 또 
차이를 계산할 수 있다. 이 작업을 모든 네 개의 
정수가 같아질 때까지 반복한다.예를 들어, 1, 3, 5, 9로 
시작했을 때를 생각해보자.1 3 5 92 2 4 8 
(1)0 2 4 6 (2)2 2 2 6 (3)0 
0 4 4 (4)0 4 0 4 (5)4 4 
4 4 (6)위의 경우에서 수열은 6번 만에 수렴한다. a, 
b, c, d가 주어졌을 때, 이 수열이 얼마나 빨리 
수렴하는지 구하는 프로그램을 작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 
테스트 케이스는 한 줄로 이루어져 있고, a, b, c, 
d가 순서대로 주어진다. 입력의 마지막 줄에는 0이 4개 주어진다. 
(1 ≤ a,b,c,d ≤ 2,000,000,000) 

&Output
각 테스트 케이스에 대해서, 수열이 몇 번 만에 
수렴하는지 출력한다. 

&Example
-input
1 3 5 9
4 3 2 1
1 1 1 1
0 0 0 0

-output
6
4
0


*/

/*
#include <iostream>
#include <cmath>
using namespace std;

int a, b, c, d;

void f(int A, int B, int C, int D) {
	a = abs(A - B);
	b = abs(B - C);
	c = abs(C - D);
	d = abs(D - A);
}

int main() {
	ios::sync_with_stdio(false);
	while (true) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)break;
		int cnt = 0;
		while (!(a == b && b == c && c == d)) {
			f(a, b, c, d);
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
*/