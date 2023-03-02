#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if(head==NULL ){
        smaller = NULL;
        larger = NULL;
    return;
    
    } else if(head->val > pivot){
    
    //put in larger   
    larger = head;
    head = head->next;
    larger->next = NULL; 
    llpivot(head, smaller, larger->next, pivot);


    } else if(head->val <= pivot) {
   
    //put in smaller
    smaller = head;
    head = head->next;
    smaller->next = NULL; 
    llpivot(head, smaller->next, larger, pivot);   
    
    }
}

// llrec-test1.in
//8 9 12 19 6 8