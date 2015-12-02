for t in range(input()): print (lambda N=input(): (lambda N=N, F=(lambda N=N: ("%s%s" % ("" if N%3 else"Fize","" if N%5 else "Buzz")))(), P="Case #%s:\n"%(t+1): P+F if F else P+str(N))()) ()
