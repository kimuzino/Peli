#include <string>
#include <iostream>
#include <stdlib.h>

// Taistelun koodi
#include "Taistelu.cpp"

#include "WindowsLinux.h"


int main() {

    int hahmo;

    int kesto = 0;

    std::string tutorial;
    std::string jatka;

    while (true){

        std::cout << "Lue ohjeet jos olet ensikertalainen.\n";
        std::cout << "Haluatko lukea ohjeet? (Y/N) : ";
        
        std::cin >> tutorial;


        // ohjeet peliin
        if (tutorial == "Y" || tutorial == "y"){
            std::cout << "Ok, tässä on ohjeet.\n" << "\n";
            sleep_ms (1000);
            std::cout << "Kummallakin pelaajalla on 100hp.\n";
            std::cout << "Kummallakin on 3 liikettä ja 1 erikoisliike.\n";
            std::cout << "Erikoisliikkeen voi käyttää kun on osunut viholliseen 2 kertaa.\n";
            std::cout << "Ultimate iskun voi käyttää kun on käyttänyt 2 kertaa normaaliliikkeen ja yhden erikoisliikkeen.\n";
            std::cout << "Valitset liikkeet numeron mukaan.\n";
            std::cout << "Jotta peli kestäisi kauemmin niin pelaajat parantavat itseään 15hp joka kolmen erän jälkeen.\n";
            std::cout << "Liikkeen 2 voi käyttää kun on käyttänyt liikkeen 1 kaksi kertaa.\n";
            std::cout << "Kun liike 3 tai 4 on käytetty niin liikepisteesi laskevat sen verran kuin käytit niitä.\n";
            std::cout << "Pelaaja voittaa kun toinen pelaaja on kuollut.\n";
            std::cout << "Liikepisteiden käyttömäärä lukee liikkeen jälkeen!\n" << "\n";

            std::cout << "Haluatko aloittaa pelin? (Y/N) : ";
            std::cin >> jatka;

            if (jatka == "Y" || jatka == "y"){
                std::cout << "Ok, aloitetaan peli.\n" << "\n";
                sleep_ms (2000);
                clear_screen();;
                break;
            }

            if (jatka == "N" || jatka == "n"){
                std::cout << "Ok, sinulla on 10 sekuntia aikaa.\n" << "\n";
                sleep_ms (10000);
                clear_screen();;
                break;
            }
        }

        if (tutorial == "N" || tutorial == "n"){
            std::cout << "Ok, aloitetaan peli.\n" << "\n";
            sleep_ms (2000);
            clear_screen();;
            break;
        }

        else {
            clear_screen();
            continue;    
        }

    }
    

    // Aloitus teksti
    std::cout << "Terve tuloa taistelemaan!\n";
    sleep_ms (1000);
    std::cout << "Tässä pelissä taistelet tietokoneen kanssa.\n";
    sleep_ms (1000);
    std::cout << "Voit valita Pommittajan tai Alkoholistin.\n" << "\n";
    sleep_ms (1000);


    // Pommittajan voimat
    std::cout << "Pommittaja antaa sinulle nämä voimat.\n";
    std::cout << "\n";

    std::cout << "Liike 1. Nyrkki (10 dmg)\n";
    std::cout << "Liike 2. Kotitekoinen pommi (35 dmg)\n";
    std::cout << "Liike 3. (ultimate) Ydinpommi (75 dmg)\n";
    std::cout << "Liike 4. Erikois liike. Kotitekoinen adrenaliinipiikki (+30hp)\n";


    // Alkoholistin voimat
    std::cout << "\n";
    sleep_ms (5000);
    std::cout << "Alkoholisti antaa sinulle nämä voimat.\n";
    std::cout << "\n";
   
    std::cout << "Liike 1. Puukotus (20 dmg)\n";
    std::cout << "Liike 2. Pullon heitto (35 dmg)\n";
    std::cout << "Liike 3. (Ultimate) Isän käsi (50 dmg)\n";
    std::cout << "Liike 4. Erikois liike. Kalja (+30hp)\n";

    while (true) {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        // Hahmon valinta
        std::cout << "\n";

        if (kesto == 0) {
            sleep_ms (5000);
        }   

        if (kesto >= 1) {
            clear_screen();

            std::cout << "Pommittaja antaa sinulle nämä voimat.\n";
            std::cout << "\n";

            std::cout << "Liike 1. Nyrkki (10 dmg)\n";
            std::cout << "Liike 2. Kotitekoinen pommi (35 dmg)\n";
            std::cout << "Liike 3. (ultimate) Ydinpommi (75 dmg)\n";
            std::cout << "Liike 4. Erikois liike. Kotitekoinen adrenaliinipiikki (+30hp)\n" << "\n";

            std::cout << "Alkoholisti antaa sinulle nämä voimat.\n";
            std::cout << "\n";
   
            std::cout << "Liike 1. Puukotus (20 dmg)\n";
            std::cout << "Liike 2. Pullon heitto (35 dmg)\n";
            std::cout << "Liike 3. (Ultimate) Isän käsi (50 dmg)\n";
            std::cout << "Liike 4. Erikois liike. Kalja (+30hp)\n" << "\n";

        }

        std::cout << "Kumman hahmon haluat Pommittajan(1) vai Alkoholistin(2)\n";

        if (kesto == 0) {
            sleep_ms (1000);
        }
        
        std::cout << "Valitse hahmo: ";
        std::cin >> hahmo;

        if (hahmo == 1) {
            std::cout << "\n";
            std::cout << "Valitsit Pommittajan.\n";
            sleep_ms (1000);
            std::cout << "Sinua siirretään taisteluun.\n";
            sleep_ms (2000);
            Taistelu1();
            break;
        }

        if (hahmo == 2) {
            std::cout << "\n";
            std::cout << "Valitsit Alkoholistin.\n";
            sleep_ms (1000);
            std::cout << "Sinua siirretään taisteluun.\n";
            sleep_ms (2000);
            Taistelu2();
            break;
        }

        else {
            std::cout << "Valitse joko 1 tai 2.\n";
            sleep_ms (2000);
            kesto++;
            continue;
        }
    }
}