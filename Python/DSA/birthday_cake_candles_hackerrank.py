import math
import os
import random
import re
import sys

#
# Complete the 'birthdayCakeCandles' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY candles as parameter.
#

def birthdayCakeCandles(candles):
    # Write your code here
    tallest = max(candles)
    
    count = 0
    for i in candles:
        if i == tallest:
            count += 1

    return count

print(birthdayCakeCandles([4, 4, 1, 3]))