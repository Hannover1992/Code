with open('1.csv') as f:
    lines = f.readlines()

#print(lines)
lines = lines[0]
arr = []

index = 0

words = []
temp = ""
for x in lines:
    if x != ' ':
        temp += x
    else:
        print(temp)
        words.append(temp)
        temp = ""

print("words_bevor\n\n")
print(words)
without_duplickate = []
without_duplickate.append(words[0])

found = False
for word in words:
    for word_final in without_duplickate:
        if word_final == word:
            found = True
    if found:
        found = False
        continue
    without_duplickate.append(word)

print("words_after\n\n")

print(word_final)



