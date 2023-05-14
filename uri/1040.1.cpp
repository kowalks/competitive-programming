#include<stdio.h>
 int main(){
   float a,b,c,d,e,m,n;
    scanf("%f %f %f %f %f", &a, &b, &c, &d, &e);
     m = (((2*a) + (3*b) + (4*c) + (1*d))/10);
     if(m>=(7.0))
      printf("Media: %.1f\nAluno aprovado.\n",m);
     if(m<(5.0))
      printf("Media: %.1f\nAluno reprovado.\n",m);
     else if(((m>=5.0)) && (m<=(6.9))){
      n=((m+e)/(2.0));
      if(n>=(5.0))
       printf("Media: %.1f\nAluno em exame.\nNota do exame: %.1f\nAluno aprovado.\nMedia final: %.1f\n",m,e,n);
      else
       printf("Media: %.1f\nAluno em exame.\nNota do exame: %.1f\nAluno reprovado.\nMedia final: %.1f\n",m,e,n);
     }
 return 0;
 }
