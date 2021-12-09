#include <iostream>

int main() {
    int cityNUmber,
        cityRoutes,
        **cities,
        routesNumber,
        route,
        maxRoutes = 0,
        routes,
        maxRoutesCity;

    printf("Number of cities: \n");
    scanf("%d", &cityNUmber);

    cities = (int **)malloc(cityNUmber * sizeof (int *));
    for (int i = 0; i < cityNUmber; ++i) {
        cities[i] = (int *) malloc((cityNUmber - i) * sizeof (int));
        for (int j = 0; j < cityNUmber - i; ++j) {
            cities[i][j] = 0;
        }
    }

    for (int i = 0; i < cityNUmber; ++i) {
        printf("Number of routes from %d. city: \n", i+1);
        scanf("%d", &routesNumber);
        printf( routesNumber == 0 ? "\n" : "Routes from the city: \n");

        cityRoutes = 0;

        for (int j = 0; j < routesNumber; ++j) {
            scanf("%d", &route);
            if(i == route - 1)
                continue;
            cities[i][route - 1 - i] = 1;
            routes ++;
            cityRoutes ++;
        }
        if(cityRoutes > maxRoutes)
        {
            maxRoutes = cityRoutes;
            maxRoutesCity = i;
        }
    }

    for (int i = 0; i < cityNUmber; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("  ");
        }
        for (int j = 0; j < cityNUmber - i; ++j) {
            printf("%d ", cities[i][j]);
        }
        printf("\n");
    }

    printf("All routes: %d, with %d.city having most routes (%d)", routes, maxRoutesCity + 1, maxRoutes);

    for (int i = 0; i < cityNUmber; ++i) {
        free(cities[i]);
    }

    free(cities);
}
