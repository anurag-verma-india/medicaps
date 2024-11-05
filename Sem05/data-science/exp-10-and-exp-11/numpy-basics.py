import numpy as np

# Load data from CSV into a NumPy array
data = np.genfromtxt('laptops.csv', delimiter=',', skip_header=1)

# Print first 5 rows
print("---- First 5 rows of dataset ----")
print(data[:5])

# Get basic information about the data (data types, missing values)
print("---- Basic info of dataset ----")
print(f"Data types: {data.dtype}")
print(f"Missing values (per column): {np.sum(np.isnan(data), axis=0)}")

# Filter laptops with more than 8GB RAM
print("---- Laptops with more than 8GB RAM ----")
ram_gt_8 = data[:, 1] > 8  # Select RAM column (index 1) and filter by condition
filtered_data = data[ram_gt_8]
print(filtered_data)

# Sort laptops by price (descending order)
print("---- Sort laptops by price in descending order ----")
sorted_data = data[data[:, 3].argsort()[::-1]]  # Sort by price (index 3) descending
print(sorted_data)