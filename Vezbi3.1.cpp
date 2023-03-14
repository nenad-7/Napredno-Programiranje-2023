
//Ovaa zadaca ni ovozmozuva vnes na godina,mesec i broj na den vo mesecot i potoa ni kazuva kako se vika toj den vo nedelata. 
// Ja koristi bibliotekata time.h. Prvo se kreira promenliva od tip time_t koja go sodrzi segasnoto vreme.  Strukturata tm gi sodrzi komponentite na kalendarski datum. 
// Potoa se bara da se vnesi godina mesec i den, tie vrednosti se zamenuvaat so segasnite od localtime. Potoa se povikuva funkcijata tm_wday koja go pecati soodvetniot den.


#include <stdio.h>  
#include <time.h>       
int main()
{
    time_t rawtime;
    struct tm* timeinfo;
    int year, month, day;
    const char* weekday[] = { "Sunday", "Monday",
                               "Tuesday", "Wednesday",
                               "Thursday", "Friday", "Saturday" };

    /* prompt user for date */
    printf("Enter year: "); fflush(stdout); scanf("%d", &year);
    printf("Enter month: "); fflush(stdout); scanf("%d", &month);
    printf("Enter day: "); fflush(stdout); scanf("%d", &day);

    /* get current timeinfo and modify it to the user's choice */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* call mktime: timeinfo->tm_wday will be set */
    mktime(timeinfo);

    printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);

    return 0;
}