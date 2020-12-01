'''
ID: 11074501
TASK: preface
LANG: PYTHON3
'''
import copy

units = {1:'I', 4: 'IV', 5:'V', 9: 'IX', 10:'X', 40: 'XL', 50:'L', 90: 'XC', 100:'C', 400: 'CD', 500:'D', 900: 'CM', 1000:'M'}
units = sorted(units.items(), key=lambda x:x[0], reverse=True)

with open('preface.in', 'r') as f:
	n = int(f.readline())

	freq_count = {'I':0, 'V':0, 'X':0, 'L':0, 'C':0, 'D':0, 'M':0}

	for i in range(1, n+1):
		counter = copy.deepcopy(i)

		j = 0
		while(counter > 0):
			if units[j][0] <= counter:
				counter -= units[j][0]
				for char in units[j][1]:
					freq_count[char] += 1
			if units[j][0] > counter:
				j += 1

	with open('preface.out', 'w') as fo:
		for key, value in freq_count.items():
			if value != 0:
				fo.write(key + " " + str(value) + '\n')