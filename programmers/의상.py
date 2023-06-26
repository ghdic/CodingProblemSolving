def solution(clothes):
    answer = 1
    clf = {}
    for name, key in clothes:
        if key in clf:
            clf[key] += 1
        else:
            clf[key] = 1
    for num in clf.values():
        answer *= (num + 1)
    return answer - 1

print(
    solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])
)