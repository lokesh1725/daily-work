#include <stdio.h>

int main() {
    // Set the full path including filename
    const char *filePath = "/home/lokeshwarankrishnasamy/Permanent/myfile.txt";

    // Open the file for writing ("w" mode creates/truncates file)
    FILE *file = fopen(filePath, "w");
    
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write some content to the file
    if (fprintf(file, "Hello, this file is stored permanently!\n") < 0) {
        perror("Error writing to file");
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    printf("File created and written successfully at %s\n", filePath);

    return 0;
}
