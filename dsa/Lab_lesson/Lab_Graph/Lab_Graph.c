#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX         100                 // 矩阵最大容量
#define INF         9999                 // 最大值
#define isLetter(a) ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))//判断a是否是字母
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))//求a中元素的个数

// 图的结构体
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;

// 边的结构体
typedef struct _EdgeData
{
    char start; // 边的起点
    char end;   // 边的终点
    int  weight; // 边的权重
}EData;

/* 返回名为ch的顶点在图G中的位置（下标） */
static int get_position(Graph G, char ch)
{
    int i;
    for(i=0; i<G.vexnum; i++)
        if(ch==G.vexs[i])//与顶点集合中的元素相比较
            return i;
    return -1;
}

/* 读取一个输入字符 */
static char read_char()
{
    char ch;

    do {
        ch = getchar();
    } while(!isLetter(ch));

    return ch;
}//scanf("%c",&ch);

/* 创建图(需要自己输入) */
Graph* create_graph()
{
    char c1, c2;
    int v, e;
    int i, j, w, p1, p2;
    Graph *pG;

    // 输入"顶点个数"和"边的条数"
    printf("请输入图G中顶点的个数: ");
    scanf("%d", &v);
    printf("请输入图G中边的个数: ");
    scanf("%d", &e);
    while ( v < 1 || e < 1 || (e > (v * (v-1))))  /*(e > (v * (v-1))？*/
    {
        printf("输入错误: 无效的参数!请重新输入：\n");
        printf("请输入图G中顶点的个数: ");
        scanf("%d", &v);
        printf("请输入图G中边的个数: ");
        scanf("%d", &e);
    }

    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL )
        return NULL;
    memset(pG, 0, sizeof(Graph));//memset函数用来对pG图中所有对象初始化，清零

    // 初始化"顶点个数"和"边的条数"
    pG->vexnum=v;
    pG->edgnum=e;

    // 初始化"顶点"信息
    printf("\n请输入%d个顶点的字母标号：\n", v);
    for (i = 0; i < pG->vexnum; i++)
    {
        printf("顶点(%d): ", i+1);
        pG->vexs[i] = read_char();  //scanf("%c",&pG->vexs[i]);
    }

    // 1. 初始化"边"的权值为0或者最大值
    for (i = 0; i < pG->vexnum; i++)
    {
        for (j = 0; j < pG->vexnum; j++)
        {
            if (i==j)
                pG->matrix[i][j]=0;   //对角线上的元素都为0
            else
                pG->matrix[i][j]=INF;  //非对角线上的元素都为无穷大
        }
    }

    // 2.  根据用户输入，设置边的权值
    printf("\n请输入%d条边的信息(起点 终点 权值)：\n", e);
    for (i = 0; i < pG->edgnum; i++)
    {
        // 读取边的起始顶点，结束顶点，权值
        printf("第%d条边：", i+1);
        c1 = read_char();  //输入边上第一个顶点符号
        c2 = read_char();  //输入边上第二个顶点符号
        scanf("%d", &w);   //输入边上的权值

        p1 = get_position(*pG, c1);  //获取c1顶点在顶点数组中的下标
        p2 = get_position(*pG, c2);  //获取c2顶点在顶点数组中的下标

        while (p1==-1 || p2==-1)
        {
            printf("输入错误: 无效的边!\n");
            printf("边(%d):", i+1);
            c1 = read_char();
            c2 = read_char();
            scanf("%d", &w);

            p1 = get_position(*pG, c1);
            p2 = get_position(*pG, c2);
        }

        pG->matrix[p1][p2]=w;   //设置邻接居中中对应边的权值
        pG->matrix[p2][p1]=w;
    }

    return pG;
}

/* 返回顶点v的第一个邻接顶点的索引（下标），失败则返回-1 */
static int first_vertex(Graph G, int v)
{
    int i;

    if (v<0 || v>(G.vexnum-1))
        return -1;

    for (i = 0; i < G.vexnum; i++)
        if (G.matrix[v][i]!=0 && G.matrix[v][i]!=INF) //邻接矩阵中不在对角线上和不是无穷大
            return i;
    return -1;
}

