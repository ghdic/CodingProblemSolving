/*
���� ����
��ȣ���� �����ϴ� ��¥ ������ ������ �̹����� �ߺ� ���ڸ� �̿��� ���ο� ��ȣ�� ��������ϴ�. ���� ��� browoanoommnaon�̶�� ��ȣ���� ������ ���� ������ �ص��� �� �ֽ��ϴ�.
1. "browoanoommnaon"
2. "browoannaon"
3. "browoaaon"
4. "browoon"
5. "brown"
������ ���ڿ� cryptogram�� �Ű������� �־��� ��, �����ϴ� �ߺ� ���ڵ��� ������ ����� return �ϵ��� solution �޼��带 �ϼ����ּ���.
���ѻ���
cryptogram�� ���̰� 1 �̻� 1000 ������ ���ڿ��Դϴ�.
cryptogram�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
����� ��
cryptogram	result
browoanoommnaon	brown
zyelleyz	""
����� �� ����
����� �� #1
������ ���ÿ� �����ϴ�.

����� �� #2
������ ���� ������ �ص��� �� �ֽ��ϴ�.

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