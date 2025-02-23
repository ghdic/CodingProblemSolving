# 탐험을 시작하기 위한 최소필요 피로도, 던전탐험을 마쳤을때 소모되는 소모피로도가 있음
# 게임에 하루에 한번씩 탐험할수있는 던전이 여러개있음
# 유저가 탐험할수있는 최대 던전 수??
def solution(k, dungeons):
    answer = 0
    n = len(dungeons)
    visited = [False] * n

    def dfs(hp, count):
        nonlocal answer
        answer = max(answer, count)
        for index, [need_hp, use_hp] in enumerate(dungeons):
            if visited[index] or hp < need_hp:
                continue
            visited[index] = True
            dfs(hp - use_hp, count + 1)
            visited[index] = False

    dfs(k, 0)
    return answer

