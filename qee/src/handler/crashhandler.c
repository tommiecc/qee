#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

struct stat st = {0};

void handle_signal(int sig) {
    // check if /tmp/ exists
    if (stat("./tmp", &st) == -1) {
        // if not make it
        mkdir("./tmp", 0700);
    }
    // open log file
    FILE *log_file = fopen("../tmp/crash.log", "wb");
    if (log_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fprintf(log_file, "Received signal %d\n", sig);

    // get log and background
    void *buffer[30];
    int nptrs = backtrace(buffer, 30);
    fprintf(log_file, "Backtrace (%d frames):\n", nptrs);
    backtrace_symbols_fd(buffer, nptrs, fileno(log_file));
    
    // close file
    fclose(log_file);

    exit(EXIT_FAILURE);
}

void register_signal_handlers() {
    signal(SIGSEGV, handle_signal);  // Segmentation fault
    signal(SIGABRT, handle_signal);  // Abort signal
    signal(SIGFPE, handle_signal);   // Floating point exception
    signal(SIGILL, handle_signal);   // Illegal instruction
    signal(SIGBUS, handle_signal);   // Bus error
    signal(SIGINT, handle_signal);   // interrupt error
    signal(SIGTERM, handle_signal);  // termination error
    signal(SIGTRAP, handle_signal);   // stack trace error 
}
