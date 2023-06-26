/*
문제 설명
성공한 덕후로서 연예 기획사에 입사를 하게 된 배달이는 첫 프로젝트로 콘서트 티켓팅을 진행하게 되었습니다. 기존에는 팬으로서 참여했던 티켓팅을 운영자로서 참여하게 되어서 감회가 새로운 배달이었지만 한편으로 팬들의 마음을 누구보다도 잘 알았기 때문에 그들의 힘듦을 최소화해주고 싶다는 책임감에 잠 못 이루었습니다. 결국 티켓팅 시뮬레이션을 통해 적절한 솔루션을 찾기 위해 테스트 시뮬레이션을 만들기로 하였습니다.

총 티켓 수 totalTicket과 접속/취소 로그 배열 logs가 주어질 때, 아래의 시뮬레이션 설명을 참고하여 티켓팅에 성공한 유저의 아이디 목록을 추출하여 return 하도록 solution 메서드를 완성해주세요.

시뮬레이션 설명
접속 시도를 하면 request 로그가 남고 접속 후 1분 이내 접속을 종료하면 leave 로그가 남는다. (09:00:00에 request 후 09:00:59에 leave 시 구매 실패, 09:00:00에 request 후 09:01:00에 leave 시 구매 성공)
이미 한 유저가 접속한 상태라면 다른 유저들은 접속을 할 수 없으며 다시 접속을 시도해야 한다.
티켓을 구매하기 위해서는 서버 접속 후 1분을 유지해야 한다.
티켓 구매를 성공한 유저는 접속은 가능하지만 다시 구매는 할 수 없다.
KakaoTalk_Image_2019-03-15-09-37-55.png

case 1
09:12:29에 request 한 woni는 1분 동안 접속을 유지하여 티켓 구매에 성공함.
case 2
09:23:11에 request 한 brown은 1분 동안 접속을 유지하지 못하고 09:23:44초에 접속을 종료하여 leave 로그가 남으며 티켓 구매에 실패함.
case 3
jason과 jun과 cu가 접속을 시도하였지만 가장 빨리 접속 시도를 한 jason이 접속을 하였고 그 이후로 접속 시도한 jun과 cu는 접속을 실패함.
구매 성공
구매 중인 유저가 없을 때 request 하여 1분 동안 접속 유지(leave 로그가 없음)
구매 실패
접속 후 1분을 유지하지 못한 경우(leave 로그 있음)
다른 유저가 접속한 상태에서 request 한 경우
제한사항
티켓팅 시간은 9시부터 10시이다. (10시 0분 0초에 서버가 종료된다)
같은 시간(시분초)의 로그는 발생하지 않습니다.
로그는 request 유형과 leave 유형만 존재합니다.
총 티켓 수는 0부터 10,000까지 정수입니다.
id는 소문자 알파벳만 가능합니다.
id는 오름차순으로 정렬해 return 해주세요.
입력
총 티켓 수
접속 시도/취소 로그 배열 (id, action[request/leave], 시분초 hh:mm:ss)
input sample
totalTicket = 2000
logs = [
	"woni request 09:12:29",
	"brown request 09:23:11",
	"brown leave 09:23:44",
	"jason request 09:33:51",
	"jun request 09:33:56",
	"cu request 09:34:02"
]
출력
티켓팅 성공한 id 배열

output sample
[
	"jason",
	"woni"
]
*/

/*
#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

vector<string> solution(int totalTicket, vector<string> logs) {
	vector<string> answer;
	string temp_name, temp_date;
	bool exist = false;
	for (int i = 0; i < logs.size(); i++) {
		vector<string> s = split(logs[i], ' ');
		string name = s[0];
		string act = s[1];
		string date = s[2];
		if (date < "09:00:00")continue;
		if (temp_date <= date && temp_date<="10:00:00" && exist) {
			answer.push_back(temp_name);
			exist = false;
		}
		if (!exist && act == "request") {
			temp_name = name;
			temp_date = date;
			//1분 더해줌
			if (temp_date[4] == '9') {
				temp_date[4] = 0;
				if (temp_date[3] == '5') {
					temp_date[3] = 0;
					if (temp_date[1] == '9') {
						temp_date[1] = '0';
						temp_date[0] = '1';
					}
					else {
						temp_date[1] = temp_date[1] + 1;
					}
				}
				else {
					temp_date[3] = temp_date[3] + 1;
				}
			}
			else {
				temp_date[4] = temp_date[4] + 1;
			}
			exist = true;
		}
		
		if (act == "leave") {
			if (name == temp_name) {
				if (date < temp_date) {
					exist = false;
				}
			}
		}
	}
	
	if(temp_date <= "10:00:00" && exist)
		answer.push_back(temp_name);
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	int totalTicket = 2000;
	vector<string> logs = {
			"woni request 09:12:29",
				"brown request 09:23:11",
				"brown leave 09:23:44",
				"jason request 09:33:51",
				"jun request 09:33:56",
				"cu request 09:34:02"
	};
	vector<string> s = solution(totalTicket, logs);
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << endl;

	return 0;
}
*/