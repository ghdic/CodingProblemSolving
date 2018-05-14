/*
https://www.acmicpc.net/problem/11091

&Title
11091번 - 알파벳 전부 쓰기

&Question
팬그램은 26개의 알파벳, a~z를 최소 한번씩 모두 사용한 
문장을 말한다. 아마 가장 유명한 문장은 이것일 것이다. "The 
quick brown fox jumps over the lazy dog."꿍은 다른 
문장들중에 팬그램인 것은 없는지 궁금해졌다. 그래서 여러분이 할 일은 
꿍을 위해 어떠한 문장이 팬그램인지 아닌지를 판별해주는 프로그램을 짜는 
것이다.팬그램에서는 알파벳의 대소문자를 구분하지 않는다고 하자. 

&Input
입력의 첫번째 줄은 1 ≤ N ≤ 50의 
N이 주어진다.다음 N개의 줄은 각각 한 문장이 주어지는데, 알파벳의 
대소문자, 공백, 숫자, 그리고 분장부호들(. , ? ! ' 
")이 포함될 수 있다.각 문장은 최소 한개의 문자를 포함하며 
100개를 넘지는 않는다. 

&Output
각 입력에 대해, 팬그램에 해당하면 "pangram"을 출력한다.만약 팬그램이 
아닐 경우, "missing"을 출력한 후 한칸 띄고 문장에 나타나지 
않은 문자들을 모두 출력한다. 이 때, 나타나지 않은 문자들은 
모두 소문자로 출력하며 알파벳 순서대로 정렬된상태로 출력해야 한다. 

&Example
-input
3
The quick brown fox jumps over the lazy dog.
ZYXW, vu TSR Ponm lkj ihgfd CBA.
.,?!'" 92384 abcde FGHIJ

-output
pangram
missing eq
missing klmnopqrstuvwxyz


*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int N;
	string s;
	cin >> N;
	cin.ignore();
	for(int z=0;z<N;z++){
		bool c[26] = {};
		getline(cin, s);
		for (int i = 0; i < s.size(); i++) {
			if (isupper(s[i]))
				s[i] = tolower(s[i]);
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i]>='a' && s[i]<='z')
				c[s[i] - 'a'] = true;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (c[i] == true)
				cnt++;
		}

		if (cnt == 26)
			cout << "pangram" << endl;
		else {
			cout << "missing ";
			for (int i = 0; i < 26; i++)
				if (c[i] == false)
					cout << (char)(i+'a');
			cout << endl;
		}
	}
	return 0;
}
*/