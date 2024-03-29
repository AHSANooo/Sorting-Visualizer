# Sorting Visualizer

Welcome to the Sorting Visualizer project! This project is built using SFML (Simple and Fast Multimedia Library) and provides a visual representation of various sorting algorithms like Quick Sort, Merge Sort, and Heap Sort.


## GitHub Repository

Explore the codebase and contribute to the project on GitHub: [Sorting Visualizer GitHub](https://github.com/AHSANooo/Sorting-Visualizer).

## Compilation and Running Instructions

### Requirements For Compiling (Only need to be run once):

1. Install GNU G++ Compiler:
   ```
   sudo apt-get install g++
   ```

2. Install SFML:
   ```
   sudo apt-get install libsfml-dev
   ```

### Compilation Commands (In Order):

1. Compile Sorting.cpp:
   ```
   g++ -c Sorting.cpp
   ```

2. Link object file and SFML libraries to create executable:
   ```
   g++ Sorting.o -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
   ```

### Running The Sorting Visualizer:

3. Execute the compiled executable:
   ```
   ./sfml-app
   ```

## About the Project

This Sorting Visualizer project aims to provide a hands-on learning experience of sorting algorithms by visualizing their operations. With colorful bars representing elements, users can observe how different sorting algorithms rearrange the elements to achieve a sorted array.

## Key Features

- Visual representation of sorting algorithms.
- Support for various sorting algorithms like Quick Sort, Merge Sort, and Heap Sort.
- Colorful bars representing array elements for better visualization.
- Integration with SFML for smooth graphical rendering.

## Contributions

Contributions are welcome! Feel free to open issues, suggest improvements, or add new features to the project. Let's make sorting algorithms more accessible and fun to learn!

## Demo Video

Watch the project in action:

[![Sorting Visualizer Demo](https://img.youtube.com/vi/rwT5jgM-HlQ/0.jpg)](https://youtu.be/rwT5jgM-HlQ)

