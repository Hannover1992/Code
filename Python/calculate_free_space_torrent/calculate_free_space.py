import numpy as np

f= open("free_space_torrent.txt",mode='r',encoding='utf8', newline='\r\n')

# use enumerate to show that second line is read as a whole
arr = []
for x in f:
    word = ''
    for y in x:
        if y == ',':
            y = '.'
            
        if y == '%':
            y = ' '

        if y == '\t' or y == '\n' or y == ' ':
            if len(word) > 0:
                arr.append(word)
            word = ''
            continue

        word = word + str(y)



final = []
for x in arr:
    if x != 'GIB' and x != 'GiB':
        final.append(float(x))






ar = np.array(final)

ar.shape = (int(58/2), 2, 1)



ar[:,1] = 1.0 -  (ar[:,1] / 100)

new_column =np.multiply(ar[:,1], ar[:,0])

result = np.sum(new_column)

print(result)
