'''
ID: 11074501
TASK: inflate
LANG: PYTHON3
'''
import math
with open('inflate.in', 'r') as f:
	ir = f.readline().split()
	M = int(ir[0])
	N = int(ir[1])

	cat = [[0,0]]*N
	for i in range(N):
		# points, minutes
		cat[i] = [int(i) for i in f.readline().split()]

	dp = [-1]*(M+1)
	dp[0] = 0

	for i in range(M+1):
		if i != 0 and i % cat[0][1] == 0:
			dp[i] = int(i / cat[0][1])* cat[0][0]

	for i in range(1, N):
		for j in range(M+1):
			counter = 1
			while(dp[j] > -1 and j + (counter * cat[i][1]) <= M):
				dp[j + (counter * cat[i][1])] = max(dp[j + (counter * cat[i][1])], dp[j] + (counter * cat[i][0]))
				counter += 1

	with open('inflate.out', 'w') as fo:
		fo.write(str(max(dp)) + '\n')