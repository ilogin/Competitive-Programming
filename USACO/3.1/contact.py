'''
ID: 11074501
TASK: contact
LANG: PYTHON3
'''
import math
with open('contact.in', 'r') as f:
	ir = f.readline().split()
	A = int(ir[0])
	B = int(ir[1])
	N = int(ir[2])

	ref = ''

	for line in f:
		ref += line.strip()

	freq = {}
	for idx in range(len(ref)):
		for i in range(A, B+1):
			if i + idx <= len(ref):
				if ref[idx:idx+i] not in freq:
					freq[ref[idx:idx+i]] = 0
				freq[ref[idx:idx+i]] += 1

	sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse = True)
	ans = {}

	count = 0
	for elem in sorted_freq:
		key = elem[0]
		value = elem[1]
		if count >= N and value not in ans:
			continue

		if value not in ans:
			ans[value] = []
			count += 1

		ans[value].append(key)
		ans[value].sort()
		ans[value].sort(key=len)

	with open('contact.out', 'w') as fo:
		for key, value in ans.items():
			fo.write(str(key) + '\n')
			for i in range(0, len(value), 6):
				fo.write(' '.join(value[i:i+6]) + '\n')