#ifndef SOLUTION_H
#define SOLUTION_H

void dfs(int** image, int r, int c, int rowSize, int colSize, int oldColor, int newColor);
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes);

#endif
