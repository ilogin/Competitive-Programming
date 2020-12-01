'''
ID: 11074501
TASK: holstein
LANG: PYTHON3
'''
import copy

with open('holstein.in', 'r') as f:
	v = int(f.readline())
	vitamins = f.readline().split()
	vitamins = [int(i) for i in vitamins]

	num_feeds = int(f.readline())
	dum_feeds = []
	for i in range(num_feeds):
		dum_feeds.append(f.readline().split())
	feeds = []
	for dum_feed in dum_feeds:
		feeds.append([int(i) for i in dum_feed])

	# [vit1, vit2, ..., vitv], (idx1, idx2, ..., idxj)
	comb = []
	ans = []

	for feed_idx in range(num_feeds):
		comb2 = []
		for prev in comb:
			new = copy.deepcopy(prev)
			new[1].append(feed_idx)
			found_vit = True
			for i in range(v):
				new[0][i] += feeds[feed_idx][i]
				if new[0][i] < vitamins[i]:
					found_vit = False
			if found_vit:
				ans.append(new)
			comb2.append(new)

		found_vit = True
		for i in range(v):
			if feeds[feed_idx][i] < vitamins[i]:
				found_vit = False
		if found_vit:
			ans.append((feeds[feed_idx], [feed_idx]))
		comb2.append((feeds[feed_idx], [feed_idx]))

		for thing in comb2:
			comb.append(thing)

	# print(comb)
	true_ans = list(ans[0][1])
	for thin in ans:
		thing = list(thin[1])
		if len(thing) < len(true_ans) or (len(thing) == len(true_ans) and thing < true_ans):
			true_ans = list(thing)

	true_ans = [str(i+1) for i in true_ans]

	with open('holstein.out', 'w') as fo:
		fo.write(str(len(true_ans)) + ' ' + ' '.join(true_ans))
		fo.write('\n')