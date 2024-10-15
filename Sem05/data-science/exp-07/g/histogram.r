library(ggplot2)

stock_data <- read.csv("stock_prices.csv")

ggplot(stock_data, aes(x = stock_price)) +
  geom_histogram(binwidth = 10, fill = "blue", color = "black") +
  labs(title = "Histogram of Stock Prices", x = "Stock Price", y = "Frequency") +
  theme_minimal()

ggsave("histogram.jpg", last_plot())
