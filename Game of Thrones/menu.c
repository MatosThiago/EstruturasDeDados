#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

void menu(void)
{
    system("clear");
    printf("|--------------------------------------------------------------------------------------|\n");
    printf("|                                                                                      |\n");
    printf("|     ____________       ______           __       __       _________                  |\n");
    printf("|    |  __________|     / ____ \\         /  \\     /  \\     |  _____  |                 |\n");
    printf("|    | |  ________     / /    \\ \\       /    \\   /    \\    | |_____| |                 |\n");
    printf("|    | |  |_____  |   / /______\\ \\     /  /\\  \\_/  /\\  \\   |  _______|                 |\n");
    printf("|    | |________| |  / __________ \\   /  /  \\_____/  \\  \\  | |_______                  |\n");
    printf("|    |____________| /_/          \\_\\ /__/             \\__\\ |_________|                 |\n");
    printf("|                                                                                      |\n");
    printf("|                          _________   ________                                        |\n");
    printf("|                         |  _____  | |  ______|                                       |\n");
    printf("|                         | |     | | |  |_____                                        |\n");
    printf("|                         | |     | | |  ______|                                       |\n");
    printf("|                         | |_____| | |  |                                             |\n");
    printf("|                         |_________| |__|                                             |\n");
    printf("|                                                                                      |\n");
    printf("|     ___________   _    _   _______   _________   ___     _   _________     ________  |\n");
    printf("|    |____   ____| | |  | | |  ___  | |  _____  | |   \\   | | |  _____  |   |  ______| |\n");
    printf("|         | |      | |__| | | |___| | | |     | | | |\\ \\  | | | |_____| |   | |____    |\n");
    printf("|         | |      |  __  | |    ___| | |     | | | | \\ \\ | | |  _______|   |____  |   |\n");
    printf("|         | |      | |  | | | |\\ \\    | |_____| | | |  \\ \\| | | |_______   ______| |   |\n");
    printf("|         |_|      |_|  |_| |_| \\_\\   |_________| |_|   \\___| |_________| |________|   |\n");
    printf("|                                                                                      |\n");
    printf("|  [1] Start New Game                                                                  |\n");
    printf("|  [2] Inserir Novo Personagem                                                         |\n");
    printf("|  [3] Quit Game                                                                       |\n");
    printf("\\______________________________________________________________________________________/\n");
    printf("\tOption: ");
    int opt;
    scanf("%d", &opt);
    while(opt < 1 || opt > 3)
    {
        menu();
    }
        if(opt == 1)
        {
            selecao_de_personagem();
        }
            else if(opt == 2)
            {
                inserir_no_txt();
            }
                else if(opt == 3)
                {
                    system("clear");
                    exit(0);
                }
}
        
void vitoria(Character* voce, Character* inimigo, int atributo)
{
    printf("   __   __  _____   _    _   __    ____    __  __   ___    _\n");
    printf("   \\ \\ / / |  _  | | |  | |  \\ \\  /    \\  / / |  | |   \\  | |\n");
    printf("    \\   /  | | | | | |  | |   \\ \\/  /\\  \\/ /  |  | | |\\ \\ | | \n");
    printf("     | |   | |_| | | |__| |    \\   /  \\   /   |  | | | \\ \\| |\n");
    printf("     |_|   |_____| |______|     \\_/    \\_/    |__| |_|  \\___|\n\n\n");
    switch(atributo)
    {
        case 1:
        {
           printf("%s (%d Agility) VS %s (%d Agility)\n", voce->name, voce->agility, inimigo->name, inimigo->agility);
           printf("%s da Casa %s foi vitorioso\n\n", voce->name, voce->house);  
           break;
        }
        case 2:
        {
           printf("%s (%d Strenght) VS %s (%d Strenght)\n", voce->name, voce->strenght, inimigo->name, inimigo->strenght);
           printf("%s da Casa %s foi vitorioso\n\n", voce->name, voce->house);  
           break;
        }
        case 3:
        {
           printf("%s (%d Intelligence) VS %s (%d Intelligence)\n", voce->name, voce->intelligence, inimigo->name, inimigo->intelligence);
           printf("%s da Casa %s foi vitorioso\n\n", voce->name, voce->house);  
           break;
        }
        case 4:
        {
           printf("%s (%d Health) VS %s (%d Health)\n", voce->name, voce->health, inimigo->name, inimigo->health);
           printf("%s da Casa %s foi vitorioso\n\n", voce->name, voce->house);  
           break;
        }
    }
    printf("Pressione qualquer tecla para prosseguir\n");
    getchar();
}

void derrota(Character* voce, Character* inimigo, int atributo)
{
    printf("   __   __  _____   _    _    _       _____     _______   _______\n");
    printf("   \\ \\ / / |  _  | | |  | |  | |     |  _  |   | ______| |  ____ |\n");
    printf("    \\   /  | | | | | |  | |  | |     | | | |   |__  |    |  _____| \n");
    printf("     | |   | |_| | | |__| |  | |___  | |_| |  __ _| |    | |_____ \n");
    printf("     |_|   |_____| |______|  |_____| |_____| |______|    |_______|\n\n");
    switch(atributo)
    {
        case 1:
        {
           printf("%s (%d Agility) VS %s (%d Agility)\n", voce->name, voce->agility, inimigo->name, inimigo->agility);
           printf("%s da Casa %s foi vitorioso\n\n", inimigo->name, inimigo->house);  
           break;
        }
        case 2:
        {
           printf("%s (%d Strenght) VS %s (%d Strenght)\n", voce->name, voce->strenght, inimigo->name, inimigo->strenght);
           printf("%s da Casa %s foi vitorioso\n\n", inimigo->name, inimigo->house);  
           break;
        }
        case 3:
        {
           printf("%s (%d Intelligence) VS %s (%d Intelligence)\n", voce->name, voce->intelligence, inimigo->name, inimigo->intelligence);
           printf("%s da Casa %s foi vitorioso\n\n", inimigo->name, inimigo->house);  
           break;
        }
        case 4:
        {
           printf("%s (%d Health) VS %s (%d Health)\n", voce->name, voce->health, inimigo->name, inimigo->health);
           printf("%s da Casa %s foi vitorioso\n\n", inimigo->name, inimigo->house);  
           break;
        }
    }
    printf("Pressione qualquer tecla para ver o histórico de batalhas");
    getchar();
}