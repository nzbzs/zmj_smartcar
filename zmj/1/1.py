import numpy as np

#zmj
rows=int(input())
m=[]
for i in range(rows):
    row=list(map(int,input().split()))
    m.append(row)

try:
    A = np.array(m)
    print(A)
    B=np.linalg.inv(A)
except:
    print("矩阵不可逆")
else:
    print(B)