#include <stdio.h>
#include "electric_field.h"
int main() {
    int choice;
    Point3D point = {0, 0, 0};
    printf("Electric Field Calculator\n");
    printf("1. Infinite Wire\n2. Finite Wire\n3. Infinite Rod\n4. Thin Finite Rod\n");
    printf("5. Hollow Cylinder\n6. Solid Cylinder\n7. Hollow Sphere\n8. Solid Sphere\n");
    printf("9. Thin Sheet\n10. Hollow Cube\n11. Solid Cube\n12. Torus\n13. Coil\n");
    printf("14. Thin Ring\n15. Thin Disk\n16. Annular Disk\n17. Triangular Sheet\n");
    printf("Enter choice (1-17): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            double lambda, r;
            printf("Enter linear charge density (C/m): ");
            scanf("%lf", &lambda);
            printf("Enter radial distance (m): ");
            scanf("%lf", &r);
            double E = infinite_wire_field(lambda, r);
            print_vector(E, 0, 0);
            break;
        }
        case 2: {
            double Q, L;
            printf("Enter total charge (C): ");
            scanf("%lf", &Q);
            printf("Enter length (m): ");
            scanf("%lf", &L);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = finite_wire_field(Q, L, point);
            double r = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/r, E * point.y/r, 0);
            break;
        }
        case 3: {
            double lambda, r;
            printf("Enter linear charge density (C/m): ");
            scanf("%lf", &lambda);
            printf("Enter radial distance (m): ");
            scanf("%lf", &r);
            double E = infinite_rod_field(lambda, r);
            print_vector(E, 0, 0);  // Along x-direction
            break;
        }
        case 4: {
            double Q, L;
            printf("Enter total charge (C): ");
            scanf("%lf", &Q);
            printf("Enter length (m): ");
            scanf("%lf", &L);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = thin_finite_rod_field(Q, L, point);
            double r = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/r, E * point.y/r, 0);
            break;
        }
        case 5: {
            double sigma, radius, dist;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter distance from axis (m): ");
            scanf("%lf", &dist);
            double E = hollow_cylinder_field(sigma, radius, dist);
            print_vector(E, 0, 0);
            break;
        }
        case 6: {
            double rho, radius, dist;
            printf("Enter volume charge density (C/m³): ");
            scanf("%lf", &rho);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter distance from axis (m): ");
            scanf("%lf", &dist);
            double E = solid_cylinder_field(rho, radius, dist);
            print_vector(E, 0, 0);
            break;
        }
        case 7: {
            double sigma, radius, dist;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter distance from center (m): ");
            scanf("%lf", &dist);
            double E = hollow_sphere_field(sigma, radius, dist);
            print_vector(E, 0, 0);
            break;
        }
        case 8: {
            double rho, radius, dist;
            printf("Enter volume charge density (C/m³): ");
            scanf("%lf", &rho);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter distance from center (m): ");
            scanf("%lf", &dist);
            double E = solid_sphere_field(rho, radius, dist);
            print_vector(E, 0, 0);
            break;
        }
        case 9: {
            double sigma;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            double E = thin_sheet_field(sigma);
            print_vector(0, 0, E);
            break;
        }
        case 10: {
            double sigma, side;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter side length (m): ");
            scanf("%lf", &side);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = hollow_cube_field(sigma, side, point);
            double r = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/r, E * point.y/r, E * point.z/r);
            break;
        }
        case 11: {
            double rho, side;
            printf("Enter volume charge density (C/m³): ");
            scanf("%lf", &rho);
            printf("Enter side length (m): ");
            scanf("%lf", &side);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = solid_cube_field(rho, side, point);
            double r = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/r, E * point.y/r, E * point.z/r);
            break;
        }
        case 12: {
            double sigma, R, r;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter major radius (m): ");
            scanf("%lf", &R);
            printf("Enter minor radius (m): ");
            scanf("%lf", &r);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = torus_field(sigma, R, r, point);
            double dist = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/dist, E * point.y/dist, E * point.z/dist);
            break;
        }
        case 13: {
            double lambda, radius, turns;
            printf("Enter linear charge density (C/m): ");
            scanf("%lf", &lambda);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter number of turns: ");
            scanf("%lf", &turns);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = coil_field(lambda, radius, turns, point);
            print_vector(0, 0, E);
            break;
        }
        case 14: {
            double Q, radius;
            printf("Enter total charge (C): ");
            scanf("%lf", &Q);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = thin_ring_field(Q, radius, point);
            print_vector(0, 0, E);
            break;
        }
        case 15: {
            double sigma, radius;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter radius (m): ");
            scanf("%lf", &radius);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = thin_disk_field(sigma, radius, point);
            print_vector(0, 0, E);
            break;
        }
        case 16: {
            double sigma, r1, r2;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter inner radius (m): ");
            scanf("%lf", &r1);
            printf("Enter outer radius (m): ");
            scanf("%lf", &r2);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = annular_disk_field(sigma, r1, r2, point);
            print_vector(0, 0, E);
            break;
        }
        case 17: {
            double sigma, base, height;
            printf("Enter surface charge density (C/m²): ");
            scanf("%lf", &sigma);
            printf("Enter base length (m): ");
            scanf("%lf", &base);
            printf("Enter height (m): ");
            scanf("%lf", &height);
            printf("Enter point (x y z): ");
            scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
            double E = triangular_sheet_field(sigma, base, height, point);
            double r = calculate_distance((Point3D){0,0,0}, point);
            print_vector(E * point.x/r, E * point.y/r, E * point.z/r);
            break;
        }
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
