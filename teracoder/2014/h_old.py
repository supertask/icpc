T=input()
for t in range(T):
	N=input()
	times = []
	for n in range(N):
		name,time = raw_input().split()
		time = int(time)
		times.append(time)
	times.sort()
	waiting = 0
	waitings = []
	is_first = True
	for timeman in times:
		waiting+=timeman
		waitings.append(waiting)
	waitings.pop()
	print sum(waitings)
	

