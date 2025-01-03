#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "stat_util.h"

double combinations(int n, int k)
{
    int i;
    double result;
    double numerator;
    double denominator;

    if (n < 0 || k < 0 || k > n) {
        return 0.0;
    }

    numerator = 1.0;
    denominator = 1.0;

    for (i = 0; i < k; i++) {
        numerator *= (n - i);
        denominator *= (i + 1);
    }

    result = numerator / denominator;
    return result;
}

double permutations(int n, int k)
{
    int i;
    double result;

    if (n < 0 || k < 0 || k > n) {
        return 0.0;
    }

    result = 1.0;

    for (i = 0; i < k; i++) {
        result *= (n - i);
    }

    return result;
}

double binomial_probability(int trials, int success, double p)
{
    double combination;
    double probability;

    if (trials < 0 || success < 0 || success > trials || p < 0.0 || p > 1.0) {
        return 0.0;
    }

    combination = combinations(trials, success);
    probability = combination * pow(p, success) * pow(1.0 - p, trials - success);

    return probability;
}

double mean(const double* data, size_t size)
{
    size_t i;
    double sum;
    
    if (data == NULL || size == 0) {
        return 0.0;
    }

    sum = 0.0;
    
    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    return sum / size;
}

double median(const double* data, size_t size)
{
    size_t i;
    size_t middle;
    double* pa_sorted_data;
    double result;

    if (data == NULL || size == 0) {
        return 0.0;
    }

    pa_sorted_data = (double*)malloc(size * sizeof(double));
    if (pa_sorted_data == NULL) {
        return 0.0;
    }

    for (i = 0; i < size; i++) {
        pa_sorted_data[i] = data[i];
    }

    for (i = 0; i < size - 1; i++) {
        size_t j;
        for (j = 0; j < size - i - 1; j++) {
            if (pa_sorted_data[j] > pa_sorted_data[j + 1]) {
                double temp = pa_sorted_data[j];
                pa_sorted_data[j] = pa_sorted_data[j + 1];
                pa_sorted_data[j + 1] = temp;
            }
        }
    }

    middle = size / 2;

    if (size % 2 == 0) {
        result = (pa_sorted_data[middle - 1] + pa_sorted_data[middle]) / 2.0;
    } else {
        result = pa_sorted_data[middle];
    }

    free(pa_sorted_data);
    pa_sorted_data = NULL;

    return result;
}

double variance(const double* data, size_t size)
{
    size_t i;
    double data_mean;
    double sum_of_squares;

    if (data == NULL || size == 0) {
        return 0.0;
    }

    data_mean = mean(data, size);
    sum_of_squares = 0.0;

    for (i = 0; i < size; i++) {
        double difference = data[i] - data_mean;
        sum_of_squares += difference * difference;
    }

    return sum_of_squares / size;
}

double standard_deviation(const double* data, size_t size)
{
    double data_variance;

    if (data == NULL || size == 0) {
        return 0.0;
    }

    data_variance = variance(data, size);

    return sqrt(data_variance);
}

double range(const double* data, size_t size)
{
    double min_value;
    double max_value;
    size_t i;

    if (data == NULL || size == 0) {
        return -1.0;
    }

    min_value = data[0];
    max_value = data[0];

    for (i = 1; i < size; i++) {
        if (data[i] < min_value) {
            min_value = data[i];
        }
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    return max_value - min_value;
}

double mode(const double* data, size_t size)
{
    double* pa_sorted_data;
    double most_frequent_value;
    double current_value;
    size_t current_count;
    size_t max_count;
    size_t i;

    if (data == NULL || size == 0) {
        return -1.0;
    }

    pa_sorted_data = (double*)malloc(size * sizeof(double));
    if (pa_sorted_data == NULL) {
        return -1.0;
    }

    for (i = 0; i < size; i++) {
        pa_sorted_data[i] = data[i];
    }

    for (i = 0; i < size - 1; i++) {
        size_t j;
        for (j = i + 1; j < size; j++) {
            if (pa_sorted_data[i] > pa_sorted_data[j]) {
                double temp = pa_sorted_data[i];
                pa_sorted_data[i] = pa_sorted_data[j];
                pa_sorted_data[j] = temp;
            }
        }
    }

    most_frequent_value = pa_sorted_data[0];
    current_value = pa_sorted_data[0];
    current_count = 1;
    max_count = 1;

    for (i = 1; i < size; i++) {
        if (pa_sorted_data[i] == current_value) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                most_frequent_value = current_value;
            }
            current_value = pa_sorted_data[i];
            current_count = 1;
        }
    }

    if (current_count > max_count) {
        most_frequent_value = current_value;
    }

    free(pa_sorted_data);
    pa_sorted_data = NULL;

    return most_frequent_value;
}

double percentile(const double* data, size_t size, double p)
{
    double* pa_sorted_data;
    double index;
    double fractional_part;
    size_t lower_index;
    size_t upper_index;
    double result;
    size_t i;

    if (data == NULL || size == 0 || p < 0.0 || p > 100.0) {
        return -1.0;
    }

    pa_sorted_data = (double*)malloc(size * sizeof(double));
    if (pa_sorted_data == NULL) {
        return -1.0;
    }

    for (i = 0; i < size; i++) {
        pa_sorted_data[i] = data[i];
    }

    for (i = 0; i < size - 1; i++) {
        size_t j;
        for (j = i + 1; j < size; j++) {
            if (pa_sorted_data[i] > pa_sorted_data[j]) {
                double temp = pa_sorted_data[i];
                pa_sorted_data[i] = pa_sorted_data[j];
                pa_sorted_data[j] = temp;
            }
        }
    }

    index = (p / 100.0) * (size - 1);
    lower_index = (size_t)index;
    upper_index = lower_index + 1;
    fractional_part = index - lower_index;

    if (upper_index >= size) {
        result = pa_sorted_data[lower_index];
    } else {
        result = pa_sorted_data[lower_index] + fractional_part * (pa_sorted_data[upper_index] - pa_sorted_data[lower_index]);
    }

    free(pa_sorted_data);
    pa_sorted_data = NULL;

    return result;
}

double* normalize_malloc(const double* data, size_t size)
{
    double* pa_normalized_data;
    double min_value;
    double max_value;
    double range;
    size_t i;

    if (data == NULL || size == 0) {
        return NULL;
    }

    pa_normalized_data = (double*)malloc(size * sizeof(double));
    if (pa_normalized_data == NULL) {
        return NULL;
    }

    min_value = data[0];
    max_value = data[0];

    for (i = 1; i < size; i++) {
        if (data[i] < min_value) {
            min_value = data[i];
        }
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    range = max_value - min_value;

    if (range == 0.0) {
        for (i = 0; i < size; i++) {
            pa_normalized_data[i] = 0.0;
        }
    } else {
        for (i = 0; i < size; i++) {
            pa_normalized_data[i] = (data[i] - min_value) / range;
        }
    }

    return pa_normalized_data;
}

double z_score(double value, double mean, double std_dev)
{
    if (std_dev == 0.0) {
        return 0.0;
    }

    return (value - mean) / std_dev;
}
