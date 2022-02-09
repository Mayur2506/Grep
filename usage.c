#include <stdio.h>

void usage () {
	
    printf("  DSA MINIPROJECT GREP\n");
    printf("  -- Mayur Kongutte  MIS No. 112003072\n");
    printf("  Usage :  grep [OPTION...] PATTERNS [FILE...]\n");
    printf("  --help : output a usage message and exit\n");
    printf("  -w : Select only those lines containing matches that form  whole words.\n");
    printf("  -v : Invert the sense of matching, to select non-matching lines.\n");
    printf("  -i : Ignore case distinctions\n");
	printf("       Combinations Available in i flag are -in/-ni,-iv/-vi,-ic/-ci,-ib/-bi,-iw/-wi");
    printf("  -h : Suppress  the  prefixing  of file names on output.\n");
    printf("  -n : Prefix each line of output with  the  1-based  line  number within its input file.\n");
	printf("       Combinations Available in n flag are -nv/-vn,-nw/-wn\n");
    printf("  -m NUM  : Stop reading a file after NUM matching lines \n");
    printf("  -c : print a count  of  matching lines  for  each  input  file.\n");
    printf("  -H : Print the file name for each match. \n");
    printf("  -b : Print the 0-based byte offset within the input file  before each line of output.\n");
    printf("  -r : Read all files under each directory, recursively, following symbolic  links only if they are on the command line\n");
    printf("       Combinations Available in r flag are -ri/-ir,-rv/-vr,-rb/-br,-rn/-nr,-rc/-cr/-rh/-hr,-rH/-Hr,-rw/-wr\n");
    printf("  -q : Quiet; do not write  anything  to  standard  output.\n");
    printf("  -l :  Suppress  normal  output;  instead  print  the name of each input file from  which  output  would  normally  have  been printed.\n");
    printf("  -L : Suppress  normal  output;  instead  print  the name of each input file from which no output would  normally  have  been printed.  The scanning will stop on the first match.\n");
    
    return;
}
