

w = []
connect = {}
visit = []
res = 0

def dfs(cur, parent):
    global w
    global connect
    global visit
    global res
    visit[cur] = True
    num = w[cur]
    for nxt in connect[cur]:
        if visit[nxt]: continue
        val = dfs(nxt, cur)
        res += abs(val)
        num += val

    return num


def solution(a, edges):
    global w
    global connect
    global visit
    global res
    w = a
    for e in edges:
        if not e[0] in connect:
            connect[e[0]] = [e[1]]
        else:
            connect[e[0]].append(e[1])

        if not e[1] in connect:
            connect[e[1]] = [e[0]]
        else:
            connect[e[1]].append(e[0])
    visit = [False for i in range(len(w))]
    ret = dfs(0, 0)
    if ret == 0:
        return res
    else:
        return -1

print(solution([0,0,0,0,0], [[0,1],[3,4],[2,3],[0,3]]))