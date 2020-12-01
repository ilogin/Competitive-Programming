'''
ID: 11074501
TASK: castle
LANG: PYTHON3
'''
import copy


def ff(x, y, castle, visited, removal):
	bfs = []
	bfs.append((x, y))

	trav = []
	count = 0
	while(len(bfs) > 0):
		i, j = bfs.pop()
		if (i, j) in trav:
			continue

		trav.append((i, j))
		count += 1
		counter = castle[j][i]

		# wall to south
		if (counter & (1 << 3) == 0):
			bfs.append((i, j+1))

		# wall to east
		if (counter & (1 << 2) == 0):
			bfs.append((i+1, j))

		# wall to north
		if (counter & (1 << 1) == 0):
			bfs.append((i, j-1))

		# wall to west
		if (counter & (1 << 0) == 0):
			bfs.append((i-1, j))

	if removal == False:
		for elem in trav:
			i, j = elem
			visited[elem[1]][elem[0]] = count

	return count


def consider(i, j, castle, visited, max_count, max_wall):
	M = len(castle[0])
	N = len(castle)

	increment = 0

	if visited[j][i] == -1:
		# normal ff:
		room_size = ff(i, j, castle, visited, False)
		increment = 1
	else:
		room_size = visited[j][i]

	# remove wall:
	counter = castle[j][i]
	test = 0
	test_x = 0
	test_y = 0

	# wall to east
	if (counter & (1 << 2) != 0 and i + 1 < M):
		castle[j][i] -= 4
		test = ff(i, j, castle, visited, True)
		if test >= max_count:
			max_count = test
			max_wall = 'E'
			test_x = i
			test_y = j
		castle[j][i] += 4

	# wall to north
	if (counter & (1 << 1) != 0 and j - 1 > 0):
		castle[j][i] -= 2
		test = ff(i, j, castle, visited, True)
		if test >= max_count:
			max_count = test
			max_wall = 'N'
			test_x = i
			test_y = j
		castle[j][i] += 2

	'''
	# wall to west
	if (counter & (1 << 0) != 0 and i - 1 > 0):
		castle[j][i] -= 1
		test = ff(i, j, castle, visited, True)
		if test >= max_count:
			max_count = test
			max_wall = 'W'
			test_x = i
			test_y = j
		castle[j][i] += 1

	# wall to south
	if (counter & (1 << 3) != 0 and j + 1 < N):
		castle[j][i] -= 8
		test = ff(i, j, castle, visited, True)
		if test >= max_count:
			max_count = test
			max_wall = 'S'
			test_x = i
			test_y = j
		castle[j][i] += 8
	'''

	return increment, room_size, test, max_wall, test_x, test_y
##############
#a b c # d e #
#f g h # i j #
# ###  #     #
#k#l#m # n o #
### ######   #
#p q r s # t #
#u v w x # z #
##############

with open('castle.in', 'r') as f:
	thing = f.readline().split()
	M = int(thing[0])
	N = int(thing[1])

	castle = []
	for i in range(N):
		thing = f.readline().split()
		castle.append([int(i) for i in thing])

	visited = [[-1]*M for i in range(N)]

	num_rooms = 0
	max_room_size = 0
	max_count = 0
	max_wall = ''
	ans_x = 0
	ans_y = 0

	for x in range(M-1, -1, -1):
		for y in range(N):
			inc, room_size, test_count, test_wall, test_x, test_y = consider(x, y, castle, visited, max_count, max_wall)
			num_rooms += inc
			max_room_size = max(max_room_size, room_size)
			if test_count > max_count or (test_count == max_count and test_x < ans_x) or (test_count == max_count and test_x == ans_x and test_y > ans_y):
				max_count = test_count
				max_wall = test_wall
				ans_x = test_x
				ans_y = test_y

	with open('castle.out', 'w') as fo:
		fo.write(str(num_rooms))
		fo.write('\n')
		fo.write(str(max_room_size))
		fo.write('\n')
		fo.write(str(max_count))
		fo.write('\n')
		fo.write(str(ans_y + 1) + ' ' + str(ans_x + 1) + ' ' + str(max_wall))
		fo.write('\n')