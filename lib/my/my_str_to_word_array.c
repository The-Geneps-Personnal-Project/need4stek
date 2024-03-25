#include <stdlib.h>

int count_words(char *buffer, char charac) {
    int count = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == charac || buffer[i] == '\n' || buffer[i] == '\t') {
            count++;
            while (buffer[i] == charac || buffer[i] == '\n' || buffer[i] == '\t') {
                i++;
            }
        }
    }
    return count + 1;
}

char **my_str_to_word_array(char *buffer, char charac) {
    int num_words = count_words(buffer, charac);
    char **array = malloc(sizeof(char *) * (num_words + 1));
    if (array == NULL)
        exit(1);
    int word_index = 0;
    for (int i = 0; buffer[i] != '\0';) {
        if (buffer[i] == charac || buffer[i] == '\n' || buffer[i] == '\t') {
            i++;
            continue;
        }
        int word_length = 0;
        while (buffer[i + word_length] != '\0' && buffer[i + word_length] != charac &&
               buffer[i + word_length] != '\n' && buffer[i + word_length] != '\t') {
            word_length++;
        }
        array[word_index] = malloc(sizeof(char) * (word_length + 1));
        if (array[word_index] == NULL)
            exit(1);
        for (int j = 0; j < word_length; j++)
            array[word_index][j] = buffer[i + j];
        array[word_index][word_length] = '\0';
        word_index++;
        i += word_length;
    }
    array[num_words] = NULL;
    return array;
}
