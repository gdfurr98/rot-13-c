#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *initial_string = "They're trashing our rights man! Hack the planet!";
    size_t string_length = strlen(initial_string);
    char *final_string = malloc(string_length * sizeof(char));
    int position = 13;
    for (size_t i=0; i < string_length; i++) {
        int unicode_value = (int)initial_string[i];
        if ((unicode_value >= 97) && (unicode_value < 122)){
            printf("unicode value: %d\n", unicode_value);
            if (unicode_value + position <= 122) {
                unicode_value += position;
            } else {
                unicode_value -= position;
            }
            printf("final string unicode value: %d\n", unicode_value);
        } else if ((unicode_value >= 65) && (unicode_value < 90)){
            printf("unicode value: %d\n", unicode_value);
            if (unicode_value + position <= 90) {
                unicode_value += position;
            } else {
                unicode_value -= position;
            }
        }
        final_string[i] = (char)unicode_value;
    }
    
    final_string[string_length] = '\0';
    printf("%s\n", final_string);

    free(final_string);
    return 0;
}