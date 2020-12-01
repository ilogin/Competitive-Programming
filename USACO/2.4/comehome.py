'''
ID: 11074501
TASK: comehome
LANG: PYTHON3
'''
import math
import string

with open('comehome.in', 'r') as f:
	P = int(f.readline())

	grid = [ [math.inf]*52 for i in range(52)]

	for i in range(52):
		grid[i][i] = 0

	for i in range(P):
		thing = f.readline().split()
		src = thing[0]
		dest = thing[1]
		dist = int(thing[2])

		if src == dest:
			continue

		src_pos = string.ascii_lowercase.index(src.lower())
		dest_pos = string.ascii_lowercase.index(dest.lower())

		if src.isupper():
			src_pos += 26
		if dest.isupper():
			dest_pos += 26

		grid[src_pos][dest_pos] = min(grid[src_pos][dest_pos], dist)
		grid[dest_pos][src_pos] = grid[src_pos][dest_pos]

	# all pairs shortest path
	for k in range(52):
		for i in range(52):
			for j in range(52):
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j])
				grid[j][i] = grid[i][j]

	min_dist = (0, math.inf)
	# return shortest path from barn 'Z' to some cow ['A', 'Y']
	for i in range(26, 51):
		if grid[51][i] < min_dist[1]:
			min_dist = (i, grid[51][i])

	with open('comehome.out', 'w') as fo:
		fo.write(chr(ord('A') + min_dist[0] - 26) + ' ' + str(min_dist[1]) + '\n')
		pass