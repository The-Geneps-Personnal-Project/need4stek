#include "my.h"

// Main loop
void loop(void) {
    t_info info;

    info = init_info(info);
    while (info.run) {
        get_info(&info);
    }
}