/*
https://www.acmicpc.net/problem/1551

&Title
	1551번 - 수열의 변화

&Question
크기가 N인 수열 A가 주어졌을 때, 세준이는 인접한 
두 원소의 차이를 이용해서 크기가 N-1인 수열 B를 만들 
수 있다.예를 들어, A = {5,6,3,9,-1} 이었을 때, B 
= {6-5, 3-6, 9-3, -1-9} = {1,-3,6,-10}이 된다. 다른 
말로 B[i] = A[i+1]-A[i]가 된다.수열 A가 주어졌을 때, 세준이가 
위의 방법을 K번 했을 때 나오는 수열을 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 수열의 크기 N과 K가 주어진다. N은 
20보다 작거나 같은 자연수이고, K는 0보다 크거나 같고, N-1보다 
작거나 같은 자연수이다. 둘째 줄에는 수열이 ‘,’로 구분되어 주어진다. 


&Output
첫째 줄에 K번 변형한 수열을 ‘,’로 구분하여 출력한다. 


&Example
-input
5 1
5,6,3,9,-1

-output
1,-3,6,-10


*/

/*
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int n, k, arr[20];
string s;

void split(string input, char delimiter) {
	stringstream ss(input);
	string temp;
	int index = 0;
	while (getline(ss, temp, delimiter)) {
		arr[index++] = stoi(temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;
	split(s, ',');
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			arr[j] = arr[j + 1] - arr[j];
		}
	}

	for (int i = 0; i < n - k; i++) {
		if (i == 0)
			cout << arr[i];
		else
			cout << ',' << arr[i];
	}
	return 0;
}
*/