import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('mobile_phones.csv')

# Pie Chart: Market Share by Brand
brand_counts = data['Brand'].value_counts()

plt.figure(figsize=(8, 8))
plt.pie(brand_counts, labels=brand_counts.index, autopct='%1.1f%%', startangle=140)
plt.title('Market Share by Brand')
plt.savefig('pie-chart.png')

# Line Chart: Price vs Screen Size

data_sorted = data.sort_values('Screen Size (inch)')
plt.figure(figsize=(8, 8))
plt.plot(data_sorted['Screen Size (inch)'], data_sorted['Price'], marker='o')
plt.xlabel('Screen Size (inch)')
plt.ylabel('Price')
plt.title('Price vs Screen Size')
plt.savefig('line-chart.png')


# Histogram: Distribution of Battery Capacity
plt.figure(figsize=(8, 5))
plt.hist(data['Battery Capacity (mAh)'], bins=10, edgecolor='black')
plt.xlabel('Battery Capacity (mAh)')
plt.ylabel('Frequency')
plt.title('Distribution of Battery Capacity')
plt.savefig('histogram.png')

# Box Plot: Price Distribution by Brand
plt.figure(figsize=(10, 5))
data.boxplot(column='Price', by='Brand', grid=False)
plt.title('Price Distribution by Brand')
plt.suptitle('')
plt.xlabel('Brand')
plt.ylabel('Price ($)')
plt.savefig('box-plot.png')

# Scatter Plot: Battery Capacity vs Price
plt.figure(figsize=(8, 5))
plt.scatter(data['Battery Capacity (mAh)'], data['Price'], alpha=0.7)
plt.xlabel('Battery Capacity (mAh)')
plt.ylabel('Price ($)')
plt.title('Battery Capacity vs Price')
plt.savefig('scatter-plot.png')
