#include "flags.h"
// #include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<dirent.h>




void makelines(char *str,char *word){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z){
			Hprint(str);
			highlight(oword,word);
		}
		
	}
			
	fclose(ptr);

}
void hmakelines(char *str,char *word){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z){
			highlight(oword,word);
		}
		
	}
			
	fclose(ptr);

}

char* xpselect(char *line,char*word){
	int k=strlen(word);
    int lz=0,i=0,gb=0,tr=0,tp=0;
    char *reword=(char*)malloc(sizeof(char)*1000);
    char *oword=(char*)malloc(sizeof(char)*1000);
    char *oline=(char*)malloc(sizeof(char)*1000);
    strcpy(oword,word);
    strcpy(oline,line);
    char *p=uppertolowercase(oline);
    char *z=uppertolowercase(oword);
    char *a=strstr(p,z);
    if(a){
        while(a[lz]!='\0'){
            lz++;            
        }
        while(oline[i]!='\0'){
            i++;
        }
        int gb=i-lz;
        while(k){
            reword[tp++]=line[gb++];
            k--;
        }
        
    }
    return reword;
}
int wfind(char *line,char* word){
    char *newline=(char*)malloc(sizeof(char)*1000);
    int k=strlen(word);
    int i=0,j=0;
    char *z=strstr(line,word);
    if(z){
        if(z[k]==' '|| z[k]=='\0' || z[k]=='\n'){
            return 1;
        }
        else{
            for(int i=k;i<strlen(z);i++){
                newline[j++]=z[i];   
            }
            wfind(newline,word);
        }
    }
    else{
        return 0;
    }
}

void imakelines(char *str,char *word,int mulfile){
	char *tword=(char*)malloc(sizeof(char)*1000);	
	char*originalword=(char*)malloc(sizeof(char)*1000);
	// char sword[50];
	char *oword=(char*)malloc(sizeof(char)*1000);
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	strcpy(oword,word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z){
			strcpy(tword,word);
			originalword=xpselect(oline,tword);
			if(mulfile){
				Hprint(str);
			}
			highlight(oline,originalword);
		}

	}
	
	fclose(ptr);
	return;

}
void nimakelines(char *str,char *word,int mulfile){
	char *tword=(char*)malloc(sizeof(char)*1000);	
	char*originalword=(char*)malloc(sizeof(char)*1000);
	char sword[50];
	int f=0;
	char *oword=(char*)malloc(sizeof(char)*1000);
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	strcpy(oword,word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		f++;
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z){
			strcpy(tword,word);
			originalword=xpselect(oline,tword);
			if(mulfile){
				Hprint(str);
			}
			Nprint(f);
			highlight(oline,originalword);
		}

	}
	
	fclose(ptr);
	return;

}
void bimakelines(char *str,char *word,int mulfile){
	char *tword=(char*)malloc(sizeof(char)*1000);	
	char*originalword=(char*)malloc(sizeof(char)*1000);
	char sword[50];
	int f=0;
	char *oword=(char*)malloc(sizeof(char)*1000);
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	strcpy(oword,word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		int tz=0;
		strcpy(oword,sptr);
		while (oword[tz]!='\0')
		{
			tz++;
		}
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z){
			strcpy(tword,word);
			originalword=xpselect(oline,tword);
			if(mulfile){
				Hprint(str);
			}
			Nprint(f);
			highlight(oline,originalword);
		}
		f+=tz;

	}
	
	fclose(ptr);
	return;

}
void wimakelines(char *str,char *word,int mulfile){
	char *tword=(char*)malloc(sizeof(char)*1000);	
	char*originalword=(char*)malloc(sizeof(char)*1000);
	char sword[50];
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}

	while (fgets(sptr, 1000, ptr) != NULL) {
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z){
			strcpy(tword,word);
			originalword=xpselect(oline,tword);
			if(wfind(oline,word)){
				if(mulfile){
					Hprint(str);
				}
				highlight(oline,originalword);
			}	
		}

	}
	
	fclose(ptr);
	return;

}
void cimakelines(char *str,char *word,int mulfile){
	char *tword=(char*)malloc(sizeof(char)*1000);	
	char*originalword=(char*)malloc(sizeof(char)*1000);
	char sword[50];
	int f=0;
	char *oword=(char*)malloc(sizeof(char)*1000);
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	strcpy(oword,word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z){
			f++;
			strcpy(tword,word);
		}
		
	}
	if(mulfile){
		Hprint(str);
	}
	printf("%d",f);
	printf("\n");
	fclose(ptr);
	return;

}
void vimakelines(char *str,char *word,int mulfile){

	char sword[50];
	char *oword=(char*)malloc(sizeof(char)*1000);
	char *oline=(char*)malloc(sizeof(char)*1000);
	char *wq=uppertolowercase(word);
	strcpy(oword,word);
	char sptr[1000];
	char *k=(char*)malloc(sizeof(k)*1000);
	FILE* ptr;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		// f++;
		strcpy(oline,sptr);
		k=uppertolowercase(sptr);
		char*z;
		z = strstr(k,wq);
		if(z==NULL){
			if(mulfile){
				Hprint(str);
			}
			printf("%s",oline);
		}

	}
	
	fclose(ptr);
	return;

}


void nmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		f++;
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z){
			if(mulfile){
				Hprint(str);
			}
			Nprint(f);
			highlight(oword,word);
		}
		
	}
			
	fclose(ptr);

}
void vnmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		f++;
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z==NULL){
			if(mulfile){
				Hprint(str);
			}
			Nprint(f);
			printf("%s",oword);
		}
		
	}
			
	fclose(ptr);

}

void vmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		f++;
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z==NULL){
			if(mulfile){
				Hprint(str);
			}
			printf("%s",oword);
		}
		
	}
			
	fclose(ptr);

}
void cmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char*z;
		z = strstr(sptr,word);
		if(z){
			f++;
		}
		
	}
	if(mulfile){
		Hprint(str);
	}
	printf("%d\n",f);
			
	fclose(ptr);

}
void Hmakelines(char *str,char *word){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z){
			Hprint(str);
			highlight(oword,word);		
		}
		
	}
			
	fclose(ptr);

}

void mmakelines(char *str,char *word,int NUM,int mulfile){

	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		if(f==NUM){
			return;
		}
		char*z;
		strcpy(oword,sptr);
		z = strstr(sptr,word);
		if(z){
			f++;
			if(mulfile){
				Hprint(str);
			}
			highlight(oword,word);		
		}
		
	}
			
	fclose(ptr);

}

void bmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oword=(char*)malloc(sizeof(char)*1000);
	int f=0,b=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		int tz=0;
		strcpy(oword,sptr);
		while (oword[tz]!='\0')
		{
			tz++;
		}
		char *z = strstr(sptr,word);
		if(z){
			if(mulfile){
				Hprint(str);
			}
			Nprint(b);
			highlight(oword,word);
					
		}
		b+=(tz);
	}
			
	fclose(ptr);

}


void wmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oline=(char*)malloc(sizeof(char)*1000);
	int f=0,b=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		strcpy(oline,sptr);
		char *z=strstr(sptr,word);
		if(z){
			if(wfind(sptr,word)){
				if(mulfile){
					Hprint(str);
				}
				highlight(sptr,word);
			}

		}

	}
			
	fclose(ptr);

}
void wnmakelines(char *str,char *word,int mulfile){
	FILE* ptr;
	char sptr[1000];
	char *oline=(char*)malloc(sizeof(char)*1000);
	int f=0,b=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		f++;
		strcpy(oline,sptr);
		char *z=strstr(sptr,word);
		if(z){
			if(wfind(sptr,word)){
				if(mulfile){
					Hprint(str);
				}
				Nprint(f);
				highlight(sptr,word);
			}

		}

	}
			
	fclose(ptr);

}

void lmakelines(char *str,char*word){
	FILE* ptr;
	char sptr[1000];
	int f=0,b=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char *z=strstr(sptr,word);
		if(z){
			printf(MAGENTA);
			printf("%s\n",str);
			printf(NORMAL);
			break;
		}

	}
			
	fclose(ptr);
}
void Lmakelines(char *str,char*word){
	FILE* ptr;
	char sptr[1000];
	int f=0,b=0;
	ptr = fopen(str, "r");
	if (ptr==NULL) {
		printf("file can't be opened \n");
	}
	while (fgets(sptr, 1000, ptr) != NULL) {
		char *z=strstr(sptr,word);
		if(z){
			fclose(ptr);
			return;	
		}
	}
	printf(MAGENTA);
	printf("%s\n",str);
	printf(NORMAL);		
	
}
char *uppertolowercase(char *string) {
	int i;
	for(i = 0; i < strlen(string); i++) {
		if(string[i] >= 65 && string[i] <= 90)
			string[i] = string[i] + 32;
	}
	return string;
}
void Hprint(char *filename) {
	printf(MAGENTA);
    printf("%s", filename);
    printf(BLUE);
    printf(":");
    printf(NORMAL);
	return;
}	

void highlight(char *line, char *word) {
	int h, i =0, j = strlen(word);
	char *str;
	str = strstr(line, word);
	h = strlen(str);
	h = strlen(line) - h;
	while(line[i] != '\0') {
		if(i == h) {
			while(j) {
				printf(RED);
				printf("%c", line[i]);
				printf(NORMAL);
				j--;
				i++;
			}
		}
		else {
			printf("%c", line[i]);
			i++;
		}
	}
	
	return;
}




void addfilesrecursively(char *basePath,queue *l){

    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    if (!dir) 
        return;
    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
        	if(strcmp(basePath, ".") != 0) {
           		strcpy(path, basePath);
            	strcat(path, "/");
            	strcat(path, dp->d_name);
        	} 
        	else
        		strcpy(path, dp->d_name);
    
    		int k = 0;
    		while(path[k] != '\0') {
    			if(path[k] == '.') {
    				if((path[strlen(path) - 1] != 'o') && (strcmp(path, "a.out") != 0) && path[strlen(path) - 1] != 'h') {
    	    			add(l,path); 
    				}
    			}
    			k++;
    		}
    		addfilesrecursively(path, l);
		}
    }

    closedir(dir);
}

void Nprint(int k){
	printf(GREEN);
	printf("%d",k);
	printf(BLUE);
	printf(":");
	printf(NORMAL);
}