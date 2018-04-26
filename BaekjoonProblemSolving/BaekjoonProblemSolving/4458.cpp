/*
https://www.acmicpc.net/problem/4458

&Title
4458번 - 첫 글자를 대문자로

&Question
문장을 읽은 뒤, 줄의 첫 글자를 대문자로 바꾸는 
프로그램을 작성하시오. 

&Input
첫째 줄에 줄의 수 N이 주어진다. 다음 N개의 
줄에는 문장이 주어진다. 각 문장에 들어있는 글자의 수는 30을 
넘지 않는다. 모든 줄의 첫번째 글자는 알파벳이다. 

&Output
각 줄의 첫글자를 대문자로 바꾼뒤 출력한다. 

&Example
-input
5
powdered Toast Man
skeletor
Electra Woman and Dyna Girl
she-Ra Princess of Power
darth Vader

-output
Powdered Toast Man
Skeletor
Electra Woman and Dyna Girl
She-Ra Princess of Power
Darth Vader


*/

/*
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string N;
	int k;
	cin >> k;
	cin.ignore();
	for (int i = 0; i < k; i++) {
		getline(cin, N);
		N[0] = toupper(N[0]);
		cout << N << endl;
	}
	return 0;
}
*/