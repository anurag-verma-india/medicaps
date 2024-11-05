import numpy as np
data = np.genfromtxt('students.csv', delimiter=',')

print("---- Students data ----")
print(data)
print()


# Understanding the Data

# Basic Information
print("---- Basic Information ----")
print("Shape of the data:", data.shape)
print("Data types:", data.dtype)
print()

print("---- Descriptive Statistics ----")
print("Mean:", np.mean(data[:, 1:], axis=0))  # Exclude ID column
print("Median:", np.median(data[:, 1:], axis=0))
print("Standard Deviation:", np.std(data[:, 1:], axis=0))
print("Minimum:", np.min(data[:, 1:], axis=0))
print("Maximum:", np.max(data[:, 1:], axis=0))
# print()

# # Correlation Analysis
# correlation_matrix = np.corrcoef(data[:, 1:], rowvar=False)
# print("Correlation Matrix:\n", correlation_matrix)
# print()

# # Outlier Detection (Simple Method)
# z_scores = np.abs((data[:, 1:] - np.mean(data[:, 1:], axis=0)) / np.std(data[:, 1:], axis=0))
# outliers = np.where(z_scores > 2)  # Adjust the threshold as needed
# print("Potential outliers:", data[outliers])



# # Visualization
# import matplotlib.pyplot as plt

# # Scatter plot of height vs. weight
# plt.scatter(data[:, 2], data[:, 3])
# plt.xlabel("Height (cm)")
# plt.ylabel("Weight (kg)")
# plt.title("Height vs. Weight")
# plt.show()