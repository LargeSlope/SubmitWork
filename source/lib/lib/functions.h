#pragma once

/* ξ{f[^^ΖξbΦQ*/
#include "standard.h"

/* string^ */
#include <string>

/* vecotr^ */
#include <vector>


/* €ΦQ€================================================================================= */

//splitΦ ( Άρ Λ Άρp )
std::vector<std::string> split(std::string str, char c);

//splitΦ ( Άρ Λ lp )
std::vector<unsigned int> nsplit(std::string str, char c);

//_ΖόͺΜ£πίι
float dis(point1<float> point, point2<float> line);

//lineπξΖ΅½moveΜ¬ͺͺπ ( s:½s¬ͺ e:Ό¬ͺ )
point2<float> getVector(point2<float> line, point2<float> move);

/* ’ΦQ’================================================================================= */
