#include<cstdlib>
#include<cstdio>
#include <iostream>
#include <bitset>

int swap[16]={0x0,0x8,0x4,0xc,0x2,0xa,0x6,0xe,0x1,0x9,0x5,0xd,0x3,0xb,0x7,0xf};
int max[12]={8,8,8,8,8,4,4,4,4,2,1,1};
int uses[24]={};
int usepos=0;
struct piece{
    int maxlengy=0;
    int maxlengx=0;
    int minlengx=0;
    unsigned long long shape=0;
};
piece array[12][8];
struct complexpiece{
    unsigned long long v1;//v is like-----
    unsigned long long v2;
    unsigned long long v3;
    unsigned long long v4;
    unsigned long long h1;///h ils like |
    unsigned long long h2;
    unsigned long long h3;
    unsigned long long h4;
};

piece transform(complexpiece b){
    int mxb=3;
    int mnb=0;
    int mnh=0;
    int mxh=3;
    int min=0;
    if (b.h1==0){mxb=mxb-1;
        if (b.h2==0){mxb=mxb-1;
        if (b.h3==0){mxb=mxb-1;}
        }
    }
    
    
    if (b.h4==0){mnb=mnb+1;
        if (b.h3==0){mnb=mnb+1;
        if (b.h2==0){mnb=mnb+1;}
    }
    }
    if (b.v1==0){mxh=mxh-1;
        if (b.v2==0){mxh=mxh-1;
        if (b.v3==0){mxh=mxh-1;}
        }
    }
    
    
    if (b.v4==0){mnh=mnh+1;
        if (b.v3==0){mnh=mnh+1;
        if (b.v2==0){mnh=mnh+1;}
    }
    }
    unsigned long long c=(b.v1<<33) | (b.v4) |(b.v2<<22)| (b.v3<<11);
    c=c>>(mnh*11);
    c=c>>mnb;
    mxb=mxb-mnb;
    mxh=mxh-mnh;
    while ((c & 0b1)==0){
        c=c>>1;
        mxb=mxb-1;
        min=min-1;
    }
    piece d={mxh,mxb,min,c};
    return d;
}

int rotate(){
    complexpiece l= {0x0,0x2,0x2,0x6,0x0,0x1,0x7,0x0};
    for(int i=0;i<4;i++){
        array[0][2*i]=transform(l);
        complexpiece t={l.v4,l.v3,l.v2,l.v1,l.h1,l.h2,l.h3,l.h4};
        array[0][2*i+1]=transform(t);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x1,0x3,0x3,0x0,0x0,0x3,0x7};
    for(int i=0;i<4;i++){
        array[1][2*i]=transform(l);
        complexpiece t={l.v4,l.v3,l.v2,l.v1,l.h1,l.h2,l.h3,l.h4};
        array[1][2*i+1]=transform(t);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x1,0x1,0x1,0x3,0x0,0x0,0x1,0xf};
    for(int i=0;i<4;i++){
        array[2][2*i]=transform(l);
        complexpiece t={l.v4,l.v3,l.v2,l.v1,l.h1,l.h2,l.h3,l.h4};
        array[2][2*i+1]=transform(t);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x1,0x1,0x3,0x1,0x0,0x0,0x2,0xf};
    for(int i=0;i<4;i++){
        array[3][2*i]=transform(l);
        complexpiece t={l.v4,l.v3,l.v2,l.v1,l.h1,l.h2,l.h3,l.h4};
        array[3][2*i+1]=transform(t);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }

    l= {0x1,0x1,0x3,0x2,0x0,0x0,0x3,0xe};
    for(int i=0;i<4;i++){
        array[4][2*i]=transform(l);
        complexpiece t={l.v4,l.v3,l.v2,l.v1,l.h1,l.h2,l.h3,l.h4};
        array[4][2*i+1]=transform(t);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x0,0x1,0x3,0x0,0x0,0x1,0x3};
    for(int i=0;i<4;i++){
        array[5][i]=transform(l);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x1,0x1,0x7,0x0,0x1,0x1,0x7};
    for(int i=0;i<4;i++){
        array[6][i]=transform(l);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x1,0x3,0x6,0x0,0x1,0x3,0x6};
    for(int i=0;i<4;i++){
        array[7][i]=transform(l);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x0,0x5,0x7,0x0,0x3,0x1,0x3};
    for(int i=0;i<4;i++){
        array[8][i]=transform(l);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x1,0x1,0x1,0x1,0x0,0x0,0x0,0xf};
    for(int i=0;i<2;i++){
        array[9][i]=transform(l);
        l={swap[l.h1],swap[l.h2],swap[l.h3],swap[l.h4],l.v4,l.v3,l.v2,l.v1};
    }
    l= {0x0,0x0,0x3,0x3,0x0,0x0,0x3,0x3};
    array[10][0]=transform(l);
    l= {0x0,0x2,0x7,0x2,0x0,0x2,0x7,0x2};
    array[11][0]=transform(l);
    return 0;
}

bool recursive(int x,int y,unsigned long long board,int fpos,unsigned long used,int usedf){
    if(used==0){
        return true;
    }
    unsigned long uset=used>>usedf;
    for(int i = usedf; i<12 ;i++){
    int l=0;
    while (l<max[i]){
        if((board & (array[i][l].shape<<fpos))==0){
            if((x+array[i][l].maxlengx<11)&&(x+array[i][l].minlengx>-1)&&(y+array[i][l].maxlengy<5)){
                unsigned long long boar=board|(array[i][l].shape<<fpos);
                unsigned long long bt=boar>>fpos;
                int t=0;
                while((bt & 0b1)!=0){
                    bt=bt>>1;
                    t=t+1;
                }
                int f=0;
                unsigned long usef=used&(~(0b1<<i));
                unsigned long usete=usef>>usedf;
                int p=0;
                while(((usete&0b1)==0)&(f<13)){
                usete=usete>>1;
                f++;
                }
                if(recursive((fpos+t)%11,(fpos+t)/11,boar,fpos+t,usef,usedf+f)){
                    uses[usepos]=i;
                    uses[usepos+1]=l;
                    usepos=usepos+2;
                    return true;
                }
            }
        }
        l=l+1;
        
    }
    uset=uset>>1;   
    while(((uset&0b1)==0)&&(i<13)){
    uset=uset>>1;
    i=i+1;
    }
    }
    
    return false;
}
int main(){
rotate();
recursive(0,0,0b0,0,0b111111111111,0);
for(int i=0;i<24;i++){
    std::cout<<uses[i]<<"\n";
}
return 0;
}