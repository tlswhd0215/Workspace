import matplotlib.pyplot as plt
import math
import numpy as np
iter=np.arange(0,10,0.001)
A=[pow((i+1),3) for i in iter]
B=[pow((i+1),math.log(7,2)) for i in iter]
X=[(i+1)for i in iter]

plt.plot(X,A)
plt.plot(X,B)
plt.ylabel('time')
plt.xlabel('n')
plt.legend(['n^3','n^log7'])
plt.show()