'''
ID: 11074501
TASK: runround
LANG: PYTHON3
'''

with open('runround.in', 'r') as f:
	N = f.readline()
	n = int(N)
	runround = False

	while(runround == False):
		n += 1
		N = str(n)

		if (any(char == '0' for char in N)):
			N = N.replace('0', '1')

		n = int(N)

		ptr = 0
		digit_count = [0]*(10)
		freq_count = [0]*len(N)

		while(all(freq_count) == False):
			freq_count[ptr] += 1
			digit_count[int(N[ptr])] += 1
			if digit_count[int(N[ptr])] > 1:
				break
			ptr += int(N[ptr])
			ptr %= len(N)

		if digit_count[int(N[ptr])] > 1:
			continue

		runround = (ptr == 0 and all(freq == 1 for freq in freq_count))

	with open('runround.out', 'w') as fo:
		fo.write(N)
		fo.write('\n')