import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
import urllib.request
import ssl

# Disable SSL verification (only for downloading dataset)
ssl._create_default_https_context = ssl._create_unverified_context

# Download the SMS Spam Collection Dataset
url = "https://raw.githubusercontent.com/mohitgupta-omg/Kaggle-SMS-Spam-Collection-Dataset/master/spam.csv"
urllib.request.urlretrieve(url, "spam_dataset.csv")

# Load the dataset
df = pd.read_csv("spam_dataset.csv", encoding='latin-1')

# Rename columns for clarity
df.columns = ['label', 'text']

# Convert labels to binary (spam = 1, not spam = 0)
df['label'] = df['label'].map({'spam': 1, 'ham': 0})

# Split the text into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(
    df['text'], df['label'], test_size=0.2, random_state=42
)

# Convert text to numerical features using CountVectorizer
vectorizer = CountVectorizer(stop_words='english', max_features=1000)
X_train_vectorized = vectorizer.fit_transform(X_train)
X_test_vectorized = vectorizer.transform(X_test)

# Train Logistic Regression model
lr_model = LogisticRegression(random_state=42, max_iter=1000)
lr_model.fit(X_train_vectorized, y_train)

# Make predictions
y_pred = lr_model.predict(X_test_vectorized)

# Evaluate the model
print("Accuracy:", accuracy_score(y_test, y_pred))
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Confusion Matrix
print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))

# Example prediction function
def predict_spam(text):
    """
    Predict if a given text is spam or not
    
    Args:
    text (str): Email text to classify
    
    Returns:
    str: Prediction ('Spam' or 'Not Spam')
    """
    vectorized_text = vectorizer.transform([text])
    prediction = lr_model.predict(vectorized_text)
    return "Spam" if prediction[0] == 1 else "Not Spam"

# Example usage
sample_texts = [
    "Congratulations! You've won a free iPhone. Click here to claim now!",
    "Hi, can we discuss the project details tomorrow?"
]

for text in sample_texts:
    print(f"\nText: {text}")
    print(f"Prediction: {predict_spam(text)}")