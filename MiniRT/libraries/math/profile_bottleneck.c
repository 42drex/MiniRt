#ifndef _POSIX_C_SOURCE
# define _POSIX_C_SOURCE 199309L
#endif

#include "mymath.h"
#include <time.h>
#include <stdio.h>

#define ITERATIONS 10000000

// Mesure le temps en nanosecondes
static long measure_time(struct timespec start, struct timespec end)
{
    long seconds = end.tv_sec - start.tv_sec;
    long nanos = end.tv_nsec - start.tv_nsec;
    return seconds * 1000000000L + nanos;
}

// Test des opérations tuple
static void profile_tuple_ops(void)
{
    struct timespec start, end;
    t_tuple a = {1.0f, 2.0f, 3.0f, 1.0f};
    t_tuple b = {4.0f, 5.0f, 6.0f, 1.0f};
    t_tuple result;
    long elapsed;
    unsigned int i;

    printf("\n=== TUPLE OPERATIONS ===\n");

    // Addition
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = add_tupple(a, b);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("add_tupple:    %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Soustraction
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = sub_tupple(a, b);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("sub_tupple:    %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Multiplication
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = prod_tuple(a, 2.0f);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("prod_tuple:    %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Négation
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = neg_tupple(a);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("neg_tupple:    %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    (void)result;
}

// Test des opérations vector
static void profile_vector_ops(void)
{
    struct timespec start, end;
    t_vector v1 = {3.0f, 4.0f, 5.0f, 0.0f};
    t_vector v2 = {1.0f, 2.0f, 3.0f, 0.0f};
    t_vector result;
    float fresult;
    long elapsed;
    unsigned int i;

    printf("\n=== VECTOR OPERATIONS ===\n");

    // Magnitude
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        fresult = magnitude(v1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("magnitude:     %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Normalize
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = normalize(v1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("normalize:     %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Dot product
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        fresult = dot_product(v1, v2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("dot_product:   %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Cross product
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = cross(v1, v2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("cross:         %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    (void)result;
    (void)fresult;
}

// Test des opérations point
static void profile_point_ops(void)
{
    struct timespec start, end;
    t_point p = {1.0f, 2.0f, 3.0f, 1.0f};
    t_vector v = {1.0f, 1.0f, 1.0f, 0.0f};
    t_point result;
    long elapsed;
    unsigned int i;

    printf("\n=== POINT OPERATIONS ===\n");

    // Forward
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = new_point_forward(p, v);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("point_forward: %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Backward
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        result = new_point_backward(p, v);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("point_backward:%6.2f ns/op\n", (double)elapsed / ITERATIONS);

    (void)result;
}

// Test des opérations matrice
static void profile_matrix_ops(void)
{
    struct timespec start, end;
    t_mat4 m1, m2, result;
    long elapsed;
    unsigned int i;

    printf("\n=== MATRIX OPERATIONS ===\n");

    // Initialisation
    mat4_set_row(&m1, 0, 1.0f, 2.0f, 3.0f, 4.0f);
    mat4_set_row(&m1, 1, 5.0f, 6.0f, 7.0f, 8.0f);
    mat4_set_row(&m1, 2, 9.0f, 10.0f, 11.0f, 12.0f);
    mat4_set_row(&m1, 3, 13.0f, 14.0f, 15.0f, 16.0f);

    mat4_set_row(&m2, 0, 2.0f, 0.0f, 0.0f, 0.0f);
    mat4_set_row(&m2, 1, 0.0f, 2.0f, 0.0f, 0.0f);
    mat4_set_row(&m2, 2, 0.0f, 0.0f, 2.0f, 0.0f);
    mat4_set_row(&m2, 3, 0.0f, 0.0f, 0.0f, 1.0f);

    // Multiplication
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        matrice_product(&result, &m1, &m2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("matrice_product: %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Égalité
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        matrice_is_equal(&m1, &m2);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("matrice_equal:   %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Matrice × Tuple (TRÈS utilisé dans miniRT !)
    t_tuple tup = {1.0f, 2.0f, 3.0f, 1.0f};
    t_tuple tres;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        tres = matrice_to_tuple(&m1, tup);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("matrice×tuple:   %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    (void)result;
    (void)tres;
}

// Test des conversions
static void profile_conversions(void)
{
    struct timespec start, end;
    t_tuple tup = {1.0f, 2.0f, 3.0f, 1.0f};
    t_vector vec;
    t_point pt;
    long elapsed;
    unsigned int i;

    printf("\n=== CONVERSIONS ===\n");

    // Tuple to vector
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        vec = tuple_to_vector(tup);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("tuple_to_vector: %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    // Tuple to point
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < ITERATIONS; i++)
        pt = tuple_to_point(tup);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = measure_time(start, end);
    printf("tuple_to_point:  %6.2f ns/op\n", (double)elapsed / ITERATIONS);

    (void)vec;
    (void)pt;
}

int main(void)
{
    printf("=================================\n");
    printf("   PROFILER DE BOTTLENECKS SIMD\n");
    printf("=================================\n");
    printf("Iterations: %d\n", ITERATIONS);

    profile_tuple_ops();
    profile_vector_ops();
    profile_point_ops();
    profile_matrix_ops();
    profile_conversions();

    printf("\n=================================\n");
    printf("ANALYSE:\n");
    printf("- Opérations < 10 ns : EXCELLENT ✅\n");
    printf("- Opérations 10-50 ns : BON ⚠️\n");
    printf("- Opérations > 50 ns : BOTTLENECK ❌\n");
    printf("=================================\n");

    return 0;
}
