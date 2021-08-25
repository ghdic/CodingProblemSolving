/*
https://www.acmicpc.net/problem/9184

&Title
	9184번 - 신나는 함수 실행출처다국어 

&Question
재귀 호출만 생각하면 신이 난다! 아닌가요?다음과 같은 재귀함수 
w(a, b, c)가 있다. if a <= 0 or 
b <= 0 or c <= 0, then w(a, 
b, c) returns: 1 if a > 20 or 
b > 20 or c > 20, then w(a, 
b, c) returns: w(20, 20, 20) if a < 
b and b < c, then w(a, b, c) 
returns: w(a, b, c-1) + w(a, b-1, c-1) - 
w(a, b-1, c) otherwise it returns: w(a-1, b, c) 
+ w(a-1, b-1, c) + w(a-1, b, c-1) - 
w(a-1, b-1, c-1) 위의 함수를 구현하는 것은 매우 쉽다. 
하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. 
(예를 들면, a=15, b=15, c=15)a, b, c가 주어졌을 때, 
w(a, b, c)를 출력하는 프로그램을 작성하시오. 

&Input
입력은 세 정수 a, b, c로 이루어져 있으며, 
한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 
나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 
없다. 

&Output
입력으로 주어진 각각의 a, b, c에 대해서, w(a, 
b, c)를 출력한다. 

&Example
-input
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1

-output
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int memo[51][51][51];

int recur(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return memo[a][b][c] = 1;
	if (memo[a][b][c] != 0)
		return memo[a][b][c];

	if (a > 20 || b > 20 || c > 20)
		return memo[20][20][20] = recur(20, 20, 20);
	if (a < b && b < c)
		return memo[a][b][c] = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);

	return memo[a][b][c] = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
}


int main() {
	ios::sync_with_stdio(false);
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(max(a, 0), max(b, 0), max(c, 0)) << "\n";
	}
	return 0;
}
*/