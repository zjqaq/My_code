#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
static const int maxm=2e3+10;
static const int INF=~(1<<31);

int hgt[maxm][maxm],f[maxm][maxm],cant[maxm][maxm];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char ch[10];
int n,m;

void mark(int x1,int y1,int x2,int y2,bool f){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            cant[i][j]=f;
}

int dfs(int x,int y){
    if(cant[x][y])return -INF;
    if(f[x][y])return f[x][y];
    f[x][y]=1;
    for(int i=0;i<=3;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>n)continue;
        if(hgt[xx][yy]>hgt[x][y])f[x][y]=max(f[x][y],dfs(xx,yy)+1);
    }
    return f[x][y];
}

void change(int x,int y,int h){
    hgt[x][y]=h;
}

int main(){
    int x1,x2,y1,y2,x,y,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        scanf("%d",&hgt[i][j]);
    scanf("%d",&m);

    while(m--){
    scanf("%s",ch);
        if(ch[0]=='C')scanf("%d%d%d",&x,&y,&c),change(x,y,c);
        else if(ch[0]=='S')scanf("%d%d%d%d",&x1,&y1,&x2,&y2),mark(x1,y1,x2,y2,1);
        else if(ch[0]=='B')scanf("%d%d%d%d",&x1,&y1,&x2,&y2),mark(x1,y1,x2,y2,0);
        else if(ch[0]=='Q'){
            int ans=0;
            memset(f,0,sizeof f);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    ans=max(ans,dfs(i,j));
            printf("%d\n",ans);
        }
    }

    return 0;
}
