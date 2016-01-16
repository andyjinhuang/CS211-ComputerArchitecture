#include "first.h"

int isPrime(int x){
  if (x <= 3){ /*3, 2, and 1 are prime numbers*/
    return 1; /* 1 means prime*/
  }

  int i = x-1;
  for (i; i > 1; i--){ /*loop to check if divisable by x < i < 1*/
    if (x%i == 0){
      return 0; /*not prime*/
    }
  }

  return 1; /*finishes loop; means its prime*/
}

int main(int argc, char** argv){
  if (argv[1] == NULL){ /*no number was inputted*/
    printf("error\n");;
    return 0;
  }
 
 int input = atoi(argv[1]); /*value not the char*/
  
 if (input <= 0){ /*number cannot be negative*/
    printf("error");
    return 0;
  }

 if (isPrime(input)== 0){ /*zero means not prime*/
    printf("no\n");
  } else{
   printf("yes\n"); /* anything else (aka 1) is prime*/
  }

 return 0; /*exits program*/
}
