'''
ID: 11074501
TASK: concom
LANG: PYTHON3
'''


with open('concom.in', 'r') as f:
	n = int(f.readline())

	portfolio = {}
	owns = {}

	for a in range(n):
		thing = f.readline().split()
		i = int(thing[0])
		j = int(thing[1])
		p = int(thing[2])

		if i not in portfolio:
			portfolio[i] = {}

		portfolio[i][j] = p
		if portfolio[i][j] > 50:
			if i not in owns:
				owns[i] = []
			owns[i].append(j)


	for c, o in owns.items():
		bfs = [c]
		visited = {}

		all_owns = []
		while(len(bfs) > 0):
			consider = bfs.pop()
			if consider in visited:
				continue
			visited[consider] = 1

			if consider in owns:
				for children in owns[consider]:
					bfs.append(children)
					if children not in all_owns:
						all_owns.append(children)
		owns[c] = all_owns

	for company, port in portfolio.items():
		updates = {}

		if company in owns:

			for subseq in owns[company]:

				if subseq not in portfolio:
					continue

				for new_company, new_shares in portfolio[subseq].items():

					if new_company not in port:
						port[new_company] = 0
					port[new_company] += new_shares

					if port[new_company] > 50 and new_company not in owns[company]:
						owns[company].append(new_company)

	ans = []
	for company, port in portfolio.items():
		for k, v in port.items():
			if v > 50:
				if k!=company:
					ans.append((company, k))

	ans.sort()

	with open('concom.out', 'w') as fo:
		for elem in ans:
			fo.write(str(elem[0]) + ' ' + str(elem[1]) + '\n')