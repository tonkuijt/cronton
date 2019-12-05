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
        /* Config file name is set but location isn't, lets check where it is */
        if (access("cronton.conf", F_OK) != -1 ){
                return "./cronton.conf";
        } else if (access("/etc/cronton/cronton.conf", F_OK) != -1 ){
                return "/etc/cronton/cronton.conf";
        } else {
                printf("Config file not found!\n");
                exit(1);
        }
        /* Nothing found, notify main process and DIE */
        printf("Config not found, please check documentation.\n");
        exit(1);
}

void delay(int number_of_seconds) 
{ 
        /* CLOCKS_PER_SEC is a timed loop to determine how many cycles
           the loop takes, thus calibrating the delay loop */
	int milli_seconds = CLOCKS_PER_SEC * number_of_seconds;
	clock_t start_time = clock(); 
        //This loop should take 1 cycle per iteration and ALL CPU
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
char command[256], settime[256];
while(fgets(line, 256, file) != NULL)
	{
        linenum++;
        if(line[0] == '#')  continue; 

                if(sscanf(line, "%s %s", settime, command) != 2)
                        {
                        fprintf(stderr, "Syntax error, line %d\n", linenum);
                        continue;
                        }
                set_hour = atoi(strtok(settime, ":"));
                set_minute = atoi(strtok(NULL, ":"));
        }

/* If all is found, run the rest please */
/* NEEDED: SANITY CHECKING. You lazy bastard you. */

for (;;)
  {
	time_t rawtime;
        struct tm * timeinfo;
        time (&rawtime);
        timeinfo = localtime (&rawtime);
	int trigger_hour=set_hour;
	int trigger_minute=set_minute;
        int hour = timeinfo->tm_hour;
        int minute = timeinfo->tm_min;
	if (( hour == trigger_hour ) & ( minute == trigger_minute)){
		system(command);
	} 
  delay(60);
  }
}

