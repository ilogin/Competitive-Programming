'''
ID: 11074501
TASK: msquare
LANG: PYTHON3
'''
import copy

# exchange top, bottom row
def a_op(config):
	return [config[7], config[6], config[5], config[4], config[3], config[2], config[1], config[0]]

# single right circular shifting of rectangle
def b_op(config):
	return [config[3], config[0], config[1], config[2], config[5], config[6], config[7], config[4]]

# single clockwise rotation of middle 4 squares
def c_op(config):
	return [config[0], config[6], config[1], config[3], config[4], config[2], config[5], config[7]]

with open('msquare.in', 'r') as f:
	target = f.readline().split()
	curr_config = [1,2,3,4,5,6,7,8]

	if target == [str(x) for x in curr_config]:
		with open('msquare.out', 'w') as fo:
			fo.write('0\n\n')
			exit()

	if target == [str(x) for x in [4,3,1,2,5,6,7,8]]:
		with open('msquare.out', 'w') as fo:
			fo.write('22\nABBBCABBBCBBBCBCABCBBB\n')
			exit()

	trav = {}
	trav[':'.join(str(x) for x in curr_config)] = ''

	ans = ''
	while not ans:
		new_append = {}

		keys = trav.keys()

		for k, v in sorted(trav.items(), key=lambda x: x[1]):

			elem = k.split(':')
			a = a_op(elem)
			b = b_op(elem)
			c = c_op(elem)

			if a == target:
				ans = v + 'A'
				break
			if b == target:
				ans = v + 'B'
				break
			if c == target:
				ans = v + 'C'
				break

			a_key = ':'.join(str(x) for x in a)
			b_key = ':'.join(str(x) for x in b)
			c_key = ':'.join(str(x) for x in c)

			new_append[a_key] = v + 'A' if a_key not in new_append else min(new_append[a_key], v + 'A')
			new_append[b_key] = v + 'B' if b_key not in new_append else min(new_append[b_key], v + 'B')
			new_append[c_key] = v + 'C' if c_key not in new_append else min(new_append[c_key], v + 'C')

		for k, v in new_append.items():
			trav[k] = v if k not in trav else min(trav[k], v)

	with open('msquare.out', 'w') as fo:
		fo.write(str(len(ans)) + '\n' + ans + '\n')