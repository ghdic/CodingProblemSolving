/*
https://www.acmicpc.net/problem/10384

&Title
10384번 - 팬그램

&Question
팬그램은 모든 알파벳을 적어도 한 번씩을 사용한 영어 
문장을 말한다.다음은 유명한 팬그램 중 하나이다.The quick brown fox 
jumps over a lazy dog더블 팬그램은 모든 알파벳을 적어도 
두 번씩은 사용한 문장을 말하고,트리플 팬그램은 모든 알파벳을 적어도 
세 번씩은 사용한 문장을 말한다.더 이어나갈 수도 있겠지만 시간상 
여기까지만 하도록 하겠다. 

&Input
입력은 여러 줄의 테스트케이스들로 이루어진다.첫째 줄에 테스트케이스의 수 
n이 주어진다.각 테스트케이스는 영어 소문자와 대문자, 특수기호들로 이루어진다. 

&Output
각 케이스마다 한 줄에 하나씩 다음 중 하나를 
출력한다.팬그램이 아닐 경우 - Not a pangram팬그램일 경우 - 
Pangram!더블 팬그램일 경우 - Double pangram!!트리플 팬그램일 경우 - 
Triple pangram!!!트리플 팬그램일 경우에는 자연스럽게 팬그램과 더블 팬그램이 되지만, 
Triple pangram!!!만을 출력한다. 더블 팬그램도 마찬가지이다. 

&Example
-input
3
The quick brown fox jumps over a lazy dog.
The quick brown fox jumps over a laconic dog.
abcdefghijklmNOPQRSTUVWXYZ-zyxwvutsrqpon   2013/2014      MLKJIHGFEDCBA

-output
Case 1: Pangram!
Case 2: Not a pangram
Case 3: Double pangram!!


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	for(int i = 0; i < N; i++) {
		string s;
		int arr[26] = {};
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (isupper(s[j])) {
				arr[s[j] - 65]++;
			}
			else if (islower(s[j])) {
				arr[s[j] - 97]++;
			}
		}
		int j;
		for (j = 3; j > 0; j--) {
			bool check = true;
			for (int k = 0; k < 26; k++) {
				if (arr[k] < j) {
					check = false;
					break;
				}
			}
			if (check)break;
		}

		switch (j)
		{
		case 0:
			cout << "Case " << i + 1 << ": Not a pangram" << endl;
			break;
		case 1:
			cout << "Case " << i + 1 << ": Pangram!" << endl;
			break;
		case 2:
			cout << "Case " << i + 1 << ": Double pangram!!" << endl;
			break;
		case 3:
			cout << "Case " << i + 1 << ": Triple pangram!!!" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}
*/