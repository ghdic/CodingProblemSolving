/*
https://www.acmicpc.net/problem/2309

&Title
2309번 - 일곱 난쟁이스페셜 저지

&Question
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 
백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 
아닌 아홉 명이었던 것이다.아홉 명의 난쟁이는 모두 자신이 "백설 
공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 
있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 
기억해 냈다.아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 
난쟁이를 찾는 프로그램을 작성하시오. 

&Input
아홉 개의 줄에 걸쳐 일곱 난쟁이의 키가 주어진다. 
주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 
모두 다르며, 가능한 정답이 여러가지인 경우에는 아무거나 출력한다. 

&Output
일곱 난쟁이의 키를 오름차순으로 출력한다. 

&Example
-input
20
7
23
19
10
15
25
8
13

-output
7
8
10
13
19
20
23


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	sort(arr, arr + 9);

	int a = 0, b = 1;
	for (int i = 0; i < 36; i++) {
		int sum = 0;
		b++;
		if (b % 9 == 0) { 
			a++;
			b = a + 1;
		}
		for (int j = 0; j < 9; j++) {
			if (j == a || j == b)continue;
			else sum += arr[j];
		}
		if (sum == 100)break;
	}

	for (int i = 0; i < 9; i++) {
		if (i == a || i == b)continue;
		else cout << arr[i] << endl;
	}
	return 0;
}
*/