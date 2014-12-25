import itertools
all_str = raw_input()
don = raw_input()
katu = raw_input()
mini_str = min(len(don),len(katu))
print mini_str
seq = [don,katu]
pat_num = len(all_str)/mini_str
for  in list(itertools.permutations(seq,pat)):
	
