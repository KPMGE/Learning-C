/*
NOME E MATRICULA: Kevin Carvalho de Jesus 2020101820 e Lara Tagarro Bernardes 2020102553 
DATA DE ENTREGA:  4/11/2020
UNIVERSIDADE: Universidade Federal do Espírito Santo - UFES
DESCRIÇÃO: Programa em linguagem C para leitura e manipulação de dados de um arquivo csv que contém dados sobre o Covid 19 no ano de 2020 no estado do Espírito Santo.
*/

// importação de bibliotecas necessárias para o programa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// definindo valores booleanos True e False
#define True 1
#define False 0
// definindo tamanho do csv(quantidade de linhas)
#define TAMANHOCSV 202362

// criando struct para armazenar um município e a quantidade de casos
typedef struct
{
  int numeroDeCasos;
  char municipio[30];
} CasosMunicipio;

// criando struct para trabalhar com datas
typedef struct
{
  int dia;
  int mes;
  int ano;
} Data;

// criando struct para as comorbidades
typedef struct
{
  int comorbidadePulmao;
  int comorbidadeCardio;
  int comorbidadeRenal;
  int comorbidadeDiabetes;
  int comorbidadeTabagismo;
  int comorbidadeObesidade;
} Comorbidades;

// criando struct principal para armazenar todos os dados do csv
typedef struct
{
  char municipio[30];
  int idadePessoa;
  int classificacao;
  int ficouInternado;
  Data dataCadastro;
  Data dataObito;
  Comorbidades comorbidadesPacientes;
} DadosCsv;

// criando vetor csv como global
DadosCsv vetorCsv[TAMANHOCSV];
// criando matriz com todos os munícipios do Espirito Santo em ordem alfabética
char municipiosEspiritoSanto[79][30] =
{
  "AFONSO CLAUDIO", "AGUA DOCE DO NORTE", "AGUIA BRANCA", "ALEGRE",
  "ALFREDO CHAVES", "ALTO RIO NOVO", "ANCHIETA", "APIACA", "ARACRUZ",
  "ATILIO VIVACQUA", "BAIXO GUANDU", "BARRA DE SAO FRANCISCO",
  "BOA ESPERANCA", "BOM JESUS DO NORTE", "BREJETUBA", "CACHOEIRO DE ITAPEMIRIM",
  "CARIACICA", "CASTELO", "COLATINA", "CONCEICAO DA BARRA", "CONCEICAO DO CASTELO",
  "DIVINO DE SAO LOURENCO", "DOMINGOS MARTINS", "DORES DO RIO PRETO", "ECOPORANGA",
  "FUNDAO", "GOVERNADOR LINDENBERG", "GUACUI", "GUARAPARI", "IBATIBA", "IBIRACU",
  "IBITIRAMA", "ICONHA", "IRUPI", "ITAGUACU", "ITAPEMIRIM", "ITARANA", "IUNA",
   "JAGUARE", "JERONIMO MONTEIRO", "JOAO NEIVA", "LARANJA DA TERRA", "LINHARES",
  "MANTENOPOLIS", "MARATAIZES", "MARECHAL FLORIANO", "MARILANDIA", "MIMOSO DO SUL",
  "MONTANHA", "MUCURICI", "MUNIZ FREIRE", "MUQUI", "NOVA VENECIA", "PANCAS",
  "PEDRO CANARIO", "PINHEIROS", "PIUMA", "PONTO BELO", "PRESIDENTE KENNEDY", "RIO BANANAL",
  "RIO NOVO DO SUL", "SANTA LEOPOLDINA", "SANTA MARIA DE JETIBA", "SANTA TERESA",
  "SAO DOMINGOS DO NORTE", "SAO GABRIEL DA PALHA", "SAO JOSE DO CALCADO", "SAO MATEUS",
  "SAO ROQUE DO CANAA", "SERRA", "SOORETAMA", "VARGEM ALTA", "VENDA NOVA DO IMIGRANTE",
  "VIANA", "VILA PAVAO", "VILA VALERIO", "VILA VELHA", "VITORIA"
};

