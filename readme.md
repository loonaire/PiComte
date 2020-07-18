# Compilation

Pour compiler:

``` sh
cd build/
cmake .. ( -G " Générateur à utiliser " -autres options)
```

Le makefiles généré crée une cible release ainsi qu'une cible debug :

``` sh
make release
```

Compile avec des options d'optimisation (-O3 dans le cmakelists, a modifier si vous le souhaitez)

``` sh
make debug
```

Compile avec les options de debogage

``` sh
make realsewithdebug
```

Compile en mode release mais permet le debogage