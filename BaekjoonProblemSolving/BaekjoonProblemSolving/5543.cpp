/*
https://www.acmicpc.net/problem/5543

&Title
상근날드
&Question
상근날드에서 가장 잘 팔리는 메뉴는 세트 메뉴이다. 주문할 때, 자신이 원하는 햄버거와 음료를 하나씩 골라, 세트로 구매하면, 가격의 합계에서 50원을 뺀 가격이 세트 메뉴의 가격이 된다.

햄버거는 총 3종류 상덕버거, 중덕버거, 하덕버거가 있고, 음료는 콜라와 사이다 두 종류가 있다.

햄버거와 음료의 가격이 주어졌을 때, 가장 싼 세트 메뉴의 가격을 출력하는 프로그램을 작성하시오
&Input
입력은 총 다섯 줄이다. 첫째 줄에는 상덕버거, 둘째 줄에는 중덕버거 셋째 줄에는 하덕버거의 가격이 주어진다. 넷째 줄에는 콜라의 가격, 다섯째 줄에는 사이다의 가격이 주어진다. 모든 가격은 100원 이상, 2000원 이하이다.
&Output
첫째 줄에 가장 싼 세트 메뉴의 가격을 출력한다.
&Example
-input
800
700
900
198
330
-output
848
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[3], b[2];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	sort(a, a + 3);
	for (int i = 0; i < 2; i++)
		cin >> b[i];
	sort(b, b + 2);
	cout << a[0] + b[0] - 50 << endl;
	return 0;
}
*/