#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class OrdemProducao{
string cliente;
string dataEntrega;
vector<ProdutoOP*> produto;
public:
  ordemProducao(string cliente, string dataEntrega)
  {
    this->cliente = cliente;
    this->dataEntrega = dataEntrega;
  }
//  string toString()
//  {
//    return this->cliente + ',' + this->dataEntrega;
//  }

  void adicionaProduto(Produto *produto, int qtProdutos)
  {
      produto.push_back(new produtoOP(produto, qtProdutos))
  }
  string getCliente(){
    return this->cliente;
  }
  string getDataEntrega()
  {
    return this->dataEntrega;
  }
  string imprimeFicha(){}
  string liberaProducao(){}
};
