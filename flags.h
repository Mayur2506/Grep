#define NORMAL 	 "\x1B[0m"
#define RED  	 "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYN      "\x1B[36m"
#define WHITE    "\x1B[37m"
#include "queue.h"


void usage();

char *uppertolowercase(char *);
void Hprint(char *filename);
void highlight(char *, char *);
void addfilesrecursively(char *,queue *);
void Nprint(int );
void makelines(char *,char *);
void hmakelines(char *,char *);
char* xpselect(char *,char*);
int wfind(char *,char* );
void imakelines(char *,char *,int );
void nimakelines(char *,char *,int );
void bimakelines(char *,char *,int );
void wimakelines(char *,char *,int);
void cimakelines(char *,char *,int);
void vimakelines(char *,char *,int );
void nmakelines(char *,char *,int );
void vnmakelines(char *,char *,int );
void vmakelines(char *,char *,int );
void cmakelines(char *,char *,int);
void Hmakelines(char *,char *);
void mmakelines(char *,char *,int ,int );
void bmakelines(char *,char *,int);
void wmakelines(char *,char *,int );
void wnmakelines(char *,char *,int );
void lmakelines(char *,char*);
void Lmakelines(char *,char*);

