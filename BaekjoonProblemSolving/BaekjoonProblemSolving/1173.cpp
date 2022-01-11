/*
https://www.acmicpc.net/problem/1173

&Title
	1173번 - 운동

&Question
영식이가 운동을 하는 과정은 1분 단위로 나누어져 있다. 
매 분마다 영식이는 운동과 휴식 중 하나를 선택해야 한다.운동을 
선택한 경우, 영식이의 맥박이 T만큼 증가한다. 즉, 영식이의 맥박이 
X였다면, 1분 동안 운동을 한 후 맥박이 X+T가 되는 
것이다. 영식이는 맥박이 M을 넘는 것을 원하지 않기 때문에, 
X+T가 M보다 작거나 같을 때만 운동을 할 수 있다. 
휴식을 선택하는 경우 맥박이 R만큼 감소한다. 즉, 영식이의 맥박이 
X였다면, 1분 동안 휴식을 한 후 맥박은 X-R이 된다. 
맥박은 절대로 m보다 낮아지면 안된다. 따라서, X-R이 m보다 작으면 
맥박은 m이 된다.영식이의 초기 맥박은 m이다. 운동을 N분 하려고 
한다. 이때 운동을 N분하는데 필요한 시간의 최솟값을 구해보자. 운동하는 
시간은 연속되지 않아도 된다. 

&Input
첫째 줄에 다섯 정수 N, m, M, T, 
R이 주어진다. 

&Output
첫째 줄에 운동을 N분하는데 필요한 시간의 최솟값을 출력한다.. 
만약 운동을 N분 할 수 없다면 -1을 출력한다. 

&Example
-input
5 70 120 25 15

-output
10

-input
100 50 100 5 200

-output
109

-input
1 60 70 11 11

-output
-1

-input
200 50 200 150 1

-output
30050

-input
19 89 143 17 13

-output
40


*/

/*
#include <iostream>
using namespace std;

int N, m, M, T, R;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> m >> M >> T >> R;
	
	int cnt = 0, pulse = m;

	if (M - m < T) {
		cout << -1 << endl;
		return 0;
	}

	while (N) {
		if (M >= pulse + T) {
			N -= 1;
			pulse += T;
		}
		else if (m <= pulse - R) {
			pulse -= R;
		}
		else {
			pulse = m;
		}
		cnt += 1;
	}

	
	cout << cnt << endl;
	
	return 0;
}
*/