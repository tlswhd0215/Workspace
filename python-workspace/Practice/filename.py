f=open("filename.txt",'rt')
file=[]
while True:
    line=f.readline()
    if not line: break
    file.append(line)
f.close()
f=open("1.txt",'rt')
first=[]
while True:
    line=f.readline()
    if not line: break
    first.append(line)
f.close()
for i in range(len(first)):
    first[i]=first[i][0:len(first[i])-1]
print(first)
f_re=[]
for i in range(len(first)):
    temp=-1
    for j in range(len(file)):
        if(first[i] in file[j]):
            if temp!=-1:
                temp=-2
            else:
                temp=j
    if temp==-1:
        f_re.append('NULL\n')
    elif temp==-2:
        f_re.append('double\n')
    else:
        f_re.append(file[temp])
f=open('1re.txt','wt')
for i in range(len(f_re)):
    str=f_re[i]
    f.write(str)
f.close()