// função que realiza a leitura do csv
void leCsv(FILE *csv);
// função que mostra a quantidade total de casos entre a data inicial e final
void mostraTotalCasosEntreDatas(FILE *arquivo, Data dataInicial, Data dataFinal);
// função que lista em ordem alfabética as cidades com mais de N casos
void listaCasosEmOrdemAlfabetica(FILE *arquivo, int n);
// função que ordena os casos em ordem decrescente
void colocaEmOrdemDecrescente(CasosMunicipio vetorMunicipios[]);
// função que lista as Top N cidades
void listaTopNCidades(FILE *arquivo, int n, Data dataInicial, Data dataFinal);
// função que converte uma string para maiúsculo
void converteStringMaiusculo(char string[]);
// função que imprime as porcentagens para item 6
void imprimePorcentagensItem6(FILE *arquivo, char municipio[]);
// função que imprime os itens da questão 7
void imprimeDadosItem7(FILE *arquivo, Data dataInicial, Data dataFinal);
// função que imprime a porcentagem de pessoas confirmadas internadas
void porcentagemPessoasConfirmadasInternadas(FILE *arquivo, char Municipio[]);
// função que imprime a porcentagem de pessoas que morreram
void porcentagemPessoasQueMorreram(FILE *arquivo, char Municipio[]);
// função que imprime a quantidade de pessoas internadas que morreram
void porcentagemPessoasInternadasQueMorreram(FILE *arquivo, char Municipio[]);
// função que retorna a quantidade de dias, dado um certo mês
int quantidadeDiasDoMes(int mes);
// função que verifica se as datas são iguais
int ehMesmaData(Data data1, Data data2);
// função que calcula o total de casos, dado um munícipio
int calculaTotalCasos(char municipio[]);
// função que determina a quantidade de casos
int calculaQuantidadeDeCasosComDatas(Data dataInicial, Data dataFinal, char municipio[]);
// função que retorna a porcentagem, dados dois valores
float calculaPorcentagem(float valor1, float valor2);
// função que calcula o desvio padrão, dadas duas datas
float calculaDesvioPradraoEntreDatas(Data dataInicial, Data dataFinal, float media);
// função que calcula a media, datas duas datas
float calculaMediaDeIdadeEntreDatas(Data dataInicial, Data dataFinal);
// função que calcula a porcentagem de pessoas que morreram e não possuiam comorbidades
float calculaPorcentagemPessoasQueMorreramSemComorbidade(Data dataInicial, Data dataFinal);
// função que realiza a leitura de uma data
Data leData(void);
// função que passa para a próxima data
Data proximaData(Data dataInicial);

