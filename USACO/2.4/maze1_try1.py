'''
ID: 11074501
TASK: maze1
LANG: PYTHON3
'''

import copy

def bfs(i, j, grid):
	h = (len(grid) - 1) // 2
	w = (len(grid[0]) - 1) // 2

	if grid[j][i] != ' ':
		return -1

	visited = [[0]*((2*w) + 2) for i in range((2*h) + 2)]

	bfs = []
	bfs.append((i, j, 0))

	max_dist = -1

	while(len(bfs)>0):
		thing = bfs.pop()
		x = thing[0]
		y = thing[1]
		dist = copy.deepcopy(thing[2])

		if visited[y][x] == 1:
			continue

		visited[y][x] = 1

		if x - 1 == 0 and grid[y][x-1] == ' ':
			if max_dist == -1:
				max_dist = dist + 1
			max_dist = min(dist + 1, max_dist)

		if y - 1 == 0 and grid[y-1][x] == ' ':
			if max_dist == -1:
				max_dist = dist + 1
			max_dist = min(dist + 1, max_dist)

		if x + 1 == (2*w) and grid[y][x+1] == ' ':
			if max_dist == -1:
				max_dist = dist + 1
			max_dist = min(dist + 1, max_dist)

		if y + 1 == (2*h) and grid[y+1][x] == ' ':
			if max_dist == -1:
				max_dist = dist + 1
			max_dist = min(dist + 1, max_dist)


		if x - 2 >= 0 and grid[y][x-1] == ' ':
			bfs.append((x-2, y, dist + 1))

		if y - 2 >= 0 and grid[y-1][x] == ' ':
			bfs.append((x, y-2, dist + 1))

		if x + 2 <= (2*w) and grid[y][x+1] == ' ':
			bfs.append((x+2, y, dist + 1))

		if y + 2 <= (2*h) and grid[y+1][x] == ' ':
			bfs.append((x, y+2, dist + 1))

	return max_dist


with open('maze1.in', 'r') as f:
	thing = f.readline().split()
	w = int(thing[0])
	h = int(thing[1])

	grid = [['']*((2*w) + 1) for i in range((2*h) + 1)]
	exits = []

	for i in range((2*h) + 1):
		grid[i] = f.readline()[:2*w +1]

	ans = -1
	for i in range(1, (2*w), 2):
		for j in range(1,(2*h),2):
			result = bfs(i, j, grid)
			if ans == -1:
				ans = result
			ans = max(ans, result)

	with open('maze1.out', 'w') as fo:
		fo.write(str(ans) + '\n')