import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Read file
df = pd.read_csv(r'Machine_learning\Data\student_info.csv')
# print(df)
# print(df.head())
# print(df.tail())
# print(df.shape)
# print(df.info())
# print(df.describe())

'''
plt.figure(figsize=(7, 5))
plt.scatter(x=df.study_hours, y=df.student_marks, color='red', marker='*', s=100, alpha=0.5)
plt.xlabel('Study_hours')
plt.ylabel("Student_marks")
plt.title('Test data')
plt.show()
'''

# print(df.isnull())
# print(df.isnull().sum())

# print(df.mean())

df_2 = df.fillna(df.mean())
# print(df_2.isnull().sum())

# Heatmap
'''
plt.figure(figsize=(8, 5))
sns.heatmap(df.corr(), annot=True, linewidths=3)
plt.show()
'''
'''
plt.figure(figsize=(8, 5))
sns.barplot(x='study_hours', y='student_marks', data=df_2)
plt.show()
'''

X = df_2.drop('student_marks', axis='columns')
y = df_2.drop('study_hours', axis='columns')
# print(X.shape)
# print(y.shape)

sns.pairplot(df)
plt.show()