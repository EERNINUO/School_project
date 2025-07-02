#include "read_data.h"

double data[] = {
    10, 2000.36, 2000.35, 2000.34, 2000.37,
    15, 2000.51, 2000.49, 2000.52, 2000.53,
    20, 2000.72, 2000.71, 2000.73, 2000.74,
    25, 2000.86, 2000.89, 2000.85, 2000.87,
    30, 2001.07, 2001.09, 2001.05, 2001.08,
    35, 2001.25, 2001.28, 2001.24, 2001.26,
    40, 2001.48, 2001.50, 2001.46, 2001.49,
    45, 2001.60, 2001.59, 2001.62, 2001.63,
};

double X_read[] = {
    10, 
    15,
    20,
    25,
    30,
    35,
    40,
    45
};

double Yread[] = {
    2000.36, 2000.35, 2000.34, 2000.37,
    2000.51, 2000.49, 2000.52, 2000.53,
    2000.72, 2000.71, 2000.73, 2000.74,
    2000.86, 2000.89, 2000.85, 2000.87,
    2001.07, 2001.09, 2001.05, 2001.08,
    2001.25, 2001.28, 2001.24, 2001.26,
    2001.48, 2001.50, 2001.46, 2001.49,
    2001.60, 2001.59, 2001.62, 2001.63,
};

// int read() {
//     FILE *file;
//     char line[100];
//     char *token;
//     char *filename = "data.csv";
 
//     // 打开CSV文件进行读取
//     file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Error opening file.\n");
//         return 1;
//     }
 
//     // 读取并解析文件中的每一行
//     while (fgets(line, sizeof(line), file)) {
//         token = strtok(line, ",");
//         while (token != NULL) {
//             printf("%s\n", token);
//             token = strtok(NULL, ",");
//         }
//     }

//     // 关闭文件
//     fclose(file);

//     return 0;
// }

void averge(double *matrix, double* output_arr, uint16_t rows_){
    for (uint8_t i = 0; i < rows_; i++){
        double ave = 0; 
        for (uint16_t j = 0; j < 4; j++){
            ave += Yread[i*4+j];
        }
        ave /= (double)4.0;
        output_arr[i] = ave;
    }
}