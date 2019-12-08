/*
https://www.acmicpc.net/problem/2023

&Title
2023번 - 신기한 소수

&Question
수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 
가지고 노는 것이다. 요즘 수빈이가 가장 관심있어 하는 소수 
7331이다.7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 
즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 
수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.수빈이는 N자리의 숫자 
중에서 어떤 수들이 신기한 소수인지 궁금해졌다. N이 주어졌을 때, 
수빈이를 위해 N자리 신기한 소수를 모두 찾아보자. 

&Input
첫재 줄에 N(1 ≤ N ≤ 8)이 주어진다. 


&Output
N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 
줄에 하나씩 출력한다. 

&Example
-input
4

-output
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393


*/

/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;

bool isPrime(int num) {
	if (num < 2)return false;

	int sq = sqrt(num);
	for (int i = 2; i <= sq; ++i)
		if (num % i == 0)
			return false;
	return true;
}

void dfs(int num, int depth) {
	if (n == depth) {
		cout << num << '\n';
		return;
	}

	for (int i = 1; i <= 9; ++i) {
		int val = 10 * num + i;
		if (isPrime(val)) {
			dfs(val, depth + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	dfs(0, 0);
	return 0;
}
*/