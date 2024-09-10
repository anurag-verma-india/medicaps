
data_csv <- read.csv("student_data.csv")
mean_value<-mean(data_csv$books_read)

cat("\n")
cat("Mean: ",mean_value, "\n")


median_value<-median(data_csv$books_read)
cat("Median: ", median_value, "\n")



calculate_mode <- function(data_vector) {
    frequency_table <- table(data_vector)
    highest_frequency_value <- sort(frequency_table, decreasing = TRUE)[1]
    result <- as.numeric(names(highest_frequency_value))
    return(result)
}

mode_value <- calculate_mode(data_csv$books_read)
cat("Mode: ",mode_value, "\n\n")
