#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define max(n1,n2) ((n1 >= n2) ? n1 : n2)
#define min(n1,n2) ((n1 <= n2) ? n1 : n2)

int main()
{
    int i,j,maxnum = -1,minnum = INT_MAX,edges,n1,n2,edge;
    int matrix[11][11];
    memset(matrix,-1,sizeof(matrix));
    printf("please input the edges and pedge between 2 sides like 2 3 10\n");
    printf("max n <= 10,min n >= 0\n");
    printf("the edges:");
    scanf("%d",&edges);

    for(i=0;i<edges;++i)
    {
        scanf("%d %d %d",&n1,&n2,&edge);
        if(n1 < 0 || n2 < 0 || edge < 0)    exit(0);
        matrix[n1][n2] = edge;
        matrix[n2][n1] = edge;
        maxnum = max(max(n1,n2),maxnum);
        minnum = min(min(n1,n2),minnum);
    }

    int start,end,tmp;
    for(tmp=minnum;tmp<=maxnum;++tmp)
    {
        for(start=minnum;start<=maxnum;++start)
        {
            for(end=minnum;end<=maxnum;++end)
            {
                if(matrix[start][tmp] != -1 && matrix[tmp][end] != -1)
                {
                    if(matrix[start][end] == -1) matrix[start][end] = matrix[start][tmp] + matrix[tmp][end];
                    else    matrix[start][end] = min(matrix[start][end],matrix[start][tmp] + matrix[tmp][end]);
                }
            }
        }
    }

    printf("here is the result\n");
    for(i=minnum;i<=maxnum;++i)
    {
        for(j=i+1;j<=maxnum;++j)
        {
            if(matrix[i][j] == -1)  continue;
            printf("%d -> %d: %d\n",i,j,matrix[i][j]);
        }
    }

    return 0;
}

/*
10

1 4 10
1 2 12
1 3 3
0 1 8
0 3 5
3 6 15
3 5 7
2 4 6
2 5 2
4 5 9

*/

