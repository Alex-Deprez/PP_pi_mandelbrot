#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double pi_naif(long long N) {
   double global_res = 0.0;
    double invN = 1.0 / N;

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nb_threads = omp_get_num_threads();

        long long intervalle = N / nb_threads;
        long long debut = id * intervalle;
        long long fin = (id == nb_threads - 1) ? N : (id + 1) * intervalle;

        double local_res = 0.0;
        for (long long i = debut; i < fin; i++) {
            double x = (i + 0.5) * invN;
            local_res += 4.0 / (x * x + 1.0);
        }

        #pragma omp critical
        {
            global_res += local_res;
        }
    }
    return global_res * invN;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("USAGE: %s N\n", argv[0]);
        return 1;
    }
    long long N = atoll(argv[1]);

    double start = omp_get_wtime();
    double result = pi_naif(N);
    double end = omp_get_wtime();

    printf("Pi : %.10f | Temps : %lf s\n", result, end - start);
    return 0;
}
