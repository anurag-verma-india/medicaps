import numpy as np

# dataset with 10 rows and 4 columns (ID, Age, Height (cm), Weight (kg))
data = np.array([
    [1, 25, 175, 70],
    [2, 30, 160, 60],
    [3, 22, 165, 65],
    [4, 28, 180, 75],
    [5, 26, 172, 68],
    [6, 24, 178, 74],
    [7, 29, 158, 58],
    [8, 27, 170, 67],
    [9, 23, 162, 63],
    [10, 31, 176, 72]
])

print(data)
# np.savetxt('students.csv', data, delimiter=',') 
np.savetxt('students.csv', data, fmt="%d", delimiter=",")



# Understanding the Data

# Basic Information
print("---- Basic Information ----")
print("Shape of the data:", data.shape)
print("Data types:", data.dtype)

# Descriptive Statistics
print("---- Descriptive Statistics ----")
print("Mean:", np.mean(data[:, 1:], axis=0))  # Exclude ID column
print("Median:", np.median(data[:, 1:], axis=0))
print("Standard Deviation:", np.std(data[:, 1:], axis=0))
print("Minimum:", np.min(data[:, 1:], axis=0))
print("Maximum:", np.max(data[:, 1:], axis=0))

# Correlation Analysis
correlation_matrix = np.corrcoef(data[:, 1:], rowvar=False)
print("Correlation Matrix:\n", correlation_matrix)

# Outlier Detection (Simple Method)
z_scores = np.abs((data[:, 1:] - np.mean(data[:, 1:], axis=0)) / np.std(data[:, 1:], axis=0))
outliers = np.where(z_scores > 2)  # Adjust the threshold as needed
print("Potential outliers:", data[outliers])



# # Visualization
# import matplotlib.pyplot as plt

# # Scatter plot of height vs. weight
# plt.scatter(data[:, 2], data[:, 3])
# plt.xlabel("Height (cm)")
# plt.ylabel("Weight (kg)")
# plt.title("Height vs. Weight")
# plt.show()