# How many Sundays fell on the first of the month
# during the twentieth century?
# ----------------------------------------------------
# Analysis: brute force

class Calendar:
    def __init__(self):
        self.day = 1
        self.month = 1
        self.year = 1900
        self.weekend = 1

    def next_day(self):
        self.weekend = self.weekend + 1 if self.weekend < 7 else self.weekend - 6
        self.day += 1
        up_day = 31
        if self.month == 2:
            up_day = 28 + (not self.year % 400 or not self.year % 4 and self.year % 100 > 0)
        elif self.month in [4, 6, 9, 11]:
            up_day = 30
        if self.day > up_day:
            self.day -= up_day
            self.month += 1
        if self.month > 12:
            self.month -= 12
            self.year += 1

    def __str__(self):
        pass

c = Calendar()
res = 0
while not c.year == 2001:
    res += 1900 < c.year and c.weekend == 7 and c.day == 1
    c.next_day()

print(res)
