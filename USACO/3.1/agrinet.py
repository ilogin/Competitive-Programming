'''
ID: 11074501
TASK: agrinet
LANG: PYTHON3
'''
import math
with open('agrinet.in', 'r') as f:
	N = int(f.readline())
	grid = [ [0]*(N) for i in range(N)]

	l = []
	idx = 0
	for line in f:
		for i in line.split():
			l.append(int(i))
		if len(l) == N:
			grid[idx] = l
			idx += 1
			l = []

	# gen MST
	ans = 0
	dist = [math.inf]*(N)
	source = [0]*(N)
	source[0] = -1

	for i in range(N):
		if i == 0:
			continue
		dist[i] = grid[0][i]

	tree_nodes = [0]

	while(len(tree_nodes) < N):

		min_dist = math.inf
		next_node = -1

		for i in range(N):
			if i in tree_nodes:
				continue
			if dist[i] < min_dist:
				min_dist = dist[i]
				next_node = i

		tree_nodes.append(next_node)
		ans += min_dist

		for i in range(N):
			if dist[i] > grid[next_node][i]:
				dist[i] = grid[next_node][i]

	with open('agrinet.out', 'w') as fo:
		fo.write(str(ans) + '\n')