#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "stat_util.h"

#define EPSILON 1e-6 /* Tolerance for floating-point comparisons */

static void test_combinations(void);
static void test_permutations(void);
static void test_binomial_probability(void);
static void test_mean(void);
static void test_median(void);
static void test_variance(void);
static void test_standard_deviation(void);
static void test_range(void);
static void test_mode(void);
static void test_percentile(void);
static void test_normalize_malloc(void);
static void test_z_score(void);

int main(void)
{
    test_combinations();
    test_permutations();
    test_binomial_probability();
    test_mean();
    test_median();
    test_variance();
    test_standard_deviation();
    test_range();
    test_mode();
    test_percentile();
    test_normalize_malloc();
    test_z_score();

    printf("All tests passed!\n");
    return 0;
}

static void test_combinations(void)
{
    assert(combinations(5, 3) == 10.0);
    assert(combinations(0, 0) == 1.0);
    assert(combinations(10, 0) == 1.0);
    assert(combinations(5, 5) == 1.0);
    assert(combinations(5, -1) == 0.0);
    assert(combinations(-5, 3) == 0.0);
}

static void test_permutations(void)
{
    assert(permutations(5, 3) == 60.0);
    assert(permutations(0, 0) == 1.0);
    assert(permutations(10, 0) == 1.0);
    assert(permutations(5, 5) == 120.0);
    assert(permutations(5, -1) == 0.0);
    assert(permutations(-5, 3) == 0.0);
}

static void test_binomial_probability(void)
{
    assert(fabs(binomial_probability(5, 3, 0.5) - 0.3125) < EPSILON);
    assert(binomial_probability(5, 0, 0.5) > 0.0);
    assert(binomial_probability(5, 6, 0.5) == 0.0);
    assert(binomial_probability(-5, 3, 0.5) == 0.0);
    assert(binomial_probability(5, 3, -0.1) == 0.0);
    assert(binomial_probability(5, 3, 1.1) == 0.0);
}

static void test_mean(void)
{
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    assert(fabs(mean(data, 5) - 3.0) < EPSILON);
    assert(mean(NULL, 5) == 0.0);
    assert(mean(data, 0) == 0.0);
}

static void test_median(void)
{
    double data1[] = {1.0, 3.0, 2.0, 5.0, 4.0};
    double data2[] = {1.0, 3.0, 2.0, 4.0};
    assert(fabs(median(data1, 5) - 3.0) < EPSILON);
    assert(fabs(median(data2, 4) - 2.5) < EPSILON);
    assert(median(NULL, 5) == 0.0);
    assert(median(data1, 0) == 0.0);
}

static void test_variance(void)
{
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    assert(fabs(variance(data, 5) - 2.0) < EPSILON);
    assert(variance(NULL, 5) == 0.0);
    assert(variance(data, 0) == 0.0);
}

static void test_standard_deviation(void)
{
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    assert(fabs(standard_deviation(data, 5) - sqrt(2.0)) < EPSILON);
    assert(standard_deviation(NULL, 5) == 0.0);
    assert(standard_deviation(data, 0) == 0.0);
}

static void test_range(void)
{
    double data[] = {1.0, 5.0, 3.0, 2.0, 4.0};
    assert(fabs(range(data, 5) - 4.0) < EPSILON);
    assert(range(NULL, 5) == -1.0);
    assert(range(data, 0) == -1.0);
}

static void test_mode(void)
{
    double data1[] = {1.0, 2.0, 2.0, 3.0, 4.0};
    double data2[] = {1.0, 1.0, 2.0, 2.0};
    assert(fabs(mode(data1, 5) - 2.0) < EPSILON);
    assert(fabs(mode(data2, 4) - 1.0) < EPSILON);
    assert(mode(NULL, 5) == -1.0);
    assert(mode(data1, 0) == -1.0);
}

static void test_percentile(void)
{
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    assert(fabs(percentile(data, 5, 50.0) - 3.0) < EPSILON);
    assert(fabs(percentile(data, 5, 100.0) - 5.0) < EPSILON);
    assert(percentile(NULL, 5, 50.0) == -1.0);
    assert(percentile(data, 0, 50.0) == -1.0);
    assert(percentile(data, 5, -10.0) == -1.0);
}

static void test_normalize_malloc(void)
{
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double* normalized;
    normalized = normalize_malloc(data, 5);

    assert(normalized != NULL);
    assert(fabs(normalized[0]) < EPSILON);
    assert(fabs(normalized[4] - 1.0) < EPSILON);

    free(normalized);
}

static void test_z_score(void)
{
    assert(fabs(z_score(5.0, 3.0, 2.0) - 1.0) < EPSILON);
    assert(z_score(5.0, 3.0, 0.0) == 0.0);
}
