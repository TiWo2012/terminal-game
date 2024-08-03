#pragma once 
namespace random {
    // Funktion zur Erzeugung einer Pseudo-Zufallszahl
    double pseudo_rand(unsigned int seed, float minRange, float maxRange) {
        // Schritt 2: Seed mit einer Konstante multiplizieren (LCG Parameter)
        unsigned int a = 1664525;
        unsigned int c = 1013904223;
        unsigned int m = 0xFFFFFFFF; // 2^32
        seed = (a * seed + c) % m;

        // Schritt 3: Auf eine Float-Zahl reduzieren
        double randomFloat = static_cast<double>(seed) / static_cast<double>(m);

        // Schritt 4: In den gewünschten Bereich skalieren
        double randomInRange = minRange + randomFloat * (maxRange - minRange);

        return randomInRange;
    }
}