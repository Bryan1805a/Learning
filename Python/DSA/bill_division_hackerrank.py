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
    actual_share = (sum(bill) - bill[k]) // 2

    if b == actual_share:
        print("Bon Appetit")
    else:
        print(b - actual_share)

bonAppetit([3, 10, 2, 9], 1, 12)