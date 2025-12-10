import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import statsmodels.api as sm

ad_data = pd.read_csv(r'Machine_learning\advertising_sales_prediction\sales_info.csv')
# print(ad_data)
#print(ad_data.head())
#print(ad_data.tail())
#print(ad_data.info())
#print(ad_data.dtypes)
#print(ad_data['Influencer'].unique())

# Mapping 'Influencer'
ad_data['Influencer_new'] = ad_data['Influencer'].map({'Mega': 3, 'Micro': 2, 'Nano': 1, 'Macro': 0})
#print(ad_data['Influencer_new'])

'''
for col in ad_data:
    if col in ['TV', 'Radio', 'Social Media', 'Influencer_new', 'Sales']:
        print(col)
        print('Sum of ', col, ' = ', ad_data[col].sum())
        print('-------')
'''

#print(ad_data.describe())

# Data cleaning
third_col = ad_data.pop('Influencer_new')
ad_data.insert(3, 'Influencer_new', third_col)

ad_data['Sales'] = ad_data['Sales'].fillna(ad_data['Sales'].median())
ad_data['Radio'] = ad_data['Radio'].fillna(ad_data['Radio'].median())
ad_data['Social Media'] = ad_data['Social Media'].fillna(ad_data['Social Media'].median())
ad_data.drop(['Influencer'], axis=1, inplace=True)
clean_data = ad_data.drop(['Social Media'], axis=1)

X = clean_data.iloc[:, :-2]
y = clean_data['Sales']

TV = ad_data['TV'].to_numpy()
Radio = ad_data['Radio'].to_numpy()
Sales = ad_data['Sales'].to_numpy()

x0 = np.ones(len(TV))
X2 = np.array([TV, Radio]).T
W = np.array([0, 0])
Y2 = np.array(Sales)

def cost_function(X, Y, W):
    m = len(Y)
    J = np.sum((X.dot(X) - Y) ** 2) / (2 * m)
    return J

print(cost_function(X2, Y2, W))