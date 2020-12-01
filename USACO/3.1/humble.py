'''
ID: 11074501
TASK: humble
LANG: PYTHON3
'''
import math
with open('humble.in', 'r') as f:
	ir = f.readline().split()
	K = int(ir[0])
	N = int(ir[1])

	primes = [int(i) for i in f.readline().split()]
	humbles = [1]
	p_idx = [0]*(N)

	while(len(humbles) <= N):
		next_humble = math.inf
		last = humbles[-1]
		min_p = -1

		for k in range(K):
			while(primes[k] * humbles[p_idx[k]] <= last):
				p_idx[k] += 1

			if (primes[k] * humbles[p_idx[k]] < next_humble):
				next_humble = primes[k] * humbles[p_idx[k]]
				min_p = k

		humbles.append(next_humble)
		p_idx[min_p] += 1

	with open('humble.out', 'w') as fo:
		fo.write(str(humbles[-1]) + '\n')