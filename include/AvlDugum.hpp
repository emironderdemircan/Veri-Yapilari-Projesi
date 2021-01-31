/**
* @file AvlDugum.hpp
* @description Elemanların iş yerleri ile beraber eklendiği ağac düğüm sınıfı oluşturuluyor.
* @course 1-B
* @assignment 2.Ödev
* @date 19.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
#ifndef AVLDUGUM_HPP
#define AVLDUGUM_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class AvlDugum { //Elemanların olduğu ağaç düğümü.
public:
    int elemanSayisi;
    string isYeri;
    AvlDugum* sol;
    AvlDugum* sag;
    elemanlar* eleman;
    AvlDugum(const string&, const string& ,const int& );
    AvlDugum();
    ~AvlDugum();
};
#endif