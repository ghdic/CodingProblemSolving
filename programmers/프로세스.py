# 운영체제가 프로세스를 관리할 경우 특정 프로세스가 몇번ㅉ래ㅗ 실행되는지 알아보고싶다
# 1. 실행 대기큐에서 대기중인 프로세스 하나를 꺼낸다
# 2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣는다
# 3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행한다
# 한번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료된다
from collections import deque
import heapq

def solution(priorities, location):
    queue = deque([(priority, index) for index, priority in enumerate(priorities)])
    max_heap = [-p for p in priorities]
    heapq.heapify(max_heap)
    rank = 0
    while queue:
        cur_node = queue.popleft()

        if -max_heap[0] > cur_node[0]:
            queue.append(cur_node)
        else:
            rank += 1
            heapq.heappop(max_heap)
            if cur_node[1] == location:
                return rank


print(solution([1,1,9,1,1,1], 0))