 # 📦 MyContainer Library - C++ Templated Container with Custom Iterators

This project implements a generic, header-only C++ container `MyContainer<T>`, which supports multiple types of traversal patterns via custom iterators.  


## Project Structure

- `MyContainer.hpp` – Templated container class
- `test.cpp` – Unit tests
- `main.cpp` – Example usage with int, string, double
- `doctest.h` – Test framework
- `makefile` – Build instructions
- `README.md` – This documentation



##  Features

- ✅ **Generic design** with `template<typename T>` – supports any type (int, string, double, etc.).
- ✅ **Header-only implementation** – just include `MyContainer.hpp`, no linking needed.
- ✅ **Safe operations** – invalid removals throw exceptions.
- ✅ **Fully printable** – supports `operator<<` for printing contents.
- ✅ **Custom iterators** – six traversal strategies are implemented:

##  Iterators

| Iterator Type           | Description                                                                 |
|-------------------------|-----------------------------------------------------------------------------|
| `AscendingIterator`     | Iterates over elements in **sorted ascending** order                        |
| `DescendingIterator`    | Iterates over elements in **sorted descending** order                       |
| `SideCrossIterator`     | Alternates: smallest → largest → 2nd smallest → 2nd largest → ...           |
| `ReverseOrderIterator`  | Iterates over elements in **reverse of insertion** order                    |
| `OrderIterator`         | Iterates over elements in the **original insertion** order                  |
| `MiddleOutOrderIterator`| Starts from the middle and moves outward: middle → left → right → ...      |




## Usage Examples

In the file **main.cpp** you can find demonstration of usage with int, string, and double.

## Testing

We use [`doctest`](https://github.com/doctest/doctest) for unit testing.  
The test suite in `test.cpp` provides coverage for:
- Element insertion and removal  
- Iterators (ascending, descending, reverse, etc.)  
- Edge cases (empty containers, duplicates, exception handling)  
- Type versatility (`int`, `double`, `std::string`)





This project includes input validation,exception handling,and extensive unit tests.

## Installation and Usage

**Compilation:**To compile, using the provided Makefile:
```bash 
make
```
**Running the Main Program:** To execute demos and examples:
``` bash
make Main
```
**Running Tests:** To run tests, using **doctest**:
```bash
make test
```
**Memory Check(Valgrind):** To check for memory leaks:
```bash
make valgrind
```
**Cleaning Files:** To remove compile files:
```bash
make clean
```


## 👨‍💻 Author

**Roy Meoded**  
B.Sc. Computer Science student at Ariel University roymeoded2512@gmail.com 
