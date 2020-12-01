'''
ID: 11074501
TASK: fact4
LANG: PYTHON3
'''
import math
with open('fact4.in', 'r') as f:
	N = int(f.readline())

	fact = ['1']

	'''

	fact = 1
	for i in range(2, N+1):
		fact *= i
		print(i, fact)

	exit()
	'''

	for i in range(2, N+1):
		print(fact)
		last = int(fact[-1])
		new = str(last * i)

		j = 1
		while(new[-j] == '0'):
			j += 1

		if -1*j + 1 != 0:
			fact.append(new[-(j + len(str(i))-1):-1*j+1])
		else:
			fact.append(new[-(j + len(str(i))-1):])

	with open('fact4.out', 'w') as fo:
		fo.write(str(fact[-1][-1]) + '\n')