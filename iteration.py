import numpy as np

def iteration(matrix_A,matrix_B):
    n=matrix_A.shape[0]
    C=np.zeros((n*n),dtype=np.longlong).reshape(n,n)
    for i in range (n):
        for j in range (n):
            for k in range(n):
                C[i,j]+=matrix_A[i,k]*matrix_B[k,j]
    return C