/*
https://www.acmicpc.net/problem/1344

&Title
1344번 - 축구스페셜 저지

&Question
홍준이는 축구 경기를 보고 있다. 그러다가 홍준이는 역시 
두 팀 중 적어도 한 팀이 골을 소수로 득점할 
확률이 궁금해 졌다. 축구 경기는 90분동안 이루어지고, 분석을 쉽게하기 
위해서 경기를 5분 간격으로 나눴다. 처음 간격은 처음 5분이고, 
두 번째 간격은 그 다음 5분, 그리고 이런식으로 나눈다. 
경기가 진행되는 동안 각 간격에서 A팀이 득점할 확률과 B팀이 
득점할 확률이 주어진다. 그리고, 각 간격에서 두 팀은 각각 
많아야 한 골을 득점할 수 있다. 경기가 끝난 후 
적어도 한 팀이 골을 소수로 득점할 확률을 구하시오. 

&Input
첫째 줄에 A팀이 득점할 확률, 둘째 줄에 B팀이 
득점할 확률이 퍼센트 단위로 주어진다. 퍼센트 단위로 주어지는 확률은 
모두 0보다 크거나 같고 100보다 작거나 같은 정수이다. 

&Output
첫째 줄에 적어도 한 팀이 골을 소수로 득점할 
확률을 출력한다. 정답과의 절대/상대 오차가 10-6이내인 경우에 정답이다. 

&Example
-input
50
50

-output
0.5265618908306351


*/

/*
#include <iostream>
#include <cstring>
using namespace std;

double dp[19][19][19]; // 라운드, a가 i점일 확률, b가 j점일 확률
double a, b;
bool isPrime[19] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0 };

double run(int round, int y, int x) {
	if (round == 18)return isPrime[y] || isPrime[x] ? 1.0 : 0.0;

	double& ret = dp[round][y][x];
	if (ret > -1.0)return ret;
	ret = 0.0;
	ret += run(round + 1, y + 1, x + 1) * a * b;
	ret += run(round + 1, y + 1, x) * a * (1 - b);
	ret += run(round + 1, y, x + 1) * (1 - a) * b;
	ret += run(round + 1, y, x) * (1 - a) * (1 - b);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	a /= 100.0;
	b /= 100.0;
	memset(dp, -1, sizeof(dp));
	cout.fixed;
	cout.precision(16);
	cout << run(0, 0, 0) << endl;
	return 0;
}
*/