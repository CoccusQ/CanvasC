#include "font.h"

const char fontTable[26][FONT_LENGTH + 1] = {
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111100000000000011110000000000011111100000000001101110000000000110011000000000111001110000000011000111000000001100001100000001110000111000000110000011100000111000000111000011111111111100001111111111110001110000000011100111000000001110011000000000011011100000000001110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*A*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111111000000111111111110000011100000111000001110000001110000111000000111000011100000011000001110000011100000111111111100000011111111110000001110000011110000111000000111000011100000001100001110000000110000111000000111000011100000111100001111111111100000111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*B*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111110000001111111111000001111000000000001110000000000000111000000000000011000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000011000000000000001110000000000000111100000000000001111000000100000011111111110000000011111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*C*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111110000000111111111100000011100000111000001110000001110000111000000011000011100000001110001110000000111000111000000011100011100000001110001110000000111000111000000011100011100000001100001110000001110000111000000111000011100001111000001111111111000000111111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*D*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111110000011111111111000001110000000000000111000000000000011100000000000001110000000000000111000000000000011111111110000001111111111000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111111111110000011111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*E*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111110000011111111111000001110000000000000111000000000000011100000000000001110000000000000111000000000000011111111110000001111111111000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*F*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111110000001111111111000001110000000000001110000000000000110000000000000111000000000000011100000000000001110000111111000111000011111100011100000000110001110000000011000111000000001100001100000000110000111000000011000001110000001100000011111111110000000111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*G*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110000001110000111000000111000011100000011100001110000001110000111000000111000011100000011100001110000001110000111111111111000011111111111100001110000001110000111000000111000011100000011100001110000001110000111000000111000011100000011100001110000001110000111000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*H*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111111111000111111111111100000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000001111111111111000111111111111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*I*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111111100000011111111110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000010000001110000001100001111000000111111111000000001111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*J*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110000001110000111000001110000011100001110000001110001110000000111000110000000011100110000000001110110000000000111111000000000011111100000000001110110000000000111011100000000011100111000000001110001110000000111000011100000011100000111000001110000011110000111000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*K*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111111111110000011111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*L*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011100000000111001111000000111100111100000011110011111000011111001101100001101100110110000110110011001100110011001100110011001100110011001100110011000111100011001100011110001100110000110000110011000011000011001100000000001100110000000000110011000000000011001100000000001100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*M*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001110000000110000111100000011000011110000001100001111100000110000110110000011000011011100001100001100110000110000110011100011000011000110001100001100011100110000110000110011000011000011101100001100000110110000110000011111000011000000111100001100000011110000110000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*N*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111000000011111111110000011110000111100001110000001110001110000000011100111000000001110011100000000111001100000000001100110000000000110011000000000011001110000000011100111000000001110011100000000111000111000000111000011110000111100000111111111100000001111111100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*O*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111110000000111111111110000011100000111100001110000001110000111000000011000011100000001100001110000000110000111000000111000011100001111000001111111111000000111111110000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*P*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111000000011111111110000011100000011100001110000001110001110000000011100111000000001110011100000000111001100000000001100110000000000110011000000000011001110000000011100111000000001110011100000000110000111000000111000011110000111000000111111111100000001111111000000000000110000000000000011000000000000001111000100000000011111110000000000011110000000000000000000000000000000000",/*Q*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111110000000111111111110000011100000111000001110000001100000111000000110000011100000011000001110000011100000111111111100000011111111000000001110011110000000111000011000000011100001110000001110000011100000111000001110000011100000011100001110000001110000111000000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*R*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011111111100000011111111110000011100000000000001110000000000000110000000000000011100000000000000111100000000000001111100000000000011111110000000000001111100000000000001111000000000000011100000000000001110000000000000111000000000000111100001111111111100000111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*S*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111111111000111111111111100000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000111000000000000011100000000000001110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*T*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011100000000111001110000000011100111000000001110011100000000111001110000000011100111000000001110011100000000111001110000000011100111000000001110011100000000111001110000000011100111000000001110011100000000111000111000000111000011111111111100000111111111100000000111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*U*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111000000000011101100000000001100111000000001110001100000000110000110000000011000011100000011100000110000001100000011000000110000001110000111000000011000011000000001100001100000000111001110000000001100110000000000110011000000000011111100000000000111100000000000011110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*V*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011000000000011001100000000001100110000000000110011000000000011001100000000001100110000000000110011000011000011001100011110001100111001111001110011100111100111001110110011011100011011001101100001101100110110000111100001111000011110000111100001111000011110000111000000111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*W*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011100000000111000111000000111000001110000111000000111000011100000001110011100000000011001100000000001111110000000000011110000000000001111000000000000111100000000000111111000000000111001110000000011000011000000011100001110000011100000011100011110000001111001110000000011100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*X*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111000000000011101110000000011100011100000011100001110000001110000011100001110000001110000111000000011100111000000000110011000000000011111100000000000111100000000000001100000000000000110000000000000011000000000000001100000000000000110000000000000011000000000000001100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",/*Y*/
    "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001111111111110000111111111111000000000000011100000000000011100000000000011100000000000001100000000000001110000000000001110000000000000111000000000000111000000000000111000000000000111000000000000011000000000000011100000000000011100000000000001111111111110000111111111111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"/*Z*/
};