import pandas as pd

df = pd.DataFrame({
    'Age': [25, 30, 35, 28],
    'City': ['New York', 'London', 'Tokyo', 'New York']
})

# 25, 28, 30, 35
# median 29

print()
print(df.describe())
print()