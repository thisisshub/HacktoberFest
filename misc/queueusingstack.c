#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct stack{
int top;
unsigned capacity;
int*array;
};
struct stack* createStack(unsigned c){
struct stack*s=(struct stack*)malloc(sizeof(struct stack));
s->capacity=c;
s->top=-1;
s->array=(int*)malloc((s->capacity)*sizeof(int));
return s;
}
struct queue{
struct stack*s1;
struct stack*s2;
int size;
};
struct queue* createQueue(unsigned capacity)
{
struct queue*q= (struct queue*)malloc(sizeof(struct queue));
q->s1=createStack(capacity);
q->s2=createStack(capacity);
q->size=0;
return q;
}
int isfull(struct stack* s){
if(s->top==s->capacity){
return 1;
}
else{
return 0;
}
}
int isempty(struct stack* s){
if(s->top==-1){
return 1;}
else{
return 0;
}
}
int isFull_queue(struct queue* q)
{
return (q->size == q->s1->capacity);
}
int isEmpty_queue(struct queue* q)
{
return (q->size == 0);
}
int peek(struct stack* s) {
if(isempty(s)){
printf("stack is empty");
return INT_MIN;
}
return (s->array[s->top]);
}
void pop(struct stack* s){
int data;
if(!isempty(s)) {
data = s->array[s->top];
s->top = s->top - 1;
} else {
printf("stack underflow\n");
}
}
int push(struct stack* s,int data) {
if(!isfull(s)) {
s->top = s->top + 1;
s->array[s->top] = data;
} else {
printf("stack overflow\n");
}
}
void enqueue(struct queue*q,int data){
if(isfull(q->s1)){
return;
}
push(q->s1,data);
(q->size)++;
}
int dequeue(struct queue*q){if((isempty(q->s1))&&((isempty(q->s2)))){
return -1;
}
while (!(isempty(q->s1)))
{
push(q->s2,peek(q->s1));
pop(q->s1);
}
int x=peek(q->s2);
pop(q->s2);
return x;
}
int main(){
struct queue* q = createQueue(4);
enqueue(q, 10);
enqueue(q, 20);
enqueue(q, 30);
enqueue(q, 40);
printf("%d dequeued from queue\n\n",dequeue(q));
printf("%d dequeued from queue\n\n",dequeue(q));
return 0;
}
