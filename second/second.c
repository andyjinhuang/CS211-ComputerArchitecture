#include "second.h"

struct Node{ /*Node*/
    int x;
    struct Node* next;
};


struct Node *insert(struct Node *head, int val){
    struct Node *prev;
    if(head == NULL){
        head = malloc(sizeof(struct Node));
        head->x = val;
        head->next = NULL;
    }
    
    else if(head->x > val){
        struct Node *insertN = malloc(sizeof(struct Node));
        insertN->x = val;
        insertN->next = head;
        return insertN;
    }
    else{
        struct Node *temp = head;
        while(temp != NULL){
            if(temp->x == val){
                return head;
            }
            else if(temp->x > val){
                struct Node *insertN;
                insertN = malloc(sizeof(struct Node));
                insertN->x = val;
                insertN->next = prev->next;
                prev->next = insertN;
                return head;
            }
            prev = temp;
            temp = temp->next;
        }
        
        struct Node *insertN;
        insertN = malloc(sizeof(struct Node));
        insertN->x = val;
        insertN-> next = NULL;
        prev->next = insertN;
        /*
         temp = malloc(sizeof(struct Node));
         temp->x = val;
         temp->next = NULL;*/
        return head;
    }
}

struct Node *delete(struct Node *head, int val){
    struct Node *temp = head;
    struct Node *prev = head;
    
    if (head == NULL){
        return head;
    }
    
    if(head->x == val){
        return head->next;
    }
    while(temp != NULL){
        if(temp->x == val){
            prev->next = temp->next;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    
    return head;
}

int main(int argc, char** argv){
    struct Node *head;
    
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
    
    while(fscanf(inputFile, "%c %d\n", &action, &num) == 2 ){
        if(action == 'i'){
            head = insert(head, num);
        }
        
        else if(action == 'd'){
            head = delete(head, num);
        }
        
        else {
            printf("error");
            return 0;
        }
    }

    if(!feof(inputFile)){
      printf("error");
      return 0;
    }
    
    while (head != NULL){
      printf("%d\t", head->x);
      head = head->next;
    }
    
    fclose(inputFile);
    free(head);
    return 0;    
}
