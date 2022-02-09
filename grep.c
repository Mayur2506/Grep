#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<limits.h>
#include <unistd.h>
// #include "queue.h"
#include "flags.h"


int main(int argc,char*argv[]){
	int mulfile=0;
	int opt;
	int fd;
	int hfl=0,rfl=0,ifl=0,Hfl=0,qfl=0,bfl=0,wfl=0,nfl=0,vfl=0,t=0,cfl=0,mfl=0,lfl=0,Lfl=0;
	int NUM;
	char *word=(char*)malloc(sizeof(char)*100);
	word=strcpy(word,argv[argc-2]);
	if(argc == 1) {
		printf("Use ./mygrep --help command for usage\n");
		return 0;
	}
	else if(strcmp(argv[1],"--help") == 0 && argv[2] == NULL) {
		usage();
		return 0;
	}
	if(argc < 3 && strcmp(argv[0], "./mygrep") != 0) {
		printf("Invalid Arguments\n");
		return 0; 
	}
	
	while((opt = getopt(argc, argv,"iblLrqwnmvhHc")) != -1)
	{
		switch(opt)
		{
			case 'i':
                ifl=1;
                break;
			case 'm':
                mfl=1;
                break;	
			case 'b':
				bfl=1;
                break;
			case 'r':
				rfl=1;
				break;
			case 'w':
				wfl=1;
				break;
			case 'H':
				Hfl=1;
				break;	
			case 'n':
				nfl=1;
				break;
			case 'v':
				vfl=1;
				break;
			case 'q':
				qfl=1;
				break;
			case 'c':
				cfl=1;
				break;
			case 'h':
				hfl=1;
				break;
			case 'l':
				lfl=1;
				break;
			case 'L':
				Lfl=1;
				break;					

			default:
				t=1;
				break;
		}
	}

	if(qfl){
		return 0;
	}

	else if(rfl){
		if(argc>4){
			mulfile=1;
			strcpy(word,argv[2]);
			for(int f=3;f<argc;f++){
				DIR *dir;
				queue l;
				queue l1;
				init(&l1);
				char *tmp;
				char *tmp1;
				init(&l);
				dir=opendir(argv[f]);
				if(dir !=NULL){
					addfilesrecursively(argv[f],&l);
					
					while (!isEmpty(&l))
					{
						tmp=del(&l);
						// if(ifl){
						// 	imakelines(tmp,word,mulfile);
						// }
						if(vfl){
							vmakelines(tmp,word,mulfile);
						}
						else if(bfl){
							
							bmakelines(tmp,word,mulfile);
						}
						else if(nfl){
							nmakelines(tmp,word,mulfile);
						}
						else if(cfl){
							cmakelines(tmp,word,mulfile);
						}
						else if(hfl){
							hmakelines(tmp,word);
						}
						else if(Hfl){
							Hmakelines(tmp,word);
						}
						else if(wfl){
							wmakelines(tmp,word,mulfile);
						}
						else{
							makelines(tmp,word);
						}					
					}
				}
				else{
					if(ifl){
						imakelines(argv[f],word,mulfile);
					}
					else if(vfl){
						vmakelines(argv[f],word,mulfile);
					}
					else if(bfl){
						bmakelines(argv[f],word,mulfile);
					}
					else if(cfl){
						cmakelines(argv[f],word,mulfile);
					}
					else if(nfl){
						nmakelines(argv[f],word,mulfile);
					}
					else if(hfl){
						hmakelines(argv[f],word);
					}
					else if(Hfl){
						Hmakelines(argv[f],word);
					}
					else if(wfl){
						wmakelines(argv[f],word,mulfile);
					}
					else{
						makelines(argv[f],word);
					}	
				}
			}	
		}
		else{
			mulfile=0;
			strcpy(word,argv[2]);
			// printf("%s",word);
			queue l;
			init(&l);
			// queue l1;
			// init(&l1);
			char *tmp=(char*)malloc(sizeof(char)*1000);
			char *tmp1;
			DIR *dir;
			dir=opendir(argv[argc-1]);
			if(dir !=NULL){
				addfilesrecursively(argv[argc-1],&l);
				while (!isEmpty(&l))
				{
					// tmp=del(&l);
					strcpy(tmp,del(&l));
					mulfile=1;
					// printf("%s\n",tmp);
					// if(ifl){
					// 	imakelines(tmp,word,mulfile);
					// }
					if(vfl){
						vmakelines(tmp,word,mulfile);
					}
					else if(bfl){
						bmakelines(tmp,word,mulfile);
					}
					else if(nfl){
						nmakelines(tmp,word,mulfile);
					}
					else if(hfl){
						hmakelines(tmp,word);
					}
					else if(Hfl){
						Hmakelines(tmp,word);
					}
					else if(wfl){
						wmakelines(tmp,word,mulfile);
					}
					else if(cfl){
						cmakelines(tmp,word,mulfile);
					}
					else{
						makelines(tmp,word);
					}
									
				}
			}
			else{
				if(ifl){
					imakelines(argv[argc-1],word,mulfile);
				}
				else if(vfl){
					vmakelines(argv[argc-1],word,mulfile);
				}
				else if(bfl){
					bmakelines(argv[argc-1],word,mulfile);
				}
				else if(nfl){
					nmakelines(argv[argc-1],word,mulfile);
				}
				else if(cfl){
					cmakelines(argv[argc-1],word,mulfile);
				}
				else if(wfl){
					wmakelines(argv[argc-1],word,mulfile);
				}
				else if(hfl){
					hmakelines(argv[argc-1],word);
				}
				else if(Hfl){
					Hmakelines(argv[argc-1],word);
				}
				else{
					makelines(argv[argc-1],word);
				}
				
			}

		}	
		
	}
	else if(ifl==1 && rfl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				if(nfl){
					nimakelines(xc,word,mulfile);
				}
				else if(cfl){
					cimakelines(xc,word,mulfile);
				}
				else if(vfl){
					vimakelines(xc,word,mulfile);
				}
				else if(bfl){
					bimakelines(xc,word,mulfile);
				}
				else if(wfl){
					wimakelines(xc,word,mulfile);
				}
				else{
					imakelines(xc,word,mulfile);
				}		
			}
		}
		else{
			if(nfl){
				nimakelines(argv[argc-1],word,mulfile);
			}
			else if(cfl){
				cimakelines(argv[argc-1],word,mulfile);
			}
			else if(vfl){
				vimakelines(argv[argc-1],word,mulfile);
			}
			else if(bfl){
				bimakelines(argv[argc-1],word,mulfile);
			}
			else if(wfl){
				wimakelines(argv[argc-1],word,mulfile);
			}
			else{
				imakelines(argv[argc-1],word,mulfile);
			}
		}
	}

	else if(nfl && rfl==0 && ifl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);                                              //iw 
				if(vfl){
					vnmakelines(xc,word,mulfile);
				}
				else if(wfl){
					wnmakelines(xc,word,mulfile);
				}
				else{
					nmakelines(xc,word,mulfile);
				}		
			}
		}
		else{
				if(vfl){
					vnmakelines(argv[argc-1],word,mulfile);
				}
				else if(wfl){
					wnmakelines(argv[argc-1],word,mulfile);
				}
				else{
					nmakelines(argv[argc-1],word,mulfile);
				}
		}

	}
	else if(vfl && rfl==0 && ifl==0 && nfl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				vmakelines(xc,word,mulfile);	
			}
		}
		else{
			vmakelines(argv[argc-1],word,mulfile);
		}
		
	}
	else if(cfl && rfl==0 && ifl==0 && nfl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				cmakelines(xc,word,mulfile);	
			}
		}
		else{
			cmakelines(argv[argc-1],word,mulfile);
		}
	}
	else if(Hfl && rfl==0){
		if(argc>3){
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				Hmakelines(xc,word);	
			}
		}		
	}
	else if(mfl){
		NUM=atoi(argv[2]);		
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[3]);
				strcpy(xc,argv[f]);
				mmakelines(xc,word,NUM,mulfile);	
			}
		}
		else{
			mmakelines(argv[argc-1],word,NUM,mulfile);
		}

	}
	else if(bfl && rfl==0 && ifl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				bmakelines(xc,word,mulfile);	
			}
		}
		else{
			bmakelines(argv[argc-1],word,mulfile);
		}

	}
	else if(wfl && rfl==0){
		if(argc>4){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				wmakelines(xc,word,mulfile);	
			}
		}
		else{
			wmakelines(argv[argc-1],word,mulfile);
		}

	}
	else if(hfl && rfl==0){
		if(argc>3){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				hmakelines(xc,word);	
			}
		}

	}
	else if(lfl){
		if(argc>3){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				lmakelines(xc,word);	
			}
		}

	}
	else if(Lfl){
		if(argc>3){
			mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=3;f<argc;f++){
				strcpy(word,argv[2]);
				strcpy(xc,argv[f]);
				Lmakelines(xc,word);	
			}
		}

	}
	else{
		if(argc>3){
			// mulfile=1;
			char *xc=(char*)malloc(sizeof(char)*1000);
			for(int f=2;f<argc;f++){
				strcpy(word,argv[1]);
				strcpy(xc,argv[f]);
					FILE* ptr;
					char sptr[1000];
					char *oword=(char*)malloc(sizeof(char)*1000);
					ptr = fopen(xc, "a+");
					if (ptr==NULL) {
						printf("file can't be opened \n");
					}
					while (fgets(sptr, 1000, ptr) != NULL) {
						char*z;
						strcpy(oword,sptr);
						z = strstr(sptr,word);
						if(z){
							Hprint(xc);
							highlight(oword,word);
						}
						
					}
					fclose(ptr);		
			}		
					
			
		}
		else{
				strcpy(word,argv[1]);
				char *xc=(char*)malloc(sizeof(char)*1000);
				strcpy(xc,argv[2]);
				FILE* ptr;
				char sptr[1000];
				char *oword=(char*)malloc(sizeof(char)*1000);
				ptr = fopen(xc, "a+");
				if (ptr==NULL) {
					printf("file can't be opened \n");
				}
				while (fgets(sptr, 1000, ptr) != NULL) {
						char*z;
						strcpy(oword,sptr);
						z = strstr(sptr,word);
						if(z)
							highlight(oword,word);
						
				}
				fclose(ptr);
			

		}

	}



    return 0;
}


