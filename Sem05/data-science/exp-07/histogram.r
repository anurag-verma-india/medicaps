library(ggplot2)
library(tidyverse)

df <- read_csv("./family-income.csv")
head(df)
# Basic histogram
ggplot(df, aes(x=Average_income)) + geom_histogram()