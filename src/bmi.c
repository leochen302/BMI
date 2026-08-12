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
    double height_cm, weight_kg;

    while (1) {
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

        if (sscanf(text, "%lf %lf", &height_cm, &weight_kg) != 2) {
            if (sscanf(text, "%lf", &height_cm) == 1) {
                if (!fgets(line, sizeof(line), stdin)) {
                    break;
                }
                text = trim_whitespace(line);
                if (sscanf(text, "%lf", &weight_kg) != 1) {
                    printf("Invalid input\n");
                    continue;
                }
            } else {
                printf("Invalid input\n");
                continue;
            }
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
