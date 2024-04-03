#include "my.h"

// Initialize the simulation
// This function is called once at the beginning of the simulation
void start_simulation(void) {
    char *str;
    char **check_command;

    run_command("START_SIMULATION\n");
    str = get_input();
    fprintf(stderr, "%s\n", str);
    if (!str || !strcmp(str, "")) {
        fprintf(stderr, "Error: problem on get line\n");
        exit(84);
    }
    check_command = my_str_to_word_array(str, ':', 0, 0);
    if ((check_command[1] && strcmp(check_command[1], "OK") != 0) || !check_command[1]) {
        fprintf(stderr, "Error: could not start simulation\n%s\n", str);
        my_free_tab(check_command);
        exit(84);
    }
    fprintf(stderr, "%s\n", str);
    free(str);
    my_free_tab(check_command);
    return;
}

// End the simulation
// This function is called once at the end of the simulation
void end_simulation(void) {
    run_command("END_SIMULATION\n");
}