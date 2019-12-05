all: cronton.c

	# Build binary
	gcc -o cronton cronton.c

	# Generate cronton.conf example file
	@echo "# Config file for cronton" > cronton.conf
	@echo "# Please see readme for explanation of it's contents" >> cronton.conf
	@echo "13:37 task.sh" >> cronton.conf

	# Generate example task.sh
	@echo "#!/bin/bash" > task.sh
	@echo "#" >> task.sh
	@echo "# Example task. Please see readme for explanation" >> task.sh
	@echo "echo \"LEET TIME!\"" >> task.sh

	# Generate readme file
	@echo "cronton, the totally useless not-cron process to schedule one (1) task." > readme
	@echo "Created because of a challenge. Yes, talking to you, Ries and Jor." >> readme
	@echo "TL;DR: See last line of this file" >> readme
	@echo " " >> readme
	@echo "This program checks the config file for one (1) task to do at a certain time," >> readme
	@echo "wasting clock cycles untill it is time to do the task at hand (Or file for that matter)." >> readme
	@echo "The program expects at least a cronton.conf file, either in the working dir or in" >> readme
	@echo "/etc/cronton. The file must contain a single timestamp and command. Just one." >> readme
	@echo "It looks like this:" >> readme
	@echo " " >> readme
	@echo "13:37 task.sh" >> readme
	@echo " " >> readme
	@echo "Meaning at 13:17 time, task.sh will be executed as the user running the cronton process." >> readme
	@echo "Obviously, if you run this a s root you are out of your mind and subsequent hacks are your own fault." >> readme
	@echo " " >> readme
	@echo "The task should be a self-running thingy like a php, python or shell script." >> readme
	@echo " " >> readme
	@echo "And just in case you did not read all of the above:" >> readme
	@echo "THIS USELESS PROGRAM POSES A SECURITY RISK SO DO NOT RUN ON ANYTHING YOU INTEND ON KEEPING!" >> readme

	chmod 644 cronton.conf
	chmod 644 readme
	chmod 755 task.sh





clean:
	rm -rf cronton
	rm -rf cronton.conf
	rm -rf task.sh