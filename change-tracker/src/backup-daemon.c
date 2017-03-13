#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
  char backup_dir[100] = "/home/alex/Coding/systems-software/change-tracker/backup/";
  char dev_dir[100] = "/home/alex/Coding/systems-software/change-tracker/website/dev";
  
  struct tm *tm;
  time_t t;
  char str_timestamp[100];

  t = time(NULL);
  tm = localtime(&t);

  strftime(str_timestamp, sizeof(str_timestamp), "%Y%m%d%H%M%S", tm);
  
  strcat(backup_dir, str_timestamp);
  
  char *command = "/bin/cp";
  char *arguments[] = { "cp", "-a", dev_dir, backup_dir, NULL };
  execvp(command, arguments);
  
  return 0;
}
