# 단 한명의 선수를 제외하고는 모두 완주
# 참여한선수 담긴 배열, 완주한선수 담긴 배열 주어질때
# 완주하지 못한 선수의 이름을 return
# 참가자 중에는 동명이인이 있을 수 있음
from collections import Counter

def solution(participant, completion):
    completion_player = Counter(completion)
    for player in participant:
        completion_player[player] -= 1

    for player, cnt in completion_player.items():
        if cnt != 0:
            return player
    return None


# import timeit
#
# a = list(range(1000000))  # 큰 리스트
#
# # 방법 1: 리스트 덧셈
# time1 = timeit.timeit(lambda: a + [10], number=1000)
#
# # 방법 2: 리스트 언패킹
# time2 = timeit.timeit(lambda: [*a, 10], number=1000)
#
# print(f"a + [10] 실행 시간: {time1:.6f}초")
# print(f"[*a, 10] 실행 시간: {time2:.6f}초")
#
# # list + list: list_concat 두 리스트를 memcpy로 한번에 복사해서 더해줌
# # unpacking: list_append 반복적 호출해서 하나씩 데이터삽입 및 메모리 추가할당 가능성있음