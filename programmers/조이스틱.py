# 조이스틱 조작해서 목표하는 문자열 만드는데 사용되는 조작횟수 최솟값
def solution(name):
    answer = float('inf')
    n = len(name)
    visited = [False] * n

    def dfs(pos, new_name, cnt):
        nonlocal answer

        visited[pos] = True

        # 현재 위치의 문자를 일치시키는데 드는 최소비용
        ord_w = ord(name[pos])
        gap = min(ord_w - ord('A'), ord('Z') - ord_w + 1)
        new_name[pos] = name[pos]

        if name == ''.join(new_name):
            answer = min(answer, cnt + gap)

        # 왼쪽으로 가는경우
        next_left = pos - 1 if pos - 1 >= 0 else n - 1
        if not visited[next_left]:
            dfs(next_left, new_name, cnt + gap + 1)

        # 오른쪽으로 가는 경우
        next_right = pos + 1 if pos + 1 < n else 0
        if not visited[next_right]:
             dfs(next_right, new_name, cnt + gap + 1)

        new_name[pos] = 'A'
        visited[pos] = False

    dfs(0, list('A' * n), 0)
    return answer

print(solution("JAZ"))