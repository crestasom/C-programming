#include<stdio.h>
#include<math.h>
typedef struct
{
    int x1,x2,t;
}Input;

void neuronAdaline(float *w1,float *w2,float *b,Input ipSet[],int i,int thres,float alpha)
{
    static int step=1;
    float e1,e2,eb;
    float w1Temp=*w1,w2Temp=*w2,bTemp=*b,dw1,dw2,db;
    float yin=(*w1)*ipSet[i].x1+(*w2)*ipSet[i].x2+(*b);

    dw1=alpha*ipSet[i].x1*(ipSet[i].t-yin);
    dw2=alpha*ipSet[i].x2*(ipSet[i].t-yin);
    db=alpha*(ipSet[i].t-yin);
    *w1+=dw1;
    *w2+=dw2;
    *b+=db;
    e1=fabs(*w1-w1Temp);
    e2=fabs(*w2-w2Temp);
    eb=fabs(*b-bTemp);
    printf("\nStep=%d\tw1=%f\tw2=%f\tb=%f\t",step,*w1,*w2,*b);
    printf("\nx1=%d\tx2=%d\tt=%d\t",ipSet[i].x1,ipSet[i].x2,ipSet[i].t);
    printf("\nw1=%f\tw2=%f\tb=%f\t",w1Temp,w2Temp,bTemp);
    printf("\ne1=%f\te2=%f\teb=%f",e1,e2,eb);
    printf("\nyin=%f\n",yin);
    if((e1>thres||e2>thres||eb>thres)&&step<100)
    {
        step++;
        neuronAdaline(w1,w2,b,ipSet,(i+1)%4,thres,alpha);
    }
}

int validationPhase(int x1,int x2,float w1,float w2,float b)
{
    return (x1*w1+x2*w2+b)>0?1:-1;
}
main()
{
    Input ipSet[4];
    int x1[]={1,1,-1,-1},x2[]={1,-1,1,-1},t[]={1,-1,-1,-1},i=0,iter=0;
    float alpha=0.01,thres=0.001;
    for(i=0;i<4;i++)
    {
        ipSet[i].x1=x1[i];
        ipSet[i].x2=x2[i];
        ipSet[i].t=t[i];
    }

    float w1=0.2,w2=0.3,b=0.1;
    for(i=0;i<4;i++){
        printf("\nx1=%d\tx2=%d\noutput=%d",ipSet[i].x1,ipSet[i].x2,validationPhase(ipSet[i].x1,ipSet[i].x2,w1,w2,b));
    }
    neuronAdaline(&w1,&w2,&b,ipSet,iter,thres,alpha);
    printf("\nFinal Values:\n");
    printf("\nw1=%f\tw2=%f\tb=%f\t",w1,w2,b);
    printf("\nValidation Phase:\n");
    for(i=0;i<4;i++){
        printf("\nx1=%d\tx2=%d\noutput=%d",ipSet[i].x1,ipSet[i].x2,validationPhase(ipSet[i].x1,ipSet[i].x2,w1,w2,b));
    }
}
