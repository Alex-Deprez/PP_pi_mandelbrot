#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double time_start, time_end;
double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}
double pi(long long N){
    double res = 0.0;
    double invN = 1.0 / N;

    #pragma omp parallel for reduction(+:res) schedule(runtime)
        for (long long i = 0; i < N; i++) {
            double x = (double)i * invN; 
            res += 4.0 / (x * x + 1.0);
        }
    return invN * res;
}


int main(int argc, char * argv[]){
    

    if (argc < 2){
        printf("USAGE : ./exercice5 N");

    }
    printf("le schedule est : %s\n", getenv("OMP_SCHEDULE"));
    long long N = atoll(argv[1]);
    
    
    time_start = my_gettimeofday();

    printf("la valeur de pi est : %lf \n", pi(N));

    time_end = my_gettimeofday();
    printf("temps : %lf \n", time_end - time_start );
    return 0;
}