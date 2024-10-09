#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *initial_string = "The quick brown fox jumps over the lazy dog.";
    size_t string_length = strlen(initial_string);
    char *final_string = malloc(string_length + 1 * sizeof(char));
    if (final_string == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int position;
    int remainder;
    printf("Enter a number between 1-25\n");
    scanf("%d", &position);
    while (position < 1 || position > 25){
        printf("Invalid input. Please enter a number between 1 and 25.\n");
        scanf("%d", &position);
    }
    for (size_t i=0; i < string_length; i++) {
        int unicode_value = (int)initial_string[i];
        if ((unicode_value >= 97) && (unicode_value <= 122)){
            if (unicode_value + position <= 122) {
                unicode_value += position;
            } else {
                remainder = 122 - unicode_value;
                unicode_value = 96 + (position-remainder);
            }
        } else if ((unicode_value >= 65) && (unicode_value <= 90)){
            if (unicode_value + position <= 90) {
                unicode_value += position;
            } else {
                remainder = 90 - unicode_value;
                unicode_value = 64 + (position-remainder);
            }
        }
        final_string[i] = (char)unicode_value;
    }
    
    final_string[string_length] = '\0';
    printf("%s\n", final_string);

    free(final_string);
    return 0;
}
