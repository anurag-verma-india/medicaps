import pandas as pd

df = pd.read_csv('laptops.csv')

print("---- First 5 rows of dataset ----")
print(df.head(), "\n")

print("---- Basic info of dataset ----")
print(df.info(), "\n")

print("---- Statistical summary of numerical columns ----")
print(df.describe(), "\n")

print("---- Missing values ----")
print(df.isnull().sum(), "\n")

# Filter laptops with more than 8GB RAM
print("---- Laptops with more than 8GB RAM ----")
filtered_df = df[df['RAM (GB)'] > 8]
print(filtered_df, "\n")

# Sort laptops by price in descending order
print("---- Sort laptops by price in descending order ----")
sorted_df = df.sort_values(by='Price (USD)', ascending=False)
print(sorted_df, "\n")
