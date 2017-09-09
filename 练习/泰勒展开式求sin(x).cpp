#include <stdio.h>

#include <math.h>


int jiecheng(int n)
{
   int result = 1;
   if(n==0) return result;

   else
   {
       while(n)
       {
           result *= n;
           n--;
       }
       return result;
   }
}


double dsin(double x)
{
   double result = x;
   int n = 3;
   int sign = -1;
   double temp;
   while(1)
   {
       temp = pow(x,n)/jiecheng(n);
       if(temp<0.000001)return result;
       temp *= sign; //��ſ���
       result += temp;
       n +=2;
       sign *=-1;
   }
}


int main()
{
   double p;
   p = 1;
   printf("%.10lf  %.10lf", dsin(p),sin(p));

   getchar();
   getchar();
   return 0;
}
//double���͵����������,���ǽ���ڿɽ��ܷ�Χ��
//������̩��չ���������㣬������sin(1) 
//�׳˿��ܻ����
/********************************************************************/
#include<stdio.h>
double dt(double x,int n)
{
    double i;
    double s=1;
    for(i=1;i<=n;i++)
    {
        s*=x/i;
}

    return s;
}
int main()
{
    double t,x,sum=0;
    int sign=1,i=1;
    scanf("%lf",&x);
    t=dt(x,1);
    while(t>0.00000001)
    {
        sum+=sign*t;
        sign*=-1;
        t=dt(x,2*i+1);
        i++;
    }
    printf("%.10lf\n%d",sum,i);

    getchar();
    getchar();
    return 0;
}

/*****************************************************/
#include<math.h>
#include<stdio.h>
int main(){
    int n=1,count=1;
    float x;
    double sum ,term;
    printf("input x:");
    scanf("%f",&x);
    sum=x;
    term=x;
    do{
        term=-term*x*x/((n+1)*(n+2));
        sum=sum+term;
        n=n+2;
        count++;
    }while (fabs(term)>=1e-5);//������Ըľ��ȣ��Ҹ������10��-5�η��ľ��� 
    printf("sin(x)=%g,count=%d\n",sum,count); 
    printf("sin(x)=%10lf,count=%d\n",sum,count); 
    getchar();
    getchar();
    return 0;
}
#include<math.h>
#include<stdio.h>
main()
 {
   int n=1,count=1;
   float x;
   double sum ,term;
   printf("input x:");
   scanf("%f",&x);
   sum=x;
   term=x;
   do
    {
     term=-term*x*x/((n+1)*(n+2));
     sum=sum+term;
     n=n+2;
     count++;
      }
     while (fabs(term)>=1e-50);
    printf("sin(x)=%f,count=%d\n",sum,count);
    getchar();
    getchar();
   }

#include"iostream"  
#include "Cmath"// �ԱȽ�������ÿ⺯����  
using namespace std;  
double mysin(double);// ����  
double mycos(double);  
double myabs(double);     //Ҫ�󾫶ȵľ���ֵ��  
  
  
const int pi = 3.1415926;  
  
  
int main()  
  
{  
    cout << " �⺯��   ��sin(3.14/2)��ֵΪ��" << sin(pi / 2) << endl;  
    cout << "�Զ����  sin(3.14/2)��ֵΪ��" << mysin(pi / 2);  
  
    cout << "�Զ����sin(56')��ֵΪ" << mysin((56.0/180)*pi)<< endl;  
    cout << "�⺯���� sin(56')��ֵΪ" << sin((56.0 / 180)*pi) << endl;  
  
  
    cout << "�⺯����    cos(87)" <<cos((87.0/180)*pi )<< endl;  
    cout << "�Զ����   cos(87)" << mycos( (87.0/180)/pi)<< endl;   
  
    cout << "���ÿ⺯����cos(��/3)" <<cos(pi/3) << endl;  
    cout << "�����Զ����   ��cos(��/3)" << mycos(pi / 3) << endl;  
  
  
  
  
  
  
    system("pause");  
    return 0;  
}  
double mysin(double x)  
{  
    double sum = x, x_pow = x, item;  
    int n = 1, fact = 1, sign = 1;//   �������ʱ��ֵ���Ѿ�����һ��ǵ��ۼӺ�sum����  
    do  
    {  
        fact = fact*(n + 1)*(n + 2);  
        x_pow *= x*x; fact;  
            sign = -sign; //    ȷ��Ҫ�ۼ���һ��ķ��ţ�  
            item = x_pow / fact*sign;   
            sum += item;  
            n += 2;  
      
    } while (myabs(item) > 1e-5);  
    return sum;  
  
  
}  
double mycos(double x)  
{  
    double sum = 1,x_pow = 1, item;  
    int n = 0, fact = 1, sign = -1;  
  
  
    fact = fact*(n + 1)*(n + 2);  
    item = x_pow / fact*sign;  
    x_pow *= x*x; fact;  
    sum += item;  
    sign = -sign; //    ȷ��Ҫ�ۼ���һ��ķ��ţ�  
      
    n += 2;  
  
    return sum;  
}  
double myabs(double x)  
{  
    return ((x >= 0 ? x : -x));  
} 

#include <math.h>
#include<stdio.h>
float aacos(float x){  
    unsigned char i;  
    float ans=x,t1=1,t2=x;x*=x;  
    for(i=3;i<100;i+=2){  
        t1*=(float)(i-2)/(float)(i-1);  
        t2*=x;  
        ans+=(t1*t2/(float)i);  
    }  
    return ans=1.5708-ans;  
}  
int main(){  
    float ang;  
    while(scanf("%f",&ang)!=EOF)  
        printf("%.5f   %.5f\n",aacos(ang),acos(ang));  
    return 0;  
}  