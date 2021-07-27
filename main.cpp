#include <iostream>
using namespace std;

const int QTDE_AMOSTRAS = 5;
const int CONCENTRACAO_MAXIMA = 15;

void leAmostras (float amostras[QTDE_AMOSTRAS]) {
  for (int i = 0; i < QTDE_AMOSTRAS; i++) {
    cin >> amostras[i];
     if (amostras[i] > CONCENTRACAO_MAXIMA || amostras[i] < 0)
     i--;
  } 
}

void imprimeAmostras (float amostras[QTDE_AMOSTRAS]) {
  for (int i = 0; i < QTDE_AMOSTRAS; i++)
    cout << amostras[i] << "\t";
  cout << endl;
}

float amostraMinima (float amostras[QTDE_AMOSTRAS]) {
  float minima = amostras[0];
  for (int i = 1; i < QTDE_AMOSTRAS; i++)
    if (amostras[i] < minima)
      minima = amostras[i];
  return minima;
}

float amostraMaxima (float amostras[QTDE_AMOSTRAS]) {
  float maxima = amostras[0];
   for (int i = 1; i < QTDE_AMOSTRAS; i++)
    if (amostras[i] > maxima)
      maxima = amostras[i];
   return maxima;
}

void normalizaAmostras (float amostras[QTDE_AMOSTRAS]) {
  float minima = amostraMinima (amostras);
  float maxima = amostraMaxima (amostras);
  for (int i = 0; i < QTDE_AMOSTRAS; i++) {
    amostras[i] = (amostras[i] - minima) / (maxima - minima);
  }
}

float mediaAmostras (float amostras[QTDE_AMOSTRAS]) {
  float soma = 0;
  float minima = amostraMinima(amostras);
    for (int i = 0; i < QTDE_AMOSTRAS; i++) {
     soma = soma + amostras[i];
 }
  return soma / (QTDE_AMOSTRAS - 1);
}

int main() {
  float amostras [QTDE_AMOSTRAS];

  leAmostras (amostras);
  normalizaAmostras (amostras);
  cout << "Media: " << mediaAmostras (amostras) * CONCENTRACAO_MAXIMA << endl;

  return 0;
}
