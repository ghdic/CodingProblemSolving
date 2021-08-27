/*
https://www.acmicpc.net/problem/10974

&Title
	10974번 - 모든 순열

&Question
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 
사전순으로 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다. 


&Output
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 
출력한다. 

&Example
-input
3

-output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1


*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		v.push_back(i);

	do {
		for (auto it = v.begin(); it != v.end(); ++it)
			cout << *it << " ";
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}
*/