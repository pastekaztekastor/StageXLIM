/*******************************************************************************
* File Name: kernel.cuh
* Author: Mathurin Champemont
* Created Date: 2023-06-14
* Last Modified: 2023-06-14
* Description: 
*******************************************************************************/

#ifndef __KERNEL_CUH__
#define __KERNEL_CUH__

#include "main.hpp"


void model1_GPU(
    unsigned int ***    populationPosition,         // (*) Because change
    enum _Element ***   map,                        // (*) Because change
    unsigned int *      simPIn,                     // (*) Because change
    unsigned int **     cost,                       // useless
    unsigned int *      simExit, 
    unsigned int        simDimX, 
    unsigned int        simDimY, 
    unsigned int        simDimP, 
    unsigned int        settings_print );

__global__ void kernel_model1_GPU(
    unsigned int ***    dev_populationPosition,     // (*) Because change
    enum _Element ***   dev_map,                    // (*) Because change
    unsigned int *      dev_simPIn,                 // (*) Because change
    unsigned int **     dev_cost,                   // useless
    unsigned int *      dev_simExit, 
    unsigned int            simDimX, 
    unsigned int            simDimY
);

int cudaTest(unsigned int max);
__global__ void addArrays(int* a, int* b, int* c, int size);

#endif