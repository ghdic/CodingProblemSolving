/*
https://www.acmicpc.net/problem/2011

&Title
2011번 - 암호코드원문과 다름 

&Question
상근이와 선영이가 다른 사람들이 남매간의 대화를 듣는 것을 
방지하기 위해서 대화를 서로 암호화 하기로 했다. 그래서 다음과 
같은 대화를 했다.상근: 그냥 간단히 암호화 하자. A를 1이라고 
하고, B는 2로, 그리고 Z는 26으로 하는거야.선영: 그럼 안돼. 
만약, "BEAN"을 암호화하면 25114가 나오는데, 이걸 다시 글자로 바꾸는 
방법은 여러 가지가 있어.상근: 그렇네. 25114를 다시 영어로 바꾸면, 
"BEAAD", "YAAD", "YAN", "YKD", "BEKD", "BEAN" 총 6가지가 나오는데, 
BEAN이 맞는 단어라는건 쉽게 알수 있잖아?선영: 예가 적절하지 않았네 
ㅠㅠ 만약 내가 500자리 글자를 암호화 했다고 해봐. 그 
때는 나올 수 있는 해석이 정말 많은데, 그걸 언제 
다해봐?상근: 얼마나 많은데?선영: 구해보자!어떤 암호가 주어졌을 때, 그 암호의 
해석이 몇 가지가 나올 수 있는지 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 5000자리 이하의 암호가 주어진다. 암호는 숫자로 
이루어져 있다. 

&Output
나올 수 있는 해석의 가짓수를 구하시오. 정답이 매우 
클 수 있으므로, 1000000으로 나눈 나머지를 출력한다.암호가 잘못되어 암호를 
해석할 수 없는 경우에는 0을 출력한다. 

&Example
-input
25114
-output
6

*/

/*
#include <iostream>
#include <string>
using namespace std;
const int MOD = 1000000;

string pw;
int dp[5000][2], len;

int check(int num) {
	if (num > 26)return 0;
	if (num < 10)return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> pw;
	dp[0][0] = (pw[0] == '0' ? 0 : 1);
	dp[1][1] = check((pw[0] - '0') * 10 + (pw[1] - '0'));
	dp[1][0] = (pw[1] == '0' ? 0 : dp[0][0]);
	len = pw.length();
	for (int i = 2; i < len; ++i) {
		int num1 = pw[i] == '0' ? 0 : 1;
		int num2 = check((pw[i - 1] - '0') * 10 + (pw[i] - '0'));
		if (num1)
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		if (num2)
			dp[i][1] = (dp[i - 2][0] + dp[i - 2][1]) % MOD;
	}
	cout << (dp[len - 1][0] + dp[len - 1][1]) % MOD << endl;
	return 0;
}
*/