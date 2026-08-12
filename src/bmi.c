#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *trim_whitespace(char *str) {
    char *end;
    while (*str != '\0' && isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == '\0') {
        return str;
    }
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    end[1] = '\0';
    return str;
}

int main(void) {
    char line[256];
    int height_cm, weight_kg;

    while (1) {
        printf("Enter height in cm and weight in kg, or type quit to exit:\n");

        if (!fgets(line, sizeof(line), stdin)) {
            break;
        }

        char *text = trim_whitespace(line);
        if (text[0] == '\0') {
            continue;
        }

        if (strcmp(text, "quit") == 0) {
            break;
        }

        if (sscanf(text, "%d %d", &height_cm, &weight_kg) != 2) {
            printf("Invalid input\n");
            continue;
        }

        if (height_cm <= 0 || weight_kg <= 0) {
            printf("Invalid input\n");
            continue;
        }

        double height_m = height_cm / 100.0;
        double bmi = weight_kg / (height_m * height_m);
        printf("%.1f\n", bmi);
    }

    return 0;
}
