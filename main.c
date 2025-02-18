#include <mlx.h>
#include <stdlib.h>
int destroy_exit()
{
    exit(1);
    return (0);
}
int main()
{
    void *mlx;
    void *win;

    // Initialiser la connexion à MiniLibX
    mlx = mlx_init();

    // Créer une fenêtre de 800x600
    win = mlx_new_window(mlx, 800, 600, "So_ong");
    // mlx_hook(win, 17, 0, destroy_exit, NULL);
    // Attendre que l'utilisateur ferme la fenêtre
    mlx_loop(mlx);

    return 0;
}
