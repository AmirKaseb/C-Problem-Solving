    else //offset < 0
    {
        *minute -= (-offset % 100);
        if (*minute < 0)
        {
            *minute += 60;
            (*hour)--;
        }
        *hour -= (-offset / 100);
        if (*hour < 0)
        {
            *hour += 24;
            return -1;
        }
    }
    return 0;
}
void forwardDate(int* year, char* month, int* dayOfMonth, char* dayOfWeek, int offset)
{
    int monthId = getMonthId(month); //0-based
    int curDayNumber = dayNumberOfMonth[monthId] + (monthId == 1 && isLeapYear(*year));

    int dayOfWeekId = getDayOfWeekId(dayOfWeek);
    strcpy(dayOfWeek, dayOfWeekName[(dayOfWeekId + 1) % 7]);

    if ((*dayOfMonth += offset) > curDayNumber)
    {
        *dayOfMonth = 1;
        if ((monthId += 1) >= 12)
        {
            monthId = 0;
            (*year)++;
        }
    }
    strcpy(month, monthName[monthId]); //maybe advanced before
}
void backwardDate(int* year, char* month, int* dayOfMonth, char* dayOfWeek)
{
    int monthId = getMonthId(month); //0-based
    int dayOfWeekId = getDayOfWeekId(dayOfWeek);
    strcpy(dayOfWeek, dayOfWeekName[(dayOfWeekId + 6) % 7]);
    if ((*dayOfMonth -= 1) <= 0)
    {
        if ((monthId -= 1) < 0)
        {
            monthId = 11;
            (*year)--;
        }
        *dayOfMonth = dayNumberOfMonth[monthId] + (monthId == 1 && isLeapYear(*year));
        //update dayOfMonth before monthId
    }
    strcpy(month, monthName[monthId]);
}
int solve()
{
    char dayOfWeek[5];
    char month[4];
    char timeZone[8];
    char yearStr[5];
    int dayOfMonth;
    int year;
    int hour, minute, second;
    int offset;
    if (scanf("%s%d%s%s%d:%d:%d%s", dayOfWeek, &dayOfMonth, month, yearStr,
              &hour, &minute, &second, timeZone) == EOF)
        return 0;
    dayOfWeek[3] = '\0'; //erase the comma
    year = (strlen(yearStr) == 4 ? atoi(yearStr) : 1900 + atoi(yearStr));
    offset = getOffset(timeZone);
    int advanceClockResult = advanceClock(&hour, &minute, offset);
    if (advanceClockResult >= 1)
        forwardDate(&year, month, &dayOfMonth, dayOfWeek, advanceClockResult);
    else if (advanceClockResult == -1)
        backwardDate(&year, month, &dayOfMonth, dayOfWeek);
    printf("%s, %02d %s %04d %02d:%02d:%02d +0300",
           dayOfWeek, dayOfMonth, month, year, hour, minute, second);

    return 1;
}
int main()
{
    int i;
    for (i = 0; solve(); i++)
    {
        if (i > 0)
            putchar('\n');
