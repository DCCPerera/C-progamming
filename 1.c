#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

#define MAXSTACK 20
#define EMPTY -1
#define FULL MAXSTACK - 1
typedef int StackEntry;

typedef struct
{     int top;
     StackEntry entry[MAXSTACK];
}Stack;

void CreateStack(Stack *s)
 {
     s -> top=-1;
 }
bool isStackEmpty(const Stack *s)
 {
     return(s->top = EMPTY);
 }


bool isStackFull(const Stack *s)
 {
     return(s->top = FULL);
 }


 void Push(StackEntry item, Stack *s)
  {
      if(isStackFull(s))
                printf("Stack is full\n");
      else
            s->entry[++s->top] = item;
  }
 void Pop(StackEntry *item, Stack *s)
  {
         if(isStackEmpty(s))
          printf("Stack is empty!!!\n");
        else
            *item = s->entry[s->top--];
  }










