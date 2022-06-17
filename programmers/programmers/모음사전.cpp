// https://programmers.co.kr/learn/courses/30/lessons/84512
/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
string vowel[5] = { "A", "E", "I", "O", "U" };

void dfs(int len, string s) {
    if (len == s.length()) {
        v.push_back(s);
        return;
    }

    for (int i = 0; i < 5; i++) {
        dfs(len, s + vowel[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for (int i = 1; i <= 5; i++) {
        dfs(i, "");
    }

    sort(v.begin(), v.end());
    answer = find(v.begin(), v.end(), word) - v.begin() + 1;
    return answer;
}
*/