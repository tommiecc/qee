
// local header files
#include "cli.h"
#include "crashhandler.h"

int main(int argc, char *argv[]) {
    // setup handlers for a crash
    register_signal_handlers();
    cli(argv, argc);
    return 0;
}
