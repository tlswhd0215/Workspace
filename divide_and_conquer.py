import numpy as np

def div_con(matrix_A,matrix_B):
    n = matrix_A.shape[0]
    C = np.zeros((n * n), dtype=np.longlong).reshape(n, n)
    if n==1:
        C[0][0]=matrix_A[0][0]*matrix_B[0][0]
    else:
        k = int(n / 2)
        A11, A21, A12, A22 = matrix_A[:k, :k], matrix_A[k:, :k], matrix_A[:k, k:], matrix_A[k:, k:]
        B11, B21, B12, B22 = matrix_B[:k, :k], matrix_B[k:, :k], matrix_B[:k, k:], matrix_B[k:, k:]
        C[:k, :k] = div_con(A11,B11)+div_con(A12,B21)
        C[:k, k:] = div_con(A11,B12)+div_con(A12,B22)
        C[k:, :k] = div_con(A21,B11)+div_con(A22,B21)
        C[k:, k:] = div_con(A21,B12)+div_con(A22,B22)

    return C