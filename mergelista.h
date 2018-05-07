/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mergelista.h
 * Author: rafael
 *
 * Created on 2 de Maio de 2018, 10:35
 */

#ifndef MERGELISTA_H
#define MERGELISTA_H

typedef struct Node Node;

void MergeSort(struct Node** headReaf);

struct Node* integra(struct Node* a, struct Node* b);

void particiona(struct Node* no, struct Node** frente, struct Node** pos);

void mostraLista(struct Node *node);

void construct(struct Node** antigo, int valor);

struct Node* limpar(struct Node *a);

int aumentaComp();

int aumentaMov();

#endif /* MERGELISTA_H */

