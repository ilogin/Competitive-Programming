'''
ID: 11074501
TASK: hamming
LANG: PYTHON3
'''
import copy

def ham_dist(i, j):
	return bin(i^j).count('1')



with open('hamming.in', 'r') as f:
	thing = f.readline().split()
	N = int(thing[0])
	B = int(thing[1])
	D = int(thing[2])

	ans = [0]
	for i in range(1, 2**B):
		# print(i)

		found = True
		for j in ans:
			if ham_dist(i, j) < D:
				found = False
				break

		if found:
			ans.append(i)

		if len(ans) == N:
			break

	with open('hamming.out', 'w') as fo:
		for i in range(1, N+1):
			fo.write(str(ans[i-1]))
			if i % 10 == 0 and i != N:
				fo.write('\n')
			elif i != N:
				fo.write(' ')
		fo.write('\n')