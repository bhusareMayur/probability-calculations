#include<stdio.h>
#include<conio.h>
#include<math.h>

float sum_x(float X[],int n);
float sum_y(float Y[],int n);
float sum_xx(float X[],int n);
float sum_yy(float Y[],int n);
float sum_xy(float X[],float Y[],int n);
float std_x(float X[], int n);
float std_y(float Y[], int n);
float coeff_of_corl(float X[],float Y[], int n); 
float coeff_of_var_x(float X[], int n);
float coeff_of_var_y(float Y[], int n);

int  main(){
    
    int i,n,choice,a;
    float s;
    float X[100];
    float Y[100];
    do{
    system("cls");
    printf("Please enter the  number of events = ");
    scanf("%d",&n);
    system("cls");
    printf("Please enter the values of X =\n");
    for(i=0;i<n;i++){
        scanf("%f",&X[i]);
      
    }
    system("cls");
    printf("Please  enter the values of Y =\n");
    for(i=0;i<n;i++){
        scanf("%f",&Y[i]);
       
    }
    
    system("cls");
    printf("Please enter your choice \n1. sum of x \n2. sum of y\n3. sum of x^2 \n");
    printf("4. sum of y^2 \n5. sum of xy  \n6. standard deviation  of x\n");
    printf("7. standard devition  of y \n8. Coefficient of correlation \n");
    printf("9. coefficient of variance of X \n10. coefficient of variance of Y\n");
    printf("11. End program \n");
scanf("%d",&choice);
    
    switch(choice){
        
        case 1:
         s=sum_x(X,n);
         system("cls");
        printf("Sum of X is  %f \n\n\n",s);
        break;
        
        
        case 2:
         s=sum_y(Y,n);
         system("cls");
        printf("Sum of Y is  %f \n\n\n",s);
        break;
        
        case 3:
        s=sum_xx(X,n);
        system("cls");
        printf("Sum of X^2 is  %f \n\n\n",s);
        break;
        
        
        case 4:
        s=sum_yy(Y,n);
        system("cls");
        printf("Sum of Y^2 is  %f\n\n\n",s);
        break;
        
        
        case 5:
        s=sum_xy(X,Y,n);
        system("cls");
        printf("Sum of XY is %f\n\n\n",s);
        break;
        
        case 6:
       system("cls");
        printf("Standard deviation of X is %f\n\n\n",std_x(X,n));
        break;
        
        case 7:
        system("cls");
        printf("Standard deviation of y is %f\n\n\n",std_y(Y,n));
        break;
        
        case 8:
           system("cls");
        printf("Coefficient of correlation is  %f \n\n\n",coeff_of_corl(X,Y,n));
        break;

        case 9:
          system("cls");
        printf("Coefficient of variation of X is  %f\n\n\n ",coeff_of_var_x(X,n));
        break;
        
        case 10:
           system("cls");
        printf("Coefficient of variation of y is  %f\n\n\n ",coeff_of_var_y(Y,n));
        break;

        case 11:
        printf("\n\n\n\n\nprogram ended successfully \n\n\n\n");
        return 1;
        break;

        default:
        printf("Please enter valid choice  \n\n\n\n");
 
    } 
    if(choice > 11 || choice < 1){
      printf("\nIf you want to try again then press 1 otherwise press 2\n");
scanf("%d",&a);
if(a!=1){
     printf("\n\n\n\n\nprogram ended successfully \n\n\n\n");
return 1;
}
    }
    else{
printf("\nIf you want to continue then press 1 otherwise press 2\n");
scanf("%d",&a);
if(a!=1){
     printf("\n\n\n\n\nprogram ended successfully \n\n\n\n");
return 1;
}
    }
    }while(a==1);
    return 0;    
}

float sum_x(float X[],int n){
    
    int i;
    float add=0.0;
    for(i=0;i<n;i++){
        
        add=add+X[i];
    
    }
    
    
    return add;
    
}

float sum_y(float Y[],int n){
    
   float add=0.0;

    int i;
    for(i=0;i<n;i++){
       
        add=add+Y[i];
    
    }
    
    
    return add;
    
}


float sum_xx(float X[],int n){
    
   float add=0.0;
    int i;
    for(i=0;i<n;i++){
        
        add=add+(X[i]*X[i]);
    
    }
    
    
    return add;
    
}

float sum_yy(float Y[],int n){
    
   float add=0.0;

    int i;
    for(i=0;i<n;i++){
       
        add=add+(Y[i]*Y[i]);
    }
    
    
    return add;
    
}

float sum_xy(float X[],float Y[],int n){
   
   float add=0.0;

    int i;
    for(i=0;i<n;i++){
        
        add=add+X[i]*Y[i];
   
    }
    
    
    return add;
    
}

float std_x(float X[], int n){
    
    float mean=((sum_x(X,n))/n); 
    float xx=((sum_xx(X,n))/n);
    float sd=xx-(mean*mean);
    float  std=sqrt(sd);
    return std;
  
}

float std_y(float Y[], int n){
   
    float mean=((sum_y(Y,n))/n);
    float yy=((sum_yy(Y,n))/n);
    
    
    float sd=yy-(mean*mean);
  float  std=sqrt(sd);
    
    return std;
   
}


float coeff_of_var_x(float X[], int n){

float var_x ;
var_x=((std_x(X,n))/((sum_x(X,n))/n))*100;

return var_x;

}


float coeff_of_var_y(float Y[], int n){

float var_y ;
var_y=((std_y(Y,n))/((sum_y(Y,n))/n))*100;

return var_y;


}


float coeff_of_corl(float X[],float Y[], int n){
  
float std1=std_x(X,n);
float std2=std_y(Y,n);
float dinomerator=(std1*std2);
float std3=(sum_xy(X,Y,n));
float std4=(sum_x(X,n));
float std5=(sum_y(Y,n));

float numeretor =((std3/n)-((std4/n)*(std5/n)));

float coeffcorl=((numeretor)/(dinomerator));

return coeffcorl;

}