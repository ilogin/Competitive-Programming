'''
ID: 11074501
TASK: prefix
LANG: PYTHON3
'''

class Node():
	def __init__(self, val = None, children = []):
		self.val = val
		self.children = children

class prefix_trie():
	def __init__(self):
		self.root = Node()

	def dfs(self, it):
		if it.val == '$':
			return ['']

		r = []
		for child in it.children:

			result = self.dfs(child)
			for elem in result:
				r.append( (it.val + elem) if it.val != None else elem)
		return r

	def extend(self, word):

		# walk tree, adding children as needed + delimiters
		it = self.root
		for letter in word:
			added = False
			for child in it.children:
				if child.val == letter:
					it = child
					added = True

			if added == False:
				new = Node(letter, [])
				it.children.append(new)
				it = new

		if len(it.children) == 0:
			end = Node('$', [])
			it.children.append(end)



	def search(self, query):

		it = self.root
		idx = 0
		success_idx = -1

		while(idx < len(query)):
			print('query[idx]: ', query[idx])
			print('query: ', query)
			print('it.val: ', it.val)

			if any(child.val == query[idx] for child in it.children) == False:
				return False, success_idx, False

			for child in it.children:
				if child.val == query[idx]:
					it = child

			# pick best option
			search = self.dfs(it)
			match = ''

			for elem in search:
				print(query[idx:idx + len(elem)], elem)
				if query[idx:idx + len(elem)] == elem and len(elem) > len(match):
					match = elem

			if not match:
				return False, success_idx, False

			idx += len(match)
			it = self.root
			success_idx = idx - 1

			print('success_idx: ', success_idx)
			print('\n\n')

			# request more
			if idx + 10 > len(query) - 1:
				return True, success_idx, True

		return True, len(query) - 1, False




with open('prefix.in', 'r') as f:
	read = f.readline()
	trie = prefix_trie()

	while (read.find(".") == -1):
		for primitive in read.split():
			trie.extend(primitive)
		read = f.readline()

	for elem in trie.dfs(trie.root):
		print(elem)

	exit()

	running_query = ""
	running_idx = 0
	request = False

	for line in f:
		running_query += line.strip()
		query_result, last_idx, request = trie.search(running_query)
		if request:
			running_query = running_query[last_idx+1:]
		print('line last_idx: ', last_idx)
		running_idx += last_idx + 1
		if query_result == False:
			break

	while request:
		query_result, last_idx, request = trie.search(running_query)
		print('request last_idx: ', last_idx)
		running_idx += last_idx + 1
		running_query = running_query[last_idx+1:]

	with open('prefix.out', 'w') as fo:
		fo.write(str(running_idx) + '\n')