# 초단위 주시가격 담긴 배열 prices, 가격이 떨어지지 않은 기간은 몇초인가?
def solution(prices):
    queue = []
    result = [0] * len(prices)

    for index, price in enumerate(prices):
        while queue and prices[queue[-1]] > price:
            q_index = queue.pop()
            result[q_index] = index - q_index
        queue.append(index)

    index = len(prices) - 1
    while queue:
        q_index = queue.pop()
        result[q_index] = index - q_index
    return result


print(solution([1,2,3,2,3]))