int main(void)
{
  // abrindo o arquivo csv em modo leitura
  FILE *csv;
  csv = fopen("covid19ES.csv", "r");

  // caso não seja possivel abrir o arquivo, o programa é abortado
  if (csv == NULL)
  {
    printf("Nao foi possivel abrir o arquivo!");
    exit(1);
  }
  // inicializando variáveis
  char nomePasta[10], municipioParaItem6[30];
  int NCasos, N;
  Data dataIniTotalCasos, dataFimTotalCasos;
  Data dataIniTopCidades, dataFimTopCidades;
  Data dataParaMediaDesvioIni, dataParaMediaDesvioFim;

  // lendo nome da pasta
  scanf("%s", nomePasta);
  // lendo quantidade para ordem alfabética
  scanf("%d", &NCasos);
  // lendo datas para total de casos
  dataIniTotalCasos = leData();
  dataFimTotalCasos = leData();
  // lendo datas e valor para top N cidades
  scanf("%d", &N);
  dataIniTopCidades = leData();
  dataFimTopCidades = leData();
  // lendo munícipio para o item 6
  scanf("%s", municipioParaItem6);
  // lendo datas para media e desvio
  dataParaMediaDesvioIni = leData();
  dataParaMediaDesvioFim = leData();

  // criando variávies para criação e escrita na pasta dada como entrada
  char comando[10] = "mkdir ";

  // criando variáveis para armazenar o caminho para cada item
  char enderecoParaOutputItem3[20], enderecoParaOutputItem4[20], enderecoParaOutputItem5[20], enderecoParaOutputItem6[20], enderecoParaOutputItem7[20];
  // criando variáveis para os itens
  FILE *item3, *item4, *item5, *item6, *item7;

  // criando comando para criar o diretório
  strcat(comando, nomePasta);
  // criando diretório
  system(comando);
  // copiando nome da pasta para enderecoParaOutput em cada elemento
  strcpy(enderecoParaOutputItem3, nomePasta);
  strcpy(enderecoParaOutputItem4, nomePasta);
  strcpy(enderecoParaOutputItem5, nomePasta);
  strcpy(enderecoParaOutputItem6, nomePasta);
  strcpy(enderecoParaOutputItem7, nomePasta);
  // criando endereço para a pasta de output
  strcat(enderecoParaOutputItem3, "item3.txt");
  strcat(enderecoParaOutputItem4, "item4.txt");
  strcat(enderecoParaOutputItem5, "item5.txt");
  strcat(enderecoParaOutputItem6, "item6.txt");
  strcat(enderecoParaOutputItem7, "item7.txt");
  // criando itens na pasta
  item3 = fopen(enderecoParaOutputItem3, "w");
  item4 = fopen(enderecoParaOutputItem4, "w");
  item5 = fopen(enderecoParaOutputItem5, "w");
  item6 = fopen(enderecoParaOutputItem6, "w");
  item7 = fopen(enderecoParaOutputItem7, "w");

  // lendo csv
  leCsv(csv);

  // listando os munícipios com mais de N casos
  listaCasosEmOrdemAlfabetica(item3, NCasos);
  // mostrando os casos entre data1 e data2
  mostraTotalCasosEntreDatas(item4, dataIniTotalCasos, dataFimTotalCasos);
  // listando top N cidades
  listaTopNCidades(item5, N, dataIniTopCidades, dataFimTopCidades);
  // mostrando porcentagens para o item 6
  imprimePorcentagensItem6(item6, municipioParaItem6);
  // imprimindo valores do item 7
  imprimeDadosItem7(item7, dataParaMediaDesvioIni, dataParaMediaDesvioFim);

  // fechando arquivos
  fclose(csv);
  fclose(item3);
  fclose(item4);
  fclose(item5);
  fclose(item6);
  fclose(item7);

  return 0;
}

void leCsv(FILE *csv)
{
  int i;
  // variável auxiliar para ler cada string e fazer a comparação
  char vetorParaDados[20];

  // ignorando primeira linha do csv
  fscanf(csv, "%*[^\n]%*c");
  // lendo os dados do csv para o vetor de struct
  for (i = 0; i < TAMANHOCSV; i++)
  {
    // lendo as datas
    fscanf(csv, "%d-%d-%d,%d-%d-%d,", &vetorCsv[i].dataCadastro.ano, &vetorCsv[i].dataCadastro.mes, &vetorCsv[i].dataCadastro.dia, &vetorCsv[i].dataObito.ano, &vetorCsv[i].dataObito.mes, &vetorCsv[i].dataObito.dia);
    // lendo classificação
    fscanf(csv, "%[^,],", vetorParaDados);
    vetorCsv[i].classificacao = (strcmp(vetorParaDados, "Confirmados") == 0) ? True : False;
    // lendo município
    fscanf(csv, "%[^,],", vetorCsv[i].municipio);
    // lendo idade da pessoa
    fscanf(csv, "%*c%d %*[^\"]%*c,", &vetorCsv[i].idadePessoa);
    // lendo comorbidades
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadePulmao = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadeCardio = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadeRenal = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadeDiabetes = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadeTabagismo = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    fscanf(csv, "%[^,],", vetorParaDados);
    // se tiver comorbidade, variável recebe True, se não recebe False
    vetorCsv[i].comorbidadesPacientes.comorbidadeObesidade = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
    // lendo ficou internado
    fscanf(csv, "%[^\n]%*c", vetorParaDados);
    // se o indivíduo ficou internado, variável recebe True, se não, False
    vetorCsv[i].ficouInternado = (strcmp(vetorParaDados, "Sim") == 0) ? True : False;
  }
}

