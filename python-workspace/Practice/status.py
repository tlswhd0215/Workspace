f=open("mid.txt",'rt')
mid=[]
while True:
    line=f.readline()
    if not line: break
    mid.append(line)
f.close()
f=open("final.txt",'rt')
final=[]
while True:
    line=f.readline()
    if not line: break
    final.append(line)
f.close()
for i in range(len(mid)):
    mid[i]=mid[i].split('\t')
    mid[i][1]=float(mid[i][1][0:2])
for i in range(len(final)):
    final[i]=final[i].split('\t')
    final[i][1]=float(final[i][1][0:3])
mid.sort(key= lambda mid: mid[0])
final.sort(key= lambda final: final[0])
total={mid[i][0]:mid[i][1]*0.3+final[i][1]*100/171*0.35 for i in range(len(mid))}
s_total=sorted(total.items(),key=lambda item:item[1],reverse=True)
score=[s_total[i][1] for i in range(len(s_total))]
ave=sum(score)/len(score)
f=open('sorted.txt','w')
for i in range(len(s_total)):
    str="%d\t%d\t%.2f\n" %(i+1,int(s_total[i][0]),s_total[i][1])
    f.write(str)
str="average : %.2f" %ave
f.write(str)
f.close()