library("readxl")

calculate_mode <- function(data_vector) {
    frequency_table <- table(data_vector)
    highest_frequency_value <- sort(frequency_table, decreasing = TRUE)[1]
    result <- as.numeric(names(highest_frequency_value))
    return(result)
}

data_xlsx <- read_excel("file.xlsx")
mean_value<-mean(data_xlsx$average_montly_hours)
median_value<-median(data_xlsx$average_montly_hours)
mode_value <- calculate_mode(data_xlsx$average_montly_hours)

mean_value
median_value
mode_value