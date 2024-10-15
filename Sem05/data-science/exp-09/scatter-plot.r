library(ggplot2)

# Read the CSV file
data <- read.csv("advertising_traffic_data.csv")

# Create the scatter plot with the new heading
ggplot(data, aes(x = Advertising_Expenses, y = Website_Traffic)) +
  geom_point() +
  labs(title = "Advertising Expenses vs. Website Traffic", x = "Advertising Expenses (Millions)", y = "Website Traffic (Millions)") +
  theme_minimal()

ggsave("advertising-traffic-scatter-plot.jpg", last_plot())

