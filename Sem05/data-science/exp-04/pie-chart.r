

slices <- c(40, 30, 20, 10)  # Percentages
labels <- c("A", "B", "C", "D")  # Labels for each slice

pie(slices, labels = labels, main = "Pie Chart Example", col = rainbow(length(slices)))
