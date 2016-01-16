#include "third.h"
struct Node{ //Node
    int x;
    struct Node* next;
};

//Checks if Node is there
int *present(struct Node *head, int val){
    if (head == NULL){
        return 0;
        //0 is not present; 1 is present
    }
    struct Node *temp = head;
    while(temp != NULL){
        if(temp->x == val){
            return 1;
        }
        temp = temp->next;
    }
    
    //checks through whole LL
    return 0;
}

//inserts new node
struct Node *insert(struct Node *head, int val){
    //if there is nothing in the key
    if(head == NULL){
        head = malloc(sizeof(struct Node));
        head->x = val;
        head->next = NULL;
        printf("inserted\n");
        return head;
        
    } else{
        //node is put before head
        if(present(head, val) == 1){
            printf("duplicate\n");
            return head;
        }
        
        //node is not present
        struct Node *insertN;
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        insertN = malloc(sizeof(struct Node));
        insertN->x = val;
        temp->next = insertN;
        insertN->next = NULL;
        printf("inserted\n");
        return head;
    }
}

int main(int argc, char** argv){
    struct Node *start = NULL;
    struct Node **hashtable[10000]; //hashtable is made up of nodes
    
    /*If no file was inputed*/
    if (argc != 2){
        return 0;
    }
    
    FILE *inputFile = fopen(argv[1], "r");
    char action;
    int num;
    
    /*File doesn't exist*/
    if (inputFile == NULL){
        printf("error\n");
        return 0;
    }
    
    int i = 0;
    for (i; i < 10000; i++){
        hashtable[i] = NULL;
    }
    
    while(fscanf(inputFile, "%c %d\n", &action, &num) == 2){
        
        int key;
        if(num >= 0){ //positives
            key = (num%10000);
        } else{ //negatives
            key = -(num%10000);
        }
        
        //when inserting an integer
        if(action == 'i'){
            if (hashtable[key] == NULL){
                //nothing is there
                hashtable[key] = insert(start, num);
            } else {
                struct Node *temp = hashtable[key];
                hashtable[key] = insert(temp, num);
            }
            
        }
        else if(action == 's'){
            if(hashtable[key] == NULL){
                //nothing is there
                printf("absent\n");
            } else{
                struct Node *temp = hashtable[key];
                if(present(temp, num) == 0){
                    printf("absent\n");
                } else{
                    printf("present\n");
                }
            }
            
        }
        else{
            //char is not i or s
            printf("error\n");
        }
    }
    
    fclose(inputFile);
    return 0;
}



