T=input()
for t in range(T):
	N = input()
	if N % 15 == 0:
		print "FizzBuzz"
	elif N % 3 == 0:
		print "Fizz"
	elif N % 5 == 0:
		print "Buzz"
	else:
		print N
