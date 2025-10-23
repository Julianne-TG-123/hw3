#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //base case
  if(!head){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  //detach front to temp
  Node* temp = head;
  head = head->next;
  temp->next = nullptr;

  //recursive call for rest of list 
  llpivot(head, smaller, larger, pivot);

  //move "temp"
  if(temp->val <= pivot){
    //insert at front of smaller list
    temp->next = smaller;
    smaller = temp;
  } else {
    //insert at front of larger list
    temp->next = larger;
    larger = temp;
  }

}