#ifndef STAT_UTIL_H
#define STAT_UTIL_H

#include <stddef.h>

/* Probability Functions */

/* 
   Calculate the number of combinations (n choose k).
   Parameters:
     - n: Total number of items. Must be non-negative.
     - k: Number of items to select. Must be non-negative and less than or equal to n.

   Behavior:
     - Returns 1 if both n and k are 0 (by definition).
     - If n < 0, k < 0, or k > n, the function returns 0.

   Returns:
     - The number of ways to choose k items from n items without considering the order.
     - Returns 0 for invalid input.
*/
double combinations(int n, int k);

/* 
   Calculate the number of permutations (nPk).
   Parameters:
     - n: Total number of items. Must be non-negative.
     - k: Number of items to select. Must be non-negative and less than or equal to n.

   Behavior:
     - Returns 1 if both n and k are 0 (by definition).
     - If n < 0, k < 0, or k > n, the function returns 0.

   Returns:
     - The number of ways to arrange k items from n items, considering the order.
     - Returns 0 for invalid input.
*/
double permutations(int n, int k);

/* 
   Calculate the probability of exactly `success` successes in a binomial distribution.
   Parameters:
     - trials: The number of independent trials. Must be non-negative.
     - success: The number of desired successes. Must be non-negative and less than or equal to trials.
     - p: The probability of success for a single trial. Must be between 0 and 1 (inclusive).

   Behavior:
     - If any input is invalid, the function returns 0.

   Returns:
     - The binomial probability for the given parameters.
     - 0 for invalid input.
*/
double binomial_probability(int trials, int success, double p);

/* Basic Statistics */

/*
    Calculate the mean (average) of an array of numbers.
    Parameters:
        - data: Pointer to the array of numbers. Must not be NULL.
        - size: The number of elements in the array. Must be greater than 0.
    Returns:
        - The mean of the numbers.
        - 0.0 if the input is invalid.
*/
double mean(const double* data, size_t size);

/*
    Calculate the median of an array of numbers.
    Parameters:
        - data: Pointer to the array of numbers. Must not be NULL.
        - size: The number of elements in the array. Must be greater than 0.
    Returns:
        - The median of the numbers.
        - 0.0 if the input is invalid.
    Behavior:
        - A sorted copy of the input dataset is used internally for calculation.
*/
double median(const double* data, size_t size);

/*
    Calculate the variance of an array of numbers.
    Parameters:
        - data: Pointer to the array of numbers. Must not be NULL.
        - size: The number of elements in the array. Must be greater than 0.
    Returns:
        - The variance of the numbers.
        - 0.0 if the input is invalid.
*/
double variance(const double* data, size_t size);

/*
    Calculate the standard deviation of an array of numbers.
    Parameters:
        - data: Pointer to the array of numbers. Must not be NULL.
        - size: The number of elements in the array. Must be greater than 0.
    Returns:
        - The standard deviation of the numbers.
        - 0.0 if the input is invalid.
*/
double standard_deviation(const double* data, size_t size);

/* Calculate the range of a dataset.
   Parameters:
     - data: Pointer to an array of doubles. If NULL, the function returns -1.0.
     - size: The number of elements in the array. If 0, the function returns -1.0.

   Behavior:
     - Calculates the range (maximum value - minimum value) of the given dataset.

   Returns:
     - The range of the dataset as a double (always non-negative).
     - -1.0 if the input array is NULL or empty.
*/
double range(const double* data, size_t size);

/* Advanced Statistics */

/* Calculate the mode of a dataset.
   Parameters:
     - data: Pointer to an array of doubles. If NULL, the function returns -1.0.
     - size: The number of elements in the array. If 0, the function returns -1.0.

   Behavior:
     - Identifies the mode (most frequently occurring value) in the dataset.
     - In case of ties (multiple values with the same frequency), the smallest value is returned.
     - A sorted copy of the input dataset is used internally for calculation.

   Returns:
     - The mode of the dataset as a double.
     - -1.0 if the input array is NULL, empty, or if a memory allocation failure occurs.
*/
double mode(const double* data, size_t size);

/* Calculate the pth percentile of a dataset.
   Parameters:
     - data: Pointer to the dataset (array of doubles). Must not be NULL.
     - size: The size of the dataset. Must be greater than 0.
     - p: The desired percentile (0.0 to 100.0).

   Returns:
     - The value at the specified percentile in the dataset.
     - Returns -1.0 if:
       - The input dataset is NULL.
       - The size is 0.
       - The percentile p is out of range (not between 0.0 and 100.0).
       - Memory allocation fails.

   Behavior:
     - The input dataset remains unmodified.
     - A sorted copy of the dataset is used internally to determine the percentile value.
*/
double percentile(const double* data, size_t size, double p);

/* Data Transformation */

/* Normalize a dataset to a range of 0 to 1 (returns dynamically allocated memory).
   Parameters:
     - data: Pointer to the array of data to normalize. Must not be NULL.
     - size: Number of elements in the array. Must be greater than 0.

   Returns:
     - Pointer to a newly allocated array containing the normalized values.
     - NULL if the input data is NULL, size is 0, or memory allocation fails.

   Behavior:
     - Each value in the returned array is normalized using the formula:
       normalized_value = (value - min_value) / (max_value - min_value).
     - If all values in the input array are equal, all normalized values will be 0.

    Note:
     - The caller is responsible for freeing the returned array.
*/
double* normalize_malloc(const double* data, size_t size);

/* Calculate the z-score of a given value.
   Parameters:
     - value: The value for which to calculate the z-score.
     - mean: The mean of the dataset.
     - std_dev: The standard deviation of the dataset. Must not be 0.

   Returns:
     - The z-score of the value.
     - If the standard deviation is 0, the function returns 0.

   Behavior:
     - The z-score is calculated using the formula:
       z_score = (value - mean) / std_dev.
*/
double z_score(double value, double mean, double std_dev);

#endif /* STAT_UTIL_H */
