#ifndef FOGAO_HPP
#define FOGAO_HPP

#include <iostream>

class Fogao {
    private:
    
    int numero_de_queimadores;
    int capacidade_forno;
    
    public:
    
    Fogao();

    int getNumero_de_queimadores();
    int getCapacidade_forno();

    void setNumero_dequeimadores(int nqueimadores);
    void setCapacidade_forno(int ncapacidade_forno);
};

#endif