#! coding: utf-8
import math
import fractions
import datetime
T=input()
for t in range(T):
	hour,mini,sec = map(int,raw_input().split(":"))
	if hour >= 12:
		hour = hour - 12
	hour_sec = hour*3600+mini*60+sec
	mini_sec = mini*60+sec
	child = [0,0,0]
	parent = [0,0,0]
	franc = [0,0,0]
	print "-"*10
	child[0] = math.fabs(hour_sec * 10 - mini_sec * 120)
	parent[0] = 1200
	child[1] = math.fabs(mini_sec - sec * 60)
	parent[1] = 10
	child[2] = math.fabs(sec * 720 - hour_sec)
	parent[2] = 120

	mini = 100000000
	ans_i = 0
	is_mirors = [False,False,False]
	for i in range(len(franc)):
		franc[i] = fractions.gcd(child[i],parent[i]) #最大公約数
		num = child[i] / float(parent[i])
		if num > 180:
			num = 360 - num	
			is_mirors[i] = True
		print num
		if num < mini:
			mini = num
			ans_i = i
	# print franc[ans_i]
	ans_child = int(child[ans_i]/franc[ans_i])
	ans_parent = int(parent[ans_i]/franc[ans_i])
	print "%s/%s" % (ans_child,ans_parent)
	
