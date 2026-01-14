#include "solution.h"
#include <stdlib.h>

// 扩散器：负责连通域染色
void dfs(int** image, int r, int c, int rowSize, int colSize, int oldColor, int newColor) {
    if (r < 0 || r >= rowSize || c < 0 || c >= colSize || image[r][c] != oldColor) {
        return;
    }
    image[r][c] = newColor;
    dfs(image, r - 1, c, rowSize, colSize, oldColor, newColor);
    dfs(image, r + 1, c, rowSize, colSize, oldColor, newColor);
    dfs(image, r, c - 1, rowSize, colSize, oldColor, newColor);
    dfs(image, r, c + 1, rowSize, colSize, oldColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    int oldColor = image[sr][sc];
    if (oldColor == color) {
        // 如果颜色没变，依然要按照契约分配返回数组的形状信息
        *returnSize = imageSize;
        *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
        for(int i=0; i<imageSize; i++) (*returnColumnSizes)[i] = imageColSize[i];
        return image; 
    }

    // 1. 形状复刻：申请新图的“柜子外壳”
    int** res = (int**)malloc(imageSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(imageSize * sizeof(int));
    *returnSize = imageSize;

    for (int i = 0; i < imageSize; i++) {
        int cols = imageColSize[i];
        // 2. 申请“抽屉内部”
        res[i] = (int*)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
        // 3. 数据搬运
        for (int j = 0; j < cols; j++) {
            res[i][j] = image[i][j];
        }
    }

    // 4. 在新图上执行编排好的扩散操作
    dfs(res, sr, sc, imageSize, imageColSize[0], oldColor, color);

    return res;
}