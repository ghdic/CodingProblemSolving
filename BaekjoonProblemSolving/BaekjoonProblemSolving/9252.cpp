/*
https://www.acmicpc.net/problem/9252

&Title
9252번 - LCS 2스페셜 저지

&Question
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 
수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 
가장 긴 것을 찾는 문제이다.예를 들어, ACAYKP와 CAPCAK의 LCS는 
ACAK가 된다. 

&Input
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 
알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다. 

&Output
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 
둘째 줄에 LCS를 출력한다.LCS가 여러 가지인 경우에는 아무거나 출력한다. 


&Example
-input
ACAYKP
CAPCAK

-output
4
ACAK


*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;

	s1 = "0" + s1;
	s2 = "0" + s2;

	int len1 = s1.length(), len2 = s2.length(), LCS_len = 0;
	vector<vector<int>> table(len2, vector<int>(len1, 0));
	for (int i = 1; i < len2; ++i) {
		int max = 0;
		for (int j = 1; j < len1; ++j) {
			if (s2[i] == s1[j]) {
				max = table[i - 1][j - 1] + 1;
				table[i][j] = max;
			}
			else {
				if (table[i][j - 1] > table[i - 1][j])
					table[i][j] = table[i][j - 1];
				else
					table[i][j] = table[i - 1][j];
			}
		}
		LCS_len = LCS_len < max ? max : LCS_len;
	}
	//LCS 추출
	int temp = LCS_len - 1, temp_j = len1 - 1;
	string LCS = "";

	for (int i = len2 - 1; i > 0; --i) {
		for (int j = temp_j; j > 0; --j) {
			if (table[i][j] == temp + 1 && table[i][j - 1] == temp && table[i - 1][j - 1] == temp && table[i - 1][j] == temp) {
				--temp;
				LCS = s2[i] + LCS;
				temp_j = j;
				break;
			}
		}
	}
	cout << LCS_len << "\n";
	cout << LCS << endl;
	return 0;
}
*/