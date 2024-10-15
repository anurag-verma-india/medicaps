

set.seed(1234)
df <- data.frame(
  sex=factor(rep(c("F", "M"), each=20)),
  weight=round(c(rnorm(20, mean=55, sd=10), rnorm(20, mean=65, sd=10)))
  )
head(df)

write.csv(df,"./weight-data.csv")


# Make histogram