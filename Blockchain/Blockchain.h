#ifndef Blockchain_h
#define Blockchain_h

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



enum boolean {
    true = 1, false = 0
};

typedef enum boolean bool;
//typedef u_int8_t uint8_t;

//Estrutura do bloco
typedef struct Block {
    unsigned int index; // contem a identificação do bloco atual
    char* previousHash; // hash do bloco anterior
    struct Block* previousBlock; // bloco anterior
    unsigned long timestamp; // data e horario da criação do bloco
    float data; // dado contido no bloco
    char* hash; // 
}Block;


typedef struct Blockchain {
    Block *genesisBlock; // guarda o primeiro blooco
    Block *latestBlock; // guarda o último bloco
}Blockchain;

//Procedimento responsavel por iniciar a lista do blockchain
void initBlockchain(Blockchain *blockchain);
//Função ao qual calcula o hash do bloco
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data);
// Função que cria o próximo bloco
Block* generateNextBlock(Blockchain *blockchain, float data);
//Função que retorna o ultimo bloco
Block* getLatestBlock(Blockchain *blockchain);
//Verifica a validade  de um novo bloco
bool isValidNewBlock(Block* newBlock, Block* previousBlock);
//Verifica a validade do blockchain
bool isBlockchainValid(Blockchain *blockchain);
//Adiciona um novo bloco
int addBlock(Blockchain *blockchain, Block *newBlock);

static void hash_to_string(char string[65], const uint8_t hash[32]);


#endif