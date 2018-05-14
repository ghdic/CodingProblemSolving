/*
https://www.acmicpc.net/problem/1076

&Title
1076번 - 저항

&Question
전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 
그 저항이 몇 옴인지 나타낸다.처음 색 2개는 저항의 값이고, 
마지막 색은 곱해야 하는 값이다.저항의 값은 다음 표를 이용해서 
구한다.색값곱black01brown110red2100orange31000yellow410000green5100000blue61000000violet710000000grey8100000000white91000000000예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 
4,700이 된다. 

&Input
첫째 줄에 첫번째 색, 둘째 줄에 두번째 색, 
셋째 줄에 세번째 색이 주어진다. 색은 모두 위의 표에 
써 있는 색만 주어진다. 

&Output
첫째 줄에 입력을 주어진 저항의 저항값을 출력한다. 

&Example
-input
yellow
violet
red
-output
4700

*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	long long N = 0;
	const string s[10] = { "black", "brown", "red", "orange", "yellow", "green",
					"blue", "violet", "grey", "white" };
	
	for (int i = 0; i < 3; i++) {
		string k;
		cin >> k;
		for (int j = 0; j < 10; j++) {
			if (k == s[j]) {
				if (i == 0)
					N = j;
				else if (i == 1)
					N = N * 10 + j;
				else if(i==2)
					N *= pow(10, j);
				break;
			}
		}
	}
	cout << N << endl;
	return 0;
}
*/