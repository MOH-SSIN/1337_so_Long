// int est_bloque(char **carte)
// {
//     char **copie;
//     int i, j;

//     // Faire une copie de la carte pour éviter de modifier l'originale
//     copie = copie_map(carte);
//     if (!copie)
//         return (0);

//     // Trouver la position du joueur
//     if (get_position_player(copie, &i, &j)) {
//         ft_marque(copie, i, j);  // Marquer toutes les cases accessibles
//     }

//     // Vérifier si le joueur peut atteindre la collecte avant la porte
//     for (i = 0; copie[i]; i++) {
//         for (j = 0; copie[i][j]; j++) {
//             // Vérifier si la porte bloque l'accès à une collecte
//             if (copie[i][j] == 'C') {
//                 // Si la case de la collecte est atteinte avant la porte
//                 if (copie[i][j] == 'V') {
//                     // Si la porte bloque le chemin vers la collecte, le joueur est bloqué
//                     printf("Erreur: La porte bloque l'accès à la collecte.\n");
//                     free_map(copie);
//                     return (1);  // Le joueur est bloqué
//                 }
//             }
//         }
//     }

//     free_map(copie);
//     return (0);  // Le joueur peut accéder à la collecte
// }