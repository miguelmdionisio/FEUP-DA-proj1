/**
 * @file ex3.h
 * @brief Functions regarding the exercises 3.X
*/
#ifndef PROJ1_EX3_H
#define PROJ1_EX3_H

#include "ex3.h"
#include "ex1.h"
#include <map>

/**
 * @brief removes a reservoir and runs the calculateMaxFlowToCities function with the updated graph.
 * Complexity: O(n^2)
 * @param graph
 * @param res
 */
void removeReservoir(Graph *graph, string res);
/**
 * @brief
 * @param graph
 */
void removePumpingStations(Graph *graph);
/**
 * @brief
 * @param graph
 */
void removePipelines(Graph *graph);
/**
 * @brief iterates through all pipelines and sets their capacity to 0 one at a time. It then runs the EK on the "updated" graph, checks what cities are lacking water, and prints it out.
 * @param g
 */
void simulatePipelineFailure(Graph* g);
/**
 * @brief our attempt at the heuristics exercise
 * @param originalGraph
 */
void balanceLoad(Graph* originalGraph);
#endif //PROJ1_EX3_H
