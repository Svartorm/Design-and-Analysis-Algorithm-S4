#include <stdio.h>
#include <stdlib.h>

struct Node {
    int position;
    struct Node* child;
    struct Node* sibling;
};

struct Node* head = NULL;    //global var

//print the tree
void printTree(){
    printf("Tree:\n");
    __printTree(head, 0);
}

void __printTree(struct Node* current, int level){
    if(current == NULL){
        return;
    }
    for(int i = 0; i < level; i++){
        printf("  ");
    }
    printf("-> %d\n", current->position);
    __printTree(current->child, level + 1);
    __printTree(current->sibling, level);
}

//create a function to add node in the tree given the parent position
void addTree(int parentPosition, int position){
    // find the parent node
    struct Node* parent = head;
    while(parent != NULL && parent->position != parentPosition){
        parent = parent->sibling ? parent->sibling : parent->child;
    }
    if(parent == NULL){
        printf("Parent not found\n");
        return;
    }

    // create the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->position = position;
    newNode->child = NULL;
    newNode->sibling = NULL;

    // add the new node to the parent
    if(parent->child == NULL){
        parent->child = newNode;
    }else{
        struct Node* child = parent->child;
        while(child->sibling != NULL){
            child = child->sibling;
        }
        child->sibling = newNode;
    }
}

int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    head->position = 1;
    head->child = NULL;
    head->sibling = NULL;

    //modify these following codes into a function
    // struct Node* newData2 = NULL;
    // newData2 = (struct Node*)malloc(sizeof(struct Node));
    // newData2->position = 2;
    // newData2->child = NULL;
    // newData2->sibling = NULL;
    // head->child = newData2;

    // struct Node* newData3 = NULL;
    // newData3 = (struct Node*)malloc(sizeof(struct Node));
    // newData3->position = 3;
    // newData3->sibling = NULL;
    // newData3->child = NULL;
    // newData2->sibling = newData3;

    // struct Node* newData4 = NULL;
    // newData4 = (struct Node*)malloc(sizeof(struct Node));
    // newData4->position = 4;
    // newData4->sibling = NULL;
    // newData4->child = NULL;
    // newData2->child = newData4;   
    
    // struct Node* newData5 = NULL;
    // newData5 = (struct Node*)malloc(sizeof(struct Node));
    // newData5->position = 5;
    // newData5->sibling = NULL;
    // newData5->child = NULL;
    // newData4->sibling = newData5;   

    addTree(1, 2);
    addTree(1, 3);
    addTree(2, 4);
    addTree(2, 5);
    
    //-------------

    printTree();
    return 0;
}