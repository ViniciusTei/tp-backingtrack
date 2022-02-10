// #include "../../include/core/readFile.h"

// void RemoveChar(char* str, char c) {
//     char *pr= str, *pw = str;

//     while(*pr)
//     {
//         *pw = *pr++;
//         pw += (*pw != c);
//     }

//     *pw = '\0';
// }

// int ReadFile(char* file_name, ListaInimigos *inimigos) {
//   FILE *file;
//   char linha[100], *pLinha, *pChar;
//   char P[4], K[4];
//   file = fopen(file_name, "r");
  
//   int fileCurrentLine = 0;

//   if(file == NULL)
//     {
//         printf("Erro ao abrir o arquivo!\n");
//         return 0;
//     }
//     else
//     {
//       fscanf(file, "%s %s", P, K);
//       Ness.p = strtol(P, NULL, 10);
//       Ness.k = strtol(K, NULL, 10);
//       Ness.name = 'N';
//       for (int i = 0; i < 5; i++) {
        
//         fscanf(file, "%s %s", P, K);
//         inimigos->inimigos[i].p = strtol(P, NULL, 10);
//         inimigos->inimigos[i].k = strtol(K, NULL, 10);
        
//         if (i == 0) {
//           inimigos->inimigos[i].name = 'U';
//         }
//         if (i == 1) {
//           inimigos->inimigos[i].name = 'T';
//         }
//         if (i == 2) {
//           inimigos->inimigos[i].name = 'S';
//         }
//         if (i == 3) {
//           inimigos->inimigos[i].name = 'B';
//         }
//         if (i == 4) {
//           inimigos->inimigos[i].name = 'G';
//         }
//       }

//     }
//   return 0;
// }