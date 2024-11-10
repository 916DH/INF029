// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Leonardo Ferreira dos Santos
//  email: 20241160046@ifba.edu.br
//  Matrícula: 20241160046
//  Semestre: 02

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LeonardoSantos20241160046.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{

  char sDia[3], sMes[3], sAno[5];
  int i = 0;

  //quebrar a string data em strings sDia, sMes, sAno
  for(; data[i] != '/'; i++)
    sDia[i] = data[i];

  if(i==1 || i==2)
    sDia[i] = '\0';
  else
    return 0;

  int j = i + 1; i = 0;

  for(; data[j] != '/'; j++, i++)
    sMes[i] = data[j];

  if(i==1 || i==2)
    sMes[i] = '\0';
  else
    return 0;

  j++; i = 0;

  for(; data[j] != '\0'; j++, i++)
    sAno[i] = data[j];

  if(i==2 || i==4)
    sAno[i] = '\0';
  else
    return 0;

  // transformando a string quebrada em inteiro
  int dia, mes, ano;

  dia = strlen(sDia) == 2 ? ((sDia[0] - 48) * 10) + (sDia[1] - 48) : (sDia[0] - 48);
  
  mes = strlen(sMes) == 2 ? ((sMes[0] - 48) * 10) + (sMes[1] - 48) : (sMes[0] - 48); 
  if(mes>12 || mes<1) return 0;
  
  ano = strlen(sAno) == 2 ? 2000 + (((sAno[0] - 48) * 10) + (sAno[1] - 48)) : ((sAno[0] - 48) * 1000) + ((sAno[1] - 48) * 100) + ((sAno[2] - 48) * 10) + (sAno[3] - 48);
  if(ano>2024 || ano<1) return 0;

  int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
    diasNoMes[1] = 29;

  if(dia>diasNoMes[mes-1] || dia<1)
    return 0;

  return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[])
{   

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //calcule a distancia entre as datas
      //quebrando as strings e transformanado em interios - DATA INICIAL
      char sDia[3], sMes[3], sAno[5];
      int dia[2], mes[2], ano[2];
      int i = 0;

      for(; datainicial[i] != '/'; i++)
        sDia[i] = datainicial[i];

      sDia[i] = '\0';
      int j = i + 1; i = 0;

      for(; datainicial[j] != '/'; j++, i++)
        sMes[i] = datainicial[j];

      sMes[i] = '\0';
      j++; i = 0;

      for(; datainicial[j] != '\0'; j++, i++)
        sAno[i] = datainicial[j];

        sAno[i] = '\0'; i = 0;

      dia[0] = strlen(sDia) == 2 ? ((sDia[0] - 48) * 10) + (sDia[1] - 48) : (sDia[0] - 48);
      mes[0] = strlen(sMes) == 2 ? ((sMes[0] - 48) * 10) + (sMes[1] - 48) : (sMes[0] - 48); 
      ano[0] = strlen(sAno) == 2 ? 2000 + (((sAno[0] - 48) * 10) + (sAno[1] - 48)) : ((sAno[0] - 48) * 1000) + ((sAno[1] - 48) * 100) + ((sAno[2] - 48) * 10) + (sAno[3] - 48);

      int diasNoMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if(ano[0] % 4 == 0 && (ano[0] % 100 != 0 || ano[0] % 400 == 0)){
          diasNoMes[1] = 29;
      }


      for(; datafinal[i] != '/'; i++)
        sDia[i] = datafinal[i];

      sDia[i] = '\0';
      j = i + 1; i = 0;

      for(; datafinal[j] != '/'; j++, i++)
        sMes[i] = datafinal[j];

      sMes[i] = '\0';
      j++; i = 0;

      for(; datafinal[j] != '\0'; j++, i++)
        sAno[i] = datafinal[j];

        sAno[i] = '\0';

      dia[1] = strlen(sDia) == 2 ? ((sDia[0] - 48) * 10) + (sDia[1] - 48) : (sDia[0] - 48);
      mes[1] = strlen(sMes) == 2 ? ((sMes[0] - 48) * 10) + (sMes[1] - 48) : (sMes[0] - 48); 
      ano[1] = strlen(sAno) == 2 ? 2000 + (((sAno[0] - 48) * 10) + (sAno[1] - 48)) : ((sAno[0] - 48) * 1000) + ((sAno[1] - 48) * 100) + ((sAno[2] - 48) * 10) + (sAno[3] - 48);

      // verificando se a data inicial é maior do que a final
      if(ano[0] > ano[1] || ((ano[0] == ano[1]) && mes[0] > mes[1]) || (((ano[0] == ano[1]) && mes[0] == mes[1]) && dia[0] > dia[1])){
        dma.retorno = 4;
        return dma;
      }

      dma.qtdAnos = dma.qtdDias = dma.qtdMeses = 0;
      int auxMes = mes[0];
      
      for(; ano[0] < ano[1]; ano[0]++){
        dma.qtdAnos++;
      }
      if(mes[0] > mes[1]){
        dma.qtdAnos--;
        dma.qtdMeses = 12 + (mes[1] - mes[0]);
      }else if(mes[0] < mes[1]){
        for(; mes[0] < mes[1]; mes[0]++)
          dma.qtdMeses++;
      }
      if(dia[0] > dia[1]){
        dma.qtdMeses--;
        dma.qtdDias = diasNoMes[auxMes-1] == 29 ? (diasNoMes[auxMes-1] - 1) + (dia[1] - dia[0]) : diasNoMes[auxMes-1] + (dia[1] - dia[0]);
        if(ano[1] % 4 == 0 && (ano[1] % 100 != 0 || ano[1] % 400 == 0))
          dma.qtdDias++;
      }else if(dia[0] < dia[1])
        for(; dia[0] < dia[1]; dia[0]++)
          dma.qtdDias++;

      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    char com_acento[] = "áéíóúÁÉÍÓÚàèìòùÀÈÌÒÙâêîôûÂÊÎÔÛãõÃÕçÇ";
    char sem_acento[] = "aeiouaeiouaeiouaeiouaeiouaeiouaoaocc";
    char auxTexto[250];
    
    if(isCaseSensitive == 1){
      for(int i=0; i < strlen(texto); i++){
        if(c==texto[i])
          qtdOcorrencias++;
      }
    }else{
      for(int i=0; i < strlen(texto); i++)
        auxTexto[i] = texto[i];
      auxTexto[strlen(texto)] = '\0';
      for(int i=0; i < strlen(auxTexto); i++){
        if(auxTexto[i]>='A' && auxTexto[i]<='Z'){
          auxTexto[i] += 32;
        }else{
          for(int j=0; j < strlen(com_acento); j++){
            if(auxTexto[i]==com_acento[j])
              auxTexto[i] = sem_acento[j];
          }
        }
      }
      if(c>='A' && c<='Z'){
          c += 32;
      }else{
        for(int j=0; j < strlen(com_acento); j++){
          if(c==com_acento[j]){
            c = sem_acento[j];
            break;
          }
        }
      }
      for(int i=0; i < strlen(auxTexto); i++){
        if(c==auxTexto[i])
          qtdOcorrencias++;
      }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int size = strlen(strBusca);

    for(int i=0, n=0; i < strlen(strTexto); i++){
      if(strTexto[i] == strBusca[0]){
        char teste[size+1];
        teste[size] = '\0';

        for(int j=0, k=i; j < size; j++)
          teste[j] = strTexto[k++];
        
        if(strcmp(teste, strBusca) == 0){
          posicoes[n++] = i+1;
          posicoes[n++] = i + size;
          qtdOcorrencias++;
          i += (size-1);
        }
      }
    }

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}




DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
