# I 숫자	큐에 주어진 숫자를 삽입합니다.
# D 1	큐에서 최댓값을 삭제합니다.
# D -1	큐에서 최솟값을 삭제합니다.
# 큐가 비어있으면 [0, 0], [최댓값, 최솟값]을 return하도록
import heapq

def solution(operations):
    min_heap = []  # 최소 힙
    max_heap = []  # 최대 힙 (음수 값 저장)
    count_dict = {}  # 각 숫자의 등장 횟수 관리

    for op in operations:
        command, value = op.split()
        value = int(value)

        if command == "I":  # 삽입 연산
            heapq.heappush(min_heap, value)
            heapq.heappush(max_heap, -value)
            count_dict[value] = count_dict.get(value, 0) + 1  # 등장 횟수 증가

        elif command == "D":
            if count_dict:  # 비어있지 않을 때만 삭제 수행
                if value == 1:  # 최댓값 삭제
                    while max_heap:
                        max_val = -heapq.heappop(max_heap)
                        if count_dict.get(max_val, 0) > 0:  # 유효한 값인지 확인
                            count_dict[max_val] -= 1
                            break  # 하나만 삭제

                elif value == -1:  # 최솟값 삭제
                    while min_heap:
                        min_val = heapq.heappop(min_heap)
                        if count_dict.get(min_val, 0) > 0:  # 유효한 값인지 확인
                            count_dict[min_val] -= 1
                            break  # 하나만 삭제

    # 최종 결과 확인 (비어있으면 [0,0] 반환)
    if not any(count_dict.values()):  # 남아있는 값이 없으면 [0, 0] 반환
        return [0, 0]

    # 존재하는 값들 중 최대, 최소 찾기
    while min_heap:
        min_val = heapq.heappop(min_heap)
        if count_dict.get(min_val, 0) > 0:
            break

    while max_heap:
        max_val = -heapq.heappop(max_heap)
        if count_dict.get(max_val, 0) > 0:
            break

    return [max_val, min_val]


print(solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]))
print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))