# 모든 음식의 스코빌 지수를 K이상으로 만들려함
# 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
# 음식은 섞이면서 하나로 줄어듬
# 모든 음식의 스코빌 지수가 K이상이 되려면 최소 몇번 섞어야 하는가?

import heapq

def solution(scoville, K):
    answer = 0
    q = []
    for i in scoville:
        heapq.heappush(q, i)
    while True:
        item = heapq.heappop(q)
        if item >= K:
            break
        if len(q) == 0:
            answer = -1
            break 
        answer+=1
        heapq.heappush(q, item + 2 * heapq.heappop(q))
    return answer