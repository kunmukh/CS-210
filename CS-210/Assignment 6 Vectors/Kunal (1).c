#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
#define MAX 20

int    MenuPrint();
double Distance(double x1, double y1, double x2, double y2);
double Area(double a, double b, double c);
double AreaDifferenciator (double pointsarray[][1], int number_of_points, int largest_or_smallest_area, double vertex1[][2], double vertex2[][2],double vertex3[][2] );
double LineLength(double pointsarray[][2], int number_of_points,int largest_or_smallest_line,double point1[][2], double point2[][2]);

int main()
{
   int choice = 0;    

   int number_of_points = 20;
   double x1,x2,y1,y2,x3,y3;
   double point1[1][2], point2[1][2];
   double vertex1[1][2], vertex2[1][2], vertex3[1][2];

   double x[20], y[20];
   double  pointsarray[20][2];
   FILE *point;
   point = fopen("Asn06_1.txt", "r");
   for(int i = 0; i < number_of_points; ++i)
        {
            fscanf_s( point , "%lf,%lf " , &x[i],&y[i]);
        }  
          
   for (int i=0;i<20;i++)
        {   pointsarray[i][0] = x[i];
            pointsarray[i][1] = y[i];
        }    
        
    while (choice != 5)
    {
        choice = MenuPrint(); 

        if (choice == 1 || choice == 2)
        {
                int largest_or_smallest_line = choice;
                LineLength (pointsarray, number_of_points, largest_or_smallest_line, point1, point2);
                x1 = point1[0][0];
                x2 = point2[1][0];
                y1=  point1[0][1];
                y2 = point2[1][1];
                
                printf("Points are %5.2f, %5.2f and %5.2f, %5.2f\n",x1,y1,x2,y2);
             
        }
        
        else if (choice == 3 || choice == 4)
        {
            int largest_or_smallest_area = choice;
            AreaDifferenciator (pointsarray, number_of_points, largest_or_smallest_area, vertex1, vertex2, vertex3 );
            x1 = vertex1[0][0];
            x2 = vertex2[0][0];
            x3 = vertex3[0][0];
            y1=  vertex1[0][1];
            y2 = vertex2[0][1];
            y3 = vertex3[0][1];

            printf("Points are %5.2f, %5.2f, %5.2f, %5.2f and %5.2f,%5.2f\n",x1,y1,x2,y2,x3,y3);
        }
        
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

double Area(double distance1, double distance2, double distance3 )
{
    double area, s;
    s = (distance1+distance2+distance3)/2;
    area = sqrt(s*(s-distance1)*(s-distance2)*(s-distance3));
    return area;
}

double LineLength (double pointsarray[][1], int number_of_points, int largest_or_smallest_line, double point1[][2], double point2[][2])
{
    
          if (largest_or_smallest_line = 1)
          {
                double x1, y1, x2, y2;
                double dist, dist_Min;
                int i,j;                
                int iMin, jMin;
                iMin = 0;
                jMin = 1;
                
                x1 = pointsarray[iMin][0];
                y1= pointsarray[iMin][1];
                x2 = pointsarray[jMin][0];
                y2 = pointsarray[jMin][1]; 

                dist_Min = Distance( x1, y1, x2, y2); 

                for (i = 0; i < 20; i++)
                { 
                    for (j = i + 1; j < 21; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x1, y1, x2, y2);
                        if (dist < dist_Min)
                        {
                            iMin = i;
                            jMin = j;
                            dist_Min = dist;
                        }
                    }
                }
                    
                         point1[iMin][0] = x1;
                         point1[iMin][1] = y1;
                         point2[jMin][0] = x2;
                         point2[jMin][1] = y2;
                            
                                   
                                 
          }   
    
          if  (largest_or_smallest_line = 2)
          {
                double x1, y1, x2, y2;
                double dist_max, dist ;
                int iMax, jMax;
                int i,j;
                iMax = 0;
                jMax = 1;
                
                x1 = pointsarray[iMax][0];
                y1= pointsarray[iMax][1];
                x2 = pointsarray[jMax][0];
                y2 = pointsarray[jMax][1]; 

                dist_max = Distance( x1, y1, x2, y2); 

                for (i = 0; i < 20; i++)
                { 
                    for (j = i + 1; j < 21; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x1, y1, x2, y2);
                        if (dist > dist_max)
                        {
                            iMax = i;
                            jMax = j;
                            dist_max = dist;
                        }
                    }
                }
                    
               
                         for    ( int i = 0; i < 2; i++)
                                {   
                                    point1[iMax][0] = x1;
                                    point1[iMax][1] = y1;
                                    point2[jMax][0] = x2;
                                    point2[jMax][1] = y2;
                                 } 

          }
       
}

double AreaDifferenciator (double pointsarray[][1], int number_of_points, int largest_or_smallest_area, double vertex1[][2], double vertex2[][2],double vertex3[][2] )
{
    double distance_a,distance_b,distance_c;
    double x1,y1,x2,y2,x3,y3;    
   
   if (largest_or_smallest_area == 3)
       {
          
                double dist, dist_Min;
                int i,j;                
                int iMin, jMin;
                iMin = 0;
                jMin = 1;
                x3=0, y3=0;
                
                x1 = pointsarray[iMin][0];
                y1= pointsarray[iMin][1];
                x2 = pointsarray[jMin][0];
                y2 = pointsarray[jMin][1]; 

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
                            iMin = i;
                            jMin = j;
                            dist_Min = dist;
                        }
                    }
                }
                    
               
                           
                                    vertex1[0][0] = x1;
                                    vertex1[0][1] = y1;

                dist_Min = Distance( x2, y2, x3, y3); 

                for (i = 0; i < 19; i++)
                { 
                    for (j = i + 1; j < 20; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x2, y2, x3, y3);
                        if (dist < dist_Min)
                        {
                            iMin = i;
                            jMin = j;
                            dist_Min = dist;
                        }
                    }
                }
                                    vertex2[0][0] = x2;
                                    vertex2[0][1] = y2;
                                    vertex3[0][0] = x3;
                                    vertex3[0][1] = y3;
                                 
        }

   else if (largest_or_smallest_area == 4)
   {
         double dist, dist_Max;
                int i,j;                
                int iMax, jMax;
                iMax = 0;
                jMax = 1;
                x3=0, y3=0;
                
                x1 = pointsarray[iMax][0];
                y1= pointsarray[iMax][1];
                x2 = pointsarray[jMax][0];
                y2 = pointsarray[jMax][1]; 

                dist_Max = Distance( x1, y1, x2, y2); 

                for (i = 0; i < 20; i++)
                { 
                    for (j = i + 1; j < 21; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x1, y1, x2, y2);
                        if (dist > dist_Max)
                        {
                            iMax = i;
                            jMax = j;
                            dist_Max = dist;
                        }
                    }
                }
                    
               
                           
                                    vertex1[0][0] = x1;
                                    vertex1[0][1] = y1;

                dist_Max = Distance( x2, y2, x3, y3); 

                for (i = 0; i < 19; i++)
                { 
                    for (j = i + 1; j < 20; j++)
                    {
                        x1 = pointsarray[i][0];
                        y1 = pointsarray[i][1];
                        x2 = pointsarray[j][0];
                        y2 = pointsarray[j][1];
                        dist = Distance( x2, y2, x3, y3);
                        if (dist < dist_Max)
                        {
                            iMax = i;
                            jMax = j;
                            dist_Max = dist;
                        }
                    }
                }
                                    vertex2[0][0] = x2;
                                    vertex2[0][1] = y2;
                                    vertex3[0][0] = x3;
                                    vertex3[0][1] = y3;
    }
 }
 