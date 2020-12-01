'''
ID: 11074501
TASK: lamps
LANG: PYTHON3
'''

with open('lamps.in', 'r') as f:
	N = int(f.readline())
	C = int(f.readline())

	on_lamps = f.readline()
	on_lamps = on_lamps.split()[:-1]

	off_lamps = f.readline()
	off_lamps = off_lamps.split()[:-1]

	xor = 0
	even = 0
	odd = 0
	fx = 0

	state = 0
	for i in range(1, N+1):
		state ^= 1 << i
		xor ^= 1 << i
		if i % 2 == 0:
			even ^= 1 << i
		else:
			odd ^= 1 << i

	i = 0
	while ((3*i + 1) <= (N)):
		fx ^= 1 << ((3*i) + 1)
		i+= 1

	comb = [state]
	for i in range(C):
		new = []
		for elem in comb:
			new.append(elem ^ xor)
			new.append(elem ^ odd)
			new.append(elem ^ even)
			new.append(elem ^ fx)
		for elem in new:
			if elem not in comb:
				comb.append(elem)

	ans = []

	for elem in comb:
		valid = True
		for lamp in on_lamps:
			if (1 << int(lamp)) & elem == 0:
				valid = False
				break

			if valid == False:
				break

		for lamp in off_lamps:
			if (1 << int(lamp)) & elem != 0:
				valid = False
				break

		if valid:
			thing = bin(elem)[2:-1][::-1]
			while(len(thing) < N):
				thing += '0'
			ans.append(thing)

	ans = sorted(ans)
	if len(ans) == 0:
		ans.append('IMPOSSIBLE')
	print(ans)

	with open('lamps.out', 'w') as fo:
		if ans[0] == 'IMPOSSIBLE':
			fo.write('IMPOSSIBLE' + '\n')

		else:
			for elem in ans:
				fo.write(elem.zfill(N) + '\n')