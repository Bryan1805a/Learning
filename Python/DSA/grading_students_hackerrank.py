import math
import os
import random
import re
import sys

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def gradingStudents(grades):
    # Write your code here
    new_grades = []
    for grade in grades:
        if grade >= 38:
            rem = grade % 5
            if rem >= 3:
                grade += (5 - rem)
        
        new_grades.append(grade)
    
    return new_grades

print(gradingStudents([73, 67, 38, 33]))