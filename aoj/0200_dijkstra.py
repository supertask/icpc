# -*- coding: utf-8 -*-

E, V = map(int, raw_input().split())
costs = [[10000 for j in range(E)] for i in range(E)]
times = [[10000 for j in range(E)] for i in range(E)]

for e in range(E):
	a,b,cost,time = map(int, raw_input().split())
	a,b=a-1,b-1
	costs[a][b] = cost
	times[a][b] = time



def dijkstra(first, last):
	costD = [10000 for i in range(V)]
	timeD = [10000 for i in range(V)]
	costD[first] = 0
	timeD[first] = 0

	S = {}
	for i,c in enumerate(costs[first]):
		if c != 10000:
			S[i] = c
	mini = min(S.values())
	for station,cost in S.items():
		if mini == cost:
			costD[station] = cost
	

# output 
K = input()
for k in range(K):
	p,q,r = map(int, raw_input().split())
	p=p-1
	q=q-1
	if r == 0:
		dijkstra(p,q)
	else :
		dijkstra(p,q)
