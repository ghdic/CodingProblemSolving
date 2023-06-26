def solution(participant, completion):
  a = dict()
  for i in participant:
    if i in a:
      a[i] += 1
    else:
      a[i] = 1

  for person in completion:
    if a[person] == 1:
      a.pop(person)
    else:
      a[person] -= 1

  answer = next(iter(a.keys()))
  return answer


print(solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"]))


# import collections

# def solution(participiant, completion):
#   answer = collections.Counter(participiant) - collections.Counter(completion)
#   return list(answer.keys())[0]