# 물에 잠긴 경로를 피해서 학교까지 가는법
# (1, 1) -> (m, n)
def solution(m, n, puddles):
    MOD = 1_000_000_007
    map = [[0] * (m + 1) for i in range(n + 1)]
    map[1][1] = 1

    for x, y in puddles:
        map[y][x] = -1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if map[i][j] == -1:
                continue
            if map[i - 1][j] != -1:
                map[i][j] += map[i - 1][j]
            if map[i][j - 1] != -1:
                map[i][j] += map[i][j - 1]
            map[i][j] %= MOD
    return map[n][m]
