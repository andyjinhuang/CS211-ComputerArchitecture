#include "ninth.h"

struct Node{
  int value, height;
  struct Node* left;
  struct Node* right;
  
};

//will print inserted/present and height value
void *insert(struct Node *root, int val){
  if(root == NULL){
    root = malloc(sizeof(struct Node));
    root->value = val;
    root->height = 1;
    printf("inserted 1\n");
    return;
  }

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
  if(root == NULL){
    printf("absent\n");
    return;
  }
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

void reheight(struct Node *head, int height){
 
  if(head == NULL){
    return;
  }  

  if (head->right != NULL){
    reheight(head->right, height+1);
  }
  if (head->left != NULL){
    reheight(head->left, height+1);
  }
  head->height = height;
  return;
}

struct Node *delete(struct Node *root, int val, int height){
  struct Node *left;
  struct Node *right = root->right;
  struct Node *before = root;
  struct Node *temp = root;
    
  //if the right subtree is NULL
  if (root->right == NULL){
    //root had no children
    if(root->left == NULL){
      root = NULL;
      printf("success\n");
      return root;
    }
    //has left subtree; no right subtree
    root = root->left;
    reheight(root, height);
    printf("success\n");
    return root;
  }
    
  //has a right subtree
  else {
    //finds the left most in right subtree
    if(right-> left != NULL){
      while(right->left != NULL){
	before = right;
	right = right->left; 
      }
      before->left = NULL;
    }
    //if left most in right subtree has right children
    if(before != root){
      if(right->right != NULL){
	left = right->right;
	before->left = left;
	/*
	while(left->right != NULL){
	  left = left->right;
	  before = before->left;
	  before->left = left;
	}
	while(left->right != NULL){
	left = left->right;
        }            
	left->right = root->right;
      } else{
	right->right = root->right;
      }*/
      }
      right->right = root->right;
    }

    if(root->left != NULL){
      right->left = root->left;
    } else{
      right->left = NULL;
    }

    root = right;
    reheight(root, height);
    printf("success\n");
    return root;
  }
}

struct Node *whereuat(struct Node *root, int val){
  struct Node *temp = root;
  struct Node *before = NULL;
  
  while(temp != NULL){
    if(temp->value == val){
      temp = delete(temp, val, temp->height);
      if(before != NULL){
	if(temp->value < before->value){
	  before->left = temp;
	} else{
	  before->right = temp;
	}
      } else{
	return temp;
      }
      break;            
    } else if(temp->value > val){
      before = temp;
      temp = temp->left;
      
    } else{
      before = temp;
      temp = temp->right;
    }
  }
  
  if(temp == NULL){
    printf("fail\n");
  }
  
  return root;
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
        
    else if (action == 'd'){
      root = whereuat(root, num);
    }
    else {
      printf("error\n");
    }
  }

  return 0;
}
