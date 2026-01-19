#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

// 辅助函数：打印地图
void printGrid(int** grid, int rows, int* colSizes) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 1. 定义数据尺寸（4行5列）
    int rows = 4;
    int cols = 5;

    // 每一行的列数清单（模拟星敏感器的一帧图像）
    int* gridColSize = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) gridColSize[i] = cols;

    // 2. 准备原始测试数据
    // 这里有三个岛屿：面积分别为 4, 1, 2
    int rawData[4][5] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1}
    };

    // 3. 为 int** 分配堆内存（模拟 LeetCode 环境）
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rawData[i][j];
        }
    }

    printf("--- 原始图像矩阵 ---\n");
    printGrid(grid, rows, gridColSize);

    // 4. 调用算法：寻找最大岛屿（星群）面积
    int result = maxAreaOfIsland(grid, rows, gridColSize);

    printf("\n--- 计算结果 ---\n");
    printf("最大岛屿的像素面积为: %d\n", result); // 预期输出应该是 4

    // 5. 释放内存（养成不泄露内存的好习惯）
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    return 0;
}