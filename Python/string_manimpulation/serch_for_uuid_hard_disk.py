with open ('xaa') as f:
    text = f.readlines()

    textBlock = []
    for lines in text:
        temp = ''
        last = ''
        for words in lines:
            last = ''
            if words == '\n'and last == '\n':
                textBlock.append(temp)
                temp = ''
                continue

            last = words
            temp += words

    print(textBlock)

