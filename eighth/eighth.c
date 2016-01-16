#include "eighth.h"

struct Node{
    int value, height;
    struct Node* left;
    struct Node* right;
    
};

//will print inserted/present and height value
void *insert(struct Node *root, int val){
    if (root->value == val){
        printf("duplicate\n");
        return;
    }
    
    struct Node *temp = root;
    struct Node *before = root;
    int h = 1;
    
    while (temp != NULL){
        if (temp->value == val){
            printf("duplicate\n", temp->height);
            return;
        }
        
        else if (temp->value > val){
            before = temp;
            temp = temp->left;
            h++;
        }
        
        else {
            before = temp;
            temp = temp->right;
            h++;
        }
    }
    
    struct Node *insertN;
    insertN = malloc(sizeof(struct Node));
    insertN->value = val;
    insertN->height = h;
    if (before->value > val){
        before->left = insertN;
    } else {
        before->right = insertN;
    }
    printf("inserted %d\n", h);
    return;
    
}

void search(struct Node *root, int val){
    //0 absent; height value if present
    if (root->value == val){
        printf("present 1\n");
        return;
    }
    
    struct Node *temp = root;
    while (temp != NULL){
        if (temp->value == val){
            printf("present %d\n", temp->height);
            return;
        }
        else if (temp->value > val){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    
    printf("absent\n");
    return;
    
}

int main(int argc, char** argv){
    char action;
    int num;
    
    if (argc != 2){
        printf("error\n");
        return 0;
    }
    
    FILE *file = fopen(argv[1], "r");
    fscanf(file, "%c %d\n", &action, &num);
    
    //if it's not i, they're searches and nothing was created
    //so it is absent
    while (action != 'i'){
        printf("absent\n");
        fscanf(file, "%c %d\n", &action, &num);
    }
    
    //root
    struct Node *root = malloc(sizeof(struct Node));
    root->value = num;
    root->height = 1;
    printf("inserted 1\n");
    
    while (fscanf(file, "%c %d\n", &action, &num) == 2){
        if (action == 'i'){
            insert(root, num);
        }
        
        else if (action == 's'){
            search(root, num);
        }
        
        else {
            printf("error\n");
        }
    }

    return 0;
}
