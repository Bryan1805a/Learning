import math
import os
import random
import re
import sys

#
# Complete the 'bonAppetit' function below.
#
# The function accepts following parameters:
#  1. INTEGER_ARRAY bill
#  2. INTEGER k
#  3. INTEGER b
#

def bonAppetit(bill, k, b):
    # Write your code here
    total = 0
    n = len(bill)
    for i in range(n):
        if i == k:
            continue
        
        total += bill[i]
    
    if b - (total / 2) == 0:
        print("Bon Appetit")
    else:
        print(int((abs(b - (total / 2)))))

bonAppetit([3, 10, 2, 9], 1, 12)