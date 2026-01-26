#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    tail_check = s[-2:]
    hour = s[0:2]
    minute = s[3:5]
    second = s[-4:-2]

    if tail_check == 'PM':
        if hour == '12':
            hour = '12'
        else:
            hour = int(hour)
            hour += 12
            hour = str(hour)
    elif tail_check == "AM":
        if hour == '12':
            hour = '00'

    return f"{str(hour)}:{minute}:{second}"

result = timeConversion('07:05:45PM')
print(result)

'''
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
'''