void mostraTotalCasosEntreDatas(FILE *arquivo, Data dataInicial, Data dataFinal)
{
  // inicializando variáveis
  int i, totalCasos = 0;
  // ajustando data final
  dataFinal.dia++;

  // loop de uma data até a outra
  for (dataInicial; !ehMesmaData(dataInicial, dataFinal); dataInicial = proximaData(dataInicial))
  {
    // percorrendo o vetor do csv
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // se a data do cadastro for igual a data no loop
      if (ehMesmaData(vetorCsv[i].dataCadastro, dataInicial))
      {
        // caso a classificação esteja confirmada, incrementamos a quantidade de casos
        if (vetorCsv[i].classificacao)
        {
          totalCasos++;
        }
      }
    }
  }
  // imprimindo total de casos no arquivo
  fprintf(arquivo, "- Total de pessoas: %d", totalCasos);
}

void listaCasosEmOrdemAlfabetica(FILE *arquivo, int n)
{
  // inicializando variáveis
  int i, total;

  // percorrendo a matriz com os nomes das cidades, que já está em ordem alfabética
  for (i = 0; i < 79; i++)
  {
    // calculando o total para a cidade na posição de i
    total = calculaTotalCasos(municipiosEspiritoSanto[i]);
    // caso o total seja maior, imprimimos seu valor
    if (total > n)
    {
      // imprimindo municípios e total no arquivo
      fprintf(arquivo, "- %s: %d casos\n", municipiosEspiritoSanto[i], total);
    }
  }
}

void colocaEmOrdemDecrescente(CasosMunicipio vetorCasosPorMunicipio[])
{
  // inicializando variáveis
  int i, j, aux1;
  char aux2[30];

  // percorrendo vetor de casos por município
  for (i = 0; i < 78; i++)
  {
    for (j = 0; j < 77 - i; j++)
    {
      // comparando o numero de casos na posição j com seu sucessor
      if (vetorCasosPorMunicipio[j].numeroDeCasos < vetorCasosPorMunicipio[j + 1].numeroDeCasos)
      {
        // auxilar1 recebe número de casos
        aux1 = vetorCasosPorMunicipio[j].numeroDeCasos;
        // auxiliar2 recebe string município
        strcpy(aux2, vetorCasosPorMunicipio[j].municipio);
        // número de casos do vetor na posição j recebe o número de casos do seu sucessor
        vetorCasosPorMunicipio[j].numeroDeCasos = vetorCasosPorMunicipio[j + 1].numeroDeCasos;
        // município do vetor na posição j recebe o próximo município
        strcpy(vetorCasosPorMunicipio[j].municipio, vetorCasosPorMunicipio[j + 1].municipio);
        // número de casos na posição j+1 recebe aux1
        vetorCasosPorMunicipio[j + 1].numeroDeCasos = aux1;
        // município no vetor recebe município, contido na variável aux2
        strcpy(vetorCasosPorMunicipio[j + 1].municipio, aux2);
      }
    }
  }
}

void listaTopNCidades(FILE *arquivo, int n, Data dataInicial, Data dataFinal)
{
  // inicializando variáveis
  int i;
  // criando vetor local para analise dos casos por munícipio
  CasosMunicipio vetorCasosPorMunicipio[79];

  // percorrendo a matriz munícipios
  for (i = 0; i < 79; i++)
  {
    // calculando número de casos e atribuindo a posição corrente
    vetorCasosPorMunicipio[i].numeroDeCasos = calculaQuantidadeDeCasosComDatas(dataInicial, dataFinal, municipiosEspiritoSanto[i]);
    // copiando município para a posição corrente
    strcpy(vetorCasosPorMunicipio[i].municipio, municipiosEspiritoSanto[i]);
  }
  // colocando vetor em ordem decrescente
  colocaEmOrdemDecrescente(vetorCasosPorMunicipio);
  // percorrendo vetor e imprimindo valores no arquivo
  for (i = 0; i < n; i++)
  {
    fprintf(arquivo, "- %s: %d casos\n", vetorCasosPorMunicipio[i].municipio, vetorCasosPorMunicipio[i].numeroDeCasos);
  }
}

