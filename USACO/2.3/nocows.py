'''
ID: 11074501
TASK: nocows
LANG: PYTHON3
'''
import math
import copy
import operator as op
from functools import reduce

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2

def recurse(N, K, tree, num_nodes, level, node_pos):
	poss = 0

	if node_pos >= len(tree[level]):
		node_pos = 0
		level += 1

	for l in range(level, K):
		if l == K - 1:
			if num_nodes == N and any(tree[K-1][i] == 1 for i in range(len(tree[K-1]))):
				poss += 1
				print(tree)
			continue

		for idx in range(node_pos, len(tree[l])):
			if tree[l][idx] == 0:
				continue

			tree[l+1][2*idx] = 1
			tree[l+1][(2*idx) + 1] = 1

			poss += recurse(N, K, tree, num_nodes + 2, l, idx + 1)

			tree[l+1][2*idx] = 0
			tree[l+1][(2*idx) + 1] = 0

		node_pos = 0

	return poss

def dp(N, K):
	dp = [[0]*(N+1) for i in range(K)]
	dp[0][1] = 1
	dp[1][3] = 1

	for i in range(2, K):
		for j in range(N+1):

			if dp[i-1][j] > 0:
				exposed_leaves = (j//2)+1
				for k in range(1, exposed_leaves+1):
					if j + (2*k) <= N:
						print(j, 'exposed_leaves: ', exposed_leaves, 'k: ', k)
						print('poss: ', ncr(exposed_leaves, k))
						dp[i][j+ (2*k)] += ncr(exposed_leaves, k)*(dp[i-1][j])

		for row in dp:
			print(i+1, [(idx, row[idx]) for idx in range(len(row))])

		print('\n')

	return dp[K-1][N]

with open('nocows.in', 'r') as f:
	thing = (f.readline()).split()
	N = int(thing[0])
	K = int(thing[1])
	'''
	dp = [0] * (N+1)
	dp[0] = 1

	tree = []

	for i in range(K):
		tree.append([0] * 2**i)

	tree[0][0] = 1
	ans = recurse(N, K, tree, 1, 0, 0)
	'''

	ans = dp(N, K)
	print(ans)

	with open('nocows.out', 'w') as fo:
		fo.write(str(ans) + '\n')