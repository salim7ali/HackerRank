#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *next;
};

// head->
// 5->3->20->NULL
class SinglyLinkedList{
    
public:
    node* recursiveReverse(node *currPtr){

        if(currPtr->next){
            recursiveReverse(currPtr->next);
        }
        
    }

    int iterativeReverse(){
        node *runningPtr = head;

        while(runningPtr){
            runningPtr = runningPtr->next;
        }

    }

    void addItem(){

    }
};

int main(){
    
    SinglyLinkedList obj;

    // insert elements into LL


    obj.recursiveReverse(obj.head);
}