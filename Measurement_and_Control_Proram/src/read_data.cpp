#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int read() {
    FILE *file;
    char line[100];
    char *token;
    char *filename = "data.csv";
 
    // 打开CSV文件进行读取
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
 
    // 读取并解析文件中的每一行
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    // 关闭文件
    fclose(file);

    return 0;
}
