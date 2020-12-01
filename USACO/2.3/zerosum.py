'''
ID: 11074501
TASK: zerosum
LANG: PYTHON3
'''

# 1 2 3 4
# 

import copy

def recurse(N, idx, counter, prev, ans):
	# print(prev)
	if idx == N:
		if counter == 0:
			ans.append(copy.deepcopy(prev))
			return 1
		return 0

	if idx == 1:
		thing = 0
		prev.append('|')
		thing += recurse(N, idx+1, 12, prev, ans)
		del prev[-1]

		prev.append('+')
		thing += recurse(N, idx+1, 1 + 2, prev, ans)
		del prev[-1]

		prev.append('-')
		thing += recurse(N, idx+1, 1 - 2, prev, ans)
		del prev[-1]
		return thing

	prev.append('|')
	thing = 0
	if prev[-2] == '+':
		thing += recurse(N, idx+1, counter - idx + (idx*10) + idx + 1, prev, ans)
	if prev[-2] == '-':
		thing += recurse(N, idx+1, counter + idx -(idx*10) - idx - 1, prev, ans)
	del prev[-1]

	prev.append('+')
	thing += recurse(N, idx+1, counter + idx + 1, prev, ans)
	del prev[-1]

	prev.append('-')
	thing += recurse(N, idx+1, counter - (idx+1), prev, ans)
	del prev[-1]

	return thing

with open('zerosum.in', 'r') as f:
	N = int(f.readline())
	ans = []
	results = recurse(N, 1, 0, [''], ans)

	with open('zerosum.out', 'w') as fo:
		for i in range(len(ans)):
			for num in range(1, N+1):
				fo.write(str(num))
				if num < N:
					fo.write(ans[i][num] if ans[i][num] != '|' else ' ')
			fo.write('\n')