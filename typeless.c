#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LENGTH 4096

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage:\n");
        printf("  Alias: %s -a alias_name -c 'command' -d 'description'\n", argv[0]);
        printf("  Function: %s -f function_name 'command1' 'command2' ... -d 'description'\n", argv[0]);
        return 1;
    }

    char *config_file = "~/.bashrc";
    char buffer[MAX_CMD_LENGTH];

    if (strcmp(argv[1], "-a") == 0) {
        // Creating an alias
        snprintf(buffer, sizeof(buffer), "echo 'alias %s=\"%s\" # %s' >> %s", argv[2], argv[4], argv[6], config_file);
    } else if (strcmp(argv[1], "-f") == 0) {
        // Creating a function
        char function_body[MAX_CMD_LENGTH] = "";
        int i = 2;
        while (i < argc && strcmp(argv[i], "-d") != 0) {
            strcat(function_body, argv[i]);
            strcat(function_body, "; ");
            i++;
        }
        if (i >= argc || i + 1 >= argc) {
            printf("Error: Missing description for the function.\n");
            return 1;
        }
        char *description = argv[i + 1];
        snprintf(buffer, sizeof(buffer), "echo 'function %s() { echo \"%s\"; %s; }' >> %s", argv[2], description, function_body, config_file);
    } else {
        printf("Invalid option. Use -a for alias or -f for function.\n");
        return 1;
    }

    // Execute the command to append to the config file
    system(buffer);

    printf("Entry added successfully to %s.\n", config_file);

    return 0;
}
 