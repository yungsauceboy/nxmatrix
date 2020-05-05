#include <switch.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    consoleInit(NULL);
    printf("\e[32mnxmatrix\n");
    int i=0;
    while (appletMainLoop())
    {
      printf("\r");
      hidScanInput();
      u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
      if(kDown & KEY_PLUS)
        break;

      printf("%d", i);
      i++;
      consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return(0);
}
