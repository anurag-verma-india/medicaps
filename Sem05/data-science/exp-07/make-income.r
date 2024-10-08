# library(ggplot2)

# ds <- read.csv(
#   "crop-data.csv,
#   header = TRUE
# )

# ggsave("crops box plot.png", plot = ggplot(ds, aes(x = crops, y = temperature, fill = crops)) +
#   geom_histogram())


# library(ggplot2)

set.seed(123)
df <- data.frame(
   gender=factor(rep(c(
     "Average Female income ", "Average Male incmome"), each=20000)),
   Average_income=round(c(rnorm(20000, mean=15500, sd=500), 
                          rnorm(20000, mean=17500, sd=600)))   
)  

write.csv(df,"./family-income.csv")
# head(df)
 
# Basic histogram
# ggplot(df, aes(x=Average_income)) + geom_histogram()