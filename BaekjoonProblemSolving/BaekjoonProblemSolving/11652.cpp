/*
https://www.acmicpc.net/problem/11652

&Title
	11652번 - 카드

&Question
준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 
정수가 하나 적혀있는데, 적혀있는 수는 -262보다 크거나 같고, 262보다 
작거나 같다.준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 
가지고 있는 정수를 구하는 프로그램을 작성하시오. 만약, 가장 많이 
가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다. 

&Input
첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 
N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 
N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 

&Output
첫째 줄에 준규가 가장 많이 가지고 있는 정수를 
출력한다. 

&Example
-input
5
1
2
1
2
1

-output
1

-input
6
1
2
1
2
1
2

-output
1


*/

/*
#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<long long, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	long long input, key = 0;
	int res = 0;
	while (n--) {
		cin >> input;
		if (um.find(input) != um.end()) {
			um[input]++;
		}
		else {
			um[input] = 1;
		}

		if (res < um[input]) {
			res = um[input];
			key = input;
		}
		else if (res == um[input] && input < key) {
			key = input;
		}
	}
	cout << key << endl;
	return 0;
}
*/