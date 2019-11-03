#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main() {
//int main(int argc, char* argv[], char* env[]) {
  //char* ptr = getenv("MYPATH");
  //printf("ptr:%s\n", ptr);
  extern char **environ; //库里的变量

  int i;
  for (i = 0; environ[i] != NULL; i++) {
    //printf("env[%d] = [%s]\n", i, env[i]);
    printf("env[%d]=[%s]\n", i, environ[i]);
    
  }

  return 0;
}
