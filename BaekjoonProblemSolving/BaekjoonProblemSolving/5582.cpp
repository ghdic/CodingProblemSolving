/*
https://www.acmicpc.net/problem/5582

&Title
5582번 - 공통 부분 문자열

&Question
두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 
가장 긴 공통 부분 문자열을 찾는 프로그램을 작성하시오.어떤 문자열 
s의 부분 문자열 t란, s에 t가 연속으로 나타나는 것을 
말한다. 예를 들어, 문자열 ABRACADABRA의 부분 문자열은 ABRA, RAC, 
D, ACADABRA, ABRACADABRA, 빈 문자열 등이다. 하지만, ABRC, RAA, 
BA, K는 부분 문자열이 아니다.두 문자열 ABRACADABRA와 ECADADABRBCRDARA의 공통 
부분 문자열은 CA, CADA, ADABR, 빈 문자열 등이 있다. 
이 중에서 가장 긴 공통 부분 문자열은 ADABR이며, 길이는 
5이다. 또, 두 문자열이 UPWJCIRUCAXIIRGL와 SBQNYBSBZDFNEV인 경우에는 가장 긴 
공통 부분 문자열은 빈 문자열이다. 

&Input
첫째 줄과 둘째 줄에 문자열이 주어진다. 문자열은 대문자로 
구성되어 있으며, 길이는 1 이상 4000 이하이다. 

&Output
첫째 줄에 두 문자열에 모두 포함 된 부분 
문자열 중 가장 긴 것의 길이를 출력한다. 

&Example
-input
ABRACADABRA
ECADADABRBCRDARA

-output
5


*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	s1 = "0" + s1;
	s2 = "0" + s2;

	int len1 = s1.length(), len2 = s2.length(), LCS_len = 0;
	vector<vector<int>> table(len2 + 1, vector<int>(len1 + 1, 0));
	for (int i = 1; i < len2; ++i) {
		for (int j = 1; j < len1; ++j) {
			if (s2[i] == s1[j]) {
				table[i][j] = table[i - 1][j - 1] + 1;
				LCS_len = LCS_len < table[i][j] ? table[i][j] : LCS_len;
			}
		}
		
	}


	cout << LCS_len << endl;
	return 0;
}
*/