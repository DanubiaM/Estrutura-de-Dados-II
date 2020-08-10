
#include "Blockchain.h"
#include "sha-256.h"
#include <string.h>
#include <time.h>



void initBlockchain(Blockchain *blockchain){
    Block *genesisBlock = (Block*)malloc(sizeof(Block));

    genesisBlock->index =0;             // inicia o bloco com 0
    genesisBlock->data = 123;           // coloca um dado
    genesisBlock->previousBlock = NULL; // como não existe bloco anterior recebe NULL
    genesisBlock->previousHash = "0";
    genesisBlock->timestamp = time(NULL);

    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data);

    blockchain->genesisBlock = genesisBlock;//Aponta o ponteiro do genesisblock parece receber o block criado agora
    blockchain->latestBlock = genesisBlock;
};
static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        //montar uma string com 64 caracteres hexadecimais
        string += sprintf(string, "%02x", hash[i]); //02x hexadecimal em 2 caracteres
    }
};
char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data){
    char input[1024];
    sprintf(input, "%i%s%lu%.8f",index,previousHash, timestamp, data);
    //vetor de 32 bytes de inteiros unsigned [0-255] (256/8 = 32)
    uint8_t hash[32];
    //char hash_string[65];
    char *hash_string = (char*)malloc(sizeof(char)*65);
    calc_sha_256(hash, input, strlen(input));
    hash_to_string(hash_string, hash);
    return hash_string;

};

Block* generateNextBlock(Blockchain *blockchain, float data){
    Block *previusBlock = getLatestBlock(blockchain);   // cria-se uma variavel para receber o bloco do ultimo da lista
    Block *newBlock = (Block*)(malloc(sizeof(Block))); // crio um bloco para ser adicionado

    newBlock->index = previusBlock->index+1;         //logo o index do ultimo bloco sera usado para somar +1
    newBlock->previousHash = previusBlock->hash;    // chama-se o hash do bloco anterior para adicionar no previous deste
    newBlock->timestamp = time(NULL);
    newBlock->data = data;
    newBlock->hash = calculateHash(newBlock->index,newBlock->previousHash,newBlock->timestamp, newBlock->data); //realiza-se o calculo do hash desse bloco

    return newBlock;

};

Block* getLatestBlock(Blockchain *blockchain){

    return blockchain->latestBlock; // retorna o ultimo bloco
};

bool isValidNewBlock(Block* newBlock, Block* previousBlock){

   if(previousBlock->index +1 != newBlock->index){ // primeiro verifica-se se o index do newblock é diferente do bloco anterior +1, se sim não há integridade no bloco, pois deve ser igual
       return false;
   }else if(previousBlock->hash != newBlock->previousHash){ // a hash do bloco anterior deve ser igual ao hash do previusHash do newBlock
       return false;
   }else if (strcmp(calculateHash(newBlock->index,newBlock->previousHash,newBlock->timestamp, newBlock->data), newBlock->hash) != 0){ // se o hash do novo bloco não for igual ao hash contido no newblock, não há integridade
       return false;
   };

   return true;
   

};
bool isBlockchainValid(Blockchain *blockchain){ 
    Block *aux = blockchain->latestBlock;

      while (aux!=blockchain->genesisBlock) {
        if (!isValidNewBlock(aux, aux->previousBlock))
            return false;
        aux = aux->previousBlock;
    }
    return true;
};

int addBlock(Blockchain *blockchain, Block *newBlock){
 if (isValidNewBlock(newBlock, getLatestBlock(blockchain))) { // se o novo bloco for validado com o ultimo
        newBlock->previousBlock = getLatestBlock(blockchain); // ele recebe como previousBlock o ultimo bloco
        blockchain->latestBlock = newBlock; // atualiza o ultimo bloco para esse
        return 1;
    };
    return -1;
};

