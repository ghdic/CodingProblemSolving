/*
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWrDLM0aRA8DFARG&categoryId=AWrDLM0aRA8DFARG&categoryType=CODE

7732. 시간 개념 D3
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.

은빈이는 시간 개념이 없다.

은빈이를 보고 있자면 코리아 타임이라는 단어가 왜 생겼는지 알 수 있는 것 같다.

호석이는 은빈이를 위해 프로그램을 작성해주려고 한다.

현재 시각과 약속 시각을 알려주면 약속까지 남은 시간을 알려주는 프로그램이다.

현재 시각보다 약속 시각이 더 빠른 경우에는, 약속이 다음 날에 있는 것이다.

모든 시간은 00:00:00 ~ 23:59:59 사이로 표현되고 XX:XX:XX 형태이며, 숫자가 2자리가 아닐 경우에는 0으로 채운다.

현재 시각과 약속 시각을 받으면 남은 시간을 알려주는 프로그램을 작성해라.

[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 현재 시각이 주어지고 두 번째 줄에는 약속 시각이 주어진다. 현재 시각이 약속 시각보다 빠르다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

남은 시간을 XX:XX:XX 형태로 출력하라.

입력
3
00:00:00
23:59:59
23:59:59
00:00:00
03:29:35
15:01:52 // 테스트 케이스 개수
// 첫 번째 테스트 케이스

// 두 번째 테스트 케이스

// 세 번째 테스트 케이스
  input.txt
출력
#1 23:59:59
#2 00:00:01
#3 11:32:17 // 첫 번째 테스트 케이스 결과

// 세 번째 테스트 케이스 결과
output.txt
*/

/*
#include <iostream>
#include <string>
using namespace std;

string subtime(string& s1, string& s2) {
	string s(8, ' ');
	s[2] = s[5] = ':';
	bool down = false;
	for (int i = 7; i >= 0; i--) {
		if (i == 2 || i == 5)continue;
		int num = (s2[i] - '0') - (s1[i] - '0') - down;
		if (num >= 0) {
			down = false;
		}
		else {
			num += ((i == 1 || i == 4 || i == 7) ? 10 : 6);
			down = true;
		}
		s[i] = num + '0';
	}
	return s;
}

string full_time = "24:00:00";
int main() {
	int T;
	string s1, s2;
	bool up = false;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> s1 >> s2;
		if (s1 <= s2) {
			s1 = subtime(s1, s2);
		}
		else {
			s1 = subtime(s2, s1);
			s1 = subtime(s1, full_time);
		}

		cout << "#" << i + 1 << " " << s1 << "\n";
	}
	return 0;
}
*/