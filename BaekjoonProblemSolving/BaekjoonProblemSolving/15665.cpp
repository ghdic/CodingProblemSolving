/*
https://www.acmicpc.net/problem/15665

&Title
15665번 - N과 M (11)

&Question
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 
만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.N개의 자연수 
중에서 M개를 고른 수열같은 수를 여러 번 골라도 된다. 


&Input
첫째 줄에 N과 M이 주어진다. (1 ≤ M 
≤ N ≤ 7)둘째 줄에 N개의 수가 주어진다. 입력으로 
주어지는 수는 10,000보다 작거나 같은 자연수이다. 

&Output
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 
구분해서 출력해야 한다.수열은 사전 순으로 증가하는 순서로 출력해야 한다. 


&Example
-input
3 1
4 4 2

-output
2
4

-input
4 2
9 7 9 1

-output
1 1
1 7
1 9
7 1
7 7
7 9
9 1
9 7
9 9

-input
4 4
1 1 2 2

-output
1 1 1 1
1 1 1 2
1 1 2 1
1 1 2 2
1 2 1 1
1 2 1 2
1 2 2 1
1 2 2 2
2 1 1 1
2 1 1 2
2 1 2 1
2 1 2 2
2 2 1 1
2 2 1 2
2 2 2 1
2 2 2 2


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nums;
int N, M;
int number[9] = {};

void sequence() {
	if (nums.size() == M) {
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (number[i] != number[i - 1]) {
			nums.push_back(number[i]);
			sequence();
			nums.pop_back();
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> number[i];
	number[0] = -1;
	sort(number + 1, number + N + 1);
	sequence();
	return 0;
}
*/