# -*- coding: utf-8 -*-
N, M = map(int, raw_input().split())
mapCost = [[10000 for j in range(N)] for i in range(N)]
mapTime = [[10000 for j in range(N)] for i in range(N)]

for n in range(N):
	a,b,cost,time = map(int, raw_input().split())
	mapCost[a-1][b-1] = cost
	mapTime[a-1][b-1] = time
for n in range(N):
	mapCost[n][n] = 0
	mapTime[n][n] = 0

for k in range(N):
	for i in range(N):
		for j in range(N):
			if mapCost[i][j] > (mapCost[i][k] + mapCost[k][j]):
				mapCost[i][j] = mapCost[i][k] + mapCost[k][j]
			if mapTime[i][j] > (mapTime[i][k] + mapTime[k][j]):
				mapTime[i][j] = mapTime[i][k] + mapTime[k][j]

K = input()
for k in range(K):
	p,q,r = map(int, raw_input().split())
	if r == 0:
		print mapCost[p-1][q-1]
	else :
		print mapTime[p-1][q-1]

