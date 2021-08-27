/*
https://www.acmicpc.net/problem/10973

&Title
	10973번 - 이전 순열

&Question
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 
바로 이전에 오는 순열을 구하는 프로그램을 작성하시오.사전 순으로 가장 
앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 
내림차순으로 이루어진 순열이다.N = 3인 경우에 사전순으로 순열을 나열하면 
다음과 같다.1, 2, 31, 3, 22, 1, 32, 3, 
13, 1, 23, 2, 1 

&Input
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄에 순열이 주어진다. 

&Output
첫째 줄에 입력으로 주어진 순열의 이전에 오는 순열을 
출력한다. 만약, 사전순으로 가장 처음에 오는 순열인 경우에는 -1을 
출력한다. 

&Example
-input
4
1 2 3 4

-output
-1

-input
5
5 4 3 2 1

-output
5 4 3 1 2


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	bool check = prev_permutation(v.begin(), v.end());

	if (!check) {
		cout << -1 << endl;
	}
	else {
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
	}
	return 0;
}
*/