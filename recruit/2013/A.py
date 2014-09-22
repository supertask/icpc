T = input()
for i in range(T):
	N = input()
	same_numbers = [0 for ii in range(N)]
	nums = raw_input().split()
	sentoList = [int(numm[0]) for numm in nums]
	sentoList = set(sentoList)
	for num_str in nums:
		for i,sento in enumerate(sentoList):
			if int(num_str[0]) == sento:
				same_numbers[i] += int(num_str)
	print max(same_numbers)

