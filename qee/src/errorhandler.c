#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    SyntaxError,
    ImportError,
    TypeError
} errorType;

typedef struct {
    errorType type;
    char *message;
    char *stackTrace;
    char *snippet;
    int line;
    int startColumn;
    int endColumn;
    int errorNumber;
    bool panic;
} error;

char *getErrorType(errorType type) {
    switch (type) {
        case SyntaxError:
            return "SyntaxError";
        case ImportError:
            return "ImportError";
        case TypeError:
            return "TypeError";
    }
}

void reportError(error err) {
    char *type = getErrorType(err.type);
    printf(
    "[%d] %s at [%d:%d]\n"
    "%s",
    err.errorNumber,
    type,
    err.line,
    err.startColumn,
    err.message
    ); 
}

void panicError(error err) {
    reportError(err);
    exit(EXIT_FAILURE);
}

int fixError() {
    // TODO
    return 1;
}

bool isFixable(error err) {
    // TODO
    return false;
}

void nonPanicError(error err) {
    if (isFixable(err)) {
        fixError();
        return;
    }
    reportError(err);
    printf("STARTING ERROR CLI");
    int res; 
}

void handler(error err) {
    if (err.panic == true) {
        panicError(err);
    } else {
        nonPanicError(err);
    }
}
