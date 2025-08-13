#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void cleanup(void) {
    clear_history();          // libère ce que add_history a dupliqué
}

static void sigint_handler(int sig) 
{
    (void)sig;
    write(STDOUT_FILENO, "\n", 1);      // async-signal-safe
    rl_replace_line("", 0);             // vide la ligne en cours
    rl_on_new_line();                   // on se place sur une nouvelle ligne
    rl_redisplay();                     // réaffiche le prompt
}

static void setup_signals(void) 
{
    struct sigaction sa = {0};

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;           // ok avec readline
    sigaction(SIGINT, &sa, NULL);

    signal(SIGQUIT, SIG_IGN);           // comme bash
}

int main(void) {
    char *pwd_before = NULL;
    char *pwd_after  = NULL;

    setup_signals();                    // ✅ une seule fois

    while (1) {
        char *input = readline("minishell$ ");
        if (!input) {                   // Ctrl+D -> EOF
            write(STDOUT_FILENO, "exit\n", 5);
            break;
        }
        if (*input) add_history(input); // pas d'historique pour lignes vides

        // ... traitement de la commande ...

        free(input);
    }

    // Exemple d'allocs après la boucle
    pwd_before = getcwd(NULL, 0);
    if (pwd_before) {
        printf("pwd before chdir: %s\n", pwd_before);
        free(pwd_before);
    }
    if (chdir("/home/dbhujoo/Desktop/minishell/test") == -1)
        perror("chdir");
    pwd_after = getcwd(NULL, 0);
    if (pwd_after) {
        printf("pwd after chdir: %s\n", pwd_after);
        free(pwd_after);
    }

    cleanup();                          // ✅ point unique de nettoyage
    return 0;
}