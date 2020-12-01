'''
ID: 11074501
TASK: ttwo
LANG: PYTHON3
'''

def check(grid, f_idx):

	visited = [[0]*(10) for i in range(10)]

	bfs = []
	bfs.append(f_idx)

	while(len(bfs)>0):
		elem = bfs.pop()
		x = elem[0]
		y = elem[1]

		if grid[y][x] == 'C':
			return True

		if visited[y][x] == 1:
			continue

		visited[y][x] = 1

		if y-1 >= 0 and grid[y-1][x] != '*':
			bfs.append((x, y-1))

		if x-1 >= 0 and grid[y][x-1] != '*':
			bfs.append((x-1, y))

		if y+1 < 10 and grid[y+1][x] != '*':
			bfs.append((x, y+1))

		if x+1 < 10 and grid[y][x+1] != '*':
			bfs.append((x+1, y))

	return False

with open('ttwo.in', 'r') as f:
	grid = [['']*(11) for i in range(10)]
	f_idx = (0, 0)
	c_idx = (0, 0)

	for i in range(10):
		grid[i] = f.readline().rstrip()
		for x in range((10)):
			if grid[i][x] == 'F':
				f_idx = (x, i)
			if grid[i][x] == 'C':
				c_idx = (x, i)
	
	if (check(grid, f_idx) == False):
		with open('ttwo.out', 'w') as fo:
			fo.write('0\n')
		exit()

	f_dir = 'N'
	c_dir = 'N'
	itr = {'N': (0, -1), 'E': (1, 0), 'S': (0, 1), 'W': (-1, 0)}
	nxt = {'N': 'E', 'E': 'S', 'S': 'W', 'W': 'N'}

	steps = 0

	while(f_idx != c_idx):
		f_itr = itr[f_dir]
		f_x_nxt = f_idx[0] + f_itr[0]
		f_y_nxt = f_idx[1] + f_itr[1]

		if f_x_nxt < 10 and f_x_nxt >= 0 and f_y_nxt < 10 and f_y_nxt >= 0 and grid[f_y_nxt][f_x_nxt] != '*':
			f_idx = (f_x_nxt, f_y_nxt)
		else:
			f_dir = nxt[f_dir]


		c_itr = itr[c_dir]
		c_x_nxt = c_idx[0] + c_itr[0]
		c_y_nxt = c_idx[1] + c_itr[1]

		if c_x_nxt < 10 and c_x_nxt >= 0 and c_y_nxt < 10 and c_y_nxt >= 0 and grid[c_y_nxt][c_x_nxt] != '*':
			c_idx = (c_x_nxt, c_y_nxt)
		else:
			c_dir = nxt[c_dir]

		steps += 1

	with open('ttwo.out', 'w') as fo:
		fo.write(str(steps) + '\n')