library(tidyverse)
setwd("/home/anurag/Documents/github/medicaps/Sem05/data-science/exp-03/")

# Importing data
starwars_data <- read_csv("starwars-cropped.csv")

starwars_data <- data.frame(matrix(unlist(starwars_data), nrow = nrow(starwars_data)), stringsAsFactors = FALSE)

## missing Data
mean <- mean(starwars_data$height, na.rm = TRUE)


# quit(save = "no")
# Removing missing values
starwars_data |>
    select(name, gender, hair_color, height) |>
    drop_na(height)

# Replacing missing values

starwars_data %>%
    select(name, gender, hair_color, height) %>%
    filter(!complete.cases(.)) %>%
    mutate(hair_color = replace_na(hair_color, "none"))
