# 수포자 문제찍는 방법 세가지~
# 1,2,3,4,5,1,2,3,4,5 ....
# 2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5 ....
# 3,3,1,1,2,2,4,4,5,5,3,3,1,1 ....
# 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return
# 가장 높은 점수 받은 사람이 여럿일 경우 오름차순정렬
def get_score(answers, rules):
    n = len(rules)
    score = 0

    for i, answer in enumerate(answers):
        if answer == rules[i % n]:
            score += 1
    return score


def solution(answers):
    patterns = [
        [1, 2, 3, 4, 5],
        [2, 1, 2, 3, 2, 4, 2, 5],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ]

    scores = [get_score(answers, pattern) for pattern in patterns]
    max_score = max(scores)

    return [i + 1 for i, score in enumerate(scores) if score == max_score]