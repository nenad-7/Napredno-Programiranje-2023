//se kreira promenliva od tip time_t, i potoa se pravi pointer na timeinfo koja ja prikazuva denesnata data. na time mu se dodeluva adresata na rawtime.
// na timeinfo mu se dodeluva localtime so adresata na rawtime. potoa na kraj se pecati denesniot den,mesec,vreme i godina.

#include <stdio.h>      /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */

int main()
{
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));

	return 0;
}