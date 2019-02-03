dates = ['20 Oct 2052', '06 Jun 1933', '26 May 1960', '20 Sep 1958', '16 Mar 2068', '25 May 1912', '16 Dec 2018', '26 Dec 2061', '04 Nov 2030', '28 Jul 1963']

MONTH_HASH_MAP = {
    "Jan": "01",
    "Feb": "02",
    "Mar": "03",
    "Apr": "04",
    "May": "05",
    "Jun": "06",
    "Jul": "07",
    "Aug": "08",
    "Sep": "09",
    "Oct": "10",
    "Nov": "11",
    "Dec": "12"
}

MONTH_REVERSE_HASH_MAP = {
    "01": "Jan",
    "02": "Feb",
    "03": "Mar",
    "04": "Apr",
    "05": "May",
    "06": "Jun",
    "07": "Jul",
    "08": "Aug",
    "09": "Sep",
    "10": "Oct",
    "11": "Nov",
    "12": "Dec"
}


def sortDates(dates):
    stringOutput = []
    print dates

    for i in dates:
        date = i.split()
        stringOutput.append(int("{year}{month}{day}".format(day=date[0], month=MONTH_HASH_MAP[date[1]], year=date[2])))
    stringOutput.sort()
    result = []

    for i in stringOutput:
        i = str(i)
        result.append("{date} {month} {year}".format(date=i[-2:], month=MONTH_REVERSE_HASH_MAP[i[4:6]], year=i[0:4]))
    print result


sortDates(dates)
