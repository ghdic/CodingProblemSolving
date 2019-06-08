/*
https://www.acmicpc.net/problem/15651

&Title
15651번 - N과 M (3)

&Question
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 
길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.1부터 N까지 자연수 
중에서 M개를 고른 수열같은 수를 여러 번 골라도 된다. 


&Input
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ 
M ≤ N ≤ 7) 

&Output
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 
구분해서 출력해야 한다.수열은 사전 순으로 증가하는 순서로 출력해야 한다. 


&Example
-input
3 1

-output
1
2
3

-input
4 2

-output
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4
3 1
3 2
3 3
3 4
4 1
4 2
4 3
4 4

-input
3 3

-output
1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
1 3 1
1 3 2
1 3 3
2 1 1
2 1 2
2 1 3
2 2 1
2 2 2
2 2 3
2 3 1
2 3 2
2 3 3
3 1 1
3 1 2
3 1 3
3 2 1
3 2 2
3 2 3
3 3 1
3 3 2
3 3 3


*/

/*
#include <iostream>
#include <vector>
using namespace std;


vector<int> nums;
int N, M;

void sequence() {
	if (nums.size() == M) {
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		nums.push_back(i);
		sequence();
		nums.pop_back();
	}


}
int main() {

	ios::sync_with_stdio(false);
	cin >> N >> M;
	sequence();
	return 0;
}
*/