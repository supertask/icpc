T = input()
for t in range(T):
	line = raw_input()
	if line[0]=='g' and line[1]=='1':
		if line[2] == '1':
			print "B4"
		elif line[2] == '2':
			print "B3"
		elif line[2] == '3':
			print "B2"
		elif line[2] == '4':
			print "B1"
		else:
			print "ERROR"
	else:
		print "ERROR"
