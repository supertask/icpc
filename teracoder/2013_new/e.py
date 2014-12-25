import sys
T=input()
for t in range(T):
	N=input()
	groups = map(int,raw_input().split())
	group_dict = [0,0,0,0,0,0]

	is_over=False
	for g in groups:
		if g > 6:
			is_over=True
			break
		group_dict[g-1]+=1
	if is_over:
		print "No"
		continue

	print group_dict
	"""
	cnt = 0
	for index in range(len(group_dict)):
		ii = index+1 #group_dict_index
		if ii == 6:
			cnt+=1 #OK
		else if ii == 5:
			if group_dict[1-1] > 0:
				group_dict[1-1]-=1
			cnt+=1 #OK
		else if ii == 4:
			if group_dict[2-1] > 0:
				group_dict[2-1]-=1
			elif group_dict[1-1] > 0:
				group_dict[1-1]-=1
			cnt+=1
		else if ii == 2:
			if group_dict[4-1] > 0:
				group_dict[4-1]-=1
			elif group_dict[3-1] > 0:
				group_dict[3-1]-=1
			cnt+=1
		else if ii == 1:
			for i in range(5,0,-1):
			if group_dict[5-1] > 0:
				group_dict[5-1]-=1
			cnt+=1
	if cnt > 7:
		print "Yes"
	else:
		print "No"
	"""


