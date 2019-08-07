#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// inisialisasi fungsi atau method
void teksBiruTua();
void teksBiruTerang();
void teksHijauTua();
void teksHijauTerang();
void teksMerahTua();
void teksMerahTerang();
void kembalikanWarna();

/* ============================================================================================================
mengambil handle dari windows yang aktif
referensi: https://stackoverflow.com/questions/9203362/c-color-text-in-terminal-applications-in-windows
*/
HANDLE hConsole; // deklarasi handle

/*
** Referensi: https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-info-str
di dalam CONSOLE_SCREEN_BUFFER_INFO mengandung data:
* lebar dari windows(cmd)
* posisi kursor
* attribut text (character)
* posisi windows dari sisi kiri atas, kanan atas, kiri bawah, kanan bawah
    * referensi: https://docs.microsoft.com/en-us/windows/console/small-rect-str
* dan kordinat dari karakter
    * referensi: https://docs.microsoft.com/en-us/windows/console/coord-str

*/
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

/*
inisialisasi pengaturan awal (disini dikhususkan untuk warna)
*/
WORD saved_attributes;
/* ========================================================================================================= */

/*
rubah warna tulisan dibawah kodingan ini menjadi bagus
referensi https://docs.microsoft.com/en-us/windows/console/setconsoletextattribute

untuk attribut character bisa dilihat pada link: https://docs.microsoft.com/en-us/windows/console/console-screen-buffers
*/

/* ============= BIRU ============= */
// teks berwarna biru tua
void teksBiruTua(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
}


// teks berwarna biru
void teksBiruTerang(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
/* ======================================= */



/* ============= HIJAU ============= */
// teks berwarna hijau tua
void teksHijauTua(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
}

// teks berwarna hijau
void teksHijauTerang(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_GREEN);
}
/* ======================================= */



/* ============= MERAH ============= */
// teks berwarna merah tua
void teksMerahTua(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
}

// teks berwarna merah
void teksMerahTerang(){
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_RED);
}
/* ======================================= */


// mengembalikan warna ke putih
void kembalikanWarna(){
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

// program utama
int main(){
    // inisialisasi handle
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    /* menyimpan settingan default warna (putih) */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    // inisialisasi untuk mengatur warna menjadi default (putih)
    saved_attributes = consoleInfo.wAttributes;

    teksBiruTua();
    printf("Tulisan ini akan berwarna BLUE");

    teksMerahTerang();
    printf("Tulisan ini akan berwarna merah terang");

    kembalikanWarna();
    return 0;
}
