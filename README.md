# cronton
cronton, the totally useless not-cron process to schedule one (1) task.
Created because of a challenge. Yes, talking to you, Ries and Jor.

TL;DR: See last line of this file

This program checks the config file for one (1) task to do at a certain time,
wasting clock cycles untill it is time to do the task at hand (Or file for that matter).
The program expects at least a cronton.conf file, either in the working dir or in
/etc/cronton. The file must contain a single timestamp and command. Just one.
It looks like this:

13:37 task.sh

Meaning at 13:17 time, task.sh will be executed as the user running the cronton process.
Obviously, if you run this a s root you are out of your mind and subsequent hacks are your own fault.

The task should be a self-running thingy like a php, python or shell script.

And just in case you did not read all of the above:

THIS USELESS PROGRAM POSES A SECURITY RISK SO DO NOT RUN ON ANYTHING YOU INTEND ON KEEPING!



