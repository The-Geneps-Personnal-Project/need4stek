#include "my.h"

int verif_info(char **tab) {
    for (int i = 0; tab[i]; i++) {
        if (!strcmp(tab[i], "First CP Cleared") || !strcmp(tab[i], "CP Cleared")) {
            fprintf(stderr, "CP Cleared\n");
            return 1;
        }
    }
    return 0;
}

void check_finish(char **tab, t_info *info) {
    for (int i = 0; tab[i]; i++) {
        if (strcmp(tab[i], "Track Cleared") == 0) {
            info->run = false;
            return;
        }
    }
    return;
}

char **get_info(t_info *info) {
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
    free(str);
    return tab;
}

// Initialize the info structure
t_info init_info(t_info info) {
    info.run = true;
    info.speed = 0.1;
    return info;
}