void converteStringMaiusculo(char string[])
{
  // incializando variáveis
  int i;
  // percorrendo a string letra a letra
  for (i = 0; i < strlen(string); i++)
  {
    // convertendo letra para maiúsculo
    string[i] = toupper(string[i]);
  }
}

void imprimePorcentagensItem6(FILE *arquivo, char municipio[])
{
  // imprimindo dados formatados do arquivo
  fprintf(arquivo, "- Resultados para %s:\n", municipio);
  porcentagemPessoasConfirmadasInternadas(arquivo, municipio);
  porcentagemPessoasQueMorreram(arquivo, municipio);
  porcentagemPessoasInternadasQueMorreram(arquivo, municipio);
}

void imprimeDadosItem7(FILE *arquivo, Data dataInicial, Data dataFinal)
{
  // calcualando média entre a dataInicial e a dataFinal
  float media = calculaMediaDeIdadeEntreDatas(dataInicial, dataFinal);

  // imprimindo dados formatados do arquivo
  fprintf(arquivo, "A media e desvio padrao da idade: %.3f -- %.3f\n", media, calculaDesvioPradraoEntreDatas(dataInicial, dataFinal, media));
  fprintf(arquivo, "A %% de pessoas que morreram sem comorbidade: %.3f%%", calculaPorcentagemPessoasQueMorreramSemComorbidade(dataInicial, dataFinal));
}

void porcentagemPessoasConfirmadasInternadas(FILE *arquivo, char Municipio[])
{
  // inicializando váriaveis
  int i, CasosConfirmados = 0, pessoasInternadasConfirmadas = 0;

  // convertendo a string para maiúsculo
  converteStringMaiusculo(Municipio);

  // se a string municipio receber a palavra 'TODAS'
  if (strcmp(Municipio, "TODAS") == 0)
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa tenha sido contaminada e tenha ficado internada
      if (vetorCsv[i].classificacao && vetorCsv[i].ficouInternado)
      {
        // incrementando pessoas confirmadas que ficaram internadas
        pessoasInternadasConfirmadas++;
      }
      // caso a pessoa tenha sido contaminada
      if (vetorCsv[i].classificacao)
      {
        // incrementando casos confirmados
        CasosConfirmados++;
      }
    }
  }
  // caso outra string seja passada
  else
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa tenha sido contaminada e tenha ficado internada em determinado município
      if ((strcmp(vetorCsv[i].municipio, Municipio) == 0) && vetorCsv[i].classificacao && vetorCsv[i].ficouInternado)
      {
        // incrementando pessoas confirmadas que ficaram internadas
        pessoasInternadasConfirmadas++;
      }
      // caso a pessoa tenha sido contaminada em determinado município
      if ((strcmp(vetorCsv[i].municipio, Municipio) == 0) && vetorCsv[i].classificacao)
      {
        // incrementando casos confirmados
        CasosConfirmados++;
      }
    }
  }
  // imprimindo porcentagem de pessoas confirmadas que ficaram internadas
  fprintf(arquivo, "- A %% de pessoas com Covid-19 que ficaram internadas: %.3f%%\n", calculaPorcentagem(pessoasInternadasConfirmadas, CasosConfirmados));
}

