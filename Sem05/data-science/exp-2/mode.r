# Calculating mode of a column from an imported file in R

data_csv <- read.csv("student_data.csv")

calculate_mode <- function(data_vector) {
    frequency_table <- table(data_vector)
    highest_frequency_value <- sort(frequency_table, decreasing = TRUE)[1]
    result <- as.numeric(names(highest_frequency_value))
    return(result)
}

cat("\n")
mode_value <- calculate_mode(data_csv$books_read)
cat("Mode: ",mode_value, "\n\n")
