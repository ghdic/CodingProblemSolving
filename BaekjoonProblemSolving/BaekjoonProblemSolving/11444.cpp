/*
https://www.acmicpc.net/problem/11444

&Title
11444번 - 피보나치 수 6

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
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 
자연수이다. 

&Output
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 
출력한다. 

&Example
-input
1000

-output
517691607


*/

/*
//메모라이제이션을 활용한 fibo
#include <iostream>
#include <map>
using namespace std;
map<long long, long long> d;
const long long mod = 1000000007LL;
long long fibo(long long n) {
	if (n <= 1) {
		return n;
	}
	else if (n == 2) {
		return 1;
	}
	else if (d.count(n) > 0) {
		return d[n];
	}
	else {
		if (n % 2 == 1) {
			long long m = (n + 1) / 2;
			long long t1 = fibo(m);
			long long t2 = fibo(m - 1);
			d[n] = t1 * t1 + t2 * t2;
			d[n] %= mod;
			return d[n];
		}
		else {
			long long m = n / 2;
			long long t1 = fibo(m - 1);
			long long t2 = fibo(m);
			d[n] = (2LL * t1 + t2)*t2;
			d[n] %= mod;
			return d[n];
		}
	}
}

int main() {
	long long n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}
*/

//행렬의 거듭제곱을 이용한 풀이
/*
#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;

//정사각 행렬 연산
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
				//(i\j)=(i\k)*(k\j)
			c[i][j] %= mod;
		}
		
	}
	return c;
}

int main() {
	long long n;
	cin >> n;
	if (n <= 1) {
		cout << n << endl;
		return 0;
	}

	matrix ans = { {1, 0}, {0,1} };
	matrix a = { {1,1}, {1,0} };

	//제곱연산시 거듭제곱을 통해 연산하면 더 빠르다.
	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1] << endl;
	return 0;
}
*/