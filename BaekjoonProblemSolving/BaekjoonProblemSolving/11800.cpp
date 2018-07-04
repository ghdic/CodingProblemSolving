/*
https://www.acmicpc.net/problem/11800

&Title
11800번 - Tawla

&Question
상근이와 창영이는 재미있는 주사위 게임을 하고 있다.게임에서 사용되는
주사위는 2개를 사용하며 1 부터 6 까지 존재하는 정육면체이다.주사위의
각 면에는 다음과 같은 고유 별칭이 부여된다.1 : "Yakk"2
: "Doh"3 : "Seh"4 : "Ghar"5 : "Bang"6 :
"Sheesh"상근이와 창영이가 주사위를 한 개씩 던졌을 때 나온 수
중 큰 수부터 별칭을 부르면 된다예를 들어 1 과
2 가 나오면 "Doh Yakk" , 3 과 5
가 나오면 " Bang Seh" , 6 과 4
가 나오면 "Sheesh Ghar "단 두 수가 같은 수가
나오는 경우에는 다음과 같은 별칭을 부여한다1 - 1 :
"Habb Yakk" 2 - 2 : "Dobara" 3 -
3 : "Dousa"4 - 4 : "Dorgy"5 - 5
: "Dabash"6 - 6 : "Dosh"어째서인지 주사위 수가 6-5
( 5-6 ) 이 나오는 경우에는 "Sheesh Bang" 은
어감이 좋지 않아서 "Sheesh Bang" 대신에 "Sheesh Beesh" 로
부르기로 하였다.두 수가 주어질 때 상근이와 창영이가 외쳐야 할
문장을 출력하시오.

&Input
첫 줄에는 전체 테스트 개수인 T 가 주어진다.
(1 ≤ T ≤ 100)그 다음줄부터는 각 테스트에 주어지는
두 수 a , b 가 주어진다. (1 ≤
a, b ≤ 6)

&Output
각 테스트마다 상근이와 창영이가 외쳐야 할 문장을 "Case
n:" ( "" 제외 ) 을 포함하여 출력하시오.

&Example
-input
3
1 2
2 3
3 4

-output
Case 1: Doh Yakk
Case 2: Seh Doh
Case 3: Ghar Seh

*/

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//	int N;
//	string s[13] = { "Yakk", "Doh","Seh","Ghar","Bang","Sheesh","Habb Yakk"
//		,"Dobara","Dousa","Dorgy", "Dabash","Dosh","Sheesh Beesh" };
//	cin >> N;
//	for (int i = 1; i <= N;i++) {
//		int a, b;
//		cin >> a >> b;
//
//		cout << "Case " << i << ": ";
//		if (a == b) {
//			cout << s[a + 5] << endl;
//		}
//		else if ((a == 5 && b == 6) || (a == 6 && b == 5)) {
//			cout << s[12] << endl;
//		}
//		else {
//			cout << (a > b ? s[a - 1] : s[b - 1]) + " " + (a > b ? s[b - 1] : s[a - 1]) << endl;
//		}
//	}
//	return 0;
//}