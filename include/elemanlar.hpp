/**
* @file elemanlar.hpp
* @description Elemanların olduğu fonksiyonlar ve ekleme işlemleri.
* @course 1-B
* @assignment 2.Ödev
* @date 18.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
#ifndef ELEMANLAR_HPP
#define ELEMANLAR_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class elemanlar { //Elemanlar fonksiyonu.
private:
    calisanDugum* head;
    void AraEkle(calisanDugum*&, string&, int);
    void postOrder(calisanDugum*& );
public:
    elemanlar();
    void ekle(string, int );
    void yaz();
    ~elemanlar();
};
#endif