/**
* @file main.cpp
* @description Main kodları yazılıyor ve dosyadan okutulup yazdırılıyor..
* @course 1-B
* @assignment 2.Ödev
* @date 22.12.2020
* @author Emir Önder Demircan // emir.demircan@ogr.sakarya.edu.tr
*/
//Gerekli kütüphaneler eklendi
#include <iostream>
#include <fstream>
#include <string>
#include "calisanDugum.hpp"
#include "elemanlar.hpp"
#include "AvlDugum.hpp"
#include "AvlAgaci.hpp"
#include<sstream>
using namespace std; //std fonksiyonu tanımlandı.
int main() {
    avlAgaci* isyeriVeElemanlar = new avlAgaci(); //pointerlar oluşturuldu.
    string adiSoyadi, satir, isYeri; //Kullanılacak değişkenler oluşturuldu.
    int calismayaBaslamaYil;
	string okuma;
    ifstream readFile("Deneme.txt");
		while (getline(readFile, satir)) 
		{
        stringstream ss(satir);
        getline(ss, isYeri, '#');
        getline(ss, adiSoyadi, '#');
        getline(ss, okuma, '#');
        isyeriVeElemanlar->ekle(isYeri, adiSoyadi, stoi(okuma));
		}
    isyeriVeElemanlar->ekranaYazdir(); //ekrana yazdır fonksiyonu ile ekrana yazdırılıyor.
    delete isyeriVeElemanlar; //çöpler siliniyor.
    return 0;
}