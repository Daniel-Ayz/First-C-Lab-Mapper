#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i=0;i<array_length;i++){
    mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

/* Ignores c, reads and returns a character from stdin using fgetc. */
char my_get(char c){
  return fgetc(stdin);
}

/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
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

 
int main(int argc, char **argv){
  int base_len = 5;
  char arr1[base_len];
  char* arr2 = map(arr1, base_len, my_get);
  char* arr3 = map(arr2, base_len, cprt);
  char* arr4 = map(arr3, base_len, xprt);
  char* arr5 = map(arr4, base_len, encrypt);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
}


