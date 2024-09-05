#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double mean(double arr[], int n);

void Cov_and_Var(double x[], double y[], int n, double *Var_X, double *Var_Y, double *Cov_XY);


int main(int argc, char *argv[]) {
  double x_arr[100];
  double y_arr[100];
  
  char *x = argv[1];
  char *y = argv[2];
  
  int x_count = 0;
  int y_count = 0; 
  
  char *parser = strtok(x, ",");
  while (parser != NULL) {
    x_arr[x_count]= strtod(parser, NULL);
    x_count ++;
    parser = strtok(NULL, ",");
  }

  char *parser2 = strtok(y, ",");
  while (parser2 != NULL) {
    y_arr[y_count]= strtod(parser2, NULL);
    y_count ++;
    parser2 = strtok(NULL, ",");
  }
  int n = 4;
  double Var_X;
  double Var_Y;
  double Cov_XY;

  Cov_and_Var(x_arr, y_arr, n, &Var_X, &Var_Y, &Cov_XY);

  printf("The Cov of two input arrays is %.2f, and their own Var are %.2f and %.2f.\n", Cov_XY, Var_X, Var_Y);

  return 0;
}

double mean(double arr[], int n){
   double arr_tot = 0;
   for (int i = 0; i < n; i++){
      arr_tot += arr[i];
   }
   double mean = arr_tot/n;
   return mean;
}

void Cov_and_Var(double x[], double y[], int n, double *Var_X, double *Var_Y, double *Cov_XY){
   double mean_x = mean(x, n);
   double mean_y = mean(y, n);
   double sum_x = 0;
   double sum_y = 0;
   double sum_xy = 0;
   for (int i = 0; i < n; i++){
      sum_x += (x[i] - mean_x)*(x[i] - mean_x);
      sum_y += (y[i] - mean_y)*(y[i] - mean_y);
      sum_xy += x[i]*y[i];
   }

   *Var_X = sum_x/(n - 1); 
   *Var_Y = sum_y/(n - 1);
   *Cov_XY = sum_xy/n - (mean_x*mean_y); 
}


