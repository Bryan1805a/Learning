import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression

# Read file
df = pd.read_csv(r'Machine_learning\student_marks_prediction\student_marks.csv')
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

# sns.pairplot(df_2, kind='reg')
# plt.show()

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=51)
# print(X_train.shape)
# print(y_train.shape)
#print(X_test.shape)
#print(y_test.shape)

model = LinearRegression()
model.fit(X_train, y_train)

# print(model.coef_)
# print(model.intercept_)

y_pred = model.predict(X_test)

a= pd.DataFrame(np.c_[X_test, y_test, y_pred], columns=['study_hours', 'original_student_marks', 'Predicted marks'])

# print(model.score(X_test, y_test))

plt.figure(figsize=(7, 5))
plt.scatter(X_test, y_test)
plt.plot(X_train, model.predict(X_train), color='red')
plt.show()