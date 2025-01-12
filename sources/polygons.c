/**
 * @file polygons.c
 * @brief Calcule les coordonnées cartésiennes et la surface d'un polygone régulier.
 * @author François Roland <francois.roland@heh.be>
 */

#include <math.h>
#include <stdio.h>

/* Constantes */

const double PI = 3.1416;

/* Structures */

struct CartesianCoordinates
{
  double x;
  double y;
};

struct PolarCoordinates
{
  double r;
  double theta;
};

/* Fonctions */

/**
 * @brief Vide le buffer utilisé par la fonction scanf.
 *
 * Permet de faire à nouveau appel à la fonction scanf sans être impacté par la saisie précédente.
 * Probablement hors d'atteinte pour les étudiants de première année.
 */
void flush_input()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
    // Do nothing. Just consume characters.
  }
}

/**
 * @brief Demande à l'utilisateur de saisir le nombre de cotés d'un polygone.
 * @return Le nombre de cotés du polygone.
 *
 * Demande à l'utilisateur de saisir le nombre de cotés d'un polygone et vérifie que ce nombre est supérieur ou égal à 3.
 * En cas d'erreur de saisie, un message est affiché et l'utilisateur est invité à saisir une nouvelle valeur.
 */
int get_polygon_sides()
{
  int sides;
  do
  {
    printf("Nombre de cotés : ");
    scanf("%d", &sides);
    flush_input();
    if (sides < 3)
    {
      printf("Un polygone doit avoir au moins 3 cotés.\n");
    }
  } while (sides < 3);
  return sides;
}

/**
 * @brief Demande à l'utilisateur de saisir le rayon du cercle.
 * @return Le rayon du cercle.
 *
 * Demande à l'utilisateur de saisir le rayon du cercle et vérifie que ce nombre est strictement supérieur à 0.
 * En cas d'erreur de saisie, un message est affiché et l'utilisateur est invité à saisir une nouvelle valeur.
 */
double get_circle_radius()
{
  double radius;
  do
  {
    printf("Rayon du cercle : ");
    scanf("%lf", &radius);
    flush_input();
    if (radius <= 0)
    {
      printf("Le rayon doit être supérieur à 0.\n");
    }
  } while (radius <= 0);
  return radius;
}

/**
 * @brief Convertit des coordonnées polaires en coordonnées cartésiennes.
 * @param polar Les coordonnées polaires à convertir.
 * @return Les coordonnées cartésiennes correspondantes.
 */
struct CartesianCoordinates polar_to_cartesian(struct PolarCoordinates polar)
{
  struct CartesianCoordinates cartesian;
  cartesian.x = polar.r * cos(polar.theta);
  cartesian.y = polar.r * sin(polar.theta);
  return cartesian;
}

/**
 * @brief Calcule les coordonnées cartésiennes des sommets d'un polygone régulier.
 * @param sides Le nombre de cotés du polygone.
 * @param radius Le rayon du cercle circonscrit au polygone.
 * @param vertices Un tableau dans lequel stocker les coordonnées cartésiennes des sommets du polygone.
 */
void compute_vertices(int sides, double radius, struct CartesianCoordinates vertices[])
{
  double angle_rad = 2 * PI / sides;
  for (int i = 0; i < sides; i++)
  {
    struct PolarCoordinates polar;
    polar.r = radius;
    polar.theta = i * angle_rad;
    struct CartesianCoordinates cartesian = polar_to_cartesian(polar);
    vertices[i] = cartesian;
  }
}

/**
 * @brief Affiche les coordonnées cartésiennes des sommets d'un polygone régulier.
 * @param sides Le nombre de cotés du polygone.
 * @param vertices Un tableau contenant coordonnées cartésiennes des sommets du polygone.
 */
void display_vertices(int sides, struct CartesianCoordinates vertices[])
{
  for (int i = 0; i < sides; i++)
  {
    printf("Sommet %d : (%.2lf, %.2lf)\n", i + 1, vertices[i].x, vertices[i].y);
  }
}

/**
 * @brief Calcule la surface d'un polygone régulier.
 * @param sides Le nombre de cotés du polygone.
 * @param radius Le rayon du cercle circonscrit au polygone.
 * @return La surface du polygone.
 */
double compute_surface(int sides, double radius)
{
  double angle_rad = 2 * PI / sides;
  return sides * radius * radius * sin(angle_rad) / 2;
}

/**
 * @brief Affiche la surface d'un polygone régulier.
 * @param surface La surface du polygone.
 */
void display_surface(double surface)
{
  printf("Surface : %.2lf\n", surface);
}

/**
 * @brief Calcule les coordonnées cartésiennes des sommets d'un polygone régulier et sa surface, affiche ces coordonnées et la surface.
 * @param sides Le nombre de cotés du polygone.
 * @param radius Le rayon du cercle circonscrit au polygone.
 */
void compute_and_display(int sides, double radius)
{
  struct CartesianCoordinates vertices[sides];
  compute_vertices(sides, radius, vertices);
  display_vertices(sides, vertices);
  double surface = compute_surface(sides, radius);
  display_surface(surface);
}

/**
 * @brief Affiche le menu.
 */
void display_menu()
{
  printf("\n");
  printf("MENU\n");
  printf("====\n");
  printf("1. Calculer un autre polygone\n");
  printf("0. Quitter\n");
  printf("Que voulez-vous faire ? ");
}

/**
 * @brief Point d'entrée principal du programme.
 * @return Le statut de sortie du programme.
 */
int main(void)
{
  int sides = get_polygon_sides();
  double radius = get_circle_radius();
  compute_and_display(sides, radius);
  int choice = 0;
  do
  {
    display_menu();
    scanf("%d", &choice);
    if (choice == 0)
    {
      printf("Au revoir.\n");
    }
    else if (choice == 1)
    {
      sides = get_polygon_sides();
      radius = get_circle_radius();
      compute_and_display(sides, radius);
    }
    else
    {
      printf("Choix invalide.\n");
    }
  } while (choice != 0);
  return 0;
}
