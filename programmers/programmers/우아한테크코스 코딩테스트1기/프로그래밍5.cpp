/*
문제 설명
배달이가 좋아하는 369게임(배달이는 아재입니다.)을 하고자 합니다. 놀이법은 1부터 숫자를 하나씩 대면서, 3, 6, 9가 들어가는 숫자는 숫자를 말하는 대신 3, 6, 9의 개수만큼 손뼉을 쳐야 합니다.

숫자 number가 매개변수로 주어질 때, 1부터 number까지 손뼉을 몇 번 쳐야 하는지 횟수를 return 하도록 solution 메서드를 완성해주세요.

제한사항
number는 1 이상 10,000 이하인 자연수입니다.
입출력 예
number	result
13	4
33	14
입출력 예 설명
입출력 예 #1
1부터 13까지 총 4번의 손뼉을 쳐야 합니다.

3	6	9	13
짝	짝	짝	짝
입출력 예 #2
1부터 33까지 총 14번의 손뼉을 쳐야 합니다.

3	6	9	13	16	19	23	26	29	30	31	32	33
짝	짝	짝	짝	짝	짝	짝	짝	짝	짝	짝	짝	짝짝
*/

/*
//아 먼가 수식으로 하고싶었는데 자리수 올라갈때마다 처리하는게 좀 꼬여서.. 시간없어서 그냥 시간복잡도 높은 간단한거로 하겠음..
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int number) {
	int answer = 0, num = 1;
	while (num <= number) {
		
		int temp = num;
		while (temp) {
			int a = temp % 10;
			if (a == 3 || a == 6 || a == 9)
				answer++;
			temp /= 10;
		}
		num++;
	}

	return answer;
}

int main() {
	int num = 34;
	cout << solution(num) << endl;
	return 0;
}
*/