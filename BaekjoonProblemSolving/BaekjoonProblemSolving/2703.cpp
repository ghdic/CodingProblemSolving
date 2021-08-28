/*
https://www.acmicpc.net/problem/2703

&Title
	2703번 - Cryptoquote출처다국어 

&Question
Cryptoquote는 어떤 메시지가 있을 때, 각 알파벳을 다른 
알파벳으로 변환해 암호화 하는 방법이다.예를 들어, HPC PJVYMIY란 메시지가 
있을 때, 이를 원래 메시지로 바꾼다면 ACM CONTEST가 된다.위의 
예를 바꾸는 규칙은 H=A, P=C, C=M, J=O, V=N, Y=T, 
M=E, I=S이다. 이처럼 Cryptoquote를 하려면, 문자와 문자 사이의 규칙이 
있어야 한다.암호화된 메시지와 문자와 문자 사이의 규칙이 주어졌을 때, 
이를 원래 메시지로 바꾸는 프로그램을 작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T 
≤ 1000)가 주어진다. 각 테스트 케이스는 다음과 같이 두 
줄로 구성되어 있다.테스트 케이스의 첫째 줄에는 암호화된 메시지가 주어지고, 
둘째 줄에는 변환 규칙이 주어진다. 변환 규칙은 알파벳 대문자 
26글자로 이루어져있고, 암호회된 메시지의 길이는 100 이하이다.첫 번째 문자는 
A에 해당하는 문자, 두 번째는 B, ..., 26번째는 Z에 
해당하는 문자이다. 변환 규칙은 중복되지 않는다. 암호화된 메시지에는 공백이 
있을 수 있고, 이것은 원래 메시지에도 포함되어야 한다. 

&Output
각 테스트 케이스에 대해서 한 줄에 하나씩 원래 
메시지를 출력한다. 

&Example
-input
2
HPC PJVYMIY
BLMRGJIASOPZEFDCKWYHUNXQTV
FDY GAI BG UKMY
KIMHOTSQYRLCUZPAGWJNBVDXEF

-output
ACM CONTEST
THE SKY IS BLUE


*/

/*
#include <iostream>
#include <string>
using namespace std;

int t;
string s, k;

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, s);
		getline(cin, k);
		for (int i = 0; i < s.length(); i++) {
			if(s[i] != ' ')
				s[i] = k[s[i] - 'A'];
		}
		cout << s << "\n";
	}
	return 0;
}
*/