# stat_util

`stat_util` is a C89-compliant utility library providing a comprehensive suite of functions for statistical calculations and probability analysis. It includes robust tools for common operations such as computing combinations, permutations, statistical measures, and data transformations.

## Features

- **Probability Functions**: Compute combinations, permutations, and binomial probabilities.
- **Basic Statistics**: Calculate mean, median, variance, and standard deviation.
- **Advanced Statistics**: Determine the range, mode, and percentiles of datasets.
- **Data Transformation**: Normalize datasets to a [0, 1] range and compute z-scores.

For detailed descriptions and usage, see the header file: `stat_util.h`.

## Requirements

- **Compiler**: Clang 18.1.8
- **Target Platform**: `i686-pc-windows-msvc`
- **Compilation Flags**: `-std=c89 -Wall -pedantic-errors`

## Implementation Details

- **Memory Management**:  
  Functions with `_malloc` suffix dynamically allocate memory. The caller must free the allocated memory.

- **Input Validation**:  
  Invalid inputs such as `NULL` pointers, out-of-range parameters, or empty datasets are handled gracefully, returning appropriate default values (e.g., `0.0` or `-1.0`).

- **Standard Compliance**:  
  Fully compliant with the C89 standard for broad compatibility with legacy systems.

- **Function Behavior**:  
  - Original datasets remain unchanged.  
  - Robust handling of edge cases and memory allocation failures ensures stability.

### Thorough Testing
`stat_util` has been rigorously tested across various scenarios, including edge cases, to ensure reliability and correctness. The provided `main` function includes a comprehensive test suite demonstrating typical usage and handling of diverse input conditions.

## Compilation

To compile and use the `stat_util` library, follow these instructions based on your operating system:

### For Windows Users

- If you only need the `stat_util` library:
  ```
  clang -std=c89 -Wall -pedantic-errors -D_CRT_SECURE_NO_WARNINGS -o stat_util.lib stat_util.c
  ```

- To compile and run the provided test cases (included in `main.c`):
  ```
  clang -std=c89 -Wall -pedantic-errors -D_CRT_SECURE_NO_WARNINGS -o stat_util_test.exe stat_util.c main.c
  ```
  
  - Run the executable:
    ```
    ./stat_util_test.exe
    ```

**Important**: The `-D_CRT_SECURE_NO_WARNINGS` flag suppresses warnings related to secure function usage in MSVC environments. These warnings can be safely ignored for this library.

### For Unix-like Systems (Linux/macOS)

- If you only need the `stat_util` library:
  ```
  clang -std=c89 -Wall -pedantic-errors -o stat_util stat_util.c
  ```
- To compile and run the provided test cases (included in `main.c`):
  ```
  clang -std=c89 -Wall -pedantic-errors -o stat_util_test stat_util.c main.c
  ```

  - Run the executable:
    ```
    ./stat_util_test
    ```

## Contribution

We welcome contributions to improve `stat_util`. Here’s how you can contribute:

### Report Issues

If you encounter bugs or have feature suggestions, please open an issue with detailed information.

### Make Changes

1. **Fork the Repository**: Create your own copy of the repository.
2. **Create a Branch**: Use a descriptive branch name: `git checkout -b feature/your-feature`
3. **Make Changes**: Implement your changes, ensuring adherence to C89 standards and repository conventions.
4. **Commit and Push**:
    - Commit your changes with a meaningful message: `git commit -m "Describe your changes"`
    - Push your branch to your fork: `git push origin feature/your-feature`
5. **Submit a Pull Request**: Open a pull request with a detailed description of your changes.

Whether reporting an issue or proposing new features, your input helps us improve the library.

## Contact

If you have questions, suggestions, or discussions, please reach out by opening an issue or starting a discussion in the repository.  
Alternatively, you can email us at: [potterLim0808@gmail.com](mailto:potterLim0808@gmail.com)

Your feedback is always welcome!