/*
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int t = x, sum = 0;
	while (t) {
		sum += t % 10;
		t /= 10;
	}
	answer = (x % sum == 0 ? true : false);
	return answer;
}
*/


