cmake_minimum_required(VERSION 3.0)
project(GPUSimulation VERSION 0.1.0 LANGUAGES C CXX)

# Spécifier les fichiers source
set(SOURCES
    src/gpu/function.cpp
    src/gpu/kernel.cu
    src/gpu/main.cpp
)

# Spécifier les fichiers d'en-tête
set(HEADERS
    src/gpu/kernel.cuh
    src/gpu/main.hpp
)

# Spécifier le répertoire de sortie pour l'exécutable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/StageXLIM/exe)

# Ajouter les options de compilation pour CUDA
find_package(CUDA REQUIRED)
set(CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS};-arch=sm_30)

# Compiler les fichiers source avec g++
add_executable(gpuSimulation ${SOURCES} ${HEADERS})

# Lier les librairies CUDA
target_link_libraries(gpuSimulation ${CUDA_LIBRARIES})