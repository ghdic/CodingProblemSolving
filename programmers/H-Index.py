# 논문 n편중 h번이상 인용된 논문이 h편이상이면 h최댓값이 이 과학자의 H-Index
def solution(citations):
    citations.sort(reverse=True)
    n = len(citations)
    for idx, cit in enumerate(citations):
        if idx + 1 > cit:
            return idx

    return n