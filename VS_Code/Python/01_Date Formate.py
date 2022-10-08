import datetime as dt
date_string = "25/12/2018"
format = "%d/%m/%Y"

try:
  dt.datetime.strptime(date_string, format)
  print("This is the correct date string format.")
except ValueError:
  print("This is the incorrect date string format. It should be YYYY-MM-DD")