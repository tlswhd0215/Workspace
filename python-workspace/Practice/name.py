import pickle
f=open("eng.txt",'rt',encoding="UTF8")
eng=[]
while True:
    line=f.readline()
    if not line: break
    eng.append(line)
f.close()
f=open("code.txt",'rt',encoding="UTF8")
code=[]
while True:
    line=f.readline()
    if not line: break
    code.append(line)
f.close()
f=open("1.txt",'rt',encoding="UTF8")
first=[]
while True:
    line=f.readline()
    if not line: break
    first.append(line)
f.close()
f_re=[]

for i in range(len(first)):
    temp=-1
    for j in range(len(eng)):
        if(first[i]==eng[j]):
            if temp!=-1:
                temp=-2
            else:
                temp=j
    if temp==-1:
        f_re.append('NULL')
    elif temp==-2:
        f_re.append('double')
    else:
        f_re.append(code[temp])

f=open('1re.txt','wt')
for i in range(len(f_re)):
    str=f_re[i]
    f.write(str)
f.close()
