'''
ID: 11074501
TASK: maze1
LANG: PYTHON3
'''

import copy

def bfs(i, j, grid):
	h = (len(grid) - 1) // 2
	w = (len(grid[0]) - 1) // 2

	visited = [[0]*((2*w) + 2) for i in range((2*h) + 2)]
	dist_mat = [[-1]*((2*w) + 2) for i in range((2*h) + 2)]

	bfs = []
	bfs.append((i, j, 0))

	while(len(bfs)>0):
		thing = bfs.pop()
		x = thing[0]
		y = thing[1]
		dist = thing[2]

		'''
		if (dist > 500):
			print(x, y, dist)
		'''

		if dist_mat[y][x] > -1:
			continue

		dist_mat[y][x] = dist

		if x - 2 >= 0 and grid[y][x-1] == ' ':
			bfs.insert(0, (x-2, y, dist + 1))

		if y - 2 >= 0 and grid[y-1][x] == ' ':
			bfs.insert(0, (x, y-2, dist + 1))

		if x + 2 <= (2*w) and grid[y][x+1] == ' ':
			bfs.insert(0, (x+2, y, dist + 1))

		if y + 2 <= (2*h) and grid[y+1][x] == ' ':
			bfs.insert(0, (x, y+2, dist + 1))

	return dist_mat


with open('maze1.in', 'r') as f:
	thing = f.readline().split()
	w = int(thing[0])
	h = int(thing[1])

	grid = [['']*((2*w) + 1) for i in range((2*h) + 1)]
	exits = []

	for i in range((2*h) + 1):
		thing = f.readline()[:2*w +1]
		for j in range(len(thing)):
			if thing[j] == ' ' and (i == 0 or i == (2*h) or j == 0 or j == (2*w)):
				exits.append((j, i))
		grid[i] = thing

	entries = []

	for i in range(2):
		entries.append([exits[i][0], exits[i][1]])
		if exits[i][0] == 0:
			entries[i][0] += 1
		if exits[i][0] == 2*w:
			entries[i][0] -= 1
		if exits[i][1] == 0:
			entries[i][1] += 1
		if exits[i][1] == 2*h:
			entries[i][1] -= 1

	if entries[0] == entries[1]:
		mat = bfs(entries[0][0], entries[0][1], grid)
		ans = 0
		for i in range(1, (2*h) + 1, 2):
			for j in range(1, (2*w) + 1, 2):
				ans = max(ans, mat[i][j])
		ans += 1

	else:
		mat_1 = bfs(entries[0][0], entries[0][1], grid)
		mat_2 = bfs(entries[1][0], entries[1][1], grid)
		mat = [[-1]*((2*w) + 2) for i in range((2*h) + 2)]
		ans = 0
		for i in range(1, (2*h) + 1, 2):
			for j in range(1, (2*w) + 1, 2):
				mat[i][j] = min(mat_1[i][j], mat_2[i][j])
				ans = max(ans, mat[i][j])
		ans += 1

	with open('maze1.out', 'w') as fo:
		fo.write(str(ans) + '\n')