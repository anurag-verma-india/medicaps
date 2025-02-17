from sklearn.datasets import load_breast_cancer
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# load the following dataset
print("Loading data")
X, y = load_breast_cancer(return_X_y=True)

print("Splitting dataset")
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.20, random_state=23
)


print("Training model")
clf = LogisticRegression(max_iter=10000, random_state=0)
print("clf", clf)
print("X_train", X_train)
print("y_train", y_train)
clf.fit(X_train, y_train)

print("Testing accuracy")
acc = accuracy_score(y_test, clf.predict(X_test)) * 100
print(f"Logistic Regression model accuracy: {acc:.2f}%")
