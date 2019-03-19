/*
문제 설명
암호문을 좋아하는 괴짜 개발자 브라운이 이번에는 중복 문자를 이용한 새로운 암호를 만들었습니다. 예를 들어 browoanoommnaon이라는 암호문은 다음과 같은 순서로 해독할 수 있습니다.
1. "browoanoommnaon"
2. "browoannaon"
3. "browoaaon"
4. "browoon"
5. "brown"
임의의 문자열 cryptogram이 매개변수로 주어질 때, 연속하는 중복 문자들을 삭제한 결과를 return 하도록 solution 메서드를 완성해주세요.
제한사항
cryptogram은 길이가 1 이상 1000 이하인 문자열입니다.
cryptogram은 알파벳 소문자로만 이루어져 있습니다.
입출력 예
cryptogram	result
browoanoommnaon	brown
zyelleyz	""
입출력 예 설명
입출력 예 #1
문제의 예시와 같습니다.

입출력 예 #2
다음과 같은 순서로 해독할 수 있습니다.

1. "zyelleyz"
2. "zyeeyz"
3. "zyyz"
4. "zz"
5. ""
*/

/*
#include <iostream>

#include <string>
#include <vector>

using namespace std;

string solution(string cryptogram) {
	string answer = "", temp = cryptogram;
	bool check = true;
	while (check) {
		check = false;
		for (int i = 0; i < temp.length()-1; i++) {
			if (temp[i] == temp[i + 1]) {
				temp = temp.substr(0, i) + temp.substr(i + 2, temp.length());
				check = true;
				if (temp == "")
					check = false;
				break;
			}

		}
	}
	answer = temp;
	return answer;
}

int main() {
	string s = "zyelleyz";
	cout << solution(s) << endl;
	return 0;
}
*/