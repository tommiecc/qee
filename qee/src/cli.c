#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int help() {
    char *lookpath = "~/Desktop/qee";
    FILE *helpptr;
    helpptr = fopen(strcat(lookpath, "/docs/help/general.txt"), "r");
    if (NULL == helpptr) {
        printf("CLIError: Help file could not be opened or found\n");
    }
    char buff[255];
    fgets(buff, 255, helpptr);
    printf("%s", buff);

    fclose(helpptr);
    return 0;
}


int cli(char *args[], int argsCount) {
    
    int res = 0;
    for (int i = 0; i < argsCount; i++) {
       printf("%s", args[i]);
        // check for help command
        if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help")) {
            res = help();
        }
    }

    return res;
}
