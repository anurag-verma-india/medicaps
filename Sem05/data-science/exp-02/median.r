# Calculating median of a column from an imported file in R

data_csv <- read.csv("student_data.csv")

cat("\n")
median_value<-median(data_csv$books_read)
cat("Median: ", median_value, "\n\n")
