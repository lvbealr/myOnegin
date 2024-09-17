<p align="center">
  <a href="https://artnow.ru/kartina-Evgeniy-Onegin-Portret-hudozhnik-Shipitsova-Elena-998492.html" rel="noopener">
 <img width=400 height=500 src="https://i.imgur.com/cfONpXQ.png" alt="Project logo"></a>
</p>

<h1 align="center">myONEGIN 💫</h1>

<h2 align="center">📖 ENCYCLOPEDIA OF RUSSIAN LIFE IN C 📖</h2>

## 📝 Table of Contents
- [About](#about)
- [Getting Started](#getting_started)
- [Documentation](#documentation)
- [Modes](#modes)
- [Example Usage](#usage)
- [Built Using](#built_using)
- [TODO List](#todo)
- [Authors](#authors)
- [Acknowledgments](#acknowledgement)

## 🧐 About <a name = "about"></a>

V. G. Belinsky called the poem "Eugene Onegin" by A. S. Pushkin "an encyclopedia of Russian life." But in an encyclopedia everything should be in alphabetical order... Let's fix this problem!

**COMPARE ORDERED AND UNORDERED TEXT! WHICH'S BETTER?**

<p align="center">
  <img src = "https://i.imgur.com/955BJji.png" width=400 height=350>
  <img src = "https://i.imgur.com/d18eCLQ.png" width=400 height=350>
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

First of all, clone submodule <b>CustomWarning</b>.

```bash
git clone git@github.com:lvbealr/customWarning.git
```

You can use <b>MAKE</b> to build the program and run it.

Enter the following command in the terminal:

```bash
make
```

Once compiled you can run the executable with the following command.

```bash
./ONEGIN
```

The program will start in manual mode and ask you to enter data for correct operation.

## 🗎 Documentation <a name = "documentation"></a>

For convenient use of the program, [Doxygen documentation](https://lvbealr.github.io/) is included with the project.

## 🔧 MODES <a name = "modes"></a>

THIS ARTICLE IS BEING EDITED...

## 🎈 Example Usage <a name="usage"></a>

### DEFAULT MODE
```bash
./ONEGIN

# /texts/oneginOutEng.txt >>
#
# A bad turn has come!
# A barely born day.
# A barely noticeable stream
# A bearded postilion is sitting,
# ...
# Neither Scott, nor Byron, nor Seneca,
# Under the sky of my Africa,
# The incessant whisper of Nereida,
# How often is it on the shores of Taurida
# ...
# Not thinking to amuse the proud light,
# The attention of the friendship of the beloved,
# I'd like to introduce you
# The pledge is worthier than you,
# ...
```
## ⛏️ Built Using <a name = "built_using"></a>
- [customWarning](https://github.com/lvbealr/customWarning) - Warning Module

## ⌛ TODO List <a name = "todo"></a>
- [x] Create Struct, That Contains Pointer To Line And Line Length
- [x] Remove Three Calloc's In TextStruct (Do Use TextLine Array)
- [x] TextLine Array Initializing, Rewrite NewLinePoint Function
- [x] Rewrite Sorting Function With Parameters Like In A QSORT()
- [x] Rewrite Two String Comparators (Forward & Backward)
- [x] Original Text Is In textData->text
- [x] Move CustomWarning Into Git Submodule
- [ ] Define MyFree (Optional)
- [ ] Hoare QSort() (Optional)
- [ ] Do Flags (-sort, -rsort, -orig, -all) (Optional)
- [ ] Flag -o To Enter Output File Name
- [ ] Struct To Describe Flags (Check getopt MAN)


## ✍️ Authors <a name = "authors"></a>

- [@lvbealr](https://github.com/lvbealr) - Idea & Initial work



## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- [@livlavr](https://github.com/livlavr) - Good Boy
- [@Iprime111](https://github.com/Iprime111) - Bad Boy 😈
