import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    n = len(arr)
    positive_ratio = 0
    negative_ratio = 0
    zero_ratio = 0

    for i in arr:
        if i > 0:
            positive_ratio += 1
        elif i == 0:
            zero_ratio += 1
        elif i < 0:
            negative_ratio += 1
    
    positive_ratio = "{:.6f}".format(positive_ratio / n)
    negative_ratio = "{:.6f}".format(negative_ratio / n)
    zero_ratio = "{:.6f}".format(zero_ratio / n)

    print(positive_ratio)
    print(negative_ratio)
    print(zero_ratio)

plusMinus([1, 1, 0, -1, -1])