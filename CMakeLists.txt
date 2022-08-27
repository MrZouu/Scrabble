cmake_minimum_required(VERSION 3.21)
project(SCRABBLE C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(SCRABBLE
        affichPlat.c
        dictionnaire.c
        header.h
        initPartie.c
        initPlat.c
        main.c
        menu.c
        partie.c
        pioche.c
        piocherJeton.c
        placementMot.c
        reglesAide.c
        score.c)
