/* cronton
* 
* This little thing checks if the time matches the wanted time.
* If so, execute given command. Ugly, but works (ish)
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

const char * config()
{
        if (access("cronton.conf", F_OK) != -1 ){
                return "./cronton.conf";
        } else if (access("/etc/cronton/cronton.conf", F_OK) != -1 ){
                return "/etc/cronton/cronton.conf";
        } else {
                printf("Config file not found!\n");
                exit(1);
        }
        /* Nothing found, notify main process */
}

void delay(int number_of_seconds) 
{ 
	int milli_seconds = CLOCKS_PER_SEC * number_of_seconds; 
	printf("Counting to %d...\n", milli_seconds);
	clock_t start_time = clock(); 
	while (clock() < start_time + milli_seconds)
        ; 
}

int main ()
{
/* First, init ALL the variables! */
char filename[256];
sprintf(filename,"%s", config());
char line[256];
int linenum=0;
int set_hour;
int set_minute;
FILE *file;
file=fopen(filename, "r");

int a = 1;

/* Finding and using the config line */
char time[256], command[256];
while(fgets(line, 256, file) != NULL)
	{
        linenum++;
        if(line[0] == '#')  continue; 

                if(sscanf(line, "%s %s", time, command) != 2)
                        {
                        fprintf(stderr, "Syntax error, line %d\n", linenum);
                        continue;
                        }
		printf("Printing stuff %s %s\n", time, command);
                set_hour = atoi(strtok(time, ":"));
                set_minute = atoi(strtok(NULL, ":"));
        }

/* If all is found, run the rest please */
/* NEEDED: SANITY CHECKING. You lazy bastard you. */

while ( a == a )
  {
	time_t now;
	struct tm *now_tm;
	now = time(NULL);
	now_tm = localtime(&now);
	int hour = now_tm->tm_hour;
	int minute = now_tm->tm_min;
	int trigger_hour=set_hour;
	int trigger_minute=set_minute;
	printf("Time is now %d:%d and set to %d:%d\n",hour, minute, trigger_hour, trigger_minute);
	if (( hour == trigger_hour ) & ( minute == trigger_minute)){
		system("%s", command);
		printf("Awwww jisssssss, we have ran!\n");
	} 
  delay(60);
  }
}

