#include <iostream>

using namespace std;

class Categoria{
  private:
    int codigo;
    double caixa;
    
  public:
    Categoria(int codigo_categoria, double valor_caixa) {
      this->codigo=codigo_categoria;
      this->caixa=valor_caixa;
    }
    
    // Recupera o código correspondente a uma categoria.
    int getCodigo() {
      return codigo;
    }
    
    // Recupera o valor em caixa de uma categoria.
    double getValorCaixa(){
      return caixa;
    }
    
    // Adiciona uma quantia ao caixa de uma categoria.
    void adicionaCaixa(double valor) {
      caixa+=valor;
    }
    
    // Remove uma quantia ao caixa de uma categoria.
    void gastaCaixa(double valor) {
      caixa-=valor;
    }
};



class Orcamento {
  private:
    Categoria *saude;
    Categoria *educacao;
    Categoria *seguranca;
    Categoria *previdencia;
    Categoria *admPublica;
    
    // Construtor do Orçamento que deve conter um objeto categoria para cada pasta.
    // Recebe como parâmetro o valor monetário que deve ser atribuído a aquele orçamento.
    // Este valor deve ser distribuído a cada categoria, nos percentuais descritos anteriormente.
  public:
    Orcamento(double impostos) {
      saude = new Categoria(0,impostos*0.15);
      educacao = new Categoria(1,impostos*0.15);
      seguranca=  new Categoria(2,impostos*0.20);
      previdencia = new Categoria(3,impostos*0.35);
      admPublica = new Categoria(4,impostos*0.15);
    }
    
    // Reduz o valor no caixa da categoria especificada.
    void gastoCategoria(int codigo_categoria, double valor) {
      if(codigo_categoria == 0){
        saude->gastaCaixa(valor);
        }
      if(codigo_categoria == 1){ 
        educacao->gastaCaixa(valor);
      }
      if(codigo_categoria == 2){ 
        seguranca->gastaCaixa(valor);
      }


      if(codigo_categoria == 3){
       previdencia->gastaCaixa(valor);
      
      }
      if(codigo_categoria == 4){
        admPublica->gastaCaixa(valor);
      }
    }
    
    // Retorna o valor em caixa da categoria especificada.
    double getSaldo(int codigo_categoria) {
      if(codigo_categoria==0){
       return saude->getValorCaixa();
      }
      
      
      
      if(codigo_categoria==1){
       return educacao->getValorCaixa();
      }
      if(codigo_categoria==2){
       return seguranca->getValorCaixa();
      }

      if(codigo_categoria==3){ 
        return previdencia->getValorCaixa();
      }
      if(codigo_categoria==4){
        return admPublica->getValorCaixa();
      }
    }
    
    // Retorna o ponteiro para o objeto da categoria especificada.
    Categoria* getCategoria(int codigo_categoria) {
      if(codigo_categoria==0){
         return saude;
      }
      if(codigo_categoria==1) {
        return educacao;
      }
      if(codigo_categoria==2){
        return seguranca;
      }
      
      
      if(codigo_categoria==3){
        return previdencia;
      
      }   
      if(codigo_categoria==4){
        return admPublica;
      }
    }
};



int main() {
  Orcamento *orcamento;

  char test = 0;
  while(cin >> test) {
      switch (test) {
        case 'o': { // Inicia novo orçamento
          double valor = 0;
          cin >> valor;
          
          orcamento = new Orcamento(valor);   
          
        }
        break;
        case 'g': { // Gastar em uma categoria
          int categoria = 0;
          double valor = 0;
          cin >> categoria >> valor;
          
          orcamento->gastoCategoria(categoria, valor);
          
          cout << categoria << ": " << orcamento->getSaldo(categoria) << endl;
        }
        break;
        case 'p': { // Imprimir todas as categorias e seus saldos
          for (int categoria = 0; categoria < 5; categoria++) {
            cout << categoria << ": " << orcamento->getSaldo(categoria) << endl;
          }
        }
        break;
        default: {
          cout << "----------" << endl;
        } break;
      }
  }
  return 0;
}