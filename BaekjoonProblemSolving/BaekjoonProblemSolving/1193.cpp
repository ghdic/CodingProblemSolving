/*
https://www.acmicpc.net/problem/1193

&Title
1193번 - 분수찾기

&Question
무한히 큰 배열에 다음과 같이 분수들이 적혀있다.1/11/21/31/41/5…2/12/22/32/4……3/13/23/3………4/14/2…………5/1……………………………이와 같이 
나열된 분수들을 1/1 -> 1/2 -> 2/1 -> 3/1 
-> 2/2 -> … 과 같은 지그재그 순서로 차례대로 
1번, 2번, 3번, 4번, 5번, … 분수라고 하자.X가 주어졌을 
때, X번째 분수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다. 


&Output
첫째 줄에 분수를 출력한다. 

&Example
-input
14

-output
2/4


*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, cnt = 1, m = 1, a, b;
	ios::sync_with_stdio(false);
	cin >> N;
	while (cnt + m <= N) {
		cnt += m++;
	}
	if (m % 2 == 0) {
		a = 1, b = m;
		m = N - cnt;
		while (m--) {
			a++, b--;
		}
	}
	else {
		a = m, b = 1;
		m = N - cnt;
		while (m--) {
			a--, b++;
		}
	}
	cout << a << "/" << b << endl;
	return 0;
}
*/