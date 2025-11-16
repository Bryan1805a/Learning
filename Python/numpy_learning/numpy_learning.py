import numpy as np

arr = np.array([[1, 2, 3], [4, 5, 6]])

for inx, i in np.ndenumerate(arr):
    print(inx, i)