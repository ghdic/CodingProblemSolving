# n개의 송전탑이 하나의 트리 형태로 연결되어있다
# 전선을 하나 끊어서 두 전력망의 송전탑의 갯수를 비슷하게 하려함
# 두전력망의 송전탑 개수차이의 절대값을 return
from collections import defaultdict


def solution(n, wires):
    answer = float('inf')
    connect_dict = defaultdict(list)

    for v1, v2 in wires:
        connect_dict[v1 - 1].append(v2 - 1)
        connect_dict[v2 - 1].append(v1 - 1)
    visited = [False] * n

    def dfs(cur_node):
        node_cnt = 1
        visited[cur_node] = True

        for next_node in connect_dict[cur_node]:
            if visited[next_node]:
                continue
            node_cnt += dfs(next_node)
        visited[cur_node] = False
        return node_cnt

    for v1, v2 in wires:
        visited[v1 - 1] = True
        node_cnt = dfs(v2 - 1)
        answer = min(answer, abs(n - node_cnt * 2))
        visited[v1 - 1] = False
    return answer

print(solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]))