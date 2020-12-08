#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main () {
  srand(time(NULL));
  printf("pre-forking pid: %d\n", getpid());

  int f = fork();
  if (f) {
    int status;
    int pid = wait(&status);
    int time = WEXITSTATUS(status);
    printf("child %d finished; time: %d seconds\n", pid, time);
    printf("parent finished\n");
  }

  if (!f) {
    int pid = getpid();
    int time = rand()%9 + 2;
    sleep(time);
    printf("child % d finished; time: %d seconds\n", pid, time);
  }

  return 0;
}
