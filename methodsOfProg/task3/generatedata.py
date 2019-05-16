import random
import string
import sys

def gFIO():
    min_char = 4
    max_char = 10
    allchar = string.ascii_letters

    return  str("".join(random.choice(allchar) for x in range(random.randint(min_char,max_char))))


f = open('listec.txt','w+')
for i in range(int(sys.argv[1])):
    s= str(gFIO())+' '+str(gFIO())+' '+str(gFIO())+','+str(gFIO())+','+str(random.randint(1,10000))+','+str(random.randint(1,500))+','+str(random.randint(1,31))+'.'+str(random.randint(1,12))+'.'+str(random.randint(1,3000))+'\n'
    f.write(s)
f.close()
print('fd', (gFIO()))

