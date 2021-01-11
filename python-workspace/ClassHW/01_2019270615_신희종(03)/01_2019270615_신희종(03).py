sum=0
i=0
while(i<1001):
    sum+=1
    i+=1
print(sum)
sum=0
for i in range (1000):
    if(sum>=10000):
        break
    sum+=i
print(sum)
