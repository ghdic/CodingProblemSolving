n, m = map(int, input().split())
board = ["" for x in range(n)]
for i in range(n):
    board[i] = input()
k = int(input())

state = {}
for i in range(n):
    num = 0
    for j in range(m):
        if board[i][j] == '1':
            num += (1 << j)
    if num in state.keys():
        state[num] += 1
    else:
        state[num] = 1


res = 0

for key in state:
    cnt = 0
    for i in range(m):
        if key & (1 << i) == 0:
            cnt += 1
    if(cnt > k): continue
    if((k - cnt) % 2 == 0):
        res = max(res, state[key])

print(res)
