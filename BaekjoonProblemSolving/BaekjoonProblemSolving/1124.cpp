/*
https://www.acmicpc.net/problem/1124

&Title
1124번 - 언더프라임

&Question
자연수 X를 소인수 분해 하면, 곱해서 X가 되는 
소수의 리스트가 나온다. 12는 2*2*3이고, 1은 소수가 아니다. 이때, 
X가 언더프라임이기 위한 조건은 소인수 분해 했을 때, 나오는 
소수의 개수가 소수일 때이다. 예를 들어, 12는 언더프라임이다. 그 
이유는 나오는 소수의 개수가 3개이기 때문이다. A와 B가 주어졌을 
때, A보다 크거나 같고, B보다 작거나 같은 언더프라임의 개수를 
출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 A와 B가 주어진다. A는 B보다 작거나 
같고, A와 B는 100,000보다 작거나 같고, 2보다 크거나 같은 
자연수이다. 

&Output
첫째 줄에 문제의 정답을 출력한다. 

&Example
-input
2 10
-output
5

*/

/*
#include <iostream>
#include <vector>
using namespace std;

int a, b, arr[100001] = {};
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= 100000; ++i) {
		if (arr[i])continue;
		v.push_back(i);
		for (int j = i + i; j <= 100000; j += i) {
			arr[j] = 1;
		}
	}
	int res = 0;
	for (int i = a; i <= b; ++i) {
		int num = i;
		int pos = 0, cnt = 0;
		while (num != 1) {
			if (num % v[pos] == 0) {
				num /= v[pos];
				++cnt;
			}
			else {
				++pos;
			}
		}
		if (arr[cnt] == 0)
			++res;
	}
	cout << res << endl;
	return 0;
}
*/

/*
// 머냐? 모르겠따
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int A, B;
	scanf("%d %d", &A, &B);
	vector<bool> isNprime(B+1);
	isNprime[0] = true;
	isNprime[1] = true;
	vector<unsigned char> pCount(B+1);
	int answ = 0;
	for(int i=2; i<=B; ++i) {
		if(isNprime[i]) continue;
		if(i>=sqrt(B)) {
			for(; i<=B; ++i) {
				if(!isNprime[i]) {
					for(int k=i; k<=B; k+=i) ++pCount[k];
				}
			}
			break;
		}
		for(int j=i*i; j<=B; j+=i) {
			isNprime[j] = true;
		}
		for(int c=1, j=i; j<=B; ++c, j*=i) {
			for(int n=1; n<i; ++n) {
				for(int k=n*j; k<=B; k+=j*i) pCount[k] += c;
			}
		}
	}
	for(int i=A; i<=B; ++i) {
		if(!isNprime[pCount[i]]) ++answ;
	}
	printf("%d", answ);
	return 0;
}

*/