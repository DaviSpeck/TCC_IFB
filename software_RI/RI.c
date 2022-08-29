#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

// Trata texto, retirando sinais ortográficos, aumentando compatibilidade e otimizando identificação de textos
char trata_texto(char texto[999999])
{
    for (int i = 0; i < strlen(texto) - 1; i++)
    {

        int aux1 = 2;
        int aux2 = 3;

        if (texto[i + 1] == -61)
        {
            if (texto[i + 2] == -93 || texto[i + 2] == -94 || texto[i + 2] == -95 || texto[i + 2] == -96) // arrumar o 'a'
            {
                texto[i + 1] = 'a';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }

            if (texto[i + 2] == -86 || texto[i + 2] == -87 || texto[i + 2] == -88) // arrumando o 'e'
            {
                texto[i + 1] = 'e';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -82 || texto[i + 2] == -83 || texto[i + 2] == -84) // arrumando o 'i'
            {
                texto[i + 1] = 'i';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -78 || texto[i + 2] == -77 || texto[i + 2] == -76 || texto[i + 2] == -75) // arrumando o 'o'
            {
                texto[i + 1] = 'o';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -69 || texto[i + 2] == -70 || texto[i + 2] == -71) // arrumando o 'o'
            {
                texto[i + 1] = 'u';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -125 || texto[i + 2] == -126 || texto[i + 2] == -127 || texto[i + 2] == -128) // arrumando o 'A'
            {
                texto[i + 1] = 'A';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -117 || texto[i + 2] == -118 || texto[i + 2] == -119 || texto[i + 2] == -120) // arrumando o 'E'
            {
                texto[i + 1] = 'E';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -114 || texto[i + 2] == -115 || texto[i + 2] == -116) // arrumando o 'I'
            {
                texto[i + 1] = 'I';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -107 || texto[i + 2] == -108 || texto[i + 2] == -109 || texto[i + 2] == -110) // arrumando o 'O'
            {
                texto[i + 1] = 'O';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
            if (texto[i + 2] == -101 || texto[i + 2] == -102 || texto[i + 2] == -103) // arrumando o 'U'
            {
                texto[i + 1] = 'U';
                for (int aux3 = i; aux3 < strlen(texto); aux3++)
                {
                    texto[i + aux1] = texto[i + aux2];
                    aux1++;
                    aux2++;
                }
            }
        }
    }

    return texto;
}

int algoritmo_KMP_pagina(char texto[999999], char new_pags[20], int paginas)
{
    int tamanho_palavra = strlen(new_pags);
    int tamanho_texto = strlen(texto);
    int pont1[tamanho_palavra];
    prefixo_sufixo_array_pagina(new_pags, tamanho_palavra, pont1);
    int i = 0;
    int j = 0;
    while (i < tamanho_texto)
    {
        if (new_pags[j] == texto[i])
        {
            j++;
            i++;
        }
        if (j == tamanho_palavra)
        {
            paginas++;
            j = pont1[j - 1];
        }
        else if (i < tamanho_texto && new_pags[j] != texto[i])
        {
            if (j != 0)
                j = pont1[j - 1];
            else
                i = i + 1;
        }
    }

    return paginas;
}

void prefixo_sufixo_array_pagina(char *pont2, int tamanho_palavra, int *pont1)
{
    int tamanho = 0;
    pont1[0] = 0;
    int i = 1;
    while (i < tamanho_palavra)
    {
        if (pont2[i] == pont2[tamanho])
        {
            tamanho++;
            pont1[i] = tamanho;
            i++;
        }
        else
        {
            if (tamanho != 0)
                tamanho = pont1[tamanho - 1];
            else
            {
                pont1[i] = 0;
                i++;
            }
        }
    }
}

void algoritmo_KMP_palavra(char texto[999999], char palavra[20])
{
    int tamanho_palavra = strlen(palavra);
    int tamanho_texto = strlen(texto);
    int pont1[tamanho_palavra];
    prefixo_sufixo_array_palavra(palavra, tamanho_palavra, pont1);
    int i = 0;
    int j = 0;
    while (i < tamanho_texto)
    {
        if (palavra[j] == texto[i])
        {
            j++;
            i++;
        }
        if (j == tamanho_palavra)
        {
            j = pont1[j - 1];
        }
        else if (i < tamanho_texto && palavra[j] != texto[i])
        {
            if (j != 0)
                j = pont1[j - 1];
            else
                i = i + 1;
        }
    }
}

void prefixo_sufixo_array_palavra(char *pont2, int tamanho_palavra, int *pont1)
{
    int tamanho = 0;
    pont1[0] = 0;
    int i = 1;
    while (i < tamanho_palavra)
    {
        if (pont2[i] == pont2[tamanho])
        {
            tamanho++;
            pont1[i] = tamanho;
            i++;
        }
        else
        {
            if (tamanho != 0)
                tamanho = pont1[tamanho - 1];
            else
            {
                pont1[i] = 0;
                i++;
            }
        }
    }
}

char *copia_frase(char *dst, char *src, int start, int end)
{
    return strncpy(dst, src + start, end);
}

char *monta_frase(char texto[999999], char palavra[20], int aux)
{
    int indice_inicial = strlen(palavra) + 41;
    char *frase = malloc(strlen(texto));

    do
    {
        if (!strncmp(texto + aux, palavra, strlen(palavra)))
        {

            frase = copia_frase(frase, texto, (aux - indice_inicial), (aux));
            return frase;

            aux += strlen(palavra);
        }
        else
        {
            aux += 1;
        }
    } while (aux < strlen(texto));
}

void monta_aparicoes(char frase_inserida[5000], int paginas)
{
    FILE *arq;
    char caracteres_frase[150];

    memcpy(caracteres_frase, &frase_inserida[0], 150);
    caracteres_frase[150] = '\0';

    arq = fopen("aparicoes.txt", "a");

    fprintf(arq, "Aparicao da pagina %d - %s\n", paginas, caracteres_frase);
}

int contador_palavra(int contador_pagina, int contador_texto, int paginas, char texto[999999], char palavra[20])
{
    int aux = 0, aux_pagina = 0;
    char *frase = malloc(strlen(texto));

    paginas--;

    do
    {
        if (!strncmp(texto + aux, palavra, strlen(palavra)))
        {
            contador_pagina++;
            frase = monta_frase(texto, palavra, aux);
            monta_aparicoes(frase, paginas);
            aux += strlen(palavra);
        }
        else
        {
            aux += 1;
        }
    } while (aux < strlen(texto));

    if (contador_pagina != 0)
    {
        printf("Total de aparicoes na pagina %d: %d aparicoes\n\n", paginas, contador_pagina);
    }
    contador_texto += contador_pagina;
    aux_pagina--;

    return contador_texto;
}

int contador_rank(int contador_pagina, int contador_texto, int paginas, char texto[999999], char palavra[20], int paginas_rank[9999])
{
    int aux = 0;

    paginas--;

    do
    {
        if (!strncmp(texto + aux, palavra, strlen(palavra)))
        {
            contador_pagina++;
            aux += strlen(palavra);
        }
        else
        {
            aux += 1;
        }
    } while (aux < strlen(texto));

    contador_texto += contador_pagina;

    if (paginas == 351)
    {
        return 0;
    }

    if (contador_pagina != 0)
    {
        paginas_rank[paginas] = contador_pagina;
        return paginas_rank[paginas];
    }
}

void monta_rank(int paginas_rank[9999], int paginas, int contador_texto)
{
    FILE *arq;
    int procurado = contador_texto, posicao = 1, aux = 0;
    char auxiliar[30] = "º Lugar - Página", new_auxiliar[30];

    snprintf(new_auxiliar, 30, "%d%s", posicao, auxiliar);
    paginas--;

    arq = fopen("ranking.txt", "w");

    while (aux != contador_texto)
    {
        for (int i = 1; i <= paginas; i++)
        {
            if (paginas_rank[i] == procurado)
            {
                fprintf(arq, "%s %d - %d aparições\n", new_auxiliar, i, paginas_rank[i]);
                posicao++;
                snprintf(new_auxiliar, 30, "%d%s", posicao, auxiliar);
            }
        }
        procurado--;
        aux++;
    }
}

int main()
{
    // HtmlElement execucao = webBrowser.Document.GetElementById("btn_buscar");

    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "");

    FILE *arq;
    char texto[999999];
    int paginas_rank[9999];
    char palavra[20] = {'C', 'a', 'p', 'i', 't', 'u'};
    char pags[20] = "Pagina";
    char new_pags[20];
    int contador_pagina = 0, contador_texto = 0, auxiliar = 1, paginas = 1, aux2 = 1;

    snprintf(new_pags, 10, "%s %d", pags, paginas);

    arq = system("python LendoPdf.py");
    arq = fopen("aparicoes.txt", "w");
    arq = fopen("texto.txt", "r");

    if (arq == NULL)
    {
        return 0;
    }

    while (fgets(texto, 999999, arq) != NULL)
    {
        if (auxiliar == 1)
        {
            //printf("\nInsira a palavra que deseja buscar: ");
            //fgets(palavra, 20, stdin);
            //palavra = 
            palavra[strlen(palavra) - 1] = '\0';
            auxiliar++;
        }

        trata_texto(texto);

        paginas = algoritmo_KMP_pagina(texto, new_pags, paginas);

        snprintf(new_pags, 20, "%s %d", pags, paginas);

        algoritmo_KMP_palavra(texto, palavra);

        contador_texto = contador_palavra(contador_pagina, contador_texto, paginas, texto, palavra);

        paginas_rank[paginas] = contador_rank(contador_pagina, contador_texto, paginas, texto, palavra, paginas_rank);
    }

    printf("Total de aparicoes: %d aparicoes\n\n", contador_texto);
    monta_rank(paginas_rank, paginas, contador_texto);

    return 0;
}
