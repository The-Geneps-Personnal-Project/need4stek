#include "my.h"

// Run a command
// Send a command to the need4stek API
int run_command(const char* command) {
    write(1, command, strlen(command));
    return 0;
}