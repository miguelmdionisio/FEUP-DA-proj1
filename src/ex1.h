/**
 * @file ex1.h
 * @brief Functions regarding exercises 2.X
*/
#ifndef PROJ1_EX1_H
#define PROJ1_EX1_H
#include <queue>
#import "../data_structures//Graph.h"

/**
 * @brief Print flow for all cities | Complexity: O(n), n = n cities
 * @param g Pointer to the graph
 */
void showFlowAll(Graph* g);

/**
 * @brief Print flow to given city | Complexity: O(n), n = num vertexs
 * @param g, string
 */
void showFlowCity(Graph* g, string city);

/**
 * @brief print deficits | Complexity: O(n), n = n cities
 * @param g
 */
void showDeficits(Graph* g);

/**
 * @brief Edmonds Karp algorithm. We used the algorithm discussed in class, but since we have multiple sources and multiple sinks, we added a super Source/Sink, connected to respective nodes.
 * Complexity: O(n^2), n = num nodes
 * @param g
 * @param source
 * @param target
 */
void edmondsKarp(Graph *g, Vertex *source, Vertex *target);

/**
 * @brief creates supersource, supersink and calls the Edmond Karp algorithm to calculate max flow to all nodes.
 * Complexity: ssame as Edmond Karp
 * @param g
 */
void calculateMaxFlowToCities(Graph* g);

/**
 * @brief auxiliary function
 * @param q
 * @param e
 * @param w
 * @param residual
 */
void testAndVisit(queue<Vertex*> &q, Edge *e, Vertex *w, double residual);

/**
 * @brief finds augmenting path using a bfs
 * @param g
 * @param s
 * @param t
 * @return
 */
bool findAugmentingPath(Graph *g, Vertex *s, Vertex *t);

/**
 * @brief augments flow along path
 * @param s
 * @param t
 * @param f
 */
void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);

/**
 * @brief searches the path for the minimal residual flow
 * @param s
 * @param t
 * @return
 */
double findMinResidualAlongPath(Vertex *s, Vertex *t);


#endif //PROJ1_EX1_H
