/*
https://www.acmicpc.net/problem/1562

&Title
1562번 - 계단 수

&Question
45656이란 수를 보자.이 수는 인접한 모든 자리수의 차이가 
1이 난다. 이런 수를 계단 수라고 한다.그럼, 오늘도 역시 
세준이는 0부터 9까지 모든 한 자리수가 자리수로 등장하면서, 수의 
길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.N이 주어질 
때, 길이가 N이면서 0에서 9가 모두 등장하는 계단 수가 
총 몇 개 있는 지 구하는 프로그램을 작성하시오. (0으로 
시작하는 수는 없다.) 

&Input
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 
100보다 작거나 같은 자연수이다. 

&Output
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다. 

&Example
-input
10

-output
1


*/

/*
#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000000
#define MAX 101
#define ALL (1 << 10) -1
int n;
int cache[10][MAX][1 << 10];

int stairNum(int start, int length, int number) {
	// 기저 사례 : 목표 길이 도달
	// 0~9 모두 등장했으면 추가
	if (length == n)
		return number == ALL ? 1 : 0;

	int& res = cache[start][length][number];
	if (res != -1)return res;

	res = 0;
	// 계단 수 하나 차이
	if (start - 1 >= 0)
		res += stairNum(start - 1, length + 1, number | 1 << (start - 1));
	if (start + 1 < 10)
		res += stairNum(start + 1, length + 1, number | 1 << (start + 1));
	res %= MOD;

	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int res = 0;
	for (int i = 1; i < 10; ++i) {
		memset(cache, -1, sizeof(cache));
		res += stairNum(i, 1, 1 << i);
		res %= MOD;
	}
	cout << res << endl;
	return 0;
}
*/