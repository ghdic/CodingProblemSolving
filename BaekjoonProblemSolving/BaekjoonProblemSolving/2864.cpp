/*
https://www.acmicpc.net/problem/2864

&Title
2864번 - 5와 6의 차이

&Question
상근이는 2863번에서 표를 너무 열심히 돌린 나머지 5와 
6을 헷갈리기 시작했다. 싱근이가 숫자 5를 볼 때, 5로 
볼 때도 있지만, 6으로 잘못 볼 수도 있고, 6을 
볼 때는, 6으로 볼 때도 있지만, 5로 잘못 볼 
수도 있다. 두 수 A와 B가 주어졌을 때, 상근이는 
이 두 수를 더하려고 한다. 이 때, 상근이가 구할 
수 있는 두 수의 가능한 합 중, 최소값과 최대값을 
구해 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 두 정수 A와 B가 주어진다. (1 
<= A,B <= 1,000,000) 

&Output
첫째 줄에 상근이가 구할 수 있는 두 수의 
합 중 최소값과 최대값을 출력한다. 

&Example
-input
1430 4862

-output
6282 6292


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, maxA, maxB, minA, minB;
	cin >> a >> b;
	maxA = a;
	minA = a;
	maxB = b;
	minB = b;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '5') {
			maxA[i] = '6';
		}
		else if (a[i] == '6') {
			minA[i] = '5';
		}
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '5') {
			maxB[i] = '6';
		}
		else if (b[i] == '6') {
			minB[i] = '5';
		}
	}
	
	cout << stoi(minA) + stoi(minB) << " " << stoi(maxA) + stoi(maxB) << endl;
	return 0;
}
*/