import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv(r'Machine_learning\Data\study.csv')


def gradient_descent(m_now, b_now, points, L):
    m_gradient = 0
    b_gradient = 0
    
    n = len(points)
    
    for i in range(n):
        x = points.iloc[i].study_time
        y = points.iloc[i].score
        
        m_gradient += -(2/n) * x * (y - (m_now * x + b_now))
        b_gradient += -(2/n) *  (y - (m_now * x + b_now))
    
    m = m_now - m_gradient * L;
    b = m_now - b_gradient * L;
    
    return m, b

m = 0
b = 0
L = 0.0001
epochs = 300

for i in range(epochs):
    if i % 50 == 0:
        print(f"Epoch: {i}")
    m, b = gradient_descent(m, b, data, L)
    
print(m, b)

plt.scatter(data.study_time, data.score, color='black', )
plt.plot(list(range(20, 80)), [m * + b for x in range(20, 80)], color='red')
plt.show()