/*  返回顶点v相对于w的下一个邻接顶点的索引（下标），失败则返回-1 */
static int next_vertix(Graph G, int v, int w)
{
    int i;

    if (v<0 || v>(G.vexnum-1) || w<0 || w>(G.vexnum-1))
        return -1;

    for (i =w+1; i < G.vexnum; i++)
        if( G.matrix[v][i]!=0 && G.matrix[v][i]!=INF)
            return i;

    return -1;
}

/* 深度优先搜索遍历图的递归实现 */
static void DFS(Graph G, int i, int *visited)
{
    int w;
    visited[i] = 1;
    printf("%c ", G.vexs[i]);
    // 遍历该顶点的所有邻接顶点。若是没有访问过，那么继续往下走
    for (w = first_vertex(G, i); w >= 0; w = next_vertix(G, i, w))
    {
        if (visited[w]==0)
            DFS( G, w, visited);
    }

}


/*  深度优先搜索遍历图 */
void DFSTraverse(Graph G)
{
    int i;
    int visited[MAX];       // 顶点访问标记，0表示未访问，1表示已访问

    // 初始化所有顶点都未被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0; //G.vexs[i]

    printf("\n深度优先搜索遍历(DFS): ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (visited[i]==0)
            DFS(G, i, visited);
    }
    printf("\n");
}


/*  广度优先搜索（类似于树的层次遍历） */
void BFS(Graph G)
{
    int head = 0;
    int rear = 0;
    int queue[MAX];     // 辅组队列,存放读取顶点下标
    int visited[MAX];     // 顶点访问标记
    int i, j, k;
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;

    printf("\n广度优先搜索遍历(BFS): ");
    for (i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            printf("%c ", G.vexs[i]);
            queue[rear++] = i;  // 入队列
        }
        while (head != rear)
        {
            j = queue[head++];  // 出队列
            for (k = first_vertex(G, j); k >= 0; k = next_vertix(G, j, k)) //k是为访问的邻接顶点
            {
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf("%c ", G.vexs[k]);
                    queue[rear++]=k;
                }
            }
        }
    }
    printf("\n");
}

/* 打印图的邻接矩阵 */
void print_graph(Graph G)
{
    int i,j;
    printf("\n图G的顶点信息：\n");
    for(i=0;i<G.vexnum;i++)
        printf("%10c",G.vexs[i]);
    printf("\n图G的邻接矩阵:\n");
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            printf("%10d ", G.matrix[i][j]);
        printf("\n");
    }
}




/* Prim最小生成树 */
/* 从图中下标为start的顶点开始，求解图G的最小生成素*/
void prim(Graph G, int start)
{
    int min,i,j,k,m,n,sum;
    int index=0;         // prim最小树的索引，即prims数组的下标起始值
    char Ebegin,Eend,prims[MAX];     // prim最小树的结果数组，顶点按照访问次序存放在prims数组中
    int weights[MAX];    // 顶点间边的权值

    // prim最小生成树中第一个数是"图中第start个顶点"，因为是从start开始的。
    prims[index++] = G.vexs[start];

    // 初始化"顶点的权值数组"，
    // 将每个顶点的权值初始化为"第start个顶点"到"该顶点"的权值。
    for (i = 0; i < G.vexnum; i++ )
        weights[i] = G.matrix[start][i];

    // 将第start个顶点的权值初始化为0。
    // 可以理解为"第start个顶点到它自身的距离为0"。
    weights[start] = 0;

    //
    for (i = 0; i < G.vexnum; i++)
    {
        // 由于从start开始的，因此不需要再对第start个顶点进行处理。
        if(start == i)
            continue;

        j = 0;
        k = 0;
        min = INF;

        // 在未被加入到最小生成树的顶点中，找出权值最小的顶点。
        while (j < G.vexnum)
        {
            // 若weights[j]=0，意味着"第j个节点已经被排序过"(或者说已经加入了最小生成树中)。
            if (weights[j] != 0 && weights[j] < min)
            {
                min = weights[j];
                k = j;
            }
            j++;
        }

        // 经过上面的处理后，在未被加入到最小生成树的顶点中，权值最小的顶点是第k个顶点。
        // 将第k个顶点加入到最小生成树的结果数组中
        prims[index++] = G.vexs[k];

        // 将"第k个顶点的权值"标记为0，意味着第k个顶点已经排序过了(或者说已经加入了最小树结果中)。
        weights[k] = 0;

        // 当第k个顶点被加入到最小生成树的结果数组中之后，更新其它顶点的权值。
        for (j = 0 ; j < G.vexnum; j++)
        {
            // 当第j个节点没有被处理，并且需要更新时才被更新。
            if (weights[j] != 0 && G.matrix[k][j] < weights[j])
                weights[j] = G.matrix[k][j];
        }
    }

    // 计算最小生成树的权值
    sum = 0;
    printf("\n最小生成树用Prim算法实现:\n ");
    for (i = 1; i < index; i++)
    {
        min = INF;
        n = get_position(G, prims[i]);// 获取prims[i]在G中的位置
        for (j = 0; j < i; j++)        // 在vexs[0...i]中，找出到j的权值最小的顶点。
        {
            m = get_position(G, prims[j]);
            if (G.matrix[m][n]<min)
            {

                min = G.matrix[m][n];
                Ebegin=m;
                Eend=n;
            }
        }
        printf("(%c,%c,%d) ", G.vexs[Ebegin],G.vexs[Eend], min);
        sum += min;
    }
    printf("\n从%c点出发找到的最小生成树的权值Prim (%c)=%d ", G.vexs[start],G.vexs[start], sum);}



