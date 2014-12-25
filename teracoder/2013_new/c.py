while True:
	ip_str = raw_input()
	if ip_str == "0.0.0.0": break
	subnet = input()
	ip_parts = map(int,ip_str.split('.'))
	bits = []
	for ip_part in ip_parts:
		bits += list(format(ip_part,'08b'))
	ans = []
	# print ''.join(bits) #DD
	for i,bit in enumerate(bits):
		if i+1 > subnet:
			ans.append("0")
		else:
			ans.append(bit)
	# print ''.join(ans) #DD

	ip = []
	for i in range(4):
		ip.append(str(int(''.join(ans[i*8:i*8+8]),2)))
	print '.'.join(ip)
