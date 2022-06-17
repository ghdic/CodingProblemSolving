// https://programmers.co.kr/learn/courses/30/lessons/87946

/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int need[8], use[8];
bool check[8];
int num, res = 0;

void dfs(int cnt, int remain) {
    for (int i = 0; i < num; i++) {
        if (!check[i] && need[i] <= remain) {
            check[i] = true;
            dfs(cnt + 1, remain - use[i]);
            check[i] = false;
        }
    }
    res = max(res, cnt);
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    num = dungeons.size();
    for (int i = 0; i < num; i++) {
        need[i] = dungeons[i][0];
        use[i] = dungeons[i][1];
    }
    dfs(0, k);
    return answer = res;
}

*/