#pragma once

/* Šî–{ƒf[ƒ^Œ^‚ÆŠî‘bŠÖ”ŒQ*/
#include "standard.h"

/* stringŒ^ */
#include <string>

/* vecotrŒ^ */
#include <vector>


/* ¤‚‹‰ŠÖ”ŒQ¤================================================================================= */

//splitŠÖ” ( •¶š—ñ Ë •¶š—ñ—p )
std::vector<std::string> split(std::string str, char c);

//splitŠÖ” ( •¶š—ñ Ë ”’l—p )
std::vector<unsigned int> nsplit(std::string str, char c);

//“_‚Æü•ª‚Ì‹——£‚ğ‹‚ß‚é
float dis(point1<float> point, point2<float> line);

//line‚ğŠî€‚Æ‚µ‚½move‚Ì¬•ª•ª‰ğ ( s:•½s¬•ª e:‚’¼¬•ª )
point2<float> getVector(point2<float> line, point2<float> move);

/* ¢‚‹‰ŠÖ”ŒQ¢================================================================================= */
