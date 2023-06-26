/*
���� ����
������ ���ķμ� ���� ��ȹ�翡 �Ի縦 �ϰ� �� ����̴� ù ������Ʈ�� �ܼ�Ʈ Ƽ������ �����ϰ� �Ǿ����ϴ�. �������� �����μ� �����ߴ� Ƽ������ ��ڷμ� �����ϰ� �Ǿ ��ȸ�� ���ο� ����̾����� �������� �ҵ��� ������ �������ٵ� �� �˾ұ� ������ �׵��� ������ �ּ�ȭ���ְ� �ʹٴ� å�Ӱ��� �� �� �̷�����ϴ�. �ᱹ Ƽ���� �ùķ��̼��� ���� ������ �ַ���� ã�� ���� �׽�Ʈ �ùķ��̼��� ������ �Ͽ����ϴ�.

�� Ƽ�� �� totalTicket�� ����/��� �α� �迭 logs�� �־��� ��, �Ʒ��� �ùķ��̼� ������ �����Ͽ� Ƽ���ÿ� ������ ������ ���̵� ����� �����Ͽ� return �ϵ��� solution �޼��带 �ϼ����ּ���.

�ùķ��̼� ����
���� �õ��� �ϸ� request �αװ� ���� ���� �� 1�� �̳� ������ �����ϸ� leave �αװ� ���´�. (09:00:00�� request �� 09:00:59�� leave �� ���� ����, 09:00:00�� request �� 09:01:00�� leave �� ���� ����)
�̹� �� ������ ������ ���¶�� �ٸ� �������� ������ �� �� ������ �ٽ� ������ �õ��ؾ� �Ѵ�.
Ƽ���� �����ϱ� ���ؼ��� ���� ���� �� 1���� �����ؾ� �Ѵ�.
Ƽ�� ���Ÿ� ������ ������ ������ ���������� �ٽ� ���Ŵ� �� �� ����.
KakaoTalk_Image_2019-03-15-09-37-55.png

case 1
09:12:29�� request �� woni�� 1�� ���� ������ �����Ͽ� Ƽ�� ���ſ� ������.
case 2
09:23:11�� request �� brown�� 1�� ���� ������ �������� ���ϰ� 09:23:44�ʿ� ������ �����Ͽ� leave �αװ� ������ Ƽ�� ���ſ� ������.
case 3
jason�� jun�� cu�� ������ �õ��Ͽ����� ���� ���� ���� �õ��� �� jason�� ������ �Ͽ��� �� ���ķ� ���� �õ��� jun�� cu�� ������ ������.
���� ����
���� ���� ������ ���� �� request �Ͽ� 1�� ���� ���� ����(leave �αװ� ����)
���� ����
���� �� 1���� �������� ���� ���(leave �α� ����)
�ٸ� ������ ������ ���¿��� request �� ���
���ѻ���
Ƽ���� �ð��� 9�ú��� 10���̴�. (10�� 0�� 0�ʿ� ������ ����ȴ�)
���� �ð�(�ú���)�� �α״� �߻����� �ʽ��ϴ�.
�α״� request ������ leave ������ �����մϴ�.
�� Ƽ�� ���� 0���� 10,000���� �����Դϴ�.
id�� �ҹ��� ���ĺ��� �����մϴ�.
id�� ������������ ������ return ���ּ���.
�Է�
�� Ƽ�� ��
���� �õ�/��� �α� �迭 (id, action[request/leave], �ú��� hh:mm:ss)
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
���
Ƽ���� ������ id �迭

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
			//1�� ������
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