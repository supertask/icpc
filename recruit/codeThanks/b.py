a_list = input(),input(),input()
ans = []
ans.append(sum(a_list))
ans.append((a_list[0]+a_list[1])*a_list[2])
ans.append((a_list[0]*a_list[1])+a_list[2])
ans.append((a_list[0]*a_list[1])*a_list[2])
print max(ans)