void porcentagemPessoasQueMorreram(FILE *arquivo, char Municipio[])
{
  // inicializando variáveis
  int i, totalpessoas = 0, pessoasQueMorreram = 0;
  Data data1;
  data1.dia = 0;
  data1.mes = 0;
  data1.ano = 0;

  // convertendo a string para maiusculo
  converteStringMaiusculo(Municipio);

  // se a string municipio receber a palavra 'TODAS'
  if (strcmp(Municipio, "TODAS") == 0)
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa tenha sido contaminada
      if (vetorCsv[i].classificacao)
      {
        // incrementando total de pessoas contaminadas
        totalpessoas++;
        // se a pessoa morreu
        if (!ehMesmaData(vetorCsv[i].dataObito, data1))
          // incrementanto pessoas que morreram
          pessoasQueMorreram++;
      }
    }
  }
  // caso outra string seja passada
  else
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa tenha sido contaminada em determinado município
      if ((strcmp(vetorCsv[i].municipio, Municipio) == 0) && (vetorCsv[i].classificacao))
      {
        // incrementando total de pessoas contaminadas
        totalpessoas++;
        // se caso a pessoa morreu, incrementa a variável
        if (!ehMesmaData(vetorCsv[i].dataObito, data1))
          pessoasQueMorreram++;
      }
    }
  }
  // imprimindo porcentagem de pessoas que morreram no arquivo
  fprintf(arquivo, "- A %% de pessoas com Covid-19 que morreram: %.3f%%\n", calculaPorcentagem(pessoasQueMorreram, totalpessoas));
}

void porcentagemPessoasInternadasQueMorreram(FILE *arquivo, char Municipio[])
{
  // inicializando variáveis
  int i, pessoasInternadasQueMorreram = 0, pessoasConfirmadasQueMorreram = 0;
  // data para comparação de óbitos
  Data data1;
  data1.dia = 0;
  data1.mes = 0;
  data1.ano = 0;

  // convertendo a string para maiusculo
  converteStringMaiusculo(Municipio);

  // se a string munícipio receber a palavra 'TODAS'
  if (strcmp(Municipio, "TODAS") == 0)
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa confirmada tenha ficado internada e tenha vindo a óbito
      if (vetorCsv[i].ficouInternado && (!(ehMesmaData(vetorCsv[i].dataObito, data1))) && vetorCsv[i].classificacao)
      {
        // incrementando pessoas contaminadas internadas que morreram
        pessoasInternadasQueMorreram++;
      }
      // caso a pessoa confirmada tenha vindo a óbito
      if ((!(ehMesmaData(vetorCsv[i].dataObito, data1))) && vetorCsv[i].classificacao)
      {
        // incrementando pessoas contaminadas que morreram
        pessoasConfirmadasQueMorreram++;
      }
    }
  }
  // caso outra string seja passada
  else
  {
    // percorrendo o vetorCsv inteiro
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // caso a pessoa confirmada tenha ficado internada e tenha vindo a óbito em determinado munícipio
      if ((strcmp(vetorCsv[i].municipio, Municipio) == 0) && vetorCsv[i].ficouInternado && (!(ehMesmaData(vetorCsv[i].dataObito, data1))) && vetorCsv[i].classificacao)
        // incrementando pessoas contaminadas internadas que morreram
        pessoasInternadasQueMorreram++;
      // caso a pessoa confirmada tenha vindo a óbito em determinado munícipio
      if ((strcmp(vetorCsv[i].municipio, Municipio) == 0) && (!(ehMesmaData(vetorCsv[i].dataObito, data1))) && (vetorCsv[i].classificacao))
        // incrementando pessoas contaminadas que morreram
        pessoasConfirmadasQueMorreram++;
    }
  }
  // imprimindo porcentagem de pessoas internadas que morreram no arquivo
  fprintf(arquivo, "- A %% de pessoas que ficaram internadas e morreram: %.3f%%", calculaPorcentagem(pessoasInternadasQueMorreram, pessoasConfirmadasQueMorreram));
}

int quantidadeDiasDoMes(int mes)
{
  // se for mês 2
  if (mes == 2)
    return 29;
  // se for o mês 4, 6, 9, ou 11
  else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
    return 30;
  // caso seja outro mês
  else
    return 31;
}

