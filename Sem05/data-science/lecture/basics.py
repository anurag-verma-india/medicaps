import numpy as np

x = np.arange(1,11)
print(x)
np.random.choice(x,10,replace=True)
print(x)
