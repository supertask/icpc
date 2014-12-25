N = input()
vs = map(int,raw_input().split())
fs = map(int,raw_input().split())
cnt = 0
for v,f in zip(vs,fs):
	 if f > (v/2):
	 	cnt+=1
print cnt
