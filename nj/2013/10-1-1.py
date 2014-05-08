machi_number = input()
road_number = input()
mapp = [[10000 for j in range(machi_number)] for i in range(machi_number)]

for i in range(road_number):
	a,b,c,d =map(int, raw_input().split(","))
	aa = a-1
	bb = b-1
	mapp[aa][bb] = c
	mapp[bb][aa] = d
for i in range(machi_number):
	mapp[i][i] = 0

for k in range(machi_number):
	for i in range(machi_number):
		for j in range(machi_number):
			if mapp[i][j] > (mapp[i][k] + mapp[k][j]):
				mapp[i][j] = mapp[i][k] + mapp[k][j]

x1,x2,y1,y2 = map(int, raw_input().split(","))
print y1 - y2 - mapp[x1-1][x2-1] - mapp[x2-1][x1-1]


