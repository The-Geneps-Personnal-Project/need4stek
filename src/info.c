#include "my.h"

void check_finish(char **tab, t_info *info) {
    for (int i = 0; tab[i]; i++) {
        if (strcmp(tab[i], "Track Cleared") == 0) {
            info->run = false;
            return;
        }
    }
    return;
}

void get_info(t_info *info) {
    char *str;
    char **tab;

    run_command("GET_INFO_LIDAR\n");
    str = get_input();
    if (!str || !strcmp(str, "")) {
        fprintf(stderr, "Error: problem on get line\n");
        exit(84);
    }
    tab = my_str_to_word_array(str, ':', 0, 0);
    if (strcmp(tab[1], "KO") == 0)
        get_info(info);
    fprintf(stderr, "%s\n", str);
    check_finish(tab, info);
    manage_speed(tab, info);
    // manage_direction(tab, info);
    my_free_tab(tab);
    free(str);
    return;
}

// Initialize the info structure
t_info init_info(t_info info) {
    info.run = true;
    info.speed = 0.1;
    info.slow = 0.0;
    info.turn = 0.0;
    info.end = 0.0;
    return info;
}