#include <iostream>

int dfs(int v, int nv, int visited[], int **matrix){
    int i;
    visited[v]=1;
    for(i=1;i<=nv;i++){
            if(matrix[v][i] && !visited[i]){
                visited[i]=1;
                dfs(i, nv, visited, matrix);
            }
    }
    return *visited;
}

int main(){
    int vertices, edges;
    scanf("%d %d", &vertices, &edges);

    int ** m = (int**)malloc(vertices * sizeof (int *));
    
    int i, j;
    for(i=1;i<=vertices;i++){
        for(j=1;j<=vertices;j++){
            m[i][j]=0;
        }
    }
    
    int v1, v2, p;
    for(i=0;i<edges;i++){
        scanf("%d %d %d", &v1, &v2, &p);
        m[v1][v2]=p;
    }
    
    int *visited = (int *)malloc(vertices * sizeof (int));
    for(i=1;i<=vertices;i++){
        visited[i]=0;
    }
    
    int componentes=0;
    for(i=1;i<=vertices;i++){
        if(visited[i]==0){
            visited[i]=dfs(1, vertices, visited, m);
            componentes = componentes+1;
        }
    }
    
    printf("%d", componentes);


    return 0;
}
