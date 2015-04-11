h = range(1,25+1)
line=""
for i in h:
	if i % 15 == 0:
		line+="FizzBuzz"
	elif i % 3 == 0:
		line+="Fizz"
	elif i % 5 == 0:
		line+="Buzz"
	else:
		line+=str(i)
print line[22:25+1]
print line
print len(line)
