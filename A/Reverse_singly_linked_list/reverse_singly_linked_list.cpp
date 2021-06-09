#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *next;
};

class SinglyLinkedList{
    node *head = NULL;
public:
    node* recursiveHelper(node *currPtr, node *prevPtr, node *oldHead){

        if(currPtr->next){
            recursiveHelper(currPtr->next, currPtr, oldHead);
        }else{// end node to be set as start node
            head = currPtr;
        }

        if(currPtr != oldHead)
            currPtr->next = prevPtr;
        else    // new end node
            currPtr->next = NULL;
    }

    
    node* recursiveReverse(){
        node *oldHead = head;
        recursiveHelper(head, NULL, oldHead);
    }

// head->
// 5->3->20->NULL

// head->  5
//  N   <-      5    <-       3    <-    20          NULL
//                                     prev,         curr,next
    int iterativeReverse(){
        node *prevPtr = NULL;
        node *currPtr = head;
        node *nextPtr = head->next;

        while(currPtr){
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;

            if(nextPtr != NULL)
                nextPtr = nextPtr->next;
            else{
                head = prevPtr;
                break;
            }
        }

    }

    void insertNode(int value){
        node *newPtr = new node();  
        // node *newPtr = (node*)malloc(sizeof(node));

        newPtr->value = value;
        newPtr->next = NULL;

        node *runningPtr = head;

        // when LL is empty
        if(runningPtr==NULL){
            head = newPtr;
            return;
        }
        
        while(runningPtr->next)
            runningPtr = runningPtr->next;
        runningPtr->next = newPtr;
    }

    void displayLL(){
        node *runningPtr = head;

        while(runningPtr){
            cout<<runningPtr->value<<" ";
            if(runningPtr->next)
                runningPtr = runningPtr->next;
            else
                break;
        }cout<<"\n";

    }
};

int main(){
    
    SinglyLinkedList obj;

    // insert elements into LL
    obj.insertNode(5);
    obj.insertNode(3);
    obj.insertNode(20);
    obj.displayLL();

    obj.recursiveReverse();
    obj.displayLL();

    obj.iterativeReverse();
    obj.displayLL();

}