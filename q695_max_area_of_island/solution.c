#include "solution.h"
#include <stdlib.h>

int dfs(int r,int c, int** image,int* imageColSize,int imageSize){

    //递归条件：不超出边界、不等于0
    if( r<0 || r>=imageSize || c<0 || c>=imageColSize[r] ||image[r][c]==0)return 0;

    //沉岛
    image[r][c]=0;

    //返回面积
    return 1+dfs(r-1,c,image,imageColSize,imageSize)+ 
             dfs(r+1,c,image,imageColSize,imageSize)+
             dfs(r,c-1,image,imageColSize,imageSize)+
             dfs(r,c+1,image,imageColSize,imageSize);

}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){

    if(gridSize == 0)return 0;

    int max_area = 0;

    for(int i = 0;i<gridSize;i++){
        for(int j =0;j<gridColSize[i];j++){
            if(grid[i][j] ==1 ){
                //计算当前岛屿面积
                int current_island_area = dfs(i,j,grid,gridColSize,gridSize);
                if(current_island_area>max_area){
                    max_area = current_island_area;
                }
            }
        }
    }

    return max_area;
}