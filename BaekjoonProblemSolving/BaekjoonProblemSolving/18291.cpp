/*
https://www.acmicpc.net/problem/18291

&Title
18291번 - 비요뜨의 징검다리 건너기

&Question
비요뜨는 지금 강 앞에 서 있다. 강 위에는 
징검다리가 놓여 있다.징검다리는 비요뜨가 있는 방향에서부터 반대 방향까지 차례로 
1번, 2번, ..., N번의 번호를 가지고 있다.비요뜨는 1번 징검다리 
위에 올라갔다. 그리고 아래 두 가지 규칙을 지키며 징검다리를 
건너려고 한다.1 ≤ X ≤ N 인 임의의 정수 
X에 대해, 현재 있는 징검다리의 번호를 i번이라고 할 때 
i+X번 징검다리로 뛸 수 있다.N번째 징검다리를 지나쳐선 안 되고, 
정확히 도착해야 한다비요뜨는 자신의 특기인 코딩을 살리기 위해 노트북을 
켰지만, 실수로 노트북을 강에 빠뜨리고 말았다.비요뜨를 대신해 강을 건너는 
경우의 수를 구해 주자! 

&Input
첫 번째 줄에 테스트 케이스의 수 T가 주어진다. 
(1 ≤ T ≤ 1000)각 테스트 케이스는 한 줄로 
구성되며, 징검다리의 개수를 의미하는 N이 주어진다. (1 ≤ N 
≤ 109) 

&Output
각 테스트 케이스에 대해, 한 줄에 하나씩 규칙을 
만족하면서 징검다리를 건너는 경우의 수를 109+7로 나눈 나머지를 출력한다. 


&Example
-input
1
4

-output
4


*/

/*
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
long long n;

long long calpow(long long exp) {
	if (exp == 0)
		return 1;
	long long temp = calpow(exp / 2);
	if ((exp & 1) == 0)
		return (temp * temp) % MOD;
	else
		return ((temp * temp) << 1) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1)cout << 1 << '\n';
		else cout << calpow(n-2) << '\n';
	}
	return 0;
}
*/