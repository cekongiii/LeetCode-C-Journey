#include <stdlib.h>
#include "solution.h"

int numIslands(char** grid, int gridSize, int* gridColSize){
    //遇到1：扩散
    if(gridSize==0)return 0;
    int count =0;

    //扫描全图
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            //只要发现1，代表发现新岛屿
            if(grid[i][j]=='1'){
                count++;
                //爆破沉岛
                dfs(i,j,grid,gridSize,gridColSize);
            }
        }
    }
    return count;
}


void dfs(int sr,int sc,char **image,int imageSize,int *imageColSize){//扩散函数

    //结束条件:超过图像边界/遇到0
    if(sr<0 || sr>=imageSize) {
        return;
    }
    if(sc<0||sc>=imageColSize[sr] ||image[sr][sc]=='0'){
        return;
    }

    image[sr][sc] ='0';
    //四周扩散
    dfs(sr-1,sc,image,imageSize,imageColSize);
    dfs(sr+1,sc,image,imageSize,imageColSize);
    dfs(sr,sc-1,image,imageSize,imageColSize);
    dfs(sr,sc+1,image,imageSize,imageColSize);

    return;
}