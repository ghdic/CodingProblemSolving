def solution(array, commands):
    answer = []
    for start, end, st in commands:
        print(start, end, st)
        sector = array[start-1:end]
        sector.sort()
        answer.append(sector[st - 1])
    return answer

print(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]	))