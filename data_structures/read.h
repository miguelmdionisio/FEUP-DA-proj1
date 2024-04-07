/**
 * @file read.h
 * @brief Contains functions for parsing input files and  populating a graph
 */
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief used solely for parsing files
*/
class read {
        public:
        /**
         * @brief Parses small data set
         * @return small Graph
         */
        static Graph populate();
        /**
         * @brief Parses larger data set
         * @return
         */
        static Graph populate_large();
    };
