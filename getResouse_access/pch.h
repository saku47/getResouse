#ifndef PCH_H
#define PCH_H

//プリコンパイルするヘッダーを追加
#include "Section.h"
#include <fstream>  //ファイル操作
#include <list>  //リストのため
#include <sstream> 
#include <string>


using namespace std;

//関数の宣言
Section StringSplit_class(const std::string &str, char sep);
bool comp(Section &v1, Section &v2);


#endif //PCH_H