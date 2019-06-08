/*
https://www.acmicpc.net/problem/15655

&Title
15655번 - N과 M (6)

&Question
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 
만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오. N개의 
자연수는 모두 다른 수이다.N개의 자연수 중에서 M개를 고른 수열고른 
수열은 오름차순이어야 한다. 

&Input
첫째 줄에 N과 M이 주어진다. (1 ≤ M 
≤ N ≤ 8)둘째 줄에 N개의 수가 주어진다. 입력으로 
주어지는 수는 10,000보다 작거나 같은 자연수이다. 

&Output
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 
구분해서 출력해야 한다.수열은 사전 순으로 증가하는 순서로 출력해야 한다. 


&Example
-input
3 1
4 5 2

-output
2
4
5

-input
4 2
9 8 7 1

-output
1 7
1 8
1 9
7 8
7 9
8 9

-input
4 4
1231 1232 1233 1234

-output
1231 1232 1233 1234


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[9] = {};
vector<int> nums;
int N, M;
int number[9] = {};

void sequence(int pos) {
	if (nums.size() == M) {
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = pos + 1; i <= N; i++) {
		if (!check[i]) {
			check[i] = true;
			nums.push_back(number[i]);
			sequence(i);
			check[i] = false;
			nums.pop_back();
		}
	}

}
int main() {

	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> number[i];
	sort(number + 1, number + N + 1);
	sequence(0);
	return 0;
}
*/