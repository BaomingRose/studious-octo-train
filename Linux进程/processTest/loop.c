#include<stdio.h>
#include<unistd.h>

int main() {
  //获取调用进程ID
  pid_t pid = getpid();
  while(1) {

    printf("hello worle!!  %d\n", pid);
    sleep(1);
  }

  return 0;
}
