#include <iostream>

int main() {
    int cityNUmber,
            **cities,
            route,
            routesNumber,
            maxInRoutes = 0,
            maxOutRoutes = 0,
            inRoutes,
            outRoutes,
            allInRoutes = 0,
            allOutRoutes = 0,
            maxInRoutesCity,
            maxOutRoutesCity;

    printf("Number of cities: \n");
    scanf("%d", &cityNUmber);

    cities = (int **)malloc(cityNUmber * sizeof (int *));
    for (int i = 0; i < cityNUmber; ++i) {
        cities[i] = (int *) malloc(cityNUmber * sizeof (int));
        for (int j = 0; j < cityNUmber; ++j) {
            cities[i][j] = 0;
        }
    }

    for (int i = 0; i < cityNUmber; ++i) {

        printf("Number of routes from %d. city: \n", i+1);
        scanf("%d", &routesNumber);
        printf( routesNumber == 0 ? "\n" : "Routes from the city: \n");

        inRoutes = 0;

        for (int j = 0; j < routesNumber; ++j) {
            scanf("%d", &route);
            cities[i][route - 1] = 1;
            if(route - 1 > i) {
                inRoutes ++;
                allInRoutes ++;
            }
            else if(i < route - 1) {
                allOutRoutes ++;
            }
        }
        if(inRoutes > maxInRoutes)
        {
            maxInRoutes = inRoutes;
            maxInRoutesCity = i;
        }
    }

    for (int i = 0; i < cityNUmber; ++i) {

        outRoutes = 0;

        for (int j = i; j < cityNUmber; ++j) {
            if(cities[j][i] == 1) {
                outRoutes ++;
            }
        }
        if(outRoutes > maxOutRoutes) {
            maxOutRoutes = outRoutes;
            maxOutRoutesCity = i;
        }
    }

    for (int i = 0; i < cityNUmber; ++i) {
        for (int j = 0; j < cityNUmber; ++j) {
            printf("%d ", cities[i][j]);
        }
        printf("\n");
    }

    printf("All routes: %d (%d incoming, %d outgoing). \n%d. city with most incoming routes (%d), %d. city with most outgoing routes(%d).", allInRoutes + allOutRoutes, allInRoutes, allOutRoutes, maxInRoutesCity + 1, maxInRoutes, maxOutRoutesCity + 1, maxOutRoutes);

    for (int i = 0; i < cityNUmber; ++i) {
        free(cities[i]);
    }

    free(cities);
}