int ehMesmaData(Data data1, Data data2)
{
  // se os dias e meses da data inicial e final forem iguais
  return ((data1.dia == data2.dia) && (data1.mes == data2.mes)) ? True : False;
}

int calculaTotalCasos(char municipio[])
{
  // inciializando variáveis
  int i, total = 0;

  // percorrendo o vetor todo
  for (i = 0; i < TAMANHOCSV; i++)
  {
    // se o município passado for igual ao munícipio no vetor
    if (strcmp(municipio, vetorCsv[i].municipio) == 0)
    {
      // se a classificação for confirmada, incrementa total de casos
      if (vetorCsv[i].classificacao)
        total++;
    }
  }
  // retornando total de casos
  return total;
}

int calculaQuantidadeDeCasosComDatas(Data dataInicial, Data dataFinal, char municipio[])
{
  // inicializando variáveis
  int i, quantidadeDeCasos = 0;
  // ajustando dia da data final
  dataFinal.dia++;

  // loop de uma data até a outra
  for (dataInicial; !ehMesmaData(dataInicial, dataFinal); dataInicial = proximaData(dataInicial))
  {
    // percorrendo o vetor do csv
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // se a data do cadastro for igual a data no loop
      if (ehMesmaData(vetorCsv[i].dataCadastro, dataInicial))
      {
        // se o município no vetor do csv for igual ao município informado
        if (strcmp(vetorCsv[i].municipio, municipio) == 0)
        {
          // caso a classificação esteja confirmada, incrementa a quantidade de casos
          if (vetorCsv[i].classificacao)
            quantidadeDeCasos++;
        }
      }
    }
  }
  // retornando total de casos entre a data inicial e a data final
  return quantidadeDeCasos;
}

float calculaPorcentagem(float valor1, float valor2)
{
  // retornando a porcentagem
  return (valor1 / valor2) * 100.00;
}

float calculaMediaDeIdadeEntreDatas(Data dataInicial, Data dataFinal)
{
  // inicializando variáveis
  int i, totalpessoas = 0;
  float soma = 0;
  // data para comparação
  Data dataTeste;
  dataTeste.dia = 0;
  dataTeste.mes = 0;
  dataTeste.ano = 0;
  // ajustando dia da data final
  dataFinal.dia++;

  // loop de uma data até a outra
  for (dataInicial; !ehMesmaData(dataInicial, dataFinal); dataInicial = proximaData(dataInicial))
  {
    // percorrendo o vetor csv
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // se a data do cadastro for igual a data no loop
      if (ehMesmaData(vetorCsv[i].dataCadastro, dataInicial))
      {
        // se a pessoa estava contaminada e veio a obito
        if (!ehMesmaData(vetorCsv[i].dataObito, dataTeste) && vetorCsv[i].classificacao)
        {
          // incrementando soma das idades
          soma += vetorCsv[i].idadePessoa;
          // incrementando total de pessoas
          totalpessoas++;
        }
      }
    }
  }
  // retornando média
  return (soma / totalpessoas);
}

float calculaDesvioPradraoEntreDatas(Data dataInicial, Data dataFinal, float media)
{
  // inicializando variáveis
  int i, totalpessoas = 0;
  float denominador = 0;
  // criando data para comparar óbitos
  Data dataTeste;
  dataTeste.dia = 0;
  dataTeste.mes = 0;
  dataTeste.ano = 0;
  // ajustando dia da data final
  dataFinal.dia++;

  // loop de uma data até a outra
  for (dataInicial; !ehMesmaData(dataInicial, dataFinal); dataInicial = proximaData(dataInicial))
  {
    // percorrendo o vetor do csv
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // se a data do cadastro for igual a data no loop
      if (ehMesmaData(vetorCsv[i].dataCadastro, dataInicial))
      {
        // se a pessoa estava contaminada e veio a óbito
        if (!ehMesmaData(vetorCsv[i].dataObito, dataTeste) && vetorCsv[i].classificacao)
        {
          // incrementando total de pessoas
          totalpessoas++;
          // incrementando denominador para o cálculo de desvio padrão
          denominador += pow((fabs(vetorCsv[i].idadePessoa - media)), 2);
        }
      }
    }
  }
  // como o somatório é de 1 até n, precisamos subtrair 1, pois nossa contagem começa do 0
  totalpessoas--;
  // retornando desvio padrão
  return sqrt(denominador / totalpessoas);
}

