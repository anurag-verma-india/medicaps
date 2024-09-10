# Sample data
categories <- c("A", "B", "C", "D", "E")
values <- c(10, 24, 15, 32, 18)

# Create a bar chart
barplot(values, 
        names.arg = categories,
        main = "Simple Bar Chart",
        xlab = "Categories",
        ylab = "Values",
        col = "skyblue",
        border = "darkblue")

# Add value labels on top of each bar
text(x = 1:length(values), 
     y = values, 
     labels = values, 
     pos = 3, 
     cex = 0.8, 
     col = "black")