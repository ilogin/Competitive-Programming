'''
ID: 11074501
TASK: fracdec
LANG: PYTHON3
'''

with open('fracdec.in', 'r') as f:
	thing = f.readline().split()
	N = int(thing[0])
	D = int(thing[1])

	integer = N // D
	rem = N - (N // D) * D

	seen_before = []
	quotients = []
	repeat = -1

	while(rem != 0):
		if rem in seen_before:
			repeat = rem
			break

		seen_before.append(rem)
		quotients.append( (rem*10 // D, rem) )
		rem *= 10
		rem = rem - (rem // D)*D

	dec_str = ''

	if repeat > -1:
		for idx in range(len(quotients)-1, -1, -1):
			if quotients[idx][1] == repeat:
				dec_str = ''.join(str(i[0]) for i in quotients[:idx])
				dec_str += '(' + ''.join(str(i[0]) for i in quotients[idx:]) + ')'
				break
	else:
		dec_str = ''.join(str(i[0]) for i in quotients)

	if not dec_str:
		dec_str = '0'

	ans = str(integer) + '.' + dec_str

	with open('fracdec.out', 'w') as fo:
		for i in range(0, len(ans), 76):
			fo.write(ans[i:i+76] + '\n')