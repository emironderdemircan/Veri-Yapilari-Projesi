/**
* @file calisanDugum.hpp
* @description Elemanların ağac düğüm sınıfı oluşturuluyor.
* @course 1-B
* @assignment 2.Ödev
* @date 17.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
#ifndef CALISANDUGUM_HPP
#define CALISANDUGUM_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class calisanDugum { //Çalışanlar düğüm sınıfı.
public:
    string adi;
    int calismayaBaslamaYili;
    calisanDugum* sag;
    calisanDugum* sol;
    calisanDugum();
    calisanDugum(const string& ad, const int& calismabasla);
};
#endif