/**
* @file elemanlar.cpp
* @description Elemanların ağaçta yeleşeceği yerler aranıyor ve ekleniyor.
* @course 1-B
* @assignment 2.Ödev
* @date 22.12.2020
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
    void elemanlar::AraEkle(calisanDugum*& alt_dugum, string& adisoyadi, int calismabasla) { //Elemanların ağaçta yerleşeceği yeri arıyor.Ve bulduğunda ekleme işlemini yapıyor.
        if (alt_dugum == NULL) {
            alt_dugum = new calisanDugum(adisoyadi, calismabasla);
        }
        else if (2020 - calismabasla < 2020 - alt_dugum->calismayaBaslamaYili) { //çalışma süresi büyük olan sağa ekleneceği için yalıştığı yıl hesaplanıyor.
            AraEkle(alt_dugum->sol, adisoyadi, calismabasla);
        }
        else if (2020 - calismabasla > 2020 - alt_dugum->calismayaBaslamaYili) { //çalışma süresi büyük olan sağa ekleneceği için yalıştığı yıl hesaplanıyor.
            AraEkle(alt_dugum->sag, adisoyadi, calismabasla);
        }
        else return;
    }
    void elemanlar::postOrder(calisanDugum*& alt_dugum) { //elemanları postorder yöntemiyle okuma yapılıyor.
        if (alt_dugum != NULL) {
            postOrder(alt_dugum->sol);
            postOrder(alt_dugum->sag);
            cout << alt_dugum->adi << "-" << alt_dugum->calismayaBaslamaYili << " | ";
        }
    }
    elemanlar::elemanlar() {
        head = NULL;
    }
    void elemanlar::ekle(string isim, int calismabasla) { //Elemanlar fonksiyonu yazılıyor.
        AraEkle(head, isim, calismabasla);
    }
    void elemanlar::yaz() {
        postOrder(head);
    }
    elemanlar::~elemanlar() {
        delete head;
    }

