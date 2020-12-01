'''
ID: 11074501
TASK: kimbits
LANG: PYTHON3
'''
import math
with open('kimbits.in', 'r') as f:
	ir = f.readline().split()
	N = int(ir[0])
	L = int(ir[1])
	I = int(ir[2])

	idx = 0
	counter = 1

	while(counter < I):
		idx += 1
		ones = bin(idx).count('1')

		if ones > L:
			continue
		else:
			counter += 1

	dec = "{0:b}".format(idx)
	leading = "0"*(N-len(dec))
	ans = leading + dec

	with open('kimbits.out', 'w') as fo:
		fo.write(ans + '\n')