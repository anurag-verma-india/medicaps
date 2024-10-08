library(tidyverse)


# glimpse(starwars)

new_starwars = data.frame(starwars)

new_starwars<- apply(new_starwars,2,as.character)
write.csv(new_starwars, "/home/anurag/Documents/github/medicaps/Sem05/data-science/exp-03/starwars.csv")

