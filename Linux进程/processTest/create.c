#include<stdio.h>
#include<unistd.h>

int main() {
  printf("hello hello, %d\n", getpid());
  //创建子进程，父进程返回子进程的pid，子进程返回0
  pid_t pid = fork();
  if (pid < 0) {
    printf("fork error\n");
    return -1;
  } else if (pid == 0) {
    printf("-----------i am child------------%d\n", getpid());
  } else {
    printf("-----------i am parent-----------%d\n", getpid());
  }
  printf("leihoua~~~  %d\n", getpid());
  
  return 0;
}
