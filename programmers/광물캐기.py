# 다이아곡괭이(1,1,1), 철곡괭이(5, 1, 1), 돌곡괭이(25, 5, 1) 각각 0~5개 보유중
# 괄호로 나타낸건 다이아, 철, 돌 캘경우 소모되는 피로도
# 종류와 상관없이 광물 5개 캔 후 더이상 사용 불가
# 한번 사용하기 시작한 곡괭이는 사용할 수 없을때까지 사용
# 광물은 주어진 순서대로만 캘수 있음
# 종료조건: 모든 광물캐기 or 곡괭이가 없을때까지
# 작업이 끝나기까지 최소한의 피로도를 return

def cal_cost(pick, mineral):
    if pick == "diamond":
        return 1
    elif pick == "iron":
        if mineral == "diamond":
            return 5
        else:
            return 1
    elif pick == "stone":
        if mineral == "diamond":
            return 25
        elif mineral == "iron":
            return 5
        else:
            return 1

def solution(picks, minerals):
    answer = 0
    cost_per = []
    for i in range(0, len(minerals), 5):
        box = [0, 0, 0]
        if i + 5 >= len(minerals):
            for j in range(i, len(minerals)):
                box[0] += cal_cost("diamond", minerals[j])
                box[1] += cal_cost("iron", minerals[j])
                box[2] += cal_cost("stone", minerals[j])
        else:
            for j in range(i, i+5):
                box[0] += cal_cost("diamond", minerals[j])
                box[1] += cal_cost("iron", minerals[j])
                box[2] += cal_cost("stone", minerals[j])
        cost_per.append(box)
    cost_per.sort(key=lambda x: (-x[2], -x[1], -x[0]))
    for c in cost_per:
        if picks[0] != 0:
            picks[0] -= 1
            answer += c[0]
        elif picks[1] != 0:
            picks[1] -= 1
            answer += c[1]
        elif picks[2] != 0:
            picks[2] -= 1
            answer += c[2]

    return answer

print(solution([1, 3, 2], ["diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"]))