from copy import deepcopy

dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, -1, -1, -1, 0, 1, 1, 1]

s, e = 0, 0

fishes = [[] for _ in range(17)]
board = [[] for _ in range(4)]


for i in range(4):
    values = list(map(int, input().split()))
    for j in range(0, 8, 2):
        board[i].append([values[j], values[j+1]-1]) # 번호, 방향 저장
        fishes[values[j]] = [i, j//2] # 위치 저장


ans = -int(1e9)

def dfs(y, x, d, val):
    global ans, fishes, board
    move(y, x)
    while True:
        ny, nx = y + dy[d], x + dx[d]
        if ny < 0 or ny >= 4 or nx < 0 or nx >= 4:
            ans = max(ans, val)
            return
        if not board[ny][nx]:
            y, x = ny, nx
            continue
        t_board, t_fish = deepcopy(board), deepcopy(fishes)
        nd, nval = board[ny][nx][1], board[ny][nx][0] + val
        fishes[board[ny][nx][0]], board[ny][nx] = [], []
        dfs(ny, nx, nd, nval)
        board, fishes = t_board, t_fish
        y, x = ny, nx



def move(sy, sx):
    """ 물고기 번호순으로 움직인다 """
    for i in range(1, 17):
        if fishes[i]:
            y, x = fishes[i]
            d = board[y][x][1]
            for _ in range(9): # 8방향에 대해 움직일수 있는지 확인
                ny, nx = y + dy[d], x + dx[d]
                if ny < 0 or ny >= 4 or nx < 0 or nx >= 4 or (sy == ny and sx == nx):
                    d = (d + 1) % 8
                    continue
                board[y][x][1] = d
                if board[ny][nx]: # 옮길 방향에 물고기가 있는 경우 스위치
                    fishes[board[ny][nx][0]] = [y, x]
                fishes[i] = [ny, nx]
                board[ny][nx] , board[y][x] = board[y][x], board[ny][nx]
                break

d, val = board[0][0][1], board[0][0][0]
fishes[board[0][0][0]], board[0][0] = [], []                    
dfs(0, 0, d, val)
print(ans)