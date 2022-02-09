run : grep.o usage.o queue.o flags.o 
	gcc -Wall -o mygrep *.o
	
clean :
	rm *.o	

usage : usage.c flags.h
	gcc -c usage.c
		
grep : grep.c 
	gcc -c grep.c
	
queue : queue.c queue.h
	gcc -c queue.c 
	
flags : flags.c flags.c queue.h
	gcc -c flags.c 
	
