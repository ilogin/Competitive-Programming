'''
ID: 11074501
TASK: cowtour
LANG: PYTHON3
'''
import math

def dist_form(p1, p2):
	p1_x = p1[0]
	p1_y = p1[1]
	p2_x = p2[0]
	p2_y = p2[1]

	return math.sqrt( (abs(p1_x - p2_x)**2) + (abs(p1_y - p2_y)**2))

def bfs(grid, pastures):
	bfs = []
	bfs.insert(0, 0)

	visited = []
	ans = []
	while(len(bfs) > 0):
		elem = bfs.pop()
		if elem in visited:
			continue

		visited.append(elem)
		for idx in range(len(grid[elem])):
			if grid[elem][idx] == 1:
				bfs.insert(0, idx)

	ans.append(visited)

	for idx in range(len(pastures)):
		if idx not in visited:
			bfs.append(idx)
			break

	visited = []

	while(len(bfs) > 0):
		elem = bfs.pop()
		if elem in visited:
			continue

		visited.append(elem)
		for idx in range(len(grid[elem])):
			if grid[elem][idx] == 1:
				bfs.insert(0, idx)

	ans.append(visited)

	return ans

def fw(N, grid, pastures, sets):
	dist = [ [math.inf]*(N) for i in range(N)]

	for i in range(N):
		for j in range(N):
			if grid[j][i] == 0:
				continue
			length = dist_form(pastures[i], pastures[j])
			dist[i][j] = length
			dist[j][i] = length

	for k in range(N):
		for i in range(N):
			for j in range(N):
				if i == j or dist[k][i] == math.inf or dist[j][k] == math.inf:
					continue
				dist[j][i] = min(dist[k][i] + dist[j][k], dist[j][i])
				dist[i][j] = dist[j][i]

	return dist

with open('cowtour.in', 'r') as f:
	N = int(f.readline())

	pastures = []
	for i in range(N):
		thing = f.readline().rstrip().split()
		pastures.append((int(thing[0]), int(thing[1])))

	grid = []
	for i in range(N):
		thing = f.readline().rstrip()
		grid.append([int(i) for i in thing])

	sets = bfs(grid, pastures)

	dist_mat = fw(N, grid, pastures, sets)
	furthest = []

	for i in range(N):
		furthest_from_i = (0, 0)
		for j in range(N):
			if dist_mat[i][j] != math.inf and dist_mat[i][j] > furthest_from_i[0]:
				furthest_from_i = (dist_mat[i][j], j)
		furthest.append(furthest_from_i)


	max_dist = math.inf

	for i in sets[0]:
		for j in sets[1]:
			bridge = dist_form(pastures[i], pastures[j])
			# furthest from i + bridge + furthest from j

			curr_dist = bridge + furthest[i][0] + furthest[j][0]

			max_dist = min(max_dist, curr_dist)

	print(max_dist)

	form_ans = round(max_dist, 6)

	with open('cowtour.out', 'w') as fo:
		fo.write(format(form_ans, '0.6f') + '\n')
		pass