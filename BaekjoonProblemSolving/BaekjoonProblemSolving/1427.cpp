/*
https://www.acmicpc.net/problem/1427

&Title
1427번 - 소트인사이드

&Question
배열을 정렬하는 것은 쉽다. 수가 주어지면, 그 수의 
각 자리수를 내림차순으로 정렬해보자. 

&Input
첫째 줄에 정렬하고자하는 수 N이 주어진다. N은 1,000,000,000보다 
작거나 같은 자연수이다. 

&Output
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다. 

&Example
-input
2143

-output
4321


*/

/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string k;
	priority_queue <int> a;

	cin >> k;
	for (int i = 0; i < k.size(); i++)
		a.push(k[i] - '0');
	for (int i = 0; i < k.size(); i++) {
		cout << a.top();
		a.pop();
	}
	cout << endl;
	return 0;
}
*/