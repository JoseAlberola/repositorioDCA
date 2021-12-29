#include <stdio.h>
#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

void empty_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int main() {

    setlocale(LC_ALL, "");
    bindtextdomain("hw", "po");
    textdomain("hw");

    printf(_("\nHola mundo! \n"));

    int estadoUsuario;
    int return_value = 0;
    do{
        printf(_("\n¿Cómo estás? \n"));
        printf(_("\t1. Genial, muchas gracias. \n"));
        printf(_("\t2. Sin mas, gracias por preguntar. \n"));
        printf(_("\t3. No he tenido un buen dia, pero gracias por preguntar. \n"));
        printf(_("\tElige una opcion: "));
        return_value = scanf("%d", &estadoUsuario);
        if(return_value==0){
            empty_stdin();
        }
    }while(true);

    switch (estadoUsuario)
    {
    case 1:
        printf(_("\n¡Me alegro mucho!"));
        break;
    case 2:
        printf(_("\nEsta bien, ¡de nada!"));
        break;
    case 3:
        printf(_("\nNo todos los dias pueden ser buenos."));
        break;
    }

    printf(_("\nGracias por contestar."));
    return 0;
}