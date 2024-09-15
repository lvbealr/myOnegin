<p align="center">
  <a href="" rel="noopener">
 <img width=400 height=500 src="https://i.imgur.com/cfONpXQ.png" alt="Project logo"></a>
</p>

<h1 align="center">myONEGIN 💫</h1>

<h2 align="center">📖 ENCYCLOPEDIA OF RUSSIAN LIFE IN C 📖</h2>

## 📝 Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Documentation](#documentation)
- [Modes](#modes)
- [Example Usage](#example_usage)
- [Built Using](#built_using)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

V. G. Belinsky called the poem "Eugene Onegin" by A. S. Pushkin "an encyclopedia of Russian life." But in an encyclopedia everything should be in alphabetical order... Let's fix this problem!

**COMPARE ORDERED AND UNORDERED TEXT! WHICH'S BETTER?**

<p align="center">
  <img src = "https://i.imgur.com/aGemPWb.png" width=400>
  <img src = "https://i.imgur.com/d18eCLQ.png" width=400>
</p>

## 🏁 Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development.

### Clone Repository

What things you need to clone the repository to your own computer and .

```bash
git clone git@github.com:lvbealr/myOnegin.git
cd myOnegin/
```

### Build and Using

You can use <b>MAKE</b> to build the program and run it.

Enter the following command in the terminal:

```bash
make
```

Once compiled you can run the executable with the following command.

```bash
./main
```

The program will start in manual mode and ask you to enter data for correct operation.


## 🗎 Documentation <a name = "documentation"></a>

For convenient use of the program, [Doxygen documentation](https://lvbealr.github.io) is included with the project.

## 🔧 MODES <a name = "modes"></a>

The program provides several operating modes.

### SORTING MODE

In sorting mode, the program will ask you to enter the coefficients of the quadratic equation with the following message:

```bash
./main > Input values of coefficients a, b, c: ### your input
```

### REVERSE SORTING MODE

In test mode, the program will perform tests, the data for which is specified in a file called testData.h. For using this mode you should enter following command in console.

```bash
./main --test ### running tests
```

### ORIGINAL MODE

Google tests mode involves checking the program with test data from the testData.h file using Google C++ Testing Framework

```bash
./main --gtest ### running google tests
```

## 🎈 Example Usage <a name="usage"></a>

### MANUAL MODE

```bash
./main

Input values of coefficients a, b, c: 3 4 -5
D > 0
Solutions: -2.11963	0.7863	
```

### TEST MODE
```bash
./main --test

Test   1: [SUCCESS]

Test   2: [SUCCESS]

Test   3: [SUCCESS]

Test   4: [SUCCESS]

Test   5: [SUCCESS]

Test   6: [SUCCESS]

Test   7: [SUCCESS]

Test   8: [SUCCESS]

Test   9: [SUCCESS]

Test  10: [SUCCESS]
	
```

### GOOGLE TEST MODE
```bash
./main --gtest
[==========] Running 10 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 10 tests from QUADRATIC_EQUATION
[ RUN      ] QUADRATIC_EQUATION.ALL_NULLS_SUCCESS
[       OK ] QUADRATIC_EQUATION.ALL_NULLS_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.ALL_NULLS_EXCEPT_C_SUCCESS
[       OK ] QUADRATIC_EQUATION.ALL_NULLS_EXCEPT_C_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.A_IS_NULL_SUCCESS
[       OK ] QUADRATIC_EQUATION.A_IS_NULL_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.A_IS_NULL_SUCCESS_1
[       OK ] QUADRATIC_EQUATION.A_IS_NULL_SUCCESS_1 (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_LESS_NULL_SUCCESS
[       OK ] QUADRATIC_EQUATION.D_LESS_NULL_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_LESS_NULL_SUCCESS_1
[       OK ] QUADRATIC_EQUATION.D_LESS_NULL_SUCCESS_1 (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_EQUAL_NULL_SUCCESS
[       OK ] QUADRATIC_EQUATION.D_EQUAL_NULL_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_EQUAL_NULL_SUCCESS_1
[       OK ] QUADRATIC_EQUATION.D_EQUAL_NULL_SUCCESS_1 (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_GREATER_NULL_SUCCESS
[       OK ] QUADRATIC_EQUATION.D_GREATER_NULL_SUCCESS (0 ms)
[ RUN      ] QUADRATIC_EQUATION.D_GREATER_NULL_SUCCESS_1
[       OK ] QUADRATIC_EQUATION.D_GREATER_NULL_SUCCESS_1 (0 ms)
[----------] 10 tests from QUADRATIC_EQUATION (0 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 10 tests.

```


## ⛏️ Built Using <a name = "built_using"></a>

- [Google C++ Testing Framework](https://github.com/google/googletest) - Testing Framework

## ✍️ Authors <a name = "authors"></a>

- [@lvbealr](https://github.com/lvbealr) - Idea & Initial work
- [@overx4](https://vk.com/overx4) - Support & Motivate <3 (какие нах*й гугл тесты????!!№$$)



## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- [@livlavr](https://github.com/livlavr) - present bananas & did big nothing
