#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  for(int i=0;i<array_length;i++){
    mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

char my_get(char c){
  return fgetc(stdin);
}

char cprt(char c){
  if( 0x20 <= c && c <= 0x7E){
    printf("%c\n", c);
  }
  else{
    printf(".\n");
  }
  return c;
}

char encrypt(char c) {
    if (c >= 0x20 && c <= 0x7E) {
        return c + 1;
    }
    return c;
}

char decrypt(char c) {
    if (c >= 0x20 && c <= 0x7E) {
        return c - 1;
    }
    return c;
}

char xprt(char c) {
    printf("0x%X\n", c);
    return c;
}

struct fun_desc {
    char *name;
    char (*fun)(char);
};

int main(int argc, char **argv){
    char choise[3];
    char * carray = calloc(5, sizeof(char));
    struct fun_desc menu[] = { { "Get string", my_get }, { "Print string", cprt }, { "Encrypt", encrypt }, { "Decrypt", decrypt }, { "Print Hex", xprt },{ NULL, NULL } };
    int i = 0;
    struct fun_desc p = menu[i];
    while(p.name != NULL){
        p = menu[++i];
    }
    printf("Select operation from the following menu:\n");
    for(int option=0; option<i; option++){
        printf("%d) %s\n", option, menu[option].name);
    }
    printf("Option:");
    while(fgets(choise, 3, stdin) != NULL){
        int number = atoi(&choise[0]);
        if ( number < 0 || i <= number){
            printf("Not within bounds\n");
            exit(1);
        }
        printf("\nWithin bounds\n");
        char * new_array = map(carray, 5, menu[number].fun);
        free(carray);
        carray = new_array;
        printf("Done.\n\n");

        printf("Select operation from the following menu:\n");
        for(int option=0; option<i; option++){
            printf("%d) %s\n", option, menu[option].name);
        }
    }
    free(carray);
}
