# 투포인터

def solution(sequence, k):
    answer = []
    s, e = 0, 0
    hap = sequence[0]
    while s <= e:
        if hap == k:
            answer.append([s, e])
            hap -= sequence[s]
            s += 1
        elif hap < k:
            e += 1
            if e == len(sequence):
                break
            hap += sequence[e]
        else:
            hap -= sequence[s]
            s += 1
    answer.sort(key=lambda x: x[1]-x[0])
    return answer[0]

print(solution([2, 2, 2, 2, 2], 6)) # [[1, 3], [2, 4]]