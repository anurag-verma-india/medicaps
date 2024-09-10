# Importing data
data <- read.csv("expense.csv")

# Specifing the file name of the PDF file created
pdf("Expense pie chart.pdf")

# Creating Pie chart
pie(data$expense, labels = data$expense_category, main="Monthly Expenses")
