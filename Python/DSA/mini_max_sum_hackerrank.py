import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    # Write your code here
    total = sum(arr)
    minimum = total - max(arr)
    maximum = total - min(arr)

    print(minimum, maximum)

miniMaxSum([1, 3, 5, 7, 9])