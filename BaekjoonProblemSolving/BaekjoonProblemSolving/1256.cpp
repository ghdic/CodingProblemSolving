/*
https://www.acmicpc.net/problem/1256

&Title
1256번 - 사전

&Question
동호와 규완이는 212호에서 문자열에 대해 공부하고 있다. 김진영 
조교는 동호와 규완이에게 특별 과제를 주었다. 특별 과제는 특별한 
문자열로 이루어 진 사전을 만드는 것이다. 사전에 수록되어 있는 
모든 문자열은 N개의 "a"와 M개의 "z"로 이루어져 있다. 그리고 
다른 문자는 없다. 사전에는 알파벳 순서대로 수록되어 있다.규완이는 사전을 
완성했지만, 동호는 사전을 완성하지 못했다. 동호는 자신의 과제를 끝내기 
위해서 규완이의 사전을 몰래 참조하기로 했다. 동호는 규완이가 자리를 
비운 사이에 몰래 사전을 보려고 하기 때문에, 문자열 하나만 
찾을 여유밖에 없다.N과 M이 주어졌을 때, 규완이의 사전에서 K번째 
문자열이 무엇인지 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N, M, K가 순서대로 주어진다. N과 
M은 100보다 작거나 같은 자연수이고, K는 1,000,000,000보다 작거나 같은 
자연수이다. 

&Output
첫째 줄에 규완이의 사전에서 K번째 문자열을 출력한다. 만약 
규완이의 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1을 
출력한다. 

&Example
-input
2 2 2

-output
azaz

*/

/*
n = 2 m = 1
aaz
aza
zaa

n = 1 m = 2
azz
zaz
zza

n = 2 m = 2
a|azz
a|zaz
a|zza
z|aaz
z|aza
z|zaa

n = 2 m = 2 경우의수를 생각해보면
a를 맨앞에 고정하고 n = 1 m = 2일때의 경우의수를 돌리는것과
z를 맨앞에 고정하고 n = 2 m = 1일때의 경우의수를 돌리는것과 같다.

여기서 k번째는 어캐아는가?

위 경우 절반은 a가 앞 절반은 b가 앞인 경우의 수이다.
if(dp[n][m](총개수)*n/(n+m) >= k){
  a 이다
}
else{
  z이다
  dp[n][m-1]로이동 및 k = k-dp[n][m]*n/(n+m)
}

근데 우린 이미 구한게 있었지.. dp[n-1][m]이랑 dp[n][m-1]!!
굳이 dp[n][m]*n/(n+m) 같은거 안해도된다잉
*/

/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
#define MAX 1000000000

int n, m, k;
int dp[101][101];
string s;

// 그냥 dp[n][m] = dp[n-1][m] + dp[n][m-1] 하는 함수 for두개 돌려도 무관
int func(int a, int z) {
	int& ret = dp[a][z];
	if (ret != -1)return ret;
	return ret = min(func(a - 1, z) + func(a, z - 1), MAX + 1); // 이거 n = 100 m = 100하면 int 범위 벗어남...
}

// a개, z개 있을때 cnt번째의 맨 앞의 문자를 구하며 재귀하는 함수
void getKstString(int a, int z, int cnt) {

	// 기저 조건 : a 또는 z가 0개 인 경우 경우의수는 1임
	if (a == 0) {
		for (int i = 0; i < z; ++i)
			s += 'z';
		return;
	}
	if (z == 0) {
		for (int i = 0; i < a; ++i)
			s += 'a';
		return;
	}
	int nc = func(a - 1, z); // 맨앞에 a가 올 경우
	if (cnt <= nc) {
		s += 'a';
		getKstString(a - 1, z, cnt);
	}
	else {
		s += 'z';
		getKstString(a, z - 1, cnt - nc);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= 100; ++i) {
		dp[i][0] = dp[0][i] = 1;
	}
	cin >> n >> m >> k;
	int cnt = func(n, m);
	if (cnt < k) // k가 결과보다 더 크면 -1 출력!
		cout << -1 << endl;
	else {
		getKstString(n, m, k);
		cout << s << endl;
	}
	return 0;
}
*/