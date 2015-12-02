for t in range(input()):
	line, ans = raw_input(), ""
	for i in range(4):
		if int(line[2]) == (4-i): ans="B%s"%(i+1)
	print "Case #%s:\n"%(t+1) + (ans if line[0:2]=='g1' and ans else "ERROR")
