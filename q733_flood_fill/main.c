#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

void printImage(int** img, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 1. 准备测试数据：3x3 矩阵
    int rows = 3;
    int cols_init[] = {3, 3, 3};
    int** image = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        image[i] = (int*)malloc(cols_init[i] * sizeof(int));
    }

    // 初始化图像 (1 1 1, 1 1 0, 1 0 1)
    image[0][0]=1; image[0][1]=1; image[0][2]=1;
    image[1][0]=1; image[1][1]=1; image[1][2]=0;
    image[2][0]=1; image[2][1]=0; image[2][2]=1;

    printf("Original Image:\n");
    printImage(image, rows, cols_init);

    // 2. 调用算法
    int returnSize;
    int* returnColumnSizes;
    int** result = floodFill(image, rows, cols_init, 1, 1, 2, &returnSize, &returnColumnSizes);

    printf("\nAfter Flood Fill (Start at 1,1 with Color 2):\n");
    printImage(result, returnSize, returnColumnSizes);

    // 3. 清理内存（养成好习惯，防止内存泄漏）
    for (int i = 0; i < rows; i++) free(image[i]);
    free(image);
    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}