library(ggplot2)

ds <- read.csv(
  "crop-data.csv,
  header = TRUE
)

ggsave("crops box plot.png", plot = ggplot(ds, aes(x = crops, y = temperature, fill = crops)) +
  geom_boxplot())
