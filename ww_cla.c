#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int ouro,meta,dias,numero_missao,membros=0,membros_ativos=0,doadores=0;
    char snumero_missao[12],cRelatorio[35],auxRelatorio[60];
    printf("Digite o numero da missao: ");
    scanf("%d",&numero_missao);
    sprintf(snumero_missao,"%d",numero_missao); // Converte o numero da missão para string
    printf("Digite o ouro atual do seu cla: ");
    scanf("%d",&ouro);
    
    FILE *q = fopen("membros.txt","r");
    char *p = (char *)malloc(50 * sizeof(char));
    while ((fgets(p, 50, q)) != NULL)
    {
        membros ++;
    }
    fclose(q);
    q = fopen("membros_ativos.txt","r");
    while ((fgets(p, 50, q)) != NULL)
    {
        membros_ativos ++;
    }
    fclose(q);
    q = fopen("doadores_ativos.txt","r");
    while ((fgets(p, 50, q)) != NULL)
    {
        doadores ++;
    }
    free(p);
    fclose(q);

    printf("Digite a meta de ouro e a quantidade de dias (meta,dias): ");
    scanf("%d,%d",&meta,&dias);
    float z = (float) ((meta - ouro) / doadores) / dias; // Vazão de ouro que cada doador ativo precisa doar por dia.
    float x = (float) (meta - ouro) / doadores; // Meta que cada doador ativo precisa doar.
    float z_ativos = (float) ((meta - ouro) / membros_ativos) / dias;
    float x_ativos = (float) (meta - ouro) / membros_ativos;
    float caso_otimo_z = (float) ((meta - ouro) / 50) / dias;
    float caso_otimo_x = (float) (meta - ouro) / 50;
    strcpy(cRelatorio,"Relatorios/Missao ");
    strcat(cRelatorio,snumero_missao); // cRelatorio = Relatorios/Missao X
    char cria_diretorio[50] = "mkdir \"";
    strcat(cria_diretorio,cRelatorio);
    strcat(cria_diretorio,"\"");
    system(cria_diretorio);
    strcat(cRelatorio,"/"); // cRelatorio = Relatorios/Missao X/
    strcpy(auxRelatorio,cRelatorio);
    strcat(auxRelatorio,"relatorio.txt");
    
    // Saída de dados:
    q = fopen(auxRelatorio,"w");
    printf("%s",auxRelatorio);
    fprintf(q,"Relatório:\n    Ouro atual: %d\n    Ouro necessário (Meta): %d\n    Numero de Membros: %d\n    Numero de Membros Ativos: %d\n    Numero de Doadores Ativos: %d\n",ouro,meta,membros,membros_ativos,doadores);
    fprintf(q,"\n- Caso Doadores Ativos doem (%d Doadores Ativos):\n    Para que o clã atinja a meta precisamos que cada doador ativo doe: %.2f ouros por dia.\n    Ou, para que o clã atinja a meta precisamos que cada doador ativo doe %.2f ouros ao longo de %d dias.\n",doadores,z,x,dias);
    fprintf(q,"\n- Caso Membros Ativos doem (%d Doadores Ativos):\n    Para que o clã atinja a meta precisamos que cada doador ativo doe: %.2f ouros por dia.\n    Ou, para que o clã atinja a meta precisamos que cada doador ativo doe %.2f ouros ao longo de %d dias.\n",membros_ativos,z_ativos,x_ativos,dias);
    fprintf(q,"\n- Caso Ótimo (50 Doadores Ativos):\n    Para que o clã atinja a meta precisamos que cada doador ativo doe: %.2f ouros por dia.\n    Ou, para que o clã atinja a meta precisamos que cada doador ativo doe %.2f ouros ao longo de %d dias.",caso_otimo_z,caso_otimo_x,dias);
    return 0;
}