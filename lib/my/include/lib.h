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

#ifndef LIB_
#define LIB_
#define EXIT_ERROR 84

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

char *get_input(void);
void my_free_tab(char **tab);
char **my_str_to_word_array(char *buffer, char charac, int j, int k);

#endif /* !LIB_ */