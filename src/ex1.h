
#ifndef PROJ1_EX1_H
#define PROJ1_EX1_H
#import "../data_structures//Graph.h"

void edmondsKarp(Graph *g, Vertex* source, Vertex* target);
void testAndVisit(std::queue<Vertex*> &q, Edge *e, Vertex *w, double residual);
bool findAugmentingPath(Graph *g, Vertex *s, Vertex *t);
void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);
double findMinResidualAlongPath(Vertex *s, Vertex *t);



#endif //PROJ1_EX1_H
