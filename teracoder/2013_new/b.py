while True:
	num_str = raw_input()
	if num_str == "-1": break
	print "OK" if sum(map(int,list(num_str))) % 10 == 0 else "NG"
