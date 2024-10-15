library(ggplot2)

stock_data <- read.csv("stock_prices.csv")

# Creating a new column for sequence of data
stock_data$sequence <- 1:nrow(stock_data)

# write.csv(stock_data, "/home/anurag/Documents/github/medicaps/Sem05/data-science/exp-08/stock_with_sequence.csv")

ggplot(stock_data, aes(x = sequence, y = stock_price)) +
  geom_line(color = "blue") +
  geom_point(color = "blue") +
  labs(title = "Line Graph of Stock Prices", x = "Data Point", y = "Stock Price") +
  theme_minimal()


ggsave("line-graph.jpg", last_plot())
