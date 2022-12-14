#pragma once
#include <GL/glut.h>

/**
* このプログラムに関して
* このプログラムは以下のサイトから利用させていただきました。
* https://www.natural-science.or.jp/article/20110313211402.php
* カラーサンプルをまとめてくださった著者に感謝を申し上げます。
*/

struct MaterialStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
};


//////////////////////////////////////////
//ruby(ルビー)
MaterialStruct ms_ruby = {
 {0.1745,   0.01175,  0.01175,   1.0},
 {0.61424,  0.04136,  0.04136,   1.0},
 {0.727811, 0.626959, 0.626959,  1.0},
 76.8 };
//emerald(エメラルド)
MaterialStruct ms_emerald = {
  {0.0215,  0.1745,   0.0215,  1.0},
  {0.07568, 0.61424,  0.07568, 1.0},
  {0.633,   0.727811, 0.633,   1.0},
  76.8 };
//jade(翡翠)
MaterialStruct ms_jade = {
  {0.135,     0.2225,   0.1575,   1.0},
  {0.54,      0.89,     0.63,     1.0},
  {0.316228,  0.316228, 0.316228, 1.0},
  12.8 };
//obsidian(黒曜石)
MaterialStruct ms_obsidian = {
  {0.05375, 0.05,    0.06625, 1.0},
  {0.18275, 0.17,    0.22525, 1.0},
  {0.332741,0.328634,0.346435,1.0},
  38.4 };
// pearl(真珠)
MaterialStruct ms_pearl = {
  {0.25,     0.20725,  0.20725,  1.0},
  {1,        0.829,    0.829,    1.0},
  {0.296648, 0.296648, 0.296648, 1.0},
  10.24 };
//turquoise(トルコ石)
MaterialStruct ms_turquoise = {
  {0.1,     0.18725, 0.1745,  1.0},
  {0.396,   0.74151, 0.69102, 1.0},
  {0.297254,0.30829, 0.306678,1.0},
  12.8 };
//brass(真鍮)
MaterialStruct ms_brass = {
  {0.329412,  0.223529, 0.027451, 1.0},
  {0.780392,  0.568627, 0.113725, 1.0},
  {0.992157,  0.941176, 0.807843, 1.0},
  27.89743616 };
//bronze(青銅)
MaterialStruct ms_bronze = {
  {0.2125,   0.1275,   0.054,   1.0},
  {0.714,    0.4284,   0.18144, 1.0},
  {0.393548, 0.271906, 0.166721,1.0},
  25.6 };
//chrome(クローム)
MaterialStruct ms_chrome = {
  {0.25,    0.25,     0.25,     1.0},
  {0.4,     0.4,      0.4,      1.0},
  {0.774597,0.774597, 0.774597, 1.0},
  76.8 };
//copper(銅)
MaterialStruct ms_copper = {
  {0.19125,  0.0735,   0.0225,  1.0},
  {0.7038,   0.27048,  0.0828,  1.0},
  {0.256777, 0.137622, 0.086014,1.0},
  12.8 };
//gold(金)
MaterialStruct ms_gold = {
  {0.24725,  0.1995,   0.0745,    1.0},
  {0.75164,  0.60648,  0.22648,   1.0},
  {0.628281, 0.555802, 0.366065,  1.0},
  51.2 };
//silver(銀)
MaterialStruct ms_silver = {
  {0.19225,  0.19225,  0.19225, 1.0},
  {0.50754,  0.50754,  0.50754, 1.0},
  {0.508273, 0.508273, 0.508273,1.0},
  51.2 };
//プラスチック(黒)
MaterialStruct ms_black_plastic = {
  {0.0,    0.0,    0.0,  1.0},
  {0.01,   0.01,   0.01, 1.0},
  {0.50,   0.50,   0.50, 1.0},
  32 };
//プラスチック(シアン)
MaterialStruct ms_cyan_plastic = {
  {0.0,   0.1,    0.06,    1.0},
  {0.0,       0.50980392,0.50980392,1.0},
  {0.50196078,0.50196078,0.50196078,1.0},
  32 };
//プラスチック(緑)
MaterialStruct ms_green_plastic = {
  {0.0,     0.0,   0.0,  1.0},
  {0.1,     0.35,  0.1,  1.0},
  {0.45,    0.55,  0.45, 1.0},
  32 };
//プラスチック(赤)
MaterialStruct ms_red_plastic = {
  {0.0,     0.0,     0.0,  1.0},
  {0.5,     0.0,     0.0,  1.0},
  {0.7,     0.6,     0.6,  1.0},
  32 };
//プラスチック(白)
MaterialStruct ms_white_plastic = {
  {0.0,   0.0,     0.0,  1.0},
  {0.55,  0.55,    0.55, 1.0},
  {0.70,  0.70,    0.70, 1.0},
  32 };
//プラスチック(黄)
MaterialStruct ms_yellow_plastic = {
  {0.0,  0.0,     0.0,  1.0},
  {0.5,  0.5,     0.0,  1.0},
  {0.60, 0.60,    0.50, 1.0},
  32 };
//ゴム(黒)
MaterialStruct ms_black_rubber = {
  {0.02,   0.02,    0.02, 1.0},
  {0.01,   0.01,    0.01, 1.0},
  {0.4,    0.4,     0.4,  1.0},
  10.0 };
//ゴム(シアン)
MaterialStruct ms_cyan_rubber = {
  {0.0,     0.05,    0.05, 1.0},
  {0.4,     0.5,     0.5,  1.0},
  {0.04,    0.7,     0.7,  1.0},
  10.0 };
//ゴム(緑)
MaterialStruct ms_green_rubber = {
  {0.0,    0.05,    0.0,  1.0},
  {0.4,    0.5,     0.4,  1.0},
  {0.04,   0.7,     0.04, 1.0},
  10.0 };
//ゴム(赤)
MaterialStruct ms_red_rubber = {
  {0.05,     0.0,     0.0,  1.0},
  {0.5,      0.4,     0.4,  1.0},
  {0.7,      0.04,    0.04, 1.0},
  10.0 };
//ゴム(白)
MaterialStruct ms_white_rubber = {
  {0.05,   0.05,    0.05, 1.0},
  {0.5,    0.5,     0.5,  1.0},
  {0.7,    0.7,     0.7,  1.0},
  10.0 };
//ゴム(黄)
MaterialStruct ms_yellow_rubber = {
  {0.05,  0.05,    0.0,  1.0},
  {0.5,   0.5,     0.4,  1.0},
  {0.7,   0.7,     0.04, 1.0},
  10.0 };

MaterialStruct materials[] = {ms_ruby, ms_emerald, ms_jade, ms_obsidian, ms_pearl,
ms_turquoise, ms_brass,ms_bronze,ms_chrome,ms_copper,ms_gold,ms_silver,ms_black_plastic,
ms_red_plastic,ms_white_plastic,ms_yellow_plastic,ms_black_rubber,ms_yellow_rubber,ms_red_rubber,ms_white_rubber,ms_cyan_rubber};
int materialNum = 21;