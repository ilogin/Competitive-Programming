'''
ID: 11074501
TASK: money
LANG: PYTHON3
'''

with open('money.in', 'r') as f:
	thing = f.readline().split()
	V = int(thing[0])
	N = int(thing[1])

	coins = []
	for line in f:
		thing = line.split()
		for i in thing:
			coins.append(int(i))

	dp = [[0]*(N+1) for i in range(V)]

	for i in range(0,N+1,coins[0]):
		if i % coins[0] == 0:
			dp[0][i] = 1

	for i in range(1, V):
		for j in range(0, N+1):
			dp[i][j] = dp[i-1][j]

		for j in range(0, N+1):
			itself = 1

			while (j + (itself * coins[i])) <= N:
				if dp[i-1][j] > 0:
					dp[i][j + (itself * coins[i])] += dp[i-1][j]
				itself += 1
	'''
	for idx in range(V):
		print(coins[idx], [(j, dp[idx][j]) for j in range(len(dp[idx]))])
	print(dp[V-1][N])
	'''

	with open('money.out', 'w') as fo:
		fo.write(str(dp[V-1][N]) + '\n')