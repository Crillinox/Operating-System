#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 50
#define MAX_ENTRIES 10

struct configEntry {
    char key[MAX_VALUE];
    char value[MAX_VALUE];
};

struct config {
    struct configEntry entries[MAX_ENTRIES];
    int entryCount;
};

void parseLine(char *line, struct configEntry *entry) {
    // strip newline that fgets leaves behind
    line[strcspn(line, "\n")] = 0;
    
    // skip comments and empty lines
    if (line[0] == '#' || line[0] == ';' || line[0] == '\0') return;
    
    char *token = strtok(line, "=");
    if (token == NULL) return;
    strcpy(entry->key, token);
    
    token = strtok(NULL, "");
    if (token == NULL) return;
    strcpy(entry->value, token);
}

struct config parseConfig(const char *filename) {
    struct config cfg;
    cfg.entryCount = 0;

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("ERROR: could not open %s\n", filename);
        return cfg;
    }

    char line[MAX_VALUE];
    while (fgets(line, MAX_VALUE, f) && cfg.entryCount < MAX_ENTRIES) {
        parseLine(line, &cfg.entries[cfg.entryCount]);
        // only count if key was actually parsed
        if (cfg.entries[cfg.entryCount].key[0] != '\0') {
            cfg.entryCount++;
        }
    }

    fclose(f);
    return cfg;
}

void printConfig(struct config cfg) {
    printf("=== CrillinOS Boot Config ===\n");
    for (int i = 0; i < cfg.entryCount; i++) {
        printf("Key: %s | Value: %s\n",
            cfg.entries[i].key,
            cfg.entries[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <config file>\n", argv[0]);
        return 1;
    }

    struct config cfg = parseConfig(argv[1]);
    printConfig(cfg);

    return 0;
}
