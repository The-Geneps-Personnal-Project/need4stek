#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "../lib/my/include/lib.h"

#ifndef MY_H_
#define MY_H_

typedef struct s_info {
    float speed;
    float slow;
    float turn;
    float end;
    bool run;
} t_info;

// Include functions
void run_command(const char *command);
void run_command_forward(float speed);

void loop(void);

void start_simulation(void);
void end_simulation(void);

t_info init_info(t_info info);
void get_info(t_info *info);

void manage_speed(char ** data, t_info *info);
// void manage_direction(char ** data, t_info *info);

#endif // MY_H_