/* 获取图中的边 */
EData* get_edges(Graph G)
{
    int i,j;
    int index=0;
    EData *edges;

    edges = (EData*)malloc(G.edgnum*sizeof(EData));
    for (i=0;i < G.vexnum;i++)
    {
        for (j=i+1;j < G.vexnum;j++)
        {
            if (G.matrix[i][j]!=INF)
            {
                edges[index].start  = G.vexs[i];
                edges[index].end    = G.vexs[j];
                edges[index].weight = G.matrix[i][j];
                index++;
            }
        }
    }

    return edges;
}

/* 对边按照权值大小进行排序(由小到大) */
void sorted_edges(EData* edges, int elen)
{
    int i,j;

    for (i=0; i<elen; i++)
    {
        for (j=i+1; j<elen; j++)
        {
            if (edges[i].weight > edges[j].weight)
            {
                // 交换"第i条边"和"第j条边"
                EData tmp = edges[i];
                edges[i] = edges[j];
                edges[j] = tmp;
            }
        }
    }
}

/* 获取i的终点 */
int get_end(int vends[], int i)
{
    while (vends[i] != 0)
        i = vends[i];
    return i;
}

/* 克鲁斯卡尔（Kruskal)最小生成树 */
void kruskal(Graph G)
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;            // rets数组的索引
    int vends[MAX]={0};     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
    EData rets[MAX];        // 结果数组，保存kruskal最小生成树的边
    EData *edges;           // 图对应的所有边

    // 获取"图中所有的边"
    edges = get_edges(G);
    // 将边按照"权"的大小进行排序(从小到大)
    sorted_edges(edges, G.edgnum);

    for (i=0; i<G.edgnum; i++)
    {
        p1 = get_position(G, edges[i].start);   // 获取第i条边的"起点"的序号
        p2 = get_position(G, edges[i].end);     // 获取第i条边的"终点"的序号

        m = get_end(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
        n = get_end(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
        // 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
        if (m != n)
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = edges[i];           // 保存结果
        }
    }
    free(edges);

    // 统计并打印"kruskal最小生成树"的信息
    printf("\n\n最小生成树用Kruskal算法实现:\n ");
    for (i = 0; i < index; i++)
        printf("(%c,%c,%d) ", rets[i].start, rets[i].end, rets [i].weight);
    printf("\n");
    length = 0;
    for (i = 0; i < index; i++)
        length += rets[i].weight;
    printf("最小生成树的权值Kruskal=%d\n\n", length);
}


void main()
{
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    Graph* pG;

    printf("       **************************************************\n");
    printf("                      图 的 常 用 算 法\n");
    printf("       **************************************************\n\n");


    //自定义"图"(输入矩阵队列)
    pG = create_graph();


    print_graph(*pG);       // 打印图
    BFS(*pG);               // 广度优先遍历
    DFSTraverse(*pG);       // 深度优先遍历

    prim(*pG, 0);           // prim算法生成最小生成树
    kruskal(*pG);           // kruskal算法生成最小生成树

}


