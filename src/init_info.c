#include "my.h"

// Initialize the info structure
t_info init_info(t_info info) {
    info.speed = 0.0;
    info.turn = 0.0;
    info.end = 0.0;
    return info;
}