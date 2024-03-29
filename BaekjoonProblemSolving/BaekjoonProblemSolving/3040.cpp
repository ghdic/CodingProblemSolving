/*
https://www.acmicpc.net/problem/3040

&Title
3040번 - 백설 공주와 일곱 난쟁이스페셜 저지

&Question
매일 매일 일곱 난쟁이는 광산으로 일을 하러 간다. 
난쟁이가 일을 하는 동안 백설공주는 그들을 위해 저녁 식사를 
준비한다. 백설공주는 의자 일곱개, 접시 일곱개, 나이프 일곱개를 준비한다. 
어느날 광산에서 아홉 난쟁이가 돌아왔다. (왜 그리고 어떻게 아홉 
난쟁이가 돌아왔는지는 아무도 모른다) 아홉 난쟁이는 각각 자신이 백설공주의 
일곱 난쟁이라고 우기고 있다. 백설공주는 이런 일이 생길 것을 
대비해서, 난쟁이가 쓰고 다니는 모자에 100보다 작은 양의 정수를 
적어 놓았다. 사실 백설 공주는 공주가 되기 전에 매우 
유명한 수학자였다. 따라서, 일곱 난쟁이의 모자에 써 있는 숫자의 
합이 100이 되도록 적어 놓았다. 아홉 난쟁이의 모자에 써 
있는 수가 주어졌을 때, 일곱 난쟁이를 찾는 프로그램을 작성하시오. 
(아홉 개의 수 중 합이 100이 되는 일곱 개의 
수를 찾으시오) 

&Input
총 아홉개 줄에 1보다 크거나 같고 99보다 작거나 
같은 자연수가 주어진다. 모든 숫자는 서로 다르다. 또, 항상 
답이 유일한 경우만 입력으로 주어진다. 

&Output
일곱 난쟁이가 쓴 모자에 써 있는 수를 한 
줄에 하나씩 출력한다. 

&Example
-input
7
8
10
13
15
19
20
23
25

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