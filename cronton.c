/* cronton
* 
* This little thing checks if the time matches the wanted time.
* If so, execute given command. Ugly, but works (ish)
*/

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
int main ()
{
int a = 1;
while ( a == a )
  {
	time_t now;
	struct tm *now_tm;
	now = time(NULL);
	now_tm = localtime(&now);
	int hour = now_tm->tm_hour;
	int minute = now_tm->tm_min;
	int trigger_hour=16;
	int trigger_minute=43;

	if (( hour == trigger_hour ) & ( minute == trigger_minute)){
		system("/home/ton/leetscript.sh");
	} 
  delay(60);
  }
}
