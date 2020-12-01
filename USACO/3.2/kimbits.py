'''
ID: 11074501
TASK: kimbits
LANG: PYTHON3
'''

# n := size of set
# m := num 1's 
def sizeofset(n, m):
	if (n == 0 and m == 1) or m == 0:
		return 1

	print(n, m, sizeofset(n-1, m) + sizeofset(n-1, m-1))
	return sizeofset(n-1, m) + sizeofset(n-1, m-1)

with open('kimbits.in', 'r') as f:
	n, l, i = [int(x) for x in f.readline().split()]

	print(sizeofset(5,3))

	ans = '1'

	with open('kimbits.out', 'w') as fo:
		fo.write(ans + '\n')