// https://programmers.co.kr/learn/courses/30/lessons/87377
/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const long long MAX = 10000000001;

vector<pair<long long, long long>> v;
long long len, maxX, minX, maxY, minY;
void init() {
    maxX = -MAX;
    maxY = -MAX;
    minX = MAX;
    minY = MAX;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    len = line.size();
    init();
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++) {
            long long adbc = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            if (adbc == 0)  continue;
            long long bfed = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long ecaf = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if ((bfed % adbc != 0) || (ecaf % adbc != 0)) continue;
            bfed /= adbc;     //x
            ecaf /= adbc;     //y
            v.push_back({ ecaf, bfed });
            maxX = max(maxX, (long long)bfed);
            maxY = max(maxY, (long long)ecaf);
            minX = min(minX, (long long)bfed);
            minY = min(minY, (long long)ecaf);
        }
    long long row = maxY - minY + 1;
    long long col = maxX - minX + 1;
    string temp(col, '.');
    answer.assign(row, temp);
    for (int i = 0; i < v.size(); i++) {
        long long y = v[i].first;
        long long x = v[i].second;
        answer[maxY - y][x - minX] = '*';
    }
    return answer;
}
*/