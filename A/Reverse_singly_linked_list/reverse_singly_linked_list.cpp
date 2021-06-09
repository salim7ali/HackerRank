#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *next;
};

// head->
// 5->3->20->NULL

// head->
// 5-> <-3<-20 
class SinglyLinkedList{
    node *oldHead = NULL;
    node *newHead;
public:
    node* recursiveReverse(node *currPtr, node *prevPtr){

        if(currPtr->next){
            recursiveReverse(currPtr->next, currPtr);
        }else{// end node to be set as start node
            newHead = currPtr;
        }

        if(currPtr != oldHead)
            currPtr->next = prevPtr;
        else    // new end node
            currPtr->next = NULL;
    }

    int iterativeReverse(){
        node *runningPtr = head;

        while(runningPtr){
            runningPtr = runningPtr->next;
        }

    }

    void insertNode(int value){
        node *newPtr = new node();  
        // node *newPtr = (node*)malloc(sizeof(node));

        newPtr->value = value;
        newPtr->next = NULL;

        node *runningPtr = oldHead;
        while(runningPtr->next)
            runningPtr = runningPtr->next;
        runningPtr->next = newPtr;
    }

    void addItem(){

    }
};

int main(){
    
    SinglyLinkedList obj;

    // insert elements into LL
    obj.insertNode(5);
    obj.insertNode(3);
    obj.insertNode(20);

    obj.recursiveReverse(obj.head);
}