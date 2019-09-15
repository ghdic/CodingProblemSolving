#include <iostream>

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	for (int i = 0; i < progresses.size(); ++i) {
		progresses[i] = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] ? 1 : 0);
	}
	int prev = progresses[0], cnt = 1;
	for (int i = 1; i < progresses.size(); ++i)
		if (prev >= progresses[i])
			++cnt;
		else {
			answer.push_back(cnt);
			cnt = 1;
			prev = progresses[i];
		}
	answer.push_back(cnt);
	return answer;
}

int main() {
	vector<int> a = { 93 }, b = { 1 };
	vector<int> k = solution(a, b);
	for (int i = 0; i < k.size(); ++i)
		cout << k[i] << endl;
}