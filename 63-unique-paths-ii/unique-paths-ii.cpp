class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int arr[obstacleGrid.size()][obstacleGrid[0].size()];
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[i].size();j++){
                if(obstacleGrid[i][j]==1){arr[i][j]=0;}
                else{
                    if(i==0&&j==0){arr[i][j]=1;continue;}
                    else if(i==0&&j!=0){
                        if(arr[i][j-1]==1){arr[i][j]=1;}else{arr[i][j]=0;}
                    }
                    else if(i!=0&&j==0){
                        if(arr[i-1][j]==1){arr[i][j]=1;}else{arr[i][j]=0;}
                    }
                    else{arr[i][j]=arr[i-1][j]+arr[i][j-1];}
                }
            }
        }
        return arr[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};