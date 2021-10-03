bool isSafe(int A,int B,int a,int b){
    if (a>=1&&b>=1&&a<=A&&b<=B) return true;
    else return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    if(C==E&&D==F) return 0;
    vector<int> x_moves = {2,2,-2,-2,1,1,-1,-1};
    vector<int> y_moves = {1,-1,1,-1,2,-2,2,-2};
    vector<vector<int>> isVisited(A+1,vector<int>(B+1,0));
    queue<vector<int>> q;
    q.push({C,D,0});
    isVisited[C][D]=1;
    while(!q.empty()){
        vector<int> current = q.front();
        q.pop();
        if(current[0]==E&&current[1]==F) return current[2];
        else{
            for(int i =0;i<8;i++){
                int new_x = current[0]+x_moves[i];
                int new_y = current[1]+y_moves[i];
                if(isSafe(A,B,new_x,new_y)&&!isVisited[new_x][new_y]){
                    isVisited[new_x][new_y]=1;
                    q.push({new_x,new_y,current[2]+1});
                }
            }
        }
    }
    return -1;
    
}
