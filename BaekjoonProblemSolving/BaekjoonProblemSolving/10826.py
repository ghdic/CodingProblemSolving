/*
https://www.acmicpc.net/problem/10826

&Title
10826번 - 피보나치 수 4

&Question
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 
0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 
바로 앞 두 피보나치 수의 합이 된다.이를 식으로 써보면 
Fn = Fn-1 + Fn-2 (n>=2)가 된다.n=17일때 까지 피보나치 
수를 써보면 다음과 같다.0, 1, 1, 2, 3, 5, 
8, 13, 21, 34, 55, 89, 144, 233, 377, 
610, 987, 1597n이 주어졌을 때, n번째 피보나치 수를 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 n이 주어진다. n은 10,000보다 작거나 같은 
자연수 또는 0이다. 

&Output
첫째 줄에 n번째 피보나치 수를 출력한다. 

&Example
-input
10

-output
55


*/

N = int(input())
dp = [0 for i in range(max(N + 1, 3))];
dp[0] = 0
dp[1] = 1
for i in range(2, N + 1) :
	dp[i] = dp[i - 1] + dp[i - 2]
	print(dp[N])
#파이선 자료형 십사기요...

//c++ code
/*
//답은 맞으나
//시간 초과.. ㅠㅠ
#include <iostream>
#include <string>
using namespace std;

string sumStr(string a, string b) {
	string tmp;
	char add;
	bool raised = false;
	int aSize = a.size(), bSize = b.size();
	int size = aSize > bSize ? aSize : bSize;
	for (int i = 1; i <= size; i++) {
		
		if (i > aSize)
			add = b[bSize - i];
		else if (i > bSize)
			add = a[aSize - i];
		else 
			add = a[aSize - i] + b[bSize - i] - '0';

		if (raised == true)add += 1;
		if (add - '0' >= 10) {
			raised = true;
			add = add - 10;
			tmp = add + tmp;
		}
		else {
			raised = false;
			tmp = add + tmp;
		}
			
	}
	if (raised == true)tmp = '1' + tmp;
	return tmp;
}

int compStr(string a, string b) {
	if (a.size() > b.size())return -1;
	else if (a.size() < b.size())return 1;
	else {
		for (int i = a.size()-1; i >=0; i--) {
			if (a[i] > b[i])return -1;
			else if (a[i] < b[i])return 1;
		}
		return 0;
	}
}

long long int fibo_int(int n) {
	long long int n0 = 0, n1 = 1, n2 = 1;
	if (n == 0)return 0;
	if (n == 1)return 1;
	for (int i = 2; i <= n; i++) {
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
	}
	return n2;
}

string fibo(string n) {
	if (n.size() < 3) {
		int a = stoi(n);
		if (a <= 88)return to_string(fibo_int(a));
	}
	string n0 = to_string(fibo_int(87)), n1 = to_string(fibo_int(88)), n2;
	for (string i = "88"; compStr(i, n) != 0;i=sumStr(i, "1")) {
		n2 = sumStr(n0, n1);
		n0 = n1;
		n1 = n2;
	}
	return n2;
}
int main() {
	string N;
	cin >> N;
	cout << fibo(N) << endl;

	return 0;
}
*/