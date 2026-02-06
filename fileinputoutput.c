#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int num, choice;
    char name[50];
    
    printf("=== File I/O Operations Demo ===\n");
    
    // 1. WRITING TO FILE
    printf("\n1. Writing to file...\n");
    fp = fopen("students.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }
    
    fprintf(fp, "Name\tAge\tGrade\n");
    fprintf(fp, "Alice\t20\tA\n");
    fprintf(fp, "Bob\t22\tB\n");
    fprintf(fp, "Charlie\t19\tA+\n");
    fclose(fp);
    printf("Data written to students.txt\n");
    
    // 2. READING FROM FILE
    printf("\n2. Reading from file...\n");
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }
    
    printf("Contents of students.txt:\n");
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
    
    // 3. APPENDING TO FILE
    printf("\n3. Appending to file...\n");
    fp = fopen("students.txt", "a");
    fprintf(fp, "David\t21\tB+\n");
    fclose(fp);
    printf("Appended David to students.txt\n");
    
    // 4. BINARY FILE OPERATIONS
    printf("\n4. Binary file operations...\n");
    struct Student {
        int id;
        float gpa;
    };
    
    struct Student s1 = {101, 3.8}, s2 = {102, 3.5};
    
    // Write binary
    fp = fopen("students.bin", "wb");
    fwrite(&s1, sizeof(struct Student), 1, fp);
    fwrite(&s2, sizeof(struct Student), 1, fp);
    fclose(fp);
    
    // Read binary
    fp = fopen("students.bin", "rb");
    struct Student s;
    printf("Binary file contents:\n");
    printf("ID\tGPA\n");
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("%d\t%.1f\n", s.id, s.gpa);
    }
    fclose(fp);
    
    // 5. INTERACTIVE READ/WRITE
    printf("\n5. Interactive student entry:\n");
    fp = fopen("students.txt", "a");
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &num);
    fprintf(fp, "%s\t%d\tA\n", name, num);
    fclose(fp);
    
    printf("\n=== File Operations Complete ===\n");
    printf("Check students.txt and students.bin files\n");
    
    return 0;
}
