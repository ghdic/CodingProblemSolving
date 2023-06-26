def solution(board, moves):
  stack = [0]
  answer = 0
  for i in range(len(moves)):
    for j in range(len(board)):
      if board[j][moves[i]-1]:
        item = board[j][moves[i]-1]
        board[j][moves[i]-1] = 0
        if stack[-1] == item:
          stack.pop()
          answer += 2
        else:
          stack.append(item)
        break
  return answer

print(solution([
  [0,0,0,0,0],
  [0,0,1,0,3],
  [0,2,5,0,1],
  [4,2,4,4,2],
  [3,5,1,3,1]], [1,5,3,5,1,2,1,4]))

