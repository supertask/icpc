N,T = map(int,raw_input().split())
A = []
for i in range(N):
	A.append(input())

risums = []
nums = [0 for i in range(1,T+1)]

for a in A:
	i = 1
	risum = []
	while True:
		node = a * i
		if node > T: break
		risum.append(node)
		i+=1
	for r in risum:
		nums[r-1]+=1
print max(nums)
