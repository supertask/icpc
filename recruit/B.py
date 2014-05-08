T = input()
for t in range(T):
	hanin_strs = raw_input().split()
	hanin_ritsu = float(sum([len(w) for w in hanin_strs])) / len(hanin_strs)
	
	N = input()	
	yogisya_list = ["" for n in range(N)] 
	yogisya_memo_list = ["" for n in range(N)]
	ritsu_list = [0.0 for n in range(N)]
	
	for i in range(N):
		aa = raw_input().split(": ")
		yogisya_list[i] = aa[0]
		yogisya_memo_list[i] = aa[1]

	for i,yogisya_memo in enumerate(yogisya_memo_list):
		yogisya_memos = yogisya_memo.split()
		ritsu = float(sum([len(w) for w in yogisya_memos])) / len(yogisya_memos)
		ritsu_list[i] = abs(hanin_ritsu - ritsu)

	mini = min(ritsu_list)
	for i,ritsu in enumerate(ritsu_list):
		if ritsu == mini:
			print yogisya_list[i]
			break

