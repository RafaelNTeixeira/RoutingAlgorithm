cmake_minimum_required(VERSION 3.23)
project(DA_trabalho_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(DA_trabalho_2
        main.cpp
        data_structures/Graph.cpp
        data_structures/Graph.h
        data_structures/Heap.cpp
        data_structures/Heap.h
        data_structures/UFDS.cpp
        data_structures/UFDS.cpp
        data_structures/VertexEdge.cpp
        data_structures/VertexEdge.h
        FileManager.cpp
        FileManager.h
        Menu.cpp
        Menu.h
        Algorithms.cpp
        Algorithms.h
        )
