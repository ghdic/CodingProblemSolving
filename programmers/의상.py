# def solution(clothes):
#     answer = 1
#     clf = {}
#     for name, key in clothes:
#         if key in clf:
#             clf[key] += 1
#         else:
#             clf[key] = 1
#     for num in clf.values():
#         answer *= (num + 1)
#     return answer - 1

# 코니는 하루에 최소 1개의 의상을 입음
# 매번 서로 다른 방법으로 옷을 착용
def solution(clothes):
    grouping = {}
    answer = 1
    for name, key in clothes:
        grouping[key] = grouping.get(key, 0) + 1
    for num in grouping.values():
        answer *= (num + 1)
    return answer - 1

from collections import Counter
from functools import reduce


def solution_review(clothes):
    category_count = Counter(category for _, category in clothes)

    return reduce(lambda acc, x: acc * (x + 1), category_count.values(), 1) - 1


print(
    solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])
)