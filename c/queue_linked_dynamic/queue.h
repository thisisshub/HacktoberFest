
#define FLUSH while(getchar()!='\n')

struct NODE{
        int info;
        struct NODE *next;
        };

typedef struct NODE* QUEUE;

void init(QUEUE *q);

int is_empty(QUEUE q);

void print_queue(QUEUE q);

int insert(QUEUE *q, int Elem);

int pop(QUEUE *q, int *Elem);

int read_top(QUEUE q, int *topo);
