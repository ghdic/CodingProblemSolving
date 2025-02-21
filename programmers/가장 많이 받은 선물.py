# 두사람이 선물이 주고받았으면 더 많은 선물준사람이 다음달에 1개 받음
# 기록x거나 서로 같다면 선물 지수가 더 큰사람이 작은사람에게 다음달에 1개 받음
# 선물지수는 이번달에 자신이 준 선물수 - 친구가 준 선물수
# 다음달에 가장 많은 선물을 받을 친구가 받을 선물 수 ?
import copy

def solution(friends, gifts):
    answer = 0
    friends_cnt = len(friends)
    friends_rev = { key:i for i, key in enumerate(friends)}
    data = { key:0 for key in range(friends_cnt) }
    table = { key:copy.deepcopy(data) for key in range(friends_cnt) }
    for gift in gifts:
        giver, receiver = gift.split(' ')
        table[friends_rev[giver]][friends_rev[receiver]] += 1

    score = [0 for x in range(friends_cnt)]
    for i in range(friends_cnt):
        for j in range(friends_cnt):
            if i == j: continue
            score[i] += table[i][j]
            score[j] -= table[i][j]
    for i in range(friends_cnt):
        cnt = 0
        for j in range(friends_cnt):
            if i == j: continue
            if table[i][j] > table[j][i]:
                cnt += 1
            elif table[i][j] == table[j][i] and score[i] > score[j]:
                cnt += 1
        answer = max(answer, cnt)
    return answer

print(
solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"])
)