for p in range(int(input())):
	a, b = map(str, input().split())
	a = [ord(i) for i in a]
	b = [ord(i) for i in b]
	s = "Distances:"
	for i in range(len(a)):
		
		if b[i]>=a[i]:
			s += " " + str(b[i]-a[i])
		else:
			s += " " + str(b[i]+26-a[i])
	
	print(s)