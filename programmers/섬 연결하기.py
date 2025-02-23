# n개의 섬사이에 모든섬이 통행 가능하도록 다리 건설하는 비용이 최소가 되도록
# 섬갯수 n, 각 연결에 대해 드는 비용 costs
# 1. 모든섬이 통행 가능하냐?
# 2. 어떻게 최소 비용으로 연결할거냐
#  - 연결된거중 가장 cost가 낮은 경로부터 깔면 어떰?
import heapq
from collections import defaultdict


def solution(n, costs):
    answer = 0
    connected_node = [False] * n
    connect_cost = defaultdict(list)
    for i, j, cost in costs:
        connect_cost[i].append([j, cost])
        connect_cost[j].append([i, cost])

    connected_node[0] = True
    pq = [(cost, 0, j) for j, cost in connect_cost[0]]
    heapq.heapify(pq)
    while pq:
        cost, i, j = heapq.heappop(pq)
        if connected_node[j]:  # 이미 연결되어있는 노드
            continue
        # 가장 저렴한 비용의 경로 공사를 진행
        connected_node[j] = True
        answer += cost
        for j_j, j_cost in connect_cost[j]:
            heapq.heappush(pq, (j_cost, j, j_j))
    return answer

print(solution(4, [[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))