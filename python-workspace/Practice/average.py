f=open("score.txt",'rt')

chscore=[]
while True:
    line=f.readline()
    if not line: break
    chscore.append(line)
f.close()
for i in range(len(chscore)):
    chscore[i]=chscore[i].split('\t')
    chscore[i][1]=float(chscore[i][1][0:4])
score={chscore[i][0]:chscore[i][1] for i in range(len(chscore))}
s_score=sorted(score.items(),key=lambda item: item[1],reverse=True)
iscore=[s_score[i][1] for i in range(len(s_score))]
ave=sum(iscore)/len(iscore)
f=open('sorted.txt','w')
for i in range(len(s_score)):
    str="%d\t%d\t%f\n" %(i+1,int(s_score[i][0]),s_score[i][1])
    f.write(str)
str="average : %f" %ave
f.write(str)
f.close()
