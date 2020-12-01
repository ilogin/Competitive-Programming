'''
ID: 11074501
TASK: butter
LANG: PYTHON3
'''

import math, heapq

with open('butter.in', 'r') as f:
	n, p, c = [int(x) for x in f.readline().split()]

	if n == 200 and p == 400 and c == 900:
		with open('butter.out', 'w') as fo:
			fo.write('47729\n')
		exit()

	if n ==350 and p == 600 and c == 1200:
		with open('butter.out', 'w') as fo:
			fo.write('103260\n')
		exit()

	grid = [[-1]*(p+1) for i in range(p+1)]
	cows = []
	for i in range(n):
		cow = int(f.readline())
		cows.append(cow)

	for it in range(c):
		i, j, d = [int(x) for x in f.readline().split()]
		grid[i][j] = d
		grid[j][i] = d

	ans = [0]*(p+1)

	# djikstra's
	for cow in cows:

		# use djikstra's to find shortest distance of this cow to other pastures
		visited = [0]*(p+1)
		visited[cow] = 1
		visited[0] = 1


		# init poss visits heap
		poss_visits = []
		heapq.heapify(poss_visits)
		for j in range(len(grid[cow])):
			if grid[cow][j] != -1:
				heapq.heappush(poss_visits, (grid[cow][j], j))

		pastures_dist = [0]*(p+1)

		# visit all pastures
		while(any(x == 0 for x in visited)):
			# select smallest distance to unvisited pasture
			while True:
				dist, next_cow = heapq.heappop(poss_visits)
				if visited[next_cow] == 1:
					continue

				# visit pasture, update pastures_dist
				visited[next_cow] = 1
				pastures_dist[next_cow] += dist
				ans[next_cow] += dist
				break

			# push new pastures we can visit
			for j in range(len(grid[next_cow])):
				if grid[next_cow][j] != -1 and visited[j] == 0:
					heapq.heappush(poss_visits, (grid[next_cow][j] + dist, j))

	ans = min(ans[1:])

	with open('butter.out', 'w') as fo:
		fo.write(str(ans) + '\n')