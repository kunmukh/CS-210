#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
#define MAX 20

int    MenuPrint();
double Distance(double x1, double y1, double x2, double y2);
double LineLength( double pointsarray[][2], int number_of_points,int largest_or_smallest_line, double point1[][2], double point2[][2]);

int main()
{   double  pointsarray[20][2];   double point1[1][2], point2[1][2];   double vertex1[1][2], vertex2[1][2], vertex3[1][2];   double x1,x2,y1,y2,x3,y3;   int choice = 0;  
   int number_of_points = 20;     {               double x[20], y[20];  
               FILE *point;
               point = fopen("Asn06.txt", "r");
               for(int i = 0; i < number_of_points; i++)
                    {                        fscanf_s( point , "%lf,%lf" , &x[i] , &y[i] );                    }            
               for (int i=0 ; i < 19; i++)
                    {                           pointsarray[i][0] = x[i];
                        pointsarray[i][1] = y[i];
                    }                        pointsarray;    }   
        choice = MenuPrint(); 
        if (choice == 1 || choice == 2)
        {
                int largest_or_smallest_line = choice;
                LineLength (pointsarray, number_of_points, largest_or_smallest_line, point1, point2);
                x1 = point1[0][0];
                y1=  point1[0][1];                x2 = point2[0][0];
                y2 = point2[0][1];                
                printf("Points are %5.2f, %5.2f and %5.2f, %5.2f\n",x1,y1,x2,y2);             
        }
}

int MenuPrint()
{
    int choice;
    printf("\nPlease choice a option:\n1> points closest together\n2> points further apart\n3>triangle with the smallest area\n4>triangle with the largest area\n5>exit\n");
    scanf_s("%d", &choice); 
    return choice;
}

double Distance(double x1, double y1, double x2, double y2)
{
    double distance;
    distance = sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return distance;
}

double LineLength (double pointsarray[][1], int number_of_points, int largest_or_smallest_line, double point1[][2], double point2[][2])
{
          if (largest_or_smallest_line = 1)
          {
                double x1, y1, x2, y2;
                double dist, dist_Min;
                int i, j;               
               int coord_1_min = 0;                int coord_2_min = 1;
                x1 = pointsarray[coord_1_min][0];
                y1= pointsarray[coord_1_min][1];
                x2 = pointsarray[coord_2_min][0];
                y2 = pointsarray[coord_2_min][1]; 

                dist_Min = Distance( x1, y1, x2, y2); 

                for (i = 0; i < 19; i++)
                { 
                    for (j = i + 1; j < 20; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x1, y1, x2, y2);
                        if (dist < dist_Min)
                        {
                            coord_1_min = i;
                            coord_2_min = j;
                            dist_Min = dist;
                        }
                    }
                }
                    
                         point1[coord_1_min][0] = x1;
                         point1[coord_1_min][1] = y1;
                         point2[coord_2_min][0] = x2;
                         point2[coord_2_min][1] = y2;                             
          }   
    
          if  (largest_or_smallest_line = 2)
          {                double x1, y1, x2, y2;
                double dist, dist_Min;
                int i,j;                
               int coord_1_min = 0;                int coord_2_min = 1;
                
                x1 = pointsarray[coord_1_min][0];
                y1= pointsarray[coord_1_min][1];
                x2 = pointsarray[coord_2_min][0];
                y2 = pointsarray[coord_2_min][1]; 

                dist_Min = Distance( x1, y1, x2, y2); 

                for (i = 0; i < 19; i++)
                { 
                    for (j = i + 1; j < 20; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x1, y1, x2, y2);
                        if (dist < dist_Min)
                        {
                            coord_1_min = i;
                            coord_2_min = j;
                            dist_Min = dist;
                        }
                    }
                }
                    
                         point1[coord_1_min][0] = x1;
                         point1[coord_1_min][1] = y1;
                         point2[coord_2_min][0] = x2;
                         point2[coord_2_min][1] = y2;   
                          }
       
}