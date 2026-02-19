#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double my_gettimeofday()
{
    struct timeval tmp_time;
    gettimeofday(&tmp_time, NULL);
    return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

double calculate_pi(long long N)
{
    double delta = 0.0;

    for (int i = 0; i < N; i++)
    {
        double v = (double)i / N;
        delta += 4 / (1 + v * v);
    }

    return delta / N;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: %s N\n", argv[0]);
        return EXIT_FAILURE;
    }

    long long N = atoll(argv[1]);

    double start = my_gettimeofday();
    double result = calculate_pi(N);
    double end = my_gettimeofday();

    printf("Pi : %.10f | Temps : %g s\n", result, end - start);
    return EXIT_SUCCESS;
}
