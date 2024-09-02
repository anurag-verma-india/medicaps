# Calculating mean of a column from an imported file in R

data_csv <- read.csv("student_data.csv")
mean_value<-mean(data_csv$books_read)

cat("\n")
cat("Mean: ",mean_value, "\n\n")

