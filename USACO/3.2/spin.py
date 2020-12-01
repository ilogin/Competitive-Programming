'''
ID: 11074501
TASK: spin
LANG: PYTHON3
'''

t = 0

def check_light(wheels):
	light = [-1, -1]

	for wheel in wheels:
		# init case
		if light == [-1, -1]:
			light = [wheel[1], wheel[2]]
			continue

		print(i, light)

		# current wheel is totally to right of light
		if (wheel[1] < light[0] and wheel[2] < light[1]):
			return False

		# current wheel is totally to right of light
		if (wheel[1] > light[0] and wheel[2] > light[1]):
			return False

		light = [min(wheel[1], light[0]), min(wheel[2], light[1])]

	return True


def incr(wheel):
	return [wheel[0], (wheel[1] + wheel[0]) % 360, (wheel[2] + wheel[0]) % 360]

with open('spin.in', 'r') as f:
	wheels = []
	for i in range(5):
		ir = [int(x) for x in f.readline().split()]

		for j in range(ir[1]):
			wheels.append([ir[0], ir[2 + 2*j], ir[2+ 2*j] + ir[2 + 2*j + 1]])

	ans = -1
	# all poss simulations
	for i in range(360):
		t = i
		if (check_light(wheels)):
			ans = i
			break

		for wheel in wheels:
			wheel[1] = (wheel[1] + wheel[0]) % 360
			wheel[2] = (wheel[2] + wheel[0]) % 360

		print(wheels)

	with open('spin.out', 'w') as fo:
		format_ans = str(ans) if ans > -1 else 'none'
		fo.write(format_ans + '\n')