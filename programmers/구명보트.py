# 구명보트 한번에 최대 2명씩, 무게제한있음
# 구명보트를 최대한 적게 사용하여 모든 사람을 구출해보려고함
# 몸무게 담은 배열 people, 무게 제한 limit, 필요한 구명보트갯수 최솟값??
# 구명보트 무게제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어짐(구출할수없는경우는 없음)
def solution(people, limit):
    people.sort()
    left, right = 0, len(people) - 1
    boats = 0

    while left <= right:
        if people[left] + people[right] <= limit:
            left += 1
        right -= 1
        boats += 1
    return boats
print(solution([70, 50, 80, 50], 100))