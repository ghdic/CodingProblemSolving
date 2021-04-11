def solution(answers):
	answer = []
	person = []
	pattern = [[1, 2, 3, 4, 5],
						[2, 1, 2, 3, 2, 4, 2, 5],
						[3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
	for i in range(3):
		correct = 0
		index = 0
		for ans in answers:
			if pattern[i][index] == ans:
				correct += 1
			index += 1
			if index == len(pattern[i]):
				index = 0
		person.append(correct)
	mx = max(person)
	for p in range(3):
		if person[p] == mx:
			answer.append(p + 1)
	return answer