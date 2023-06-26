from queue import Queue

def can_change(prev, target):
    cnt = 0
    for a, b in zip(prev, target):
        if a != b:
            cnt += 1
    return cnt == 1

def solution(begin, target, words):
    q = Queue()
    answer = 0

    q.put(begin)
    while not q.empty():
        sz = q.qsize()
        answer += 1
        for i in range(sz):
            p = q.get()
            index = 0
            while index < len(words):
                if can_change(p, words[index]):
                    if words[index] == target:
                        return answer
                    q.put(words[index])
                    del words[index]
                    index -= 1
                index += 1

    return 0