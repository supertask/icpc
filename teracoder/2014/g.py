import math
T=input()
for t in range(T):
	X,C = map(int,raw_input().split())
	T,S = raw_input(),raw_input()
	padman = list(T).pop()
	N = int(math.log(X,2))
	fugo_2sin = ""
	for s in S:
		trans = format(ord(s),'08b')
		fugo_2sin += trans
	now=0
	ans = ""
	for i in range(len(fugo_2sin)):
		if i % N == 0:
			now = i
			tmp = fugo_2sin[now:now+N]
			if len(tmp) != N:
				pad = N-len(tmp)
				for p in range(pad):
					tmp=tmp+"0"
			sin2 = int(tmp,2) #trans 2sin
			ans+=T[sin2]
	while True:
		if (len(ans)*N) % 8 == 0:
			break
		else:
			ans = ans + padman
	print ans
	
