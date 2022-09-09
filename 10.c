#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
typedef enum { NO, YES } BOOL;

typedef struct Node {
 int data;
 char *lpNum;
 struct Node * next;
} NODE_t;

typedef NODE_t * NODE_p_t;

NODE_p_t createNode ()
{
 NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
 temp-> next = temp;
 temp-> data = 0;
 temp-> lpNum = (char *)malloc(SIZE * sizeof(char));
 return temp;
}


void addCar (NODE_p_t queue, char *lpNum)
{
 NODE_p_t temp = createNode();
 NODE_p_t p;

 strcpy(temp->lpNum, lpNum);
 temp-> next = queue;

 if (queue->next == queue)
 queue-> next = temp;

 else {
 p = queue-> next;

 while (p->next != queue)
 p = p-> next;
 p-> next = temp;
 }
 (queue-> data)++;
}



void removeCar (NODE_p_t queue, char *lpNum)
{
 NODE_p_t temp = queue;
 NODE_p_t p;

 while (temp->next != queue)
    {
 p = temp-> next;
 if (strcmp(lpNum, p->lpNum) == 0)
        {
 (queue-> data)--;
 temp-> next = p->next;
 free(p);
 return;
        }
 temp = temp-> next;
    }
}



BOOL containsCar (NODE_p_t queue, char *lpNum)
{
 NODE_p_t temp = queue->next;
 while (temp != queue)
    {
 if (strcmp(lpNum, temp->lpNum == 0))
 return YES;
 temp = temp-> next;
    }
 return NO;
}




int main (int argc,const char * argv [])
{

 NODE_p_t carpark = createNode();
 char arrDep;
 char *lpNum = (char *)malloc(SIZE * sizeof(char));

 do
{
 printf("\n\tGIVE INPUT: ");
 scanf(" %c", &arrDep);
 scanf(" %s", lpNum);

 if (arrDep == 'A')
{

 if (carpark->data < 10)
    {
 printf("\n\tAdding car '%s' to car park.\n", lpNum);
 addCar(carpark, lpNum);
    }

else
     {
 printf("\n\tParking Full! \n\n");
 continue;
     }
}

 else if (arrDep == 'D')
 {

 if (containsCar(carpark, lpNum))
   {
 printf("\n\tRemoving car '%s' from car park.\n", lpNum);
 removeCar(carpark, lpNum);
   }
else
   {
 printf("\n\tCar '%s' not found in car park.\n", lpNum);
 continue;
   }

 }

 } while (arrDep == 'A' || arrDep == 'D');

 return 0;
}

