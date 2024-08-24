
# csv file
data_csv <- read.csv("file.csv")
mean(data_csv$population)
View(data_csv)

# txt file
data_txt <- read.csv("file.txt")
mean(data_txt$population)

# xlsx file 
library("readxl")
data_xlsx <- read_excel("file.xlsx")
mean(data_xlsx$average_montly_hours)

# json file
library("jsonlite")
data_json <- fromJSON("iris.json")
mean(data_json$petalLength)
