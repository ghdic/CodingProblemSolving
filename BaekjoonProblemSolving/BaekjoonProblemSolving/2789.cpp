/*
https://www.acmicpc.net/problem/2789

&Title
2789번 - 유학 금지

&Question
아주 멀리 떨어져 있는 작은 나라가 있다. 이 
나라에서 가장 공부를 잘하는 학생들은 모두 다른 나라로 유학을 
간다. 정부는 최고의 학생들이 자꾸 유학을 가는 이유를 찾으려고 
했다. 하지만, 학생들의 이유가 모두 달랐기 때문에 정확한 이유를 
찾을 수 없었다. 정부의 고위직은 뛰어난 학생들이 자꾸 유학을 
가는 현상을 매우 불쾌해 했다. 가장 많은 학생들이 유학을 
가는 대학교는 영국의 캠브리지 대학교이다. 정부는 인터넷 검열을 통해서 
해외로 나가는 이메일의 내용 중 일부를 삭제하기로 했다. 이메일의 
각 단어 중에서 CAMBRIDGE에 포함된 알파벳은 모두 지우기로 했다. 
즉, 어떤 이메일에 LOVA란 단어가 있다면, A는 CAMBRIDGE에 포함된 
알파벳이기 때문에, 받아보는 사람은 LOV로 받는다. 이렇게, 어떤 단어가 
주어졌을 때, 검열을 거친 후에는 어떤 단어가 되는지 구하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 이 
단어는 적어도 3글자이며, 많아야 100글자이다. 

&Output
입력으로 주어진 단어를 정부가 검열을 하면 어떻게 변하는지를 
출력한다. 즉, 단어에서 CAMBRIDGE에 포함된 알파벳을 모두 지운 뒤 
출력한다. 항상 정답의 길이는 0보다 크다. 

&Example
-input
LOVA

-output
LOV


*/

/*
#include <iostream>
#include <string>
using namespace std;
string a, b = "CAMBRIDGE";
int main() {
	cin >> a;
	for (int i = 0; i<a.size(); i++)
		for (int j = 0; j<b.size(); j++)
			if (a[i] == b[j]) { a[i] = 0; }
	for (int i = 0; i < a.size(); i++)
		if (a[i] != 0)cout << a[i];
}

*/