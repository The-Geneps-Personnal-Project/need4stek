#include "my.h"

// Main loop
void loop(void) {
    t_info info;
    int verif = 0;

    info = init_info(info);
    while (info.run) {
        info.information = get_info(&info);
        check_finish(info.information, &info);
        verif = verif_info(info.information);
        fprintf(stderr, "verif: %d\n", verif);
        if (verif == 0) {
            manage_speed(&info);
            manage_direction(&info);
        }
        my_free_tab(info.information);
    }
}