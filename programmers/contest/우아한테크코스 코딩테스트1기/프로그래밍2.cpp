/*
���� ����
�� ���� ���� ���� ������ ����� �� ������ ���� ������ �о�ް��� �մϴ�. ������ 
���簢�� ���·� �о���� �� ������, x��(���� ����)�� y��(���� ����)�� 
���� ��������� 2���� ��鿡�� �� �� P1(x1, y1)�� P2(x2, y2)�� ǥ���� �� 
�ֽ��ϴ�. ���� �������� �ļ����� �����Ͽ�, �̹� �о�� ������ ��ġ�� 
������ �ļ��� �Ϻθ� ������ ������ �о�ް��� �մϴ�.

���� ������ �̹� �о�� ������ ��ġ�� ������ �ļ����� �����ϰ� �����Ƿ�
�о� �����մϴ�.

�̹� �о�� ������ ��ġ�� ���� ������ �迭 lands�� �ļ����� ��ġ�� ���� 
������ �迭 wells, �о�ް��� �ϴ� ������ ��ġ�� ���� �迭 point�� 
�Ű������� �־��� ��, �����о��� �������� �Ǻ��Ͽ� return �ϵ��� solution �޼��带 �ϼ����ּ���.

���ѻ���
lands�� wells�� ���̴� 1 �̻� 10,000 �����Դϴ�.
lands�� wells�� ����(������ �ļ����� ��ġ)�� [x1, y1, x2, y2]�� ����ֽ��ϴ�.
point�� ���̴� 4�Դϴ�.
point���� ���� [x1, y1, x2, y2]�� ����ֽ��ϴ�.
x ��ǥ�� y ��ǥ�� 0 �̻� 1,000,000 ������ �����Դϴ�.

����� ��
lands	wells	point	result
[ [10, 0, 30, 5], [0, 30, 20, 50], [30, 30, 40, 40] ]	[ [15, 15, 25, 25], [40, 10, 50, 20] ]	[10, 10, 30, 30]	true
[ [0, 0, 20, 10], [10, 20, 20, 40], [30, 0, 50, 20] ]	[ [20, 40, 30, 50], [30, 20, 50, 30] ]	[20, 30, 30, 40]	false
����� �� ����
����� �� #1
������ ���ÿ� �����ϴ�.

����� �� #2
�̹� �о�� ������ ��ġ�� ������ �ļ��� �Ϻθ� �����ϰ� ���� �ʾ� �о���� �� �����ϴ�.
*/

/*
#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> lands, vector<vector<int>> wells, vector<int> point) {
	bool answer = true;
	bool landCheck = true;
	bool wellCheck = false;
	int x1 = point[0];
	int x2 = point[2];
	int y1 = point[1];
	int y2 = point[3];
	// ���� ��ġ���� Ȯ�� �Ȱ�ġ�� true, ��ġ�� false
	for (int i = 0; i < lands.size(); i++) {
		bool checkX = false;
		bool checkY = false;
		if (x1<lands[i][0] && x2>lands[i][0])
			checkX = true;
		if (x1<lands[i][2] && x2>lands[i][2])
			checkX = true;
		
		if (y1<lands[i][1] && y2>lands[i][1])
			checkY = true;
		if (y1<lands[i][3] && y2>lands[i][3])
			checkY = true;

		if (checkX && checkY) {
			landCheck = false;
			break;
		}
	}

	// �ļ��� ��ġ���� Ȯ�� ��ġ�� true, �Ȱ�ġ�� false
	for (int i = 0; i < wells.size(); i++) {
		bool checkX = false;
		bool checkY = false;
		if (x1<wells[i][0] && x2>wells[i][0])
			checkX = true;
		if (x1<wells[i][2] && x2>wells[i][2])
			checkX = true;

		if (y1<wells[i][1] && y2>wells[i][1])
			checkY = true;
		if (y1<wells[i][3] && y2>wells[i][3])
			checkY = true;

		if (checkX && checkY) {
			wellCheck = true;
			break;
		}
	}
	answer = landCheck && wellCheck;
	return answer;
}

int main() {
	vector<vector<int>> lands = { {10, 0, 30, 5},{0, 30, 20, 50},{30, 30, 40, 40} }, wells = { {15, 15, 25, 25},{40, 10, 50, 20} };
	vector<int> point = { 10, 10, 30, 30 };
	cout << solution(lands, wells, point);
	return 0;
}
*/