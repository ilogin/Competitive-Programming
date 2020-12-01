'''
ID: 11074501
TASK: stamps
LANG: PYTHON3
'''
import math
with open('stamps.in', 'r') as f:
	ir = f.readline().split()
	K = int(ir[0])
	N = int(ir[1])

	stamps = []
	for i in range(N):
		for i in f.readline().split():
			stamps.append(int(i))
	stamps.sort()

	postages = [math.inf]*(200*10000 + 1)
	postages[0] = 0

	for i in range(N):
		for j in range(0, 200*10000):
			if postages[j] < K:
				postages[j + stamps[i]] = min(postages[j + stamps[i]], postages[j] + 1)

	ans = 0
	while(postages[ans] <= K):
		ans += 1

	with open('stamps.out', 'w') as fo:
		fo.write(str(ans-1) + '\n')