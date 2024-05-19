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

    char ch;
    while(!feof(helpptr)) {
        ch = fgetc(helpptr);
        if (ch != "\n") {
            printf("%c", ch);
        } else {
            printf("\n");
        }
    }
    fclose(helpptr);
    return 0;
}


int cli(char *args[], int argc) {
    
    for (int i = 0; i < argc; i++) {
       printf("%s", args[i]);
        // check for help command
        if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help")) {
            help();
        }
    }

    return 0;
}
