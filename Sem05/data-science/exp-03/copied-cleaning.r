library(tidyverse)
library(zoo)
setwd("/home/anurag/Documents/github/medicaps/Sem05/data-science/exp-03/")
starwars_data <- read_csv("starwars-cropped.csv")

# Removing irrelevant column
starwars_data$serial <- NULL

# deleting duplicate data
starwars_data <- starwars_data[!duplicated(starwars_data), ]

# Replacing NA data with mean
starwars_data$height[is.na(starwars_data$height)]<-mean(starwars_data$height,na.rm=TRUE)

# Replacing NA in hair_color and sex columns
starwars_data$hair_color[is.na(starwars_data$hair_color)] <- "no hair"
starwars_data$sex[is.na(starwars_data$sex)] <- "not applicable"

# Checking missing values
view(starwars_data)

# Removing rows with missing values in homeworld column
starwars_data <- na.omit(starwars_data, c("homeworld"))

# Removing all other rows with NA in any column
na.aggregate(starwars_data)

view(starwars_data)
write.csv(starwars_data, "./cleaned-starwars.csv")

