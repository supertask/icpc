all_str,left_str,right_str = raw_input(),raw_input(),raw_input()
dp = [0 for i in range(len(all_str)+1)]
dp[0] = 1
now_index = 0

if all_str.find(left_str,now_index,now_index+len(left_str)) != -1:
	
