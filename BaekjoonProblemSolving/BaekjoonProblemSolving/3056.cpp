/*
https://www.acmicpc.net/problem/3056

&Title
3056번 - 007스페셜 저지

&Question
비밀 요원 007은 제임스 본드로 유명한 비밀 요원이다. 
최근 알려진 정보에 의하면 제임스본드는 대다수 미션을 자신이 직접 
수행하지 않는다고 한다. 본드는 미션을 자신과 비슷하게 생긴 사촌들인 
지미 본드에게 시킨다. 제임스 본드는 MI6로부터 미션을 받으면, 각 
미션을 사촌들에게 하나씩 할당해 준다.매달 초에 제임스 본드는 미션 
목록을 받게 된다. 그 다음에 그는 각각의 지미 본드에 
대해서 미션을 성공적으로 수행할 확률을 구한다. 이제, 전체 미션을 
성공할 확률이 가장 크게 되게 미션을 지미 본드에게 나누어 
주려고 한다. 어떤 미션을 어떤 지미 본드에게 나누어 주어야 
할 지를 결정한 다음, 전체 미션을 성공할 확률을 구하는 
프로그램을 작성하시오.모든 미션을 성공적으로 끝낼 확률은 각 미션을 성공적으로 
끝낼 확률을 모두 곱하면 된다. 

&Input
첫째 줄에 미션과 지미 본드의 수인 N이 주어진다. 
(1 ≤ N ≤ 20)다음 N개 줄에는 0과 100 
사이의 정수가 N개씩 주어진다. i번째 줄의 j번째 정수는 지미 
본드 i가 미션 j를 성공적으로 마칠 확률이며, 퍼센트로 주어진다. 


&Output
첫째 줄에 모든 미션을 성공적으로 마칠 확률을 퍼센트로 
출력한다. 정답과의 오차는 ±0.000001까지 허용한다. 

&Example
-input
3
25 60 100
13 0 50
12 70 90

-output
9.10000


*/

/*
일반적으로 생각하자면
모든 제임스 본드의 확률을 곱해보는
nCn = n! 풀이가 생각남

dp와 bitmask 이용시 n*2^n으로 가능
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

const double INF = 1e9;
const int MAXN = 21;
double prob[MAXN][MAXN];
int n;
double cache[(1 << MAXN)];

double solve(int i, int used) {
	if (i == n)return 1.0;
	double& ret = cache[used];
	if (ret != -1)return ret;
	ret = 0.0;
	for (int j = 0; j < n; ++j) {
		if ((used & (1 << j)) == 0) {
			used |= (1 << j);
			ret = max(ret, prob[i][j] * solve(i + 1, used));
			used &= ~(1 << j);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> prob[i][j];
			prob[i][j] /= 100.0;
		}
	for (int i = 0; i < (1 << MAXN); ++i)
		cache[i] = -1;
	double ans = solve(0, 0);
	cout.setf(ios::fixed);
	cout.precision(8);
	cout << ans * 100 << endl;
	return 0;
}
*/