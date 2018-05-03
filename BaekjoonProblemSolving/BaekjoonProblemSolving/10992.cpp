/*
https://www.acmicpc.net/problem/10992

&Title
10992번 - 별 찍기 - 17

&Question
예제를 보고 별찍는 규칙을 유추한 뒤에 별을 찍어 
보세요. 

&Input
첫째 줄에 N (1<=N<=100)이 주어진다. 

&Output
첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다. 


&Example
-input
1

-output
*

-input
2

-output
 *
***
-input
3

-output
  *
 * *
*****
-input
4

-output
   *
  * *
 *   *
*******


*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N*2-1; j++) {
			if (i == N - 1)cout << "*";
			else {
				if (j == N-i-1 || j == N +i-1)cout << "*";
				else if (N - i - 1 > j||(N-i-1<j&&j<N+i-1))cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
*/