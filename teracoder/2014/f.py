for t in range(input()):
	ronris, buff = raw_input().split(), []
	for r in ronris:
		if r == "AND": buff.append(buff.pop() & buff.pop())
		elif r == "OR": buff.append(buff.pop() | buff.pop())
		elif r == "NAND": buff.append( not(buff.pop() & buff.pop()) )
		elif r == "NOR": buff.append( not(buff.pop() | buff.pop()) )
		elif r == "XOR": buff.append(buff.pop() ^ buff.pop())
		elif r == "NOT": buff.append(not buff.pop())
		elif r == "=": print "Case #%s:\n%s" % (t+1, int(buff.pop()))
		else: buff.append(int(r))
