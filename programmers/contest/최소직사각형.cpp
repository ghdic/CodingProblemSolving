// https://programmers.co.kr/learn/courses/30/lessons/86491
/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int left = 0;
	int right = 0;
	for (int i = 0; i < sizes.size(); i++) {
		left = max(left, max(sizes[i][0], sizes[i][1]));
		right = max(right, min(sizes[i][0], sizes[i][1]));
	}
	return left * right;
}
*/