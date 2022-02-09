typedef struct node
{
    char a[1000];
    struct node *next;  
}node;

typedef struct queue
{
    node *front;
    node *rear;
}queue;

void init(queue* );
void add(queue*,char*);
char *del(queue*);
int isEmpty(queue*);
