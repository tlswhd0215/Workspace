import numpy as np
def strassen (matrix_A,matrix_B):
    n=matrix_A.shape[0]
    C=np.zeros((n*n),dtype=np.longlong).reshape(n,n)

    if n==1:
        C[0][0]=matrix_A[0][0]*matrix_B[0][0]

    else:
        k=int(n/2)
        A11, A21, A12, A22 = matrix_A[:k, :k], matrix_A[k:, :k], matrix_A[:k, k:], matrix_A[k:, k:]
        B11, B21, B12, B22 = matrix_B[:k, :k], matrix_B[k:, :k], matrix_B[:k, k:], matrix_B[k:, k:]

        M1=strassen(A11+A22,B11+B22)
        M2=strassen(A21+A22,B11)
        M3=strassen(A11,B12-B22)
        M4=strassen(A22,B21-B11)
        M5=strassen(A11+A12,B22)
        M6=strassen(A21-A11,B11+B12)
        M7=strassen(A12-A22,B21+B22)
        C[:k,:k]=M1+M4-M5+M7
        C[:k,k:]=M3+M5
        C[k:,:k]=M2+M4
        C[k:,k:]=M1-M2+M3+M6
    return C
