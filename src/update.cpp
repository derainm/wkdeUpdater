// Base code taken from 
// https://github.com/mfontanini/Programs-Scripts/blob/master/constexpr_hashes/md5.h 
// and expanded to include a main function

//#ifndef CONSTEXPR_HASH_MD5_H
//#define CONSTEXPR_HASH_MD5_H

#include "update.h"
#include "md5.h"
#include <cstdio>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <string>
#include <fstream>


using namespace std;

inline bool exists_file1(const std::string& name) {
    if (FILE* file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    else {
        return false;
    }
}


/*
*	Hash d'une chaine de caractères
*/
char* md5_str(char* p)
{
    md5_state_t state;
    md5_byte_t digest[16];
    //char* hex_output = {};// (char*)malloc(33);
    char hex_output[33] = {};
    int di;

    //hashage
    md5_init(&state);
    md5_append(&state, (const md5_byte_t*)p, (int)strlen(p));
    md5_finish(&state, digest);

    //output
    for (di = 0; di < 16; di++) {
        sprintf(hex_output + di * 2, "%02x", digest[di]);
    }
    return hex_output;
}

/*
*	Hash d'un fichier
*/
const char* md5_file(FILE* fp)
{
    md5_state_t state;
    md5_byte_t digest[16];
    //char* hex_output =   (char*)malloc(33);
    char hex_output[33] = {};// (char*)malloc(33);
    char data[64];
    int di;
    size_t ln;

    //hashage
    md5_init(&state);
    while (!feof(fp))
    {
        ln = fread(data, 1, sizeof(data), fp);
        md5_append(&state, (const md5_byte_t*)data, (int)ln);
    }
    md5_finish(&state, digest);

    //output
    for (di = 0; di < 16; di++) {
        sprintf(hex_output + di * 2, "%02x", digest[di]);
    }
    /*printf("%s  ici \n", hex_output);*/
    return hex_output;
}

std::string ExePath_s() {
    char buffer[260];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string s(buffer);
    std::string::size_type pos = s.find_last_of("\\/");
    //string last = std::string(s).substr(0, pos);
    return std::string(s).substr(0, pos);
}

bool CheckWololoKingdomsDE()
{
    FILE* fp;
    std::string  pathexe = ExePath_s();
    std::string s = "\\AGE2_X1";
    std::string::size_type i = pathexe.find(s);
    if (i != std::string::npos)
        pathexe.erase(i, s.length());

    //char * path = "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat";
    std::string path = {};// "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat";
    path.append(pathexe);
    path.append("\\Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat");
    //if wecan open file (then the file doesn't exist
    //if (strcmp(path , "error") == 0) return false;
    fp = fopen(path.c_str(), "rb");
    //debug on md5 function odn't try to store in vzriable 
    //char currentversion[33] = {};
    //sprintf(currentversion, "%s", md5_file(fp));
    //printf("%s  ici \n", currentversion);
    //currentversion  = md5_file(fp);
 
   
    printf("%s\n", path.c_str());
   
    //https://www.voobly.com/gamemods/mod/1371/WololoKingdoms-DE
    //Version: 5.8.1.152
    const char * version150 = "f91af0bd805de903866de535da6ddc03";
    //0E5781B6690E301289E597556DA4E119
    //we ruturn boolean of string compaire the tow md5
    bool res = strcmp(version150, md5_file(fp)) == 0;
    //we ruturn boolean of string compaire the tow md5
    return res;
}

//void  UpdateDataMod()
//{
//
//
//    if ((exists_file1("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\version.ini") || exists_file1("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat")))
//    {
//        if (!CheckWololoKingdomsDE())
//        {
//            //.dat
//            //DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat");
//            Sleep(5);
//            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.5 RC DE features\\update\\empires2_x1_p1.dat", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat", false);
//            //xml
//            DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\age2_x1.xml");
//            Sleep(5);
//            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.5 RC DE features\\update\\age2_x1.xml", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\age2_x1.xml", false);
//            //ini
//            DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\language.ini");
//            Sleep(5);
//            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.5 RC DE features\\update\\language.ini", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\language.ini", false);
//            //drs
//            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\drs", "Voobly Mods\\AOC\\Data Mods\\myde\\drs", true);
//            system("copy \"Voobly Mods\\AOC\\Patches\\v1.5 RC DE features\\update\\drs\" \"Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\drs\" ");
//            //mp3
//            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\stream\\poles.mp3", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Sound\\stream\\poles.mp3", true);
//            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\stream\\bohemians.mp3", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Sound\\stream\\bohemians.mp3", true);
//
//            MessageBox(NULL, "Update  WololoKingdoms DE version: 5.8.1.152", "WololoKingdoms DE version: 5.8.1.152", MB_ICONINFORMATION);
//            ofstream myfile("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\version.ini");
//            if (myfile.is_open())
//            {
//                //change here
//                myfile << "5.8.1.152" << "";
//                myfile << std::endl << "";
//                myfile.close();
//            }
//            system("taskkill /IM \"age2_x1.exe\" /F");
//        }
//    }
//}
void  UpdateDataMod()
{

  
    if ((exists_file1("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\version.ini") || exists_file1("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat")))
    {
        if (!CheckWololoKingdomsDE())
        {
            //.dat
            //DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat");
            Sleep(5);
            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\empires2_x1_p1.dat", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Data\\empires2_x1_p1.dat", false);
            //xml
            DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\age2_x1.xml");
            Sleep(5);
            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\age2_x1.xml", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\age2_x1.xml", false);
            //ini
            DeleteFileA("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\language.ini");
            Sleep(5);
            CopyFileA("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\language.ini", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\language.ini", false);
            //drs
            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\drs", "Voobly Mods\\AOC\\Data Mods\\myde\\drs", true);
            system("copy \"Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\drs\" \"Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\drs\" ");
            //mp3
            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\stream\\poles.mp3", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Sound\\stream\\poles.mp3", true);
            //CopyFile("Voobly Mods\\AOC\\Patches\\v1.6 RC\\update\\stream\\bohemians.mp3", "Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\Sound\\stream\\bohemians.mp3", true);

            MessageBox(NULL, "Update  WololoKingdoms DE version: 5.8.1.152", "WololoKingdoms DE version: 5.8.1.152", MB_ICONINFORMATION);
            ofstream myfile("Voobly Mods\\AOC\\Data Mods\\WololoKingdoms DE\\version.ini");
            if (myfile.is_open())
            {
                //change here
                myfile << "5.8.1.152" << "";
                myfile << std::endl << "";
                myfile.close();
            }
            system("taskkill /IM \"age2_x1.exe\" /F");
        }
    }
}



void updatemod()
{
    UpdateDataMod();

}