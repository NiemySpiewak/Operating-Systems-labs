#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void flip_line(char *line) 
{
    if (line == NULL) return;
    
    size_t len = strlen(line);
    for (size_t i = 0; i < len / 2; i++) 
    {
        char temp = line[i];
        line[i] = line[len - i - 2];
        line[len - i - 2] = temp;
    }
}

void process_file(const char *input_path, const char *output_path) 
{
    FILE *input_file = fopen(input_path, "r");

    FILE *output_file = fopen(output_path, "w");

    
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, input_file)) 
    {
        flip_line(buffer);
        fputs(buffer, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

void process_directory(const char *source_dir, const char *output_dir) 
{
    DIR *dir = opendir(source_dir);

    struct dirent *entry;
    char input_path[BUFFER_SIZE];
    char output_path[BUFFER_SIZE];
    
    mkdir(output_dir, 0777);
    
    
    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(input_path, BUFFER_SIZE, "%s/%s", source_dir, entry->d_name);
        snprintf(output_path, BUFFER_SIZE, "%s/%s", output_dir, entry->d_name);
        


        const char *dot = strrchr(entry->d_name, '.');
        if (dot && strcmp(dot, ".txt") == 0) {
            process_file(input_path, output_path);
        }

    }
    closedir(dir);
}

int main(int argc, char *argv[]) 
{
    process_directory(argv[1], argv[2]);
    return 0;
}
