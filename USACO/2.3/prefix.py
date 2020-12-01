'''
ID: 11074501
TASK: prefix
LANG: PYTHON3
'''

with open('prefix.in', 'r') as f:
	primitives = []

	read = f.readline()

	while (read.find(".") == -1):
		for primitive in read.split():
			primitives.append(primitive)
		read = f.readline()

	primitives.sort()

	whole_thing = ""
	for line in f:
		whole_thing += line.rstrip()

	dp = [0]*(len(whole_thing))
	dp[0] = 1
	ans = 0
	zero_count = 0

	for i in range(len(whole_thing)):
		for primitive in primitives:
			if primitive > whole_thing[i:i+len(primitive)]:
				break
			
			if dp[i] > 0 and whole_thing[i:i+len(primitive)] == primitive:
				if i + len(primitive) >= len(dp):
					ans = len(dp)
					break
				dp[i+len(primitive)] = 1
				ans = i+len(primitive)

	with open('prefix.out', 'w') as fo:
		fo.write(str(ans) + '\n')