float calculaPorcentagemPessoasQueMorreramSemComorbidade(Data dataInicial, Data dataFinal)
{
  // inicializando váriaveis
  int i, pessoasQueMorreram = 0, pessoasQueMorreramSemComorbidade = 0;
  // criando data para testar óbitos
  Data dataTeste;
  dataTeste.ano = 0;
  dataTeste.mes = 0;
  dataTeste.dia = 0;
  // ajustando dia da data final
  dataFinal.dia++;

  // loop de uma data até a outra
  for (dataInicial; !ehMesmaData(dataInicial, dataFinal); dataInicial = proximaData(dataInicial))
  {
    // percorrendo o vetor csv
    for (i = 0; i < TAMANHOCSV; i++)
    {
      // se a data do cadastro for igual a data no loop
      if (ehMesmaData(vetorCsv[i].dataCadastro, dataInicial))
      {
        // se a pessoa estava contaminada
        if (vetorCsv[i].classificacao)
        {
          // verificadno se o indivíduo veio a óbito
          if (!ehMesmaData(vetorCsv[i].dataObito, dataTeste))
          {
            // incrementando a quantidade de pessoas que morreram
            pessoasQueMorreram++;
            // verificando se o paciente tinha alguma comorbidade
            if (!vetorCsv[i].comorbidadesPacientes.comorbidadeCardio)
              if (!vetorCsv[i].comorbidadesPacientes.comorbidadeDiabetes)
                if (!vetorCsv[i].comorbidadesPacientes.comorbidadeObesidade)
                  if (!vetorCsv[i].comorbidadesPacientes.comorbidadePulmao)
                    if (!vetorCsv[i].comorbidadesPacientes.comorbidadeRenal)
                      if (!vetorCsv[i].comorbidadesPacientes.comorbidadeTabagismo)
                        pessoasQueMorreramSemComorbidade++;
          }
        }
      }
    }
  }
  // retornando porcentagem de pessoas que morreram e nao tinham comorbidade
  return calculaPorcentagem(pessoasQueMorreramSemComorbidade, pessoasQueMorreram);
}

Data proximaData(Data dataInicial)
{
  // encontrando a quantidade de dias do mês da data inicial
  int quantidadeDiasDataInicial = quantidadeDiasDoMes(dataInicial.mes);

  // se o mês for 12 e a data esteja no seu limite de dias
  if (dataInicial.mes == 12 && quantidadeDiasDataInicial == dataInicial.dia)
  {
    // incrementando dia mês e ano
    dataInicial.dia = 1;
    dataInicial.mes = 1;
    dataInicial.ano++;
  }
  // caso contrário, se apenas a quantidade de dias estiver no limite
  else if (dataInicial.dia == quantidadeDiasDataInicial)
  {
    // incrementando dia e mês
    dataInicial.dia = 1;
    dataInicial.mes++;
  }
  // se houver menos dias do que a quantidade máxima de dias da data
  else if (dataInicial.dia < quantidadeDiasDataInicial)
    // incrementando os dias
    dataInicial.dia++;
  // se o mês for menor que 12
  else if (dataInicial.mes < 12)
    // incrementando o mês
    dataInicial.mes++;
  // retornando data atualizada
  return dataInicial;
}

Data leData(void)
{
  // inicializando variáveis
  Data algumaData;
  // lendo data do arquivo
  scanf("%d-%d-%d", &algumaData.ano, &algumaData.mes, &algumaData.dia);
  // retornando data
  return algumaData;
}