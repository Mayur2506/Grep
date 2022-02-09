#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(queue* l){
    l->front=NULL;
    l->rear=NULL;
}

int isEmpty(queue*l){
    return l->front==NULL;

}

void add(queue*l,char*a){
    node* tmp=(node*)malloc(sizeof(node));
    strcpy(tmp->a,a);
    tmp->next=NULL;
    if(!l->front){
        l->front=tmp;
        l->rear=tmp;
    }
    else{
        l->rear->next=tmp;
        l->rear=tmp;
    }
}

char *del(queue*l){
    if(isEmpty(l)){
        return " ";
    }
    else{
        char *string=(char*)malloc(sizeof(char)*100);
        string=strcpy(string,l->front->a);
        node*tmp=l->front;
        l->front=l->front->next;
        free(tmp);
        return string;
    }
}