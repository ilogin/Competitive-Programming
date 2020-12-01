if len(message) >= 160:
        return [message]

    left_it = 0
    right_it = 0
    content = []
    while(right_it < len(message)):
        if right_it + 160 > len(message):
            right_it = len(message) - 1
        else:
            right_it += 160
        while (message[right_it].isalpha()):
            right_it -= 1
        content.append(message[left_it:right_it] + str(len(suffixes)) + '/' + str(len(message) // 160))
        left_it = right_it
    return segments

    if len(message) <= 160:
        return [message]

    as_list = message.split()
    segments = []
    content = ''
    suffix = [len(segments) + 1, len(message) // 160]
    if len(message) % 160 > 0:
        suffix[1] += 1