T = input()
for t in range(T):
	player_num = input()
	cards = raw_input()
	cards_len = len(cards)
	modd = 0
	scores = [0 for w in range(player_num)]
	i = 0
	while True:
		if i > cards_len-1:
			break
		if modd >= player_num:
			modd = 0
		if cards[i] == "X":
			i+=1
			while True:
				if i > cards_len-1:
					break
				else:
					if cards[i].isdigit():
						scores[modd] *= int(cards[i])
						break
					i+=1

		elif cards[i] == "D":
			i+=1
			while True:
				if i > cards_len-1:
					break
				else:
					if cards[i].isdigit():
						scores[modd] /= int(cards[i])
						break
					i+=1

		elif cards[i] == "S":
			i+=1
			while True:
				if i > cards_len-1:
					break
				else:
					if cards[i].isdigit():
						scores[modd] -= int(cards[i])
						break
					i+=1
		else:
			scores[modd] += int(cards[i])
		modd+=1
		i+=1
	print max(scores)
