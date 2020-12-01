'''
ID: 11074501
TASK: ratios
LANG: PYTHON3
'''

with open('ratios.in', 'r') as f:	
	ideal = [int(x) for x in f.readline().split()]

	feeds = []
	for i in range(3):
		feeds.append([int(x) for x in f.readline().split()])

	smallest_mult = 101

	comb = [0, 0, 0]
	for i in range(1, 101):
		comb[0] += feeds[0][0]
		comb[1] += feeds[0][1]
		comb[2] += feeds[0][2]

		for j in range(1, 101):
			comb[0] += feeds[1][0]
			comb[1] += feeds[1][1]
			comb[2] += feeds[1][2]

			for k in range(1, 101):

				c0 = comb[0] + k*feeds[2][0]
				mult = c0 / ideal[0]
				if (mult < 1 or not mult < smallest_mult):
					continue

				c1 = comb[1] + k*feeds[2][1]
				if (mult*ideal[1] != c1):
					continue

				c2 = comb[2] + k*feeds[2][2]
				if (mult*ideal[2] != c2):
					continue

				smallest_mult = min(smallest_mult, mult)
				ans = [i, j, k]
				break

	with open('ratios.out', 'w') as fo:
		if smallest_mult == 101:
			fo.write('NONE\n')
			exit()

		str_ans = ' '.join(str(x) for x in ans) + ' ' + str(int(smallest_mult))
		fo.write(str_ans + '\n')