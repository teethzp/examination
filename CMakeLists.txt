cmake_minimum_required(VERSION 3.10)
project(mybishi)

set(CMAKE_CXX_STANDARD 11)

add_executable(mybishi main.cpp mergesort/MergeSort.cpp mergesort/MergeSort.h mergesort/MergeSortTest.h subset/SubsetIntergers.cpp subset/SubsetIntergers.h subset/SubsetTest.h FirstPositionOfTarget/FirstPositionOfTarget.cpp FirstPositionOfTarget/FirstPositionOfTarget.h FirstPositionOfTarget/FirstPositionOfTargetTest.h RotatedSortedArray/RotatedSortedArray.cpp RotatedSortedArray/RotatedSortedArray.h BinaryTree/BinaryTree.cpp BinaryTree/BinaryTree.h BreadthFirstSearch/BreadthFirst.cpp BreadthFirstSearch/BreadthFirst.h TopologicalSorting/TopologicalSorting.h NumberOfIslands/NumberOfIslands.h ZombieInMatrix/ZombieMatrix.h CombinationSum/CombinationSum.h Permmutations/Permutations.h Permmutations/Permutations2.h NQueens/NQueens.h)