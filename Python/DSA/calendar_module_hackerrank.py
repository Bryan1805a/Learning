import calendar

conversion = {
    0: "MONDAY",
    1: "TUESDAY",
    2: "WEDNESDAY",
    3: "THURSDAY",
    4: "FRIDAY",
    5: "SATURDAY",
    6: "SUNDAY"
}

date_input = list(map(int, input().split()))
day_in_week = calendar.weekday(date_input[2], date_input[0], date_input[1])

print(conversion[day_in_week])