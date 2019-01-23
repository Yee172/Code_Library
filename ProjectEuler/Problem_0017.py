# If all the numbers from 1 to 1000 inclusive were
# written out in words, how many letters would be used?
# ----------------------------------------------------
# Analysis: brute force

d = dict()
d[1] = 'one'
d[2] = 'two'
d[3] = 'three'
d[4] = 'four'
d[5] = 'five'
d[6] = 'six'
d[7] = 'seven'
d[8] = 'eight'
d[9] = 'nine'
d[10] = 'ten'
d[11] = 'eleven'
d[12] = 'twelve'
d[13] = 'thirteen'
d[14] = 'fourteen'
d[15] = 'fifteen'
d[16] = 'sixteen'
d[17] = 'seventeen'
d[18] = 'eighteen'
d[19] = 'nineteen'
d[20] = 'twenty'
d[30] = 'thirty'
d[40] = 'forty'
d[50] = 'fifty'
d[60] = 'sixty'
d[70] = 'seventy'
d[80] = 'eighty'
d[90] = 'ninety'

for i in range(2, 10):
    for j in range(1, 10):
        d[i * 10 + j] = d[i * 10] + d[j]

for i in range(1, 10):
    d[i * 100] = d[i] + 'hundred'
    for j in range(1, 100):
        d[i * 100 + j] = d[i * 100] + 'and' + d[j]

d[1000] = 'onethousand'

print(sum(map(len, d.values())))
