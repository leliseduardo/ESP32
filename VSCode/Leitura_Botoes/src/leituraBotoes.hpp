// ===============================================================================================
// --- Bibliotecas --- 
#include <Arduino.h>

#ifndef LEITURA_BOTOES
#define LEITURA_BOTOES

// ===============================================================================================
// --- Constantes do projeto ---
#define BTS_NUM 2

class kb_rd
{
    public:
        kb_rd(const int bta1, const int bt2);
        unsigned read_bt(const int btn, const int bounce);

    private:
        int pins[BTS_NUM];
};


#endif
