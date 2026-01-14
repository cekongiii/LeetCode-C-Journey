#include <stdlib.h>
#include "solution.h"

#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

// 辅助函数：打印地图，方便我们观察
void printGrid(char** grid, int rows, int* colSizes) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 1. 定义测试数据的尺寸
    int rows = 4;
    int cols = 5;
    
    // 每一行的列数清单
    int* gridColSize = (int*)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++) gridColSize[i] = cols;

    // 2. 准备原始数据（字符串数组，方便书写）
    // '1' 代表陆地（星点），'0' 代表水（背景）
    char* rawData[] = {
        "11000",
        "11000",
        "00100",
        "00011"
    };

    // 3. 核心：编排内存，构造 char** 结构
    // 先申请“行指针”的柜子
    char** grid = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        // 再申请每一行具体的“格子”
        grid[i] = (char*)malloc(cols * sizeof(char));
        // 将原始数据抄写进去
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rawData[i][j];
        }
    }

    printf("--- 初始海域图（发现 3 个孤立岛屿） ---\n");
    printGrid(grid, rows, gridColSize);

    // 4. 调用你的“扫描器”
    int result = numIslands(grid, rows, gridColSize);

    printf("\n--- 扫描结束 ---\n");
    printf("检测到的岛屿总数: %d\n", result);

    // 5. 清理现场（内存管理好习惯）
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(gridColSize);

    return 0;
}