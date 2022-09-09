#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50
typedef enum { NO, YES } BOOL;
typedef struct Node {
 int data;
 char *lpNo;
 struct Node * next;
} NODE_t;
typedef NODE_t * NODE_p_t;
NODE_p_t createNode () {
 NODE_p_t temp = (NODE_p_t)malloc(sizeof(NODE_t));
 temp-> next = temp;
 temp-> data = 0;
 temp-> lpNo = (char *)malloc(SIZE * sizeof(char));
 return temp;
}
void addCar (NODE_p_t queue, char *lpno) {
 NODE_p_t temp = createNode();
 NODE_p_t p;

 strcpy(temp->lpNo, lpno);
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
void removeCar (NODE_p_t queue, char *lpno) {
 NODE_p_t temp = queue;
 NODE_p_t p;

 while (temp->next != queue) {
 p = temp-> next;
 if (strcmp(lpno, p->lpNo) == 0) {
 (queue-> data)--;
 temp-> next = p->next;
 free(p);
 return;
 }
 temp = temp-> next;
 }
}
BOOL containsCar (NODE_p_t queue, char *lpno) {
 NODE_p_t temp = queue->next;
 while (temp != queue) {
 if (strcmp(lpno, temp->lpNo) == 0)
 return YES;
 temp = temp-> next;
 }
 return NO;
}
int main (int argc, const char * argv []) {

 NODE_p_t scratchEmUp = createNode();
 NODE_p_t knockEmDown = createNode();
 NODE_p_t streetThugs = createNode();

 char arrDep;
 char *lpNo = (char *)malloc(SIZE * sizeof(char));

 do {
 printf("\n\tGIVE INPUT: ");
 scanf(" %c", &arrDep);
 scanf(" %s", lpNo);

 if (arrDep == 'A') {

 if (scratchEmUp->data < 10) {
 printf("\n\tAdding car '%s' to ScratchEmUp garage.\n", lpNo);
 addCar(scratchEmUp, lpNo);
 }

 else if (knockEmDown->data < 8) {
 printf("\n\tAdding car '%s' to KnockEmDown garage.\n", lpNo);
 addCar(knockEmDown, lpNo);
 }

 else if (streetThugs->data < 8) {
 printf("\n\tAdding car '%s' to the Street.\n", lpNo);
 addCar(streetThugs, lpNo);
 }

 else {
 printf("\n\tParking and Street Full! Only handicap parking space available. Are you actually thinking of parking there?\n\n");
 continue;
 }
 }

 else if (arrDep == 'D') {

 if (containsCar(scratchEmUp, lpNo)) {
 printf("\n\tRemoving car '%s' from ScratchEmUp garage.\n", lpNo);
 removeCar(scratchEmUp, lpNo);
 }

 else if (containsCar(knockEmDown, lpNo)) {
 printf("\n\tRemoving car '%s' from KnockEmDown garage.\n", lpNo);
 removeCar(knockEmDown, lpNo);
 }

 else if (containsCar(streetThugs, lpNo)) {
 printf("\n\tRemoving car '%s' from the street.\n", lpNo);
 removeCar(streetThugs, lpNo);
 }

 else {
 printf("\n\tCar '%s' not found in both garages or streets. It'sloudly.\n", lpNo);
 continue;
 }

 }

 } while (arrDep == 'A' || arrDep == 'D');

 return 0;
}
