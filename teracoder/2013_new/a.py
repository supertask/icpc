while True:
	C = raw_input()
	if C == "#": break
	N = input()
	names = []
	for i in range(N):
		name = raw_input()
		names.append(name)
	if C in names:
		print "FOUND"
	else:
		print "NOT FOUND"
