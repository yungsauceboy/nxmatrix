#include <switch.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printRow(char *m);
void genRow(char *m);

int main() {

    consoleInit(NULL);
    printf("\e[32m");
    char matrix[81];
    int count=0;
    while (appletMainLoop())
    {
      hidScanInput();
      u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
      if(kDown & KEY_PLUS)
        break;

      genRow(matrix);
      if(count >= 44)
      {
        //if we get here need to reprint whole matrix every time
        consoleClear();
        count=0;
      }
      printRow(matrix);

      usleep(16.7*1000);
      consoleUpdate(NULL);
      count++;
    }

    consoleExit(NULL);
    return(0);
}

void genRow(char *m)
{
  for(int i = 0; i<80; i++)
  {
    int temp = 33 + rand() % 95;
    m[i] = temp;
  }
  m[80] = '\0';
}

void printRow(char *m)
{
  printf("%s", m);
}
