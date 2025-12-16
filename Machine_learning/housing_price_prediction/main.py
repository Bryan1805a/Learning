import pandas as pd
import matplotlib.pyplot as plt
from sklearn.preprocessing import MinMaxScaler

data = pd.read_csv(r'Machine_learning\housing_price_prediction\Housing.csv')

# Binary mapping
binary_cols = ['mainroad', 'guestroom', 'basement', 'hotwaterheating', 'airconditioning', 'prefarea']
def binary_map(x):
    return x.map({'yes': 1, 'no': 0})

data[binary_cols] = data[binary_cols].apply(binary_map)

status = pd.get_dummies(data['furnishingstatus'], drop_first=True)
data = pd.concat([data, status], axis=1)

data.drop(['furnishingstatus'], axis=1, inplace=True)

data.to_csv('housing_cleaned.csv', index=False)