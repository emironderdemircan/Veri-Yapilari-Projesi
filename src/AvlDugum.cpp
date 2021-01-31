/**
* @file AvlDugum.cpp
* @description iş yerlerinin olduğu ağac düğüm sınıfı oluşturuluyor.
* @course 1-B
* @assignment 2.Ödev
* @date 20.12.2020
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

    AvlDugum::AvlDugum(const string& isyeri, const string& isim, const int& calismabasla) { //Kurucu fonksiyonlar oluşturuldu.
        isYeri = isyeri;
        eleman = new elemanlar();
        sol = NULL;
        sag = NULL;
    }
    AvlDugum::AvlDugum() { //elemanlar işyerine göre ekleniyor.
        isYeri = "";
        eleman = new elemanlar();
        sol = NULL;
        sag = NULL;
    }
    AvlDugum::~AvlDugum() { //Yıkıcı fonksiyonlar oluşturuldu.
        delete sol, sag, eleman;
    }

