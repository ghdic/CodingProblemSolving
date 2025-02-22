# 일차선 다리를 정해진 순서대로 모든 트럭이 건너려면 최소 몇초가 걸리나?
# 다리는 weight 이하까지 무게를 견딜수있음
# 지나가는데 bridge_length만큼 시간걸림
# 자동차가 다리위로 올라가는데 1초 걸림
from collections import deque

def solution(bridge_length, weight, truck_weights):
    n = len(truck_weights)
    time = 0
    bridge = deque([0] * bridge_length)
    cur_weight = 0
    cur_index = 0

    while cur_index < n:
        time += 1
        item = bridge.popleft()
        cur_weight -= item

        # 트럭이 지나갈수 있는 경우
        if truck_weights[cur_index] + cur_weight <= weight:
            cur_weight += truck_weights[cur_index]
            bridge.append(truck_weights[cur_index])
            cur_index += 1
        else:
            bridge.append(0)
    return time + bridge_length

print(solution(2, 10, [7,4,5,6]))
print(solution(100, 100, [10,10,10,10,10,10,10,10,10,10]))