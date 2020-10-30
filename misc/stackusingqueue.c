#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Queue {
int front, rear, size;
unsigned capacity;
int* array;
};
struct Queue* createQueue(unsigned capacity)
{
struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
q->capacity = capacity;
q->front = q->size = 0;
q->rear = capacity - 1;
q->array = (int*)malloc(q->capacity * sizeof(int));
return q;
}
struct stack{
struct Queue*q1;
struct Queue*q2;
int size;
};
struct stack* createStack(unsigned capacity)
{
struct stack* s = (struct stack*)malloc(sizeof(struct stack));
s->q1=createQueue(capacity);
s->q2=createQueue(capacity);
s->size=0;
return s;
}
int isFull_stack(struct stack* s)
{
return (s->size ==s->q1->capacity);
}
int isEmpty_stack(struct stack* s)
{
return (s->size==0);
}
int isFull(struct Queue* q)
{
return (q->size == q->capacity);
}int isEmpty(struct Queue* q)
{
return (q->size == 0);
}
void enqueue(struct Queue*q, int data)
{
if(isFull(q)){
return;
}
q->rear=(q->rear+1)%(q->capacity);
q->array[q->rear]=data;
q->size=q->size+1;
}
void dequeue(struct Queue* q)
{
if (isEmpty(q))
return;
int item = q->array[q->front];
q->front = (q->front + 1)% q->capacity;
q->size =q->size-1;
if(q->size==0){
q->front = 0;
q->rear = q->capacity - 1;
}
}
int front(struct Queue* queue)
{
if (isEmpty(queue))
return INT_MIN;
return queue->array[queue->front];
}
int rear(struct Queue* q)
{
if (isEmpty(q))
return INT_MIN;
return q->array[q->rear];
}
void push(struct stack*s,int data){
if(isFull_stack(s)){
printf("Stack Overflow");
return;
}
s->size=s->size+1;
enqueue(s->q2,data);
while(!(isEmpty(s->q1))){enqueue(s->q2,front(s->q1));
dequeue(s->q1);
}
struct Queue*q=s->q1;
s->q1=s->q2;
s->q2=q;
}
void pop(struct stack*s){
if(isEmpty_stack(s)){
printf("Stack Underflow");
return;
}
dequeue(s->q1);
s->size=s->size-1;
}
int top(struct stack*s){
if(isEmpty_stack(s)){
return -1;
}
return front(s->q1);
}
int main(){
struct stack* s=createStack(100);
push(s,3);
push(s,5);
push(s,9);
push(s,1);
push(s,12);
push(s,15);
printf("Element at top of the stack: %d\n" ,top(s));
printf("Elements: \n");
// print stack data
while(!isEmpty_stack(s)) {
int data = top(s);
pop(s);
printf("%d\n",data);
}
printf("Stack full: %s\n" , isFull_stack(s)?"true":"false");
printf("Stack empty: %s\n" , isEmpty_stack(s)?"true":"false");
return 0;
}
