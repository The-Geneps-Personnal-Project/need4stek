#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <string.h>

#include "../lib/my/include/lib.h"

#ifndef MY_H_
#define MY_H_

typedef struct s_info {
    float speed;
    float turn;
    float end;
} t_info;

// Include functions
int run_command(const char *command);
void loop(void);
void start_simulation(void);
void end_simulation(void);

#endif // MY_H_