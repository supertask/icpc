T=input()
for t in range(T):
	ronris = raw_input().split()
	baf = []
	for r in ronris:
		if r == "AND":
			left,right = baf.pop(),baf.pop()
			baf.append(left & right)
		elif r == "OR":
			left,right = baf.pop(),baf.pop()
			baf.append(left | right)
		elif r == "NAND":
			left,right = baf.pop(),baf.pop()
			if left==1 and right==1:
				baf.append(0)
			elif left==1 and right==0:
				baf.append(1)
			elif left==0 and right==1:
				baf.append(1)
			elif left==0 and right==0:
				baf.append(1)
		elif r == "NOR":
			left,right = baf.pop(),baf.pop()
			if left==1 and right==1:
				baf.append(0)
			elif left==1 and right==0:
				baf.append(0)
			elif left==0 and right==1:
				baf.append(0)
			elif left==0 and right==0:
				baf.append(1)
		elif r == "XOR":
			left,right = baf.pop(),baf.pop()
			baf.append(left ^ right)
		elif r == "NOT":
			node = baf.pop()
			if node == 0:
				node = 1
			else:
				node = 0
			baf.append(node)
		elif r == "=":
			ans = baf.pop()
			print ans
		else:
			baf.append(int(r))
	
