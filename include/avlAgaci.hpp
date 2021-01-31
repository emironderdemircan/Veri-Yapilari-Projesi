/**
* @file avlAgaci.hpp
* @description Elemanların ağac düğümlerine eklendiği class.
* @course 1-B
* @assignment 2.Ödev
* @date 17.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
#ifndef AVLAGACI_HPP
#define AVLAGACI_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class avlAgaci { //elemanların işyerlerine göre eklendiği ağaç sınıfı.
private:
    int elemanSayisi = 0;
    AvlDugum* root;
    int height(AvlDugum*& yukseklik);
    int difference(AvlDugum*& Difference);
    AvlDugum* rr_rotat(AvlDugum*& parent);
    AvlDugum* ll_rotat(AvlDugum*& parent);
    AvlDugum* lr_rotat(AvlDugum*& parent);
    AvlDugum* rl_rotat(AvlDugum*& parent);
    AvlDugum*& balance(AvlDugum*& t);
    AvlDugum*& AraVeEkle(AvlDugum*& alt_dugum, const string& adisoyadi, const string& isyeri, const int& calismabaslama);
    void postOrder(AvlDugum* alt_dugum)const;
public:
    avlAgaci();
    void ekle(const string& isyeri, const string& adisoyadi, const int& calismayabasla);
    void ekranaYazdir();
    ~avlAgaci();
};
#endif