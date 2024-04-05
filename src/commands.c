#include "my.h"

// Run a command
// Send a command to the need4stek API
void run_command(const char* command) {
    write(1, command, strlen(command));
    return;
}

void run_command_forward(float speed) {
    write(1, "CAR_FORWARD:", 12);
    dprintf(1, "%f\n", speed);
    return;
}

void run_command_direction(double sign, char * direction) {
    fprintf(stderr, "sign: %f, direction: %s\n", sign, direction);
    write(1, "WHEELS_DIR:", 11);
    if (sign < 0)
        write(1, "-", 1);
    dprintf(1, "%s\n", direction);
    return;
}