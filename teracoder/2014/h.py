for t in range(input()):
	times = [int(raw_input().split().pop()) for n in range(input())]
	times.sort()
	waiting = 0
	waitings = []
	for timeman in times:
		waiting+=timeman
		waitings.append(waiting)
	waitings.pop()
	print "Case #%s:\n%s" % (t+1, sum(waitings))
