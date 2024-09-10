pdf("Monthly expense bar chart.pdf")

data <- read.csv("expense.csv")

barplot(
  height = data$expense,
  names.arg = data$expense_category,
  main = "Monthly Expense Bar chart",
  xlab = "Expense Category",
  ylab = "Expense Amount",
  col = "lightblue",
  border = "blue"
)
