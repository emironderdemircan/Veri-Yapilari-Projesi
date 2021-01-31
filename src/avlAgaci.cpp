/**
* @file avlAgaci.cpp
* @description Ağacın fonksiyonları oluşturuluyor ve uygulanıyor..
* @course 1-B
* @assignment 2.Ödev
* @date 24.12.2020
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


    int avlAgaci::height(AvlDugum*& yukseklik) { //Yükseklik fonksiyonu.
        int h = 0;
        if (yukseklik != NULL) {
            int l_height = height(yukseklik->sol);
            int r_height = height(yukseklik->sag);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }
    int avlAgaci::difference(AvlDugum*& Difference) { //avl ağacı için gerekli olan fonksiyonlar.
        int l_height = height(Difference->sol);
        int r_height = height(Difference->sag);
        int b_factor = l_height - r_height;
        return b_factor;
    }
    AvlDugum* avlAgaci::rr_rotat(AvlDugum*& parent) { //avl ağacı için gerekli olan fonksiyonlar.
        AvlDugum* temp = new AvlDugum();
        temp = parent->sag;
        parent->sag = temp->sol;
        temp->sol = parent;
        return temp;
    }
    AvlDugum* avlAgaci::ll_rotat(AvlDugum*& parent) { //avl ağacı için gerekli olan fonksiyonlar.
        AvlDugum* temp = new AvlDugum();
        temp = parent->sol;
        parent->sol = temp->sag;
        temp->sag = parent;
        return temp;
    }
    AvlDugum* avlAgaci::lr_rotat(AvlDugum*& parent) { //avl ağacı için gerekli olan fonksiyonlar.
        AvlDugum* temp = new AvlDugum();
        temp = parent->sol;
        parent->sol = rr_rotat(temp);
        return ll_rotat(parent);
    }
    AvlDugum* avlAgaci::rl_rotat(AvlDugum*& parent) { //avl ağacı için gerekli olan fonksiyonlar.
        AvlDugum* temp = new AvlDugum();
        temp = parent->sag;
        parent->sag = ll_rotat(temp);
        return rr_rotat(parent);
    }
    AvlDugum*& avlAgaci::balance(AvlDugum*& t) { //avl ağacı için gerekli olan fonksiyonlar.
        int bal_factor = difference(t);
        if (bal_factor > 1) {
            if (difference(t->sol) > 0)
                t = ll_rotat(t);
            else
                t = lr_rotat(t);
        }
        else if (bal_factor < -1) {
            if (difference(t->sag) > 0)
                t = rl_rotat(t);
            else
                t = rr_rotat(t);
        }
        return t;
    }
    AvlDugum*& avlAgaci::AraVeEkle(AvlDugum*& alt_dugum, const string& adisoyadi, const string& isyeri, const int& calismabaslama) { //Ağaca ekleme yapılıyor.
        if (alt_dugum == NULL) {
            alt_dugum = new AvlDugum(isyeri, adisoyadi, calismabaslama);
            alt_dugum->elemanSayisi++;
            alt_dugum->sol = NULL;
            alt_dugum->sag = NULL;
            alt_dugum->eleman->ekle(adisoyadi, calismabaslama);
        }
        else if (isyeri < alt_dugum->isYeri) {
            AraVeEkle(alt_dugum->sag, adisoyadi, isyeri, calismabaslama);
        }
        else if (isyeri == alt_dugum->isYeri) {
            if (elemanSayisi == 0) {
                alt_dugum->eleman->ekle(adisoyadi, calismabaslama);
                elemanSayisi++;
            }
            if (elemanSayisi < alt_dugum->elemanSayisi) {
                alt_dugum->eleman->ekle(adisoyadi, calismabaslama);
                alt_dugum = balance(alt_dugum);
            }
            else if (elemanSayisi >= alt_dugum->elemanSayisi) {
                alt_dugum->eleman->ekle(adisoyadi, calismabaslama);
                alt_dugum = balance(alt_dugum);
                elemanSayisi++;
            }
        }
        else if (isyeri > alt_dugum->isYeri) {
            AraVeEkle(alt_dugum->sol, adisoyadi, isyeri, calismabaslama);
        }
        return alt_dugum;
    }
    void avlAgaci::postOrder(AvlDugum* alt_dugum)const { //ekrana postorder şeklinde yazdırılıyor.
        if (alt_dugum != NULL) {
            postOrder(alt_dugum->sag);
            postOrder(alt_dugum->sol);
            cout << alt_dugum->isYeri << ": " << endl;
            alt_dugum->eleman->yaz();
            cout << endl << endl;
        }
    }
    avlAgaci::avlAgaci() {
        root = NULL;
    }
    void avlAgaci::ekle(const string& isyeri, const string& adisoyadi, const int& calismayabasla) {
        AraVeEkle(root, adisoyadi, isyeri, calismayabasla);
    }
    void avlAgaci::ekranaYazdir() { //Ekrana yazdırılıyor.
        postOrder(root);
    }
    avlAgaci::~avlAgaci() { 
        delete root; //çöpler siliniyor.
    }



