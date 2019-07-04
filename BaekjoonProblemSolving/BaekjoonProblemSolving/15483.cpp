/*
https://www.acmicpc.net/problem/15483

&Title
15483번 - 최소 편집

&Question
두 문자열 A와 B가 주어졌을 때, A에 연산을 
최소 횟수로 수행해 B로 만드는 문제를 "최소 편집" 문제라고 
한다.A에 적용할 수 있는 연산은 총 3가지가 있으며 아래와 
같다.삽입: A의 한 위치에 문자 하나를 삽입한다.삭제: A의 문자 
하나를 삭제한다.교체: A의 문자 하나를 다른 문자로 교체한다.두 문자열이 
주어졌을 때, 최소 편집 횟수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 
알파벳 소문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다. 

&Output
첫째 줄에 최소 편집 횟수를 출력한다. 

&Example
-input
abc
ab

-output
1

-input
ca
abc

-output
3

-input
abc
cba

-output
2

-input
abcd
bcde

-output
2

-input
abababababa
aaaaaaaaaaa

-output
5

-input
for
whileforif

-output
7

-input
whilewhile
whalewhale

-output
2

-input
aaabaaa
acacaca

-output
3

-input
qwerty
dvorak

-output
5

-input
asdf
asdf

-output
0


*/

/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int LD[1001][1001] = {};
int main() {
	string A, B;
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> A >> B;
	int Alen = A.length(), Blen = B.length();
	// 처음 공집합과 비교하여 바꿔야하는건 대상 문자열 길이만큼 비용이 필요함!
	for (int i = 0; i <= A.length(); ++i)LD[i][0] = i;
	for (int i = 1; i <= B.length(); ++i)LD[0][i] = i;
	
	// 비교한 문자가 같으면 D(i, j) = D(i-1, j-1);
	// 비교한 문자가 다를 경우 이전편집거리 중 최소값에 코스트 1증가
	for (int j = 1; j <= Blen; ++j) {
		for (int i = 1; i <= Alen; ++i) {
			if (A[i - 1] == B[j - 1]) LD[i][j] = LD[i - 1][j - 1]; // A, B에 가상의 공집합이 있다 가정하여 A[i-1] == B[i-1] 비교
			else LD[i][j] = min(LD[i - 1][j - 1] + 1, min(LD[i][j - 1] + 1, LD[i - 1][j] + 1));
			// LD[i-1][j-1] + 1 == 수정, LD[i-1][j] + 1 == 삭제, LD[i][j-1] + 1 == 추가
		}
	}
	cout << LD[Alen][Blen] << endl;
	return 0;
}
*/

/*
편집거리 알고리즘 (Leavenshtein Distance)
두 문자열의 유사도를 판단하는 알고리즘
어떠한 문자열 삽입, 삭제, 변경을 몇번해서 바꿀수 있는지 최소값을 구함
LCS와 비슷함
*/