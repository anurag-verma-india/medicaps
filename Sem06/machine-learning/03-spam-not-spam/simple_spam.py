import pandas as pd
import kagglehub

path = kagglehub.dataset_download("colormap/spambase")
print("Path to dataset files:", path)
df = pd.read_csv(f"{path}/spambase.csv", encoding='latin-1')

print("Sample data")
print(df.head())

