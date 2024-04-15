# KdTreeSpaceCraft
 C++ application demonstrating Kd tree search algorithm

## Usage
From the repository root directory:  
To compile space craft application:
```g++ main.cpp src/*.cpp -o bin/SpaceCraft```  
  
To run space craft application:  
```./bin/SpaceCraft```  

To compile and run tests:  
```g++ test.cpp src/*.cpp -o bin/SpaceCraft_test```  
```./bin/SpaceCraft_test```  

## Algorithm
The search algorithm used in this App is a 3-dimensional k-d tree. With this algorithm planets are categorized as nodes in a custom binary tree. This tree can be traversed to find the closest planet given a target x,y,z coordinate with an average O(logn) runtime.
[k-d tree wikipedia](https://en.wikipedia.org/wiki/K-d_tree)
