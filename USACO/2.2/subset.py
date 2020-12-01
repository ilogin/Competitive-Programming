'''
ID: 11074501
TASK: subset
LANG: PYTHON3
'''

'''
8->6->2->1->3 ---> 8
'''

with open('subset.in', 'r') as f:
	N = int(f.readline())

	cum_sum = 0
	arr = []
	for i in range(1, N+1):
		cum_sum += i
		arr.append(i)

	if (cum_sum % 2 == 1):
		with open('subset.out', 'w') as fo:
			fo.write(str(0))
			fo.write('\n')
		exit()

	cum_sum = int(cum_sum/2)
	dp = [0]*(cum_sum + 1)
	dp[0] = 1

	for i in range(1, N+1):
		for j in range(cum_sum - i, -1, -1):
			if (dp[j] > 0):
				dp[j + i] += dp[j]

	ans = (dp[cum_sum] // 2)

	with open('subset.out', 'w') as fo:
		fo.write(str(ans))
		fo.write('\n')