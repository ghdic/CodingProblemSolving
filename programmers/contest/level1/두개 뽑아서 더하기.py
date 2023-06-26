def solution(numbers):
    a = set()
    l = len(numbers)
    for i in range(l):
      for j in range(l):
        if i != j:
          a.add(numbers[i] + numbers[j])

    answer = sorted(list(a))
    return answer

print(solution([5,0,2,7]))