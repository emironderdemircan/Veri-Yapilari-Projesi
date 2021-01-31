/**
* @file calisanDugum.cpp
* @description Çalışanların kurucu ve parametreli kurucu fonksiyonları oluşturuluyor.
* @course 1-B
* @assignment 2.Ödev
* @date 21.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>
#include "calisanDugum.hpp"
#include "elemanlar.hpp"
#include "AvlDugum.hpp"
#include "AvlAgaci.hpp"
using namespace std;


    calisanDugum::calisanDugum() { //kurucu fonksiyon oluşturuluyor.
        sag = NULL;
        sol = NULL;
        adi = "";
        calismayaBaslamaYili = 0;
    }
    calisanDugum::calisanDugum(const string& ad, const int& calismabasla) { //parametreli kurucu fonksiyon oluşturuldu.
        sag = NULL;
        sol = NULL;
        adi = ad;
        calismayaBaslamaYili = calismabasla;
    }
